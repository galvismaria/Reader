#include "Hash.h"

Hash::Hash(){
	
	for ( int i = 0 ; i < MAX_HASH ; i++ )
		tabla[i] = new Lista<Palabra>;
	
}

int Hash::hashing( string palabra ){
	
	return ( toupper( palabra.at( 0 ) ) - 'A' );
	
}

int Hash::hashing( int capitulo ){
	
	return capitulo;
	
}

void Hash::insertar( Palabra palabra ){
	
	int hashClave = hashing( palabra.getPalabra() );
	
	if (hashClave >= 0 && hashClave < MAX_HASH ){
		
		tabla[hashClave]->insertar(palabra);
		
	}

}

void Hash::insertar( Palabra palabra, int capitulo ){
	
	int hashClave = hashing( capitulo );
	
	if (hashClave >= 0 && hashClave < MAX_HASH ){
		
		tabla[hashClave]->insertar(palabra);
		
	}
	
}

void Hash::eliminar( Palabra palabra ){
	
	int hashClave = hashing( palabra.getPalabra() );
	
	if (hashClave >= 0 && hashClave < MAX_HASH ){
		
		tabla[hashClave]->borrar( palabra );
		
	}
	
}

void Hash::eliminar( Palabra palabra, int capitulo ){
	
	int hashClave = hashing( capitulo );
	
	if (hashClave >= 0 && hashClave < MAX_HASH ){
		
	tabla[hashClave]->borrar( palabra );
		
	}
	
}

bool Hash::pertenece( Palabra palabra ){
	
	int hashClave = hashing( palabra.getPalabra() );
	
	if (hashClave >= 0 && hashClave < MAX_HASH ){
		
		Palabra temp = tabla[hashClave]->buscar( palabra );
		
		if ( temp.getPalabra() == palabra.getPalabra() ){
			
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
		
		Palabra temp = tabla[hashClave]->buscar( palabra );
		
		if ( temp.getPalabra() == palabra.getPalabra() ){
			
			return true;
			
		}
		
		else{
			
			return false;
			
		}
		
	} else{
		
		return false;
		
	}
	
}

void Hash::imprimir(){
	
	for ( int i = 0 ; i < MAX_HASH ; i++ ){
		
		if ( tabla[i]->getRepeticiones() > 0 ){
			
			tabla[i]->primero();
			
			while ( tabla[i]->hayActual() ){
				
				cout << "Palabra: " << tabla[i]->valorActual().getPalabra() << " Clave: " << i << endl;
				
			}
						
		}
		
	}
	
}
