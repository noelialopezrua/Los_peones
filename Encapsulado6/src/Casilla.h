#pragma once
#include"Vector2D.h"
class Casilla {

private:

	int nClick = 0;
	Vector2D posicion;

public:
	Casilla();
	//Métodos
	void dibuja(int, int);
	void setCasilla();
	Vector2D clickcas(int boton, int estado, int x, int y);
	
	Vector2D getCasilla();

};