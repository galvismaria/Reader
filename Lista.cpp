#include "Lista.h"

Lista::Lista(){
	
    principio = actual = nullptr;
    elementos = 0;
    
}

bool Lista::listaVacia(){
	
    return principio == nullptr;
    
}

bool Lista::hayActual(){
	
	return actual != nullptr;
	
}

void Lista::insertar( Palabra *pb ){
	
	Nodo* temp;

    if ( listaVacia() ){
    	
        principio = new Nodo();
        principio->siguiente = nullptr;
        principio->palabra = pb;
        elementos++;
        principio->repeticiones++;
        
    } else if ( buscar( pb->getPalabra() )->getPalabra() == pb->getPalabra() ){
    	
    	temp = principio;
	
		while ( temp != nullptr ){
		
			if ( temp->palabra->getPalabra() == pb->getPalabra() ){
			
				temp->repeticiones++;
			
			}
		
			temp = temp->siguiente;
		}
    	
	} else{
    	
        ultimo();
        actual->siguiente = new Nodo();
        actual->siguiente = actual->siguiente;
        actual->siguiente->palabra = pb;
        elementos++;
        actual->repeticiones++;
        
    }
	
}

void Lista::siguiente(){
	
    if ( actual != nullptr )
    
        actual = actual->siguiente;
        
}

bool Lista::haySiguiente(){
	
	return ( actual->siguiente == nullptr) ;
	
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

int Lista::getRepeticiones(){
	
	return actual->repeticiones;
	
}

Palabra* Lista::buscar( string palabra ){
	
	Nodo* aux = principio;
	
	while ( aux != nullptr ){
		
		if ( aux->palabra->getPalabra() == palabra ){
			
			return aux->palabra;
			
		}
		
		aux = aux->siguiente;
	}
	
}

void Lista::borrar(string palabra){
	
    Nodo *ant, *aux;

    aux = principio;
    ant = nullptr;
    
    while ( aux != nullptr && aux->palabra->getPalabra() != palabra){
    	
        ant = aux;
        aux = aux->siguiente;
        
    }

    if( aux == nullptr || aux->palabra->getPalabra() != palabra){
        return;
        
    }else{

        if ( ant == nullptr){
        	
            principio = aux->siguiente;
            
        } else{
        	
        	ant->siguiente = aux->siguiente;
            delete aux;
            
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

    actual = nullptr;
}
