#pragma once
#include <string>
#include <list>
#include <fstream>
//- Recuperador de instrucciones
//Responsabilidades :
//->Recupera de un archivo todas las secuancias de movimientos con los tiempos generados para el modelo.
using namespace std;
class RecInstr {
	string rutaArchivo;
	list<string> listaInstrucciones;
public:
	RecInstr();
	bool EstaArchivo();
	list<string> recuperarSecuancias();
};