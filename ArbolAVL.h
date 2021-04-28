#ifndef ARBOL_AVL
#define ARBOL_AVL

#include "Global.h"
#include "Nodo.h"

using namespace std;

/*
	Clase que implementa un árbol AVL.
		
	Este árbol tiene la característica de que siempre está equilibrado, de modo que para todos sus nodos la altura de la rama izquierda
	no difiere en más de una unidad de la altura de la rama derecha o viceversa.
	
	También se cumple que el subárbol izquierdo de cualquier nodo contiene valores menores que el que contiene dicho nodo, y el subárbol derecho contiene valores mayores. 

*/

class ArbolAVL{
	
	private:
		
		/* ----- ATRIBUTOS ----- */
		
		Nodo *raiz;									// Apuntador a la raíz del árbol
		
		/* ----- MÉTODOS PRIVADOS ----- */
		
		/* ----- Procedimientos ----- */
		
		void balancearEnNodo(Nodo *n);							// Balancea el árbol a partir del punto dado
		
		Nodo *encontrarNodo(string palabra);					// Recibe como parámetro un string que representa una palabra y la busca en el árbol
																// Devuelve el nodo donde se encuentra el objeto que representa la palabra
													
		void rotarIzquierda(Nodo *n);							// Función que realiza una rotación simple hacia la izquierda.
																// La nueva raíz del árbol será la raíz del subárbol derecho,
																// y la raíz antigua será el subárbol izquierdo de la nueva raíz.
																// Si la nueva raíz ya tenía un hijo izquierdo,
																// este se convierte en el hijo derecho del nuevo hijo izquierdo.

		void rotarDerecha(Nodo *n);								// Función que realiza una rotación simple hacia la derecha.
																// La nueva raíz del árbol será la raíz del subárbol izquierdo,
																// y la raíz antigua será el subárbol derecho de la nueva raíz.
																// Si la nueva raíz ya tenía un hijo derecho,
																// este se convierte en el hijo izquierdo del nuevo hijo derecho

		void setRaiz(Nodo *n);									// Reemplaza la raíz del árbol por el nodo que se pasa como parámetro
		
	public:
		
		/* ----- MÉTODOS PÚBLICOS ----- */
		
		/* ----- Constructores ----- */
		
		ArbolAVL();												// Constructor sin parámetros
		ArbolAVL(Palabra* p);									// Constructor con parámetros
		
		/* ----- Getters ----- */
		
		Nodo* getRaiz(); 
		int getAltura();
		
		/* ----- Procedimientos ----- */
		
		bool insertarNodo(Palabra* p, int linea, int pagina);	// Función de inserción. Ingresa una palabra alfabéticamente.
																// No admite palabras repetidas; en caso de detectar que la palabra ya existe en el árbol,
																// simplemente añade la línea y página de la coindencia al listado interno del objeto palabra
																
		bool quitarNodo(string palabra);						// Función de eliminación. Quita el nodo correspondiente a la palabra que se pasa como parámetro
																// y realiza un rebalanceo del árbol.
																
		void inOrden(Nodo* nodo, bool esRaiz = true);			// Función que realiza el recorrido inorden del árbol
		
		int palabrasUnicas(Nodo* nodo, int cont);				// Función que cuenta cuántas palabras únicas existen en el árbol
		
		void imprimirInOrden();									// Función que imprime in orden las palabras almacenadas en el árbol
		
		void podar(Nodo* n);									// Función recursiva para podar el árbol
		
		/* ----- Destructor ----- */
		
		~ArbolAVL();											// Destructor de la clase
	
};

#endif
