#include "Reglas.h"
Reglas::Reglas()
{
	turno = 1;//empiezan blancas (turno 1)
	//incializacion de las listas de fichas (no se si es necesario)
	int i, j;
	for (i = 0; i < 3; i++) {

		for (j = 0; j < 8; j++) {
			if ((i + j) % 2 == 0) {

				listaFichasBl.push_back(new FichaBlanca(i, j));
			}
		}
	}
	//negras

	for (i = 5; i < 8; i++) {

		for (j = 0; j < 8; j++) {
			if ((i + j) % 2 == 0) {
				listaFichasNe.push_back(new FichaNegra(i, j));
			}
		}
	}
}



bool Reglas::movDiagUnit() {
	int i;
	bool aux = false;
	//primero comprobamos que adonde quiere mover es la casilla diagonal
	//el primer if funciona (solo devuelve true cuando has movido una diagonal unitaria a la derecha o a la izquierda
	if (((posicionSiguiente.x == (posicionActual.x + 1)) && (posicionSiguiente.y == (posicionActual.y - 1)))|| ((posicionSiguiente.x == (posicionActual.x - 1)) && (posicionSiguiente.y == (posicionActual.y - 1)))) {
		//ahora comprobamos que no haya ninguna ficha ahi 
		int h = 1;
		for (i = 0; i < 12; i++) {
			int h;
			if ((posicionSiguiente = listaFichasBl[i]->posicion) || (posicionSiguiente = listaFichasNe[i]->posicion))
				return false;
			else
				aux = true;
		}
		return aux;
	}
	else
		return false;
}

bool Reglas::fichaComida() {
	int i;
	int v;
	int k;
	int auxV=0;
	int auxK=0;
	bool diagIzq = false;
	bool diagDer = false;
	//primero comprobamos que adonde quiere mover es la casilla diagonal doble
	//el primer if funciona (solo devuelve true cuando has movido una doble diagonal unitaria a la izquierda
	if ((posicionSiguiente.x == (posicionActual.x + 2)) && (posicionSiguiente.y == (posicionActual.y - 2))) {
		for (i = 0; i < 12; i++) {
			int h;
			//Comprobamos que no haya ninguna ficha ahi
			if ((posicionSiguiente = listaFichasBl[i]->posicion) || (posicionSiguiente = listaFichasNe[i]->posicion)) {
				diagIzq = false;
				listaFichasNe[auxV]->estado = 0;
				break;
			}
			else {
				for (v = 0; v < 12; v++)
				{
					//Aqui comprobamos que hay una ficha del otro color en medio de la diagonal 
					if (((posicionActual.x + 1) == listaFichasNe[v]->posicion.x) && ((posicionActual.y - 1) == listaFichasNe[v]->posicion.y)) {
						diagIzq = true;
						listaFichasNe[v]->estado = -1;
						auxV=v;
						break;
					}
					else
						diagIzq = false;
				}
			}
			
		}	
	}	
	else
		diagIzq = false;


	//diagonal derecha 
	if ( ((posicionSiguiente.x == (posicionActual.x - 2)) && (posicionSiguiente.y == (posicionActual.y - 2)))) {
		for (i = 0; i < 12; i++) {
			int h;
			//Comprobamos que no haya ninguna ficha ahi
			if ((posicionSiguiente = listaFichasBl[i]->posicion) || (posicionSiguiente = listaFichasNe[i]->posicion)) {
				diagDer = false;
				listaFichasNe[auxK]->estado = 0;
				break;
			}
			else
			{
				for (k = 0; k < 12; k++)
				{

					//Aqui comprobamos que hay una ficha del otro color en medio de la diagonal 
					if (((posicionActual.x - 1) == listaFichasNe[k]->posicion.x) && ((posicionActual.y - 1) == listaFichasNe[k]->posicion.y)) {
						diagDer = true;
						listaFichasNe[k]->estado = -1; //si hemos comido cambiamos el estado de la ficha comida(se le pasa
						auxK = k;							//a tablero en delListaFichas
						break;
					}
					else
						diagDer = false;
				}
			}						
		}	
	}
	else
		diagDer = false;

	
	return (diagDer || diagIzq);
}

