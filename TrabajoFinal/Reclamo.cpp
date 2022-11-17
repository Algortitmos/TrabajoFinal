#include "Reclamo.h"

Reclamo::Reclamo(){}

void Reclamo::registrarReclamo(/*DateTime fecha,*/ string _titulo, string _descricion)
{
	/*fecha = fecha;*/
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