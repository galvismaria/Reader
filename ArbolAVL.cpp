#include "ArbolAVL.h"

ArbolAVL::ArbolAVL(){
	
	raiz = nullptr;
	
}

ArbolAVL::ArbolAVL( Palabra *p ){
	
	raiz = new Nodo( p );
	
}

// Balancear el subárbol

void ArbolAVL::balancearEnNodo( Nodo *n ){
	
	// Obtiene el balance actual
	
	int bal = n->getBalance();
	
	// Si está muy desequilibrado hacia la izquierda, lo rota a la derecha,
  	// ajustando el subárbol izquierdo si es necesario
  	
	if ( bal > 1 ){
		
		if ( n->getIzquierda()->getBalance() < 0 )
			rotarIzquierda( n->getIzquierda() );
		rotarDerecha( n );
		
	// Por otr lado, si está muy desequilibrado hacia la derecha, lo rota hacia la izquierda
	// ajustando el subárbol derecho si es necesario
  
	} else if ( bal < -1 ){
		
		if ( n->getDerecha()->getBalance() > 0 )
			rotarDerecha( n->getDerecha() );
		rotarIzquierda( n );
		
	}
	
}

// Encuentra el nodo que contenga el string palabra

Nodo* ArbolAVL::encontrarNodo( string palabra ){
	
	Nodo *temp = raiz;
	
	while ( temp != nullptr ){
		
		// Se busca en los nodos hasta encontrar el que se esea encontrar
		
		if ( palabra == temp->getInfo()->getPalabra() )
			break;
		
		// Si el valor que se busca es menor que el actual, se verifica en el subárbol izquierdo
		
		else if ( tolower( palabra.at( 0 ) ) < tolower( temp->getInfo()->getPalabra().at( 0 ) ) )
			temp = temp->getIzquierda();
		
		// En otro caso, se busca en el subárbol derecho
		
		else
			temp = temp->getDerecha();
		
	}
	
	return temp;
	
}

int ArbolAVL::getAltura(){
	
	return raiz->getAltura();
	
}

Nodo *ArbolAVL::getRaiz(){
	
	return raiz;
	
}

// Función de inserción

bool ArbolAVL::insertarNodo( Palabra *palabra, int linea, int pagina ){
	
	// Si el árbol está vacío, se inserta el elemento como la raíz del árbol
	
	if ( raiz == nullptr )
		raiz = new Nodo( palabra );
	
	// Si no, se debe buscar el punto de inserción
	
	else{
		
		Nodo *nuevoNodo = nullptr;
		Nodo *temp = raiz;
		
		while ( temp != nullptr && nuevoNodo == nullptr ){
			
	  		// Si el valor es menor al actual valor del nodo, se va hacia la ziquierda.
			// Si no hay un subárbol izquierdo, se inserta el nodo; en caso contrario, este es el siguiente a verificar
			
			if ( palabra->getPalabra() < temp->getInfo()->getPalabra() ){
				
				if ( temp->getIzquierda() == nullptr )
					nuevoNodo = temp->setIzquierda( new Nodo( palabra ) );
					
				else
					temp = temp->getIzquierda();
			
	  		// Si el valor es mayor al actual valor del nodo, se va hacia la derecha.
	  		// Si no hay un subárbol derecho, se inserta el nodo; en caso contrario, este es el siguiente a verificar
	  		
			} else if ( palabra->getPalabra() > temp->getInfo()->getPalabra() ){
				
				if ( temp->getDerecha() == nullptr )
					nuevoNodo = temp->setDerecha( new Nodo( palabra ) );
						
				else
					temp = temp->getDerecha();
					
			// Si el valor ya está en el árbol, se ingresa la nueva coincidencia de la palabra (la página y la línea) en el nodo
			
			} else if ( palabra->getPalabra() == temp->getInfo()->getPalabra() ){
				
				temp->getInfo()->agregarPagina( pagina );
				temp->getInfo()->agregarLinea( linea );
				
				return false;
			}
			
		}
		
		// Desde el nuevo nodo hasta la raiz, se actualiza la altura y se asegura que el árbol esté balanceado	
		
		temp = nuevoNodo;
		
		while ( temp != nullptr ){
			
			temp->actualizarAltura();
			balancearEnNodo( temp );
			temp = temp->getPadre();
			
		}
		
	}
	
	return true;
	
}

