#pragma once



#include <vector>
#include <iostream>
#include "Casilla.h"
#include "Ficha.h"
#include "FichaBlanca.h"
#include "FichaNegra.h"
#include "Reglas.h"
#include "Graficos.h"
#include "ReglasBot.h"



class Tablero
{
public:

	Tablero();
	
	std::vector <Ficha*> listaFichasB;
	std::vector <Ficha*> listaFichasN;

	//Objetos
	Reglas regla;
	Casilla **c;//para las casillas inciales
	Casilla hand;
	Graficos graf;
	ReglasBot bot;
	
	
	//Variables
	int i, j, n, m;
	bool turno;// 0 negras, 1 blancas
	int controlSeleccion;//variable de control para los if del onkeyboardDown (evita que se actualicen instantáneamente)
	float cont1, cont2, cont3;

	//Metodos
	void dibujarTablero();
	void dibujarFichasIniciales();
	void moverMano(unsigned char tecla);
	
	void dibujarCementerio();
	void Animacion();
	void jugarBot();
	void marcarJugadaBot();

	~Tablero();
};