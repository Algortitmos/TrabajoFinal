#include "Usuario.h"

Usuario::Usuario() {}

Usuario::Usuario(int _dni, string _fullname, string _correo, long _cell) {
	dni = _dni;
	fullname = _fullname;
	correo = _correo;
	telefono = _cell;
	//Vector<string>vecDatos = Vector<string>();
}

void Usuario::setNombre(string na) { fullname = na; }
void Usuario::setDni(int dn) { dni = dn; }
void Usuario::setCorreo(string mail){}
void Usuario::setTelefono(long cell) {}


int Usuario::getDni() { return dni; }
string Usuario::getFullname() { return fullname; }
string Usuario::getCorreo() { return correo; }
long Usuario::getTelefono() { return telefono; }

void Usuario::guardarDatosUsuario() {
	
	vecDatos.PushFront(to_string(telefono));
	vecDatos.PushFront(correo);
	vecDatos.PushFront(to_string(dni));
	vecDatos.PushFront(fullname);
}

void Usuario::mostrarDatosUsuario() {

	//cout << "  Sus datos son los siguientes : "<<endl << endl;
	/*vecDatos.Print([](string s) { cout <<"  " << s << endl; });*/
	cout << " Nombre: " << getFullname() << endl;
	cout << " DNI : " << getDni() << endl;
	cout << " Correo : " << getCorreo() << endl;
	cout << " Numero : " << getTelefono()<<endl << endl;
}

void Usuario::guardarDatos() {
	
}


void Usuario::operacion() {








	t.realizarOperacion();
	ListaTransacciones.push_back(t);

	cout << " La lista de transacciones es la sgte : "<<endl << endl;

	ListaTransacciones.mostrarLista([](Transacciones<float> trans) {
		
		cout << " Tipo de operacion : " << trans.getTipoOperacion() << " de dolares" << endl;
		cout << " Cantidad solicitada es : " << trans.getCantidad() << endl;
		cout << " Resultado de la transaccion : " << trans.getResultado() << endl << endl;
		cout << "--------------------------------";

	});
	
}

Transacciones<float> Usuario::getTransaccion() { return t; }

