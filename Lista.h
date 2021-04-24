#ifndef LISTA
#define LISTA

#include "Palabra.h"

using namespace std;

class Lista{
	
    private:
    	
    	/* ----- ATRIBUTOS ----- */
    	
    	class Nodo{						// Clase interna del nodo de la lista
    		
    		public:
    			
    			Palabra *palabra;					// Dato que se almacena en la lista
    			int repeticiones;		// Indica cuantas veces se repite el elemento
    			Nodo *siguiente;		// Apuntador al siguiente elemento
    			
    			Nodo();
    			Nodo(Palabra *p, int r, Nodo *sig);
    		
		};
    	
        Nodo* principio;				// Nodo que apunta al principio de la lista
        Nodo* actual;					// Nodo que se mueve por la lista
        int elementos;					// Cantidad de elementos que hay en la lista

    public:
    	
    	/* ----- MÉTODOS ----- */
		
		/* ----- Constructores ----- */
    	
        Lista();						// Constructor sin parámetros -> Crea una lista vacía
        
        /* ----- Procedimientos ----- */
        
        void insertarNodo(Palabra *pb);			// Inserta un elemento en la lista
        
        Palabra* valorActual();				// Retorna el elemento almacenado en el nodo actual de la lista
        
        int cantElementos();			// Devuelve la cantidad de elementos guardados en la lista
        
        int getRepeticiones();
        
        bool listaVacia();				// Retorna 'true' si la lista está vacía, y 'false' en caso contrario
        
        bool haySiguiente();			// Retorna 'true' si el siguiente nodo es válido, y 'false' en caso contrario
        
        bool hayActual();				// Retorna 'true' si el nodo actual es válido, y 'false' en caso contrario
        
        void siguiente();				// Avanza al siguiente nodo de la lista
        
        void primero();					// Se ubica en el primer nodo de la lista
        
        void ultimo();					// Se ubica al final de la lista
        
		void imprimir();				// Imprime la información guardada en el nodo
		
		Palabra* buscar(string palabra);       		// Busca un nodo según el dato que se pase como parámetro
										// Si se trata de una lista de estudiantes recibe una cédula como parámetro,
										// y si se trata de una lista de cursos recibe un ID de materia como parámetro
										
		void borrar(string palabra);

        /* ----- Destructor ----- */
        
        ~Lista();
        
};

#endif
