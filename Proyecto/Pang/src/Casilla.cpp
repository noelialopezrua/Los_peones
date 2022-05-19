#include "ETSIDI.h"
#include "Casilla.h"

Casilla::Casilla()
{
	fm = 5;
	cm = 5;
	seleccionada = false;

	posAnteriorBot.x = 20;
	posAnteriorBot.y = 20;

}

void Casilla::dibujarCasilla(int f, int c) {
	int color;
	posicion.x = (-c - 0.5);
	posicion.y = (-f - 0.5);

	color = (f + c) % 2;
	if (color == 0) //Negro
	{
		glTranslatef((posicion.x), (posicion.y), 0);
		glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("bin/imagenes/marmolnegro.png").id);

		glBegin(GL_POLYGON);
		glColor3f(200, 200, 200);

		glTexCoord2d(0, 1);	 glVertex3f(0.0f, 0.0f, 0.0f);
		glTexCoord2d(1, 1);	 glVertex3f(1.0f, 0.0f, 0.0f);
		glTexCoord2d(1, 0);	 glVertex3f(1.0f, 1.0f, 0.0f);
		glTexCoord2d(0, 0);	 glVertex3f(0.0f, 1.0f, 0.0f);

		glEnd();
		glDisable(GL_TEXTURE_2D);
		glTranslatef((-posicion.x), (-posicion.y), 0);
	}

	if (color == 1) //Blanco
	{
		glTranslatef((posicion.x), (posicion.y), 0);
		glEnable(GL_TEXTURE_2D);

		glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("bin/imagenes/marmol.png").id);

		glBegin(GL_POLYGON);
		glColor3f(200, 200, 200);

		glTexCoord2d(0, 1);	 glVertex3f(0.0f, 0.0f, 0.0f);
		glTexCoord2d(1, 1);	 glVertex3f(1.0f, 0.0f, 0.0f);
		glTexCoord2d(1, 0);	 glVertex3f(1.0f, 1.0f, 0.0f);
		glTexCoord2d(0, 0);	 glVertex3f(0.0f, 1.0f, 0.0f);

		glEnd();
		glDisable(GL_TEXTURE_2D);
		glTranslatef((-posicion.x), (-posicion.y), 0);
	}
}

void Casilla::dibujarManoBlanca(void) {
	//Aquí añadiremos el dibujo del puntero mano que queramos.
	glColor3ub(0, 200, 100);
	mano.x = (-cm - 0.5);
	mano.y = (-fm - 0.5);
	glTranslatef((mano.x), (mano.y), 0);
	glEnable(GL_TEXTURE_2D);

	//Modificar la ruta para cambiar el dibujo.
	if (seleccionada == true)
	{
		glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("bin/imagenes/Punito.png").id);

		glBegin(GL_POLYGON);
		glColor3f(300, 300, 300);

		glTexCoord2d(1, 0);	 glVertex3f(0.0f, 0.5f, 0.259f);
		glTexCoord2d(0, 0);	 glVertex3f(0.5f, 0.5f, 0.259f);
		glTexCoord2d(0, 1);	 glVertex3f(0.5f, 1.0f, 0.259f);
		glTexCoord2d(1, 1);	 glVertex3f(0.0f, 1.0f, 0.259f);

		glEnd();
		glDisable(GL_TEXTURE_2D);
		glTranslatef((-mano.x), (-mano.y), 0);
	}

	else
	{
		glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("bin/imagenes/Dedito.png").id);

		glBegin(GL_POLYGON);
		glColor3f(300, 300, 300);

		glTexCoord2d(1, 0);	 glVertex3f(0.0f, 0.5f, 0.259f);
		glTexCoord2d(0, 0);	 glVertex3f(0.5f, 0.5f, 0.259f);
		glTexCoord2d(0, 1);	 glVertex3f(0.5f, 1.0f, 0.259f);
		glTexCoord2d(1, 1);	 glVertex3f(0.0f, 1.0f, 0.259f);

		glEnd();
		glDisable(GL_TEXTURE_2D);
		glTranslatef((-mano.x), (-mano.y), 0);
	}
}

