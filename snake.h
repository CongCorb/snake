#ifndef SNAKE
#define SNAKE
#include <stdbool.h>
struct cabeza{
	//
	//dirreciones son:
	// izquierda: 0
	// derecha: 1
	// arriba: 2
	// abajo: 3
	//
	int posicion_ant_X;
	int posicion_ant_Y;

	int posicion_act_X;
	int posicion_act_Y;

	int score;
	int dirrecion;
};

struct body{

	int posicion_ant_X;
	int posicion_ant_Y;

	int posicion_act_X;
	int posicion_act_Y;

	struct body *sig;

};

struct comida{

	int posicion_X;
	int posicion_Y;

};

struct pantalla{

	int ancho;
	int alto;

};
	//=========Cuerpo========
	void crear_cuerpo(struct body* body);	//crea una nueva cola
	void refresh_posicion(struct body* body, struct cabeza* cabeza); //actualiza la estructura de la pocision de la cola global
	//=================


	// ===========comida=========
	bool comida_comprobar(struct body* body, struct cabeza* cabeza, struct comida* comida); // comprobacion si es que la comida se genero en una pocicion correcta
	void comida_generar(struct body* body, struct cabeza* cabeza, struct comida* comida, struct pantalla* pantalla); // genera la comida aleatoriamente
	//=================

	//============== Cabeza============
	void cabeza_mover(struct cabeza* cabeza, int dirreccion); //recibe la dirrecion y escribe la nueva pocicion en el struct
	bool cabeza_record(struct cabeza* cabeza, struct comida* comida); // actualiza la puntuacion del jugador
	bool cabeza_suicidio(struct cabeza* cabeza, struct body* body); // comprobar si la serpiente se choco con sigo misma	
	bool cabeza_pared(struct cabeza* cabeza, struct pantalla* pantalla); //comprobar muerte por pared
	//===============
#endif
