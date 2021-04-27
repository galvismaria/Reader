#ifndef PALABRA
#define PALABRA

#include "Global.h"

using namespace std;

class Palabra{
	
	private:
		
		string palabra;
		list<int> *paginas;
		list<int> *lineas;
		
	public:
		
		Palabra();
		Palabra(string pb, int linea, int pagina);
		Palabra(Palabra *p);
		string getPalabra();
		void imprimir();
		void mostrarPaginas();
		void mostrarLineas();
		void agregarPagina(int pag);
		void agregarLinea(int ln);
		bool esUnica();
		~Palabra();
			
};

#endif
