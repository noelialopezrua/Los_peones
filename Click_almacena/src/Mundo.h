#include "Tablero.h"
#include "Pieza.h"
#include "Torre.h"
#include "ListaPiezas.h"

class Mundo
{
public: 

	Mundo();

	Tablero tablero;
	Casilla casilla;
	Vector2D vect_casilla;
	Pieza pieza;
	ListaPiezas torres;
	ListaPiezas alfiles;
	ListaPiezas caballos;
	ListaPiezas reyes;
	ListaPiezas reinas;
	ListaPiezas peones;

	

	void tecla(unsigned char key);
	void inicializa();
	void mueve();
	void dibuja();

	float x_ojo;
	float y_ojo;
	float z_ojo;
};
