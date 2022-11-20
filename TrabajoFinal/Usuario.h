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
	
	Lista<Transacciones<float>> ListaTransacciones;

	string tipoTransaccion;
	float valortransaccion;

	Vector<string>vecDatos = Vector<string>();

public:

	int cantElemenList;
	Lista<Transacciones<float>> listaAux;

	Usuario();
	Usuario(int _dni, string _fullname,string _correo, long _cell);

	Lista<Transacciones<float>> getListTrasnXuser() { return listaAux; }

	int getDni();
	string getFullname();
	string getCorreo();
	long getTelefono();

	void setDni(int dn);
	void setNombre(string na);
	void setCorreo(string mail);
	void setTelefono(long cell);

	void mostrarListaTransacciones();

	void guardarDatosUsuario();
	void mostrarDatosUsuario(Lista<Transacciones<float>> l);
	void guardarDatos();
	void operacion();

};