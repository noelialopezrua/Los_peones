#pragma once
#include "Tablero.h"
#include <freeglut.h>
#include "Peon.h"
#include "Torre.h"
#include "Alfil.h"
#include "Rey.h"

class Mundo
{
public: 

	Tablero tablero;
	Peon peon;
	Torre torre;
	Alfil alfil;
	Rey rey;
	void tecla(unsigned char key);
	void inicializa();
	//void rotarOjo();
	void mueve();
	void dibuja();

	float x_ojo;
	float y_ojo;
	float z_ojo;
};
