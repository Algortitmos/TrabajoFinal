#include "Controller.h"
#include "Vector.h"

Controller::Controller() {};


void Controller::PantInicio()
{

	cout << "    																   " << endl;
	cout << "               	OOOOOOOOOO      OOOOOOOOOOO						   " << endl;
	cout << "               	O               O								   " << endl;
	cout << "               	O               O								   " << endl;
	cout << "               	O               OOOOOOOOOOO						   " << endl;
	cout << "               	O                         O						   " << endl;
	cout << "               	O                         O						   " << endl;
	cout << "               	OOOOOOOOOO      OOOOOOOOOOO						   " << endl;
	cout << "    																   " << endl;
	cout << "    																   " << endl;
	cout << "                 BIENVENIDO A CAMBIO SEGURO                           " << endl;
	cout << "    																   " << endl;
	cout << "        Tu mejor opcion para cambiar Dolares($) y Soles(/.S)          " << endl;
	cout << "    																   " << endl;
	cout << "    																   " << endl;

	menu();

	/*registrarUsuario();*/

}

void Controller::menu()
	{
	int opcion;
		/*Transacciones<double> *t = new Transacciones<double>();*/



		cout << " Bienvenido a Cambio seguro, Elija una opcion : "<< endl << endl;
		cout << " 1. Comprar o vender dolares" << endl;
		cout << " 2. Ver transacciones." << endl;
		cout << " 3. Registrar Usuario." << endl;
		cout << " 4. Listar Usuarios." << endl;
		cout << " 5. Registrar Reclamo." << endl;
		cout << " 6. Cargar datos de usuarios guardados." << endl;
		cout << " 7. Salir." << endl << endl;
		
		cout << " Ingrese una opcion : ";

		
		cin >> opcion;

		switch (opcion)
		{
		case 1:
			system("cls");
			
			system("pause");
			system("cls");
			PantInicio();
			menu();

		case 2:
			system("cls");
			cout << "Aqui estan las Transacciones"<<endl;
			
			system("pause");
			system("cls");
			PantInicio();
			menu();


		case 3:

			registroUsuario();
			//system("pause");
			system("pause");
			system("cls");
			PantInicio();
			menu();

		case 4:

			Console::Clear();
			cout << " -------------LISTA DE USUARIOS -------------";
			cout << endl << endl;
			mostrarListaUsuarios();
			system("pause");
			system("cls");
			PantInicio();
			menu();

		case 5:

			system("cls");
			registrarReclamo();
			system("pause");
			system("cls");
			PantInicio();
			menu();

		case 6:
			system("cls");
			cargarUsuarios();
			system("pause");
			system("cls");
			PantInicio();
			menu();
		case 7:
			exit(1);
			break;
	
		}

}





void Controller::registroUsuario() {

	Console::Clear();
	string dni;
	string nombre;
	string correo;
	string numero;

	cout << "  ---------------- REGISTRO DE USUARIO ----------------" << endl << endl;

	cout << "  Ingrese su nombre : "; cin.ignore(); getline(cin, nombre);
	cout << "  Ingrese su DNI : "; cin >> dni;
	cout << "  Ingrese su correo : "; cin >> correo;
	cout << "  Ingrese su telefono : "; cin >> numero;

	cout << endl;

	Usuario u = Usuario(dni, nombre, correo, numero);

	listaUsuarios.push_back(u);

	
	cant = u.cantElemenList;
	ListTemp = u.listaAux;

	system("pause");
	//u.getTransaccion().getResultado();
	u.guardarDatosUsuario();
	grabarUsuarios();
	//u.mostrarDatosUsuario();


}

void Controller::mostrarListaUsuarios() {
	listaUsuarios.mostrarLista([=](Usuario user) {
		cout << endl;
		//cout << " Nombre: " << us.getFullname() << endl;
		//cout << " DNI : " << us.getDni() << endl;
		//cout << " Correo : " << us.getCorreo() << endl;
		//cout << " Numero : " << us.getTelefono()<<endl << endl;

		user.mostrarDatosUsuario(ListTemp);

		//cout << "cant : " << cant;

		cout << " --------------------------------";
		cout << endl;



	});
}

void Controller::grabarUsuarios() {
	ofstream archivo;
	string nombreArchivo = "UsuariosRegistrados.txt";

	archivo.open(nombreArchivo, ios::app);
	if (archivo.is_open()) {
		
			//archivo << " Cliente : "<<i+1 << endl;
			archivo << listaUsuarios.fin->elemento.getFullname() << endl;
			archivo << listaUsuarios.fin->elemento.getDni() << endl;
			archivo << listaUsuarios.fin->elemento.getCorreo() << endl;
			archivo << listaUsuarios.fin->elemento.getTelefono() << endl;
			
		

		cout << "Grabacion exitosa" << endl;
	}
	else
	{
		cout << "Hubo un error con la apertura del archivo o este no existe.";
	}

	archivo.close();

	
}


void Controller::cargarUsuarios() {
	ifstream archivo;
	string nombreArchivo = "UsuariosRegistrados.txt";
	
	
	string d;
	string t;
	string c, f;

	
	archivo.open(nombreArchivo, ios::in);
	if (archivo.is_open())
	{
		listaUsuarios = Lista<Usuario>();	

		while (getline(archivo, f), 
		getline(archivo, d),
		getline(archivo, c),
		getline(archivo, t))
		{
			cout << f << endl;
			cout << d << endl;
			cout << c << endl;
			cout << t << endl;

			Usuario u(d, f, c, t);
			listaUsuarios.push_back(u);
		}
	
	}
	else
	{
		
		cout << "Hubo un error con la apertura del archivo o este no existe.";
	}
	cout << "Se cargaron los usuarios de forma exitosa." << endl;
}


void Controller::registrarReclamo() {
	string u;
	string d;
	int cont = 0;

	cout << "Ingrese su nombre: "; cin.ignore(); getline(cin, u);
	cout << "Ingrese su DNI: "; (cin >> d);

	for (int i = 0; i < listaUsuarios.cantidad; i++)
	{
		if (listaUsuarios.at(i).getFullname() == u && listaUsuarios.at(i).getDni() == d) {
			listaUsuarios.at(i).realizarReclamo();
		}
		else
		{
			cont++;
		}
	}

	if (cont == listaUsuarios.cantidad)
	{
		cout << "No se encontro el usuario." << endl;
	}
	
}


