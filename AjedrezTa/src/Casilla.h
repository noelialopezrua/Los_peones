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

	//Métodos
	void dibuja(int, int);
	Vector2D clickcas(int boton, int estado, int x, int y);
};