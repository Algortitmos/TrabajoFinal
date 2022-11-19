#pragma once

#include "Librerias.h"
#include "Dolares.h"
#include "Usuario.h"
	

template<typename dato>
class Transacciones {

	dato dat;
	Dolares d;
	/*Vector<string>* trans = new Vector<string>();*/

public:

	Transacciones() {}

	//void realizarOperacion();
	//dato comprarDolares(dato d);
	//dato venderDolares(dato d);

	void realizarOperacion(Usuario u = Usuario());

	dato comprarDolares(dato cant);

	dato venderDolares(dato cant);

	void guardarTransVenta(int n, Usuario u);

	void guardarTransCompra(int n, Usuario u);

	void leerTransacciones();
};