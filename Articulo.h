#ifndef ARTICULO
#define ARTICULO

#include "ArbolAVL.h"
#include "Hash.h"
#include "Global.h"

using namespace std;

class Articulo{
	
	private:
		
		ArbolAVL *arbolPalabras;
		Hash *tablaCapitulos;
		Hash *tablaAlfabetica;
		
	public:
		
		Articulo();
		void insertarPalabra(string palabra, int linea, int pagina);
		void crearTablaAlfabeticaAux(Nodo *nodo, bool esRaiz);
		void crearTablaCapitulosAux(Nodo *nodo, bool esRaiz, int capitulo);
		void crearTablaAlfabetica();
		void crearTablaCapitulos();
		void imprimirTablaCapitulos();
		void imprimirTablaAlfabetica();
		void indice();
	
};

#endif
