#pragma once

#include "Librerias.h"
#include "Dolares.h"



template<typename dato>
class Transacciones {

	dato dat;
	Dolares d;

public:

	Transacciones() {}

	//void realizarOperacion();
	//dato comprarDolares(dato d);
	//dato venderDolares(dato d);

	void realizarOperacion() {
		int opcion;
		dato cant;
		char s = NULL;

		cout << " El tipo de cambio del dia es: " << endl;
		cout << " Compra : " << d.obtenerValorcompra() << "  |  Venta : " << d.obtenerValorVenta() << endl << endl;


		do
		{
			cout << "  Desea comprar o vender dolares? : " << endl << endl;
			cout << " 1.- Comprar" << endl;
			cout << " 2.- Vender" << endl << endl;
			cout << " Ingrese opcion : "; cin >> opcion;

			cout << endl;

			if (opcion == 1)
			{
				cout << " Ingrese la cantidad de dolares a comprar : "; cin >> cant;
				cout << endl << " Para comprar " << cant << "$ usted debe pagar : S/" << comprarDolares(cant);
				cout << endl << endl << endl;
				cout << " Presione 'm' para salir al menu principal o 'c' para continuar : "; cin >> s;
				cout << "-------------------------------------------------------";
				cout << endl << endl << endl;
			}


			if (opcion == 2)
			{
				cout << " Ingrese la cantidad de dolares a vender : "; cin >> cant;
				cout << endl << " Por vender " << cant << "$ usted recibira: S/" << venderDolares(cant);
				cout << endl << endl << endl;
				cout << " Presione 'm' para salir al menu principal o 'c' para continuar : "; cin >> s;
				cout << "-------------------------------------------------------";
				cout << endl << endl << endl;
			}



			//switch (opcion)
			//{
			//case 1:
			//	cout << " Ingrese la cantidad de dolares a comprar : "; cin >> cant;
			//	cout << " Para comprar " << cant << "$ usted debe pagar : S/" << comprarDolares(cant);
			//	cout << endl << endl;
			//	cout << " Presione 's' para salir "; cin >> s;
			//	break;
			//case 2:
			//	cout << " Ingrese la cantidad de dolares a vender : "; cin >> cant;
			//	cout << " Por vender dolares " << cant << "$ usted recibira: S/" << venderDolares(cant);
			//	cout << endl << endl;
			//	cout << " Presione 's' para salir "; cin >> s;
			//	break;

			//}
		} while (s != 'm');




	}

	dato comprarDolares(dato cant) {
		return cant * d.obtenerValorcompra();
	}
	dato venderDolares(dato cant) {
		return cant * d.obtenerValorVenta();
	}


};