#ifndef NODO
#define NODO

#include "Global.h"
#include "Palabra.h"

using namespace std;

/*

	Clase que implementa un nodo para un árbol AVL.
	Cada nodo guarda una instancia de la clase Palabra.

*/

class Nodo{
	
	private:
		
		/* ----- ATRIBUTOS ----- */
		
		Palabra *info;						// Dato que se almacena en el nodo 
		int altura;							// Altura del nodo con respecto al punto más profundo del árbol
		Nodo *der;							// Apuntador al subárbol derecho
		Nodo *izq;							// Apuntador al subárbol izquierdo
		Nodo *padre;						// Apuntador al padre del nodo
	
	public:
		
		/* ----- MÉTODOS ----- */
		
		/* ----- Constructor ----- */
			
		Nodo(Palabra *p);					// Constructor con parámetros
		
		/* ----- Getters ----- */
		
		Palabra* getInfo();
		int getAltura();
		Nodo *getDerecha();
		Nodo *getIzquierda();
		Nodo *getPadre();
		
		/* ----- Setters ----- */
		
		Nodo* setIzquierda(Nodo *nuevoIzq);
		Nodo* setDerecha(Nodo *nuevoDer);
		
		/* ----- Procedimientos ----- */
		
		int getBalance();					// Calcula el punto de balance
											// -> Si la función retorna negativo, significa que el lado derecho es más profundo que el izquierdo
											// -> Si la función retorna cero, ambos lados tienen exactamente la misma altura
											// -> Si la función retorna positivo, significa que el lado izquierdo es más profundo que el derecho
											
		int actualizarAltura();				// Actualiza la altura del nodo
		
		void quitarPadre();					// Quita el nodo padre del nodo actual
		
		/* ----- Destructor ----- */
		
		~Nodo();							// Destructor
	
};

#endif
