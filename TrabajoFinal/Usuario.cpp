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
	
	vecDatos->PushFront(to_string(dni));
	vecDatos->PushFront(fullname);
	vecDatos->PushFront(correo);
	vecDatos->PushFront(to_string(telefono));

}

void Usuario::mostrarDatosUsuario() {
	vecDatos->Print([](string s) {cout << s << endl; });
}
	
void Usuario::guardarDatos() {

}


void Usuario::realizarOperacion() {
	int opcion;
	double cant;
	char s = NULL;

	cout << " El tipo de cambio del dia es: " << endl;
	cout << " Compra : " << d.obtenerValorcompra() << "  |  Venta : " << d.obtenerValorVenta() << endl << endl;


	do
	{
		cout << " Desea comprar o vender dolares? : " << endl << endl;
		cout << " 1.- Comprar" << endl;
		cout << " 2.- Vender" << endl << endl;
	
		cout << " Ingrese opcion : "; cin >> opcion;

		cout << endl;

		if (opcion == 1)
		{
			cout << " Ingrese la cantidad de dolares a comprar : "; cin >> cant;
			cout << endl << " Para comprar " << cant << "$ usted debe pagar : S/" << d.comprarDolares(cant);
			cout << endl << endl << endl;
			cout << " Presione 'm' para salir al menu principal o 'c' para continuar : "; cin >> s;
			cout << "------------------------------------------------------------------";
			cout << endl << endl << endl;
			guardarTransCompra(cant);
		}


		if (opcion == 2)
		{
			cout << " Ingrese la cantidad de dolares a vender : "; cin >> cant;
			cout << endl << " Por vender " << cant << "$ usted recibira: S/" << d.venderDolares(cant);
			cout << endl << endl << endl;
			cout << " Presione 'm' para salir al menu principal o 'c' para continuar : "; cin >> s;
			cout << "------------------------------------------------------------------";
			cout << endl << endl << endl;
			guardarTransVenta(cant);
		}

		system("cls");
	} while (s != 'm' );
}



void Usuario::guardarTransCompra(int n) {
	ofstream archivo;
	string nombreArchivo = "U" + getFullname() + to_string(getDni()) + ".txt";

	archivo.open(nombreArchivo, ios::out | ios::app);
	if (archivo.is_open()) {
		archivo << "==================================" << endl;
		archivo << "Compra de dolares: " << n << endl;
		archivo << "Cantidad de soles invertidos: " << d.comprarDolares(n)<<endl;
		archivo << "==================================" << endl << endl;
	}
	else
	{
		cout << "Hubo un error con la apertura del archivo o este no existe.";
	}

	archivo.close();
}


void Usuario::guardarTransVenta(int n) {
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


