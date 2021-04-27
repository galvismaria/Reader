#include "ArbolAVL.h"

ArbolAVL::ArbolAVL(){
	
	raiz = nullptr;
	
}

ArbolAVL::ArbolAVL( Palabra *p ){
	
	raiz = new Nodo( p );
	
}

void ArbolAVL::balancearEnNodo( Nodo *n ){
	
	int bal = n->getBalance();
	
	if ( bal > 1 ){
		
		if ( n->getIzquierda()->getBalance() < 0 )
			rotarIzquierda( n->getIzquierda() );
		rotarDerecha( n );
		
	} else if ( bal < -1 ){
		
		if ( n->getDerecha()->getBalance() > 0 )
			rotarDerecha( n->getDerecha() );
		rotarIzquierda( n );
		
	}
	
}

Nodo* ArbolAVL::encontrarNodo( string palabra ){
	
	Nodo *temp = raiz;
	
	while ( temp != nullptr ){
		
		if ( palabra == temp->getInfo()->getPalabra() )
			break;
			
		else if ( tolower( palabra.at( 0 ) ) < tolower( temp->getInfo()->getPalabra().at( 0 ) ) )
			temp = temp->getIzquierda();
		
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

bool ArbolAVL::insertarNodo( Palabra *palabra, int linea, int pagina ){
	
	if ( raiz == nullptr )
		raiz = new Nodo( palabra );
		
	Nodo *nuevoNodo = nullptr;
	Nodo *temp = raiz;
	
	while ( temp != nullptr && nuevoNodo == nullptr ){
		
		if ( palabra->getPalabra() < temp->getInfo()->getPalabra() ){
			
			if ( temp->getIzquierda() == nullptr )
				nuevoNodo = temp->setIzquierda( new Nodo( palabra ) );
				
			else
				temp = temp->getIzquierda();
			
		} else if ( palabra->getPalabra() > temp->getInfo()->getPalabra() ){
			
			if ( temp->getDerecha() == nullptr )
				nuevoNodo = temp->setDerecha( new Nodo( palabra ) );
					
			else
				temp = temp->getDerecha();
			
		} else if ( palabra->getPalabra() == temp->getInfo()->getPalabra() ){
			
			temp->getInfo()->agregarPagina( pagina );
			temp->getInfo()->agregarLinea( linea );
			
			return false;
		}
		
	}
		
	
	temp = nuevoNodo;
	
	while ( temp != nullptr ){
		
		temp->actualizarAltura();
		balancearEnNodo( temp );
		temp = temp->getPadre();
		
	}
	
	return true;
	
}

bool ArbolAVL::quitarNodo( string palabra ){
	
	Nodo *quitar = encontrarNodo( palabra );
	
	if ( quitar == nullptr )
		return false;
		
	enum { izquierda, derecha } lado;
	
	Nodo *p = quitar->getPadre();
	
	if ( p != nullptr && p->getIzquierda() == quitar )
		lado = izquierda;
	
	else
		lado = derecha;
		
	if ( quitar->getIzquierda() == nullptr ){
		
		if ( quitar->getDerecha() == nullptr ){
			
			if ( p == nullptr ){
				
				setRaiz( nullptr );
				delete quitar;
				
			} else{
				
				if ( lado == izquierda )
					p->setIzquierda( nullptr );
				
				else
					p->setDerecha( nullptr );
					
				delete quitar;		
				p->actualizarAltura();
				balancearEnNodo( p );
				
			}
			
		} else{
			
			if ( p == nullptr ){
				
				setRaiz( quitar->getDerecha() );
				delete quitar;
				
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
	
	else if ( quitar->getDerecha() == nullptr ){
		
		if ( p == nullptr ){
			
			setRaiz( quitar->getIzquierda() );
			delete quitar;
			
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
	
	else {
		
		Nodo *rplz;
		Nodo *rplzPadre;
		Nodo *temp;
		
		int bal = quitar->getBalance();
		
		if ( bal > 0 ){
			
			if ( quitar->getIzquierda()->getDerecha() == nullptr ){
				
				rplz = quitar->getIzquierda();
				rplz->setDerecha( quitar->getDerecha() );
				temp = rplz;
				
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
			
		} else if ( quitar->getDerecha()->getIzquierda() == nullptr ){
			
			rplz = quitar->getDerecha();
			rplz->setIzquierda( quitar->getIzquierda() );
			temp = rplz;
			
			
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
		
		if ( p == nullptr )
			setRaiz( rplz );
			
		else if ( lado == izquierda )
			p->setIzquierda( rplz );
		
		else
			p->setDerecha( rplz );
			
		delete quitar;
		balancearEnNodo( temp );
		
	}
	
	return true;
	
}

void ArbolAVL::rotarIzquierda( Nodo *n ){
	
	enum { izquierda, derecha } lado;
	
	Nodo *p = n->getPadre();
	
	if ( p != nullptr && p->getIzquierda() == n )
		lado = izquierda;
		
	else
		lado = derecha;
		
	Nodo *temp = n->getDerecha();
	n->setDerecha( temp->getIzquierda() );
	temp->setIzquierda( n );
	
	if ( p == nullptr )
		setRaiz( temp );
		
	else if ( lado == izquierda )
		p->setIzquierda( temp );
		
	else
		p->setDerecha( temp );
	
}

void ArbolAVL::rotarDerecha( Nodo *n ){
	
	enum { izquierda, derecha } lado;
	
	Nodo *p = n->getPadre();
	
	if ( p != nullptr && p->getIzquierda() == n )
		lado = izquierda;
		
	else
		lado = derecha;
		
	Nodo *temp = n->getIzquierda();
	n->setIzquierda( temp->getDerecha() );
	temp->setDerecha( n );
	
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

void ArbolAVL::inOrden( Nodo *nodo, bool esRaiz ){
	
	if( esRaiz )
		nodo = raiz;
		
	if( nodo->getIzquierda() )
		inOrden( nodo->getIzquierda(), false );
   
	cout << nodo->getInfo()->getPalabra() << endl;
	
	if( nodo->getDerecha() )
		inOrden( nodo->getDerecha(), false );
   
}

int ArbolAVL::palabrasUnicas( Nodo *nodo, int cont ){
	
	if ( nodo != nullptr ){
		
		cont = palabrasUnicas ( nodo->getIzquierda(), cont ) + palabrasUnicas( nodo->getDerecha(), cont );
		
		if ( nodo->getInfo()->esUnica() )
			cont++;
		
	}
		
	return cont; 
   
}

void ArbolAVL::imprimirInOrden(){
	
	inOrden( raiz, true );
	
}

ArbolAVL::~ArbolAVL(){
	
	delete [] raiz;
	
}
