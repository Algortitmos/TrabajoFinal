#include "Usuario.h"

Usuario::Usuario() {}

Usuario::Usuario(string _dni, string _fullname, string _correo, string _cell) {
	dni = _dni;
	fullname = _fullname;
	correo = _correo;
	telefono = _cell;
	//Vector<string>vecDatos = Vector<string>();
}

void Usuario::setNombre(string na) { fullname = na; }
void Usuario::setDni(string dn) { dni = dn; }
void Usuario::setCorreo(string mail) {}
void Usuario::setTelefono(string cell) {}


string Usuario::getDni() { return dni; }
string Usuario::getFullname() { return fullname; }
string Usuario::getCorreo() { return correo; }
string Usuario::getTelefono() { return telefono; }

void Usuario::guardarDatosUsuario() {

	vecDatos.PushFront(telefono);
	vecDatos.PushFront(correo);
	vecDatos.PushFront(dni);
	vecDatos.PushFront(fullname);
}

void Usuario::mostrarDatosUsuario() {

	//cout << "  Sus datos son los siguientes : "<<endl << endl;
	/*vecDatos.Print([](string s) { cout <<"  " << s << endl; });*/
	cout << " Nombre: " << getFullname() << endl;
	cout << " DNI : " << getDni() << endl;
	cout << " Correo : " << getCorreo() << endl;
	cout << " Numero : " << getTelefono() << endl << endl;
}



void Usuario::operacion() {
	t.realizarOperacion();
}

void Usuario::realizarReclamo() {
	string t1, t2;
	ofstream archivo;
	string nombreArchivo = getFullname() + getDni() + ".txt";

	cout << "Ingrese razon de reclamo: "; cin.ignore(); getline(cin, t1);
	cout << "Escriba la descripcion de su reclamo: "; getline(cin, t2);
	
	colaReclamos.push(Reclamo(t1,t2));

	archivo.open(nombreArchivo, ios::app);
	if (archivo.is_open())
	{
		

			cout << colaReclamos.front().obtenerTitulo() << endl;
			cout << colaReclamos.front().obtenerDescripcion() << endl;

			
			archivo << colaReclamos.front().obtenerTitulo() << endl;
			
			archivo << colaReclamos.front().obtenerDescripcion() << endl;
			colaReclamos.pop();

		


		cout << "Grabacion exitosa" << endl;
	}
	else
	{
		cout << "Hubo un error con la apertura del archivo o este no existe." << endl;
	}

	archivo.close();

}



void Usuario::cargarArchivoReclamo() {
	ifstream archivo;
	string nombreArchivo = "//Algortitmos//TrabajoFinalReclamo// " + getFullname() + getDni() + ".txt";
	string t1, t2;
	archivo.open(nombreArchivo, ios::app);
	if (archivo.is_open())
	{
		while (!archivo.eof())
		{
			archivo >> t1;
			archivo >> t2;
			colaReclamos.push(Reclamo(t1, t2));
		}
	}
	else
	{
		cout << "Hubo un error con la apertura del archivo o este no existe." << endl;
	}

	archivo.close();

	cout << "Carga exitosa" << endl;

}
