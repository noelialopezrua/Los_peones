#pragma once
#include "Tablero.h"
#include <freeglut.h>

void Tablero::dibuja()
{

	//ESTE ES EL FONDO BLANCO
	glDisable(GL_LIGHTING);
	glColor3ub(255, 255, 255);
	glBegin(GL_POLYGON);
	glVertex3d(-16, -0.01, 16);
	glVertex3d(-16, -0.01, -16);
	glVertex3d(16, -0.01, -16);
	glVertex3d(16, -0.01, 16);
	glEnd();
	glEnable(GL_LIGHTING);

	//ESTE BUCLE DIBUJA CASILLAS PARES
	for (int i = 0; i < 32; i += 8) {
		for (int j = 0; j < 32; j += 8) {

			glDisable(GL_LIGHTING);
			glColor3ub(141, 73, 37);
			glBegin(GL_POLYGON);
			glVertex3d(-16 + i, 0, 16 - j);
			glVertex3d(-16 + i, 0, 12 - j);
			glVertex3d(-12 + i, 0, 12 - j);
			glVertex3d(-12 + i, 0, 16 - j);
			glEnd();
			glEnable(GL_LIGHTING);
		}
	}
	//ESTE ES EL BUCLE PARA LAS CASILLAS IMPARES
	for (int i = 4; i < 32; i += 8) {
		for (int j = 4; j < 32; j += 8) {

			glDisable(GL_LIGHTING);
			glColor3ub(141, 73, 37);
			glBegin(GL_POLYGON);
			glVertex3d(-16 + i, 0, 16 - j);
			glVertex3d(-16 + i, 0, 12 - j);
			glVertex3d(-12 + i, 0, 12 - j);
			glVertex3d(-12 + i, 0, 16 - j);
			glEnd();
			glEnable(GL_LIGHTING);
		}
	}

}
