#pragma once
#include "Usuario.h"

//.
//template<typename dato>
class Controller {

	//Arbol<Usuario>* arbolUsuarios = new Arbol<Usuario>();
	Lista<Usuario> listaUsuarios = Lista<Usuario>();

public:

	Controller();

	void PantInicio();
	void registroUsuario();
	void menu();

	void mostrarListaUsuarios();
	void grabarUsuarios();
	void cargarUsuarios();

	void registrarReclamo();

	


};