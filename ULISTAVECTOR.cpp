//---------------------------------------------------------------------------

#pragma hdrstop

#include "ULISTAVECTOR.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)

direccion ListaV::fin(){
	if (vacia()){
		throw out_of_range("La lista está vacía");
	} else {
		return 0;
	}
}

direccion ListaV::primero(){
	if (vacia())
		return 0;

	return longitud;
}

direccion ListaV::siguiente(direccion p){
	if (vacia())
		throw out_of_range("La lista está vacía");

	if (p == longitud)
		throw out_of_range("La dirección es incorrecta");

	return (p+1);
}

direccion ListaV::anterior(direccion p){
	if (vacia())
		throw out_of_range("La lista está vacía");

	if (p == 0)
		throw out_of_range("La dirección es incorrecta");

	return (p-1);
}

TipoElemento ListaV::recupera(direccion p){
    if (vacia())
		throw out_of_range("La lista está vacía");

	if (!(p>=0 && p<=longitud))
		throw out_of_range("La dirección es incorrecta");

	return elementos[p];
}

void ListaV::inserta(direccion p, TipoElemento elemento){
	if (longitud == MAX)
		throw out_of_range("La lista está llena");

	if (!(p>=0 && p<=longitud))
		throw out_of_range("La dirección es incorrecta");

	for (int i = longitud; i > p; i--)
		elementos[i] = elementos[i - 1];

	elementos[p] = elemento;
	longitud++;
}

void ListaV::inserta_primero(TipoElemento elemento){
	if (longitud == MAX)
		throw out_of_range("La lista está llena");

	for (int i = longitud; i > 0; i--)
		elementos[i] = elementos[i - 1];

	elementos[0] = elemento;
	longitud++;
}

void ListaV::inserta_ultimo(TipoElemento elemento){
	if (longitud == MAX)
		throw out_of_range("La lista está llena");

	elementos[longitud++] = elemento;
}

void ListaV::suprime(direccion p){
	if (vacia())
		throw out_of_range("La lista está vacía");

	if (!(p>=0 && p<longitud))
		throw out_of_range("La dirección es incorrecta");

	for (int i = p; i < longitud - 1; i++)
		elementos[i] = elementos[i + 1];

	longitud--;
}

void ListaV::modifica(direccion p,TipoElemento elemento){
    if (vacia())
		throw out_of_range("La lista está vacía");

	if (!(p>=0 && p<longitud))
		throw out_of_range("La dirección es incorrecta");

	elementos[p] = elemento;
}

direccion ListaV::buscar(TipoElemento elemento) {
	for (int i = fin(); i != NULO ; i--) {
		if (recupera(i) == elemento) {
			return i;
		}
	}
	return NULO;
}

