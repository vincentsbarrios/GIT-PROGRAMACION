#include <conio.h>
#include "Notas.h"
#include <iostream>

using namespace std;

int main() {

	cout << "* M E N U  P R I N C I P A L *" << endl;
	int opp = 0;

	do {
		cout << "\n1. Registrar Alumno" << endl;
		cout << "2. Registrar Materia" << endl;
		cout << "3. Registrar Notas" << endl;
		cout << "4. Consultar Alumnos" << endl;
		cout << "5. Consultar Materias" << endl;
		cout << "6. Consultar Notas" << endl;
		cout << "7. Promedio de Alumno" << endl;
		cout << "8. Promedio de Materias" << endl;
		cout << "9. Salir" << endl;
		cout << "------> ";
		cin >> opp;

		switch (opp) {
		case 1:
			Notas::registrarAlumnos();
			break;
		case 2:
			Notas::registrarMaterias();
			break;
		case 3:
			Notas::registrarNotas();
			break;
		case 4:
			Notas::consultarAlumnos();
			break;
		case 5:
			Notas::consultarMateria();
			break;
		case 6:
			Notas::consultarNota();
			break;
		case 7:
			Notas::promedioAlumno();
			break;
		case 8:
			Notas::promedioMateria();
			break;
		}

	} while (opp != 9);
	

	return 0;
}