#include "Tablero.h"

Tablero::Tablero()
{
	bot.mode = 0;

	cont1 = 0;
	cont2 = 0;
	//reservamos memoria para la matriz de punteros del trablero
	controlSeleccion = 0;
	n = 8, m = 8;
	c = new Casilla *[n];		//filas
	for (i = 0; i < n; i++) {
		c[i] = new Casilla[m];     //columnas
	}

	//asignamos a listaFichas los valores de posición inicial (solo se debe llamar una vez)

	//blancas
	int p = 0;
	for (i = 0; i < 3; i++) {
		for (j = 0; j < 8; j++) {
			if ((i + j) % 2 == 0) {
				listaFichasB.push_back(new FichaBlanca(i, j));
				p++;
			}
		}
	}

	//negras
	for (i = 5; i < 8; i++) {
		for (j = 0; j < 8; j++) {
			if ((i + j) % 2 == 0) {
				listaFichasN.push_back(new FichaNegra(i, j));
			}
		}
	}
}

void Tablero::dibujarTablero() {
	//si declaro un segundo objeto de tablero (llamado desde OnDrawn) el constructor se vuelve a llamar y se dibujan las fichas iniciales otra vez
	

	//Este if solo permite que se asigne turno para cambiar el punto de vista solo si se juega en el modo 1vs1.
	if (bot.mode == 0)
	{
		graf.Turn = regla.getTurno();
	}
	graf.DibTab();


	for (i = 0; i < 8; i++) {	//cada i es una fila del tablero
		for (j = 0; j < 8; j++) { //cada j es una columna del tablero
			c[i][j].dibujarCasilla(i, j);
		}
	}
	hand.dibujarSeleccion();
}
void Tablero::dibujarFichasIniciales() {
	//blancas
	//damos por sentado que ya estamos situados en la esquina inferior izquierda
	//fichB = new FichaBlanca();
	int nb = 0;
	int nn = 0;
	int i, j;
	int aux = 0;
	int aux2 = 0;

	//las posiciones de las fichas se cambian en otros métodos, éste solo invoca el dibujode las 20 fichas
	for (i = 0; i < 3; i++) {  //colocamos las fichas iniciales en aquellos que i+j sea par, de las 4 primeras filas
		for (j = 0; j < 8; j++) {
			if ((i + j) % 2 == 0) {
				listaFichasB[nb]->dibujarFicha();
				nb++;

			}
		}
	}

	//negras
	for (i = 5; i < 8; i++) {  //colocamos las fichas iniciales en aquellos que i+j sea par, de las 4 primeras filas
		for (j = 0; j < 8; j++) {
			if ((i + j) % 2 == 0) {
				listaFichasN[nn]->dibujarFicha();
				nn++;
			}
		}
	}

	regla.delListaFichas(listaFichasB, listaFichasN);
	if (graf.Turn == true)
		hand.dibujarManoBlanca();
	else if (bot.mode == 0)  ///////////////////////////////////bottttt
		hand.dibujarManoNegra();
}
void Tablero::moverMano(unsigned char tecla) {
	//Tablero t1;
	bool fichaComida = false;
	Vector2D posSiguiente;//vector auxiliar para regla.setPosSig() la posicion siguiente (a donde voy)
	Vector2D posActual;//vector auxiliar para pasar a regla.setPosAct() la posicion anterior (de donde vengo)
	bool turno = false;//variable local para recoger el turno de Reglas
	int i;
	static int aux = 0; //para guardar la i del vector de fichas
	//sin estatic se pierde el valor (dentro de la misma funcion)
	//int aux2 = 0;//variable de control para evitar que los if se ejecuten instantaneamente¿si la declaro aquí cada vez que pulso vale 0?

	turno = 1;
	float x, y;

	//Adaptamos el control al punto de vista de cada jugador.
	//Para Blancas o para el punto de vista aéreo.
	turno = regla.getTurno();
	if ((turno == 1) || (graf.vis == 2)) {
		if (tecla == 'w' && hand.fm < 7) {
			(hand.fm)++;
		}

		if (tecla == 'a' && hand.cm > 0) {
			(hand.cm)--;
		}

		if (tecla == 'd' && hand.cm < 7) {
			(hand.cm)++;
		}

		if (tecla == 's' && hand.fm > 0) {
			(hand.fm)--;
		}
	}

	//Para Negras. Comprobar la gestión de las negras en función del modo.
	if ((turno == 0) && (bot.mode == 0) && (graf.vis != 2)) {
		if ((tecla == 'w') && (hand.fm > 0)) {
			(hand.fm)--;
		}

		if ((tecla == 'a') && (hand.cm < 7)) {
			(hand.cm)++;
		}

		if ((tecla == 'd') && (hand.cm > 0)) {
			(hand.cm)--;
		}

		if ((tecla == 's') && (hand.fm < 7)) {
			(hand.fm)++;
		}
	}

	//Punto de vista aéreo.
	if (tecla == 'q') {
		if (graf.vis == 2)
			graf.vis = 0;
		else
			graf.vis = 2;
	}


	//Accedemos al 1vs1.
	if ((tecla == '1') && (graf.Escena == 0))
	{
		graf.Escena = 5;
	}

	//Accedemos al 1vsBot. Deshabilitado por ahora
	if ((tecla == '2') && (graf.Escena == 0))
	{
		bot.mode = 1;
		graf.Escena = 5;
	}

	//Accedemos a las instrucciones.
	if ((tecla == '3') && (graf.Escena != 1))
	{
		if (graf.Escena == 2)
			graf.Escena = 0;
		else if (graf.Escena == 0)
			graf.Escena = 2;
		else if (graf.Escena == 4)
			graf.Escena = 3;
		else if (graf.Escena == 3)
			graf.Escena = 4;
	}

	//Gestión de pausa.

	if ((tecla == 'p') && ((graf.Escena == 3) || (graf.Escena == 1)))
	{
		if (graf.Escena == 3)
			graf.Escena = 1;
		else
			graf.Escena = 3;
	}

	//Salimos del programa
	if ((tecla == '4') && ((graf.Escena == 0) || (graf.Escena == 3)))
	{
		exit(-1);
	}

	if (tecla == ' ') {
		turno = regla.getTurno();
		if (turno == 1) {
			for (i = 0; i < 12; i++) {
				//codigo para iluminar la casilla seleccionada (comprobamos que esté ocupada por una casilla blanca)
				if (listaFichasB[i]->posicion.x == (-hand.cm) && listaFichasB[i]->posicion.y == (-hand.fm)) {

					aux = i;
					hand.seleccionada = true;
					hand.fichaSeleccionada.x = hand.cm;
					hand.fichaSeleccionada.y = hand.fm;
				}
			}
		}

		if ((turno == 0) && (bot.mode == 0)) {
			for (i = 0; i < 12; i++) {
				//codigo para iluminar la casilla seleccionada (comprobamos que esté ocupada por una casilla negra)
				if (listaFichasN[i]->posicion.x == (-hand.cm) && listaFichasN[i]->posicion.y == (-hand.fm)) {
					aux = i;
					hand.seleccionada = true;
					hand.fichaSeleccionada.x = hand.cm;
					hand.fichaSeleccionada.y = hand.fm;
				}
			}
		}
	}

	if (tecla == ' ' && hand.seleccionada == true) {
		regla.setListaFichas(listaFichasB, listaFichasN);//le pasamos a "Reglas.h" las posiciones de las fichas blancas y negras y

		//actualizamos dichas posiciones cada vez que se pulsa el espacio

		if (turno == 1) {
			regla.setListaFichas(listaFichasB, listaFichasN);
			//aquí entra con el primer espacio que pulsa , pero no vuelve a entrar(a reactualizar los valores de posicion) hasta que no pulso espacio por
			//segunda vez
			posActual.x = -(hand.fichaSeleccionada.x);
			posActual.y = -(hand.fichaSeleccionada.y);
			regla.setPosAct(posActual);//fichaSeleccionada guarda la posicion inicial de la ficha (de donde viene)

			//si no pongo "controlSeleccion", cada espacio que dé cambia de turno, y lo que quiero es que cambie de turno al
			//segundo espacio (el primero selecciona ficha, el segundo la coloca y después cambia el turno)
			//el mismo cambio de turno pone controlSeleccion a 0;
			controlSeleccion++;//si el movimiento es legal y ha finiquitado controlSeleccion= a cambiarTurno
			//sino controlSeleccion = 1;

			if (controlSeleccion == 2) {
				regla.setListaFichas(listaFichasB, listaFichasN);
				posSiguiente.x = (-hand.cm);
				posSiguiente.y = (-hand.fm);
				regla.setPosSig(posSiguiente);

				if (regla.posibleComerFicha() || (regla.posibleComerConReina())) {//posibleComerFicha da positivo cuando hay una ficha negra adyacente (no comprueba que una casilla más allá este libre)
																													//Incluyo tambien la posible comida de las reinas hacia atras
					int h = 1;
					if (regla.fichaComida() || (regla.fichaComidaConReina())) {

						//regla.setListaFichas(listaFichasB, listaFichasN);
						//era posible comer y ha comido
						listaFichasB[aux]->posicion.x = (-hand.cm);//estas dos instrucciones
						listaFichasB[aux]->posicion.y = (-hand.fm);//son las que redibujan la ficha (actualizando su posicion
						hand.seleccionada = false;
						regla.delListaFichas(listaFichasB, listaFichasN);//Nos devuelve los estados de las fichas
						regla.hacerReina();
						dibujarCementerio(); //Actualizamos la posicion de las fichas para que no obligue a comer a otra ficha cuando ya se ha comido y se ha mandado al cementerio
											 //los usamos para cuando una ficha blanca come a una negra saber que ficha negra es la que se ha comido y mandarla al cementerio
						graf.ContBlancas++;//cuando ya hemos actualizado el estado de la última comida, contamos muertas
						printf("%d", graf.ContBlancas);
						///////////////////////////////////////////////////////////////////
						regla.setListaFichas(listaFichasB, listaFichasN);


						int m = 0;
						int n = 1;
						n = m;
						//if ((regla.posibleComerFicha() == false && regla.posibleComerConReina() == false) || (regla.diagDer[aux] == false && regla.diagIzq[aux] == false)) {

						if (((regla.posibleComerFicha() == false && (regla.posibleComerConReina() == false)) || (regla.diagDer[aux] == false && regla.diagIzq[aux] == false && regla.diagDerTras[aux] == false && regla.diagIzqTras[aux] == false))) {
							controlSeleccion = regla.cambiarTurno();
							hand.seleccionada = false;
						}
						else {
							controlSeleccion = 1;
						}
					}

					else {
						controlSeleccion = 1;
					}
				}
				//si no es posible comer ficha implemento los movimientos normales, tanto para las fichas normales
				//como para la reina (esta adicionalmente tiene que comprobar que la ficha en cuestion sea reina)
				else if (regla.movDiagUnit() || (regla.moverReina() && listaFichasB[aux]->estado == 1)) {
					regla.setListaFichas(listaFichasB, listaFichasN);
					listaFichasB[aux]->posicion.x = (-hand.cm);
					listaFichasB[aux]->posicion.y = (-hand.fm);
					hand.seleccionada = false;
					controlSeleccion = regla.cambiarTurno();
					regla.hacerReina();
				}
				else
					controlSeleccion = 1;
			}
		}
		////////////////////////////////////////////////////
		//negras
		else if (bot.mode == 0) {//turno de negras y bot desactivado
			regla.setListaFichas(listaFichasB, listaFichasN);

			//aquí entra con el primer espacio que pulsa , pero no vuelve a entrar(a reactualizar los valores de posicion) hasta que no pulso espacio por
			//segunda vez
			posActual.x = -(hand.fichaSeleccionada.x);
			posActual.y = -(hand.fichaSeleccionada.y);
			regla.setPosAct(posActual);//fichaSeleccionada guarda la posicion inicial de la ficha (de donde viene)

			//si no pongo "controlSeleccion", cada espacio que dé cambia de turno, y lo que quiero es que cambie de turno al
			//segundo espacio (el primero selecciona ficha, el segundo la coloca y después cambia el turno)
			//el mismo cambio de turno pone controlSeleccion a 0;
			controlSeleccion++;//si el movimiento es legal y ha finiquitado controlSeleccion= a cambiarTurno
			//sino controlSeleccion = 1;

			if (controlSeleccion == 2) {
				regla.setListaFichas(listaFichasB, listaFichasN);
				posSiguiente.x = (-hand.cm);
				posSiguiente.y = (-hand.fm);
				regla.setPosSig(posSiguiente);

				if (regla.posibleComerFichaN() || (regla.posibleComerConReinaN())) {//posibleComerFicha da positivo cuando hay una ficha negra adyacente (no comprueba que una casilla más allá este libre)
																													//Incluyo tambien la posible comida de las reinas hacia atras
					int h = 1;
					if (regla.fichaComidaN() || (regla.fichaComidaConReinaN())) {
						//regla.setListaFichas(listaFichasB, listaFichasN);
						//era posible comer y ha comido
						listaFichasN[aux]->posicion.x = (-hand.cm);//estas dos instrucciones
						listaFichasN[aux]->posicion.y = (-hand.fm);//son las que redibujan la ficha (actualizando su posicion
						hand.seleccionada = false;
						regla.delListaFichas(listaFichasB, listaFichasN);//Nos devuelve los estados de las fichas
						regla.hacerReinaN();
						dibujarCementerio(); //Actualizamos la posicion de las fichas para que no obligue a comer a otra ficha cuando ya se ha comido y se ha mandado al cementerio
											 //los usamos para cuando una ficha blanca come a una negra saber que ficha negra es la que se ha comido y mandarla al cementerio
						graf.ContNegras++;//cuando ya hemos actualizado el estado de la última comida, contamos muertas

						///////////////////////////////////////////////////////////////////
						regla.setListaFichas(listaFichasB, listaFichasN);


						int m = 0;
						int n = 1;
						n = m;
						//if (regla.posibleComerFichaN() == false && (regla.posibleComerConReinaN() == false) ) {

						if (((regla.posibleComerFichaN() == false && (regla.posibleComerConReinaN() == false)) || (regla.diagDer[aux] == false && regla.diagIzq[aux] == false && regla.diagDerTras[aux] == false && regla.diagIzqTras[aux] == false))) {

							controlSeleccion = regla.cambiarTurno();
							hand.seleccionada = false;

						}
						else {
							controlSeleccion = 1;
						}
					}

					else {
						controlSeleccion = 1;
					}
				}
				//si no es posible comer ficha implemento los movimientos normales, tanto para las fichas normales
				//como para la reina (esta adicionalmente tiene que comprobar que la ficha en cuestion sea reina)
				else if (regla.movDiagUnitN() || (regla.moverReina() && listaFichasN[aux]->estado == 1)) {
					regla.setListaFichas(listaFichasB, listaFichasN);
					listaFichasN[aux]->posicion.x = (-hand.cm);
					listaFichasN[aux]->posicion.y = (-hand.fm);
					hand.seleccionada = false;
					controlSeleccion = regla.cambiarTurno();
					regla.hacerReinaN();
				}
				else
					controlSeleccion = 1;
			}
		}
	}
}


	void Tablero::jugarBot() {



		bool turno = regla.getTurno();
		Jugada *jugada;

		//hand.dibujarJugadaBot();
		if ((bot.mode == 1) && (turno == 0) && (graf.ContBlancas < 12)) {

			bot.setListaFichas(listaFichasB, listaFichasN);//los vectores de ReglasBot adquieren las posiciones de los de tablero
			regla.setListaFichas(listaFichasB, listaFichasN);//los vectores de Reglas adquieren las posiciones de los de tablero

			int j = 0;

			bot.calcularPosicionesPosibles();

			jugada = bot.elegirMejorMov();
			//////////////////////
			///////primero guardamos la posicion original de la ficha que se va a mover para marcarla
			hand.posAnteriorBot.x = (-listaFichasN[jugada->idFicha]->posicion.x);  ////////////////////////////////////////////infraccion de acceso de lectura
			hand.posAnteriorBot.y = (-listaFichasN[jugada->idFicha]->posicion.y);
			//hand.dibujarJugadaBot();
			//////la ficha se mueve adonde le indica jugada
			listaFichasN[jugada->idFicha]->posicion.x = (jugada->posSig.x);
			listaFichasN[jugada->idFicha]->posicion.y = (jugada->posSig.y);

			int k = 0;

			regla.hacerReinaBot();

			bot.delListaFichas(listaFichasB, listaFichasN);
			bot.setListaFichas(listaFichasB, listaFichasN);
			regla.delListaFichas(listaFichasB, listaFichasN);
			regla.setListaFichas(listaFichasB, listaFichasN);


			if (jugada->idFichaComer != 20) {//si se puede comer una ficha
				listaFichasB[jugada->idFichaComer]->estado = -1;

				regla.setListaFichas(listaFichasB, listaFichasN);//los vectores de Reglas adquieren las posiciones de los de tablero
				dibujarCementerio(); //Actualizamos la posicion de las fichas para que no obligue a comer a otra ficha cuando ya se ha comido y se ha mandado al cementerio
											//los usamos para cuando una ficha blanca come a una negra saber que ficha negra es la que se ha comido y mandarla al cementerio

				graf.ContNegras++; //actualiza el contador de fichas blancas comidas por el bot

				int aux = jugada->idFicha;

				regla.setListaFichas(listaFichasB, listaFichasN);//los vectores de Reglas adquieren las posiciones de los de tablero
				bot.setListaFichas(listaFichasB, listaFichasN);//los vectores de ReglasBot adquieren las posiciones de los de tablero
				if (bot.calcularPosicionesPosibles() == true)//Con este if volvemos a comprobar si puede comer de nuevo
				{
					jugada = bot.elegirMejorMov();
					if (aux == jugada->idFicha) {
						listaFichasN[jugada->idFicha]->posicion.x = (jugada->posSig.x);
						listaFichasN[jugada->idFicha]->posicion.y = (jugada->posSig.y);

						if (jugada->idFichaComer != 20) {
							listaFichasB[jugada->idFichaComer]->estado = -1;
							graf.ContNegras++;
						}
						bot.setListaFichas(listaFichasB, listaFichasN);//bot iguala sus vectores a los de tablero
						regla.setListaFichas(listaFichasB, listaFichasN);
						int k = 0;
					}
				}
			}



			regla.hacerReinaBot();
			bot.delListaFichas(listaFichasB, listaFichasN);
			regla.delListaFichas(listaFichasB, listaFichasN);
			bot.setListaFichas(listaFichasB, listaFichasN);//bot iguala sus vectores a los de tablero
			regla.setListaFichas(listaFichasB, listaFichasN);
			regla.cambiarTurno();
		}
	}


