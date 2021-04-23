#include "Palabra.h"
#include "Lista.h"

Palabra::Palabra(){
	
	palabra = "\0";
	paginas = new Lista<int>;
	lineas = new Lista<int>;
	
}

Palabra::Palabra( string palabra, int pagina, int linea ){
	
	this->palabra = palabra;
	paginas = new Lista<int>;
	paginas->insertar(pagina);
	lineas = new Lista<int>;
	lineas->insertar(linea);
	
}

Palabra::Palabra(const Palabra &nuevaPalabra){
	
	palabra = nuevaPalabra.Palabra;
	
	
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

Palabra& Palabra::operator = (const Palabra &p){
	
    if ( this != &p ) {
        
        palabra = p.palabra;
        
        
    }
    return *this;
}

