#include "Articulo.h"

Articulo::Articulo(){

	palabras = new ArbolAVL();
	tablaCapitulos = new Hash();
	tablaAlfabetica = new Hash();

}

void Articulo::crearArbol( string palabra ){
	
	palabras->insertarNodo( new Palabra (palabra) );
	
}

void Articulo::crearTablaCapitulos( Nodo *nodo, bool esRaiz, int capitulo ){
	
	if ( esRaiz )
		nodo = palabras->getRaiz();
	
	if ( nodo->getIzquierda() )
		crearTablaCapitulos( nodo->getIzquierda(), false, capitulo );
	
	tablaCapitulos->insertar( nodo->getInfo(), capitulo );
	
	if ( nodo->getDerecha() )
		crearTablaCapitulos( nodo->getDerecha(), false, capitulo );
	
}

void Articulo::crearTablaAlfabetica( Nodo *nodo, bool esRaiz ){
	
	if ( esRaiz )
		nodo = palabras->getRaiz();
	
	if ( nodo->getIzquierda() )
		crearTablaAlfabetica( nodo->getIzquierda(), false );
	
	tablaCapitulos->insertar( nodo->getInfo() );
	
	if ( nodo->getDerecha() )
		crearTablaAlfabetica( nodo->getDerecha(), false );
	
}

void Articulo::imprimirTablaCapitulos(){
	
	crearTablaCapitulos( palabras->getRaiz() , true, 1 );
	tablaCapitulos->imprimir();
	
}

void Articulo::imprimirTablaAlfabetica(){
	
	crearTablaAlfabetica( palabras->getRaiz() , true );
	tablaAlfabetica->imprimir();
	
}
