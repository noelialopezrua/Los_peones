#include "Mundo.h"
#include "freeglut.h"
#include <math.h>
#include "Tablero.h"
#include "Peon.h"
#include "Torre.h"
#include "Alfil.h"

/*void Mundo::rotarOjo()
{
	float dist=sqrt(x_ojo*x_ojo+z_ojo*z_ojo);
	float ang=atan2(z_ojo,x_ojo);
	ang+=0.05f;
	x_ojo=dist*cos(ang);
	z_ojo=dist*sin(ang);
}*/


void Mundo::dibuja()
{
	gluLookAt(x_ojo, y_ojo, z_ojo,  // posicion del ojo
			0.0, 0, 0.0,      // hacia que punto mira  (0,0,0) 
			0.0, 1.0, 0.0);      // definimos hacia arriba (eje Y)    

	//aqui es donde hay que poner el codigo de dibujo

	tablero.dibuja();
	peon.dibuja();
	torre.dibuja();
	alfil.dibuja();
	rey.dibuja();
	
}

void Mundo::mueve()
{

}

void Mundo::inicializa()
{
	x_ojo=0;
	y_ojo=20;
	z_ojo=45;

	peon.setPosicion(10, 14);
	peon.setColor(0, 0, 255);

	torre.setPosicion(14, 14);
	torre.setColor(255, 0, 0);

	alfil.setPosicion(14, 6);
	alfil.setColor(0, 255, 0);

	rey.setPosicion(14, 2);
	rey.setColor(192,192,192);
}

void Mundo::tecla(unsigned char key)
{
	peon.mueve(key);
	torre.mueve(key);
	alfil.mueve(key);
	rey.mueve(key);
}
