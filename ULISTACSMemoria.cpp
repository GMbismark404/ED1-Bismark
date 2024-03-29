//---------------------------------------------------------------------------

#pragma hdrstop

#include "ULISTACSMemoria.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)

direccion ListaS::fin() {
		direccion ptrfin = NULO;
		for (direccion x = PtrElementos; x != NULO; x = mem->obtener_dato(x, "sig")) {
			ptrfin = x;
		}
		return ptrfin;
}

direccion ListaS::primero() {
	if (vacia()) {
		return NULO;
	} else {
		return PtrElementos;
	}
}

direccion ListaS::siguiente(direccion p) {
	if (vacia())
		throw out_of_range("La lista est� vac�a");

	if (p == fin()) {
		throw logic_error("La direcci�n es incorrecta");
	} else {
		return mem->obtener_dato(p, "sig");
	}
}

direccion ListaS::anterior(direccion p) {
	if (vacia()) {
		throw out_of_range("La lista est� vac�a");
	} else if (p == primero()) {
		return PtrElementos;
	} else {
		direccion ant = NULO;
		for (direccion x = PtrElementos; x != NULO; x = mem->obtener_dato(x, "sig")) {
			if (x == p) {
				return ant;
			} else {
				ant = x;
			}
		}
	}
    return NULO;
}

TipoElemento ListaS::recupera(direccion p) {
	if (vacia()) {
		throw out_of_range("La lista est� vac�a");
	} else {
		return mem->obtener_dato(p, "elemento");
	}
}

void ListaS::inserta(direccion p, TipoElemento elemento) {
	direccion x = mem->new_espacio("elemento,sig");
	if (x != NULO) {
		mem->poner_dato(x, "elemento", elemento);
		mem->poner_dato(x, "sig", PtrElementos);
		if (vacia()) {
			PtrElementos = x; longitud = 1;
		} else {
			longitud = longitud + 1;
//			PtrElementos = x;
			if (p == primero()) {
				mem->poner_dato(x, "sig", p);
				PtrElementos = x;
			} else {
				direccion ant = anterior(p);
				mem->poner_dato(ant, "sig", x);
				mem->poner_dato(x, "sig", p);
			}
		}
	} else throw bad_alloc("Memoria llena, no es posible asignar memoria");
}

void ListaS::inserta_primero(TipoElemento elemento) {
	direccion x = mem->new_espacio("elemento,sig");
	if (x != NULO) {
		mem->poner_dato(x, "elemento", elemento);
		mem->poner_dato(x, "sig", PtrElementos);
		PtrElementos = x;
		longitud++;
	} else throw bad_alloc("Memoria llena, no es posible asignar memoria");
}

void ListaS::inserta_ulitmo(TipoElemento elemento) {
	direccion x = mem->new_espacio("elemento,sig");
	if (x != NULO) {
		mem->poner_dato(x, "elemento", elemento);
		mem->poner_dato(x, "sig", NULO);
		if (vacia()) {
			PtrElementos = x;
		} else {
			mem->poner_dato(fin(), "sig", x);
		}
		longitud++;
	} else throw bad_alloc("Memoria llena, no es posible asignar memoria");
}

void ListaS::suprime(direccion p) {
	if (vacia()) {
		throw out_of_range("La lista est� vac�a");
	} else if (p == PtrElementos) {
		direccion x = PtrElementos;
		PtrElementos = mem->obtener_dato(PtrElementos, "sig");
		mem->delete_espacio(x);
	} else {
		direccion ant = anterior(p);
		mem->poner_dato(ant, "sig", mem->obtener_dato(p, "sig"));
		mem->delete_espacio(p);
	}
	longitud--;
}

void ListaS::modifica(direccion p, TipoElemento elemento) {
	if (vacia()) {
		throw out_of_range("La lista est� vac�a");
	} else {
		mem->poner_dato(p, "elemento", elemento);
    }
}
