#include "Caballo.h"

Caballo::Caballo() {

	
	radio = 0.5;
	rojo = verde = azul = 255;
}


Caballo::Caballo(int j, float r, int f, int c)//:Pieza(jugador, rojo, verde, azul, radio, fila, columna)
{
	jugador = j;
	//0 es blanco
	if (jugador == 0) {
		rojo = verde = azul = 255;
	}
	else rojo = verde = azul = 0;
	radio = r;
	fila = f;
	columna = c;
	
}


bool Caballo::mov_posible()
{

	return false;
}

void Caballo::dibuja()
{
	Pieza::dibuja();
	if (jugador == 0) {
		sprite.setCenter(-fila, -columna);
		sprite.setSize(socorro, socorro);
		sprite.draw();
	}
	else {
		sprite2.setCenter(-fila, -columna);
		sprite2.setSize(socorro, socorro);
		sprite2.draw();
	}
	
	
}
