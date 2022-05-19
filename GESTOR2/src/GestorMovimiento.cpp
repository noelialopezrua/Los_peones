#include "GestorMovimiento.h"
#include <stdio.h>
#include <math.h>
#include <cmath>

Vector2D GestorMovimiento::gestorREINA(Vector2D pos1, Vector2D pos2, int c)
{
	Vector2D retorno;        //El x sera si es posible el movimiento, la y nos dirá si va a comer una pieza
	// si la posición es cualquiera de las reinas
	//consultar en el vector de tablero si la posición está ocupada por una reina
	retorno.x = 0;
	retorno.y = 0;

	if (tablero.ocupado[int(pos1.x)][int(pos1.y)] == 4){
		printf("Reinaa de mi corasson\n");


		////CASOS.
		//// Se puede mover y casilla no está ocupada.

		if (tablero.ocupado[int(pos2.x)][int(pos2.y)] == 0) { //si la casilla no está ocupada
		//	//y quiero ir una casilla que está en diagonal o recto desde mi posición
			if (abs(pos2.x - pos1.x) == abs(pos2.y - pos1.y)) {//DIAGONAL
				printf("Se puede mover en diagonal\n");
				printf("%f %f", pos2.x, pos2.y);
				/*columna = pos2.x;
				fila = pos2.y;*/
				tablero.ocupado[int(pos1.x)][int(pos1.y)] = 0;
				tablero.ocupado[int(pos2.x)][int(pos2.y)] = 4;

				tablero.jugador[int(pos1.x)][int(pos1.y)] = 2;
				tablero.jugador[int(pos2.x)][int(pos2.y)] = c;
				retorno.x = 1;
				//3.cambiar de jugador en pieza mueve.

			}

			else if ((abs(pos2.y - pos1.y) == 0 && abs(pos2.x - pos1.x) != 0) || (abs(pos2.y - pos1.y) != 0 && abs(pos2.x - pos1.x) == 0)) {
				printf("Se puede mover recto\n");
				printf("%f %f", pos2.x, pos2.y);
				
				tablero.ocupado[int(pos1.x)][int(pos1.y)] = 0;
				tablero.ocupado[int(pos2.x)][int(pos2.y)] = 4;

				tablero.jugador[int(pos1.x)][int(pos1.y)] = 2;
				tablero.jugador[int(pos2.x)][int(pos2.y)] = c;
				retorno.x = 1;
			}
		}

		//SI LA CASILLA ESTÁ OCUPADA
		else if (tablero.ocupado[int(pos2.x)][int(pos2.y)] != 0) {
			if (tablero.jugador[int(pos2.x)][int(pos2.y)] == tablero.jugador[int(pos1.x)][int(pos1.y)])//me quiero comer a uno de mi equipo.
				retorno.x = 0; //el movimiento no es posible.
			else if (tablero.jugador[int(pos2.x)][int(pos2.y)] != tablero.jugador[int(pos1.x)][int(pos1.y)]) {
				if ((abs(pos2.x - pos1.x) == abs(pos2.y - pos1.y)) || ((abs(pos2.y - pos1.y) == 0 && abs(pos2.x - pos1.x) != 0) || (abs(pos2.y - pos1.y) != 0 && abs(pos2.x - pos1.x) == 0))) {
					//LLAMAR A FUNCIÓN COMER
					//ComerPieza(pos2);

					tablero.ocupado[int(pos1.x)][int(pos1.y)] = 0;
					tablero.ocupado[int(pos2.x)][int(pos2.y)] = 4;

					tablero.jugador[int(pos1.x)][int(pos1.y)] = 2;
					tablero.jugador[int(pos2.x)][int(pos2.y)] = c;
					
					retorno.y = 1;
					retorno.x = 1;
				}
			}
		}
	}
	//}

	return retorno;

}

