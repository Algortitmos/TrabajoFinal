#pragma once
#include "Lista.h"
#include "Usuario.h"

class ListaUsuarios {
private:
	Lista<Usuario*> *listaU;
public:
	ListaUsuarios();

	Usuario cargarPosUsuario(int n);
	void mostrarLista();
	void mostrarPos(int n);
	void mostrarTransaccionUbicacion(int n);
	


};