void Tablero::marcarJugadaBot() {
	if(bot.mode == 1) hand.dibujarJugadaBot();

}

void Tablero::dibujarCementerio() {
	regla.delListaFichas(listaFichasB, listaFichasN);//cada funcion de tablero debe actualizar las fichas con Reglas
												//de manera independiente
	
	int contN = -1;
	int contB = -8;
	int contSaltoN = 0;
	int contSaltoB = 0;
	int auxN = 0;
	int auxB = 0;
	for (int i = 0; i < 12; i++) {

		if (listaFichasN[i]->estado == -1) {
			contN++;
			listaFichasN[i]->posicion.x = 2 + auxN;
			listaFichasN[i]->posicion.y = -(contN + 0.2);
			contSaltoN++;
		}
		if (contSaltoN == 3)
		{
			auxN++;
			contN = -1;
			contSaltoN = 0;
		}
	}
	for (int i = 0; i < 12; i++) {

		if (listaFichasB[i]->estado == -1) {
			contB++;
			listaFichasB[i]->posicion.x = -9 + auxB;
			listaFichasB[i]->posicion.y = contB + 0.2;
			contSaltoB++;
			int i = 0;
		}
		if (contSaltoB == 3)
		{
			auxB--;
			contB = -8;
			contSaltoB = 0;
		}
	}
	int i = 0;
}


void Tablero::Animacion() {

	//Contador de transición de la primera escena.
	if ((graf.Escena == 5)) {
		cont1 += 0.1;
		if (cont1 > 6)
			graf.Escena = 1;
	}

	if ((graf.Escena == 6) || (bot.FinBot==1)) {
		graf.Escena = 6; //La redundancia sirve para poner la escena a 6 cuando accedemos a esta funcion  a traves del bot.
		cont2 += 0.1;
		if (cont2 > 12)
			exit(-1);
	}

	//Contador para salir del juego una vez se quede en tablas
	if ((graf.ContBlancas == 11) && (graf.ContNegras == 11)) {
		graf.Escena = 7;
		cont3 += 0.1;
		if (cont3 > 12)
			exit(-1);
	}
	
}

Tablero::~Tablero()
{


}