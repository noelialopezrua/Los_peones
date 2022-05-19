#include "Tablero.h"
#include "Pieza.h"
#include "Torre.h"
#include "ListaPiezas.h"


class Mundo
{
public: 

	Mundo();
	int turno = 0;
	Tablero tablero;
	Casilla casilla;
	Vector2D vect_casilla;
	Pieza pieza;
	Torre torre1,torre2,torre3,torre4;
	Alfil alfil1, alfil2, alfil3, alfil4;
	Caballo caballo1, caballo2, caballo3, caballo4;
	Rey rey1, rey2;
	Reina reina1, reina2;
	ListaPiezas peones;
	
	

	void tecla(unsigned char key);
	void inicializa();
	void mueve(Vector2D,int);
	void dibuja();
	void comerPieza(Vector2D,int);
	

	float x_ojo;
	float y_ojo;
	float z_ojo;
};
