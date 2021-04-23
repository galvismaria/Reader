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
		Palabra(string palabra, int pagina, int linea);
		Palabra(const Palabra &nuevaPalabra);
		string getPalabra();
		bool operator == (Palabra p) const;
		bool operator != (Palabra p) const;
			
};

#endif
