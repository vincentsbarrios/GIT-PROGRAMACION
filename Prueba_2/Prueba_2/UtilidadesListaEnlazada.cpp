#include "UtilidadesListaEnlazada.h"
#include <iostream>
#include <stdlib.h>
#include <fstream>

using namespace std;

void UTILIDADLISTAENLAZADA::insertarFinal(nodo **inicio, int num)
{
	nodo *nuevo = new nodo();
	nuevo->valor = num;
	nuevo->sig = 0;
	nuevo->ant = 0;

	if (*inicio == NULL) {
		*inicio = nuevo;
	}
	else {
		nodo *actual = *inicio;
		nodo *anterior = NULL;

		while (actual != 0) {
			anterior = actual;
			actual = actual->sig;
		}
		anterior->sig = nuevo;
		nuevo->ant = anterior;
	}

}

nodo ** UTILIDADLISTAENLAZADA::crearLista(int cantNodo)
{
	nodo *lista = NULL;
	int count = 0;
	
	while(count < cantNodo) {
		//RANDOM
		int numrand = rand() % cantNodo + 1;
		insertarFinal(&lista,numrand);
		count++;
	}
	cout << "LISTA SIN ORDERNAR" << endl;
	UTILIDADLISTAENLAZADA::imprimirLista(&lista);
	UTILIDADLISTAENLAZADA::ordernarLista(&lista);
	cout << "\n\nLISTA ORDENADA" << endl;
	UTILIDADLISTAENLAZADA::imprimirLista(&lista);
	char nombre[30];
	UTILIDADLISTAENLAZADA::checkOrder(&lista);

	cout << "\nNombre archivo: ";
	cin >> nombre;

	UTILIDADLISTAENLAZADA::guardarLista(&lista, nombre);
	return &lista;
}

void UTILIDADLISTAENLAZADA::ordernarLista(nodo **lista)
{
	nodo *actual, *siguiente;
	//NUMERO VARIBALE TEMPORAL
	int t;
	actual = *lista;
	while (actual->sig != NULL) {
		siguiente = actual->sig;
		while (siguiente != NULL) {
			if (actual->valor > siguiente->valor) {
				t = siguiente->valor;
				siguiente->valor = actual->valor;
				actual->valor = t;

			}
			siguiente = siguiente->sig;
		}
		actual = actual->sig;
		siguiente = actual->sig;
	}

}

void UTILIDADLISTAENLAZADA::guardarLista(nodo **lista, char *nombre)
{

	ofstream archivoLista(nombre, ios::app);
	if (!archivoLista) {
		cout << "ERROR NO SE PUDO ABRIR EL ARCHIVO" << endl;
		return;
	}

	nodo* actual = new nodo();
	actual = *lista;
	if (lista != NULL) {
		while (actual != NULL) {
			archivoLista << actual->valor << " ";
			actual = actual->sig;
		}

	}
	cout << "Se han guardo al archivo exitosamente!" << endl;
	archivoLista.close();
}

void UTILIDADLISTAENLAZADA::imprimirLista(nodo **actual)
{
	if (*actual == 0) {
		return;
	}
	else {
		std::cout << (*actual)->valor << " ";
		imprimirLista(&(*actual)->sig);
	}
}

void UTILIDADLISTAENLAZADA::checkOrder(nodo **lista)
{
	nodo *nuevo = *lista;
	while (nuevo != 0) {
		if (nuevo->ant != NULL){
			cout << "Anterior: " << nuevo->ant->valor << " Actual: " << nuevo->valor;
		}
		else {
			cout << "\n\nNULL " << " Actual: " << nuevo->valor;
		}
		if (nuevo->sig != NULL) {
			cout << " Siguiente: " << nuevo->sig->valor << endl;
		}
		else {
			cout << " NULL" << endl;
		}
		nuevo = nuevo->sig;
	}

}
