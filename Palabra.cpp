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

Palabra::Palabra(Palabra *p){
	
	palabra = p->getPalabra();
	paginas = p->paginas;
	lineas = p->lineas;
	
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
	
	if ( palabra == p.getPalabra() )
		return true;
		
	else
		return false;
	
}

bool Palabra::operator != (Palabra p) const{
	
	if ( palabra != p.getPalabra() )
		return true;
		
	else
		return false;
	
}

Palabra& Palabra::operator = (const Palabra &p){
        
    this->palabra = p.palabra;
    this->paginas = p.paginas;
    this->lineas = p.lineas;
        
    return *this;
}

