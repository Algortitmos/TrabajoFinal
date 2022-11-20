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
			cout << endl << " Para comprar " << cant << "$ usted debe pagar : S/" << t.comprarDolares(cant);

			ListaTransacciones.push_back(t);


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


void Usuario::guardarDatosUsuario() {

	vecDatos.PushFront(telefono);
	vecDatos.PushFront(correo);
	vecDatos.PushFront(dni);
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

void Usuario::realizar_GuardarReclamo() {
	string t1, t2;
	ofstream archivo;
	string nombreArchivo = getFullname() + getDni() + ".txt";

	cout << "Ingrese razon de reclamo: "; cin.ignore(); getline(cin, t1);
	cout << "Escriba la descripcion de su reclamo: "; getline(cin, t2);

	colaReclamos.push(Reclamo(t1, t2));

	archivo.open(nombreArchivo, ios::app);
	if (archivo.is_open())
	{
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
	string nombreArchivo = getFullname() + getDni() + ".txt";
	string t1, t2;
	archivo.open(nombreArchivo, ios::app);
	if (archivo.is_open())
	{
		colaReclamos = Cola<Reclamo>(); //Limpio la lista para evitar datos duplicados.

		while (!archivo.eof())
		{
			cout << " a";
			getline(archivo, t1);
			getline(archivo,t2);	
			colaReclamos.push(Reclamo(t1, t2));
		}
		cout << "carga exitosa." << endl;
	}
	else
	{
		cout << "Hubo un error con la apertura del archivo o este no existe." << endl;
	}
	archivo.close();

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



