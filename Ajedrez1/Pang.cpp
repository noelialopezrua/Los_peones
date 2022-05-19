#include "freeglut.h"
#include <math.h>

//los callback, funciones que seran llamadas automaticamente por la glut
//cuando sucedan eventos
//NO HACE FALTA LLAMARLAS EXPLICITAMENTE
void OnDraw(void); //esta funcion sera llamada para dibujar
void OnTimer(int value); //esta funcion sera llamada cuando transcurra una temporizacion
void OnKeyboardDown(unsigned char key, int x, int y); //cuando se pulse una tecla	




  


int main(int argc,char* argv[])
{
	
	
	//Inicializar el gestor de ventanas GLUT
	//y crear la ventana
	glutInit(&argc, argv);
	glutInitWindowSize(800,600);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutCreateWindow("Ajedrez");  //Nombre de la ventana que saldra

	//habilitar luces y definir perspectiva
	glEnable(GL_LIGHT0);
	glEnable(GL_LIGHTING);
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_COLOR_MATERIAL);	
	glMatrixMode(GL_PROJECTION);
	gluPerspective( 40.0, 800/600.0f, 0.1, 150);
    
	
	

	//Registrar los callbacks   //Distintos eventos que pueden suceder.
	glutDisplayFunc(OnDraw);         //Llamamos a la funcion.
	glutTimerFunc(25,OnTimer,0);//le decimos que dentro de 25ms llame 1 vez a la funcion OnTimer()
	glutKeyboardFunc(OnKeyboardDown); //Cuando se pulse una tecla.
	
	
	gluLookAt(0, 20, 45,  // posicion del ojo  //ESTO SIRVE PARA CAMBIAR EL PUNTO DE VISTA
		0.0, 0, 0.0,      // hacia que punto mira  (0,0,0) 
		0.0, 1.0, 0.0);      // definimos hacia arriba (eje Y)*/


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
	//POSICION CAMARA
	
 
	
	//ESTE ES EL FONDO BLANCO
	glDisable(GL_LIGHTING);
	glColor3ub(255, 255, 255);
	glBegin(GL_POLYGON);
	glVertex3d(-16, -0.01, 16);
	glVertex3d(-16, -0.01, -16);
	glVertex3d(16, -0.01, -16);
	glVertex3d(16, -0.01 , 16);
	glEnd();
	glEnable(GL_LIGHTING);

	//ESTE BUCLE DIBUJA CASILLAS PARES
	for  (int i = 0;i < 32;i+=8) {
		for (int j = 0;j < 32;j += 8) {

			glDisable(GL_LIGHTING);
			glColor3ub(141,73, 37);
			glBegin(GL_POLYGON);
			glVertex3d(-16 + i, 0, 16-j);
			glVertex3d(-16 + i, 0, 12-j);
			glVertex3d(-12 + i, 0, 12-j);
			glVertex3d(-12 + i, 0, 16-j);
			glEnd();
			glEnable(GL_LIGHTING);
		}
	}
	//ESTE ES EL BUCLE PARA LAS CASILLAS IMPARES
	for (int i = 4;i < 32;i += 8) {
		for (int j = 4;j < 32;j += 8) {

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


	glutSwapBuffers();
}

void OnKeyboardDown(unsigned char key, int x_t, int y_t)
{
	
	
	glutPostRedisplay();
}

void OnTimer(int value)
{
	

	glutTimerFunc(25, OnTimer, 0);
	glutPostRedisplay();
}  

