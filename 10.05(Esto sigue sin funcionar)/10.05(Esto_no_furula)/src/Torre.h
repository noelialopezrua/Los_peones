#pragma once
#include "Pieza.h"
#include "Tablero.h"
class Torre :public Pieza {
public:
	
	Torre();
	Torre(int j, float r, int f, int c);//:Pieza(jugador,rojo,verde,azul,radio,fila,columna){};

	void dibuja();
	bool mov_posible();
	void SetPos(int f, int c);
};