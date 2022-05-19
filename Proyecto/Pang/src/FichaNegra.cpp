#include "ETSIDI.h"
#include "FichaNegra.h"
#include "glut.h"


FichaNegra::FichaNegra(int f, int c)
{
	posicion.x = (-c);
	posicion.y = (-f);
	estado = 0;

}
int FichaNegra::contador = 0;
void FichaNegra::dibujarFicha(void) {

		if ((estado == 0) || (estado == -1)) {
			glTranslatef((posicion.x), (posicion.y), 0);
			glutSolidCube(0.5);
			//Superior
			glEnable(GL_TEXTURE_2D);

			glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("bin/imagenes/MaderaNegra.png").id);

			glBegin(GL_POLYGON);
			glColor3f(200, 200, 200);

			glTexCoord2d(0, 1);		glVertex3f(0.255, 0.255, 0.255);// Inferior Izquierda
			glTexCoord2d(1, 1);		glVertex3f(-0.255, 0.255, 0.255);// Inferior Derecha
			glTexCoord2d(1, 0);		glVertex3f(-0.255, -0.255, 0.255);// Superior Derecha
			glTexCoord2d(0, 0);		glVertex3f(0.255, -0.255, 0.255);// Superior Izquierda

			glEnd();
			glDisable(GL_TEXTURE_2D);

			//Inferior
			glEnable(GL_TEXTURE_2D);

			glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("bin/imagenes/MaderaNegra.png").id);

			glBegin(GL_POLYGON);
			glColor3f(200, 200, 200);

			glTexCoord2d(0, 1);		glVertex3f(0.255, 0.255, 0.0);// Inferior Izquierda
			glTexCoord2d(1, 1);		glVertex3f(-0.255, 0.255, 0.0);// Inferior Derecha
			glTexCoord2d(1, 0);		glVertex3f(-0.255, -0.255, 0.0);// Superior Derecha
			glTexCoord2d(0, 0);		glVertex3f(0.255, -0.255, 0.0);// Superior Izquierda

			glEnd();
			glDisable(GL_TEXTURE_2D);

			//Frontal
			glEnable(GL_TEXTURE_2D);

			glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("bin/imagenes/MaderaNegra.png").id);

			glBegin(GL_POLYGON);
			glColor3f(200, 200, 200);


			glTexCoord2d(0, 1);		glVertex3f(0.255, 0.255, 0);// Inferior Izquierda
			glTexCoord2d(1, 1);		glVertex3f(-0.255, 0.255, 0);// Inferior Derecha
			glTexCoord2d(1, 0);		glVertex3f(-0.255, 0.255, 0.255);// Superior Derecha
			glTexCoord2d(0, 0);		glVertex3f(0.255, 0.255, 0.255);// Superior Izquierda

			glEnd();
			glDisable(GL_TEXTURE_2D);

			//Derecha
			glEnable(GL_TEXTURE_2D);

			glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("bin/imagenes/MaderaNegra.png").id);
			glBegin(GL_POLYGON);
			glColor3f(200, 200, 200);

			glTexCoord2d(0, 1);		glVertex3f(-0.255, 0.255, 0);// Inferior Izquierda
			glTexCoord2d(1, 1);		glVertex3f(-0.255, -0.255, 0);// Inferior Derecha
			glTexCoord2d(1, 0);		glVertex3f(-0.255, -0.255, 0.255);// Superior Derecha
			glTexCoord2d(0, 0);		glVertex3f(-0.255, 0.255, 0.255);// Superior Izquierda

			glEnd();
			glDisable(GL_TEXTURE_2D);

			//Izquierda
			glEnable(GL_TEXTURE_2D);

			glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("bin/imagenes/MaderaNegra.png").id);

			glBegin(GL_POLYGON);
			glColor3f(200, 200, 200);

			glTexCoord2d(0, 1);		glVertex3f(0.255, 0.255, 0);// Inferior Izquierda
			glTexCoord2d(1, 1);		glVertex3f(0.255, -0.255, 0);// Inferior Derecha
			glTexCoord2d(1, 0);		glVertex3f(0.255, -0.255, 0.255);// Superior Derecha
			glTexCoord2d(0, 0);		glVertex3f(0.255, 0.255, 0.255);// Superior Izquierda

			glEnd();
			glDisable(GL_TEXTURE_2D);

			//Trasera
			glEnable(GL_TEXTURE_2D);

			glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("bin/imagenes/MaderaNegra.png").id);

			glBegin(GL_POLYGON);
			glColor3f(200, 200, 200);

			glTexCoord2d(0, 1);		glVertex3f(0.255, -0.255, 0);// Inferior Izquierda
			glTexCoord2d(1, 1);		glVertex3f(-0.255, -0.255, 0);// Inferior Derecha
			glTexCoord2d(1, 0);		glVertex3f(-0.255, -0.255, 0.255);// Superior Derecha
			glTexCoord2d(0, 0);		glVertex3f(0.255, -0.255, 0.255);// Superior Izquierda

			glEnd();
			glDisable(GL_TEXTURE_2D);

			glTranslatef((-posicion.x), (-posicion.y), 0);
		}
		if (estado == 1) {
			glTranslatef((posicion.x), (posicion.y), 0);
			glutSolidCube(0.5);

			//Superior
			glEnable(GL_TEXTURE_2D);

			glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("bin/imagenes/MaderaNegra.png").id);

			glBegin(GL_POLYGON);
			glColor3f(200, 200, 200);

			glTexCoord2d(0, 1);		glVertex3f(0.255, 0.255, 0.255);// Inferior Izquierda
			glTexCoord2d(1, 1);		glVertex3f(-0.255, 0.255, 0.255);// Inferior Derecha
			glTexCoord2d(1, 0);		glVertex3f(-0.255, -0.255, 0.255);// Superior Derecha
			glTexCoord2d(0, 0);		glVertex3f(0.255, -0.255, 0.255);// Superior Izquierda

			glEnd();
			glDisable(GL_TEXTURE_2D);

			//Inferior
			glEnable(GL_TEXTURE_2D);

			glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("bin/imagenes/MaderaNegra.png").id);

			glBegin(GL_POLYGON);
			glColor3f(200, 200, 200);

			glTexCoord2d(0, 1);		glVertex3f(0.255, 0.255, 0.0);// Inferior Izquierda
			glTexCoord2d(1, 1);		glVertex3f(-0.255, 0.255, 0.0);// Inferior Derecha
			glTexCoord2d(1, 0);		glVertex3f(-0.255, -0.255, 0.0);// Superior Derecha
			glTexCoord2d(0, 0);		glVertex3f(0.255, -0.255, 0.0);// Superior Izquierda

			glEnd();
			glDisable(GL_TEXTURE_2D);

			//Frontal
			glEnable(GL_TEXTURE_2D);

			glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("bin/imagenes/MaderaNegra.png").id);

			glBegin(GL_POLYGON);
			glColor3f(200, 200, 200);


			glTexCoord2d(0, 1);		glVertex3f(0.255, 0.255, 0);// Inferior Izquierda
			glTexCoord2d(1, 1);		glVertex3f(-0.255, 0.255, 0);// Inferior Derecha
			glTexCoord2d(1, 0);		glVertex3f(-0.255, 0.255, 0.255);// Superior Derecha
			glTexCoord2d(0, 0);		glVertex3f(0.255, 0.255, 0.255);// Superior Izquierda

			glEnd();
			glDisable(GL_TEXTURE_2D);

			//Derecha
			glEnable(GL_TEXTURE_2D);

			glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("bin/imagenes/MaderaNegra.png").id);
			glBegin(GL_POLYGON);
			glColor3f(200, 200, 200);

			glTexCoord2d(0, 1);		glVertex3f(-0.255, 0.255, 0);// Inferior Izquierda
			glTexCoord2d(1, 1);		glVertex3f(-0.255, -0.255, 0);// Inferior Derecha
			glTexCoord2d(1, 0);		glVertex3f(-0.255, -0.255, 0.255);// Superior Derecha
			glTexCoord2d(0, 0);		glVertex3f(-0.255, 0.255, 0.255);// Superior Izquierda

			glEnd();
			glDisable(GL_TEXTURE_2D);

			//Izquierda
			glEnable(GL_TEXTURE_2D);

			glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("bin/imagenes/MaderaNegra.png").id);

			glBegin(GL_POLYGON);
			glColor3f(200, 200, 200);

			glTexCoord2d(0, 1);		glVertex3f(0.255, 0.255, 0);// Inferior Izquierda
			glTexCoord2d(1, 1);		glVertex3f(0.255, -0.255, 0);// Inferior Derecha
			glTexCoord2d(1, 0);		glVertex3f(0.255, -0.255, 0.255);// Superior Derecha
			glTexCoord2d(0, 0);		glVertex3f(0.255, 0.255, 0.255);// Superior Izquierda

			glEnd();
			glDisable(GL_TEXTURE_2D);

			//Trasera
			glEnable(GL_TEXTURE_2D);

			glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("bin/imagenes/MaderaNegra.png").id);

			glBegin(GL_POLYGON);
			glColor3f(200, 200, 200);


			glTexCoord2d(0, 1);		glVertex3f(0.255, -0.255, 0);// Inferior Izquierda
			glTexCoord2d(1, 1);		glVertex3f(-0.255, -0.255, 0);// Inferior Derecha
			glTexCoord2d(1, 0);		glVertex3f(-0.255, -0.255, 0.255);// Superior Derecha
			glTexCoord2d(0, 0);		glVertex3f(0.255, -0.255, 0.255);// Superior Izquierda

			glEnd();
			glDisable(GL_TEXTURE_2D);

			//Corona
			glEnable(GL_TEXTURE_2D);

			glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("bin/imagenes/Corona.png").id);

			glBegin(GL_POLYGON);
			glColor3f(200, 200, 200);

			glTexCoord2d(1, 0);		glVertex3f(0.255, 0.255, 0.256);// Inferior Izquierda
			glTexCoord2d(0, 0);		glVertex3f(-0.255, 0.255, 0.256);// Inferior Derecha
			glTexCoord2d(0, 1);		glVertex3f(-0.255, -0.255, 0.256);// Superior Derecha
			glTexCoord2d(1, 1);		glVertex3f(0.255, -0.255, 0.256);// Superior Izquierda

			glEnd();
			glDisable(GL_TEXTURE_2D);

			glTranslatef((-posicion.x), (-posicion.y), 0);
		}
}

FichaNegra::~FichaNegra()
{
}