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

	/*===================================================*/

   	endwin(); // desactiva ncurse 
	return 0;
}
