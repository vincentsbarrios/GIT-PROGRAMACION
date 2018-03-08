#include "Notas.h"
#include <fstream>
#include <iostream>
#include <stdlib.h>

using namespace std;

void Notas::registrarAlumnos()
{
	//MANERJAR ESCRITURAS DENTRO DEL ARCHIVO  -- Se va abrir al final del archivo
	ofstream archivoAlumnos("alumnos.dat", ios::app);

	if (!archivoAlumnos) {
		cout << "ERROR NO SE PUDO ABRIR EL ARCHIVO" << endl;
		return;
	}

	int cuenta, edad, cantidad;
	char nombre[50];

	cout << "\n\n *** I N G R E S O  D E  A L U M N O S ***\n\n";
	cout << "Cantidad de alumnos: ";
	cin >> cantidad;

	for (int x = 0; x < cantidad; x++) {
		cout << "\nCuenta: ";
		cin >> cuenta;
		cout << "Nombre: ";
		cin >> nombre;
		cout << "Edad: ";
		cin >> edad;

		archivoAlumnos << cuenta << " " << nombre << " " << edad << endl;
	}

	archivoAlumnos.close();

}

void Notas::consultarAlumnos()
{
	ifstream archivoAlumnosIN("alumnos.dat", ios::app);

	if (!archivoAlumnosIN) {
		cout << "ERROR NO SE PUDO ABRIR EL ARCHIVO" << endl;
		return;
	}

	int cuenta, edad;
	char nombre[50];

	cout << "\n\n*** C O N S U L T A  D E  A L U M N O S ***\n\n";
	while (archivoAlumnosIN >> cuenta >> nombre >> edad) {
		cout << cuenta << " " << nombre << " " << edad << endl;
	}

}

void Notas::registrarMaterias()
{
	ofstream archivoMateriasOut("materias.dat", ios::app);
	if (!archivoMateriasOut) {
		cout << "ERROR NO SE PUDO ABRIR EL ARCHIVO" << endl;
		return;
	}

	int cantidad, codigo;
	char nombre[30];

	cout << "\n\n *** I N G R E S O  D E  M A T E R I A S ***\n\n";
	cout << "Cantidad de materias: ";
	cin >> cantidad;

	for (int x = 0; x < cantidad; x++) {
		cout << "Ingrese codigo: ";
		cin >> codigo;
		cout << "Nombre de la materia: ";
		cin >> nombre;
		archivoMateriasOut << codigo << ' ' << nombre << "\n";
	}

	archivoMateriasOut.close();
}

void Notas::consultarMateria()
{
	ifstream archivoMateriasIn("materias.dat", ios::in);
	if (!archivoMateriasIn) {
		cout << "ERROR NO SE PUDO ABRIR EL ARCHIVO" << endl;
		return;
	}

	archivoMateriasIn.seekg(0, ios::beg);

	int codigo;
	char nombre[30];

	while (archivoMateriasIn >> codigo >> nombre) {
		cout << codigo << ' ' << nombre << "\n";
	}

	archivoMateriasIn.close();
}


int Notas::ObetnerCodigoAlumno(const char * nombreA)
{
	ifstream archivoAlumnos("alumnos.dat", ios::in);
	if (!archivoAlumnos) {
		cout << "ERROR NO SE PUDO ABRIR EL ARCHIVO" << endl;
		return -1;
	}

	archivoAlumnos.seekg(0, ios::beg);
	int codigo, edad;
	char nombre[50];

	while (archivoAlumnos >> codigo >> nombre >> edad) {
		if (strcmp(nombre, nombreA) == 0) {
			return codigo;
		}
		
	}return -1;

}

int Notas::ObtenerCodigoMateria(const char * nombreM)
{
	ifstream archivoMateria("materias.dat", ios::in);
	if (!archivoMateria) {
		cout << "ERROR NO SE PUDO ABRIR EL ARCHIVO" << endl;
		return -1;
	}

	
	archivoMateria.seekg(0, ios::beg);
	int codigo;
	char nombre[30];

	while (archivoMateria >> codigo >> nombre) {
		if (strcmp(nombre, nombreM) == 0) {
			return codigo;
		}
		
		
	}
	return -1;
}

char * Notas::obtenerNombreAlumno(const int codigoAlumno)
{
	ifstream archivoAlumnos("alumnos.dat", ios::in);
	if (!archivoAlumnos) {
		cout << "ERROR NO SE PUDO ABRIR EL ARCHIVO" << endl;
		return nullptr;
	}

	int codigo, edad;
	char nombre[50];

	archivoAlumnos.seekg(0, ios::beg);

	while (archivoAlumnos >> codigo >> nombre >> edad) {
		if (codigoAlumno == codigo) {
			char *retorno = new char[strlen(nombre)];
			strcpy(retorno,nombre);
			retorno[strlen(nombre)] = '\0';
			archivoAlumnos.close();
			return retorno;
		}
	}

	archivoAlumnos.close();
	return nullptr;
}

