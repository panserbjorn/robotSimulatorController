#include <stdio.h>
#include "OrquestadorAsincronico.h"
#include <iostream>
using namespace std;



int main(int argc, char** argv)
{
	//Esto llama al orquestador asincrónico
	OrquestadorAsinc asinc = OrquestadorAsinc();
	asinc.Run();
	
	//TODO acá tengo que llamar al orquestador sincrónico

}
