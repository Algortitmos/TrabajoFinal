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

string Usuario::getDni() { return dni; }
string Usuario::getFullname() { return fullname; }
string Usuario::getCorreo() { return correo; }
long Usuario::getTelefono() { return telefono; }

void Usuario::guardarDatosUsuario() {
	
	vecDatos.PushFront(to_string(telefono));
	vecDatos.PushFront(correo);
	vecDatos.PushFront(to_string(dni));
	vecDatos.PushFront(fullname);
}

void Usuario::mostrarDatosUsuario(Lista<Transacciones<float>> l) {

	//cout << "  Sus datos son los siguientes : "<<endl << endl;
	/*vecDatos.Print([](string s) { cout <<"  " << s << endl; });*/


	cout << " Nombre: " << getFullname() << endl;
	cout << " DNI : " << getDni() << endl;
	cout << " Correo : " << getCorreo() << endl;
	cout << " Numero : " << getTelefono()<<endl << endl;

	cout << "      La lista de transacciones del Usuario : " << endl << endl;

	for (int i = 0; i < l.cantidad; i++)
	{
		//cout << "aqui aqui " << endl;

		cout << "      Tipo de operacion : " << l.at(i).getTipoOperacion() << endl;
		cout << "      Cantidad solicitada es : " << l.at(i).getCantidad() << endl;
		cout << "      Resultado de la transaccion : " << l.at(i).getResultado() << endl << endl;
		cout << "      --------------------------------"<<endl << endl;
	}
}

void Usuario::guardarDatos() {
	
}


void Usuario::operacion() {

	int opcion;
	string tipoOperacion;
	float cant;
	char s = NULL;

	do
	{
		cout << "  Desea comprar o vender dolares? : " << endl << endl;
		cout << " 1.- Comprar" << endl;
		cout << " 2.- Vender" << endl << endl;
		cout << " Ingrese opcion : "; cin >> opcion;

		cout << endl;

		if (opcion == 1)
		{
			Transacciones<float>t;
			tipoOperacion = "compra";
			cout << " Ingrese la cantidad de dolares a comprar : "; cin >> cant;
			cout << endl << " Para comprar " << cant << "$ usted debe pagar : S/" <<t.comprarDolares(cant);

			ListaTransacciones.push_back(t);
			arbolCompraDolares.insertar(cant);

			cout << endl << endl << endl;
			cout << " Presione 'm' para salir al menu principal o 'c' para continuar : "; cin >> s;
			cout << endl;
			cout << "-------------------------------------------------------";
			cout << endl << endl;

			
		}


		if (opcion == 2)
		{
			Transacciones<float>t;
			tipoOperacion = "venta";
			cout << " Ingrese la cantidad de dolares a vender : "; cin >> cant;
			cout << endl << " Por vender " << cant << "$ usted recibira: S/" << t.venderDolares(cant);

			ListaTransacciones.push_back(t);
			arbolVentaDolares.insertar(cant);

			cout << endl << endl << endl;
			cout << " Presione 'm' para salir al menu principal o 'c' para continuar : "; cin >> s;
			cout << endl;
			cout << "-------------------------------------------------------";
			cout << endl << endl;
		}

	} while (s != 'm');
	
	mostrarListaTransacciones();
	listaAux = ListaTransacciones;


	
}

void Usuario::mostrarListaTransacciones(){

	cout << "      La lista de transacciones del Usuario : " << endl << endl;
	//cout << " cant elemento en la lista : " << ListaTransacciones.cantidad << endl;

	cantElemenList = ListaTransacciones.cantidad;
	

	for (int i = 0; i < ListaTransacciones.cantidad; i++)
	{
		cout << endl;
		
		cout << "      Tipo de operacion : " << ListaTransacciones.at(i).getTipoOperacion() << endl;
		cout << "      Cantidad solicitada es : " << ListaTransacciones.at(i).getCantidad() << endl;
		cout << "      Resultado de la transaccion : " << ListaTransacciones.at(i).getResultado() << endl << endl;
		cout << "      --------------------------------";
	}



	//ListaTransacciones.mostrarLista([=](Transacciones<float> trans) {

	//	cout << endl;
	//	cout << " Dentro del lambda" << endl;
	//	cout << " Tipo de operacion : " << trans.getTipoOperacion() << " de dolares" << endl;
	//	cout << " Cantidad solicitada es : " << trans.getCantidad() << endl;
	//	cout << " Resultado de la transaccion : " << trans.getResultado() << endl << endl;
	//	cout << "--------------------------------" << endl;

	//});
}

void Usuario::mostrarReclamo() {
	cargarArchivoReclamo();
	

	while (!colaReclamos.isEmpty())
	{
		cout << "========================================" << endl;
		cout << "Titulo: " << colaReclamos.front().obtenerTitulo() << endl;
		cout << "Descripcion: " << colaReclamos.front().obtenerDescripcion() << endl;
		cout << "========================================" << endl;
		colaReclamos.pop();
	}
	cout << "Este es el fin de la lista" << endl;
}

void Usuario::guardarArbolCompra() {
	fstream archivo;
	string nombreArchivo = "ArbolCompra" + getFullname() + getDni();



}


void Usuario::guardarArbolVenta() {

}


void Usuario::cargarArbolCompra() {



}


void Usuario::cargarArbolVenta() {



}

