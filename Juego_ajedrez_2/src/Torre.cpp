#include "Vector2D.h"
#include <freeglut.h>
#include "Torre.h"

void Torre::setPosicion(float x, float z)
{
	posicion.x = x;
	posicion.z = z;
}

void Torre::setColor(unsigned char r, unsigned char v, unsigned char a)
{
	rojo = r;
	verde = v;
	azul = a;
}

void Torre::dibuja()
{
	glColor3ub(rojo, verde, azul);
	glTranslatef(posicion.x, 0, posicion.z);
	glutSolidSphere(radio, 20, 20);
	glTranslatef(-posicion.x, 0, -posicion.z);
}

void Torre::mueve(unsigned char estado)
{
	//esto es siempre desde el punto de vista del peon mirando hacia el adversario

	switch (estado) {
	case 'z':
		//este caso es el de movimiento 1 casilla hacia atrás
		if (posicion.x < 14)
			posicion.x = posicion.x + 4;
		break;

	case 'x':
		//este caso es el de movimiento 1 casilla hacia delante
		if (posicion.x > -14)
			posicion.x = posicion.x - 4;
		break;

	case 'c':
		//este caso es el de movimiento 1 casilla hacia la derecha
		if (posicion.z > -14)
			posicion.z = posicion.z - 4;
		break;

	case 'v':
		//este caso es el de movimiento 1 casilla hacia la izquierda
		if (posicion.z < 14)
			posicion.z = posicion.z + 4;
		break;
	}

}
