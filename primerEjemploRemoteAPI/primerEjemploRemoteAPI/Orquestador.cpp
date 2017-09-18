#include "Orquestador.h"

Orquest::Orquest()
{
	this->time = 0;
	this->corridas = 0;
	this->estable = true;
	this->controlador = Controlador();
}

void Orquest::Run()
{
	//TODO este es el lugar en donde va a estar todo el código que hace que el simulador se mueva
}
