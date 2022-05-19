#include "ListaPiezas.h"

ListaPiezas::ListaPiezas() {

	//rellenar la lista de 0 para que no almacene basura.
	for (int i = 0; i < 4; i++)
	{
		listaTorres[i] = 0; 

	}
}




bool ListaPiezas::agregar(Torre* t)
{
	
	for (int i = 0; i <4; i++) // me permite no crear dos esferas iguales
		{
			if (listaTorres[i] == t)
				return false;
		}
		
		listaTorres[nTorres] = t;
		nTorres++;

	return true;
	
}

void ListaPiezas::dibuja()
{
	/// Dibuja torres.
	for (int i = 0; i < 4; i++)
	{
		listaTorres[i]->Torre::dibuja();
	}
}
