#include "Usuario.h"

Usuario::Usuario(int _dni, string _fullname, string _correo, long _cell) {
	dni = _dni;
	fullname = _fullname;
	correo = _correo;
	telefono = _cell;
}

void Usuario::setNombre(string na) { fullname = na; }
void Usuario::setDni(int dn) { dni = dn; }
void Usuario::setCorreo(string mail){}
void Usuario::setTelefono(long cell) {}


int Usuario::getDni() { return dni; }
string Usuario::getFullname() { return fullname; }
string Usuario::getCorreo() { return correo; }
long Usuario::getTelefono() { return telefono; }

void Usuario::registrarUsuario() {
	
	//vecDatos.PushFront(_dni.ToString());
	//vecDatos.PushFront()


}

void Usuario::guardarDatos() {

}
