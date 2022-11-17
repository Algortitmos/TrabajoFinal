#include "Reclamo.h"

Reclamo::Reclamo(){}

void Reclamo::registrarReclamo(string titulo, string descricion)
{
	//this->fecha = fecha;
	this->titulo = titulo;
	this->descripcion = descricion;
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