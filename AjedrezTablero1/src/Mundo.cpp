#include "Mundo.h"
#include "freeglut.h"
#include <math.h>

Mundo::Mundo() {

}

void Mundo::dibuja()
{
	gluLookAt(x_ojo, y_ojo, z_ojo,  // posicion del ojo
			4, 4, 0.0,      // hacia que punto mira  (0,0,0) 
			0.0, 1.0, 0.0);      // definimos hacia arriba (eje Y)    

	
	
	tablero.dibuja();
	torre.dibuja();
	torres.dibuja();
}

void Mundo::mueve()
{

}

void Mundo::inicializa()
{
	x_ojo=4;
	y_ojo=4;
	z_ojo=15;

	
	Torre* t1= new Torre(0,0.4,0,0);
	torres.agregar(t1); // agregar a la lista

	
}

void Mundo::tecla(unsigned char key)
{

}
