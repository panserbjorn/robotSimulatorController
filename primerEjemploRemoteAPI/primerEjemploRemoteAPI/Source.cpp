#include <stdio.h>
#include "OrquestadorAsincronico.h"
#include <iostream>
using namespace std;



int main(int argc, char** argv)
{
	//Esto llama al orquestador asincr�nico
	OrquestadorAsinc asinc = OrquestadorAsinc();
	asinc.Run();
	
	//TODO ac� tengo que llamar al orquestador sincr�nico

}
