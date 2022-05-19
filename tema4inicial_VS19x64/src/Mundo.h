#include "Tablero.h"
class Mundo
{
public: 

	Tablero tablero;

	void tecla(unsigned char key);
	void inicializa();
	void mueve();
	void dibuja();

	float x_ojo;
	float y_ojo;
	float z_ojo;
};
