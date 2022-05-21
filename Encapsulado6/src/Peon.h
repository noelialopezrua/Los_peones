#pragma once
#include "Pieza.h"
#include "ETSIDI.h"
using ETSIDI::Sprite;

class Peon :public Pieza {
public:
	Sprite sprite{ "imagenes/peonb.png" };
	Sprite sprite2{ "imagenes/peonn.png" };
	Peon();
	Peon(int j, float r, int f, int c);//:Pieza(jugador,rojo,verde,azul,radio,fila,columna){};
	void dibuja();
	bool mov_posible();
};