void Casilla::dibujarManoNegra(void) {
	//Aquí añadiremos el dibujo del puntero mano que queramos.
	glColor3ub(0, 200, 100);
	mano.x = (-cm - 0.5);
	mano.y = (-fm - 0.5);
	glTranslatef((mano.x), (mano.y), 0);
	glEnable(GL_TEXTURE_2D);

	//Modificar la ruta para cambiar el dibujo.
	if (seleccionada == true)
	{
		glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("bin/imagenes/Punito.png").id);

		glBegin(GL_POLYGON);
		glColor3f(300, 300, 300);

		glTexCoord2d(0, 1);	 glVertex3f(0.5f, 0.0f, 0.259f);
		glTexCoord2d(1, 1);	 glVertex3f(1.0f, 0.0f, 0.259f);
		glTexCoord2d(1, 0);	 glVertex3f(1.0f, 0.5f, 0.259f);
		glTexCoord2d(0, 0);	 glVertex3f(0.5f, 0.5f, 0.259f);

		glEnd();
		glDisable(GL_TEXTURE_2D);
		glTranslatef((-mano.x), (-mano.y), 0);
	}
	else
	{
		glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("bin/imagenes/Dedito.png").id);

		glBegin(GL_POLYGON);
		glColor3f(300, 300, 300);

		glTexCoord2d(0, 1);	 glVertex3f(0.5f, 0.0f, 0.259f);
		glTexCoord2d(1, 1);	 glVertex3f(1.0f, 0.0f, 0.259f);
		glTexCoord2d(1, 0);	 glVertex3f(1.0f, 0.5f, 0.259f);
		glTexCoord2d(0, 0);	 glVertex3f(0.5f, 0.5f, 0.259f);

		glEnd();
		glDisable(GL_TEXTURE_2D);
		glTranslatef((-mano.x), (-mano.y), 0);
	}
}

void Casilla::dibujarSeleccion(void) {
	Vector2D coordenadas;
	if (seleccionada == true) {
		glColor3ub(255, 255, 0);
		coordenadas.x = (-fichaSeleccionada.x - 0.5);
		coordenadas.y = (-fichaSeleccionada.y - 0.5);
	
		glTranslatef((coordenadas.x), (coordenadas.y), 0);

		glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("bin/imagenes/MarmolVerde.png").id);

		glBegin(GL_POLYGON);
		glColor3f(200, 200, 200);

		glTexCoord2d(0, 1);	 glVertex3f(0.0f, 0.0f, 0.01f);
		glTexCoord2d(1, 1);	 glVertex3f(1.0f, 0.0f, 0.01f);
		glTexCoord2d(1, 0);	 glVertex3f(1.0f, 1.0f, 0.01f);
		glTexCoord2d(0, 0);	 glVertex3f(0.0f, 1.0f, 0.01f);

		glEnd();
		glDisable(GL_TEXTURE_2D);
		glTranslatef((-coordenadas.x), (-coordenadas.y), 0);
	}
}

void Casilla::dibujarJugadaBot() {
	Vector2D coord;
	glColor3ub(255, 255, 0);
	coord.x = (-posAnteriorBot.x - 0.5);
	coord.y = (-posAnteriorBot.y - 0.5);

	glTranslatef((coord.x), (coord.y), 0);

	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("bin/imagenes/MarmolAzul.png").id);

	glBegin(GL_POLYGON);
	glColor3f(200, 200, 200);

	glTexCoord2d(0, 1);	 glVertex3f(0.0f, 0.0f, 0.01f);
	glTexCoord2d(1, 1);	 glVertex3f(1.0f, 0.0f, 0.01f);
	glTexCoord2d(1, 0);	 glVertex3f(1.0f, 1.0f, 0.01f);
	glTexCoord2d(0, 0);	 glVertex3f(0.0f, 1.0f, 0.01f);

	glEnd();
	glDisable(GL_TEXTURE_2D);
	glTranslatef((-coord.x), (-coord.y), 0);

}
Casilla::~Casilla()
{

}