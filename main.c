#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include "snake.h"
#include <time.h>
#include <ncurses.h>

int main (){
 	/*=============ejecutar una sola vez===============*/	

	srand(time(NULL)); // para que se genere la comida eleatoriamente.
	initscr(); // inicia ncurses
	noecho(); //quita el eco
	cbreak(); //elimina el buffer
	keypad(stdscr,true); //habilita teclas especiales
	curs_set(0); //desactiva el cursor
	timeout(100); // 10 movimientos por segundo	
	raw(); //entrada de teclas
	/*===================================================*/

	//============== inizialisacion (??) de estructuras
	struct pantalla pantalla;
	struct cabeza cabeza;
	struct comida comida;
	struct body cuerpo;

	pantalla.alto = 20;
	pantalla.ancho = 20;

	comida.posicion_X = 0;
	comida.posicion_Y = 0;

	cabeza.dirrecion = 1;

	cabeza.posicion_act_X = (pantalla.alto / 5); // siempre tiene que dar un numero natural distinto de 0
	cabeza.posicion_act_Y = (pantalla.ancho / 4);// en ambos casos ¬¬

	cabeza.posicion_ant_X = ((cabeza.posicion_act_X) - 1);
	cabeza.posicion_ant_Y = (cabeza.posicion_act_Y);

	cuerpo.sig = NULL;

	cuerpo.posicion_act_X = (cabeza.posicion_act_X -1);
	cuerpo.posicion_act_Y = (cabeza.posicion_act_Y);

	cuerpo.posicion_ant_X = (cuerpo.posicion_act_X -1);
	cuerpo.posicion_ant_Y = (cuerpo.posicion_ant_Y);
	//====================
	
       if ((LINES - pantalla.alto) < 0){
		
	        endwin();
		printf("error al centrar la pantalla");
		return 1;
       } 
	if((COLS - pantalla.ancho) < 0){

		endwin();
		printf("error al centrar la pantalla");
		return 1;
	}

	int cent_y = ((LINES- pantalla.alto)/2); // centrar la ventana del juego
	int cent_x = ((COLS - pantalla.ancho) / 2);

	WINDOW* juego;

	juego = newwin(pantalla.alto, pantalla.ancho, cent_y, cent_x);

	box(juego, 0, 0);

	crear_cuerpo(&cuerpo);
  
	while(1){

 		int ch = getch();

		switch (ch){

			case KEY_LEFT:
		 		cabeza.dirrecion = 0;
				break;
			case KEY_RIGHT:
				cabeza.dirrecion = 1;
				break;
			case KEY_UP:
				cabeza.dirrecion = 2;
				break;
			case KEY_DOWN:
				cabeza.dirrecion = 3;
				break;
			case 'q':
				endwin();
				return 0;
				break;
			case 'Q':
				endwin();
				return 0;
				break;
			case 3:
				endwin();
				return 0;
				break;
			case 4:
				endwin();
				return 0;
				break;
			case -1:
				endwin();
				return 0;
				break;
		}
			cabeza_mover(&cabeza, cabeza.dirrecion);
			refresh_posicion(&cuerpo, &cabeza);
		        comida_generar(&cuerpo, &cabeza, &comida, &pantalla);
		         
		        cabeza_record(&cabeza, &comida);
		        cabeza_suicidio(&cabeza, &cuerpo);
		        cabeza_pared(&cabeza, &pantalla);

                       	//===========Ncurses=============
	 	        mvwprintw(juego, comida.posicion_Y, comida.posicion_X, "C");
                         
		        mvwprintw(juego, cabeza.posicion_act_Y, cabeza.posicion_act_X, "M");

		        mvwprintw(juego, cuerpo.posicion_act_Y, cuerpo.posicion_act_X, "#");
 
                       	mvprintw((((LINES- pantalla.alto)/2)+1), (((COLS - pantalla.ancho)/2)+1), "%d", cabeza.score); 
			
			refresh();

			napms(9999); //no parece funcionar :c

			//============================
	}




   	endwin(); // desactiva ncurse 
	return 0;
}
