#include "Alfil.h"
#include <stdio.h>

Alfil::Alfil() {

	rojo = verde = azul = 255;

}



void Alfil::dibuja()
{
	
	Pieza::dibuja();
	if (jugador == 0) {
		
			sprite.setCenter(-fila, -columna);
			sprite.setSize(socorro, socorro);
			sprite.draw();
		
	}
	if (jugador == 1) {

			sprite2.setCenter(-fila, -columna);
			sprite2.setSize(socorro, socorro);
			sprite2.draw();
		
	}

}


bool Alfil::mov_posible()
{

	return false;
}





	