bool ArbolAVL::quitarNodo( string palabra ){
	
	// Se busca el nodo a eliminar y si no existe, se abandona el proceso
	
	Nodo *quitar = encontrarNodo( palabra );
	
	if ( quitar == nullptr )
		return false;
	
	// Se obtiene el padre y se coloca el lado en el que está el nodo con respecto al padre
	
	enum { izquierda, derecha } lado;
	
	Nodo *p = quitar->getPadre();
	
	if ( p != nullptr && p->getIzquierda() == quitar )
		lado = izquierda;
	
	else
		lado = derecha;
	
	// Si el nodo que se va a quitar no tiene un subárbol izquierdo, se verifica si tiene un subárbol derecho
	
	if ( quitar->getIzquierda() == nullptr ){
		
		// Si no hay ningún subárbol, el nodo es una hoja
		
		if ( quitar->getDerecha() == nullptr ){
			
			// Si el padre no existe, el árbol es vacío así que se cambia la raíz a NULL y se quita el nodo actual
			
			if ( p == nullptr ){
				
				setRaiz( nullptr );
				delete quitar;
			
			// En otro caso, se modifica el padre para que no apunte al nodo actual, se borra el nodo
			// Luego se actualiza la altura del padre y se rebalancea el árbol 
			
			} else{
				
				if ( lado == izquierda )
					p->setIzquierda( nullptr );
				
				else
					p->setDerecha( nullptr );
					
				delete quitar;		
				p->actualizarAltura();
				balancearEnNodo( p );
				
			}
		
		// Por otro lado, si hay un subárbol derecho se utiliza para reemplazar el subárbol actual
			
		} else{
			
			// Si el nodo no tiene padre, el árbol es ahora el subárbol derecho
			// Se quita el nodo
			
			if ( p == nullptr ){
				
				setRaiz( quitar->getDerecha() );
				delete quitar;
			
			// En otro caso, se modifica el padre para que no apunte al nodo actual, se borra el nodo
			// Luego se actualiza la altura del padre y se rebalancea el árbol
				
			} else{
				
				if ( lado == izquierda )
					p->setIzquierda( quitar->getDerecha() );
				
				else
					p->setDerecha( quitar->getDerecha() );
					
				delete quitar;	
				p->actualizarAltura();
				balancearEnNodo( p );
				
			}
			
		}
		
	}
	
	// En otro caso, hay un subárbol izquierdo así que se verifica el derecho
	// Si no hay un subárbol derecho, se utiliza el izquierdo para reemplazar el subárbol actual
	
	else if ( quitar->getDerecha() == nullptr ){
		
		// Si el nodo no tiene padre, el árbol ahora es el subárbol izquierdo 
		// se borra el nodo
		
		if ( p == nullptr ){
			
			setRaiz( quitar->getIzquierda() );
			delete quitar;
		
		// En otro caso, se actualiza el padre para que no apunte al nodo actual
		// Se actualiza la altura del padre y se rebalancea el árbol
			
		} else{
			
			if ( lado == izquierda )
				p->setIzquierda( quitar->getIzquierda() );
			
			else 
				p->setDerecha( quitar->getIzquierda() );
			
			delete quitar;
			p->actualizarAltura();
			balancearEnNodo( p );
		}
		
	}
	
	// Si el subárbol tiene ambos subárboles
	
	else {
		
		// Se verifica el balance para saber hacia qué lado avanzar
		// Si el lado izquierdo es más profundo, se modifica
		
		Nodo *rplz;
		Nodo *rplzPadre;
		Nodo *temp;
		
		int bal = quitar->getBalance();
		
		if ( bal > 0 ){
			
			// Si el subárbol derecho del subárbol izquierdo del nodo está vacío,
			// se puede mover el subárbol derecho del nodo allí
			
			if ( quitar->getIzquierda()->getDerecha() == nullptr ){
				
				rplz = quitar->getIzquierda();
				rplz->setDerecha( quitar->getDerecha() );
				temp = rplz;
			
			// En otro caso, se busca el subárbol derecho vacío más profundo
			// del subárbol izquierdo del nodo
			// Ese será el reemplazo, así que su padre apuntará a su hizo izquierdo
			// para poder reemplazar el nodo
			// Se copian ambos subárboles del nodo borrado dentro del reemplazo
			
			} else{
				
				rplz = quitar->getIzquierda()->getDerecha();
				
				while ( rplz != nullptr )
					rplz = rplz->getDerecha();
					
				rplzPadre = rplz->getPadre();
				rplzPadre->setDerecha( rplz->getIzquierda() );
				temp = rplzPadre;
				rplz->setIzquierda( quitar->getIzquierda() );
				rplz->setDerecha( quitar->getDerecha() );			
			}
			
		// En otro caso, se modificará el lado derecho
		// Si el subárbol izquierdo del subárbol derecho del nodo está vacío,
		// se avanza hacia el subárbol izquierdo
			
		} else if ( quitar->getDerecha()->getIzquierda() == nullptr ){
			
			rplz = quitar->getDerecha();
			rplz->setIzquierda( quitar->getIzquierda() );
			temp = rplz;
		
		// En otro caso, se busca el subárbol izquierdo vacío más profundo
		// del subárbol derecho del nodo
		// Ese será el reemplazo, así que su padre apuntará a su hizo derecho
		// para poder reemplazar el nodo
		// Se copian ambos subárboles del nodo borrado dentro del reemplazo
		
			
		} else{
			
			rplz = quitar->getDerecha()->getIzquierda();
			
			while ( rplz->getIzquierda() != nullptr )
				rplz = rplz->getIzquierda();
				
			rplzPadre = rplz->getPadre();
			rplzPadre->setIzquierda( rplz->getDerecha() );
			temp = rplzPadre;
			rplz->setIzquierda( quitar->getIzquierda() );
			rplz->setDerecha( quitar->getDerecha() );
			
		}
		
		// Se arregla el padre para que apunte a la nueva raíz.
		// Si no hay un padre, se actualiza la actual raiz del árbol

		if ( p == nullptr )
			setRaiz( rplz );
		
		// En otro caso, hay un padre así que si se está actualmente en el subárbol izquierdo se actualiza
		
		else if ( lado == izquierda )
			p->setIzquierda( rplz );
		
		// Si no, se actualiza el subárbol de la derecha
		
		else
			p->setDerecha( rplz );
		
		// En cualquier caso, se borra el nodo y se rebalancea del árbol
		
		delete quitar;
		balancearEnNodo( temp );
		
	}
	
	return true;
	
}

