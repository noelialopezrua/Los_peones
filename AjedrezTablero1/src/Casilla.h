#pragma once
#include"Vector2D.h"
class Casilla {
public:
	Casilla(); //Constructor
	//Atributos;

	bool seleccionado;

	//Objetos
	Vector2D posicion;

	//Métodos
	void dibuja(int, int);
	void setCasilla();
	Vector2D clickcas(int boton, int estado, int x, int y);
	Vector2D getCasilla();
};