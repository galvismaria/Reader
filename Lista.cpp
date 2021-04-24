#include "Lista.h"

Lista::Nodo::Nodo(){
	
	palabra = new Palabra();
	repeticiones = 0;
	siguiente = nullptr;
	
}

Lista::Nodo::Nodo( Palabra *p, int r, Nodo *sig ){
	
	palabra = p;
	repeticiones = r;
	siguiente = sig;
	
}

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

void Lista::insertarNodo( Palabra *pb ){

    if ( principio == nullptr ){
    
		elementos++;
		principio = new Nodo( pb, elementos, nullptr );
        
    }
	
	else{
    	
    	ultimo();
        elementos++;
        actual->siguiente = new Nodo( pb, elementos, actual->siguiente );
            
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
        	
        while ( actual->siguiente != nullptr ){
        	
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

void Lista::imprimir(){
	
	if ( !listaVacia() ){
		
		actual = principio;
	
		while ( actual != nullptr ){
		
			cout << "Palabra: " << actual->palabra->getPalabra() << endl;
			actual = actual->siguiente;
		
		}
		
	} else{
		
		cout << "Lista vacia" << endl;
		
	}
	
}

Lista::~Lista(){
	
    Nodo* aux;

    while ( principio != nullptr ){
    	
        aux = principio;
        principio = principio->siguiente;
        delete aux;
        
    }

    actual = nullptr;
}
