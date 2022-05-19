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
	int nTorres,nAlfiles,nCaballos,nReyes,nReinas,nPeones;

	Casilla casilla;
	Torre* listaTorres[4];
	Alfil* listaAlfiles[4];
	Caballo* listaCaballos[4];
	Rey* listaReyes[2];
	Reina* listaReinas[2];
	Peon* listaPeones[16];

	ListaPiezas();
	virtual~ListaPiezas();

	bool agregar(Torre* t);
	bool agregar(Alfil* a);
	bool agregar(Caballo* c);
	bool agregar(Rey* rey);
	bool agregar(Reina* r);
	bool agregar(Peon* p);

	void dibuja_t();
	void dibuja_a();
	void dibuja_c();
	void dibuja_rey();
	void dibuja_r();
	void dibuja_p();
	void mueve(Vector2D);
};