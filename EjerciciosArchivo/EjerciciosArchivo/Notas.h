#ifndef NOTAS_H
#define NOTAS_H

class Notas {
public:
	static void registrarAlumnos();
	static void consultarAlumnos();
	static void registrarMaterias();
	static void consultarMateria();
	static void registrarNotas();
	static void consultarNota();
	static int ObetnerCodigoAlumno(const char *);
	static int ObtenerCodigoMateria(const char *);
	static char * obtenerNombreAlumno(const int);
	static char * obtenerNombreMateria(const int);
	static void promedioAlumno();
	static void promedioMateria();

};

#endif
