//---------------------------------------------------------------------------

#ifndef UCSMemoriaH
#define UCSMemoriaH
//---------------------------------------------------------------------------
#include "UDEFGENERAL.h"
using namespace std;

struct NodoM{
	int dato;
	string id;
	direccion link;
};

class CSMemoria {
private:
	NodoM* mem;
	direccion libre;
public:
	CSMemoria();
	direccion new_espacio(string cadena);
	void delete_espacio(direccion dir);
	void poner_dato(direccion dir, string cadena_id, int valor);
	int obtener_dato(direccion dir, string cadena_id);
	int espacio_disponible();
	int espacio_ocupado();
	bool dir_libre(direccion dir);
	int numero_ids(string cadena);
	string obtener_id(string cadena, int pos);
	void Mostrar();
	string add_space(string cad);
};

int CSMemoria::numero_ids(string id) { // "dia,mes,a�o"
int c = 0;
	if (id == ""){
		return c;
	}else{
		for (int i = 0; i < id.length() - 1; i++)
			if ((id[i] != ',') && (id[i+1] == ','))
				c++;

		if (id[id.length() - 1] != ',')
			c++;
	}
return c;
}

string CSMemoria::obtener_id(string cad, int pos) {  // "ca,na,ma"
int p = 0; string s = ""; int c = 0;

	while (cad[c] == ',')
		c++;

	for (int i = c; i < cad.length(); i++) {
		if (cad[i] == ',') {
			i++; p++;
		}

		if (p == pos) {
			s = s + cad[i];
		}
	}
return s;
}

void CSMemoria::Mostrar(){
cout << "+-------------------------------------------------------+" << endl;
cout << "|  DIRECCION  |    DATO     |     ID      |     LINK    |" << endl;
cout << "+-------------------------------------------------------+" << endl;
	for (int i = 0; i <= MAX - 1; i++) {
		cout << "|" << add_space(to_string(i)) << "|" << add_space(to_string(mem[i].dato))<< "|" << add_space(mem[i].id) << "|" << add_space(to_string(mem[i].link)) << "|"<< endl;
	}
cout << "+-------------------------------------------------------+" << endl;
cout << "libre -> "<< libre << endl;
cout << "espacios disponibles -> "<< espacio_disponible() << endl;
cout << "espacios ocupados -> "<< espacio_ocupado() << endl;
}

string CSMemoria::add_space(string cad){
string s = cad;
	for (int i = cad.length(); i <= 12; i++) {
		s = s + " ";
	}
return s;
}

#endif
