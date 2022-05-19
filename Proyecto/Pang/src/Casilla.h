#pragma once
#include "glut.h"
#include "Vector2D.h"
class Casilla
{
public:
	Casilla();

	//Variables
	float fm, cm;
	bool seleccionada;
	

	//Objetos
	Vector2D fichaSeleccionada;
	Vector2D posicion;
	Vector2D mano;
	Vector2D posAnteriorBot;//guarda la posicion original de la última ficha movida por el bot(se actualiza cada turno desde tablero)

	//Metodos.
	void dibujarCasilla(int f, int c);
	void dibujarManoBlanca(void);
	void dibujarManoNegra(void);
	void dibujarSeleccion(void);
	void dibujarJugadaBot(void);//d

	~Casilla();
};

