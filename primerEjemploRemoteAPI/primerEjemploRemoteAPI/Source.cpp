#include <stdio.h>
#include <iostream>
using namespace std;
//#define FORWARD_MOVEMENT 1
//#define BACKWARD_MOVEMENT 2
//#define FORWARD_LEFT_MOVEMENT 3
//#define FORWARD_RIGHT_MOVEMENT 4
//#define BACKWARD_LEFT_MOVEMENT 5
//#define BACKWARD_RIGHT_MOVEMENT 6
//#define STOP 7
#define RIGHT_CONTRACT 1
#define RIGHT_STRETCH 2
#define LEFT_CONTRACT 3
#define LEFT_STRETCH 4

extern "C" {
#include "extApi.h"
}

int main(int argc, char** argv)
{
	int portNb = 19997;   //Se define el puerto de conexión

	//Conectar con V-REP
	int clientID = simxStart("127.0.0.1", portNb, true, true, 5000, 5);

	//Si la conexión es exitosa iniciar la simulación
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
		int leftUpperSpeed, leftLowerSpeed, rightUpperSpeed, rightLowerSpeed;

		//TODO Falta traer los handlers de los motores de mi modelo

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

			//TODO estas son solo algunas de las acciones, debo definir otras más
			switch (respuesta) {
			case RIGHT_CONTRACT:
				rightUpperSpeed = -4;
				rightLowerSpeed = 4;
				break;
			case RIGHT_STRETCH:
				rightUpperSpeed = 0;
				rightLowerSpeed = -4;
				break;
			case LEFT_CONTRACT:
				leftUpperSpeed = -4;
				leftLowerSpeed = 4;
				break;
			case LEFT_STRETCH:
				leftUpperSpeed = 0;
				leftLowerSpeed = -4;
				break;
			default:
				leftUpperSpeed = leftLowerSpeed = rightUpperSpeed = rightLowerSpeed = 0;
				break;
			}

			//Código del BubbleRob que pone la velocidad definida en el simulador
			//Establesco la velocidad en el simulador (una para el motor izquierdo y otro para el derecho)
			/*simxSetJointTargetVelocity(clientID, leftMotorHandle, leftMotorSpeed, simx_opmode_oneshot);
			simxSetJointTargetVelocity(clientID, rightMotorHandle, rightMotorSpeed, simx_opmode_oneshot);*/

			//TODO Falta enviar la señal de las velocidades a los motores en el simulador

			//Pido una nueva respuesta para indicar la dirección
			cin >> respuesta;
		}

		//Detengo la simulación
		simxStopSimulation(clientID, simx_opmode_oneshot_wait);
	}

	//Cierro la conexión con el simulador
	simxFinish(clientID);
}
