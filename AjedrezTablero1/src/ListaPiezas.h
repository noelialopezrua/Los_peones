#pragma once
#include "Pieza.h"
#include "Torre.h"
class ListaPiezas {
public:
	int nTorres=0;
	Torre* listaTorres[4];
	ListaPiezas();
	virtual~ListaPiezas();

	bool agregar(Torre* t);
	void dibuja();
	//void mueve();
};