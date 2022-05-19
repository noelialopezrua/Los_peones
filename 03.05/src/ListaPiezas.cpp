#include "ListaPiezas.h"

ListaPiezas::ListaPiezas() {

	//rellenar la lista de 0 para que no almacene basura.
	for (int i = 0; i < 4; i++)
	{
		listaTorres[i] = 0; 
		listaAlfiles[i] = 0;
		listaCaballos[i] = 0;
	}
	nTorres = 0;
	nAlfiles = 0;
	nCaballos = 0;

	for (int i = 0; i < 2; i++)
	{
		listaReyes[i] = 0;
		listaReinas[i] = 0;
	}
	nReyes = 0;
	nReinas = 0;
	
	for (int i = 0; i < 16; i++) {
		listaPeones[i] = 0;
	}
	nPeones=0;
	
}

ListaPiezas::~ListaPiezas()
{
	for (int i = 0; i < 4; i++) {
		delete(listaTorres[i]);
		delete(listaAlfiles[i]);
		delete(listaCaballos[i]);
	}
	for (int i = 0; i < 2; i++)
	{
		delete(listaReyes[i]);
		delete(listaReinas[i]);
	}
	for (int i = 0; i < 16; i++) {
		delete(listaPeones[i]);
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

bool ListaPiezas::agregar(Caballo* c)
{
	listaCaballos[nCaballos] = c;
	nCaballos++;
	return true;
}

bool ListaPiezas::agregar(Rey* rey)
{
	listaReyes[nReyes] = rey;
	nReyes++;
	return true;
}

bool ListaPiezas::agregar(Reina* r)
{
	listaReinas[nReinas] = r;
	nReinas++;
	return true;
}

bool ListaPiezas::agregar(Peon* p)
{
	listaPeones[nPeones] = p;
	nPeones++;
	return true;
}


void ListaPiezas::dibuja_t()
{
	/// Dibuja torres.
	for (int i = 0; i < 4; i++)
	{
		listaTorres[i]->Torre::dibuja();
	}
}

void ListaPiezas::dibuja_a()
{
	for (int i = 0; i < 4; i++)
	{
		listaAlfiles[i]->Alfil::dibuja();
	}
}

void ListaPiezas::dibuja_c()
{
	for (int i = 0; i < 4; i++)
	{
		listaCaballos[i]->Caballo::dibuja();
	}
}

void ListaPiezas::dibuja_rey()
{
	for (int i = 0; i < 2; i++)
	{
		listaReyes[i]->Rey::dibuja();
	}
}

void ListaPiezas::dibuja_r()
{
	for (int i = 0; i < 2; i++)
	{
		listaReinas[i]->Reina::dibuja();
	}
}

void ListaPiezas::dibuja_p()
{
	for (int i = 0; i < 16; i++)
	{
		listaPeones[i]->Peon::dibuja();
	}
}