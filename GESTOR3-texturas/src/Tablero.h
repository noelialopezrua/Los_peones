#pragma once
#include "Casilla.h"

class Tablero {
public:
	int filas, columnas,fila1,columna1;
	Casilla casilla;
	Casilla** c;
	Vector2D matriz[8][8];
	int ocupado[8][8];//almacena valores en función del tipo de pieza que la ocupa.
	int jugador[8][8];
	Vector2D posicion;
	Vector2D click;
	Tablero();
	void dibuja();
	void setPosicion(float,float);

	Vector2D getCoordenada(int,int);
	float getCoordenada_texturaY(int,int);
	float getCoordenada_texturaX(int,int);

	//le das fila y columna y marca en nuestra matriz que esa casilla está ocupada.
	void setOcupado(int, int,int); 
	void setJugador(int, int, int);
	//le das fila y columna y te devuelve si está ocupada la casilla o no.
	bool getOcupado(int, int);
	int getJugador(int, int);

	void clickPieza();//iguala la posición de click en filas y columnas.


};