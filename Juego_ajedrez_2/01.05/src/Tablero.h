#pragma once
#include "Casilla.h"
class Tablero {
public:
	int filas, columnas;
	Casilla** c;
	Vector2D matriz[8][8];
	bool ocupado[8][8];
	Vector2D posicion;
	Tablero();
	void dibuja();
	void setPosicion(float,float);

	Vector2D getCoordenada(int,int);

	//le das fila y columna y marca en nuestra matriz que esa casilla está ocupada.
	void setOcupado(int, int,bool); 
	//le das fila y columna y te devuelve si está ocupada la casilla o no.
	bool getOcupado(int, int);


};