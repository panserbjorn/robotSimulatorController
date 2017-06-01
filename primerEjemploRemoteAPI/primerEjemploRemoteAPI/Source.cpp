#include <stdio.h>
#include <iostream>
using namespace std;
#define FORWARD_MOVEMENT 1
#define BACKWARD_MOVEMENT 2
#define FORWARD_LEFT_MOVEMENT 3
#define FORWARD_RIGHT_MOVEMENT 4
#define BACKWARD_LEFT_MOVEMENT 5
#define BACKWARD_RIGHT_MOVEMENT 6
#define STOP 7

extern "C" {
     #include "extApi.h"
}

int main(int argc, char** argv)
{
   int portNb=19997;   //Se define el puerto de conexi�n

   //Conectar con V-REP
   int clientID = simxStart("127.0.0.1", portNb, true, true, 5000, 5) ;

  //Si la conexi�n es exitosa iniciar la simulaci�n
  if(clientID >-1)
  {
        simxStartSimulation(clientID,simx_opmode_oneshot);
		int respuesta;
		cin>> respuesta;
		simxInt leftMotorHandle, rightMotorHandle;
		int rightMotorSpeed,leftMotorSpeed;

		//Recupero los motores del bubbleRob
		simxGetObjectHandle(clientID,"bubbleRob_leftMotor",&leftMotorHandle,simx_opmode_blocking);
		simxGetObjectHandle(clientID,"bubbleRob_rightMotor",&rightMotorHandle,simx_opmode_blocking);

		//Determino cual es la direcci�n en la que el usuario desea ir
		while (respuesta){
			switch (respuesta){
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
			}

			//Establesco la velocidad en el simulador (una para el motor izquierdo y otro para el derecho)
			simxSetJointTargetVelocity(clientID,leftMotorHandle,leftMotorSpeed,simx_opmode_oneshot);
			simxSetJointTargetVelocity(clientID,rightMotorHandle,rightMotorSpeed,simx_opmode_oneshot);

			//Pido una nueva reapuesta para indicar la direcci�n
			cin>> respuesta;
		}

		//Detengo la simulaci�n
        simxStopSimulation(clientID, simx_opmode_oneshot_wait);
  }

  //Cierro la conexi�n con el simulador
  simxFinish(clientID);
}
