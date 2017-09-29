#pragma once
//#include "extApi.h"
#include <iostream>
#include "ControladorDeMovimientos.h"
using namespace std;

extern "C" {
#include "extApi.h"
}

//#define FORWARD_MOVEMENT 1
//#define BACKWARD_MOVEMENT 2
//#define FORWARD_LEFT_MOVEMENT 3
//#define FORWARD_RIGHT_MOVEMENT 4
//#define BACKWARD_LEFT_MOVEMENT 5
//#define BACKWARD_RIGHT_MOVEMENT 6
//#define STOP 7
#define RIGHT_CONTRACT 1
#define RIGHT_STRETCH 2	
#define RIGHT_AHEAD 3
#define RIGHT_BACK 4
#define LEFT_CONTRACT 5
#define LEFT_STRETCH 6
#define LEFT_AHEAD 7
#define LEFT_BACK 8
#define STOP_L 9
#define STOP_R 10


class OrquestadorAsinc {
	int portNb;
	int clientID;
public:
	OrquestadorAsinc();
	void Run();
};
