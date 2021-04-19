#ifndef HASH
#define HASH

#include "Lista.h"
#include "Palabra.h"

using namespace std;

class Hash{
	
	private:
		
		Lista<Palabra> *tabla[MAX_HASH];
		
		int hashing(string palabra);
		int hashing(int capitulo);
		
	public:
		
		Hash();
		void insertar(Palabra palabra);
		void insertar(Palabra palabra, int capitulo);
		
		void eliminar(string palabra);
		void eliminar(string palabra, int capitulo);
		
		bool pertenece(string palabra);
		bool pertenece(string palabra, int capitulo)
	
};

#endif
