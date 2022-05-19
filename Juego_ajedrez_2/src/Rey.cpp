#include "Rey.h"
#include "Vector2D.h"
#include <freeglut.h>


void Rey::setPosicion(float x, float z)
{
	posicion.x = x;
	posicion.z = z;
}

void Rey::setColor(unsigned char r, unsigned char v, unsigned char a)
{
	rojo = r;
	verde = v;
	azul = a;
}

void Rey::dibuja()
{
	glColor3ub(rojo, verde, azul);
	glTranslatef(posicion.x, 0, posicion.z);
	glutSolidSphere(radio, 20, 20);
	glTranslatef(-posicion.x, 0, -posicion.z);
}

void Rey::mueve(unsigned char estado)
{
	switch (estado) {

	case '1':
		//este caso es el de movimiento diagonal izquierda
		if (posicion.x > -14 && posicion.z >= -14 && posicion.z < 14) {
			posicion.x = posicion.x - 4;
			posicion.z = posicion.z + 4;
		}
		break;

	case '2':
		//este caso es el de movimiento diagonal derecha
		if (posicion.x > -14 && posicion.z > -14 && posicion.z <= 14) {
			posicion.x = posicion.x - 4;
			posicion.z = posicion.z - 4;
		}
		break;

	case '3':
		//este caso es el de movimiento diagonal derecha hacia atrás
		if (posicion.x < 14 && posicion.z > -14) {
			posicion.x = posicion.x + 4;
			posicion.z = posicion.z - 4;
		}
		break;

	case '4':
		//este caso es el de movimiento diagonal izquierda hacia atrás
		if (posicion.x < 14 && posicion.z < 14) {
			posicion.x = posicion.x + 4;
			posicion.z = posicion.z + 4;
		}
		break;
	case '5':
		//este caso es el de movimiento 1 casilla hacia atrás
		if (posicion.x < 14)
			posicion.x = posicion.x + 4;
		break;

	case '6':
		//este caso es el de movimiento 1 casilla hacia delante
		if (posicion.x > -14)
			posicion.x = posicion.x - 4;
		break;

	case '7':
		//este caso es el de movimiento 1 casilla hacia la derecha
		if (posicion.z > -14)
			posicion.z = posicion.z - 4;
		break;

	case '8':
		//este caso es el de movimiento 1 casilla hacia la izquierda
		if (posicion.z < 14)
			posicion.z = posicion.z + 4;
		break;

	}
}
