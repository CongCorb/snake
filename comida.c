#include "snake.h"
#include <stdlib.h>


bool comida_comprobar(struct body* body, struct cabeza* cabeza, struct comida* comida){

	if(comida->posicion_X == cabeza->posicion_act_X && comida->posicion_Y == cabeza->posicion_act_Y){
		return false;
	}
	struct body* rec = body;

	while(rec != NULL){
	
		if((comida->posicion_X == rec->posicion_act_X && comida->posicion_Y == rec->posicion_act_Y)){

			return false;
		}
		rec = rec->sig;
	}


	return true;
}

void comida_generar(struct body* body, struct cabeza* cabeza, struct comida* comida, struct pantalla* pantalla){

	while(1){
		
			comida->posicion_X = rand() % pantalla->ancho;
			comida->posicion_Y = rand() % pantalla->alto;

		if(comida_comprobar(body,cabeza, comida)){
			break;
		}
	}
}

