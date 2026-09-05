#include "snake.h"
#include <stdbool.h>
#include <stdlib.h>
#include <ncurses.h>

void crear_cuerpo(struct body* body){

	struct body *nuevo;
	nuevo = malloc(sizeof(struct body));
	
	if(nuevo == NULL){

		return;
	}

	nuevo->posicion_act_X = body->posicion_ant_X;
	nuevo->posicion_act_Y = body->posicion_ant_Y;

	nuevo->posicion_ant_X = 0;
	nuevo->posicion_ant_Y = 0;
	
	nuevo->sig = NULL;
	body->sig = nuevo;
}

void refresh_posicion(struct body* body, struct cabeza* cabeza){

	if(body == NULL){
		return;
	}

	struct body* rec = body;

	int temp_X = rec->posicion_act_X;
    	int temp_Y = rec->posicion_act_Y;
	

		rec->posicion_ant_X = rec->posicion_act_X;
		rec->posicion_ant_Y = rec->posicion_act_Y;

		rec->posicion_act_X = cabeza->posicion_ant_X;
		rec->posicion_act_Y = cabeza->posicion_ant_Y;


	rec = rec->sig;

	while(rec != NULL){

		int next_X = rec->posicion_act_X;
        	int next_Y = rec->posicion_act_Y;	
	
			rec->posicion_ant_X = rec->posicion_act_X;
			rec->posicion_ant_Y = rec->posicion_act_Y;

			rec->posicion_act_X = temp_X;
			rec->posicion_act_Y = temp_Y;

		temp_X = next_X;
		temp_Y = next_Y;

		rec = rec->sig;
	}
}

void cuerpo_nuevo(struct body* body){

	if(body == NULL){
		return;
	}
	
	struct body* rec = body;

	while (rec->sig != NULL) {
		rec = rec->sig;
	}
	crear_cuerpo(rec);

}

void cuerpo_pintar(struct body* body, WINDOW* juego){

	if(body == NULL){
		return;
	}

	struct body* rec = body;

		mvwprintw(juego, body->posicion_act_Y, body->posicion_act_X, "#");

                rec = rec->sig;

		while(rec != NULL){
			
			mvwprintw(juego, rec->posicion_act_Y, rec->posicion_act_X, "#");
                 	rec = rec->sig;
		}
}
