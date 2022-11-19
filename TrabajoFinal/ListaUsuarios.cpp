#include "ListaUsuarios.h"

ListaUsuarios::ListaUsuarios() {
	listaU = new Lista<Usuario*>();

}

Usuario ListaUsuarios::cargarPosUsuario(int n) {
	return *listaU->at(n); 
}

void ListaUsuarios::mostrarPos(int n) {
	if (n <= listaU->cantidad)
	{
		cout << "=========================\n ";
		cout << "Usuario " << n << endl;
		cout << " DNI: " << listaU->at(n)->getDni();
		cout << " Nombre Completo: " << listaU->at(n)->getFullname();
		cout << " Correo: " << listaU->at(n)->getCorreo();
		cout << " Telefono: " << listaU->at(n)->getTelefono();
		cout << "=========================\n\n ";
	}
	else cout << "La posicion solicita en la lista no existe.\n ";
}


void ListaUsuarios::mostrarLista() {
	Lista<Usuario*> *aux = new Lista<Usuario*>();
	aux = listaU;
	int i = 1;
	for (int i = 0; i < listaU->cantidad; i++)
	{
		cout << "=========================\n";
		cout << "Usuario " << (i + 1) << endl;
		cout << " DNI: " << aux->at(i)->getDni();
		cout << " Nombre Completo: " << aux->at(i)->getFullname();
		cout << " Correo: " << aux->at(i)->getCorreo();
		cout << " Telefono: " << aux->at(i)->getTelefono();
		cout << "=========================\n\n";

	}
}
	



void ListaUsuarios::mostrarTransaccionUbicacion(int n) {

	listaU->at(n)->mostrarTransacciones();
}