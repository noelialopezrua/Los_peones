#pragma once
#include "Vector2D.h"
#include "Pieza.h"

class Peon: public Pieza {

	unsigned char rojo, verde, azul;
	Vector2D posicion;
	float radio=1.5;
	//AQUI VA EL CONSTRUCTOR HEREDADO
	//Peon():Pieza() {};
	
public:

	void setPosicion(float, float);
	void setColor(unsigned char, unsigned char, unsigned char);
	void dibuja();
	void mueve(unsigned char);

};