#include "Alfil.h"

Alfil::Alfil() {

	fila = columna = 2;
	radio = 0.5;
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

void Alfil::dibuja()
{
	Pieza::dibuja();
	tablero.setOcupado(fila, columna, ALFIL);
}


bool Alfil::mov_posible()
{

	return false;
}
