#ifndef PALABRA
#define PALABRA

#include "Global.h"

using namespace std;

class Palabra{
	
	private:
		
		string palabra;
		Lista<int> paginas;
		Lista<int> lineas;
		
	public:
		
		Palabra();
		Palabra(string palabra, int pagina, int linea);
		string getPalabra();
			
};

#endif
