#pragma once
#include "Pieza.h"
#include "ETSIDI.h"
using ETSIDI::Sprite;


class Alfil :public Pieza {


	

public:
	int w;
	Sprite sprite{ "imagenes/alfilb.png" };
	Sprite sprite2{ "imagenes/alfiln.png" };
	Alfil();
	void dibuja();
	bool mov_posible();
	
};