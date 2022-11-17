#pragma once
#include "Librerias.h"

class Reclamo
{
public:

	Reclamo();

	void registrarReclamo(string titulo, string descripcion);

	//DateTime obtenerFecha();
	string obtenerTitulo();
	string obtenerDescripcion();

private:
	//DateTime fecha;
	string titulo;
	string descripcion;

};