char * Notas::obtenerNombreMateria(const int codigoMateria)
{
	ifstream archivoMateria("materias.dat", ios::in);
	if (!archivoMateria) {
		cout << "ERROR NO SE PUDO ABRIR EL ARCHIVO" << endl;
		return nullptr;
	}

	int codigo;
	char nombre[30];

	archivoMateria.seekg(0, ios::beg);

	while (archivoMateria >> codigo >> nombre) {
		if (codigoMateria == codigo) {
			char *retorno = new char[strlen(nombre)];
			strcpy(retorno, nombre);
			retorno[strlen(nombre)] = '\0';
			archivoMateria.close();
			return retorno;
		}
	}

	archivoMateria.close();
	return nullptr;
}

void Notas::promedioAlumno()
{
	ifstream promedioNota("notas.dat", ios::in);

	if (!promedioNota) {
		cout << "ERROR NO SE PUDO ABRIR EL ARCHIVO";
		return;
	}
	promedioNota.seekg(0, ios::beg);
	char nombreA[50];
	int codigoM, codigoA, codigoAlumPromedio, nota, promedio, notaTotal=0, cantNota=0;

	cout << "\n\n * P R O M E D I O   D E L   A L U M N O *\n\n";

	cout << "\nNombre del alumno: ";
	cin >> nombreA;
	codigoAlumPromedio = ObetnerCodigoAlumno(nombreA);

	while (promedioNota >> codigoM >> codigoA >> nota) {
		if (codigoAlumPromedio == codigoA) {
			notaTotal = notaTotal + nota;
			cantNota++;
		}
	}
	promedio = notaTotal / cantNota;
	cout << "\nPromedio del alumno " << nombreA << " es " << promedio;


}

void Notas::promedioMateria()
{
	ifstream archivoMateriaP("notas.dat", ios::in);

	if (!archivoMateriaP) {
		cout << "ERROR NO SE PUDO ABRIR EL ARCHIVO" << endl;
		return;
	}

	archivoMateriaP.seekg(0, ios::beg);
	char nombreM[30];
	int codigoA, codigoM, nota, codigoMPromedio, notaSuma = 0, cantN = 0, promedio;

	cout << "\n\n *P R O M E D I O  D E  L A S  M A T E R I A S *\n\n";

	cout << "\nIngrese Materia: ";
	cin >> nombreM;

	codigoMPromedio = ObtenerCodigoMateria(nombreM);

	while (archivoMateriaP >> codigoM >> codigoA >> nota) {
		if (codigoMPromedio == codigoM) {
			notaSuma += nota;
			cantN++;
		}
	}

	promedio = notaSuma / cantN;
	cout << "\nPromedio total de la clase " << nombreM << " es " << promedio;
	
}


void Notas::registrarNotas()
{
	ofstream archivoNotasOut("notas.dat", ios::app);
	if (!archivoNotasOut) {
		cout << "ERROR NO SE PUDO ABRIR EL ARCHIVO" << endl;
		return;
	}

	cout << "\n\n *** C O N S U L T A   D E   M A T E R I A S ***\n\n";

	int opp = 0;

	do {
		char nombreM[30];
		char nombreA[50];
		int codigoM, codigoA, nota;

		//VERIFICAR QUE EXISTA LA MATERIA
		do {
			cout << "Ingrese Materia: ";
			cin >> nombreM;
			codigoM = ObtenerCodigoMateria(nombreM);

		} while (codigoM == -1);

		//VERIFICAR QUE EXISTA EL ALUMNO
		do {
			cout << "Ingrese Alumno: ";
			cin >> nombreA;
			codigoA = ObetnerCodigoAlumno(nombreA);

		} while (codigoA == -1);

		cout << "Ingrese nota: ";
		cin >> nota;

		archivoNotasOut << codigoM << ' ' << codigoA << ' ' << nota << "\n";


		cout << "\nDesea ingresar una nueva nota: ";
		cin >> opp;

	} while (opp != -1);

	archivoNotasOut.close();
}

void Notas::consultarNota()
{
	ifstream archivoNotas("notas.dat", ios::in);

	if (!archivoNotas) {
		cout << "ERROR NO SE PUDO ABRIR EL ARCHIVO" << endl;
		return;
	}

	cout << "\n\n *** C O N S U L T A   D E   N O T A S ***\n\n";

	int codigoM, codigoA, nota;

	archivoNotas.seekg(0, ios::beg);

	while (archivoNotas >> codigoM >> codigoA >> nota) {
		cout << obtenerNombreMateria(codigoM) << ' ' << obtenerNombreAlumno(codigoA) << ' ' << nota << "\n";
	}

	archivoNotas.close();
}

