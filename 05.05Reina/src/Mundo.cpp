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
	torres.dibuja_t();
	alfiles.dibuja_a();
	caballos.dibuja_c();
	reyes.dibuja_rey();
	reinas.dibuja_r();
	peones.dibuja_p();
}

void Mundo::mueve(Vector2D v)
{
	reinas.mueve(v);
}

void Mundo::inicializa()
{
	x_ojo = 4;
	y_ojo = 4;
	z_ojo = 15;

	//DIBUJO DE TORRES.
	Torre* t1 = new Torre(0, 0.4, 0, 0);
	torres.agregar(t1); // agregar a la lista
	Torre* t2 = new Torre(0, 0.4, 7, 0);
	torres.agregar(t2); // agregar a la lista
	Torre* t3 = new Torre(1, 0.4, 0, 7);
	torres.agregar(t3); // agregar a la lista
	Torre* t4 = new Torre(1, 0.4, 7, 7);
	torres.agregar(t4); // agregar a la lista

	//FILA ES COLUMNA
	//DIBUJO DE ALFILES
	Alfil* a1 = new Alfil(0, 0.5, 2, 0);
	alfiles.agregar(a1); // agregar a la lista
	Alfil* a2 = new Alfil(0, 0.5, 5, 0);
	alfiles.agregar(a2); // agregar a la lista
	Alfil* a3 = new Alfil(1, 0.5, 2, 7);
	alfiles.agregar(a3); // agregar a la lista
	Alfil* a4 = new Alfil(1, 0.5, 5, 7);
	alfiles.agregar(a4); // agregar a la lista

	//DIBUJO DE CABALLOS
	Caballo* c1 = new Caballo(0, 0.3, 1, 0);
	caballos.agregar(c1); // agregar a la lista
	Caballo* c2 = new Caballo(0, 0.3, 6, 0);
	caballos.agregar(c2); // agregar a la lista
	Caballo* c3 = new Caballo(1, 0.3, 1, 7);
	caballos.agregar(c3); // agregar a la lista
	Caballo* c4 = new Caballo(1, 0.3, 6, 7);
	caballos.agregar(c4); // agregar a la lista

	//DIBUJO DE REYES
	Rey* rey1 = new Rey(0, 0.4, 4, 0);
	reyes.agregar(rey1); // agregar a la lista
	Rey* rey2 = new Rey(1, 0.4, 4, 7);
	reyes.agregar(rey2); // agregar a la lista

	//DIBUJO DE REINAS
	Reina* r1 = new Reina(0, 0.55, 3, 0);
	reinas.agregar(r1); // agregar a la lista
	Reina* r2 = new Reina(1, 0.55, 3, 7);
	reinas.agregar(r2); // agregar a la lista

	//DIBUJO DE PEONES
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
