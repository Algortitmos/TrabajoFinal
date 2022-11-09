#pragma once

#include "Librerias.h"

template<typename dato>
class Transacciones {
	
	double cant;
	char tipo;
	
public:

	Transacciones(dato cantidad, int t) {
		cant = cantidad;
		tipo = t;
	}

};