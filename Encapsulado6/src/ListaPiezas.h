#pragma once
#include "Pieza.h"
#include "Peon.h"
class ListaPiezas {

public:
	int nPeones;
	Pieza pieza;
	Peon* listaPeones[16];

	ListaPiezas();
	virtual~ListaPiezas();

	bool agregar(Peon* p);
	void dibuja_p();
	void SetRadiop(float,int);
	Vector2D GetPos(int);
	
};