bool Reglas::posibleComerFicha() {
	//esta funcion devuelve true si es posible comer otra vez
	//en un principio (cuando la función toma la decisión) actual y siguiente no están actualizados
	//cuando pulse el primer espacio actualizo posActual
	//en el segundo espacio actualizo posSiguiente (hasta entonces posSiguiente estaba almacenando la posicion actual de este movimiento)
	bool auxdig = true;
	//comprobamos para cada blanca todas las negras
	for (int i = 0; i < 12; i++) {
		diagIzq[i] = false;
		//Estos if comprueba si hay fichas a dos casillas de la posicion donde has quedado tras comer una ficha
		//separamos entre diagonal derecha e izquierda
		for (int j = 0; j < 12; j++) {
			//izquierda
			//primero comprobamos que haya una ficha en la casilla adyacente
			if (((listaFichasBl[i]->posicion.x + 1) == listaFichasNe[j]->posicion.x) && ((listaFichasBl[i]->posicion.y - 1) == listaFichasNe[j]->posicion.y)) {
				diagIzq[i] = true;  //devuelve true si, después de un movimiento legal de blancas, hay una ficha en la NUEVA casilla adyacente 
				int aux = 0;
				aux = i;
				int j;
				j = i;
				if (((listaFichasBl[i]->posicion.x + 2) > 0) || ((listaFichasBl[i]->posicion.y - 2) < -7)) {
					diagIzq[i] = false;
					j = i;
				}

				for (int v = 0; v < 12; v++) {//necesitamos recorrer las posiciones de la negras desde cero!!! Sino el bucle empieza desde donde encontro la ficha negra del anterior if
											  //Sin embargo queremos que compare con la ficha blanca que encontro que puede comer, por lo que dejamos la que encontro en el anterior if
					//si hay una ficha en la segunda casilla diagonal
					if ((((listaFichasBl[i]->posicion.x + 2) == listaFichasNe[v]->posicion.x) && ((listaFichasBl[i]->posicion.y - 2) == listaFichasNe[v]->posicion.y)) || (((listaFichasBl[i]->posicion.x + 2) == listaFichasBl[v]->posicion.x) && ((listaFichasBl[i]->posicion.y - 2) == listaFichasBl[v]->posicion.y))) {
						diagIzq[i] = false; //funciona correctamente, similar a la anterior				
					}
				}
			}
		}
	}

	for (int i = 0; i < 12; i++) {
		//Estos if comprueba si hay fichas a dos casillas de la posicion donde has quedado tras comer una ficha
		//separamos entre diagonal derecha e izquierda
		diagDer[i] = false;
		for (int j = 0; j < 12; j++) {
			//derecha
			if ((((listaFichasBl[i]->posicion.x - 1) == listaFichasNe[j]->posicion.x) && ((listaFichasBl[i]->posicion.y - 1) == listaFichasNe[j]->posicion.y))) {
				diagDer[i] = true;  //devuelve true si, después de un movimiento legal de blancas, hay una ficha en la NUEVA casilla adyacente 
				int aux1 = 0;
				aux1 = i;
				int j1;
				j1 = i;
				if (((listaFichasBl[i]->posicion.x - 2) < -7) || ((listaFichasBl[i]->posicion.y - 2) < -7)) {
					diagDer[i] = false;
					aux1 = i;
				}

				for (int z = 0; z < 12; z++) {//necesitamos recorrer las posiciones de la negras desde cero!!! Sino el bucle empieza desde donde encontro la ficha negra del anterior if
					 //Sin embargo queremos que compare con la ficha blanca que encontro que puede comer, por lo que dejamos la que encontro en el anterior if	
					//si hay una ficha en la segunda casilla diagonal
					if ((((listaFichasBl[i]->posicion.x - 2) == listaFichasNe[z]->posicion.x) && ((listaFichasBl[i]->posicion.y - 2) == listaFichasNe[z]->posicion.y)) || (((listaFichasBl[i]->posicion.x - 2) == listaFichasBl[z]->posicion.x) && ((listaFichasBl[i]->posicion.y - 2) == listaFichasBl[z]->posicion.y))) {
						diagDer[i] = false; //funciona correctamente, similar a la anterior	
					}
				}
			}
		}
	}
	for (int i = 0; i < 12; i++)
	{
		if (diagDer[i] || diagIzq[i])
			return true;
		else
			auxdig = false;
	}
	return auxdig;
}
void Reglas::hacerReina() {
	//las condiciones son que la ficha haya llegado a la posición -9, y nos aseguramos que solo contabilice la ultima ficha que se ha movido
	for (int i = 0; i < 12; i++) {
		if ((posicionSiguiente.y + 1 == listaFichasBl[i]->posicion.y) && (posicionSiguiente.y == -7) && (posicionActual.y == posicionSiguiente.y + 1) && ((posicionActual.x == posicionSiguiente.x -1)|| (posicionActual.x == posicionSiguiente.x + 1))&& (posicionActual = listaFichasBl[i]->posicion)){
			listaFichasBl[i]->estado = 1;
			
		}
		else if ((posicionSiguiente.y + 2 == listaFichasBl[i]->posicion.y) && (posicionSiguiente.y == -7)&&(posicionActual.y == posicionSiguiente.y + 2)&&((posicionActual.x == posicionSiguiente.x - 2) || (posicionActual.x == posicionSiguiente.x +2)) && (posicionActual = listaFichasBl[i]->posicion)) {
			listaFichasBl[i]->estado = 1;
		
		}
	}
}

