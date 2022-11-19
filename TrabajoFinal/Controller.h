#pragma once
#include "Usuario.h"

//.
//template<typename dato>
class Controller {
private:
	/*ListaUsuarios U;*/
	//usuario de prueba
	Usuario u = Usuario(1289301423, "Ridan Lightwood", "ridan30060@gmail.com", 955529674);
public:

	Controller();

	void PantInicio();
	
	void menu();	

	void menuRegistrar();
	//void verTransacciones();


};