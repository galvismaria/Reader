#include "Hash.h"

Hash::Hash(){
	
	for ( int i = 0 ; i < MAX_HASH ; i++ )
		tabla[i] = new Lista();
	
}

int Hash::hashing( string palabra ){
	
		
	return ( toupper( palabra.at( 0 ) ) - 'A' );
	
	
}

int Hash::hashing( int capitulo ){
	
	if ( capitulo > 0 ){
		
		return capitulo - 1 ;
		
	}
	
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

Palabra* Hash::buscarPalabra( string pb ){
	
	int hashClave = hashing( pb );
	Palabra *resultado;
	
	if (hashClave >= 0 && hashClave < MAX_HASH ){
		
		resultado = tabla[hashClave]->buscar( pb );
		
	}
	
	return resultado;
	
}

Palabra* Hash::buscarPalabra( string pb, int capitulo ){
	
	int hashClave = hashing( capitulo );
	Palabra *resultado;
	
	if (hashClave >= 0 && hashClave < MAX_HASH ){
		
		resultado = tabla[hashClave]->buscar( pb );
		
	}
	
	return resultado;
	
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

void Hash::imprimirCapitulo( int capitulo ){
	
	if ( capitulo > 0 ){
		
		cout << "\n\n\t\tCapitulo " << capitulo << "\n\n";
		
		tabla[capitulo - 1]->imprimirPalabras();
		
	}
	
}

void Hash::mostrarCapitulos(){
	
	for ( int i = 0 ; i < MAX_HASH ; i++ ){
		
		if ( !tabla[i]->listaVacia() ){
			
			cout << "\t-> Capitulo " << i+1 << endl;
			
		}

	}
	
}

Hash::~Hash(){
	
	delete [] tabla;
	
}
