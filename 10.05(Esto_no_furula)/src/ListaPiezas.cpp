#include "ListaPiezas.h"
#include <stdio.h>
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

void ListaPiezas::mueve(Vector2D v, int n)
{
	Vector2D retorno;
	Vector2D v1;
	v1 = v;
	if (turno == 0) {

		retorno = listaReinas[0]->Reina::mov_posible(v, n);
		//printf("POSIBLE %d\n\n", posible);
		if (retorno.x == 1) {
			if (retorno.y == 1) {
				v1=listaReinas[0]->Reina::GetPos();
			
				printf(" El vector elegido %f %f", v1.x, v1.y);
				ComerPieza(v1);
			}
		
			turno = 1;
		}
	}
		else if (turno == 1) {
			retorno = listaReinas[1]->Reina::mov_posible(v, n);
			if (retorno.x == 1)
				turno = 0;
		}
	
}

void ListaPiezas::ComerPieza(Vector2D v)
{
	printf("Quiero comer\n");
	printf("El vector que me estan pasando %f %f \n", v.x, v.y);
	int numero;
	Vector2D vectorcin;
	int tipo_pieza = tablero.ocupado[int(v.x)][int(v.y)];
	switch (tipo_pieza) {
	case 1:   //Tenemos un alfil recorremos el vector de alfiles para ver cual hemos seleccionado
		
		vectorcin.x = listaAlfiles[0]->fila;
			//vectorcin.y = listaAlfiles[3]->columna;
			if ((vectorcin.x ==int( v.x)) && (vectorcin.y==int(v.y))) {

				//numero = i;
				printf("Aqui estamoh  ");
			
				
			
		}
		//Tenemos que mover este alfil al cementerio
		//listaAlfiles[numero]->radio = 0;


		break;
	}

}

Vector2D ListaPiezas::getPos(Alfil* a)
{
	Vector2D v;
	v.x = a->fila;
	v.y = a->columna;
	return v;
}


