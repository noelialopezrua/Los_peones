#pragma once
#include "Vector2D.h"
#include "Pieza.h"
#include "Tablero.h"
class GestorMovimiento
{
public:
	Tablero tablero;
	Vector2D gestorREINA(Vector2D, Vector2D,int);
	Vector2D gestorREY(Vector2D, Vector2D,int);
	
};


