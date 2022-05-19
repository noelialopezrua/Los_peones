#pragma once
#include "Pieza.h"
#include "Tablero.h"
class Torre :public Pieza {
public:
	
	Torre();
	Torre(int j, float r, int f, int c);

	bool mov_posible(Vector2D pos_init, Vector2D pos_final);
};