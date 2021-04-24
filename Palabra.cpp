#include "Palabra.h"
#include "Lista.h"

Palabra::Palabra(){
	
	palabra = "\0";
	paginas = new Lista<int>;
	lineas = new Lista<int>;
	
}

Palabra::Palabra( string p ){
	
	palabra = p;
	paginas = new Lista<int>;
	lineas = new Lista<int>;
	
}

Palabra::Palabra(const Palabra &nuevaPalabra){
	
	palabra = nuevaPalabra.palabra;	
	
}

string Palabra::getPalabra(){
	
	return palabra;
	
}

void Palabra::agregarPagina( int pag ){
	
	//lineas->insertar( pag);
	
}

void Palabra::agregarLinea( int ln ){
	
	//lineas->insertar( ln );
	
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

