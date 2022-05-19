#pragma once
#include "Pieza.h"
#include "Tablero.h"
class Rey :public Pieza {
public:

	Rey();
	Rey(int j, float r, int f, int c);//:Pieza(jugador,rojo,verde,azul,radio,fila,columna){};

	void dibuja();
	bool mov_posible();
};
