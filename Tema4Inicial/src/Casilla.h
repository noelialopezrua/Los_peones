#pragma once
#include"Vector2D.h"
class Casilla {
public:
	Casilla(); //Constructor
	//Atributos;
	float x, y;
	bool seleccionado;

	//Objetos
	Vector2D posicion;

	//M�todos
	void dibuja(int, int);
};