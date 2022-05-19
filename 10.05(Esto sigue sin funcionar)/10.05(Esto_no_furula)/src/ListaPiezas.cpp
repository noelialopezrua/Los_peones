#include "ListaPiezas.h"
#include <stdio.h>


ListaPiezas::ListaPiezas() {

	
	for (int i = 0; i < 16; i++) {
		listaPeones[i] = 0;
	}
	nPeones=0;
	
}

ListaPiezas::~ListaPiezas()
{
	for (int i = 0; i < 16; i++) {
		delete(listaPeones[i]);
	}
}


bool ListaPiezas::agregar(Peon* p)
{
	listaPeones[nPeones] = p;
	nPeones++;
	return true;
}


void ListaPiezas::dibuja_p()
{
	for (int i = 0; i < 16; i++)
	{
		listaPeones[i]->Peon::dibuja();
	}
}

void ListaPiezas::mueve(Vector2D v, int n)
{
//	
}

//void ListaPiezas::ComerPieza(Vector2D v)
//{
//	
//
//}



