#include "Mundo.h"
#include "freeglut.h"
#include <math.h>
#include <stdio.h>

Mundo::Mundo() {

}

void Mundo::dibuja()
{
	gluLookAt(x_ojo, y_ojo, z_ojo,  // posicion del ojo
			4, 4, 0.0,      // hacia que punto mira  (0,0,0) 
			0.0, 1.0, 0.0);      // definimos hacia arriba (eje Y)    

	
	tablero.dibuja();
	torre1.dibuja();
	torre2.dibuja();
	torre3.dibuja();
	torre4.dibuja();

	alfil1.dibuja();
	alfil2.dibuja();
	alfil3.dibuja();
	alfil4.dibuja();

	caballo1.dibuja();
	caballo2.dibuja();
	caballo3.dibuja();
	caballo4.dibuja();

	rey1.dibuja();
	rey2.dibuja();

	reina1.dibuja();
	reina2.dibuja();

	peones.dibuja_p();
	
}

void Mundo::comerPieza(Vector2D v, int j)
{
	printf("Quiero comer\n");
	printf("El vector que me estan pasando %f %f \n", v.x, v.y);
	int numero;
	Vector2D vectorcin, vectorcin2;
	int tipo_pieza;
	int aux;
	tipo_pieza = tablero.ocupado[int(v.x)][ int(v.y)];
	printf("TIPO DE PIEZAAAAAA %d\n", tipo_pieza);
	if (j == 1)
	{
		printf("soy negra %d\n", tipo_pieza);
		switch (tipo_pieza)
		{
		case 1:   //Tenemos un alfil negro, tenemos que encontrar cu�l de los dos es.

			vectorcin.x = alfil3.fila;
			vectorcin.y = alfil3.columna;
			vectorcin2.x = alfil4.fila;
			vectorcin2.y = alfil4.columna;

			if ((vectorcin.x == int(v.x)) && (vectorcin.y == int(v.y)))

				alfil3.radio = 0;

			else if ((vectorcin2.x == int(v.x)) && (vectorcin2.y == int(v.y)))

				alfil4.radio = 0;

			break;
		case 2: //Tenemos un caballo negro
			
			vectorcin.x = caballo3.fila;
			vectorcin.y = caballo3.columna;
			vectorcin2.x = caballo4.fila;
			vectorcin2.y = caballo4.columna;

			if ((vectorcin.x == int(v.x)) && (vectorcin.y == int(v.y)))

				caballo3.radio = 0;

			else if ((vectorcin2.x == int(v.x)) && (vectorcin2.y == int(v.y)))

				caballo4.radio = 0;
			break;
		case 3: // Tenemos peones negros

			printf("HOLA\n");
			for (int i = 0; i < 16; i++)
			{
				
				vectorcin =peones.listaPeones[i]->GetPos();
				//printf("HHHHHOOOOLLLSAAAAA %f %f ", vectorcin.x, vectorcin.y);
				//vectorcin.y = peones.listaPeones[i]->columna;
				if (vectorcin.x == v.x && vectorcin.y == v.y)
					aux = i;
					
			}

			peones.listaPeones[aux]->radio = 0;

		
		case 4: //Tenemos una reina negra
				vectorcin.x = reina2.fila;
				vectorcin.y = reina2.columna;
			
			if ((vectorcin.x == int(v.x)) && (vectorcin.y == int(v.y)))

				reina2.radio = 0;
				break;

		case 5://Tenemos una Rey

			vectorcin.x = rey2.fila;
			vectorcin.y = rey2.columna;

			if ((vectorcin.x == int(v.x)) && (vectorcin.y == int(v.y)))

				rey2.radio = 0;
			break;
		case 6: //Tenemos torres negras

			vectorcin.x = torre3.fila;
			vectorcin.y = torre3.columna;
			vectorcin2.x = torre4.fila;
			vectorcin2.y = torre4.columna;

			if ((vectorcin.x == int(v.x)) && (vectorcin.y == int(v.y)))

				torre3.radio = 0;

			else if ((vectorcin2.x == int(v.x)) && (vectorcin2.y == int(v.y)))

				torre4.radio = 0;
			break;
		
		}
	}

	if (j == 0)
	{
		printf("soy negra %d\n", tipo_pieza);
		switch (tipo_pieza)
		{
		case 1:   //Tenemos un alfiles blancos

			vectorcin.x = alfil1.fila;
			vectorcin.y = alfil1.columna;
			vectorcin2.x = alfil2.fila;
			vectorcin2.y = alfil2.columna;

			if ((vectorcin.x == int(v.x)) && (vectorcin.y == int(v.y)))

				alfil1.radio = 0;

			else if ((vectorcin2.x == int(v.x)) && (vectorcin2.y == int(v.y)))

				alfil2.radio = 0;

			break;
		case 2: //Tenemos un caballos blancos

			vectorcin.x = caballo1.fila;
			vectorcin.y = caballo1.columna;
			vectorcin2.x = caballo2.fila;
			vectorcin2.y = caballo2.columna;

			if ((vectorcin.x == int(v.x)) && (vectorcin.y == int(v.y)))

				caballo1.radio = 0;

			else if ((vectorcin2.x == int(v.x)) && (vectorcin2.y == int(v.y)))

				caballo2.radio = 0;
			break;
		case 3: // Tenemos peones blancos

			printf("HOLA\n");
			for (int i = 0; i < 16; i++)
			{

				vectorcin = peones.listaPeones[i]->GetPos();
				//printf("HHHHHOOOOLLLSAAAAA %f %f ", vectorcin.x, vectorcin.y);
				//vectorcin.y = peones.listaPeones[i]->columna;
				if (vectorcin.x == v.x && vectorcin.y == v.y)
					aux = i;

			}

			peones.listaPeones[aux]->radio = 0;


		case 4: //Tenemos una reina blanca
			vectorcin.x = reina1.fila;
			vectorcin.y = reina1.columna;

			if ((vectorcin.x == int(v.x)) && (vectorcin.y == int(v.y)))

				reina1.radio = 0;
			break;

		case 5://Tenemos un Rey 

			vectorcin.x = rey1.fila;
			vectorcin.y = rey1.columna;

			if ((vectorcin.x == int(v.x)) && (vectorcin.y == int(v.y)))

				rey1.radio = 0;
			break;
		case 6: //Tenemos torres blancas

			vectorcin.x = torre1.fila;
			vectorcin.y = torre1.columna;
			vectorcin2.x = torre2.fila;
			vectorcin2.y = torre2.columna;

			if ((vectorcin.x == int(v.x)) && (vectorcin.y == int(v.y)))

				torre1.radio = 0;

			else if ((vectorcin2.x == int(v.x)) && (vectorcin2.y == int(v.y)))

				torre2.radio = 0;
			break;

		}
	}
}

