#include "Pieza.h"
#include "freeglut.h"

Pieza::Pieza() {
	jugador = 0;
	rojo = verde = azul = 255;
	radio = 0.4;
	fila = columna = 0;

}


void Pieza::dibuja()
{
	Vector2D coordenada;
	coordenada = tablero.getCoordenada(fila, columna);
	glColor3ub(rojo, verde, azul);
	glTranslatef(coordenada.x,coordenada.y,0);
	glutSolidSphere(radio, 20, 20);
	glTranslatef(-coordenada.x, -coordenada.y, 0);
}

void Pieza::SetRadio(float r)
{
	radio = r;
}
void Pieza::SetColor(float r, float v, float a)
{
	rojo = r;
	verde = v;
	azul = a;
}

float Pieza::GetRadio()
{
	return radio;
}
float Pieza::GetColor()
{
	return rojo, verde, azul;
}
float Pieza::GetPos()
{
	return pos_init.x, pos_init.y;
}
