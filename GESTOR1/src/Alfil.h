#pragma once
#include "Pieza.h"
#include "Tablero.h"
class Alfil :public Pieza {
public:

	Alfil();
	Alfil(int j, float r, int f, int c);//:Pieza(jugador,rojo,verde,azul,radio,fila,columna){};
	void dibuja();
	bool mov_posible();
};