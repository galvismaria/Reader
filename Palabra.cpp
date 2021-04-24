#include "Palabra.h"

Palabra::Palabra(){
	
	palabra = "\0";
	paginas = new list<int>;
	lineas = new list<int>;
	
}

Palabra::Palabra( string p ){
	
	palabra = p;
	paginas = new list<int>;
	lineas = new list<int>;
	
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
        
    this->palabra = p.palabra;
    this->paginas = p.paginas;
    this->lineas = p.lineas;
        
    return *this;
}

