#include "Casilla.h"
#include "freeglut.h"
#include "Vector2D.h"

Casilla::Casilla()
{
	x = 0;
	y = 0;
	seleccionado = false;
}

void Casilla::dibuja(int fila, int columna)
{
	int paridad;
	posicion.x = columna + 0.5;
	posicion.y = fila + 0.5;

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
