#include "Palabra.h"

Palabra::Palabra(){
	
	palabra = "\0";
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
		
		printf( "\033[1;93m%s\033[0m\n", palabra.c_str() );
		cout << " ";
		
	}	
	
}

void Palabra::mostrarPaginas(){
	
	if ( palabra != "\0" ){
		
		for ( const int &p : *paginas ){
			
			cout << setw(5);
			cout << p;
			
		}
		
		cout << endl;
		
	}
	
}

void Palabra::mostrarLineas(){
	
	if ( palabra != "\0" ){
		
		for ( const int &l : *lineas ){
			
			cout << setw(6);
			cout << l;
			
		}
		
		cout << endl;
		
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

bool Palabra::esUnica(){
	
	if ( lineas->size() == 1 )
	
		return true;
	
	else
		
		return false;
		
}

Palabra::~Palabra(){
	
	delete & palabra;
	delete [] paginas;
	delete [] lineas;
	
}
