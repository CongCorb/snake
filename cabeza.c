#include <stdbool.h>
#include "snake.h"
#include <stdlib.h>

void cabeza_mover(struct cabeza* cabeza, int dirreccion){ 

	switch (dirreccion){
	
	case 0: // izquierda 
		cabeza->posicion_ant_X = cabeza->posicion_act_X;
		cabeza->posicion_act_X = cabeza->posicion_act_X--;
		break;
	case 1: // derecha
		cabeza->posicion_ant_X = cabeza->posicion_act_X;
		cabeza->posicion_act_X = cabeza->posicion_act_X++;
		break;
	case 2: // arriba 
		cabeza->posicion_ant_Y = cabeza->posicion_act_Y;
		cabeza->posicion_act_Y = cabeza->posicion_act_Y--;
		break;
	case 3: //abajo
		cabeza->posicion_ant_Y = cabeza->posicion_act_Y;
		cabeza->posicion_act_Y = cabeza->posicion_act_Y++;
		break;
	}
	
}


bool cabeza_record(struct cabeza *cabeza, struct comida *comida){

	if(cabeza->posicion_act_X == comida->posicion_X && cabeza->posicion_act_Y == comida->posicion_Y){
	
			cabeza->score = cabeza->score++;
		return true;
	}

	return false;
}

bool cabeza_suicidio(struct cabeza* cabeza, struct body* body){

	struct body* rec = body;

	while(rec != NULL){

		if ((cabeza->posicion_act_X == rec->posicion_act_X) && (cabeza->posicion_act_Y == rec->posicion_act_Y)) {
			return false;
		}
		rec = rec->sig;
	}

	
	return true;
}

bool cabeza_pared(struct cabeza* cabeza, struct pantalla *pantalla){

	//true es vive
	//false es muere

	if ((cabeza->posicion_act_X - pantalla->ancho) >= 0) {
		return false;
	}
	if ((cabeza->posicion_act_Y - pantalla->alto) >= 0) {
	 	return false;
	}

	 return true;
}
