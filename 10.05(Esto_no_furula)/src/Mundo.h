#include "Tablero.h"
#include "Pieza.h"
#include "Torre.h"
#include "ListaPiezas.h"


class Mundo
{
public: 

	Mundo();
	//int turno = 0;
	Tablero tablero;
	Casilla casilla;
	Vector2D vect_casilla;
	Pieza pieza;
	Torre torre1,torre2,torre3,torre4;
	Rey rey;
	/*ListaPiezas torres;
	ListaPiezas alfiles;
	ListaPiezas caballos;
	ListaPiezas reyes;
	ListaPiezas reinas;*/
	ListaPiezas peones;
	
	

	void tecla(unsigned char key);
	void inicializa();
	void mueve(Vector2D,int);
	void dibuja();
	

	float x_ojo;
	float y_ojo;
	float z_ojo;
};
