//---------------------------------------------------------------------------

#pragma hdrstop

#include "UCSMemoria.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
CSMemoria::CSMemoria(){
	mem = new NodoM[MAX];
	for (int i = 0; i < MAX - 1; i++ ) {
		mem[i].link = i + 1;
	}
    mem[MAX - 1].link = NULO;
	libre = 0;
}

int CSMemoria::new_espacio(string cad) {
	int cant = numero_ids(cad);
	int dir = libre;
	int d = dir;
	for (int i = 0; i < cant - 1; i++) {
		mem[d].id = obtener_id(cad, i);
		d = mem[d].link;
	}
	libre = mem[d].link;
	mem[d].link = NULO;
	mem[d].id = obtener_id(cad, cant - 1);
return dir;
}

void CSMemoria::delete_espacio(direccion dir) {
	direccion x = dir;
	while (mem[x].link != NULO) {
		x = mem[x].link;
	}
	mem[x].link = libre;
	libre = dir;
}

void CSMemoria::poner_dato(direccion dir, string cadena_id, int valor) {
	for (direccion z = dir; z != NULO; z = mem[z].link) {
		if (mem[z].id == cadena_id)
			mem[z].dato = valor;
	}
}

int CSMemoria::obtener_dato(direccion dir, string cadena_id) {
	for (direccion z = dir; z != NULO; z = mem[z].link) {
		if (mem[z].id == cadena_id)
			return mem[z].dato;
	}
	return NULO;
}

int CSMemoria::espacio_disponible() {
int contador = 0;
	for (direccion x = libre; (x < MAX) && (x != NULO) ; x = mem[x].link) {
		contador++;
	}
return contador;
}

int CSMemoria::espacio_ocupado() {
	return MAX - espacio_disponible();
}

bool CSMemoria::dir_libre(direccion dir) {
	for (direccion x = libre; (x != NULO); x = mem[x].link) {
		if (x == dir)
            return true;
	}
	return false;
}
