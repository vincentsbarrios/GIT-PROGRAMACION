#include "UtilidadesListaEnlazada.h"
#include <conio.h>
#include <stdlib.h >
#include <iostream>

using namespace std;

int main() {
	int y;

	//EN CREAR LISTA AUTOMATICAMENTE YA SE ORDENA

	do {
		cout << "Ingrese cantidad nodos: ";
		int x;
		cin >> x;
		UTILIDADLISTAENLAZADA::crearLista(x);
		cout << "Desea ingresar otro: ";
		cin >> y;
	} while (y != -1);

	_getch();
	return 0;
}