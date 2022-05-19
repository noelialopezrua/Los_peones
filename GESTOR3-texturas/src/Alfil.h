#pragma once
#include "Pieza.h"
#include "Tablero.h"
#include "ETSIDI.h"
using ETSIDI::Sprite;

class Alfil :public Pieza {

	
	Sprite sprite{ "imagenes/alfilb.png" };

public:
	Tablero tablero;
	Alfil();
	Alfil(int j, float r, int f, int c);//:Pieza(jugador,rojo,verde,azul,radio,fila,columna){};
	void dibuja();
	bool mov_posible();
};