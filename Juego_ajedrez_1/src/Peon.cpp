#include "Vector2D.h"
#include"Peon.h"
#include <freeglut.h>

void Peon::setPosicion(float _x, float _z)
{
	//si queremos cambiar la coordenda z de la pieza ir a la función dibuja.
	posicion.x = _x;
	posicion.z = _z;
}

void Peon::setColor(unsigned char r, unsigned char v, unsigned char a)
{
	rojo = r;
	verde = v;
	azul = a;
}



void Peon::dibuja()
{
	glColor3ub(rojo, verde, azul);
	glTranslatef(posicion.x, 0, posicion.z);
	glutSolidSphere(radio, 20, 20);
	glTranslatef(-posicion.x,0, -posicion.z);
}

void Peon::mueve(unsigned char estado)
{
	//esto es siempre desde el punto de vista del peon mirando hacia el adversario

	switch (estado) {
	case 'a':
		//este caso es el de movimiento 2 casilla hacia delante
		if (posicion.x == 8)
		posicion.x = posicion.x - 8;
		break;

	case 's':
		//este caso es el de movimiento 1 casilla hacia delante
		if(posicion.x > -14)
		posicion.x = posicion.x - 4;
		break;

	case 'd':
		//este caso es el de movimiento diagonal izquierda
		if (posicion.x > -14 && posicion.z >= -14 && posicion.z < 14) {
			posicion.x = posicion.x - 4;
			posicion.z = posicion.z + 4;
		}
		break;
	
	case 'f':
		//este caso es el de movimiento diagonal derecha
		if (posicion.x > -14 && posicion.z > -14 && posicion.z <=14) {
			posicion.x = posicion.x - 4;
			posicion.z = posicion.z - 4;
		}
		break;

	}
}
