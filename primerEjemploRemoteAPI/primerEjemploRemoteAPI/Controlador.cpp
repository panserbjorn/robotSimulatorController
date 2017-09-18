#include "Controlador.h"

Controlador::Controlador()
{
	this->corridaActual = 0;
	this->corridas = list<list<tuple<Movimiento, Tiempo>*>>();
}

bool Controlador::HayCorridas()
{
	return !corridas.empty();
}

//Pre: la lista de corridas no debe estar vacía
list<tuple<Movimiento, Tiempo>*> Controlador::siguienteCorrida()
{
	//list<tuple<Movimiento, Tiempo>> first = list<tuple<Movimiento,Tiempo>>( corridas.front());
	////TODO No estoy seguro de si esto no me borra la lista de movimientos que voy a devolver, puede ser que se produzca un error
	//corridas.pop_front();
	//return first;
	return list<tuple<Movimiento, Tiempo>*>();
}
