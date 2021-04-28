#ifndef ARBOL_AVL
#define ARBOL_AVL

#include "Global.h"
#include "Nodo.h"

using namespace std;

/*
	Clase que implementa un �rbol AVL.
		
	Este �rbol tiene la caracter�stica de que siempre est� equilibrado, de modo que para todos sus nodos la altura de la rama izquierda
	no difiere en m�s de una unidad de la altura de la rama derecha o viceversa.
	
	Tambi�n se cumple que el sub�rbol izquierdo de cualquier nodo contiene valores menores que el que contiene dicho nodo, y el sub�rbol derecho contiene valores mayores. 

*/

class ArbolAVL{
	
	private:
		
		/* ----- ATRIBUTOS ----- */
		
		Nodo *raiz;									// Apuntador a la ra�z del �rbol
		
		/* ----- M�TODOS PRIVADOS ----- */
		
		/* ----- Procedimientos ----- */
		
		void balancearEnNodo(Nodo *n);							// Balancea el �rbol a partir del punto dado
		
		Nodo *encontrarNodo(string palabra);					// Recibe como par�metro un string que representa una palabra y la busca en el �rbol
																// Devuelve el nodo donde se encuentra el objeto que representa la palabra
													
		void rotarIzquierda(Nodo *n);							// Funci�n que realiza una rotaci�n simple hacia la izquierda.
																// La nueva ra�z del �rbol ser� la ra�z del sub�rbol derecho,
																// y la ra�z antigua ser� el sub�rbol izquierdo de la nueva ra�z.
																// Si la nueva ra�z ya ten�a un hijo izquierdo,
																// este se convierte en el hijo derecho del nuevo hijo izquierdo.

		void rotarDerecha(Nodo *n);								// Funci�n que realiza una rotaci�n simple hacia la derecha.
																// La nueva ra�z del �rbol ser� la ra�z del sub�rbol izquierdo,
																// y la ra�z antigua ser� el sub�rbol derecho de la nueva ra�z.
																// Si la nueva ra�z ya ten�a un hijo derecho,
																// este se convierte en el hijo izquierdo del nuevo hijo derecho

		void setRaiz(Nodo *n);									// Reemplaza la ra�z del �rbol por el nodo que se pasa como par�metro
		
	public:
		
		/* ----- M�TODOS P�BLICOS ----- */
		
		/* ----- Constructores ----- */
		
		ArbolAVL();												// Constructor sin par�metros
		ArbolAVL(Palabra* p);									// Constructor con par�metros
		
		/* ----- Getters ----- */
		
		Nodo* getRaiz(); 
		int getAltura();
		
		/* ----- Procedimientos ----- */
		
		bool insertarNodo(Palabra* p, int linea, int pagina);	// Funci�n de inserci�n. Ingresa una palabra alfab�ticamente.
																// No admite palabras repetidas; en caso de detectar que la palabra ya existe en el �rbol,
																// simplemente a�ade la l�nea y p�gina de la coindencia al listado interno del objeto palabra
																
		bool quitarNodo(string palabra);						// Funci�n de eliminaci�n. Quita el nodo correspondiente a la palabra que se pasa como par�metro
																// y realiza un rebalanceo del �rbol.
																
		void inOrden(Nodo* nodo, bool esRaiz = true);			// Funci�n que realiza el recorrido inorden del �rbol
		
		int palabrasUnicas(Nodo* nodo, int cont);				// Funci�n que cuenta cu�ntas palabras �nicas existen en el �rbol
		
		void imprimirInOrden();									// Funci�n que imprime in orden las palabras almacenadas en el �rbol
		
		void podar(Nodo* n);									// Funci�n recursiva para podar el �rbol
		
		/* ----- Destructor ----- */
		
		~ArbolAVL();											// Destructor de la clase
	
};

#endif
