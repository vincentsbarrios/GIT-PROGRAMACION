#ifndef UTILIDADLISTAENLAZADA_H
#define UTILIDADLISTAENLAZADA_H

typedef struct nodo {
	int valor;
	nodo *sig;
	nodo *ant;
} nodo;

class UTILIDADLISTAENLAZADA {
public:
	static void insertarFinal(nodo **, int);
	static nodo ** crearLista(int);
	static void ordernarLista(nodo **);
	static void guardarLista(nodo **, char *);

	static void imprimirLista(nodo **actual);
	static void checkOrder(nodo **);
};


#endif