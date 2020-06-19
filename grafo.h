#include <strstream>

using namespace std;

class Nodo
{
public:
	int id;
	int d;
	int p;
};

class Grafo
{
public:
	Grafo(int nodos);
	virtual ~Grafo();

	bool existeArco(int u, int v);
	int costo(int u, int v);
	void generarGrilla();
	void prim(int s);
	ostrstream serializar();

	const static int COSTO_INFINITO = 1024*1024*1024;

protected:
	void inicializarNodos();
	void generarVecino(int nodo, int fila, int columna);

private:
	Nodo* V;
	int nodos;
	int nodos_grilla;
	int** ady;
};


