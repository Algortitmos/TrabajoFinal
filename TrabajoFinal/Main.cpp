#include "Librerias.h"
#include "Controller.h"




int main() {

	Controller<int>* obj = new Controller<int>();

	obj->PantInicio();
	obj->registrarUsuario();
	return 0;

}