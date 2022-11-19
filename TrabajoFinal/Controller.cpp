#include "Controller.h"

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



		cout << " Bienvenido a Cambio seguro, "; cout << endl;
		cout << " 1. Comprar o vender dolares \n 2. Ver transacciones. \n 3. Registrar Usuario. \n 4. Salir. \ningrese su opcion: ";
		cin >> opcion;

		switch (opcion)
		{
		case 1:
			system("cls");
			t->Transacciones<double>::realizarOperacion();
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
			system("pause");
			system("cls");
			PantInicio();
			menu();

		case 4:

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

	u.registrarUsuario();
	u.mostrarDatosUsuario();

}



