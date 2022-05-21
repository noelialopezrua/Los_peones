#pragma once
#include "Vector2D.h"



class Pieza {
public:
	Pieza();
	Pieza(int, unsigned char, unsigned char, unsigned char,float,int,int);
	int socorro = 1;

protected:
	int jugador;
	
	int r;
	int fila, columna;
	unsigned char rojo, azul, verde;
	float radio;
	
	Vector2D pos1;
	enum tipoPieza {ALFIL=1,CABALLO,PEON,REINA,REY,TORRE};
	
public:
	

	void dibuja();
	void SetRadio(float r);
	void SetSocorro(int s);
	void SetJugador(int j);
	void SetPos(int f, int c);
	void SetColor(float r, float v, float a);
	void SetFila(int);
	void SetColumna(int);
	void SetPos(Vector2D);


	int GetFila();
	int GetColumna();
	float GetRadio();
	float GetColor();
	Vector2D GetPos();



	


};