#pragma once
#include <list>
//- Controlador de robot
//Responsabilidades :
//->En base a los movimintos y las secuancias de tiempos genera las secuancias de velocidades de los motores que se van a efectuar
//->Guarda todas las secuancias generadas
#define Movimiento int
#define Tiempo int

using namespace std;

class Controlador {
	int corridaActual;
	list<list<tuple<Movimiento, Tiempo>>> corridas;
public:
	Controlador();
	bool HayCorridas();
	list<tuple<Movimiento, Tiempo>> siguienteCorrida();

};