#include "Laberinto.h"
#include <iostream>

int main(int argc, char** argv)
{
	Laberinto l(16);

	l.generar();

	std::cout << l << endl;

	return 0;
}