bool Reglas::moverReina() {
	//la reina se mueve solo de uno en uno
	int i;
	bool aux = false;


	//primero comprobamos que la casilla a la que hemos movido sea una casilla diagonal adyacente(+-,--,-+,++)
	if ((((posicionSiguiente.x == (posicionActual.x + 1)) && (posicionSiguiente.y == (posicionActual.y - 1))) || ((posicionSiguiente.x == (posicionActual.x - 1)) && (posicionSiguiente.y == (posicionActual.y - 1))) || ((posicionSiguiente.x == (posicionActual.x - 1)) && (posicionSiguiente.y == (posicionActual.y + 1))) || ((posicionSiguiente.x == (posicionActual.x + 1)) && (posicionSiguiente.y == (posicionActual.y + 1)))) && (((posicionSiguiente.x >= -7) && (posicionSiguiente.y <= 0)) && ((posicionSiguiente.x <= 0) && (posicionSiguiente.y >= -7)))) {
		//ahora comprobamos que no haya ninguna ficha ahi 
		for (i = 0; i < 12; i++) {
			int h;
			if ((posicionSiguiente = listaFichasBl[i]->posicion) || (posicionSiguiente = listaFichasNe[i]->posicion))
				return false;
			else
				aux = true;
		}
		return aux;
	}
	else
		return false;

}