// Rotar el subárbol hacia la izquierda

void ArbolAVL::rotarIzquierda( Nodo *n ){
	
	
	// Se obtiene el padre del nodo. Si existe y el nodo es su subárbol izquierdo,
	// se hace una marca para tener en cuenta que se está procesando la izquierda
	// o la derecha, en caso contrario
	
	enum { izquierda, derecha } lado;
	
	Nodo *p = n->getPadre();
	
	if ( p != nullptr && p->getIzquierda() == n )
		lado = izquierda;
		
	else
		lado = derecha;
	
	// Se coloca el subárbol derecho como la nueva raíz
	// El subárbol izquierdo para a ser el subárbol derecho del nodo
	// el nodo original pasa a ser el subárbol izquierdo de la nueva raíz
	
	Nodo *temp = n->getDerecha();
	n->setDerecha( temp->getIzquierda() );
	temp->setIzquierda( n );
	
	// El padre apunta ahora a la nueva raiz
	// Si no existe el padre, se actualiza la nueva raiz
	// En otro caso, hay un padre y si se estaba procesando el lado izquierdo, se actualiza
	// Sino, se actualiza la derecha
	
	if ( p == nullptr )
		setRaiz( temp );
		
	else if ( lado == izquierda )
		p->setIzquierda( temp );
		
	else
		p->setDerecha( temp );
	
}

void ArbolAVL::rotarDerecha( Nodo *n ){
	
	// Se obtiene el padre del nodo. Si existe y el nodo es su subárbol izquierdo,
	// se hace una marca para tener en cuenta que se está procesando la izquierda
	// o la derecha, en caso contrario
	
	enum { izquierda, derecha } lado;
	
	Nodo *p = n->getPadre();
	
	if ( p != nullptr && p->getIzquierda() == n )
		lado = izquierda;
		
	else
		lado = derecha;
		
	// Se coloca el subárbol izquierdo como la nueva raíz
	// El subárbol derecho para a ser el izquierdo derecho del nodo
	// el nodo original pasa a ser el subárbol derecho de la nueva raíz
		
	Nodo *temp = n->getIzquierda();
	n->setIzquierda( temp->getDerecha() );
	temp->setDerecha( n );
	
	// El padre apunta ahora a la nueva raiz
	// Si no existe el padre, se actualiza la nueva raiz
	// En otro caso, hay un padre y si se estaba procesando el lado izquierdo, se actualiza
	// Sino, se actualiza la derecha
	
	if ( p == nullptr )
		setRaiz( temp );
		
	else if ( lado == izquierda )
		p->setIzquierda( temp );
		
	else
		p->setDerecha( temp );
	
}

void ArbolAVL::setRaiz( Nodo *n ){
	
	raiz = n;
	
	if ( raiz != nullptr )
		raiz->quitarPadre();
	
}

// Recorrido in orden del árbol

void ArbolAVL::inOrden( Nodo *nodo, bool esRaiz ){
	
	if( esRaiz )
		nodo = raiz;
		
	if( nodo->getIzquierda() )
		inOrden( nodo->getIzquierda(), false );
   
	cout << nodo->getInfo()->getPalabra() << endl;
	
	if( nodo->getDerecha() )
		inOrden( nodo->getDerecha(), false );
   
}

// Devuelve la cantidad de palabras únicas que se encuentran en el árbol

int ArbolAVL::palabrasUnicas( Nodo *nodo, int cont ){
	
	if ( nodo != nullptr ){
		
		cont = palabrasUnicas ( nodo->getIzquierda(), cont ) + palabrasUnicas( nodo->getDerecha(), cont );
		
		if ( nodo->getInfo()->esUnica() )
			cont++;
		
	}
		
	return cont; 
   
}

// Función para imprimir el contenido del árbol

void ArbolAVL::imprimirInOrden(){
	
	inOrden( raiz, true );
	
}

ArbolAVL::~ArbolAVL(){
	
	delete [] raiz;
	
}
