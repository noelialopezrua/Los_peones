#include "Reina.h"
#include <stdio.h>
#include <iostream>
Reina::Reina() {

	fila = columna = 2;
	radio = 0.5;
	rojo = verde = azul = 255;
}


Reina::Reina(int j, float r, int f, int c)//:Pieza(jugador, rojo, verde, azul, radio, fila, columna)
{
	jugador = j;
	//0 es blanco
	if (jugador == 0) {
		rojo = verde = azul = 255;
	}
	else rojo = verde = azul = 0;
	radio = r;
	fila = f;
	columna = c;
}


void Reina::dibuja()
{
	Pieza::dibuja();
	tablero.setOcupado(fila, columna, REINA);
	
	
}

bool Reina::mov_posible(Vector2D pos1)
{
	int ocupado;
	
	std::cout << "HOLA CHICOS"<<pos1.x;
	printf("\n");
	std::cout << "ESTOY VIVO" << pos1.y;
	printf("\n");

	//printf("%d", tablero.ocupado[int(pos1.x)][int(pos1.y)]);

	// si la posición es cualquiera de las reinas
	//consultar en el vector de tablero si la posición está ocupada por una reina
	if (tablero.ocupado[int(pos1.y)][int(pos1.x)] == REINA) {
		ocupado = 1;
	
	printf("Reinaa de mi corasson\n");
	}
	//coger el segundo click
	pos2 = casilla.getClick1();
	if (pos1.x != pos2.x) {
		if (pos1.y != pos2.y)
			//Hay que comprobar sis se puede mover.
			printf("Ni reina ni pichas\n");
	}
	
	return false;
}