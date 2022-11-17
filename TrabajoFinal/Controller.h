#pragma once
#include "Usuario.h"
//.
//template<typename dato>
class Controller {


public:

	Controller();

	void PantInicio();
	void registrarUsuario();
	void menu(Usuario<void>& u)
	{
		int opcion, cantSolCambiar, cantDolCambiar;

		cout << " Bienvenido a Cambio seguro, "; cout << u.getnombre() << endl;
		cout << " 1. Cambiar soles a dolares. \n 2. Cambiar dolares a soles.\n 3. Ver transacciones. \n 4. Mostrar cuentas bancarias. \n 5. Salir. \ningrese su opcion: ";
		cin >> opcion;
		switch (opcion)
		{
		case 1:
			system("cls");
			cout << "Ingrese la cantidad de soles: "; cin >> cantSolCambiar;
			cambiarSoles(cantSolCambiar, u);
			system("pause");
			system("cls");
			PantInicio();
			menu(u);

		case 2:
			system("cls");
			cout << "Ingrese la cantidad de dolares: "; cin >> cantDolCambiar;
			cambiarDolar(cantDolCambiar, u);
			system("pause");
			system("cls");
			PantInicio();
			menu(u);


		case 3:

			system("pause");
			system("cls");
			PantInicio();
			menu(u);

		case 4:
			system("cls");
			u.mostrarCuentas();
			system("pause");
			system("cls");
			PantInicio();
			menu(u);
		case 5:
			exit(1);
		default:

			system("cls");
			PantInicio();
			cout << endl << "Ingrese una opcion valida." << endl;
			menu(u);



		}



	}

	
	void cambiarSoles(dato cant, Usuario<void>& u) {
		auto disminuirS = [&](dato cant, Usuario<void>& usuario) {
			return usuario.setCuentaSol(u.getCuentaSol() - cant);
		};
		auto aumentarD = [&](dato cant, Usuario<void>& usuario) {
			return usuario.setCuentaDol(usuario.getCuentaDol() + (cant / 3.9150));
		};

		if (cant <= u.getCuentaSol())
		{
			disminuirS(cant, u);
			aumentarD(cant, u);
			cout << "Cantidad de dolares obtenidos: " << cant / 3.9150 << endl;
		}
		else cout << "No cuentas con suficientes fondos para realizar esta accion\n";

	}

	void cambiarDolar(dato cant, Usuario<void>& u) {
		auto disminuirD = [&](dato cant, Usuario<void>& usuario) {
			return usuario.setCuentaDol(u.getCuentaDol() - cant);
		};
		auto aumentarS = [&](dato cant, Usuario<void>& usuario) {
			return usuario.setCuentaSol(usuario.getCuentaSol() + (cant * 3.8750));
		};

		if (cant <= u.getCuentaSol())
		{
			disminuirD(cant, u);
			aumentarS(cant, u);
			cout << "Cantidad de soles obtenidos: " << cant * 3.8750 << endl;
		}
		else cout << "No cuentas con suficientes fondos para realizar esta accion\n";

	}

	




};