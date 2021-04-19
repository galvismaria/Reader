#include "Hash.h"

Hash::Hash(){
	
	for ( int i = 0 ; i < MAX_HASH ; i++ )
		tabla[i] = NULL;
	
}

void Hash::hashing( string palabra ){
	
	return ( toupper( palabra.at( 0 ) ) - A );
	
}

void Hash::hasing( int capitulo ){
	
	return capitulo;
	
}

void Hash::insertar( Palabra palabra ){
	
	int hashClave = hashing( palabra->getPalabra() );
	
	if (hashClave >= 0 && hashClave < MAX_HASH ){
		
		hashTabla[hashClave]->insertar(palabra);
		
	}

}

void Hash::insertar( Palabra palabra, int capitulo ){
	
	int hashClave = hashing( capitulo );
	
	if (hashClave >= 0 && hashClave < MAX_HASH ){
		
		hashTabla[hashClave]->insertar(palabra);
		
	}
	
}

void Hash::eliminar( Palabra palabra ){
	
	int hashClave = hashing( palabra->getPalabra() );
	
	if (hashClave >= 0 && hashClave < MAX_HASH ){
		
		hashTabla[hashClave]->borrar( palabra->getPalabra() );
		
	}
	
}

void Hash::eliminar( Palabra palabra, int capitulo ){
	
	int hashClave = hashing( capitulo );
	
	if (hashClave >= 0 && hashClave < MAX_HASH ){
		
		hashTabla[hashClave]->borrar( palabra->getPalabra() );
		
	}
	
}

bool Hash::pertenece( Palabra palabra ){
	
	int hashClave = hashing( palabra->getPalabra() );
	
	if (hashClave >= 0 && hashClave < MAX_HASH ){
		
		Palabra temp = hashTabla[hashClave]->buscar( palabra );
		
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

bool Hash::pertenece( Palabra palabra, int capitulo ){
	
	int hashClave = hashing( capitulo );
	
	if (hashClave >= 0 && hashClave < MAX_HASH ){
		
		Palabra temp = hashTabla[hashClave]->buscar( palabra );
		
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