bool Reglas::posibleComerConReina() {
	//esta funcion devuelve true si es posible comer otra vez
	//en un principio (cuando la función toma la decisión) actual y siguiente no están actualizados
	//cuando pulse el primer espacio actualizo posActual
	//en el segundo espacio actualizo posSiguiente (hasta entonces posSiguiente estaba almacenando la posicion actual de este movimiento)
	bool auxdig = true;
	//comprobamos para cada blanca todas las negras
	for (int i = 0; i < 12; i++) {
		diagIzqTras[i] = false;

		if (listaFichasBl[i]->estado == 1) {
			//Estos if comprueba si hay fichas a dos casillas de la posicion donde has quedado tras comer una ficha
			//separamos entre diagonal derecha e izquierda
			for (int j = 0; j < 12; j++) {
				//izquierda
				//primero comprobamos que haya una ficha en la casilla adyacente
				if (((listaFichasBl[i]->posicion.x + 1) == listaFichasNe[j]->posicion.x) && ((listaFichasBl[i]->posicion.y + 1) == listaFichasNe[j]->posicion.y)) {
					diagIzqTras[i] = true;  //devuelve true si, después de un movimiento legal de blancas, hay una ficha en la NUEVA casilla adyacente 
					int aux = 0;
					aux = i;
					int j;
					j = i;
					if (((listaFichasBl[i]->posicion.x + 2) > 0) || ((listaFichasBl[i]->posicion.y + 2) >0)) {
						diagIzqTras[i] = false;
						j = i;
					}

					for (int v = 0; v < 12; v++) {//necesitamos recorrer las posiciones de la negras desde cero!!! Sino el bucle empieza desde donde encontro la ficha negra del anterior if
												  //Sin embargo queremos que compare con la ficha blanca que encontro que puede comer, por lo que dejamos la que encontro en el anterior if
						//si hay una ficha en la segunda casilla diagonal
						if ((((listaFichasBl[i]->posicion.x + 2) == listaFichasNe[v]->posicion.x) && ((listaFichasBl[i]->posicion.y + 2) == listaFichasNe[v]->posicion.y)) || (((listaFichasBl[i]->posicion.x + 2) == listaFichasBl[v]->posicion.x) && ((listaFichasBl[i]->posicion.y + 2) == listaFichasBl[v]->posicion.y))) {
							diagIzqTras[i] = false; //funciona correctamente, similar a la anterior				
						}
					}
				}
			}
		}
	}

	for (int i = 0; i < 12; i++) {
		//Estos if comprueba si hay fichas a dos casillas de la posicion donde has quedado tras comer una ficha
		//separamos entre diagonal derecha e izquierda
		diagDerTras[i] = false;
		if (listaFichasBl[i]->estado == 1) {
			for (int j = 0; j < 12; j++) {
				//derecha
				if (((listaFichasBl[i]->posicion.x - 1) == listaFichasNe[j]->posicion.x) && ((listaFichasBl[i]->posicion.y + 1) == listaFichasNe[j]->posicion.y)) {
					diagDerTras[i] = true;  //devuelve true si, después de un movimiento legal de blancas, hay una ficha en la NUEVA casilla adyacente 
					int aux1 = 0;
					aux1 = i;
					int j1;
					j1 = i;
					if (((listaFichasBl[i]->posicion.x - 2) < -7) || ((listaFichasBl[i]->posicion.y + 2) >0)) {
						diagDerTras[i] = false;
						j1 = i;
					}

					for (int z = 0; z < 12; z++) {//necesitamos recorrer las posiciones de la negras desde cero!!! Sino el bucle empieza desde donde encontro la ficha negra del anterior if
						 //Sin embargo queremos que compare con la ficha blanca que encontro que puede comer, por lo que dejamos la que encontro en el anterior if	
						//si hay una ficha en la segunda casilla diagonal
						if ((((listaFichasBl[i]->posicion.x - 2) == listaFichasNe[z]->posicion.x) && ((listaFichasBl[i]->posicion.y + 2) == listaFichasNe[z]->posicion.y)) || (((listaFichasBl[i]->posicion.x - 2) == listaFichasBl[z]->posicion.x) && ((listaFichasBl[i]->posicion.y + 2) == listaFichasBl[z]->posicion.y))) {
							diagDerTras[i] = false; //funciona correctamente, similar a la anterior	
						}
					}
				}
			}
		}
	}
	for (int i = 0; i < 12; i++)
	{
		if (diagDerTras[i] || diagIzqTras[i])
			return true;
		else
			auxdig = false;
	}
	return auxdig;
}
bool Reglas::fichaComidaConReina() {
	int i;
	int v;
	int k;
	bool diagIzq = false;
	bool diagDer = false;
	//primero comprobamos que adonde quiere mover es la casilla diagonal doble
	//el primer if funciona (solo devuelve true cuando has movido una doble diagonal unitaria a la izquierda
	if ((posicionSiguiente.x == (posicionActual.x + 2)) && (posicionSiguiente.y == (posicionActual.y + 2))) {
		for (i = 0; i < 12; i++) {
			int h;
			if (listaFichasBl[i]->estado == 1) {//solo evaluamos las que sean reinas
				//Comprobamos que no haya ninguna ficha ahi
				if ((posicionSiguiente = listaFichasBl[i]->posicion) || (posicionSiguiente = listaFichasNe[i]->posicion)) {
					diagIzq = false;
					listaFichasNe[v]->estado = 0;
					break;
				}
				else {
					for (v = 0; v < 12; v++)
					{
						//Aqui comprobamos que hay una ficha del otro color en medio de la diagonal 
						if (((posicionActual.x + 1) == listaFichasNe[v]->posicion.x) && ((posicionActual.y + 1) == listaFichasNe[v]->posicion.y)) {
							diagIzq = true;
							listaFichasNe[v]->estado = -1;
							break;
							int a;
						}
						else
							diagIzq = false;
					}
				}
			}

		}
	}
	else
		diagIzq = false;


	//diagonal derecha 
	if (((posicionSiguiente.x == (posicionActual.x - 2)) && (posicionSiguiente.y == (posicionActual.y + 2)))) {
		for (i = 0; i < 12; i++) {
			int h;
			if (listaFichasBl[i]->estado == 1) {
				//Comprobamos que no haya ninguna ficha ahi
				if ((posicionSiguiente = listaFichasBl[i]->posicion) || (posicionSiguiente = listaFichasNe[i]->posicion)) {
					diagDer = false;
					listaFichasNe[k]->estado = 0;
					break;
				}
				else
				{
					for (k = 0; k < 12; k++)
					{

						//Aqui comprobamos que hay una ficha del otro color en medio de la diagonal 
						if (((posicionActual.x - 1) == listaFichasNe[k]->posicion.x) && ((posicionActual.y + 1) == listaFichasNe[k]->posicion.y)) {
							diagDer = true;
							listaFichasNe[k]->estado = -1; //si hemos comido cambiamos el estado de la ficha comida(se le pasa
														//a tablero en delListaFichas
							break;
						}
						else
							diagDer = false;
					}
				}
			}
		}
	}
	else
		diagDer = false;


	return (diagDer || diagIzq);
}
////////////////////////////////////////////////////////////////////////7/
//////////////////////////////////////////////////////////////////////////
//instrucciones para negras

