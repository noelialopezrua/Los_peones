#pragma once
#include "Vector2D.h"
#include "Tablero.h"
class Pieza {
public:
	Pieza();
	Pieza(int, unsigned char, unsigned char, unsigned char,float,int,int);

	int jugador;
	int fila, columna;
	unsigned char rojo, azul, verde;
	float radio;
	Tablero tablero;
	Casilla casilla;
	enum tipoPieza {ALFIL=1,CABALLO,PEON,REINA,REY,TORRE};
	

	void dibuja();
	void SetRadio(float r);
	void SetColor(float r, float v, float a);
	


	float GetRadio();
	float GetColor();
	float GetPos();


};