#ifndef HASH
#define HASH

#include "Palabra.h"
#include <list>
#include <algorithm>

using namespace std;

class Hash{
	
	private:
		
		list<Palabra> *tabla[MAX_HASH];
		
		int hashing(string palabra);
		int hashing(int capitulo);
		
	public:
		
		Hash();
		void insertar(Palabra palabra);
		void insertar(Palabra palabra, int capitulo);
		
		void eliminar(Palabra palabra);
		void eliminar(Palabra palabra, int capitulo);
		
		bool pertenece(Palabra palabra);
		bool pertenece(Palabra palabra, int capitulo);
		
		void imprimir();
	
};

#endif
