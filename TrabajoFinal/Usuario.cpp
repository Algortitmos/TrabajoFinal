#include "Usuario.h"

Usuario::Usuario(int _dni, string _name, int cantDolar, int cantSole) {
	dni = _dni;
	fullname = _name;
}

void Usuario::setNombre(string na) { fullname = na; }
void Usuario::setDni(int dn) { dni = dn; }


int Usuario::getDni() { return dni; }
string Usuario::getnombre() { return fullname; }