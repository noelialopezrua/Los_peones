#pragma once
#include "Casilla.h"
class Tablero {
public:
	int filas, columnas;
	Casilla** c;
	Vector2D matriz[8][8];
	Vector2D posicion;
	Tablero();
	void dibuja();
	void setPosicion(float,float);

	Vector2D getCoordenada(int,int);


};