#pragma once
#include "Pieza.h"
#include "Tablero.h"
class Rey :public Pieza {
public:

	Rey();
	Rey(int j, float r, int f, int c);//:Pieza(jugador,rojo,verde,azul,radio,fila,columna){};

	void dibuja();
	Vector2D mov_posible(Vector2D,Vector2D,int);
};
