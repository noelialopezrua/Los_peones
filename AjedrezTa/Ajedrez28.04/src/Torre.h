#pragma once
#include "Pieza.h"
#include "Tablero.h"
class Torre :public Pieza {
public:
	
	Torre();

	bool mov_posible(Vector2D pos_init, Vector2D pos_final);
};