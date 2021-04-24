#ifndef PALABRA
#define PALABRA

#include "Global.h"
//#include "Lista.h"

using namespace std;

template <typename T> class Lista;

class Palabra{
	
	private:
		
		string palabra;
		Lista<int> *paginas;
		Lista<int> *lineas;
		
	public:
		
		Palabra();
		Palabra(string palabra);
		Palabra(const Palabra &nuevaPalabra);
		string getPalabra();
		void agregarPagina(int pag);
		void agregarLinea(int ln);
		bool operator == (Palabra p) const;
		bool operator != (Palabra p) const;
		Palabra& operator = (const Palabra &p);
			
};

#endif
