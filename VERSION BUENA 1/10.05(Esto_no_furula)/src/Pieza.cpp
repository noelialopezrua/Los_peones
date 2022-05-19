#include "Pieza.h"
#include "freeglut.h"

Pieza::Pieza() {
	
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
	//tablero.setOcupado(fila, columna, 1); //decirle al tablero que la casilla está ocupada esto en cada pieza


	if (jugador == 0) {
		rojo = verde = azul = 255;
	}
	else rojo = verde = azul = 0;
}

void Pieza::SetRadio(float r)
{
	radio = r;
}
void Pieza::SetJugador(int j)
{
	j = jugador;
}
void Pieza::SetPos(int f, int c)
{
	f = fila;
	c = columna;
}
void Pieza::SetColor(float r, float v, float a)
{
	rojo = r;
	verde = v;
	azul = a;
}


Vector2D Pieza::getPos1()
{
	
	return pos1;
}

Vector2D Pieza::getPos2()
{
	
	return pos2;
}

float Pieza::GetRadio()
{
	return radio;
}
float Pieza::GetColor()
{
	return rojo, verde, azul;
}
Vector2D Pieza::GetPos()
{
	Vector2D v;
	v.x = fila;
	v.y = columna;
	return v;

}

Vector2D Pieza::GetPosi(Pieza p) {
	Vector2D v;
	v.x = p.fila;
	v.y = p.columna;
	return v;
}
