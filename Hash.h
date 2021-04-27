#ifndef HASH
#define HASH

#include "Lista.h"
#include "Palabra.h"

using namespace std;

class Hash{
	
	private:
		
		Lista *tabla[MAX_HASH];
		
		int hashing(string palabra);
		int hashing(int capitulo);
		
	public:
		
		Hash();
		void insertar(Palabra *palabra);
		void insertar(Palabra *palabra, int capitulo);
		
		void eliminar(Palabra *palabra);
		void eliminar(Palabra *palabra, int capitulo);
		
		bool pertenece(Palabra *palabra);
		bool pertenece(Palabra *palabra, int capitulo);
		
		Palabra* buscarPalabra(string pb);
		Palabra* buscarPalabra(string pb, int capitulo);
		
		void imprimirPalabras();
        void imprimirPaginas();
		void imprimirLineas();
		void imprimirCapitulo( int capitulo );
		void mostrarCapitulos();
		~Hash();
	
};

#endif
