#pragma once
#include "glut.h"
#include "Ficha.h"

class FichaNegra : public Ficha
{
public:
	FichaNegra(int f, int c);
	static int contador ;
	void dibujarFicha(void);


	~FichaNegra();


};