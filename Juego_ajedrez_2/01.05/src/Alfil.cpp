#include "Alfil.h"

Alfil::Alfil() {

	fila = columna = 2;
	radio = 0.4;
	rojo = verde = azul = 255;
}


Alfil::Alfil(int j, float r, int f, int c)//:Pieza(jugador, rojo, verde, azul, radio, fila, columna)
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


bool Alfil::mov_posible(Vector2D pos_init, Vector2D pos_final)
{

	return false;
}
