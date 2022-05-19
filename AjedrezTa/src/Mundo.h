#include "Tablero.h"
class Mundo
{
public: 

	Tablero tablero;
	Casilla casilla;
	Vector2D vect_casilla;

	void tecla(unsigned char key);
	void inicializa();
	void mueve();
	void dibuja();

	float x_ojo;
	float y_ojo;
	float z_ojo;
};