bool Reglas::movDiagUnitN() {
	int i;
	bool aux = false;
	//primero comprobamos que adonde quiere mover es la casilla diagonal

	if ((((posicionSiguiente.x == (posicionActual.x + 1)) && (posicionSiguiente.y == (posicionActual.y + 1))) || ((posicionSiguiente.x == (posicionActual.x - 1)) && (posicionSiguiente.y == (posicionActual.y + 1))))   &&   (((posicionSiguiente.x >= -7) && (posicionSiguiente.y <= 0)) && ((posicionSiguiente.x <= 0) && (posicionSiguiente.y >= -7)))) {//posicionSiguiente debe estar dentro del tablero
		//ahora comprobamos que no haya ninguna ficha ahi 

		for (i = 0; i < 12; i++) {
			int h;
			if ((posicionSiguiente = listaFichasBl[i]->posicion) || (posicionSiguiente = listaFichasNe[i]->posicion))
				return false;
			else
				aux = true;
		}
		return aux;
	}
	else
		return false;

}
bool Reglas::posibleComerFichaN() {
	//esta funcion devuelve true si es posible comer otra vez

	bool auxdig = true;
	//comprobamos para cada NEGRA todas las BLANCAS
	for (int i = 0; i < 12; i++) {
		diagIzq[i] = false;
		fichaAComerIzq[i] = 20;
		
		//separamos entre diagonal derecha e izquierda
		for (int j = 0; j < 12; j++) {
			//izquierda
			//primero comprobamos que haya una ficha en la casilla adyacente
			if (((listaFichasNe[i]->posicion.x - 1) == listaFichasBl[j]->posicion.x) && ((listaFichasNe[i]->posicion.y + 1) == listaFichasBl[j]->posicion.y)) {
				diagIzq[i] = true;  //devuelve true si, después de un movimiento legal de blancas, hay una ficha en la NUEVA casilla adyacente 

				fichaAComerIzq[i] = j; //guarda el indice de la ficha blanca que va a ser comida (para el bot)
				int h=0;
				h = j;
				
				if (((listaFichasNe[i]->posicion.x - 2) < -7) || ((listaFichasNe[i]->posicion.y + 2) >0)) {
					diagIzq[i] = false;
					fichaAComerIzq[i] = 20; // El problema que hay es que primero detecta posibles fichas que estan adyacentes, y despues descarta que puedan ser
					                        //comidas por comer fuera del tablero. Asique tenemos que volver a cambiar a 20 para que no sea detectada como fichaComida (para el bot)
				}

				for (int v = 0; v < 12; v++) {//necesitamos recorrer las posiciones de la negras desde cero!!! Sino el bucle empieza desde donde encontro la ficha negra del anterior if
											  //Sin embargo queremos que compare con la ficha blanca que encontro que puede comer, por lo que dejamos la que encontro en el anterior if
					//si hay una ficha en la segunda casilla diagonal
					if ((((listaFichasNe[i]->posicion.x - 2) == listaFichasBl[v]->posicion.x) && ((listaFichasNe[i]->posicion.y + 2) == listaFichasBl[v]->posicion.y))|| (((listaFichasNe[i]->posicion.x - 2) == listaFichasNe[v]->posicion.x) && ((listaFichasNe[i]->posicion.y + 2) == listaFichasNe[v]->posicion.y))) {
						diagIzq[i] = false; //funciona correctamente, similar a la anterior	

						fichaAComerIzq[i] = 20; // El problema que hay es que primero detecta posibles fichas que estan adyacentes, y despues descarta que puedan ser
											//comidas por haber otra ficha en la posicion Siguiente. Asique tenemos que volver a cambiar a 20 para que no sea detectada como fichaComida (para el bot)
					}
				}
			}
		}
	}

	for (int i = 0; i < 12; i++) {
		//Estos if comprueba si hay fichas a dos casillas de la posicion donde has quedado tras comer una ficha
		//separamos entre diagonal derecha e izquierda
		fichaAComerDer[i] = 20;
		diagDer[i] = false;
		for (int j = 0; j < 12; j++) {
			//derecha
			if (((listaFichasNe[i]->posicion.x + 1) == listaFichasBl[j]->posicion.x) && ((listaFichasNe[i]->posicion.y + 1) == listaFichasBl[j]->posicion.y)) {
				diagDer[i] = true;  //devuelve true si, después de un movimiento legal de blancas, hay una ficha en la NUEVA casilla adyacente

				fichaAComerDer[i] = j; //guarda el indice de la ficha blanca que va a ser comida

				if (((listaFichasNe[i]->posicion.x + 2) >0) || ((listaFichasNe[i]->posicion.y + 2) >0)) {
					diagDer[i] = false;

					fichaAComerDer[i] = 20; // El problema que hay es que primero detecta posibles fichas que estan adyacentes, y despues descarta que puedan ser
					                        //comidas por comer fuera del tablero. Asique tenemos que volver a cambiar a 20 para que no sea detectada como fichaComida (para el bot)
				}

				for (int z = 0; z < 12; z++) {//necesitamos recorrer las posiciones de la BLANCAS desde cero!!! Sino el bucle empieza desde donde encontro la ficha negra del anterior if
					 //Sin embargo queremos que compare con la ficha blanca que encontro que puede comer, por lo que dejamos la que encontro en el anterior if	
					//si hay una ficha en la segunda casilla diagonal
					if ((((listaFichasNe[i]->posicion.x + 2) == listaFichasBl[z]->posicion.x) && ((listaFichasNe[i]->posicion.y + 2) == listaFichasBl[z]->posicion.y)) || (((listaFichasNe[i]->posicion.x + 2) == listaFichasNe[z]->posicion.x) && ((listaFichasNe[i]->posicion.y + 2) == listaFichasNe[z]->posicion.y))) {
						diagDer[i] = false; 
						fichaAComerDer[i] = 20; // El problema que hay es que primero detecta posibles fichas que estan adyacentes, y despues descarta que puedan ser
											//comidas por haber otra ficha en la posicion Siguiente. Asique tenemos que volver a cambiar a 20 para que no sea detectada como fichaComida (para el bot)
					}
				}
			}
		}
	}
	for (int i = 0; i < 12; i++)
	{
		if (diagDer[i] || diagIzq[i])
			return true;
		else
			auxdig = false;
	}
	return auxdig;
}
bool Reglas::fichaComidaN() {
	int i;
	int v;
	int k;
	bool diagIzq = false;
	bool diagDer = false;
	//primero comprobamos que adonde quiere mover es la casilla diagonal doble
	//el primer if funciona (solo devuelve true cuando has movido una doble diagonal unitaria a la izquierda
	if ((posicionSiguiente.x == (posicionActual.x - 2)) && (posicionSiguiente.y == (posicionActual.y + 2))) {
		for (i = 0; i < 12; i++) {
			int h;
			//Comprobamos que no haya ninguna ficha ahi
			if ((posicionSiguiente = listaFichasBl[i]->posicion) || (posicionSiguiente = listaFichasNe[i]->posicion)) {
				diagIzq = false;
				listaFichasBl[v]->estado = 0;
				break;
			}
			else {
				for (v = 0; v < 12; v++)
				{
					//Aqui comprobamos que hay una ficha del otro color en medio de la diagonal 
					if (((posicionActual.x - 1) == listaFichasBl[v]->posicion.x) && ((posicionActual.y + 1) == listaFichasBl[v]->posicion.y)) {
						diagIzq = true;
						listaFichasBl[v]->estado = -1;
						break;
						int a;
					}
					else
						diagIzq = false;
				}
			}

		}
	}
	else
		diagIzq = false;


	//diagonal derecha 
	if (((posicionSiguiente.x == (posicionActual.x + 2)) && (posicionSiguiente.y == (posicionActual.y + 2)))) {
		for (i = 0; i < 12; i++) {
			int h;
			//Comprobamos que no haya ninguna ficha ahi
			if ((posicionSiguiente = listaFichasBl[i]->posicion) || (posicionSiguiente = listaFichasNe[i]->posicion)) {
				diagDer = false;
				listaFichasBl[k]->estado = 0;
				break;
			}
			else
			{
				for (k = 0; k < 12; k++)
				{

					//Aqui comprobamos que hay una ficha del otro color en medio de la diagonal 
					if (((posicionActual.x + 1) == listaFichasBl[k]->posicion.x) && ((posicionActual.y + 1) == listaFichasBl[k]->posicion.y)) {
						diagDer = true;
						listaFichasBl[k]->estado = -1; //si hemos comido cambiamos el estado de la ficha comida(se le pasa
													//a tablero en delListaFichas
						break;
					}
					else
						diagDer = false;
				}
			}
		}
	}
	else
		diagDer = false;


	return (diagDer || diagIzq);
}