void Mundo::mueve(Vector2D v5, int n)
{
	Vector2D v1, v2;
	if (n % 2 != 0)
		pos1 = v5;
	else
		pos2 = v5;
	Vector2D retorno,vectorcin,vectorcin2;
	
	/*v1 = v5;
	v2 = v5;*/
	int completo = 0,tipo=0,aux=0;
	
	
	//printf(" OCUPADO: %d\n", tablero.ocupado[3][0]);
	if (n % 2 == 0) {
		if (turno == 0) {
		tipo = tablero.ocupado[int(pos1.y)][int(pos1.x)];printf("TIPO DE PIEZAAAAAA %d\n", tipo);
			switch (tipo)
			{
				/*case 1:

					vectorcin.x = alfil3.fila;
					vectorcin.y = alfil3.columna;
					vectorcin2.x = alfil4.fila;
					vectorcin2.y = alfil4.columna;

					if ((vectorcin.x == int(v.x)) && (vectorcin.y == int(v.y)))

						alfil3.mov_posible(v, n);

					else if ((vectorcin2.x == int(v.x)) && (vectorcin2.y == int(v.y)))

						alfil4.mov_posible(v, n);

					break;*/
					/*case 2:

						vectorcin.x = caballo3.fila;
						vectorcin.y = caballo3.columna;
						vectorcin2.x = caballo4.fila;
						vectorcin2.y = caballo4.columna;

						if ((vectorcin.x == int(v.x)) && (vectorcin.y == int(v.y)))

							caballo3.mov_posible(v, n);

						else if ((vectorcin2.x == int(v.x)) && (vectorcin2.y == int(v.y)))

							caballo4.mov_posible(v, n);
						break;*/
						/*case 3:

							for (int i = 0; i < 16; i++)
							{

								vectorcin = peones.listaPeones[i]->GetPos();
								if (vectorcin.x == v.x && vectorcin.y == v.y)
									aux = i;

							}

							peones.listaPeones[aux]->mov_posible(v, n);*/


			case 4: //Tenemos una reina blanca
				printf("HOLA\n");
				vectorcin.x = reina1.fila;
				printf("REEEEINa%d", reina1.fila);
				vectorcin.y = reina1.columna;
				printf("REINA%d", reina1.columna);
				printf("VECTOR CLICK%f %f\\\\\\", v5.x, v5.y);
				if ((vectorcin.x == int(pos1.y)) && (vectorcin.y == int(pos1.x))) {
					printf("JJJJJJJ\n");
					reina1.mov_posible(pos1, pos2, n);
					if (retorno.x == 1) {
						turno = 1;
						//printf("retornooooooo\n");
						if (retorno.y == 1) {
							//printf("comeeeer\n");
							v1 = reina1.GetPos();
							comerPieza(v1, 1);
							//printf(" El vector elegido %f %f", v1.x, v1.y);
						}

					}
				}
				break;

			case 5://Tenemos una Rey

				vectorcin.x = rey1.fila;
				vectorcin.y = rey1.columna;

				if ((vectorcin.x == int(pos1.y)) && (vectorcin.y == int(pos1.x)))
					printf("Ha entrado\n");
				rey1.mov_posible(pos1, pos2, n); {
					if (retorno.x == 1) {
						turno = 1;
						//printf("retornooooooo\n");
						if (retorno.y == 1) {
							//printf("comeeeer\n");
							v1 = rey1.GetPos();
							comerPieza(v1, 1);
							//printf(" El vector elegido %f %f", v1.x, v1.y);
						}
					}
				}
				break;
				/*case 6:

					vectorcin.x = torre3.fila;
					vectorcin.y = torre3.columna;
					vectorcin2.x = torre4.fila;
					vectorcin2.y = torre4.columna;

					if ((vectorcin.x == int(v.x)) && (vectorcin.y == int(v.y)))

						torre3.mov_posible(v, n);

					else if ((vectorcin2.x == int(v.x)) && (vectorcin2.y == int(v.y)))

						torre4.mov_posible(v, n);
					break;*/

			}

		}
	}

	/*}
	if (completo == 1)
		turno = 1;

	else if (turno == 1) {
		retorno = reina2.mov_posible(v, n);
		if (retorno.x == 1)
		{
			turno = 0;
			if (retorno.y == 1) {
				v2 = reina2.GetPos();
				comerPieza(v2, 0);
			}
		}

	}*/
}

