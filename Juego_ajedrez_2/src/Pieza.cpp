#include "Pieza.h"
#include "freeglut.h"

void Pieza::setPosicion(float _x, float _z)
{
	//si queremos cambiar la coordenda z de la pieza ir a la función dibuja.
	posicion.x = _x;
	posicion.z = _z;
}

void Pieza::setColor(unsigned char r, unsigned char v, unsigned char a)
{
	rojo = r;
	verde = v;
	azul = a;
}
