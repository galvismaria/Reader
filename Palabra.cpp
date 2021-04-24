#include "Palabra.h"

Palabra::Palabra(){
	
	palabra = "\0";
	paginas = new list<int>();
	lineas = new list<int>();
	
}

Palabra::Palabra( string p ){
	
	palabra = p;
	paginas = new list<int>();
	lineas = new list<int>();
	
}

Palabra::Palabra(const Palabra &nuevaPalabra){
	
	palabra = nuevaPalabra.palabra;	
	
}

string Palabra::getPalabra(){
	
	return palabra;
	
}

void Palabra::agregarPagina( int pag ){
	
	paginas->push_back(pag);
	
}

void Palabra::agregarLinea( int ln ){
	
	lineas->push_back(ln);
	
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
        paginas = p.paginas;
        lineas = p.lineas;
        
    }
    return *this;
}

