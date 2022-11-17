#pragma once
#include "Librerias.h"
#include "Lista.h"
#include "Transacciones.h"

class Usuario {

	string fullname;
	string correo;
	int dni;


public:

	Usuario(int _dni, string _name, int cantDolar, int cantSoles);

	void setNombre(string na);
	void setDni(int dn);


	int getDni();
	string getnombre();

};