#include "Nodo.h"

// Constructor - Incializaci�n de los atributos

Nodo::Nodo( Palabra *p ){
	
	info = p;
	altura = 0;
	der = nullptr;
	izq = nullptr;
	padre = nullptr;
	
}

// Calcula el punto de balance
// -> Negativo, el lado derecho es m�s profundo
// -> Cero, ambos lados son iguales
// -> Positivo, el lado izquierdo es m�s profundo

int Nodo::getBalance(){
	
	int result;
	
	// Si no hay sub�rbol izquierdo, se verifica el derecho
	
	if ( izq == nullptr ){
		
		// Si ninguno de los sub�rboles existe, retorna cero 
		
		if ( der == nullptr )
			result = 0;
		
		// Si el sub�rbol derecho existe, se hace la altura negativa y se resta uno
		
		else
			result = -der->altura - 1;
		
	}
	
	// Si hay un sub�rbol izquierdo y no hay uno derecho, se devuelve la altura izquierda y se suma uno
		
	else if ( der == nullptr )	
		result = izq->altura + 1;
	
	// Si los dos sub�rboles existen, se restan ambas alturas y se devuelve el resultado
	
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
	
	// Si nuevoIzq existe, *este* ser� el nuevo padre
	
	if ( nuevoIzq != nullptr )
		nuevoIzq->padre = this;
	
	// En cualquier caso, el sub�rbol izquierdo ser� nuevoIzq
	
	izq = nuevoIzq;
	
	// Debe actualizarse la altura
	
	actualizarAltura();
	
	return izq;
}

Nodo* Nodo::setDerecha( Nodo *nuevoDer ){
	
	// Si nuevoDer existe, *este* ser� el nuevo padre
	
	if ( nuevoDer != nullptr )
		nuevoDer->padre = this;
	
	// En cualquier caso, el sub�rbol derecho ser� nuevoDer
	
	der = nuevoDer;
	
	// Debe actualizarse la altura
	
	actualizarAltura();
	
	return der; 
	
}

int Nodo::actualizarAltura(){
	
	// Si no hay un sub�rbol izquierdo, se verifica del derecho
	
	if ( izq == nullptr ){
		
		// Si no hay un sub�rbol derecho, la altura es igual a 0
		
		if ( der == nullptr )
			altura = 0;
		
		// En otro caso, solo se encuentra el sub�rbol derecho, as� que nuestra altura es su altura m�s uno
		
		else
			altura = der->altura + 1;
		
	}
	
	// Si el sub�rbol izquiero existe pero el derecho no, nuestra altura es la altura del �rbol izquierdo m�s uno
	
	else if ( der == nullptr )
		altura = izq->altura + 1;
	
	// Si los dos sub�rboles existen y la altura de la izquierda es mayor que la de la derecha, nuestra altura es la altura del �rbol izquierdo m�s uno
	
	else if ( izq->altura > der->altura )
		altura = izq->altura + 1;
	
	// En otro caso, nuestra altura es la al altura del sub�rbol derecho m�s uno
	
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
