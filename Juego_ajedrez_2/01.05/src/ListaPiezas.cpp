#include "ListaPiezas.h"

ListaPiezas::ListaPiezas() {

	//rellenar la lista de 0 para que no almacene basura.
	for (int i = 0; i < 4; i++)
	{
		listaTorres[i] = 0; 
		listaAlfiles[i] = 0;
	}
	nTorres = 0;
	nAlfiles = 0;
	
	
}

ListaPiezas::~ListaPiezas()
{
	for (int i = 0; i < 4; i++) {
		delete(listaTorres[i]);
		delete(listaAlfiles[i]);
	}

}




bool ListaPiezas::agregar(Torre* t)
{
	
	listaTorres[nTorres] = t;
	nTorres++;


	return true;
	
}

bool ListaPiezas::agregar(Alfil* a)
{

	listaAlfiles[nAlfiles] = a;
	nAlfiles++;


	return true;

}



void ListaPiezas::dibuja()
{
	/// Dibuja torres.
	for (int i = 0; i < 4; i++)
	{
		listaTorres[i]->Torre::dibuja();
	}

	for (int i = 0; i < 4; i++)
	{
		listaAlfiles[i]->Alfil::dibuja();
	}
}
