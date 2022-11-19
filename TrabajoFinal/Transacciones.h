#pragma once

#include "Librerias.h"
#include "Dolares.h"




template<typename dato>
class Transacciones {

	dato dat;
	Dolares d;
	/*Vector<string>* trans = new Vector<string>();*/

public:

	Transacciones() {}

	//void realizarOperacion();
	//dato comprarDolares(dato d);
	//dato venderDolares(dato d);

	void realizarOperacion(Usuario u) {
		int opcion;
		dato cant;
		char s = NULL;

		cout << " El tipo de cambio del dia es: " << endl;
		cout << " Compra : " << d.obtenerValorcompra() << "  |  Venta : " << d.obtenerValorVenta() << endl << endl;
		

		do
		{
			cout << " Desea comprar o vender dolares? : " << endl << endl;
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
				cout << "------------------------------------------------------------------";
				cout << endl << endl << endl;
				guardarTransCompra(u, cant);
			}


			if (opcion == 2)
			{
				cout << " Ingrese la cantidad de dolares a vender : "; cin >> cant;
				cout << endl << " Por vender " << cant << "$ usted recibira: S/" << venderDolares(cant);
				cout << endl << endl << endl;
				cout << " Presione 'm' para salir al menu principal o 'c' para continuar : "; cin >> s;
				cout << "------------------------------------------------------------------";
				cout << endl << endl << endl;
				guardarTransCompra(u, cant);
			}
		
		} while (s != 'm');
	}

	dato comprarDolares(dato cant) {
		return cant * d.obtenerValorcompra();
	}
	dato venderDolares(dato cant) {
		return cant * d.obtenerValorVenta();
	}

	void guardarTransCompra(Usuario u, int cant) {
		ofstream archivo;
		archivo.open("U" + u.getFullname().c_str() + to_string(u.getDni()).c_str(), ios::out);
		if (archivo.is_open()) {
			archivo << "Compra de dolares: "<< cant << endl;
			archivo << "Cantidad de soles invertidos: " << comprarDolares(cant);
		}
		else
		{
			cout << "Hubo un error con la apertura del archivo.";
		}

		archivo.close()
	}

	void guardarTransVenta(Usuario u, int cant) {
		ofstream archivo;
		archivo.open("U" + u.getFullname().c_str() + to_string(u.getDni()).c_str(), ios::out| ios::app);
		if (archivo.is_open()) {
			archivo << "==================================" << endl;
			archivo << "Venta de dolares: " << cant << endl;
			archivo << "Cantidad de soles obtenidos: " << venderDolares(cant);
			archivo << "==================================" << endl << endl;
		}
		else
		{
			cout << "Hubo un error con la apertura del archivo.";
		}
		archivo.close()
	}

	void leerTransacciones() {
		ifstream archivo;
		string texto;

		archivo.open("U" + u.getFullname().c_str() + to_string(u.getDni()).c_str(), ios::out | ios::app);
		if (archivo.is_open())
		{
			while (!archivo.eof())
			{
				getline(archivo, texto);
				cout << texto << endl;
			}
		}
		archivo.close()
	}
};