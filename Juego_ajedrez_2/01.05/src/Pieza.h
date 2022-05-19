#pragma once
#include "Vector2D.h"
#include "Tablero.h"
class Pieza {
public:
	Pieza();
	Pieza(int, unsigned char, unsigned char, unsigned char,float,int,int);
	int jugador;
	Vector2D pos_init,pos_final;
	int fila, columna;
	enum Tipo_pieza { REY, REINA, ALFIL, CABALLO, TORRE, PEON };
	unsigned char rojo, azul, verde;
	float radio;
	Tablero tablero;
	

	void dibuja();
	void SetRadio(float r);
	void SetColor(float r, float v, float a);
	

	float GetRadio();
	float GetColor();
	float GetPos();


};