#include "ArbolAVL.h"

ArbolAVL::ArbolAVL(){
	
	raiz = nullptr;
	
}

ArbolAVL::ArbolAVL( Palabra *p ){
	
	raiz = new Nodo( p );
	
}

// Balancear el sub�rbol

void ArbolAVL::balancearEnNodo( Nodo *n ){
	
	// Obtiene el balance actual
	
	int bal = n->getBalance();
	
	// Si est� muy desequilibrado hacia la izquierda, lo rota a la derecha,
  	// ajustando el sub�rbol izquierdo si es necesario
  	
	if ( bal > 1 ){
		
		if ( n->getIzquierda()->getBalance() < 0 )
			rotarIzquierda( n->getIzquierda() );
		rotarDerecha( n );
		
	// Por otr lado, si est� muy desequilibrado hacia la derecha, lo rota hacia la izquierda
	// ajustando el sub�rbol derecho si es necesario
  
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
		
		// Si el valor que se busca es menor que el actual, se verifica en el sub�rbol izquierdo
		
		else if ( tolower( palabra.at( 0 ) ) < tolower( temp->getInfo()->getPalabra().at( 0 ) ) )
			temp = temp->getIzquierda();
		
		// En otro caso, se busca en el sub�rbol derecho
		
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

// Funci�n de inserci�n

bool ArbolAVL::insertarNodo( Palabra *palabra, int linea, int pagina ){
	
	// Si el �rbol est� vac�o, se inserta el elemento como la ra�z del �rbol
	
	if ( raiz == nullptr )
		raiz = new Nodo( palabra );
	
	// Si no, se debe buscar el punto de inserci�n
	
	else{
		
		Nodo *nuevoNodo = nullptr;
		Nodo *temp = raiz;
		
		while ( temp != nullptr && nuevoNodo == nullptr ){
			
	  		// Si el valor es menor al actual valor del nodo, se va hacia la ziquierda.
			// Si no hay un sub�rbol izquierdo, se inserta el nodo; en caso contrario, este es el siguiente a verificar
			
			if ( palabra->getPalabra() < temp->getInfo()->getPalabra() ){
				
				if ( temp->getIzquierda() == nullptr )
					nuevoNodo = temp->setIzquierda( new Nodo( palabra ) );
					
				else
					temp = temp->getIzquierda();
			
	  		// Si el valor es mayor al actual valor del nodo, se va hacia la derecha.
	  		// Si no hay un sub�rbol derecho, se inserta el nodo; en caso contrario, este es el siguiente a verificar
	  		
			} else if ( palabra->getPalabra() > temp->getInfo()->getPalabra() ){
				
				if ( temp->getDerecha() == nullptr )
					nuevoNodo = temp->setDerecha( new Nodo( palabra ) );
						
				else
					temp = temp->getDerecha();
					
			// Si el valor ya est� en el �rbol, se ingresa la nueva coincidencia de la palabra (la p�gina y la l�nea) en el nodo
			
			} else if ( palabra->getPalabra() == temp->getInfo()->getPalabra() ){
				
				temp->getInfo()->agregarPagina( pagina );
				temp->getInfo()->agregarLinea( linea );
				
				return false;
			}
			
		}
		
		// Desde el nuevo nodo hasta la raiz, se actualiza la altura y se asegura que el �rbol est� balanceado	
		
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
	
	// Se obtiene el padre y se coloca el lado en el que est� el nodo con respecto al padre
	
	enum { izquierda, derecha } lado;
	
	Nodo *p = quitar->getPadre();
	
	if ( p != nullptr && p->getIzquierda() == quitar )
		lado = izquierda;
	
	else
		lado = derecha;
	
	// Si el nodo que se va a quitar no tiene un sub�rbol izquierdo, se verifica si tiene un sub�rbol derecho
	
	if ( quitar->getIzquierda() == nullptr ){
		
		// Si no hay ning�n sub�rbol, el nodo es una hoja
		
		if ( quitar->getDerecha() == nullptr ){
			
			// Si el padre no existe, el �rbol es vac�o as� que se cambia la ra�z a NULL y se quita el nodo actual
			
			if ( p == nullptr ){
				
				setRaiz( nullptr );
				delete quitar;
			
			// En otro caso, se modifica el padre para que no apunte al nodo actual, se borra el nodo
			// Luego se actualiza la altura del padre y se rebalancea el �rbol 
			
			} else{
				
				if ( lado == izquierda )
					p->setIzquierda( nullptr );
				
				else
					p->setDerecha( nullptr );
					
				delete quitar;		
				p->actualizarAltura();
				balancearEnNodo( p );
				
			}
		
		// Por otro lado, si hay un sub�rbol derecho se utiliza para reemplazar el sub�rbol actual
			
		} else{
			
			// Si el nodo no tiene padre, el �rbol es ahora el sub�rbol derecho
			// Se quita el nodo
			
			if ( p == nullptr ){
				
				setRaiz( quitar->getDerecha() );
				delete quitar;
			
			// En otro caso, se modifica el padre para que no apunte al nodo actual, se borra el nodo
			// Luego se actualiza la altura del padre y se rebalancea el �rbol
				
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
	
	// En otro caso, hay un sub�rbol izquierdo as� que se verifica el derecho
	// Si no hay un sub�rbol derecho, se utiliza el izquierdo para reemplazar el sub�rbol actual
	
	else if ( quitar->getDerecha() == nullptr ){
		
		// Si el nodo no tiene padre, el �rbol ahora es el sub�rbol izquierdo 
		// se borra el nodo
		
		if ( p == nullptr ){
			
			setRaiz( quitar->getIzquierda() );
			delete quitar;
		
		// En otro caso, se actualiza el padre para que no apunte al nodo actual
		// Se actualiza la altura del padre y se rebalancea el �rbol
			
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
	
	// Si el sub�rbol tiene ambos sub�rboles
	
	else {
		
		// Se verifica el balance para saber hacia qu� lado avanzar
		// Si el lado izquierdo es m�s profundo, se modifica
		
		Nodo *rplz;
		Nodo *rplzPadre;
		Nodo *temp;
		
		int bal = quitar->getBalance();
		
		if ( bal > 0 ){
			
			// Si el sub�rbol derecho del sub�rbol izquierdo del nodo est� vac�o,
			// se puede mover el sub�rbol derecho del nodo all�
			
			if ( quitar->getIzquierda()->getDerecha() == nullptr ){
				
				rplz = quitar->getIzquierda();
				rplz->setDerecha( quitar->getDerecha() );
				temp = rplz;
			
			// En otro caso, se busca el sub�rbol derecho vac�o m�s profundo
			// del sub�rbol izquierdo del nodo
			// Ese ser� el reemplazo, as� que su padre apuntar� a su hizo izquierdo
			// para poder reemplazar el nodo
			// Se copian ambos sub�rboles del nodo borrado dentro del reemplazo
			
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
			
		// En otro caso, se modificar� el lado derecho
		// Si el sub�rbol izquierdo del sub�rbol derecho del nodo est� vac�o,
		// se avanza hacia el sub�rbol izquierdo
			
		} else if ( quitar->getDerecha()->getIzquierda() == nullptr ){
			
			rplz = quitar->getDerecha();
			rplz->setIzquierda( quitar->getIzquierda() );
			temp = rplz;
		
		// En otro caso, se busca el sub�rbol izquierdo vac�o m�s profundo
		// del sub�rbol derecho del nodo
		// Ese ser� el reemplazo, as� que su padre apuntar� a su hizo derecho
		// para poder reemplazar el nodo
		// Se copian ambos sub�rboles del nodo borrado dentro del reemplazo
		
			
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
		
		// Se arregla el padre para que apunte a la nueva ra�z.
		// Si no hay un padre, se actualiza la actual raiz del �rbol

		if ( p == nullptr )
			setRaiz( rplz );
		
		// En otro caso, hay un padre as� que si se est� actualmente en el sub�rbol izquierdo se actualiza
		
		else if ( lado == izquierda )
			p->setIzquierda( rplz );
		
		// Si no, se actualiza el sub�rbol de la derecha
		
		else
			p->setDerecha( rplz );
		
		// En cualquier caso, se borra el nodo y se rebalancea del �rbol
		
		delete quitar;
		balancearEnNodo( temp );
		
	}
	
	return true;
	
}

// Rotar el sub�rbol hacia la izquierda

void ArbolAVL::rotarIzquierda( Nodo *n ){
	
	
	// Se obtiene el padre del nodo. Si existe y el nodo es su sub�rbol izquierdo,
	// se hace una marca para tener en cuenta que se est� procesando la izquierda
	// o la derecha, en caso contrario
	
	enum { izquierda, derecha } lado;
	
	Nodo *p = n->getPadre();
	
	if ( p != nullptr && p->getIzquierda() == n )
		lado = izquierda;
		
	else
		lado = derecha;
	
	// Se coloca el sub�rbol derecho como la nueva ra�z
	// El sub�rbol izquierdo para a ser el sub�rbol derecho del nodo
	// el nodo original pasa a ser el sub�rbol izquierdo de la nueva ra�z
	
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
	
	// Se obtiene el padre del nodo. Si existe y el nodo es su sub�rbol izquierdo,
	// se hace una marca para tener en cuenta que se est� procesando la izquierda
	// o la derecha, en caso contrario
	
	enum { izquierda, derecha } lado;
	
	Nodo *p = n->getPadre();
	
	if ( p != nullptr && p->getIzquierda() == n )
		lado = izquierda;
		
	else
		lado = derecha;
		
	// Se coloca el sub�rbol izquierdo como la nueva ra�z
	// El sub�rbol derecho para a ser el izquierdo derecho del nodo
	// el nodo original pasa a ser el sub�rbol derecho de la nueva ra�z
		
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

// Recorrido in orden del �rbol

void ArbolAVL::inOrden( Nodo *nodo, bool esRaiz ){
	
	if( esRaiz )
		nodo = raiz;
		
	if( nodo->getIzquierda() )
		inOrden( nodo->getIzquierda(), false );
   
	cout << nodo->getInfo()->getPalabra() << endl;
	
	if( nodo->getDerecha() )
		inOrden( nodo->getDerecha(), false );
   
}

// Devuelve la cantidad de palabras �nicas que se encuentran en el �rbol

int ArbolAVL::palabrasUnicas( Nodo *nodo, int cont ){
	
	if ( nodo != nullptr ){
		
		cont = palabrasUnicas ( nodo->getIzquierda(), cont ) + palabrasUnicas( nodo->getDerecha(), cont );
		
		if ( nodo->getInfo()->esUnica() )
			cont++;
		
	}
		
	return cont; 
   
}

// Funci�n para imprimir el contenido del �rbol

void ArbolAVL::imprimirInOrden(){
	
	inOrden( raiz, true );
	
}

ArbolAVL::~ArbolAVL(){
	
	delete [] raiz;
	
}
