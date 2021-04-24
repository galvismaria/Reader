#include "Articulo.h"

Articulo::Articulo(){

	arbolPalabras = new ArbolAVL();
	tablaCapitulos = new Hash();
	tablaAlfabetica = new Hash();

}

void Articulo::insertarPalabra( string palabra, int linea, int pagina ){
	
	arbolPalabras->insertarNodo( new Palabra (palabra, linea, pagina), linea, pagina );
	
}

void Articulo::crearTablaAlfabeticaAux( Nodo *nodo, bool esRaiz ){
	
	if ( esRaiz )
		nodo = arbolPalabras->getRaiz();
	
	if ( nodo->getIzquierda() )
		crearTablaAlfabeticaAux( nodo->getIzquierda(), false );
	
	if ( nodo->getInfo()->getPalabra() != "\0" )
		tablaCapitulos->insertar( nodo->getInfo() );
	
	if ( nodo->getDerecha() )
		crearTablaAlfabeticaAux( nodo->getDerecha(), false );
	
}

void Articulo::crearTablaCapitulosAux( Nodo *nodo, bool esRaiz, int capitulo ){
	
	if ( esRaiz )
		nodo = arbolPalabras->getRaiz();
	
	if ( nodo->getIzquierda() )
		crearTablaCapitulosAux( nodo->getIzquierda(), false, capitulo );
	
	if ( nodo->getInfo()->getPalabra() != "\0" )
		tablaCapitulos->insertar( nodo->getInfo(), capitulo );
	
	if ( nodo->getDerecha() )
		crearTablaCapitulosAux( nodo->getDerecha(), false, capitulo );
	
}

void Articulo::crearTablaAlfabetica(){
	
	crearTablaAlfabeticaAux( arbolPalabras->getRaiz() , true );
	tablaCapitulos->imprimir();
	
}

void Articulo::crearTablaCapitulos(){
	
	crearTablaCapitulosAux( arbolPalabras->getRaiz() , true, 0 );
	
}

void Articulo::imprimirTablaAlfabetica(){
	
	tablaAlfabetica->imprimir();
	
}

void Articulo::imprimirTablaCapitulos(  ){
	
	tablaCapitulos->imprimir();
	
}


