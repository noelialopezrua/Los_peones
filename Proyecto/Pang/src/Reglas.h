#pragma once

#include <vector>
#include <iostream>
#include <windows.h>

#include "Vector2D.h"
#include "FichaBlanca.h"
#include "FichaNegra.h"

class Reglas
{
protected:
	std::vector <Ficha*> listaFichasBl;
	std::vector <Ficha*> listaFichasNe;
	
	int fichaAComerDer[12] ;//  indica que ficha puede ser comida por la ficha  indicada en diag
	int fichaAComerIzq[12];

private:
	bool turno;
	Vector2D posicionActual;
	Vector2D posicionSiguiente;

public:
	Reglas();
	bool diagDer[20];// si diagDer[3]==true, significa que la ficha 3 puede comer a la derecha
	bool diagIzq[20];

	bool diagIzqTras[20];
	bool diagDerTras[20];

	//BLANCAS
	bool movDiagUnit();//devuelve '1' si el movimiento que se quiere realizar es una diagonal unitaria, y además no pisa a otra ficha
	bool fichaComida();//devuelve '1' si el movimiento de comer se ha realizado correctamente
	bool posibleComerFicha();//devuelve '1' si es posible para blancas comer alguna ficha

	void hacerReina();
	void hacerReinaBot();
	bool moverReina();
	bool posibleComerConReina();
	bool fichaComidaConReina();
	

	//negras
	bool movDiagUnitN();
	bool posibleComerFichaN();
	bool fichaComidaN();

	void hacerReinaN();
	bool posibleComerConReinaN();
	bool fichaComidaConReinaN();

	//control
	bool cambiarTurno();
	bool getTurno();
	void setPosAct(Vector2D);
	void setPosSig(Vector2D);
	void setListaFichas(std::vector <Ficha*>, std::vector <Ficha*>);//cuando se llama desde tablero, los vectores de Reglas adquieren las posiciones de los de tablero
	void delListaFichas(std::vector <Ficha*>, std::vector <Ficha*>);//cuando se llama desde tablero, los vectores de tablero adquieren el estado de los de regla
	~Reglas();
};
