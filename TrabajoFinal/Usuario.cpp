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
		cout << " Bienvenido : " << getFullname() << endl << endl;
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
			/*arbolCompraUsuario->insertar(cant);*/
			/*arbolCompraUsuario->enOrden();*/

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

	cout << endl << endl << endl;
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

void Usuario::realizarReclamo() {

	cout << endl;
	string t1, t2;
	char s = NULL;

	ofstream archivo;
	string nombreArchivo = getFullname() + getDni() + ".txt";

	do
	{
		cout << "  Ingrese razon de reclamo: "; cin.ignore(); getline(cin, t1);
		cout << endl;
		cout << "  Escriba la descripcion de su reclamo: "; getline(cin, t2);

		Reclamo rec = Reclamo(t1, t1);
		colaReclamos.push(rec);

		archivo.open(nombreArchivo, ios::app);
		if (archivo.is_open())
		{
			archivo << colaReclamos.front().obtenerTitulo() << endl;
			archivo << colaReclamos.front().obtenerDescripcion() << endl;
			//colaReclamos.pop();
			cout << "  Grabacion exitosa" << endl << endl;
		}
		else
		{
			cout << " Hubo un error con la apertura del archivo o este no existe." << endl;
		}

		cout << "  Si desea ingresa otro reclamo presione r y si desea salir al presione s : "; cin >> s;
		cout << endl;
		
	} while (s!='s');

	archivo.close();

	cout << " Su cola de reclamos es  : " << endl ;

	colaReclamos.print([](Reclamo r) {     // FUNCION LAMBDA
		cout << endl << endl;
		cout << "  Titulo : " << r.obtenerTitulo() << endl;
		cout << "  Descripcion : " << r.obtenerDescripcion() << endl << endl;
		cout << "  -------------------------------------"<<endl;
	});


}



void Usuario::GuardarReclamo() {

	ofstream archivo;
	string nombreArchivo = getFullname() + getDni() + "RECLAMO.txt";

	archivo.open(nombreArchivo, ios::app);
	if (archivo.is_open())
	{
		archivo << colaReclamos.front().obtenerTitulo() << endl;
		archivo << colaReclamos.front().obtenerDescripcion() << endl;
		colaReclamos.pop();
		cout << "Reclamo ingresado satisfactoriamente" << endl;
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

void Usuario::guardarArbolCompra(float cant){
	
	fstream archivo;
	string nombreArchivo = "ArbolCompra" + getFullname() + getDni();
	string a;
	archivo.open(nombreArchivo, ios::out, ios::app);
	if (archivo.is_open())
	{
		archivo >> cant;
	}
	else
	{
		cout << "Hubo un error en la apertura del archivo."<<endl;
	}

}

void Usuario::cargarArbolCompra() {
	
	fstream archivo;
	string nombreArchivo = "ArbolCompra" + getFullname() + getDni();
	string texto;
	float a;

	arbolCompraUsuario = new Arbol<float>();
	archivo.open(nombreArchivo, ios::in);
	if (archivo.is_open())
	{
		while (archivo)
		{
			getline(archivo, texto);
			a = std::stof(texto);
			arbolCompraUsuario->insertar(a);
		}
		cout << "Lectura exitosa" << endl;
		archivo.close();
	}
	else
	{
		cout << "Hubo un error en la apertura del archivo." << endl;
	}


}


void Usuario::guardarArbolVenta(float cant) {
	fstream archivo;
	string nombreArchivo = "ArbolVenta" + getFullname() + getDni();
	string a;
	archivo.open(nombreArchivo, ios::out, ios::app);
	if (archivo.is_open())
	{
		archivo >> cant;

	}
	else
	{
		cout << "Hubo un error en la apertura del archivo." << endl;
	}
	archivo.close();
}


void Usuario::cargarArbolVenta() {

	fstream archivo;
	string nombreArchivo = "ArbolVenta" + getFullname() + getDni();
	string texto;
	float a;

	arbolCompraUsuario = new Arbol<float>();
	archivo.open(nombreArchivo, ios::in);
	if (archivo.is_open())
	{
		while (archivo)
		{
			getline(archivo, texto);
			a = std::stof(texto);
			arbolVentaUsuario->insertar(a);
		}	
	}
	else
	{
		cout << "Hubo un error en la apertura del archivo." << endl;
	}
	archivo.close();
}



