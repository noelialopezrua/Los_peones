#pragma once

#include "glut.h"
#include "Vector2D.h"
#include "Reglas.h"

class Graficos
{
public:
	Graficos();

	//Objetos
	Reglas reg;
	//Metodos
	void DibTab();
	//Variables
	int vis; //Esta varible nos permite cambiar la vista a través del teclado.
	bool Turn;
	float ojo_y;
	int Escena;
	int ContBlancas;
	int ContNegras;


	~Graficos();
};

