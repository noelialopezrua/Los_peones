#include "Rey.h"
#include <stdio.h>
#include <math.h>

#include <cmath>

Rey::Rey() {

	fila = columna = 2;
	radio = 0.5;
	rojo = verde = azul = 255;
}


Rey::Rey(int j, float r, int f, int c)//:Pieza(jugador, rojo, verde, azul, radio, fila, columna)
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


void Rey::dibuja()
{
	Pieza::dibuja();
	
	
}

Vector2D Rey::mov_posible(Vector2D pos1,Vector2D pos2, int n)
{

	Vector2D retorno;        //El x sera si es posible el movimiento, la y nos dirá si va a comer una pieza
	// si la posición es cualquiera de las reinas
	//consultar en el vector de tablero si la posición está ocupada por una reina
	retorno.x = 0;
	retorno.y= 0;
	//printf("%f %f vvvvvv", v.x, v.y);
	
	//if (n % 2 == 0)// Segundo click
	//{
	//	printf(" pinta %f %f\n", pos1.y, pos1.x);
	//	printf("Jugador pos1 % d     ", tablero.jugador[int(pos1.y)][int(pos1.x)]);
	//	printf("Ocupado pos1 %d\n", tablero.ocupado[int(pos1.y)][int(pos1.x)]);
	//	printf("pinta %f %f\n", pos2.y, pos2.x);
		printf("Jugador pos2 % d    ", tablero.jugador[int(pos2.y)][int(pos2.x)]);
		printf("Ocupado pos2 %d\n", tablero.ocupado[int(pos2.y)][int(pos2.x)]);
	//}
 //SEGUNDO CLICK
		//SI HE SELECCIONADO UNA REINA EN EL PRIMER CLICK
		if (tablero.ocupado[int(pos1.y)][int(pos1.x)] == REY) {
			printf("SOY UN REY\n");


			////CASOS.
			//// Se puede mover y casilla no está ocupada.
			
			if (tablero.ocupado[int(pos2.y)][int(pos2.x)] == 0) { 
				printf("estoy por aquí chicos\n");//si la casilla no está ocupada
			//	//y quiero ir una casilla que está en diagonal o recto desde mi posición
				if (abs(pos2.y - pos1.y) == abs(pos2.x - pos1.x) == 1) {//DIAGONAL
					printf("Se puede mover en diagonal\n");
					printf("%f %f", pos2.y, pos2.x);
					columna = pos2.x;
					fila = pos2.y;
					tablero.ocupado[int(pos1.y)][int(pos1.x)] = 0;
					tablero.ocupado[int(pos2.y)][int(pos2.x)] = REY;

					tablero.jugador[int(pos1.y)][int(pos1.x)] = 0;
					tablero.jugador[int(pos2.y)][int(pos2.x)] = jugador;
					//printf("COSAS VARIAS %d  %d  %d  %d\n", tablero.ocupado[int(pos1.y)][int(pos1.x)], tablero.ocupado[int(pos2.y)][int(pos2.x)], tablero.jugador[int(pos1.y)][int(pos1.x)], tablero.jugador[int(pos2.y)][int(pos2.x)]);
					//1.se llama a un gestor de movimientos -> la pieza a su nuevo lugar
					//2.cambiar la matriz de ocupar
					retorno.x = 1;
					//3.cambiar de jugador en pieza mueve.

				}

				else if ((abs(pos2.x - pos1.x) == 0 && abs(pos2.y - pos1.y) == 1) || (abs(pos2.x - pos1.x) == 1 && abs(pos2.y - pos1.y) == 0)) {
					printf("Se puede mover recto\n");
					printf("%f %f", pos2.y, pos2.x);
					columna = pos2.x;
					fila = pos2.y;
					tablero.ocupado[int(pos1.y)][int(pos1.x)] = 0;
					tablero.ocupado[int(pos2.y)][int(pos2.x)] = REY;

					tablero.jugador[int(pos1.y)][int(pos1.x)] = 0;
					tablero.jugador[int(pos2.y)][int(pos2.x)] = jugador;
					retorno.x = 1;
				}
			}

			//SI LA CASILLA ESTÁ OCUPADA
			else if (tablero.ocupado[int(pos2.y)][int(pos2.x)] != 0) {
				if (tablero.jugador[int(pos2.y)][int(pos2.x)] == tablero.jugador[int(pos1.y)][int(pos1.x)])//me quiero comer a uno de mi equipo.
					retorno.x = 0; //el movimiento no es posible.
				else if (tablero.jugador[int(pos2.y)][int(pos2.x)] != tablero.jugador[int(pos1.y)][int(pos1.x)]) {
					//LLAMAR A FUNCIÓN COMER
					//ComerPieza(pos2);
					columna = pos2.x;
					fila = pos2.y;
					tablero.ocupado[int(pos1.y)][int(pos1.x)] = 0;
					tablero.ocupado[int(pos2.y)][int(pos2.x)] = REY;

					tablero.jugador[int(pos1.y)][int(pos1.x)] = 0;
					tablero.jugador[int(pos2.y)][int(pos2.x)] = jugador;
					retorno.y = 1;
					retorno.x = 1;
				}
			}
		
	}
	return retorno;
}