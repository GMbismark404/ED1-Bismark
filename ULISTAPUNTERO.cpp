//---------------------------------------------------------------------------
#pragma hdrstop
#include "ULISTAPUNTERO.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)

Direccion ListaP::primero(){
	if (vacia)
		throw out_of_range("La lista est� vac�a");

	return PtrElementos;
}

Direccion ListaP::fin(){
	if (vacia) {
		throw out_of_range("La lista est� vac�a");
	} else {
		Direccion ptrfin = nullptr;
		for (Direccion x = PtrElementos; x != nullptr; x = x->sig) {
			ptrfin = x;
		}
	return ptrfin;
	}
}

void ListaP::inserta(Direccion p, TipoElemento elemento) {
	Direccion x = new Nodo;
	if (x == nullptr) {
		throw bad_alloc(); // Lanzar una excepci�n en caso de falla en la asignaci�n de memoria
	} else {
	// Si la asignaci�n de memoria fue exitosa, continuamos con la inserci�n del nodo
	x->elementos = elemento;
	x->sig = nullptr;
		if (vacia) {
			PtrElementos = x;
			longitud = 1;
		} else {
		longitud++;
			if (p == primero()) {
				x->sig = p;
				PtrElementos = x;
			} else {
				Direccion ant = anterior(p);
				ant->sig = x;
				x->sig = p;
			}
		}
	}
}

void ListaP::inserta_primero(TipoElemento elemento){
	Direccion x = new Nodo;
	if (x != nullptr) {
		x->elementos = elemento;
		x->sig = PtrElementos;
		longitud++;
		PtrElementos = x;
	}else{
		throw bad_alloc(); // Lanzar una excepci�n en caso de falla en la asignaci�n de memoria
    }
}

void ListaP::inserta_ultimo(TipoElemento elemento){
	Direccion x = new Nodo;
	if (x != nullptr) {
		x->elementos = elemento;
		x->sig = nullptr;
		if (longitud != 0) {
			fin()->sig = x;
		} else {
			PtrElementos = x;
		}
		longitud++;
	} else {
		throw bad_alloc(); // Lanzar una excepci�n en caso de falla en la asignaci�n de memoria
    }
}

Direccion ListaP::siguiente(Direccion p){
	if (vacia) {
		throw out_of_range("La lista est� vac�a");
	} else {
		if (p == fin()) {
			throw logic_error("La direcci�n es incorrecta");
		} else {
			return p->sig;
		}
	}
}

Direccion ListaP::anterior(Direccion p) {
    if (vacia()) {
        throw out_of_range("La lista est� vac�a");
    } else if (p == primero()) {
        throw logic_error("La direcci�n es incorrecta");
    } else {
        Direccion anterior = nullptr;
        Direccion actual = PtrElementos;

        while (actual != nullptr && actual != p) {
            anterior = actual;
            actual = actual->sig;
        }

        if (actual == nullptr) {
            throw logic_error("La direcci�n no se encuentra en la lista");
        } else {
            return anterior;
        }
    }
}


TipoElemento ListaP::recupera(Direccion p){
	if (vacia) {
		throw out_of_range("La lista est� vac�a");
	}else{
		return p->elementos;
	}
}

void ListaP::suprime(Direccion p) {
    if (longitud == 0 || p == nullptr) {
        throw out_of_range("La lista est� vac�a o la direcci�n es nula");
    } else {
        if (p == PtrElementos) {
            PtrElementos = p->sig;
        } else {
            Direccion actual = PtrElementos;
            while (actual != nullptr && actual->sig != p) {
                actual = actual->sig;
            }
            if (actual == nullptr) {
                throw out_of_range("La direcci�n no se encuentra en la lista");
            }
            actual->sig = p->sig;
        }
        delete p;
        longitud--;
    }
}

Direccion ListaP::buscar(TipoElemento elemento) {
	for (Direccion p = primero(); p != nullptr; p = siguiente(p)) {
		if (recupera(p) == elemento) {
			return p; // Retorna la direcci�n si se encuentra el elemento
        }
	}
    return nullptr; // Retorna nullptr si el elemento no se encuentra
}

void ListaP::mostrarLista() {
	for (Direccion p = primero(); p != nullptr; p = siguiente(p)) {
		cout << recupera(p) << " ";
	}
}
