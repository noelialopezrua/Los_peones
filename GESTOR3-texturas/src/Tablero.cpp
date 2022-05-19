#include "Tablero.h"
#include <stdio.h>
#include <iostream>


Tablero::Tablero()
{
	filas = 8;
	columnas = 8;

	//Matriz que nos sirve para dibujar
	c = new Casilla * [filas];//apuntamos a filas
	for (int i = 0; i < filas; i++) {
		c[i] = new Casilla[columnas];     //columnas
	}

	//Matriz de datos.

	posicion.x = 0.5;
	posicion.y = 0.5;
		
	for (int i = 0; i<8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			matriz[j][i] = { posicion.x,posicion.y };
			//printf("[%d]columna %f [%d]fila %f \n", i,posicion.x,j,posicion.y);
			posicion.x++;
	
		}
		posicion.x = 0.5;
		posicion.y++;
	}

	//Matriz de ocupado o no.
	
	ocupado[0][0] = ocupado[0][7] = ocupado[7][0] = ocupado[7][7] = 6;
	ocupado[2][0] = ocupado[5][0] = ocupado[2][7] = ocupado[5][7] = 1;
	ocupado[1][0] = ocupado[6][0] = ocupado[1][7] = ocupado[6][7] = 2;
	ocupado[4][0] = ocupado[4][7]  = 5;
	ocupado[3][0] = ocupado[3][7] = 4;

	for (int i = 0; i < 8; i++){
		ocupado[i][1] = 3;
		ocupado[i][6] = 3;
	}
	for (int i = 2; i < 6; i++) {
		for (int j = 0; j < 8; j++) {
			ocupado[j][i] = 0;

		}


	}
	
	
	for (int i = 0; i <2 ; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			jugador[j][i] = { 0 };
			//printf("[%d]columna %f [%d]fila %f %d \n", i,posicion.x,j,posicion.y,jugador[j][i]);

		}

	}
	
	for (int i = 6; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			jugador[j][i] = { 1 };
			//printf("[%d]fila %f [%d]columna %f %d \n", i, posicion.x, j, posicion.y, jugador[j][i]);

		}

	}

	for (int i = 2; i < 6; i++) {
		for (int j = 0; j < 8; j++) {
			jugador[j][i] = 2;

		}


	}
}

void Tablero::dibuja()
{
	int i, j;
	for (i = 0; i < 8; i++) {	//cada i es una fila del tablero
		for (j = 0; j < 8; j++) { //cada j es una columna del tablero
			c[i][j].dibuja(i, j);
		}
	}
}

void Tablero::setPosicion(float x, float y)
{
	posicion.x = x;
	posicion.y = y;
}

Vector2D Tablero::getCoordenada(int fila, int columna)
{

	Vector2D pos;
	pos = matriz[fila][columna];
	return pos;
}


void Tablero::setOcupado(int fila, int columna,int oc)
{
	ocupado[fila][columna]=oc;
	//esto hace que la casilla que le digamos (fila y columna) esté ocupada o no según que le pasamos, cero es que no está ocupada y si es un número representa el tipo de pieza que está en la casilla.
	//printf("%d %d : %d \n", fila, columna, oc);
}

void Tablero::setJugador(int fila, int columna, int jug)
{
	jugador[fila][columna] = jug;
	//esto hace que la casilla que le digamos (fila y columna) esté ocupada o no según que le pasamos, cero es que no está ocupada y si es un número representa el tipo de pieza que está en la casilla.
	//printf("%d %d : %d \n", fila, columna, oc);
}


bool Tablero::getOcupado(int fila, int columna)
{
	bool res;
	res = ocupado[fila][columna];
	return res;
	//esto hace que devuelva si la casilla que le decimos (fila y columna) está ocupada.

}

int Tablero::getJugador(int fila, int columna)
{
	bool res;
	res = jugador[fila][columna];
	return res;
	//esto hace que devuelva si la casilla que le decimos (fila y columna) está ocupada.

}

void Tablero::clickPieza()
{
	

	
}


