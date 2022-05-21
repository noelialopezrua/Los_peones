#pragma once
#include "Casilla.h"

class Tablero {

	int filas, columnas;
	Casilla casilla;
	Casilla** c;
	Vector2D posicion;
	
public:
	
	Tablero();
	void dibuja();
	void setPosicion(float,float);
	
	int ocupado[8][8];
	int jugador[8][8];

};