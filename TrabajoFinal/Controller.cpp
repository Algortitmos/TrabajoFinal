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
		int opcion, cantSolCambiar, cantDolCambiar;
		Transacciones<double> *t = new Transacciones<double>();



		cout << " Bienvenido a Cambio seguro, Elija una opcion : "<< endl << endl;
		cout << " 1. Comprar o vender dolares" << endl;
		cout << " 2. Ver transacciones." << endl;
		cout << " 3. Registrar Usuario." << endl;
		cout << " 4. Listar Usuarios." << endl;
		cout << " 5. Registrar Reclamo." << endl;
		cout << " 6. Salir." << endl << endl;
		cout << " Ingrese una opcion : ";

		
		cin >> opcion;

		switch (opcion)
		{
		case 1:
			system("cls");
			//t->Transacciones<double>::realizarOperacion();
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

			
			system("pause");
			system("cls");
			PantInicio();
			menu();

	
		}

}

void Controller::registroUsuario() {

	Console::Clear();
	int dni;
	string nombre;
	string correo;
	long numero;

	cout << "  ---------------- REGISTRO DE USUARIO ----------------" << endl << endl;

	cout << "  Ingrese su nombre : "; cin.ignore(); getline(cin, nombre);
	cout << "  Ingrese su DNI : "; cin >> dni;
	cout << "  Ingrese su correo : "; cin >> correo;
	cout << "  Ingrese su telefono : "; cin >> numero;

	cout << endl;

	Usuario u = Usuario(dni, nombre, correo, numero);

	listaUsuarios.push_back(u);

	u.operacion();

	cant = u.cantElemenList;
	ListTemp = u.listaAux;

	system("pause");
	//u.getTransaccion().getResultado();
	u.guardarDatosUsuario();
	grabarUsuarios(listaUsuarios);
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

void Controller::grabarUsuarios(Lista<Usuario> lista) {
	ofstream archivo;
	string nombreArchivo = "UsuariosRegistrados.txt";

	archivo.open(nombreArchivo, ios::out | ios::app);
	if (archivo.is_open()) {

		archivo << "--------------- LISTA DE USUARIOS ---------------" << endl << endl;

		int i;

		for (i = 0; i < lista.cantidad; i++)
		{
			
			cout << endl;
			//archivo << " Cliente : "<<i+1 << endl;
			archivo << " Nombre : " << lista.at(i).getFullname() << endl;
			archivo << " DNI : " << lista.at(i).getDni() << endl;
			archivo << " Correo : " << lista.at(i).getCorreo() << endl;
			archivo << " Telefono : " << lista.at(i).getTelefono() << endl << endl;
			archivo << "---------------------------------" << endl << endl;

			cout << "      La lista de transacciones del Usuario : " << endl << endl;

			for (int j=0; j < lista.at(i).listaAux.cantidad; j++)
			{
				//cout << "aqui aqui " << endl;

				archivo << "      Tipo de operacion : " << lista.at(i).listaAux.at(j).getTipoOperacion() << endl;
				archivo << "      Cantidad solicitada es : " << lista.at(i).listaAux.at(j).getCantidad() << endl;
				archivo << "      Resultado de la transaccion : " << lista.at(i).listaAux.at(j).getResultado() << endl << endl;
				archivo << "      --------------------------------" << endl << endl;
			}


		}

	}
	else
	{
		cout << "Hubo un error con la apertura del archivo o este no existe.";
	}

	archivo.close();

	cout << "Grabacion exitosa";
}


