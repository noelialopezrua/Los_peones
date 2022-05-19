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
		glTranslatef((posicion.x), (posicion.y), 0);
		glBegin(GL_POLYGON);
		glColor3ub(255, 255, 255);

		glVertex3d(0.0f, 0.0f, 0.0f);
		glVertex3d(1.0f, 0.0f, 0.0f);
		glVertex3d(1.0f, 1.0f, 0.0f);
		glVertex3d(0.0f, 1.0f, 0.0f);

		glEnd();
		glTranslatef((-posicion.x), (-posicion.y), 0);
		
	}

	if (paridad == 0)//NEGRO
	{
		glTranslatef((posicion.x), (posicion.y), 0);
		glBegin(GL_POLYGON);
		glColor3ub(141, 73, 37);

		glVertex3d(0.0f, 0.0f, 0.0f);
		glVertex3d(1.0f, 0.0f, 0.0f);
		glVertex3d(1.0f, 1.0f, 0.0f);
		glVertex3d(0.0f, 1.0f, 0.0f);

		glEnd();
		glTranslatef((-posicion.x), (-posicion.y), 0);
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
	

	
	if (boton == GLUT_RIGHT_BUTTON && estado == GLUT_UP) {

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
		//printf("Fila y columna auxiliar: %0.2f %0.2f\n", fila_aux, columna_aux);
		/*
		fila2 = fila_alm;
		fila1 = fila_aux;
		fila_alm = fila1;
		printf("Fila1: %0.2f\n", fila1);
		printf("Fila2: %0.2f\n", fila2);
		*/
		
		if (nClick % 2 != 0) {//EMPIEZA EN 1
			fila1 = fila_aux;
			columna1 = columna_aux;
		}
		else {
			fila2 = fila_aux;
			columna2 = columna_aux;
		}
		if(nClick==1)
		printf("Primer click %f %f\n", fila1, columna1);
		if (nClick == 2)
		{ 
		printf("Segundo click %f %f\n", fila2, columna2);

		nClick = 0;
		}
	

	}
	/*
	int aux=0;    
	aux=nClick ;
	
	filas = clicky.y;
	columnas = clicky.x;
	if (nClick > aux) {
		fila1 = clicky.y;
		columna1 = clicky.x;
	}*/
	//nClick++;
	//printf("primer click: %f %f\n", filas, columnas);
	//printf("segundo click: %f %f\n", fila1, columna1);
	//nClick++;
	
	
	return clicky;
}


Vector2D Casilla::getCasilla()
{
	return posicion;
}
