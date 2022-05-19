#include <iostream>
#include <vector>
#include "ETSIDI.h"
#include "glut.h"
#include "Tablero.h"
#include "Casilla.h"

//los callback, funciones que seran llamadas automaticamente por la glut
//cuando sucedan eventos
//NO HACE FALTA LLAMARLAS EXPLICITAMENTE
void OnDraw(void); //esta funcion sera llamada para dibujar
void OnTimer(int value); //esta funcion sera llamada cuando transcurra una temporizacion
void OnKeyboardDown(unsigned char key, int x, int y); //cuando se pulse una tecla	
Tablero tabler;
Casilla cas;

int main(int argc, char* argv[])
{
	//Sonido de fondo
	ETSIDI::playMusica("bin/sonidos/BSO.mp3");

	//Inicializar el gestor de ventanas GLUT
	//y crear la ventana
	glutInit(&argc, argv);
	glutInitWindowSize(1360, 1360);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutCreateWindow("ProyectoDamas");

	//habilitar luces y definir perspectiva
	glEnable(GL_LIGHT0);
	glEnable(GL_LIGHTING);
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_COLOR_MATERIAL);
	glMatrixMode(GL_PROJECTION);
	gluPerspective(40.0, 800 / 600.0f, 0.1, 150);

	//Blend omite un color ALPHA, no se modificarlo pero no hace falta, ya que omite el color TRANSPARENTE.
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

	//Registrar los callbacks
	glutDisplayFunc(OnDraw);
	glutTimerFunc(25, OnTimer, 0);//le decimos que dentro de 25ms llame 1 vez a la funcion OnTimer()
	glutKeyboardFunc(OnKeyboardDown);

	//pasarle el control a GLUT,que llamara a los callbacks
	glutMainLoop();

	return 0;
}

void OnDraw(void)
{
	//Borrado de la pantalla	
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	//Para definir el punto de vista
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	///////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	////La forma correcta de dibujar es todos los objetos opacos primero y por último los que tengan transparencia.////
	//Hay que dibujar las fichas antes que la mano. AHORA LA MANO SE DIBUJA EN EL METODO DIBUJAR FICHAS INICIALES!!!!//
	///////////////////////////////////////////////////////////////////////////////////////////////////////////////////

	tabler.dibujarTablero();
	tabler.marcarJugadaBot();
	tabler.dibujarFichasIniciales();
	tabler.dibujarCementerio();
	tabler.jugarBot();
	

	
	//no borrar esta linea ni poner nada despues
	glutSwapBuffers();
}
void OnKeyboardDown(unsigned char key, int x_t, int y_t)
{
	//poner aqui el código de teclado
	tabler.moverMano(key);
	//El Redisplay es la función que se encarga de redibujar todo, llamando al OnDraw.
	glutPostRedisplay();
}

void OnTimer(int value)
{
	//poner aqui el código de animacion
	//Las animaciones se realizan en Tablero.cpp
	tabler.Animacion();

	//no borrar estas lineas
	glutTimerFunc(25, OnTimer, 0);
	glutPostRedisplay();
}
