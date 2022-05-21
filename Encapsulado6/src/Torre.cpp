#include "Torre.h"

Torre::Torre() {
	//(0,0) (0,7) (7,0) (7,7)

	radio = 0.4;
	rojo = verde = azul = 255;
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
	
}


void Torre::dibuja()
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

bool Torre::mov_posible()
{

	return false;
}
