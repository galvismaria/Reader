#ifndef LISTA
#define LISTA

#include "Palabra.h"

/*
	
	Clase que implementa una lista simplemente enlazada, donde se almacenan palabras.
	Esta clase se usa para crear el arreglo de listas para el hashing abierto.

*/

using namespace std;

class Lista{
	
    private:
    	
    	/* ----- ATRIBUTOS ----- */
    	
    	class Nodo{								// Clase interna del nodo de la lista
    		
    		public:
    			
    			Palabra *palabra;				// Palabra que se almacena en la lista
    			Nodo *siguiente;				// Apuntador al siguiente elemento
    			
    			Nodo();
    			Nodo(Palabra *p, Nodo *sig);
    		
		};
    	
        Nodo* principio;						// Nodo que apunta al principio de la lista
        Nodo* actual;							// Nodo que se mueve por la lista
        int elementos;							// Cantidad de elementos que hay en la lista

    public:
    	
    	/* ----- M?TODOS ----- */
		
		/* ----- Constructores ----- */
    	
        Lista();								// Constructor sin parámetros -> Crea una lista vacía
        
        /* ----- Procedimientos ----- */
        
        void insertarNodo(Palabra *pb);			// Inserta un elemento en la lista
        
        Palabra* valorActual();					// Retorna el elemento almacenado en el nodo actual de la lista
        
        int cantElementos();					// Devuelve la cantidad de elementos guardados en la lista
        
        bool listaVacia();						// Retorna 'true' si la lista est? vac?a y 'false' en caso contrario
        
        bool haySiguiente();					// Retorna 'true' si el siguiente nodo es v?lido, y 'false' en caso contrario
        
        bool hayActual();						// Retorna 'true' si el nodo actual es v?lido, y 'false' en caso contrario
        
        void siguiente();						// Avanza al siguiente nodo de la lista
        
        void primero();							// Se ubica en el primer nodo de la lista
        
        void ultimo();							// Se ubica al final de la lista
        
        void imprimirPalabras();				// Imprime las palabras que se encuentran en la lista
    
        void imprimirPaginas();					// Imprime las palabras que se encuentran en la lista y muestra en qu? p?ginas aparecen
        
		void imprimirLineas();					// Imprime las palabras que se encuentran en la lista y muestra en qu? l?neas aparecen
		
		Palabra* buscar(string palabra);       	// Busca un nodo seg?n el dato que se pase como par?metro
										
		void borrar(string palabra);			// Elimina un elemento de la lista

        /* ----- Destructor ----- */
        
        ~Lista();
        
};

#endif
