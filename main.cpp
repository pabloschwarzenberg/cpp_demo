#include "Grafo.h"
#include <fstream>

int main(int argc, char** argv)
{
	Grafo grafo(16);
	fstream f;
	ostrstream s;

	grafo.generarGrilla();
	grafo.prim(0);

	s = grafo.serializar();

	f.open("mapa.csv", ios::out);
	f << s.str();
	f.close();

	return 0;
}