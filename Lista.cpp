#include "Lista.h"

template <typename T>
Lista<T>::Lista(){
	
    principio = actual = nullptr;
    elementos = 0;
    repeticiones = 0;
    
}

template <typename T>
bool Lista<T>::listaVacia(){
	
    return principio == nullptr;
    
}

template <typename T>
bool Lista<T>::hayActual(){
	
	return actual != nullptr;
	
}

template <typename T>
void Lista<T>::insertar( T info ){
	
	Nodo* temp;

    if ( listaVacia() ){
    	
        principio = new Nodo();
        principio->siguiente = nullptr;
        principio->info = info;
        elementos++;
        repeticiones++;
        
    } else if ( buscar( info ) == info ){
    	
    	temp = principio;
	
		while ( temp != nullptr ){
		
			if ( temp->info == info ){
			
				temp->repeticiones++;
			
			}
		
			temp = temp->siguiente;
		}
    	
	} else{
    	
    	
        ultimo();
        actual->siguiente = new Nodo();
        actual->siguiente = actual->siguiente;
        actual->siguiente->info = info;
        elementos++;
        repeticiones++;
        
    }
	
}

template <typename T>
void Lista<T>::siguiente(){
	
    if ( actual != nullptr )
    
        actual = actual->siguiente;
        
}

template <typename T>
bool Lista<T>::haySiguiente(){
	
	return ( actual->siguiente == nullptr) ;
	
}

template <typename T>
void Lista<T>::primero(){
	
    actual = principio;
    
}

template <typename T>
void Lista<T>::ultimo(){
	
    primero();
    
    if ( !listaVacia() ){
        	
        while ( actual->siguiente ){
        	
        	siguiente();
        	
		}
        	
	}
                
}

template <typename T>
T* Lista<T>::valorActual(){
	
    return actual->info;
    
}

template <typename T>
int Lista<T>::cantElementos(){
	
    return elementos;
    
}

template <typename T>
int Lista<T>::getRepeticiones(){
	
	return actual->repeticiones;
	
}

template <typename T>
void Lista<T>::imprimir(){
	
	Nodo* aux = principio;
	
	while ( aux != nullptr ){
		
		aux->info->mostrarInfo();
		aux = aux->siguiente;
	}
	
}

template <typename T>
T Lista<T>::buscar( T info ){
	
	Nodo* aux = principio;
	
	while ( aux != nullptr ){
		
		if ( aux->info == info ){
			
			return aux->info;
			
		}
		
		aux = aux->siguiente;
	}
	
	return nullptr;
	
}

template <typename T>
void Lista::borrar(T info){
	
    Nodo *ant, *aux;

    aux = princio;
    ant = nullptr;
    
    while ( aux != nullptr && aux->info != info){
    	
        ant = aux;
        aux = aux->siguiente;
        
    }

    if( aux == nullptr || aux->info != info){
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

template <typename T>
Lista<T>::~Lista(){
	
    Nodo* aux;

    while ( principio ){
    	
        aux = principio;
        principio = principio->siguiente;
        delete aux;
        
    }

    actual = NULL;
}
