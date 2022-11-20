#pragma once
#include "Librerias.h"
#include "Lista.h"
#include "Transacciones.h"
#include "Vector.h"

class Usuario {

	int dni;
	string fullname;
	string correo;
	long telefono;
	Transacciones<float> t;
	Lista<Transacciones<float>> ListaTransacciones;

	string tipoTransaccion;
	float valortransaccion;

	Vector<string>vecDatos = Vector<string>();

public:
	Usuario();
	Usuario(int _dni, string _fullname,string _correo, long _cell);

	int getDni();
	string getFullname();
	string getCorreo();
	long getTelefono();

	void setDni(int dn);
	void setNombre(string na);
	void setCorreo(string mail);
	void setTelefono(long cell);

	Transacciones<float> getTransaccion();

	void guardarDatosUsuario();
	void mostrarDatosUsuario();
	void guardarDatos();
	void operacion();

};