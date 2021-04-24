#include "Hash.h"

Hash::Hash(){
	
	for ( int i = 0 ; i < MAX_HASH ; i++ )
		tabla[i] = new Lista();
	
}

int Hash::hashing( string palabra ){
	
	return ( toupper( palabra.at( 0 ) ) - 'A' );
	
}

int Hash::hashing( int capitulo ){
	
	return capitulo;
	
}

void Hash::insertar( Palabra *palabra ){
	
	int hashClave = hashing( palabra->getPalabra() );
	

	
	if (hashClave >= 0 && hashClave < MAX_HASH ){
		
		tabla[hashClave]->insertarNodo( palabra );
		
	}

}

void Hash::insertar( Palabra *palabra, int capitulo ){
	
	int hashClave = hashing( capitulo );
	
	if (hashClave >= 0 && hashClave < MAX_HASH ){
		
		tabla[hashClave]->insertarNodo( palabra );
		
	}
	
}

void Hash::eliminar( Palabra *palabra ){
	
	int hashClave = hashing( palabra->getPalabra() );
	
	if (hashClave >= 0 && hashClave < MAX_HASH ){
		
		tabla[hashClave]->borrar( palabra->getPalabra() );
		
	}
	
}

void Hash::eliminar( Palabra *palabra, int capitulo ){
	
	int hashClave = hashing( capitulo );
	
	if (hashClave >= 0 && hashClave < MAX_HASH ){
		
	tabla[hashClave]->borrar( palabra->getPalabra() );
		
	}
	
}

bool Hash::pertenece( Palabra *palabra ){
	
	int hashClave = hashing( palabra->getPalabra() );
	
	if (hashClave >= 0 && hashClave < MAX_HASH ){
		
		Palabra *temp = tabla[hashClave]->buscar( palabra->getPalabra() );
		
		if ( temp->getPalabra() == palabra->getPalabra() ){
			
			return true;
			
		}
		
		else{
			
			return false;
			
		}
		
	} else{
		
		return false;
		
	}
	
}

bool Hash::pertenece( Palabra *palabra, int capitulo ){
	
	int hashClave = hashing( capitulo );
	
	if (hashClave >= 0 && hashClave < MAX_HASH ){
		
		Palabra *temp = tabla[hashClave]->buscar( palabra->getPalabra() );
		
		if ( temp->getPalabra() == palabra->getPalabra() ){
			
			return true;
			
		}
		
		else{
			
			return false;
			
		}
		
	} else{
		
		return false;
		
	}
	
}

void Hash::imprimirPalabras(){
	
	for ( int i = 0 ; i < MAX_HASH ; i++ ){
		
		tabla[i]->imprimirPalabras();

	}
	
}

void Hash::imprimirPaginas(){
	
	for ( int i = 0 ; i < MAX_HASH ; i++ ){
		
		tabla[i]->imprimirPaginas();

	}
	
}

void Hash::imprimirLineas(){
	
	for ( int i = 0 ; i < MAX_HASH ; i++ ){
		
		tabla[i]->imprimirLineas();

	}
	
}
