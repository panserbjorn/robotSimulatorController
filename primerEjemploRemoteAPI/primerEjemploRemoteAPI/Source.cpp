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
   /*#include "extApiCustom.h" if you wanna use custom remote API functions! */
}

int main(int argc, char** argv)
{
   int portNb=19997;   //Se define el puerto de conexión

   //Conectar con V-REP
   int clientID = simxStart("127.0.0.1", portNb, true, true, 5000, 5) ;

  //Si la conexión es exitosa iniciar la simulación
  if(clientID >-1)
  {
        simxStartSimulation(clientID,simx_opmode_oneshot);
		int respuesta;
		cin>> respuesta;
		simxInt leftMotorHandle, rightMotorHandle;
		int rightMotorSpeed,leftMotorSpeed;

		simxGetObjectHandle(clientID,"bubbleRob_leftMotor",&leftMotorHandle,simx_opmode_blocking);
		simxGetObjectHandle(clientID,"bubbleRob_rightMotor",&rightMotorHandle,simx_opmode_blocking);
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

			simxSetJointTargetVelocity(clientID,leftMotorHandle,leftMotorSpeed,simx_opmode_oneshot);
			simxSetJointTargetVelocity(clientID,rightMotorHandle,rightMotorSpeed,simx_opmode_oneshot);
			cin>> respuesta;
		}
        simxStopSimulation(clientID, simx_opmode_oneshot_wait);
  }
  simxFinish(clientID);
}
