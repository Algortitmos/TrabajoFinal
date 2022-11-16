#include "Librerias.h"
#include "Controller.h"


int main() {

	Controller<float>* obj = new Controller<float>();

	obj->PantInicio();
	obj->registrarUsuario();
	return 0;

}


//Main inicial