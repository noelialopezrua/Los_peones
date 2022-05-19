#pragma once
#include "Vector2D.h"

class Pieza
{
	unsigned char rojo, verde, azul;
	Vector2D posicion;
	//virtual~Pieza() {};
	//Pieza() {};
public:
	void setPosicion(float, float);
	void setColor(unsigned char, unsigned char, unsigned char);
	
};