#pragma once
#include "Reglas.h"
#include "Jugada.h"

//esta clase solo mueve fichas negras
class ReglasBot : public Reglas {//heredamos las dos listas de fichas de Reglas, pero no los metodos private ni el constructor
//¿posicion actual y siguiente no se heredan?; ahora posicion siguiente tiene que ser un vector con TODAS las posiciones siguientes posibles
	/////////////////variables
public:
	
	Jugada posActSigu;
	bool mode;
	int idFicha;
	int FinBot = 0;
	//bool diagIzqTras[20];
	//bool diagDerTras[20];
	
	std::vector <Jugada> posibPosSiguientes;
	std::vector <Jugada> posMismaPrioridad;
	////////////////////metodos


	bool calcularPosicionesPosibles();
	Jugada* elegirMejorMov(void);
	bool posibleComerConReinaBot();

	~ReglasBot();
};