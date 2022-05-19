#include "ReglasBot.h"
#include "math.h"
using namespace std;
bool ReglasBot::calcularPosicionesPosibles() {
	Vector2D posSigu;
	Jugada str;
	bool t = true;
	bool r = true;
	bool aux = false;
	for (int i = 0; i < 12; i++) {
		if (listaFichasNe[i]->estado == 0) { //////////////////////////////////////////////////////////////////////si la ficha esta viva
			this->setPosAct(listaFichasNe[i]->posicion);
			/////derecha
			posSigu.x = (listaFichasNe[i]->posicion.x + 1);
			posSigu.y = (listaFichasNe[i]->posicion.y + 1);

			this->setPosSig(posSigu);

			if (this->movDiagUnitN()) { //devuelve true si el mov a la posicion indicada por posSiguDer es posible (no hay ficha
				str.idFicha = i;
				str.posSig.x = posSigu.x;
				str.posSig.y = posSigu.y;
				posibPosSiguientes.push_back(str);
			}

			////////izquierda
			posSigu.x = (listaFichasNe[i]->posicion.x - 1);
			posSigu.y = (listaFichasNe[i]->posicion.y + 1);
			this->setPosSig(posSigu);
			t = this->movDiagUnitN();
			
			int h = 1;
			if (t== true) {
				str.idFicha = i;
				str.posSig.x = posSigu.x;
				str.posSig.y = posSigu.y;
				posibPosSiguientes.push_back(str);				
			}
			//////////////////////
/////////////////////////////////////coronacion
			/////derecha
			posSigu.x = (listaFichasNe[i]->posicion.x + 1);
			posSigu.y = (listaFichasNe[i]->posicion.y + 1);
			if (posSigu.y == 0) {
				if (this->movDiagUnitN() && (this->posibleComerConReinaBot() == false) && (this->posibleComerFichaN() == false)) {
					posibPosSiguientes.erase(posibPosSiguientes.begin(), posibPosSiguientes.begin() + posibPosSiguientes.size());
					str.idFicha = i;
					str.posSig.x = posSigu.x;
					str.posSig.y = posSigu.y;
					posibPosSiguientes.push_back(str);
					int k = 0;
				}
			}
			/////izquierda
			posSigu.x = (listaFichasNe[i]->posicion.x - 1);
			posSigu.y = (listaFichasNe[i]->posicion.y + 1);
			if (posSigu.y == 0) {
				if (this->movDiagUnitN() && (this->posibleComerConReinaBot() == false) && (this->posibleComerFichaN() == false)) {
					posibPosSiguientes.erase(posibPosSiguientes.begin(), posibPosSiguientes.begin() + posibPosSiguientes.size());
					str.idFicha = i;
					str.posSig.x = posSigu.x;
					str.posSig.y = posSigu.y;
					posibPosSiguientes.push_back(str);
					int k = 0;
				}
			}
		}
		int k = 0;
		if (listaFichasNe[i]->estado == 1) { ///////////////////////////////////////////////////////////////////////Si la ficha es reina
			this->setPosAct(listaFichasNe[i]->posicion);
			/////derecha para atras
			posSigu.x = (listaFichasNe[i]->posicion.x + 1);
			posSigu.y = (listaFichasNe[i]->posicion.y - 1);


			this->setPosSig(posSigu);

			if (this->moverReina()) { //devuelve true si el mov a la posicion indicada por posSiguDer es posible (no hay ficha
				str.idFicha = i;
				str.posSig.x = posSigu.x;
				str.posSig.y = posSigu.y;
				posibPosSiguientes.push_back(str);
			}
			////////izquierda para atras
			posSigu.x = (listaFichasNe[i]->posicion.x - 1);
			posSigu.y = (listaFichasNe[i]->posicion.y - 1);
			this->setPosSig(posSigu);
			///////////////////////////////////////////////////////////////////error
			//movDiagUni de la Reina tampoco  tiene en cuenta si la ficha se sale del tablero (eso lo tiene en cuenta la misma mano, que aqui no existe)
			r = this->moverReina();

			int h = 1;
			if (r == true ) {
				str.idFicha = i;
				str.posSig.x = posSigu.x;
				str.posSig.y = posSigu.y;
				posibPosSiguientes.push_back(str);
			}
			
			/////derecha para delante
			posSigu.x = (listaFichasNe[i]->posicion.x + 1);
			posSigu.y = (listaFichasNe[i]->posicion.y + 1);
			

			this->setPosSig(posSigu);

			r = this->moverReina();
			if (r==true) { //devuelve true si el mov a la posicion indicada por posSiguDer es posible (no hay ficha
				str.idFicha = i;
				str.posSig.x = posSigu.x;
				str.posSig.y = posSigu.y;
				posibPosSiguientes.push_back(str);
			}
			
			////////izquierda para delante
			posSigu.x = (listaFichasNe[i]->posicion.x - 1);
			posSigu.y = (listaFichasNe[i]->posicion.y + 1);


			this->setPosSig(posSigu);
			r = this->moverReina();

	
			if (r == true) {
				str.idFicha = i;
				str.posSig.x = posSigu.x;
				str.posSig.y = posSigu.y;
				posibPosSiguientes.push_back(str);
			}
		}
		aux = false;

	}
	int i = 0;
	////////////////////
	//comer REINA
	
	if ((posibleComerConReinaBot())) {//Aqui entra cuando la reina negra puede comer una ficha hacia delante
		
				//Si es posible comer ficha primero borramos el vector
		posibPosSiguientes.erase(posibPosSiguientes.begin(), posibPosSiguientes.begin() + posibPosSiguientes.size());
		//luego guardamos en el vector que ficha negra(idFicha) puede comer la ficha blanca (idFichaComer) tras desplazarse a posSig
			for (int i = 0; i < 12; i++) {
				if (this->diagDerTras[i] && fichaAComerDer[i] != 20) {
					posSigu.x = (listaFichasNe[i]->posicion.x + 2);
					posSigu.y = (listaFichasNe[i]->posicion.y - 2);

					str.idFicha = i;
					str.idFichaComer = this->fichaAComerDer[i];
					str.posSig.x = posSigu.x;
					str.posSig.y = posSigu.y;
					posibPosSiguientes.push_back(str);
					int k = 1;
				}
				if (this->diagIzqTras[i] && fichaAComerIzq[i] != 20) {
					posSigu.x = (listaFichasNe[i]->posicion.x - 2);
					posSigu.y = (listaFichasNe[i]->posicion.y - 2);

					str.idFicha = i;
					str.idFichaComer = this->fichaAComerIzq[i];
					str.posSig.x = posSigu.x;
					str.posSig.y = posSigu.y;
					posibPosSiguientes.push_back(str);
					int k = 0;
				}
				aux = true;
			}
	}
	////////////////////
	/////comer FICHA normal
	if (this->posibleComerFichaN())//de momento vamos a dar prioridad a que coman las fichas normales sobre que coma la reina
								//por eso borramos las posibPosSiguientes
	{
		//Si es posible comer ficha primero borramos el vector
		posibPosSiguientes.erase(posibPosSiguientes.begin(), posibPosSiguientes.begin() + posibPosSiguientes.size());
		//luego guardamos en el vector que ficha negra(idFicha) puede comer la ficha blanca (idFichaComer) tras desplazarse a posSig
		for (int i = 0; i < 12; i++) {
			if (this->diagDer[i]&& fichaAComerDer[i]!=20) {
				posSigu.x = (listaFichasNe[i]->posicion.x + 2);
				posSigu.y = (listaFichasNe[i]->posicion.y + 2);

				str.idFicha = i;
				str.idFichaComer = this->fichaAComerDer[i];
				str.posSig.x = posSigu.x;
				str.posSig.y = posSigu.y;
				posibPosSiguientes.push_back(str);
				int k = 1;
			}
			if (this->diagIzq[i] && fichaAComerIzq[i] != 20) {
				posSigu.x = (listaFichasNe[i]->posicion.x - 2);
				posSigu.y = (listaFichasNe[i]->posicion.y + 2);

				str.idFicha = i;
				str.idFichaComer = this->fichaAComerIzq[i];
				str.posSig.x = posSigu.x;
				str.posSig.y = posSigu.y;
				posibPosSiguientes.push_back(str);
				int k = 0;
			}
			aux = true;
		}	
	}

	else if ((posibleComerFichaN() == false)&& (posibleComerConReinaN()==false))
	{
		aux = false;	
	}
	return aux;
}
Jugada* ReglasBot::elegirMejorMov(void) {
	 Jugada str;

	posMismaPrioridad.erase(posMismaPrioridad.begin(), posMismaPrioridad.begin() + posMismaPrioridad.size());
	posMismaPrioridad.clear();
	posMismaPrioridad.shrink_to_fit();

	float min = 10.0;
	
	int elElegido = 0;
	int p = posibPosSiguientes.size();
	int o = 1;
	for (int i = 0; i < posibPosSiguientes.size(); i++) {

		Vector2D mejorJugada;
		if (posibPosSiguientes[i].posSig.y < min) {// mayor porque el eje y esta invertido(seleccionamos la mas lejana al borde de las blancas
			min = posibPosSiguientes[i].posSig.y;
		}

	}

	for (int i = 0; i < posibPosSiguientes.size(); i++) {
		
		if (posibPosSiguientes[i].posSig.y == min)
			posMismaPrioridad.push_back(posibPosSiguientes[i]);
	}
	if (posMismaPrioridad.size() !=0) {
		elElegido = rand() % posMismaPrioridad.size(); //si se puede comer en la diagDer de las negras con la reina, posMismaPrioridad y posibposSiguientes se borran
		posibPosSiguientes.erase(posibPosSiguientes.begin(), posibPosSiguientes.begin() + posibPosSiguientes.size());
		posibPosSiguientes.clear();
		posibPosSiguientes.shrink_to_fit();
		return &posMismaPrioridad[elElegido];
	}
	else {
		FinBot = 1;
		return 0;
	}
} 



