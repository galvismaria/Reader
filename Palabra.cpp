#include "Palabra.h"
#include "Lista.h"

Palabra::Palabra(){
	
	palabra = "\0";
	paginas = new Lista<int>;
	lineas = new Lista<int>;
	
}

Palabra::Palabra( string palabra, int pagina, int linea ){
	
	this->palabra = palabra;
	//paginas->insertar( pagina );
	//lineas->insertar( linea );
	
}

string Palabra::getPalabra(){
	
	return palabra;
	
}

bool Palabra::operator == (Palabra p) const{
	
	return palabra == p.getPalabra();
	
}

bool Palabra::operator != (Palabra p) const{
	
	return palabra != p.getPalabra();
	
}

