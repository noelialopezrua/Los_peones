#include "Alfil.h"

Alfil::Alfil() {

	fila = columna = 2;
	radio = 0.5;
	rojo = verde = azul = 255;

	
	Vector2D coordenada;
	coordenada = tablero.getCoordenada(columna, fila);
	sprite.setCenter(coordenada.x, coordenada.y);
	sprite.setSize(2, 2); 

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
	tablero.setJugador(fila, columna, jugador);
	
}

void Alfil::dibuja()
{
	Pieza::dibuja();

	sprite.draw();
	
}


bool Alfil::mov_posible()
{

	return false;
}




	