#pragma once
extern "C" {
#include "extApi.h"
}
enum class Movimiento { Contraer, Estirar, Adelantar, Retroceder, Frenar };
enum class Hemisferio { Derecho, Izquierdo };

class Controller {
	//ID para la conexion del cliente de V-REP
	int ClientID;

	//Variables de los motores del modelo
	int leftUpperMotor, leftLowerMotor, rightUpperMotor, rightLowerMotor;
	//Variables para guardar las velocidades de los motores
	int lowerSpeed, upperSpeed;

public:
	Controller(int cLientID, int LUM, int LLM, int RUM, int RLM);
	void MoverPierna(Movimiento m, Hemisferio h);
	bool Erguido();
};
