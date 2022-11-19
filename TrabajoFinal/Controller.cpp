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
	
}

void Controller::menu()
	{
	int opcion;
		/*Transacciones<double> *t = new Transacciones<double>();*/

		cout << " Bienvenido a Cambio seguro, "; cout << endl;
		cout << " 1. Comprar o vender dolares \n 2. Ver transacciones. \n 3. Salir. \ningrese su opcion: ";
		cin >> opcion;
		switch (opcion)
		{
		case 1:
			system("cls");
			u.realizarOperacion();
			system("pause");
			system("cls");
			PantInicio();
			menu();

		case 2:
			system("cls");
			cout << "Aqui estan las Transacciones"<<endl;
			u.mostrarTransacciones();
			system("pause");
			system("cls");
			PantInicio();
			menu();


		case 3:
			exit(1);
			system("pause");
			

	
		}


	//case 3:

	//	system("pause");
	//	system("cls");
	//	PantInicio();
	//	//menu(u);


	}

void Controller::menuRegistrar() {
	string nombre;
	int dni;

	cout << "Ingrese su nombre completo: "; cin >> nombre;
	cout << "Ingrese su dni: "; cin >> dni;

}



