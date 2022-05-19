#pragma once
#include "Pieza.h"
#include "Torre.h"
#include "Alfil.h"
class ListaPiezas {
public:
	int nTorres;
	int nAlfiles;
	Torre* listaTorres[4];
	Alfil* listaAlfiles[4];
	ListaPiezas();
	virtual~ListaPiezas();

	bool agregar(Torre* t);
	bool agregar(Alfil* a);
	void dibuja();
	//void mueve();
};