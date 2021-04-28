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
		int capitulosTotales;
		int paginasTotales;
		int lineasTotales;
		int palabrasTotales;
		int palabrasUnicas;
		
	public:
		
		Articulo();
		int extraerNumero(string str);
		bool esNumero(string str);
		void cargarTablaCapitulos();
		void cargarTablaAlfabetica();
		void mostrarArchivo();
		void insertarPalabra(string palabra, int linea, int pagina);
		void crearTablaAlfabetica(Nodo *nodo, bool esRaiz);
		void crearTablaCapitulos(Nodo *nodo, bool esRaiz, int capitulo);
		void indiceLineas();
		void indicePaginas();
		void indiceCapitulo(int capitulo);
		void mostrarCapitulos();
		void busquedaPalabra();
		bool borrarIndiceAlfabetico();
		bool borrarIndiceCapitulo(int capitulo);
		void menuPrincipal();
		void salir();
		~Articulo();
	
};

#endif
