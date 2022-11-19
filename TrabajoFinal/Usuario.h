#pragma once

#include "Lista.h"
#include "Transacciones.h"
#include "Vector.h"

class Usuario {

	int dni;
	string fullname;
	string correo;
	long telefono;
	Transacciones<string> t;
	Vector<string>* vecDatos = new Vector<string>();

public:

	Usuario(int _dni, string _fullname,string _correo, long _cell);

	int getDni();
	string getFullname();
	string getCorreo();
	long getTelefono();

	void setDni(int dn);
	void setNombre(string na);
	void setCorreo(string mail);
	void setTelefono(long cell);

	void registrarUsuario();
	void mostrarDatosUsuario();
	void guardarDatos();

};