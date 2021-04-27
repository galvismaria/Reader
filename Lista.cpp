#include "Lista.h"

Lista::Nodo::Nodo(){
	
	palabra = new Palabra();
	siguiente = NULL;
	
}

Lista::Nodo::Nodo( Palabra *p, Nodo *sig ){
	
	palabra = p;
	siguiente = sig;
	
}

Lista::Lista(){
	
    principio = actual = NULL;
    elementos = 0;
    
}

bool Lista::listaVacia(){
	
	if ( !principio )
		return true;
		
	else
		return false;
    
}

bool Lista::hayActual(){
	
	if ( actual )
		return true;
		
	else
		return false;
	
}

void Lista::insertarNodo( Palabra *pb ){

    if ( listaVacia() ){
    
		elementos++;
		principio = new Nodo( pb, NULL );
        
    } else {
    	
    	ultimo();
        elementos++;
        actual->siguiente = new Nodo( pb, actual->siguiente );
            
    }
	
}

void Lista::siguiente(){
	
    if ( actual->siguiente )
    
        actual = actual->siguiente;
        
}

bool Lista::haySiguiente(){
	
	if ( actual->siguiente )
		return true;
		
	else
		return false;
	
}

void Lista::primero(){
	
    actual = principio;
   
}

void Lista::ultimo(){
	
    primero();
    
    if ( !listaVacia() ){
        	
        while ( actual->siguiente ){
        	
        	siguiente();
        	
		}
        	
	}
                
}

Palabra* Lista::valorActual(){
	
    return actual->palabra;
    
}

int Lista::cantElementos(){
	
    return elementos;
    
}

Palabra* Lista::buscar( string palabra ){
	
	Nodo* aux = principio;
	
	while ( aux ){
		
		if ( aux->palabra->getPalabra() == palabra ){
			
			return aux->palabra;
			
		}
		
		aux = aux->siguiente;
	}
	
	return new Palabra("\0", 0, 0);
	
}

void Lista::borrar(string palabra){
	
    Nodo *ant, *aux;

    aux = principio;
    ant = NULL;
    
    while ( aux && ( aux->palabra->getPalabra() != palabra ) ){
    	
        ant = aux;
        aux = aux->siguiente;
        
    }

    if( !aux || ( aux->palabra->getPalabra() != palabra ) ){
        return;
        
    } else{

        if ( !ant ){
        	
            principio = aux->siguiente;
            
        } else{
        	
        	ant->siguiente = aux->siguiente;
            delete aux;
            
        }
    }
    
}

void Lista::imprimirPalabras(){
	
	if ( !listaVacia() ){
		
		primero();
	
		while ( actual ){
			
			cout <<"\t\t-> "; 
			actual->palabra->imprimir();
			cout <<"\n";
			
			actual = actual->siguiente;
		
		}
		
	}
	
}

void Lista::imprimirPaginas(){
	
	if ( !listaVacia() ){
		
		primero();
	
		while ( actual ){
			
			actual->palabra->imprimir();
			cout << "\n\n";
			actual->palabra->mostrarPaginas();
			cout << "\n\n";
			actual = actual->siguiente;
		
		}
		
	}
	
}

void Lista::imprimirLineas(){
	
	if ( !listaVacia() ){
		
		primero();
	
		while ( actual ){

			actual->palabra->imprimir();
			cout << "\n\n";
			actual->palabra->mostrarLineas();
			cout << "\n\n";
			actual = actual->siguiente;
		
		}
	
	}
	
}

Lista::~Lista(){
	
    Nodo* aux;

    while ( principio ){
    	
        aux = principio;
        principio = principio->siguiente;
        delete aux;
        
    }
    
	elementos = 0;
    actual = NULL;

}
