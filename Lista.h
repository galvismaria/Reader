#ifndef LISTA
#define LISTA

#include "Palabra.h"

using namespace std;

class Lista{
	
    private:
    	
    	/* ----- ATRIBUTOS ----- */
    	
    	class Nodo{						// Clase interna del nodo de la lista
    		
    		public:
    			
    			Palabra *palabra;		// Dato que se almacena en la lista
    			Nodo *siguiente;		// Apuntador al siguiente elemento
    			
    			Nodo();
    			Nodo(Palabra *p, Nodo *sig);
    		
		};
    	
        Nodo* principio;				// Nodo que apunta al principio de la lista
        Nodo* actual;					// Nodo que se mueve por la lista
        int elementos;					// Cantidad de elementos que hay en la lista

    public:
    	
    	/* ----- M�TODOS ----- */
		
		/* ----- Constructores ----- */
    	
        Lista();						// Constructor sin parámetros -> Crea una lista vacía
        
        /* ----- Procedimientos ----- */
        
        void insertarNodo(Palabra *pb);		// Inserta un elemento en la lista
        
        Palabra* valorActual();				// Retorna el elemento almacenado en el nodo actual de la lista
        
        int cantElementos();			// Devuelve la cantidad de elementos guardados en la lista
        
<<<<<<< HEAD
        int getRepeticiones();
        
        bool listaVacia();				// Retorna 'true' si la lista está vacía, y 'false' en caso contrario
=======
        bool listaVacia();				// Retorna 'true' si la lista est� vac�a, y 'false' en caso contrario
>>>>>>> 70c18445d6046bf2b92e557aef159853d1e917d1
        
        bool haySiguiente();			// Retorna 'true' si el siguiente nodo es válido, y 'false' en caso contrario
        
        bool hayActual();				// Retorna 'true' si el nodo actual es válido, y 'false' en caso contrario
        
        void siguiente();				// Avanza al siguiente nodo de la lista
        
        void primero();					// Se ubica en el primer nodo de la lista
        
        void ultimo();					// Se ubica al final de la lista
        
        void imprimirPalabras();
        
        void imprimirPaginas();
        
		void imprimirLineas();
		
		Palabra* buscar(string palabra);       		// Busca un nodo según el dato que se pase como parámetro

										
		void borrar(string palabra);

        /* ----- Destructor ----- */
        
        ~Lista();
        
};

#endif
