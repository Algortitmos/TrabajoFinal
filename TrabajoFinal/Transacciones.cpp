#include "Transacciones.h"

template<typename dato>
void Transacciones<dato>::realizarOperacion(Usuario u) {
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
template<typename dato>
dato Transacciones<dato>::comprarDolares(dato cant) {
	return cant * d.obtenerValorcompra();
}

template<typename dato>
dato Transacciones<dato>::venderDolares(dato cant) {
	return cant * d.obtenerValorVenta();
}

template<typename dato>
void Transacciones<dato>::guardarTransCompra(int n, Usuario u) {
	ofstream archivo;
	archivo.open("U" /*+ u.getFullname().c_str() + to_string(u.getDni()).c_str()*/, ios::out);
	if (archivo.is_open()) {
		archivo << "Compra de dolares: " << cant << endl;
		archivo << "Cantidad de soles invertidos: " << comprarDolares(cant);
	}
	else
	{
		cout << "Hubo un error con la apertura del archivo.";
	}

	archivo.close();
}

template<typename dato>
void Transacciones<dato>::guardarTransVenta(int n, Usuario u) {
	ofstream archivo;
	archivo.open("U" /*+ u.getFullname().c_str() + to_string(u.getDni()).c_str()*/, ios::out | ios::app);
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
	archivo.close();
}

template<typename dato>
void Transacciones<dato>::leerTransacciones() {
	ifstream archivo;
	string texto;

	archivo.open("U" +/* u.getFullname().c_str() + to_string(u.getDni()).c_str()*/, ios::out | ios::app);
	if (archivo.is_open())
	{
		while (!archivo.eof())
		{
			getline(archivo, texto);
			cout << texto << endl;
		}
	}
	archivo.close();
}


