#ifndef ARTICULO
#define ARTICULO

#include "ArbolAVL.h"
#include "Hash.h"

using namespace std;

class Articulo{
	
	private:
		
		ArbolAVL *palabras;
		Hash *tablaCapitulos;
		Hash *tablaAlfabetica;
		
	public:
		
		Articulo();
		void crearArbol(string palabra);
		void crearTablaCapitulos(Nodo *nodo, bool esRaiz, int capitulo);
		void crearTablaAlfabetica(Nodo *nodo, bool esRaiz);
		void imprimirTablaCapitulos();
		void imprimirTablaAlfabetica();		
	
};

#endif
