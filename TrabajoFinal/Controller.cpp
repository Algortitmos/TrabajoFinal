#include "Controller.h"

Controller::Controller() {};


void Controller::PantInicio()
{
	cout << "    																   " << endl;
	cout << "    																   " << endl;
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
	cout << "    																   " << endl;

	//Aqui le pones la lista de opciones, si desea iniciar sesion o desea registrarse




}


void Controller::registrarUsuario() {

	Console::Clear();
	string nombre;
	int dni;

	cout << "	-----------------  REGISTRRO   -----------------: "<<endl << endl;
	cout << "	Ingrese su nombre : "; cin >> nombre; cout << endl;
	cout << "	Ingrese su dni : "; cin >> dni;

	//Usuario u = Usuario()

	//menu();

}

void Controller::menu(Usuario& u)
{
	int opcion, cantSolCambiar, cantDolCambiar;
	Transacciones<double> t;

	cout << " Bienvenido a Cambio seguro, "; cout << u.getnombre() << endl;
	cout << " 1. Comprar o vender dolares \n 2. Ver transacciones. \n 3. Salir. \ningrese su opcion: ";
	cin >> opcion;
	switch (opcion)
	{
	case 1:
		system("cls");
		t.realizarOperacion();
		system("pause");
		system("cls");
		PantInicio();
		menu(u);

	case 2:
		system("cls");
		cout << "Aqui estan las Transacciones"<<endl;
		
		system("pause");
		system("cls");
		PantInicio();
		menu(u);


	case 3:

		system("pause");
		system("cls");
		PantInicio();
		menu(u);

	

	}



}

