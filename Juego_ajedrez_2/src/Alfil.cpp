#include "Vector2D.h"
#include <freeglut.h>
#include "Alfil.h"

void Alfil::setPosicion(float x, float z)
{
	posicion.x = x;
	posicion.z = z;
}

void Alfil::setColor(unsigned char r, unsigned char v, unsigned char a)
{
	rojo = r;
	verde = v;
	azul = a;
}

void Alfil::dibuja()
{
	glColor3ub(rojo, verde, azul);
	glTranslatef(posicion.x, 0, posicion.z);
	glutSolidSphere(radio, 20, 20);
	glTranslatef(-posicion.x, 0, -posicion.z);
}

void Alfil::mueve(unsigned char estado)
{
	//esto es siempre desde el punto de vista del peon mirando hacia el adversario


	switch (estado) {
	
	case 'q':
		//este caso es el de movimiento diagonal izquierda
		if (posicion.x > -14 && posicion.z >= -14 && posicion.z < 14) {
			posicion.x = posicion.x - 4;
			posicion.z = posicion.z + 4;
		}
		break;

	case 'w':
		//este caso es el de movimiento diagonal derecha
		if (posicion.x > -14 && posicion.z > -14 && posicion.z <= 14) {
			posicion.x = posicion.x - 4;
			posicion.z = posicion.z - 4;
		}
		break;

	case 'e':
		//este caso es el de movimiento diagonal derecha hacia atrás
		if (posicion.x < 14 && posicion.z > -14 ) {
			posicion.x = posicion.x + 4;
			posicion.z = posicion.z - 4;
		}
		break;

	case 'r':
		//este caso es el de movimiento diagonal izquierda hacia atrás
		if (posicion.x < 14  && posicion.z < 14) {
			posicion.x = posicion.x + 4;
			posicion.z = posicion.z + 4;
		}
		break;


	}

}
