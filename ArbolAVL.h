#ifndef ARBOL_AVL
#define ARBOL_AVL

#include "Global.h"
#include "Nodo.h"

using namespace std;

class ArbolAVL{
	
	private:
		
		Nodo *raiz;
		
		void balancearEnNodo(Nodo *n);
		Nodo *encontrarNodo(string palabra);
		void rotarIzquierda(Nodo *n);
		void rotarDerecha(Nodo *n);
		void setRaiz(Nodo *n);
		
	public:
		
		ArbolAVL();
		ArbolAVL(Palabra* p);
		Nodo *getRaiz();
		int getAltura();
		bool insertarNodo(Palabra* p, int linea, int pagina);
		bool quitarNodo(string palabra);
		void inOrden(Nodo *nodo, bool esRaiz = true);
		void imprimirInOrden();
	
};

#endif
