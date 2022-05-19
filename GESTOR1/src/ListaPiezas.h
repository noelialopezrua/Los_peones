#pragma once
#include "Pieza.h"
#include "Torre.h"
#include "Alfil.h"
#include "Caballo.h"
#include "Rey.h"
#include "Reina.h"
#include "Peon.h"
class ListaPiezas {

public:
	int nTorres, nAlfiles, nCaballos, nReyes, nReinas, nPeones;
	Pieza pieza;
	Casilla casilla;
	Tablero tablero;
	Peon* listaPeones[16];

	ListaPiezas();
	virtual~ListaPiezas();

	bool agregar(Peon* p);
	void dibuja_p();
	void mueve(Vector2D, int);
	void ComerPieza(Vector2D v);
	//void MuevePieza();
};