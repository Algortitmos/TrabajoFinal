#pragma once
#include "Librerias.h"
#include "Lista.h"
#include "Transacciones.h"
#include "Vector.h"
#include "Reclamo.h"
#include "Arbol.h"
class Usuario {

	string dni;
	string fullname;
	string correo;
	string telefono;
	Lista<Transacciones<float>> ListaTransacciones = Lista<Transacciones<float>>();
	Cola<Reclamo> colaReclamos = Cola<Reclamo>();
	Vector<string>vecDatos = Vector<string>();

	Arbol<float> *arbolCompraUsuario = new Arbol<float>();
	Arbol<float> *arbolVentaUsuario = new Arbol<float>();
public:

	int cantElemenList;
	Lista<Transacciones<float>> listaAux;

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

	void mostrarListaTransacciones();

	void guardarDatosUsuario();
	void mostrarDatosUsuario(Lista<Transacciones<float>> l);
	

	void operacion();

	void realizarReclamo();
	void GuardarReclamo();
	void cargarArchivoReclamo();
	void mostrarReclamo();

	void guardarTrans();
	void cargarTrans();

	void guardarArbolCompra(float cant);
	void cargarArbolCompra();
	void guardarArbolVenta(float cant);
	void cargarArbolVenta();

};