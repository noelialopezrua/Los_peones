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
	Vector2D pos1, pos2;
	enum tipoPieza {ALFIL=1,CABALLO,PEON,REINA,REY,TORRE};
	

	void dibuja();
	void SetRadio(float r);
	void SetJugador(int j);
	//void SetPos(int f, int c);
	void SetColor(float r, float v, float a);
	//void ComerPieza(Vector2D);
	
	Vector2D getPos1();
	Vector2D getPos2();


	float GetRadio();
	float GetColor();
	Vector2D GetPos();

	Vector2D GetPosi(Pieza);


	void ComerPieza(Vector2D v);


};