#include "Pieza.h"
#include "freeglut.h"

Pieza::Pieza() {
	jugador = 0;
	rojo = verde = azul = 255;
	radio = 0.4;
	fila = columna = 0;
}

Pieza::Pieza(int j, unsigned char r, unsigned char v, unsigned char a, float rad, int f, int c)
{
	jugador = j;
	rojo = r;
	verde = v; 
	azul = a;
	radio = rad;
	fila = f;
	columna = c;
}


void Pieza::dibuja()
{
	Vector2D coordenada;
	coordenada = tablero.getCoordenada(fila, columna);
	glColor3ub(rojo, verde, azul);
	glTranslatef(coordenada.x,coordenada.y,0);
	glutSolidSphere(radio, 20, 20);
	glTranslatef(-coordenada.x, -coordenada.y, 0);
	tablero.setOcupado(fila, columna, 1); //decirle al tablero que la casilla está ocupada.
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