Vector2D GestorMovimiento::gestorREY(Vector2D pos1, Vector2D pos2,int c)
{
	Vector2D retorno;        //El x sera si es posible el movimiento, la y nos dirá si va a comer una pieza
	// si la posición es cualquiera de las reinas
	//consultar en el vector de tablero si la posición está ocupada por una reina
	retorno.x = 0;
	retorno.y = 0;

	//}
 //SEGUNDO CLICK
		//SI HE SELECCIONADO UNA REINA EN EL PRIMER CLICK
	if (tablero.ocupado[int(pos1.x)][int(pos1.y)] == 5) {
		printf("SOY UN REY\n");


		////CASOS.
		//// Se puede mover y casilla no está ocupada.

		if (tablero.ocupado[int(pos2.x)][int(pos2.y)] == 0) {
			printf("estoy por aquí chicos\n");//si la casilla no está ocupada
		//	//y quiero ir una casilla que está en diagonal o recto desde mi posición
			if (abs(pos2.x - pos1.x) == abs(pos2.y - pos1.y) == 1) {//DIAGONAL
			
		
				tablero.ocupado[int(pos1.x)][int(pos1.y)] = 0;
				tablero.ocupado[int(pos2.x)][int(pos2.y)] = 5;

				tablero.jugador[int(pos1.x)][int(pos1.y)] = 0;
				tablero.jugador[int(pos2.x)][int(pos2.y)] = c;
				//printf("COSAS VARIAS %d  %d  %d  %d\n", tablero.ocupado[int(pos1.y)][int(pos1.x)], tablero.ocupado[int(pos2.y)][int(pos2.x)], tablero.jugador[int(pos1.y)][int(pos1.x)], tablero.jugador[int(pos2.y)][int(pos2.x)]);
				//1.se llama a un gestor de movimientos -> la pieza a su nuevo lugar
				//2.cambiar la matriz de ocupar
				retorno.x = 1;
				//3.cambiar de jugador en pieza mueve.

			}

			else if ((abs(pos2.y - pos1.y) == 0 && abs(pos2.x - pos1.x) == 1) || (abs(pos2.y - pos1.y) == 1 && abs(pos2.x - pos1.x) == 0)) {
			
				tablero.ocupado[int(pos1.x)][int(pos1.y)] = 0;
				tablero.ocupado[int(pos2.x)][int(pos2.y)] = 5;

				tablero.jugador[int(pos1.x)][int(pos1.y)] = 0;
				tablero.jugador[int(pos2.x)][int(pos2.y)] = c;
				retorno.x = 1;
			}
		}
		
		//SI LA CASILLA ESTÁ OCUPADA
		else if (tablero.ocupado[int(pos2.x)][int(pos2.y)] != 0) {
			if (tablero.jugador[int(pos2.x)][int(pos2.y)] == tablero.jugador[int(pos1.x)][int(pos1.y)])//me quiero comer a uno de mi equipo.
				retorno.x = 0; //el movimiento no es posible.
			else if (tablero.jugador[int(pos2.x)][int(pos2.y)] != tablero.jugador[int(pos1.x)][int(pos1.y)]) {
				if ((abs(pos2.x - pos1.x) == abs(pos2.y - pos1.y) == 1) || ((abs(pos2.y - pos1.y) == 0 && abs(pos2.x - pos1.x) == 1) || (abs(pos2.y - pos1.y) == 1 && abs(pos2.x - pos1.x) == 0))) {

					
					tablero.ocupado[int(pos1.x)][int(pos1.y)] = 0;
					tablero.ocupado[int(pos2.x)][int(pos2.y)] = 5;

					tablero.jugador[int(pos1.x)][int(pos1.y)] = 0;
					tablero.jugador[int(pos2.x)][int(pos2.y)] = c;
					retorno.y = 1;
					retorno.x = 1;
				}
			}
		}

	}
	return retorno;
}

