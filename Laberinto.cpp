#include "Laberinto.h"
#include "Grafo.h"
#include <fstream>

Laberinto::Laberinto(int celdas)
{
	int i, j;
	this->celdas = celdas;
	m = new char* [celdas];
	if (m == nullptr)
		error_fatal("Error creando matriz");
	for (i = 0; i < celdas; i++)
	{
		m[i] = new char[celdas];
		if (m[i] == nullptr)
			error_fatal("Error creando matriz");
		for (j = 0; j < celdas; j++)
			m[i][j] = '*';
	}
}

Laberinto::~Laberinto()
{
	int i;
	for (i = 0; i < celdas; i++)
		delete m[i];
	delete m;
}

void Laberinto::generar()
{
	int i,nodo;
	int f_o, f_d, c_o, c_d;
	Grafo* grafo;
	int nodos = (celdas / 2) * (celdas / 2);
	int nodos_grilla = celdas / 2;
	ostrstream s;
	fstream f;

	grafo = new Grafo(nodos);
	if (grafo == nullptr)
		error_fatal("Imposible generar grafo");
	grafo->generarGrilla();
	grafo->prim(0);

	for (i = 0; i < nodos; i++)
	{
		nodo = grafo->getNodo(i).p;
		if (nodo != -1)
		{
			c_o = i % nodos_grilla;
			f_o = (i - c_o) / nodos_grilla;

			m[f_o * 2][c_o * 2]=' ';

			c_d = nodo % nodos_grilla;
			f_d = (nodo - c_d) / nodos_grilla;

			m[f_d * 2][c_d * 2]=' ';

			if (c_o == c_d)
			{
				m[f_d * 2 + 1][c_d * 2]=' ';
			}
			if (f_o == f_d)
			{
				m[f_d * 2][c_d * 2 + 1]=' ';
			}
		}
	}

	f.open("mapa.txt", ios::out);
	f << *this << endl;
	f.close();

	delete grafo;
}

bool Laberinto::esMuro(int fila, int columna)
{
	if (m[fila][columna] == ' ')
		return false;
	else
		return true;
}

std::ostream& operator<<(std::ostream& os, Laberinto& l)
{
	int i,j;
	for (i = 0; i < l.celdas; i++)
		os << "* ";
	os << "*" << endl;

	for (i = 0; i < l.celdas; i++)
	{
		os << "* ";
		for (j = 0; j < l.celdas; j++)
		{
			os << l.m[i][j] << " ";
		}
		os << endl;
	}
	return os;
}