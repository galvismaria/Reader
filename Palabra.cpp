#include "Palabra.h"

Palabra::Palabra(){
	
	palabra = "\0";
	paginas = nullptr;
	lineas = nullptr;
	
}

Palabra::Palabra( string palabra, int pagina, int linea ){
	
	this->palabra = palabra;
	paginas->insertar( pagina );
	lineas->insertar( linea );
	
}

string Palabra::getPalabra(){
	
	return palabra;
	
}