Vector2D GestorMovimiento::gestorTORRE(Vector2D pos1, Vector2D pos2, int c)
{
	Vector2D retorno;        
	retorno.x = 0;
	retorno.y = 0;
	
	
	if (tablero.ocupado[int(pos1.x)][int(pos1.y)] == 6) {
		printf("TORRREEEESITAAAAAAAA\n");
		//// Se puede mover y casilla no está ocupada.

		if (tablero.ocupado[int(pos2.x)][int(pos2.y)] == 0) { //si la casilla no está ocupada
		//	//y quiero ir una casilla que está en diagonal o recto desde mi posición
			

			if ((abs(pos2.y - pos1.y) == 0 && abs(pos2.x - pos1.x) != 0) || (abs(pos2.y - pos1.y) != 0 && abs(pos2.x - pos1.x) == 0)) {
				printf("Se puede mover recto\n");
				printf("%f %f", pos2.x, pos2.y);

				tablero.ocupado[int(pos1.x)][int(pos1.y)] = 0;
				tablero.ocupado[int(pos2.x)][int(pos2.y)] = 6;

				tablero.jugador[int(pos1.x)][int(pos1.y)] = 2;
				tablero.jugador[int(pos2.x)][int(pos2.y)] = c;
				retorno.x = 1;
			}
		}

		//SI LA CASILLA ESTÁ OCUPADA
		else if (tablero.ocupado[int(pos2.x)][int(pos2.y)] != 0) {
			if (tablero.jugador[int(pos2.x)][int(pos2.y)] == tablero.jugador[int(pos1.x)][int(pos1.y)])//me quiero comer a uno de mi equipo.
				retorno.x = 0; //el movimiento no es posible.
			else if (tablero.jugador[int(pos2.x)][int(pos2.y)] != tablero.jugador[int(pos1.x)][int(pos1.y)]) {
				if ((abs(pos2.y - pos1.y) == 0 && abs(pos2.x - pos1.x) != 0) || (abs(pos2.y - pos1.y) != 0 && abs(pos2.x - pos1.x) == 0)) {
					//LLAMAR A FUNCIÓN COMER
					//ComerPieza(pos2);

					tablero.ocupado[int(pos1.x)][int(pos1.y)] = 0;
					tablero.ocupado[int(pos2.x)][int(pos2.y)] = 6;

					tablero.jugador[int(pos1.x)][int(pos1.y)] = 2;
					tablero.jugador[int(pos2.x)][int(pos2.y)] = c;

					retorno.y = 1;
					retorno.x = 1;
				}
			}
		}
	}
	//}

	return retorno;
}

Vector2D GestorMovimiento::gestorALFIL(Vector2D pos1, Vector2D pos2, int c)
{
	Vector2D retorno;        //El x sera si es posible el movimiento, la y nos dirá si va a comer una pieza
	// si la posición es cualquiera de las reinas
	//consultar en el vector de tablero si la posición está ocupada por una reina
	retorno.x = 0;
	retorno.y = 0;

	if (tablero.ocupado[int(pos1.x)][int(pos1.y)] == 1) {
		

		if (tablero.ocupado[int(pos2.x)][int(pos2.y)] == 0) { //si la casilla no está ocupada
		//	//y quiero ir una casilla que está en diagonal o recto desde mi posición
			if (abs(pos2.x - pos1.x) == abs(pos2.y - pos1.y)) {//DIAGONAL
			
				tablero.ocupado[int(pos1.x)][int(pos1.y)] = 0;
				tablero.ocupado[int(pos2.x)][int(pos2.y)] = 1;

				tablero.jugador[int(pos1.x)][int(pos1.y)] = 2;
				tablero.jugador[int(pos2.x)][int(pos2.y)] = c;
				retorno.x = 1;
				//3.cambiar de jugador en pieza mueve.

			}
		}

		//SI LA CASILLA ESTÁ OCUPADA
		else if (tablero.ocupado[int(pos2.x)][int(pos2.y)] != 0) {
			if (tablero.jugador[int(pos2.x)][int(pos2.y)] == tablero.jugador[int(pos1.x)][int(pos1.y)])//me quiero comer a uno de mi equipo.
				retorno.x = 0; //el movimiento no es posible.
			else if (tablero.jugador[int(pos2.x)][int(pos2.y)] != tablero.jugador[int(pos1.x)][int(pos1.y)]) {
				if ((abs(pos2.x - pos1.x) == abs(pos2.y - pos1.y))) {
					//LLAMAR A FUNCIÓN COMER
					//ComerPieza(pos2);

					tablero.ocupado[int(pos1.x)][int(pos1.y)] = 0;
					tablero.ocupado[int(pos2.x)][int(pos2.y)] = 1;

					tablero.jugador[int(pos1.x)][int(pos1.y)] = 2;
					tablero.jugador[int(pos2.x)][int(pos2.y)] = c;

					retorno.y = 1;
					retorno.x = 1;
				}
			}
		}
	}
	//}

	return retorno;
}
