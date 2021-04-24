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

Palabra::Palabra(string pb, int linea, int pagina){
	
	palabra = pb;
	paginas = new list<int>;
	lineas = new list<int>;
	agregarPagina( pagina );
	agregarLinea( linea );

}

Palabra::Palabra( Palabra *p ){
	
	palabra = p->getPalabra();
	paginas = p->paginas;
	lineas = p->lineas;
	
}

string Palabra::getPalabra(){
	
	return palabra;
	
}

void Palabra::imprimir(){
	
	if ( palabra != "\0" ){
		
		cout << palabra;
		
	}	
	
}

void Palabra::mostrarPaginas(){
	
	if ( palabra != "\0" ){
		
		cout << "[ ";
		
		for ( const int &p : *paginas ){
			
			cout << p << " ";
			
		}
		
		cout << "]" << endl;
		
	}
	
}

void Palabra::mostrarLineas(){
	
	if ( palabra != "\0" ){
		
		cout << "[ ";
		
		for ( const int &l : *lineas ){
			
			cout << l << " ";
			
		}
		
		cout << "]" << endl;
		
	}
	
}

void Palabra::agregarPagina( int pag ){
	
	list<int>::iterator it;
	it = find( paginas->begin(), paginas->end(), pag );
	
	if ( it == paginas->end() ){
		paginas->push_back(pag);
	}
	
}

void Palabra::agregarLinea( int ln ){
	
	list<int>::iterator it;
	it = find( lineas->begin(), lineas->end(), ln );
	
	if ( it == lineas->end() ){
		lineas->push_back(ln);
	}
	
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

