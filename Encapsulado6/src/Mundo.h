#pragma once
#include "Tablero.h"
#include "Pieza.h"
#include "Torre.h"
#include "ListaPiezas.h"
#include "GestorMovimiento.h"
#include "Alfil.h"
#include "Caballo.h"
#include "Rey.h"
#include "Reina.h"

class Mundo{
public: 

	Mundo();
	virtual ~Mundo();
	int turno = 0;
	int fin = 0;
	GestorMovimiento gestor;
	Tablero tablero;
	Casilla casilla;
	Vector2D vect_casilla,pos1,pos2,posaux;
	Pieza pieza;
	Torre torre1,torre2,torre3,torre4;
	Alfil alfil1, alfil2, alfil3, alfil4;
	Caballo caballo1, caballo2, caballo3, caballo4;
	Rey rey1, rey2;
	Reina reina1, reina2;
	ListaPiezas peones;
	
	void tecla(unsigned char key);
	void teclaEspecial(unsigned char key);
	void inicializa();
	void mueve(Vector2D,int);
	void dibuja();
	void comerPieza(Vector2D,int);
	void mundoFin();
	

	float x_ojo;
	float y_ojo;
	float z_ojo;
};
