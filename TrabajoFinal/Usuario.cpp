#include "Usuario.h"

Usuario::Usuario() {}

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
}

	archivo.close();
}


void Usuario::guardarTransVenta(double n) {
	ofstream archivo;
	string nombreArchivo = "U" + getFullname() + to_string(getDni()) + ".txt";

	archivo.open(nombreArchivo, ios::out | ios::app);
	if (archivo.is_open()) {
		archivo << "==================================" << endl;
		archivo << "Venta de dolares: " << n << endl;
		archivo << "Cantidad de soles obtenidos: " << d.venderDolares(n)<<endl;
		archivo << "==================================" << endl << endl;
	}
	else
	{
		cout << "Hubo un error con la apertura del archivo o este no existe.";
	}
	archivo.close();
}


void Usuario::mostrarTransacciones() {
	ifstream archivo;
	string texto;
	string nombreArchivo = "U" + getFullname() + to_string(getDni()) + ".txt";

	archivo.open(nombreArchivo, ios::out | ios::app);
	if (archivo.is_open())
	{
		while (!archivo.eof())
		{
			getline(archivo, texto);
			cout << texto << endl;
		}
	}
	else
	{
		cout<< "Hubo un error con la apertura del archivo o este no existe.";
	}
	archivo.close();
}