void Mundo::inicializa()
{
	x_ojo = 4;
	y_ojo = 4;
	z_ojo = 15;

	torre1.fila = 0;
	torre1.columna = 0;
	torre1.jugador = 0;

	torre2.jugador = 0;
	torre2.fila = 7;
	torre2.columna = 0;

	torre3.jugador = 1;
	torre3.fila = 0;
	torre3.columna = 7;

	torre4.jugador = 1;
	torre4.fila = 7;
	torre4.columna = 7;

	alfil1.jugador = 0;
	alfil1.fila = 2;
	alfil1.columna = 0;

	alfil2.jugador = 0;
	alfil2.fila = 5;
	alfil2.columna = 0;

	alfil3.jugador = 1;
	alfil3.fila = 2;
	alfil3.columna = 7;

	alfil4.jugador = 1;
	alfil4.fila = 5;
	alfil4.columna = 7;

	caballo1.jugador = 0;
	caballo1.fila = 1;
	caballo1.columna = 0;

	caballo2.jugador = 0;
	caballo2.fila = 6;
	caballo2.columna = 0;

	caballo3.jugador = 1;
	caballo3.fila = 1;
	caballo3.columna = 7;

	caballo4.jugador = 1;
	caballo4.fila = 6;
	caballo4.columna = 7;

	rey1.jugador = 0;
	rey1.fila = 4;
	rey1.columna = 0;

	rey2.jugador = 1;
	rey2.fila = 4;
	rey2.columna = 7;

	reina1.jugador = 0;
	reina1.fila = 3;
	reina1.columna = 0;

	reina2.jugador = 1;
	reina2.fila = 3;
	reina2.columna = 7;

	////DIBUJO DE PEONES
	for (int i = 0; i < 8; i++) {
		Peon* aux = new Peon(0, 0.2, i, 1);
		peones.agregar(aux); // agregar a la lista
		Peon* aux1 = new Peon(1, 0.2, i, 6);
		peones.agregar(aux1); // agregar a la lista
	}
	

  

}

void Mundo::tecla(unsigned char key)
{

}

