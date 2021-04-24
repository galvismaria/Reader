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
		void cargar();
		void crearTablaAlfabetica(Nodo *nodo, bool esRaiz);
		void crearTablaCapitulos(Nodo *nodo, bool esRaiz, int capitulo);
		void indiceLineas();
		void indicePaginas();
		void menuPrincipal();
		void salir();
	
};

#endif
