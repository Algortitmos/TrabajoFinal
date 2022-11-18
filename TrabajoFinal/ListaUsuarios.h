#pragma once
#include "Lista.h"
#include "Usuario.h"

class ListaUsuarios {
private:
	Lista<Usuario> listaU;
public:
	ListaUsuarios();

	Usuario cargarPosicionLista(int n);
	void mostrarLista();
	void mostrarTransaccionUbicacion(int n);



};