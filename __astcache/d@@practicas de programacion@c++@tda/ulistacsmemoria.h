//---------------------------------------------------------------------------
#ifndef ULISTACSMemoriaH
#define ULISTACSMemoriaH
#include "UCSMemoria.h"
//---------------------------------------------------------------------------

struct NodoCSMemoria{
	TipoElemento elemento;
	NodoCSMemoria *sig;
};

class ListaS {
private:
	direccion PtrElementos;
	int longitud;
	CSMemoria *mem;
public:
	ListaS() : longitud(0), PtrElementos(NULO), mem(new CSMemoria) {}
	direccion fin();
	direccion primero();
	direccion siguiente(direccion p);
	direccion anterior(direccion p);
	bool vacia() { return (longitud == 0) || (PtrElementos == NULO); }
	TipoElemento recupera(direccion p);
	int longitudListas() { return longitud; }
	void inserta(direccion p, TipoElemento elemento);
	void inserta_primero(TipoElemento elemento);
	void inserta_ulitmo(TipoElemento elemento);
	void suprime(direccion p);
	void modifica(direccion p, TipoElemento elemento);
    void mostrasLista() { mem->Mostrar(); }
};

#endif