void Reglas::hacerReinaN() {
	//las condiciones son que la ficha haya llegado a la posición -9, y nos aseguramos que solo contabilice la ultima ficha que se ha movido
	for (int i = 0; i < 12; i++) {
		if ((posicionSiguiente.y  - 1 == listaFichasNe[i]->posicion.y) && (posicionSiguiente.y == 0) && (posicionActual.y == posicionSiguiente.y - 1) && ((posicionActual.x == posicionSiguiente.x - 1) || (posicionActual.x == posicionSiguiente.x + 1)) && (posicionActual = listaFichasNe[i]->posicion)) {
  			listaFichasNe[i]->estado = 1;

		}
		else if ((posicionSiguiente.y - 2 == listaFichasNe[i]->posicion.y) && (posicionSiguiente.y == 0) && (posicionActual.y == posicionSiguiente.y - 2) && ((posicionActual.x == posicionSiguiente.x - 2) || (posicionActual.x == posicionSiguiente.x + 2)) && (posicionActual = listaFichasNe[i]->posicion)) {
			listaFichasNe[i]->estado = 1;

		}
	}
	int j = 0;
}
void Reglas::hacerReinaBot() {
	for (int i = 0; i < 12; i++)
	{
		if (listaFichasNe[i]->posicion.y == 0) {
			listaFichasNe[i]->estado = 1;
		}
	}
	int i = 0;
}

