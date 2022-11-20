#pragma once
#include "Librerias.h"
#include "Lista.h"
#include "Transacciones.h"
#include "Vector.h"
#include "Reclamo.h"

class Usuario {

	string dni;
	string fullname;
	string correo;
	string telefono;
	Transacciones<float> t;
	Cola<Reclamo> colaReclamos = Cola<Reclamo>();
	Vector<string>vecDatos = Vector<string>();

public:
	Usuario();
	Usuario(string _dni, string _fullname, string _correo, string _cell);

	string getDni();
	string getFullname();
	string getCorreo();
	string getTelefono();

	void setDni(string dn);
	void setNombre(string na);
	void setCorreo(string mail);
	void setTelefono(string cell);

	void guardarDatosUsuario();
	void mostrarDatosUsuario();
	void guardarDatos();

	void operacion();

	void realizarReclamo();
	void guardarReclamo();
	void cargarArchivoReclamo();
};