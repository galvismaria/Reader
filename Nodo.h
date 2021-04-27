#ifndef NODO
#define NODO

#include "Global.h"
#include "Palabra.h"

using namespace std;

class Nodo{
	
	private:
		
		Palabra *info;
		int altura;
		Nodo *der;
		Nodo *izq;
		Nodo *padre;
	
	public:
		
		Nodo( Palabra *p );
		int getBalance();
		Palabra* getInfo();
		int getAltura();
		Nodo *getDerecha();
		Nodo *getIzquierda();
		Nodo *getPadre();
		void quitarPadre();
		Nodo* setIzquierda( Nodo *nuevoIzq );
		Nodo* setDerecha( Nodo *nuevoDer );
		int actualizarAltura();
		~Nodo();
	
};

#endif
