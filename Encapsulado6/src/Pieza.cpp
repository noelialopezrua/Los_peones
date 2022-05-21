#include "Pieza.h"
#include "freeglut.h"

Pieza::Pieza() {
	
	rojo = verde = azul = 255;
	radio = 1;
	fila = columna = 0;

}

//Pieza::Pieza(int j, unsigned char r, unsigned char v, unsigned char a, float rad, int f, int c)
//{
//	jugador = j;
//	rojo = r;
//	verde = v; 
//	azul = a;
//	radio = rad;
//	fila = f;
//	columna = c;
//}



void Pieza::dibuja()
{
	Vector2D posicion,pos;
	posicion.x = 0.5;
	posicion.y = 0.5;

	Vector2D matriz[8][8];

	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			matriz[j][i] = { posicion.x,posicion.y };
			//printf("[%d]columna %f [%d]fila %f \n", i,posicion.x,j,posicion.y);
			posicion.x++;

		}
		posicion.x = 0.5;
		posicion.y++;
	}

	pos = matriz[fila][columna];
	glColor3ub(rojo, verde, azul);
	glTranslatef(pos.x,pos.y,0);
	//glutSolidSphere(radio, 20, 20);
	glTranslatef(-pos.x, -pos.y, 0);
	
	glutPostRedisplay();

	if (jugador == 0) {
		rojo = verde = azul = 255;
	}
	else rojo = verde = azul = 0;
}

void Pieza::SetRadio(float r)
{
	radio = r;
}
void Pieza::SetSocorro(int s)
{
	socorro = s;
}
void Pieza::SetJugador(int j)
{
	jugador=j;
}
void Pieza::SetPos(int f, int c)
{
	fila=f;
	columna=c;
}
void Pieza::SetColor(float r, float v, float a)
{
	rojo = r;
	verde = v;
	azul = a;
}

void Pieza::SetFila(int f)
{
	fila = f;
}

void Pieza::SetColumna(int c)
{
	columna = c;
}

void Pieza::SetPos(Vector2D v)
{
	pos1.x = v.y;
	pos1.y = v.x;
}



int Pieza::GetFila()
{
	return fila;
}

int Pieza::GetColumna()
{
	return columna;
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
	v.y = fila;
	v.x = columna;
	return v;

}

