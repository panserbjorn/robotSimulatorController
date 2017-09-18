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
#define LEFT_CONTRACT 3
#define LEFT_STRETCH 4


class OrquestadorAsinc {
	int portNb;
	int clientID;
public:
	OrquestadorAsinc();
	void Run();
};
