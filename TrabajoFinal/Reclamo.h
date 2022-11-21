#pragma once
#include "Librerias.h"
#include "Cola.h"

class Reclamo
{
public:

	Reclamo() {}

	Reclamo(string t , string d) {
		titulo = t;
		descripcion = d;
	}

	void registrarReclamo(string titulo, string descripcion);

	//DateTime obtenerFecha();
	string obtenerTitulo();
	string obtenerDescripcion();

private:
	
	//DateTime fecha;
	string titulo;
	string descripcion;

};



