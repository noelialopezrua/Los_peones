#include "Torre.h"

Torre::Torre() {
	//(0,0) (0,7) (7,0) (7,7)

	fila = columna = 2;
	radio = 0.4;
	rojo = verde = azul = 255;
}

bool Torre::mov_posible(Vector2D pos_init, Vector2D pos_final)
{

	return false;
}
