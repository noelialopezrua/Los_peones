#pragma once
#include "glut.h"
#include "Vector2D.h"
class Ficha
{
public:
	Ficha();
	Vector2D posicion;
	//static int contador;
	virtual void dibujarFicha()= 0;
	int estado = 0;//0 viva, -1 muerta

	~Ficha();
};