#include "ControladorDeMovimientos.h"

Controller::Controller(int cLientID, int LUM, int LLM, int RUM, int RLM) {
	this->leftLowerMotor = LLM;
	this->leftUpperMotor = LUM;
	this->rightLowerMotor = RLM;
	this->rightUpperMotor = RUM;
	this->lowerSpeed = this->upperSpeed = 0;
	this->ClientID = cLientID;
}

void Controller::MoverPierna(Movimiento m, Hemisferio h) {
	switch (m)
	{
	case Movimiento::Contraer:
		lowerSpeed = -1;
		upperSpeed = 1;
		break;
	case Movimiento::Estirar:
		lowerSpeed = 1;
		upperSpeed = -1;
		break;
	case Movimiento::Adelantar:
		lowerSpeed = 0;
		upperSpeed = 1;
		break;
	case Movimiento::Retroceder:
		lowerSpeed = 0;
		upperSpeed = -1;
		break;
	case Movimiento::Frenar:
		lowerSpeed = upperSpeed = 0;
		break;
	default:
		break;
	}
	if (h == Hemisferio::Izquierdo) {
		simxSetJointTargetVelocity(ClientID, leftLowerMotor, lowerSpeed, simx_opmode_oneshot);
		simxSetJointTargetVelocity(ClientID, leftUpperMotor, upperSpeed, simx_opmode_oneshot);
	}
	else {
		simxSetJointTargetVelocity(ClientID, rightLowerMotor, lowerSpeed, simx_opmode_oneshot);
		simxSetJointTargetVelocity(ClientID, rightUpperMotor, upperSpeed, simx_opmode_oneshot);
	}
}

bool Controller::Erguido()
{
	return true;
}
