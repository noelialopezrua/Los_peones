#pragma once
#include "Pieza.h"
#include "Tablero.h"
class Caballo :public Pieza {
public:

	Caballo();
	Caballo(int j, float r, int f, int c);//:Pieza(jugador,rojo,verde,azul,radio,fila,columna){};

	bool mov_posible();
	void dibuja();
};