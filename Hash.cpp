#include "Hash.h"

// Constructor - Incialización de los atributos

Hash::Hash(){
	
	for ( int i = 0 ; i < MAX_HASH ; i++ )
		tabla[i] = new Lista();
	
}

// Función hashing para una tabla alfabetica

// Genera una clave a partir de la letra inicial de la palabra

// Si la palabra inicia por la letra 'a', devuelve la clave 0, que dirige a la primera casilla de la tabla
// Si la palabra inicia por la letra 'b', devuelve la clave 1, que dirige a la segunda casilla de la tabla
// Si la palabra inicia por la letra 'c', devuelve la clave 2, que dirige a la tercera casilla de la tabla
// y así sucesivamente...

int Hash::hashing( string palabra ){
	
		
	return ( toupper( palabra.at( 0 ) ) - 'A' );
	
	
}

// Función hashing para una tabla de capitulos

// Genera una clave a partir del capítulo donde esté la palabra

// Si la palabra se encuentra en el capítulo 0, devuelve la clave 0, que dirige a la primera casilla de la tabla
// Si la palabra se encuentra en el capítulo 1, devuelve la clave 1, que dirige a la segunda casilla de la tabla
// Si la palabra se encuentra en el capítulo 2, devuelve la clave 2, que dirige a la tercera casilla de la tabla
// y así sucesivamente...

int Hash::hashing( int capitulo ){
	
	if ( capitulo >= 0 ){
		
		return capitulo ;
		
	}
	
}

// Genera una clave para una tabla alfabetica e inserta el elemento en la lista de la casilla correspondiente a la clave

void Hash::insertar( Palabra *palabra ){
	
	int hashClave = hashing( palabra->getPalabra() );
	

	
	if (hashClave >= 0 && hashClave < MAX_HASH ){
		
		tabla[hashClave]->insertarNodo( palabra );
		
	}

}

// Genera una clave para una tabla de capitulos e inserta el elemento en la lista de la casilla correspondiente a la clave

void Hash::insertar( Palabra *palabra, int capitulo ){
	
	int hashClave = hashing( capitulo );
	
	if (hashClave >= 0 && hashClave < MAX_HASH ){
		
		tabla[hashClave]->insertarNodo( palabra );
		
	}
	
}

// Genera una clave para una tabla alfabetica y elimina el elemento de la lista de la casilla correspondiente a la clave

void Hash::eliminar( Palabra *palabra ){
	
	int hashClave = hashing( palabra->getPalabra() );
	
	if (hashClave >= 0 && hashClave < MAX_HASH ){
		
		tabla[hashClave]->borrar( palabra->getPalabra() );
		
	}
	
}

// Genera una clave para una tabla de capitulos y elimina el elemento de la lista de la casilla correspondiente a la clave

void Hash::eliminar( Palabra *palabra, int capitulo ){
	
	int hashClave = hashing( capitulo );
	
	if (hashClave >= 0 && hashClave < MAX_HASH ){
		
	tabla[hashClave]->borrar( palabra->getPalabra() );
		
	}
	
}

// Genera una clave para una tabla alfabetica y verifica si el elemento existe en la lista de la casilla correspondiente a la clave

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

// Genera una clave para una tabla de capitulos y verifica si el elemento existe en la lista de la casilla correspondiente a la clave

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

// Genera una clave para una tabla alfabetica y busca el elemento en la lista lista de la casilla correspondiente a la clave , y retorna el resultado

Palabra* Hash::buscarPalabra( string pb ){
	
	int hashClave = hashing( pb );
	Palabra *resultado;
	
	if (hashClave >= 0 && hashClave < MAX_HASH ){
		
		resultado = tabla[hashClave]->buscar( pb );
		
	}
	
	return resultado;
	
}

// Genera una clave para una tabla de capitulos y busca el elemento en la lista lista de la casilla correspondiente a la clave , y retorna el resultado

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
	
	if ( capitulo >= 0 ){
		
		cout << "\n\n\t\tCapitulo " << capitulo << "\n\n";
		
		tabla[capitulo]->imprimirPalabras();
		
	}
	
}

void Hash::mostrarCapitulos(){
	
	for ( int i = 0 ; i < MAX_HASH ; i++ ){
		
		if ( !tabla[i]->listaVacia() ){
			
			cout << "\t-> Capitulo " << i << endl;
			
		}

	}
	
}

Hash::~Hash(){
	
	delete [] tabla;
	
}
