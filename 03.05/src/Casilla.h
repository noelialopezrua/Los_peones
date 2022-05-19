#pragma once
#include"Vector2D.h"
class Casilla {
public:
	Casilla(); //Constructor
	//Atributos;
	float fila1 = 0, columna1 = 0, fila2 = 0, columna2 = 0;
	float fila_alm = 0, columna_alm = 0;

	bool seleccionado;
	int nClick=0
		;
	

	//Objetos
	Vector2D posicion;
	Vector2D click;

	//Métodos
	void dibuja(int, int);
	void setCasilla();
	Vector2D clickcas(int boton, int estado, int x, int y);
	
	Vector2D getCasilla();
};