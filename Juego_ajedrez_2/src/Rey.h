#pragma once
#include "Pieza.h"
#include "Alfil.h"
class Rey : public Pieza {

	unsigned char rojo, verde, azul;
	Vector2D posicion;
	float radio = 1.5;
public:
	void setPosicion(float, float);
	void setColor(unsigned char, unsigned char, unsigned char);
	void dibuja();
	void mueve(unsigned char);
};