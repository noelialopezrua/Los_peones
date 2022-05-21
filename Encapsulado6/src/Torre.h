#pragma once
#include "Pieza.h"
#include "ETSIDI.h"
using ETSIDI::Sprite;

class Torre :public Pieza {
public:
	Sprite sprite{ "imagenes/torreb.png" };
	Sprite sprite2{ "imagenes/torren.png" };
	Torre();
	Torre(int j, float r, int f, int c);//:Pieza(jugador,rojo,verde,azul,radio,fila,columna){};

	void dibuja();
	bool mov_posible();
};