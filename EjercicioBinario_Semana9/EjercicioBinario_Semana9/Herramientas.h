
#ifndef HERRAMIENTA
#define HERRAMIENTA

struct Herramienta {
	int codigo;			//4
	char nombre[30];	//30
	int catidad;		//4
	float precio;		//8
						//44
};

void creararchivo();
int retornoBytes_SigEspacioVacio(int);
void agregar();
void modificar();
void eliminar();
void buscar();
void imprimirlista();

#endif // !HERRAMIENTA

