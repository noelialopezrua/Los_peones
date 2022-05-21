#pragma once
#include "Pieza.h"
#include "ETSIDI.h"
using ETSIDI::Sprite;

class Caballo :public Pieza {
public:
	Sprite sprite{ "imagenes/caballob.png" };
	Sprite sprite2{ "imagenes/caballon.png" };
	Caballo();
	Caballo(int j, float r, int f, int c);//:Pieza(jugador,rojo,verde,azul,radio,fila,columna){};

	bool mov_posible();
	void dibuja();
};