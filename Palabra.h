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
		Palabra(string palabra);
		Palabra(Palabra *p);
		string getPalabra();
		void agregarPagina(int pag);
		void agregarLinea(int ln);
		bool operator == (Palabra p) const;
		bool operator != (Palabra p) const;
		Palabra& operator = (const Palabra &p);
			
};

#endif
