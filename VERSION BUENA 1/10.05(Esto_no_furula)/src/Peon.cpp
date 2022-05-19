#include "Peon.h"

Peon::Peon() {

	fila = columna = 2;
	radio = 0.5;
	rojo = verde = azul = 255;
}


Peon::Peon(int j, float r, int f, int c)//:Pieza(jugador, rojo, verde, azul, radio, fila, columna)
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
	tablero.setJugador(fila, columna, jugador);
}

void Peon::dibuja()
{
	Pieza::dibuja();
	
	
}


bool Peon::mov_posible()
{
	//tenemos la


	return true;
}