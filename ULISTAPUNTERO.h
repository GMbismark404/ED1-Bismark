//---------------------------------------------------------------------------
#ifndef ULISTAPUNTEROH
#define ULISTAPUNTEROH
//---------------------------------------------------------------------------
#include "UDEFGENERAL.h"
using namespace std;

struct Nodo {
	TipoElemento elementos;
	Nodo *sig;
};

typedef Nodo* Direccion;

class ListaP {
private:
	Direccion PtrElementos;
	int longitud;

public:
	ListaP() : longitud(0),  PtrElementos(nullptr) {} // Constructor: Inicializa longitud con 0, PtrElementos con NULL
	Direccion fin();
	Direccion primero();
	Direccion siguiente(Direccion p);
	Direccion anterior(Direccion p);
	bool vacia() { return (longitud == 0) || (PtrElementos == nullptr); }
	TipoElemento recupera(Direccion p);
	int longitudListap() { return longitud; }
	void inserta(Direccion p, TipoElemento elemento);
	void inserta_primero(TipoElemento elemento);
	void inserta_ultimo(TipoElemento elemento);
	void suprime(Direccion p);
	void modifica(Direccion p, TipoElemento elemento);
	Direccion buscar(TipoElemento elemento);
    void mostrarLista();
};

#endif
