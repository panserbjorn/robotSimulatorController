#include "RecuperadorInstrucciones.h"

RecInstr::RecInstr()
{
	ofstream myfile("example.txt");
	if (myfile.is_open())
	{
		myfile << "This is a line.\n";
		myfile << "This is another line.\n";
		myfile.close();
	}
	//Todo este método tiene que ir a vuscar el archivo y empezar el procesamiento del mismo. Estaría bueno poder hacer el procesamiento de manera asincrónica, pero no hiere a nadie si no lo es.
}

bool RecInstr::EstaArchivo()
{
	return false;
}

list<string> RecInstr::recuperarSecuancias()
{
	return this->listaInstrucciones;
}
