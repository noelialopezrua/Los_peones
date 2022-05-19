#pragma once
#include "Vector2D.h"

class Jugada {
public:
	int idFicha;
	int idFichaComer=20;//indica la ficha que va a ser comida (si vale 20, ninguna)
	Vector2D posSig;
};