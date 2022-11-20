#pragma once

#include "Lista.h"
#include "Transacciones.h"
#include "Vector.h"
#include "Dolares.h"

class Usuario {

	int dni;
	string fullname;
	string correo;
	long telefono;
	Transacciones<float> t;

	Dolares d;

public:

	Usuario(int _dni = NULL, string _fullname = NULL,string _correo = NULL, long _cell = NULL);

	int getDni();
	string getFullname();
	string getCorreo();
	long getTelefono();

	void setDni(int dn);
	void setNombre(string na);
	void setCorreo(string mail);
	void setTelefono(long cell);

	void guardarDatosUsuario();
	void mostrarDatosUsuario();
	void mostrarTransacciones();
	void guardarDatos();
	void operacion();

	void realizarOperacion();
	void guardarTransVenta(double n);
	void guardarTransCompra(double n);
	


};