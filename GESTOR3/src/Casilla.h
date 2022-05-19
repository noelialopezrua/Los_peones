#pragma once
#include"Vector2D.h"
class Casilla {
public:
	Casilla(); //Constructor
	//Atributos;
	

	bool seleccionado;
	int nClick = 0;
		
	

	//Objetos
	Vector2D posicion;
	Vector2D click1;
	
	

	int x = 5;

	//Métodos
	void dibuja(int, int);
	void setCasilla();
	Vector2D clickcas(int boton, int estado, int x, int y);
	
	Vector2D getCasilla();

	Vector2D getClick1();

};