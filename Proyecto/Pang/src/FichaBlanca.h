#pragma once
#include "glut.h"
#include "Ficha.h"

class FichaBlanca: public Ficha
{
public:
	FichaBlanca(int f, int c);
	
	void dibujarFicha(void);


	~FichaBlanca();


};
