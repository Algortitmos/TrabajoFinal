#pragma once

#include "Reclamo.h"

void Reclamo::registrarReclamo(string _titulo, string _descricion)
{
	//this->fecha = fecha;
	titulo = _titulo;
	descripcion = _descricion;
}

//DateTime Reclamo::obtenerFecha(){
//	return fecha;
//}

string Reclamo::obtenerTitulo(){
	return titulo;
}

string Reclamo::obtenerDescripcion(){
	return descripcion;
}
