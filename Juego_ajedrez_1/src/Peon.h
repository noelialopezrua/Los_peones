#pragma once
#include "Vector2D.h"

class Peon {

	float radio=1.5;
	unsigned char rojo, verde, azul;
	Vector2D posicion;

public:

	void setPosicion(float, float);
	void setColor(unsigned char, unsigned char, unsigned char);
	void dibuja();
	void mueve(unsigned char);

};