bool Reglas::posibleComerConReinaN() {
	bool auxdig = true;
	//comprobamos para cada blanca todas las negras
	for (int i = 0; i < 12; i++) {
		diagIzq[i] = false;

		if (listaFichasNe[i]->estado == 1) {
			//Estos if comprueba si hay fichas a dos casillas de la posicion donde has quedado tras comer una ficha
			//separamos entre diagonal derecha e izquierda
			for (int j = 0; j < 12; j++) {
				//izquierda
				//primero comprobamos que haya una ficha en la casilla adyacente
				if (((listaFichasNe[i]->posicion.x - 1) == listaFichasBl[j]->posicion.x) && ((listaFichasNe[i]->posicion.y - 1) == listaFichasBl[j]->posicion.y)) {
					diagIzq[i] = true;  //devuelve true si, después de un movimiento legal de blancas, hay una ficha en la NUEVA casilla adyacente 
					int aux = 0;
					aux = i;
					int j;
					j = i;
					if (((listaFichasNe[i]->posicion.x - 2) < -7) || ((listaFichasNe[i]->posicion.y - 2) < -7)) {
						diagIzq[i] = false;
						j = i;
					}

					for (int v = 0; v < 12; v++) {//necesitamos recorrer las posiciones de la negras desde cero!!! Sino el bucle empieza desde donde encontro la ficha negra del anterior if
												  //Sin embargo queremos que compare con la ficha blanca que encontro que puede comer, por lo que dejamos la que encontro en el anterior if
						//si hay una ficha en la segunda casilla diagonal
						if ((((listaFichasNe[i]->posicion.x - 2) == listaFichasNe[v]->posicion.x) && ((listaFichasNe[i]->posicion.y - 2) == listaFichasNe[v]->posicion.y)) || (((listaFichasNe[i]->posicion.x - 2) == listaFichasBl[v]->posicion.x) && ((listaFichasNe[i]->posicion.y - 2) == listaFichasBl[v]->posicion.y))) {
							diagIzq[i] = false; //funciona correctamente, similar a la anterior				
						}
					}
				}
			}
		}
	}

	for (int i = 0; i < 12; i++) {
		//Estos if comprueba si hay fichas a dos casillas de la posicion donde has quedado tras comer una ficha
		//separamos entre diagonal derecha e izquierda
		diagDer[i] = false;
		if (listaFichasNe[i]->estado == 1) {
			for (int j = 0; j < 12; j++) {
				//derecha
				if (((listaFichasNe[i]->posicion.x + 1) == listaFichasBl[j]->posicion.x) && ((listaFichasNe[i]->posicion.y - 1) == listaFichasBl[j]->posicion.y)) {
					diagDer[i] = true;  //devuelve true si, después de un movimiento legal de blancas, hay una ficha en la NUEVA casilla adyacente 
					int aux1 = 0;
					aux1 = i;
					int j1;
					j1 = i;
					if (((listaFichasNe[i]->posicion.x + 2) >0) || ((listaFichasNe[i]->posicion.y - 2) <-7)) {
						diagDer[i] = false;
						aux1 = i;
					}

					for (int z = 0; z < 12; z++) {//necesitamos recorrer las posiciones de la negras desde cero!!! Sino el bucle empieza desde donde encontro la ficha negra del anterior if
						 //Sin embargo queremos que compare con la ficha blanca que encontro que puede comer, por lo que dejamos la que encontro en el anterior if	
						//si hay una ficha en la segunda casilla diagonal
						if ((((listaFichasNe[i]->posicion.x + 2) == listaFichasNe[z]->posicion.x) && ((listaFichasNe[i]->posicion.y - 2) == listaFichasNe[z]->posicion.y)) || (((listaFichasNe[i]->posicion.x + 2) == listaFichasBl[z]->posicion.x) && ((listaFichasNe[i]->posicion.y - 2) == listaFichasBl[z]->posicion.y))) {
							diagDer[i] = false; //funciona correctamente, similar a la anterior	
						}
					}
				}
			}
		}
	}
	for (int i = 0; i < 12; i++)
	{
		if (diagDer[i] || diagIzq[i])
			return true;
		else
			auxdig = false;
	}
	return auxdig;
}
bool Reglas::fichaComidaConReinaN() {
	int i;
	int v;
	int k;
	bool diagIzq = false;
	bool diagDer = false;
	//primero comprobamos que adonde quiere mover es la casilla diagonal doble
	if ((posicionSiguiente.x == (posicionActual.x - 2)) && (posicionSiguiente.y == (posicionActual.y - 2))) {
		for (i = 0; i < 12; i++) {
			int h;
			if (listaFichasNe[i]->estado == 1) {//solo evaluamos las que sean reinas
				//Comprobamos que no haya ninguna ficha ahi
				if ((posicionSiguiente = listaFichasBl[i]->posicion) || (posicionSiguiente = listaFichasNe[i]->posicion)) {
					diagIzq = false;
					listaFichasBl[v]->estado = 0;
					break;
				}
				else {
					for (v = 0; v < 12; v++)
					{
						//Aqui comprobamos que hay una ficha del otro color en medio de la diagonal 
						if (((posicionActual.x - 1) == listaFichasBl[v]->posicion.x) && ((posicionActual.y - 1) == listaFichasBl[v]->posicion.y)) {
							diagIzq = true;
							listaFichasBl[v]->estado = -1;
							break;
							int a;
						}
						else
							diagIzq = false;
					}
				}
			}

		}
	}
	else
		diagIzq = false;


	//diagonal derecha 
	if (((posicionSiguiente.x == (posicionActual.x + 2)) && (posicionSiguiente.y == (posicionActual.y - 2)))) {
		for (i = 0; i < 12; i++) {
			int h;
			if (listaFichasNe[i]->estado == 1) {
				//Comprobamos que no haya ninguna ficha ahi
				if ((posicionSiguiente = listaFichasBl[i]->posicion) || (posicionSiguiente = listaFichasNe[i]->posicion)) {
					diagDer = false;
					listaFichasBl[k]->estado = 0;
					break;
				}
				else
				{
					for (k = 0; k < 12; k++)
					{

						//Aqui comprobamos que hay una ficha del otro color en medio de la diagonal 
						if (((posicionActual.x + 1) == listaFichasBl[k]->posicion.x) && ((posicionActual.y - 1) == listaFichasBl[k]->posicion.y)) {
							diagDer = true;
							listaFichasBl[k]->estado = -1; //si hemos comido cambiamos el estado de la ficha comida(se le pasa
														//a tablero en delListaFichas
							break;
						}
						else
							diagDer = false;
					}
				}
			}
		}
	}
	else
		diagDer = false;


	return (diagDer || diagIzq);
}

