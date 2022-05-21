#pragma once
#include "Pieza.h"
#include "Tablero.h"
#include "ETSIDI.h"
using ETSIDI::Sprite;
class Rey :public Pieza {
public:
	Sprite sprite{ "imagenes/reyb.png" };
	Sprite sprite2{ "imagenes/reyn.png" };

	Rey();
	Rey(int j, float r, int f, int c);//:Pieza(jugador,rojo,verde,azul,radio,fila,columna){};

	void dibuja();
	
};
