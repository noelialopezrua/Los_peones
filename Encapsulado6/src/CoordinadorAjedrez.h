#pragma once
#include"Mundo.h"

class CoordinadorAjedrez
{
public:

	Mundo mundo1;
	CoordinadorAjedrez();
	virtual ~CoordinadorAjedrez();

	void teclaEspecial(unsigned char key);
	void tecla(unsigned char key);
	void mueve();
	void dibuja();
	
protected:
	enum Estado {INICIO, JUEGO, FIN, GAMEOVER};
	Estado estado;
};