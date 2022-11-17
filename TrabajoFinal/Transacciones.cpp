#include "Transacciones.h"
#include "Dolares.h"

Dolares dolar = Dolares();


template<typename dato>
Transacciones<dato>::Transacciones() {};

template<typename dato>
void Transacciones<dato>::realizarOperacion() {

	int opcion;
	dato cant;
	

	cout << "  Desea comprar o vender dolares? : " << endl;
	cout <<" 1.- Comprar" << endl;
	cout <<" 2.- Vender" << endl;
	cout << " Ingrese opcion : "; cin >> opcion;

	switch (opcion)
	{
	case 1:
		cout << " Ingrese la cantidad de dolares a comprar : "; cin >> cant;
		cout << " Para comprar "<<cant<<"$ ud debe pagar : "<<comprarDolares(cant);


	default:
		break;
	}

		
		


}


template<typename dato>
dato Transacciones<dato>::comprarDolares(dato d) {
	return d * dolar.valorCompra();
}

template<typename dato>
dato Transacciones<dato>::venderDolares(dato d) {
	return d * dolar.valorVenta();
}


