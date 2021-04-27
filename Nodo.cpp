#include "Nodo.h"

Nodo::Nodo( Palabra *p ){
	
	info = p;
	altura = 0;
	der = nullptr;
	izq = nullptr;
	padre = nullptr;
	
}

int Nodo::getBalance(){
	
	int result;
	
	if ( izq == nullptr ){
		
		if ( der == nullptr )
			result = 0;
		
		else
			result = -der->altura - 1;
		
	}
		
	else if ( der == nullptr )	
		result = izq->altura + 1;
	
	else
		result = izq->altura - der->altura;
	
	return result;

}

Palabra* Nodo::getInfo(){
	
	return info;
	
}

int Nodo::getAltura(){
	
	return altura;
	
}

Nodo* Nodo::getDerecha(){
	
	return der;
	
}

Nodo* Nodo::getIzquierda(){
	
	return izq;
	
}

Nodo* Nodo::getPadre(){
	
	return padre;
	
}

void Nodo::quitarPadre(){
	
	padre = nullptr;
	
}

Nodo* Nodo::setIzquierda(Nodo *nuevoIzq){
	
	if ( nuevoIzq != nullptr )
		nuevoIzq->padre = this;
		
	izq = nuevoIzq;
	
	actualizarAltura();
	
	return izq;
}

Nodo* Nodo::setDerecha( Nodo *nuevoDer ){
	
	if ( nuevoDer != nullptr )
		nuevoDer->padre = this;
		
	der = nuevoDer;
	
	actualizarAltura();
	
	return der; 
	
}

int Nodo::actualizarAltura(){
	
	if ( izq == nullptr ){
		
		if ( der == nullptr )
			altura = 0;
		
		else
			altura = der->altura + 1;
		
	}
	
	else if ( der == nullptr )
		altura = izq->altura + 1;
		
	else if ( izq->altura > der->altura )
		altura = izq->altura + 1;
		
	else
		altura = der->altura + 1;
		
	return altura;
	
}

Nodo::~Nodo(){
	
	delete [] info;
	delete &altura;
	delete [] der;
	delete [] izq;
	delete [] padre;
	
}
