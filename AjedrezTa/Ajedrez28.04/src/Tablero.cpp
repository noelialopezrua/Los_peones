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


