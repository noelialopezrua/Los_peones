#include "Torre.h"

Torre::Torre() {
	//(0,0) (0,7) (7,0) (7,7)

	fila = columna = 2;
	radio = 0.4;

	
}


Torre::Torre(int j, float r, int f, int c)//:Pieza(jugador, rojo, verde, azul, radio, fila, columna)
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


void Torre::dibuja()
{
	Pieza::dibuja();
	//tablero.setOcupado(fila, columna, TORRE);

	
}

bool Torre::mov_posible()
{

	return false;
}

void Torre::SetPos(int f, int c)
{
	f = fila;
	c = columna;
}
