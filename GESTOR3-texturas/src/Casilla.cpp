#include "Casilla.h"
#include "freeglut.h"
#include "Vector2D.h"
#include <stdio.h>

Casilla::Casilla()
{
	
	seleccionado = false;
	nClick = 0;

}

void Casilla::dibuja(int fila, int columna)
{
	int paridad;
	posicion.x = columna;
	posicion.y = fila;

	paridad = (fila + columna) % 2;

	if (paridad == 1)//BLANCO
	{
		glTranslatef((posicion.x), (posicion.y), -5);
		glBegin(GL_POLYGON);
		glColor3ub(255, 255, 255);

		glVertex3d(0.0f, 0.0f, 0.0f);
		glVertex3d(1.0f, 0.0f, 0.0f);
		glVertex3d(1.0f, 1.0f, 0.0f);
		glVertex3d(0.0f, 1.0f, 0.0f);

		glEnd();
		glTranslatef((-posicion.x), (-posicion.y), 5);
		
	}

	if (paridad == 0)//NEGRO
	{
		glTranslatef((posicion.x), (posicion.y), -5);
		glBegin(GL_POLYGON);
		glColor3ub(141, 73, 37);

		glVertex3d(0.0f, 0.0f, 0.0f);
		glVertex3d(1.0f, 0.0f, 0.0f);
		glVertex3d(1.0f, 1.0f, 0.0f);
		glVertex3d(0.0f, 1.0f, 0.0f);

		glEnd();
		glTranslatef((-posicion.x), (-posicion.y), 5);
	}
}

void Casilla::setCasilla()
{
	//La fila es cero cuando x es 0.5
	
}

Vector2D Casilla::clickcas(int boton, int estado, int x, int y)
{
	
	Vector2D clicky;
	int i = 186;
	int j = 84;
	float colum = 0;
	float fila = 7;
	float fila_aux, columna_aux;
	
	
	int a, b;
	

	
	//if (boton == GLUT_RIGHT_BUTTON && estado == GLUT_UP) {

		printf("%d   %d\n", x, y);
		

		for (fila = 7; fila >= 0; fila--)
		{
			if (y >= j && y <= j + 55) {
				clicky.x = fila;
				printf("fila %0.2f  ", clicky.x);
				fila_aux = clicky.x;
			}
			j += 55;
		}


		for (colum = 0; colum < 8; colum++)
		{
			if (x >= i && x <= i + 55) {
				clicky.y = colum;
				printf("columna %0.2f\n", clicky.y);
				columna_aux = clicky.y;

			}
			i += 55;
		}
		nClick++;
		printf("Numero de Clicks: %d\n", nClick);
	

		//printf("lololo %f %f \n",clicky.x, clicky.y);
		//click1 = clicky;


	//}
	
	//printf("HOLA % f % f \n", clicky.x, clicky.y);
	
	return clicky;
}


Vector2D Casilla::getCasilla()
{
	
	return posicion;
}

 Vector2D Casilla::getClick1()
{
	
	return click1;
}

