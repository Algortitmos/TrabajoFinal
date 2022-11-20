#pragma once

#include "Librerias.h"
#include "Dolares.h"



template<typename dato>
class Transacciones {

	dato dat,cant;
	Dolares d;
	string tipoOpercaion;    //Esto podria dar errores por no ponerle null al inicio
	dato resultado;

public:

	Transacciones() {}


	//void realizarOperacion();
	//dato comprarDolares(dato d);
	//dato venderDolares(dato d);

	string getTipoOperacion() { return tipoOpercaion; }
	dato getResultado() { return resultado; }
	dato getCantidad() { return cant; }

	void realizarOperacion() {
		int opcion;
		
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
				tipoOpercaion = "compra";
				cout << " Ingrese la cantidad de dolares a comprar : "; cin >> cant;
				cout << endl << " Para comprar " << cant << "$ usted debe pagar : S/" << comprarDolares(cant);
				cout << endl << endl << endl;
				cout << " Presione 'm' para salir al menu principal o 'c' para continuar : "; cin >> s;
				cout << "-------------------------------------------------------";
				cout << endl << endl << endl;
			}


			if (opcion == 2)
			{
				tipoOpercaion = "venta";
				cout << " Ingrese la cantidad de dolares a vender : "; cin >> cant;
				cout << endl << " Por vender " << cant << "$ usted recibira: S/" << venderDolares(cant);
				cout << endl << endl << endl;
				cout << " Presione 'm' para salir al menu principal o 'c' para continuar : "; cin >> s;
				cout << "-------------------------------------------------------";
				cout << endl << endl << endl;
			}

		} while (s != 'm');




	}

	dato comprarDolares(dato cant) {
		return resultado = cant * d.obtenerValorcompra();
	}
	dato venderDolares(dato cant) {
		return resultado = cant * d.obtenerValorVenta();
	}


};