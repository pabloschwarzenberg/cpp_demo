#ifndef __LABERINTO_H__
#define __LABERINTO_H__

#include <iostream>

using namespace std;

void error_fatal(const char* mensaje);

class Laberinto
{
public:
	Laberinto(int celdas);
	~Laberinto();
	void generar();
	bool esMuro(int fila, int columna);
	friend std::ostream& operator<<(std::ostream& os, Laberinto& l);

private:
	int celdas;
	char** m;
};

#endif
