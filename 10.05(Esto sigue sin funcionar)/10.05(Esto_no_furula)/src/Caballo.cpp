#include "Caballo.h"

Caballo::Caballo() {

	fila = columna = 2;
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
	tablero.setJugador(fila, columna, jugador);
}


bool Caballo::mov_posible()
{

	return false;
}

void Caballo::dibuja()
{
	Pieza::dibuja();
	//tablero.setOcupado(fila, columna, CABALLO);
	
}