bool ReglasBot::posibleComerConReinaBot() {
	/////////////////////////////////
	//////primero las diagonales traseras ((+-)(--))
	  bool auxdig = true;
	  /////////////////////primero el vovimiento hacia atrás(ya programadas):Sufijo Tras
	  //comprobamos para cada NEGRA todas las BLANCAS
	  for (int i = 0; i < 12; i++) {
		  if (listaFichasNe[i]->estado == 1) {//solo comprobamos las reinas
			  diagIzqTras[i] = false;
			  fichaAComerIzq[i] = 20;

			  //separamos entre diagonal derecha e izquierda
			  for (int j = 0; j < 12; j++) {
				  //izquierda
				  //primero comprobamos que haya una ficha en la casilla adyacente
				  if (((listaFichasNe[i]->posicion.x - 1) == listaFichasBl[j]->posicion.x) && ((listaFichasNe[i]->posicion.y - 1) == listaFichasBl[j]->posicion.y)) {
					  diagIzqTras[i] = true;  //devuelve true si, después de un movimiento legal de blancas, hay una ficha en la NUEVA casilla adyacente 

					  fichaAComerIzq[i] = j; //guarda el indice de la ficha blanca que va a ser comida (para el bot)
					  int h = 0;
					  h = j;

					  if (((listaFichasNe[i]->posicion.x - 2) < -7) || ((listaFichasNe[i]->posicion.y - 2) < -7)) {
						  diagIzqTras[i] = false;
						  fichaAComerIzq[i] = 20; // El problema que hay es que primero detecta posibles fichas que estan adyacentes, y despues descarta que puedan ser
												  //comidas por comer fuera del tablero. Asique tenemos que volver a cambiar a 20 para que no sea detectada como fichaComida (para el bot)
					  }

					  for (int v = 0; v < 12; v++) {//necesitamos recorrer las posiciones de la negras desde cero!!! Sino el bucle empieza desde donde encontro la ficha negra del anterior if
													//Sin embargo queremos que compare con la ficha blanca que encontro que puede comer, por lo que dejamos la que encontro en el anterior if
						  //si hay una ficha en la segunda casilla diagonal
						  if ((((listaFichasNe[i]->posicion.x - 2) == listaFichasBl[v]->posicion.x) && ((listaFichasNe[i]->posicion.y - 2) == listaFichasBl[v]->posicion.y)) || (((listaFichasNe[i]->posicion.x - 2) == listaFichasNe[v]->posicion.x) && ((listaFichasNe[i]->posicion.y - 2) == listaFichasNe[v]->posicion.y))) {
							  diagIzqTras[i] = false; //funciona correctamente, similar a la anterior	

							  fichaAComerIzq[i] = 20; // El problema que hay es que primero detecta posibles fichas que estan adyacentes, y despues descarta que puedan ser
												  //comidas por haber otra ficha en la posicion Siguiente. Asique tenemos que volver a cambiar a 20 para que no sea detectada como fichaComida (para el bot)
						  }
					  }
				  }
			  }
		  }
	  }

	  for (int i = 0; i < 12; i++) {
		  if (listaFichasNe[i]->estado == 1) {
			  //Estos if comprueba si hay fichas a dos casillas de la posicion donde has quedado tras comer una ficha
			  //separamos entre diagonal derecha e izquierda
			  fichaAComerDer[i] = 20;
			  diagDerTras[i] = false;
			  for (int j = 0; j < 12; j++) {
				  //derecha
				  if (((listaFichasNe[i]->posicion.x + 1) == listaFichasBl[j]->posicion.x) && ((listaFichasNe[i]->posicion.y - 1) == listaFichasBl[j]->posicion.y)) {
					  diagDerTras[i] = true;  //devuelve true si, después de un movimiento legal de blancas, hay una ficha en la NUEVA casilla adyacente

					  fichaAComerDer[i] = j; //guarda el indice de la ficha blanca que va a ser comida

					  if (((listaFichasNe[i]->posicion.x + 2) > 0) || ((listaFichasNe[i]->posicion.y - 2) < -7)) {
						  diagDerTras[i] = false;

						  fichaAComerDer[i] = 20; // El problema que hay es que primero detecta posibles fichas que estan adyacentes, y despues descarta que puedan ser
												  //comidas por comer fuera del tablero. Asique tenemos que volver a cambiar a 20 para que no sea detectada como fichaComida (para el bot)
					  }

					  for (int z = 0; z < 12; z++) {//necesitamos recorrer las posiciones de la BLANCAS desde cero!!! Sino el bucle empieza desde donde encontro la ficha negra del anterior if
						   //Sin embargo queremos que compare con la ficha blanca que encontro que puede comer, por lo que dejamos la que encontro en el anterior if	
						  //si hay una ficha en la segunda casilla diagonal
						  if ((((listaFichasNe[i]->posicion.x + 2) == listaFichasBl[z]->posicion.x) && ((listaFichasNe[i]->posicion.y - 2) == listaFichasBl[z]->posicion.y)) || (((listaFichasNe[i]->posicion.x + 2) == listaFichasNe[z]->posicion.x) && ((listaFichasNe[i]->posicion.y - 2) == listaFichasNe[z]->posicion.y))) {
							  diagDerTras[i] = false;
							  fichaAComerDer[i] = 20; // El problema que hay es que primero detecta posibles fichas que estan adyacentes, y despues descarta que puedan ser
												  //comidas por haber otra ficha en la posicion Siguiente. Asique tenemos que volver a cambiar a 20 para que no sea detectada como fichaComida (para el bot)
						  }
					  }
				  }
			  }
		  }
	  }
	  int k = 0;
	  for (int i = 0; i < 12; i++)
	  {
		  if (diagDerTras[i] || diagIzqTras[i])
			  return true;
		  else
			  auxdig = false;
	  }
	  return auxdig;
  }
  

  ReglasBot::~ReglasBot() {
	 
  }