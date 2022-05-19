#pragma once
#include "Casilla.h"
class Tablero {
public:
	int filas, columnas,fila1,columna1;
	Casilla casilla;
	Casilla** c;
	Vector2D matriz[8][8];
	int ocupado[8][8]; //almacena valores en función del tipo de pieza que la ocupa.
	Vector2D posicion;
	Tablero();
	void dibuja();
	void setPosicion(float,float);

	Vector2D getCoordenada(int,int);

	//le das fila y columna y marca en nuestra matriz que esa casilla está ocupada.
	void setOcupado(int, int,int); 
	//le das fila y columna y te devuelve si está ocupada la casilla o no.
	bool getOcupado(int, int);

	void clickPieza(Vector2D clicky);//iguala la posición de click en filas y columnas.


};