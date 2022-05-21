#pragma once
#include "Pieza.h"

#include "ETSIDI.h"
using ETSIDI::Sprite;

class Reina :public Pieza {
public:
	Sprite sprite{ "imagenes/reinab.png" };
	Sprite sprite2{ "imagenes/reinan.png" };
	Reina();
	Reina(int j, float r, int f, int c);//:Pieza(jugador,rojo,verde,azul,radio,fila,columna){};
	void dibuja();
	
};
