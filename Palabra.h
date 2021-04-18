#include "Global.h"

using namespace std;

class Palabra{
	
	private:
		
		string palabra;
		int capitulo;
		int linea;
		int contLinea;
		int contCapitulo;
		int altura;
		
	public:
		
		Palabra(){
		};
		Palabra( string palabra, int capitulo, int linea );
		string getPalabra();
		int getCapitulo();
		int getLinea();
		int getContLinea();
		int getContCapitulo();
		
	
};
