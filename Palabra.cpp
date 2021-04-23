#include "Palabra.h"

Palabra::Par::Par(){
	
	elemento = 0;
	repeticiones = 0;
	
}

Palabra::Par::Par( int elemento, int repeticiones ){
	
	this->elemento = elemento;
	this->repeticiones = repeticiones;
	
}

Palabra::Par::Par( const Par &p ){
	
	elemento = p.elemento;
	repeticiones = p.repeticiones;
	
}

void Palabra::Par::setElemento( int elemento ){
	
	this->elemento = elemento;
	
}

void Palabra::Par::incrementarRepeticiones(){
	
	repeticiones++;
	
}

int Palabra::Par::getElemento(){
	
	return elemento;
	
}

int Palabra::Par::getRepeticiones(){
	
	return repeticiones;
	
}

Palabra::Palabra(){
	
	palabra = "\0";
	paginas = new list<Par>();
	lineas = new list<Par>();
	
}

Palabra::Palabra( string palabra, int pagina, int linea ){
	
	paginas = new list<Par>();
	lineas = new list<Par>();
	
	Par pag(pagina, 1);
	Par ln(linea, 1);
	
	this->palabra = palabra;
	paginas->push_back(pag);
	lineas->push_back(ln);
	
}

Palabra::Palabra(const Palabra &newPalabra){
	
	palabra = newPalabra.palabra;
	paginas = newPalabra.paginas;
	lineas = newPalabra.lineas;
	
}

string Palabra::getPalabra(){
	
	return palabra;
	
}

void Palabra::imprimir(){
	
	cout << palabra << endl;
	
}

bool Palabra::operator == (Palabra p) const{
	
	return palabra == p.getPalabra();
	
}

bool Palabra::operator != (Palabra p) const{
	
	return palabra != p.getPalabra();
	
}

