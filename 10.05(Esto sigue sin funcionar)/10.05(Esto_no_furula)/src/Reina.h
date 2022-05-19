#pragma once
#include "Pieza.h"
#include "Tablero.h"

class Reina :public Pieza {
public:

	Reina();
	Reina(int j, float r, int f, int c);//:Pieza(jugador,rojo,verde,azul,radio,fila,columna){};
	void dibuja();
	Vector2D mov_posible(Vector2D,int);
};
