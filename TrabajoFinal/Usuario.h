#pragma once
#include "Librerias.h"
#include "Lista.h"
#include "Transacciones.h"
template<typename T>
class Usuario {

	string name;
	int dni;
	double cuentaDolares;
	double cuentaSoles;

public:



	Usuario(int _dni, string _name, int cantDolar, int cantSoles) {
		dni = _dni;
		name = _name;
		cuentaDolares = cantDolar;
		cuentaSoles = cantSoles;
	}

	void setNombre(string na);
	void setDni(int dn);

	void setCuentaDol(double dol);
	void setCuentaSol(double sol);

	int getDni();
	string getnombre();

	double getCuentaDol();
	double getCuentaSol();

	void mostrarCuentas() {
		cout << "Cuenta de dolares: " << cuentaDolares << endl;
		cout << "Cuenta de soles: " << cuentaSoles << endl;
	}

};

template <typename T>
void Usuario<T>::setNombre(string na) { name = na; }

template <typename T>
void Usuario<T>::setDni(int dn) { dni = dn; }

template <typename T>
int Usuario<T>::getDni() { return dni; }

template <typename T>
string Usuario<T>::getnombre() { return name; }

template <typename T>
double Usuario<T>::getCuentaDol() { return cuentaDolares; }

template <typename T>
double Usuario<T>::getCuentaSol() { return cuentaSoles; }

template <typename T>
void Usuario<T>::setCuentaDol(double dol) { cuentaDolares = dol; }

template <typename T>
void Usuario<T>::setCuentaSol(double sol) { cuentaSoles = sol; }