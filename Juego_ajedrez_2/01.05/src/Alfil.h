#pragma once
#include "Pieza.h"
#include "Tablero.h"
class Alfil :public Pieza {
public:

	Alfil();
	Alfil(int j, float r, int f, int c);//:Pieza(jugador,rojo,verde,azul,radio,fila,columna){};

	bool mov_posible(Vector2D pos_init, Vector2D pos_final);
};