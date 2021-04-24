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
    	
    	/* ----- M�TODOS ----- */
		
		/* ----- Constructores ----- */
    	
        Lista();						// Constructor sin par�metros -> Crea una lista vac�a
        
        /* ----- Procedimientos ----- */
        
        void insertarNodo(Palabra *pb);			// Inserta un elemento en la lista
        
        Palabra* valorActual();				// Retorna el elemento almacenado en el nodo actual de la lista
        
        int cantElementos();			// Devuelve la cantidad de elementos guardados en la lista
        
        int getRepeticiones();
        
        bool listaVacia();				// Retorna 'true' si la lista est� vac�a, y 'false' en caso contrario
        
        bool haySiguiente();			// Retorna 'true' si el siguiente nodo es v�lido, y 'false' en caso contrario
        
        bool hayActual();				// Retorna 'true' si el nodo actual es v�lido, y 'false' en caso contrario
        
        void siguiente();				// Avanza al siguiente nodo de la lista
        
        void primero();					// Se ubica en el primer nodo de la lista
        
        void ultimo();					// Se ubica al final de la lista
        
		void imprimir();				// Imprime la informaci�n guardada en el nodo
		
		Palabra* buscar(string palabra);       		// Busca un nodo seg�n el dato que se pase como par�metro
										// Si se trata de una lista de estudiantes recibe una c�dula como par�metro,
										// y si se trata de una lista de cursos recibe un ID de materia como par�metro
										
		void borrar(string palabra);

        /* ----- Destructor ----- */
        
        ~Lista();
        
};

#endif