//////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////
//instrucciones de control
bool Reglas::cambiarTurno() {
	//cada vez que se invoca esta función se cambia el turno
	if (turno == 1) {
		turno = 0;
		return 0;
	}
	else {
		turno = 1;
		return 0;
	}
}
bool Reglas::getTurno() {
	return turno;

}
void Reglas::setPosAct(Vector2D v) {
	posicionActual.x = v.x;
	posicionActual.y = v.y;
}
void Reglas::setPosSig(Vector2D v) {
	posicionSiguiente.x = v.x;
	posicionSiguiente.y = v.y;
}

void Reglas::setListaFichas(std::vector <Ficha*> listaB, std::vector <Ficha*> listaN) {	
	int i = 0;
	for (i = 0; i < 12; i++) {
		listaFichasBl[i]->posicion.x = listaB[i]->posicion.x;
		listaFichasNe[i]->posicion.x = listaN[i]->posicion.x;

		listaFichasBl[i]->posicion.y = listaB[i]->posicion.y;
		listaFichasNe[i]->posicion.y = listaN[i]->posicion.y;	
		//////////////////////////////////instruccion para reglasbot
		listaFichasBl[i]->estado = listaB[i]->estado;
		listaFichasNe[i]->estado = listaN[i]->estado;

	}
	int j = 0;
}

void Reglas::delListaFichas(std::vector <Ficha*> listaB, std::vector <Ficha*> listaN) {
	int i = 0;
	for (i = 0; i < 12; i++) {
		listaB[i]->estado = listaFichasBl[i]->estado;
		listaN[i]->estado = listaFichasNe[i]->estado;
		
	}
	int j = 0;
}

Reglas::~Reglas()
{

}