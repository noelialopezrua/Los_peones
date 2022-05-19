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
	//torre.dibuja();
	torres.dibuja();
	alfiles.dibuja();
}

void Mundo::mueve()
{

}

void Mundo::inicializa()
{
	x_ojo=4;
	y_ojo=4;
	z_ojo=15;

	//DIBUJO DE TORRES.
	Torre* t1= new Torre(0,0.4,0,0);
	torres.agregar(t1); // agregar a la lista
	Torre* t2 = new Torre(0, 0.4, 7, 0); 
	torres.agregar(t2); // agregar a la lista
	Torre* t3 = new Torre(1, 0.4, 0, 7);
	torres.agregar(t3); // agregar a la lista
	Torre* t4 = new Torre(1, 0.4, 7, 7);
	torres.agregar(t4); // agregar a la lista
	

	//DIBUJO DE ALFILES
	Alfil* a1 = new Alfil(0, 0.4, 0, 2);
	alfiles.agregar(a1); // agregar a la lista
	Alfil* a2 = new Alfil(0, 0.4, 0, 5);
	alfiles.agregar(a2); // agregar a la lista
	Alfil* a3 = new Alfil(1, 0.4, 7, 2);
	alfiles.agregar(a3); // agregar a la lista
	Alfil* a4 = new Alfil(1, 0.4, 7, 5);
	alfiles.agregar(a4); // agregar a la lista
}

void Mundo::tecla(unsigned char key)
{

}
