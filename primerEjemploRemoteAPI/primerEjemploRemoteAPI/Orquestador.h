#pragma once
#include "Controlador.h"
//- Orquestador:
//Responsabilidades:
//	->Controlar el tiempo del simulador
//		Tiene que ser de manera sincr�nica, no asincr�nica.
//	->Detectar cuando el robot se cae
//		Detiene la simulaci�n cuando el robot se cae y le pregunta al controlador de movimientos si hay m�s secuencias para realizar
//	->Lleva el recuento de cuantas corridas
//		Lleva un registro de todas las corridas que se han logrado con los movimientos del controlador del robot
//	->Sabe cual fue la distancia m�xima alcanzada en cada una de las corridas
//	->Le pasa el generador de resultados la informaci�n de cada corrida
//		Tiempo y distancia

class Orquest {
	int time;
	bool estable;
	int corridas;
	Controlador controlador;
	//TODO Tengo que agregar las clases que el orquestador tiene que conocer para poder realizar sus tareas
public:
	Orquest();
	void Run();
	
};