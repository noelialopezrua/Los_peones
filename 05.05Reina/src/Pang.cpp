#include "Mundo.h"
#include "freeglut.h"
#include <stdio.h>




Mundo mundo;



//los callback, funciones que seran llamadas automaticamente por la glut
//cuando sucedan eventos
//NO HACE FALTA LLAMARLAS EXPLICITAMENTE
void OnDraw(void); //esta funcion sera llamada para dibujar
void OnTimer(int value); //esta funcion sera llamada cuando transcurra una temporizacion
void OnKeyboardDown(unsigned char key, int x, int y); //cuando se pulse una tecla	
void ControlMouse(int boton, int estado, int x, int y);

int main(int argc,char* argv[])
{
	

	//Inicializar el gestor de ventanas GLUT
	//y crear la ventana
	glutInit(&argc, argv);
	glutInitWindowSize(800,600);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutCreateWindow("MiJuego");

	//habilitar luces y definir perspectiva
	glEnable(GL_LIGHT0);
	glEnable(GL_LIGHTING);
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_COLOR_MATERIAL);	
	glMatrixMode(GL_PROJECTION);
	gluPerspective( 40.0, 800/600.0f, 0.1, 150);

	//esto lo hemos movido
	mundo.inicializa();

	//Registrar los callbacks
	glutDisplayFunc(OnDraw);
	glutTimerFunc(25,OnTimer,0);//le decimos que dentro de 25ms llame 1 vez a la funcion OnTimer()
	glutKeyboardFunc(OnKeyboardDown);
	glutMouseFunc(ControlMouse);

	
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
	
	mundo.dibuja();

	//no borrar esta linea ni poner nada despues
	glutSwapBuffers();
}
void OnKeyboardDown(unsigned char key, int x_t, int y_t)
{
	//poner aqui el código de teclado
	mundo.tecla(key);

	glutPostRedisplay();
}

void OnTimer(int value)
{
//poner aqui el código de animacion
	
	//printf("turururu %f %f \n\n", mundo.casilla.click1.x, mundo.casilla.click1.y);
	//mundo.mueve();
	//no borrar estas lineas
	glutTimerFunc(25,OnTimer,0);
	glutPostRedisplay();
}
void ControlMouse(int boton, int estado, int x, int y) {//
	if (boton == GLUT_RIGHT_BUTTON && estado == GLUT_UP) {
		mundo.casilla.click1 = mundo.casilla.clickcas(boton, estado, x, y);
		//ESTO FUNCIONA printf("turururu %f %f \n\n", mundo.casilla.click1.x, mundo.casilla.click1.y);
		//printf(" estamos ready %f   %f \n",mundo.casilla.fila1, mundo.casilla.columna1);;
		printf("turururu %f %f \n\n", mundo.casilla.click1.x, mundo.casilla.click1.y);
		mundo.mueve(mundo.casilla.click1);
	}
		glutPostRedisplay();
		
	}
