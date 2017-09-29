#include "OrquestadorAsincronico.h"

OrquestadorAsinc::OrquestadorAsinc()
{
	this->portNb = 19997;
	this->clientID = simxStart("127.0.0.1", portNb, true, true, 5000, 5);

}

void OrquestadorAsinc::Run()
{
	if (clientID > -1)
	{
		simxStartSimulation(clientID, simx_opmode_oneshot);
		int respuesta;
		cin >> respuesta;

		//Código de BubbleRob
		//	//Variable de los motores derecho e izquierdo
		//	simxInt leftMotorHandle, rightMotorHandle;
		//	//Variables para guardar las velocidades de los motores
		//	int rightMotorSpeed, leftMotorSpeed;

		//	//Recupero los motores del bubbleRob
		//	simxGetObjectHandle(clientID, "bubbleRob_leftMotor", &leftMotorHandle, simx_opmode_blocking);
		//	simxGetObjectHandle(clientID, "bubbleRob_rightMotor", &rightMotorHandle, simx_opmode_blocking);

		//Variables de los motores del modelo
		simxInt leftUpperMotor, leftLowerMotor, rightUpperMotor, rightLowerMotor;
		//Variables para guardar las velocidades de los motores
		simxGetObjectHandle(clientID, "LUM", &leftUpperMotor, simx_opmode_blocking);
		simxGetObjectHandle(clientID, "LLM", &leftLowerMotor, simx_opmode_blocking);
		simxGetObjectHandle(clientID, "RUM", &rightUpperMotor, simx_opmode_blocking);
		simxGetObjectHandle(clientID, "RLM", &rightLowerMotor, simx_opmode_blocking);

		int leftUpperSpeed, leftLowerSpeed, rightUpperSpeed, rightLowerSpeed;
		Controller *contr = new Controller(clientID, leftUpperMotor, leftLowerMotor, rightUpperMotor, rightLowerMotor);

		simxSetJointTargetVelocity(clientID, leftLowerMotor, 0, simx_opmode_oneshot);
		simxSetJointTargetVelocity(clientID, leftUpperMotor, 0, simx_opmode_oneshot);
		simxSetJointTargetVelocity(clientID, rightLowerMotor, 0, simx_opmode_oneshot);
		simxSetJointTargetVelocity(clientID, rightUpperMotor, 0, simx_opmode_oneshot);
		//Determino cual es la dirección en la que el usuario desea ir
		while (respuesta) {
			//Código del BubbleRob que determina la velocidad de los motores
			/*switch (respuesta) {
			case FORWARD_MOVEMENT:
			leftMotorSpeed = 4;
			rightMotorSpeed = 4;
			break;
			case BACKWARD_MOVEMENT:
			leftMotorSpeed = -4;
			rightMotorSpeed = -4;
			break;
			case FORWARD_RIGHT_MOVEMENT:
			leftMotorSpeed = 4;
			rightMotorSpeed = 1;
			break;
			case FORWARD_LEFT_MOVEMENT:
			leftMotorSpeed = 1;
			rightMotorSpeed = 4;
			break;
			case BACKWARD_RIGHT_MOVEMENT:
			leftMotorSpeed = -4;
			rightMotorSpeed = -1;
			break;
			case BACKWARD_LEFT_MOVEMENT:
			leftMotorSpeed = -1;
			rightMotorSpeed = -4;
			break;
			default:
			leftMotorSpeed = 0;
			rightMotorSpeed = 0;
			break;
			}*/

			switch (respuesta) {
			case RIGHT_CONTRACT:
				contr->MoverPierna(Movimiento::Contraer, Hemisferio::Derecho);
				break;
			case RIGHT_STRETCH:
				contr->MoverPierna(Movimiento::Estirar, Hemisferio::Derecho);
				break;
			case LEFT_CONTRACT:
				contr->MoverPierna(Movimiento::Contraer, Hemisferio::Izquierdo);
				break;
			case LEFT_STRETCH:
				contr->MoverPierna(Movimiento::Estirar, Hemisferio::Izquierdo);
				break;
			case RIGHT_AHEAD:
				contr->MoverPierna(Movimiento::Adelantar, Hemisferio::Derecho);
				break;
			case RIGHT_BACK:
				contr->MoverPierna(Movimiento::Retroceder, Hemisferio::Derecho);
				break;
			case LEFT_AHEAD:
				contr->MoverPierna(Movimiento::Adelantar, Hemisferio::Izquierdo);
				break;
			case LEFT_BACK:
				contr->MoverPierna(Movimiento::Retroceder, Hemisferio::Izquierdo);
				break;
			case STOP_L:
				contr->MoverPierna(Movimiento::Frenar, Hemisferio::Izquierdo);
				break;
			case STOP_R:
				contr->MoverPierna(Movimiento::Frenar, Hemisferio::Derecho);
				break;
			default:
				simxStopSimulation(clientID, simx_opmode_oneshot);
				simxSetJointTargetVelocity(clientID, leftLowerMotor, 0, simx_opmode_oneshot);
				simxSetJointTargetVelocity(clientID, leftUpperMotor, 0, simx_opmode_oneshot);
				simxSetJointTargetVelocity(clientID, rightLowerMotor, 0, simx_opmode_oneshot);
				simxSetJointTargetVelocity(clientID, rightUpperMotor, 0, simx_opmode_oneshot);
				simxStartSimulation(clientID, simx_opmode_oneshot_wait);
				break;
			}

			//Código del BubbleRob que pone la velocidad definida en el simulador
			//Establesco la velocidad en el simulador (una para el motor izquierdo y otro para el derecho)
			/*simxSetJointTargetVelocity(clientID, leftMotorHandle, leftMotorSpeed, simx_opmode_oneshot);
			simxSetJointTargetVelocity(clientID, rightMotorHandle, rightMotorSpeed, simx_opmode_oneshot);*/


			//Pido una nueva respuesta para indicar la dirección
			cin >> respuesta;
		}

		//Detengo la simulación
		simxStopSimulation(clientID, simx_opmode_oneshot_wait);
	}

	//Cierro la conexión con el simulador
	simxFinish(clientID);
}
