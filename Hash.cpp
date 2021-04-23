#include "Hash.h"

Hash::Hash(){
	
	for ( int i = 0 ; i < MAX_HASH ; i++ ){
		
		
		tabla[i] = new list<Palabra>();
		
	}
	
}

int Hash::hashing( string palabra ){
	
	return (toupper(palabra.at(0)) - 'A');
	
}

int Hash::hashing( int capitulo ){
	
	return capitulo;
	
}

void Hash::insertar( Palabra palabra ){
	
	int hashClave = hashing(palabra.getPalabra());
	
	if (hashClave >= 0 && hashClave < MAX_HASH ){
		
		tabla[hashClave]->push_back( palabra );
		
	}

}

void Hash::insertar( Palabra palabra, int capitulo ){
	
	int hashClave = hashing(capitulo);
	
	if (hashClave >= 0 && hashClave < MAX_HASH ){
		
		tabla[hashClave]->push_back(palabra);
		
	}
	
}

void Hash::eliminar( Palabra palabra ){
	
	int hashClave = hashing(palabra.getPalabra());
	
	if (hashClave >= 0 && hashClave < MAX_HASH ){
		
		tabla[hashClave]->remove(palabra);
		
	}
	
}

void Hash::eliminar( Palabra palabra, int capitulo ){
	
	int hashClave = hashing(capitulo);
	
	if (hashClave >= 0 && hashClave < MAX_HASH ){
		
		tabla[hashClave]->remove(palabra);
		
	}
	
}

bool Hash::pertenece( Palabra palabra ){
	
	int hashClave = hashing(palabra.getPalabra());
	
	if (hashClave >= 0 && hashClave < MAX_HASH ){
		
		list<Palabra>::iterator it;
		it  = find(tabla[hashClave]->begin(), tabla[hashClave]->end(), palabra);
		
		if ( it != tabla[hashClave]->end() ){
			
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
	
	int hashClave = hashing(capitulo);
	
	if (hashClave >= 0 && hashClave < MAX_HASH ){
		
		list<Palabra>::iterator it;
		it  = find(tabla[hashClave]->begin(), tabla[hashClave]->end(), palabra);
		
		if ( it != tabla[hashClave]->end() ){
			
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
		
		if ( tabla[i]->front().getPalabra() != "\0" ){
			
			list<Palabra>::iterator it;
			
			for( it = tabla[i]->begin() ; it != tabla[i]->end() ; ++it )
			
				cout << "Palabra: " << it->getPalabra() << " Clave: " << i << endl; 
        		
    		cout << '\n';
			
		}
		
	}
	
}
