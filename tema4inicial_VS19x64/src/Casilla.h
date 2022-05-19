#pragma once
#include"Vector2D.h"
class Casilla {
public:
	Casilla(); //Constructor
	//Atributos;
	bool seleccionado;

	//Objetos
	Vector2D posicion_actual;

	//Métodos
	void dibuja(int, int);
};