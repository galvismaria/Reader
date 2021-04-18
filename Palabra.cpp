#include "Palabra.h"

Palabra::Palabra( string palabra, int capitulo, int linea ){
	
	this->palabra = palabra;
	this->capitulo = capitulo;
	this->linea = linea;
	contCapitulo = 0;
	contLinea = 0;	
	
}

string Palabra::getPalabra(){
	
	return palabra;
	
}

int Palabra::getCapitulo(){
	
	return capitulo;
	
}

int Palabra::getLinea(){
	
	return linea;
	
}

int Palabra::getContLinea(){
	
	return contLinea;
	
}

int Palabra::getContCapitulo(){
	
	return contCapitulo;
	
}
