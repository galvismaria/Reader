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
<<<<<<< HEAD
=======
		int palabrasUnicas(Nodo *nodo, int cont);
>>>>>>> f38c1b8929464028754b7d70f41e8eed555a09c8
		void imprimirInOrden();
		int palabrasUnicas( Nodo *nodo);
	
};

#endif
