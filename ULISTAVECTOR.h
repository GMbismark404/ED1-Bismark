//---------------------------------------------------------------------------
#ifndef ULISTAVECTORH
#define ULISTAVECTORH
//---------------------------------------------------------------------------
#include "UDEFGENERAL.h"
using namespace std;

class ListaV {
private:
	TipoElemento elementos[MAX];
	int longitud;
public:
	ListaV() : longitud(0) {} // Constructor: Inicializa longitud con 0
	direccion fin();
	direccion primero();
	direccion siguiente(direccion p);
	direccion anterior(direccion p);
	bool vacia() { return (longitud == 0); }
	TipoElemento recupera(direccion p);
	int longitudListav() { return (longitud); }
	void inserta(direccion p, TipoElemento elemento);
	void inserta_primero(TipoElemento elemento);
	void inserta_ultimo(TipoElemento elemento);
	void suprime(direccion p);
	void modifica(direccion p,TipoElemento elemento);
	direccion buscar(TipoElemento elemento);
	void imprimirLista();
};

void ListaV::imprimirLista(){
	if (vacia()) {
		cout << "\nLa lista está vacía." << endl;
		return;
	}

	cout << "Elementos de la lista:" << endl;
	for (int i = 0; i < longitud; ++i) {
		cout << "[" << recupera(i) << "] ";
	}
	cout << "\nMaximo elementos -> " << MAX << endl;
	cout << "longitud -> " << longitud << endl;
	cout << "fin() -> " << fin() << endl;
	cout << "primero() -> " << primero() << endl;
}

#endif
