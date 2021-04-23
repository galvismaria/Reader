#ifndef PALABRA
#define PALABRA

#include <list>
#include "Global.h"

using namespace std;

class Palabra{
	
	private:
		
		class Par{
			
			public:
				
				int elemento;
				int repeticiones;
								
				Par();
				Par(int elemento, int repeticiones);
				Par(const Par &p);
				void setElemento(int elemento);
				void incrementarRepeticiones();
				int getElemento();
				int getRepeticiones();
				
			
		};
		
		string palabra;
		list<Par> *paginas;
		list<Par> *lineas;
		
	public:
		
		Palabra();
		Palabra(string palabra, int pagina, int linea);
		Palabra(const Palabra &newPalabra);
		string getPalabra();
		void imprimir();
		bool operator == (Palabra p) const;
		bool operator != (Palabra p) const;
			
};

#endif
