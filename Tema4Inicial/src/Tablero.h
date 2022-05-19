#pragma once
#include "Casilla.h"
class Tablero {
public:
	int filas, columnas;
	Casilla** c;
	Tablero();
	void dibuja();
};