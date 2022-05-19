#include "Tablero.h"
#include "Pieza.h"
#include "Torre.h"

class Mundo
{
public: 

	Mundo();

	Tablero tablero;
	Casilla casilla;
	Vector2D vect_casilla;
	Pieza pieza;
	Torre torre;
	

	void tecla(unsigned char key);
	void inicializa();
	void mueve();
	void dibuja();

	float x_ojo;
	float y_ojo;
	float z_ojo;
};
