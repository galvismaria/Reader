#ifndef NODO
#define NODO

#include "Global.h"
#include "Palabra.h"

using namespace std;

/*

	Clase que implementa un nodo para un �rbol AVL.
	Cada nodo guarda una instancia de la clase Palabra.

*/

class Nodo{
	
	private:
		
		/* ----- ATRIBUTOS ----- */
		
		Palabra *info;						// Dato que se almacena en el nodo 
		int altura;							// Altura del nodo con respecto al punto m�s profundo del �rbol
		Nodo *der;							// Apuntador al sub�rbol derecho
		Nodo *izq;							// Apuntador al sub�rbol izquierdo
		Nodo *padre;						// Apuntador al padre del nodo
	
	public:
		
		/* ----- M�TODOS ----- */
		
		/* ----- Constructor ----- */
			
		Nodo(Palabra *p);					// Constructor con par�metros
		
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
											// -> Si la funci�n retorna negativo, significa que el lado derecho es m�s profundo que el izquierdo
											// -> Si la funci�n retorna cero, ambos lados tienen exactamente la misma altura
											// -> Si la funci�n retorna positivo, significa que el lado izquierdo es m�s profundo que el derecho
											
		int actualizarAltura();				// Actualiza la altura del nodo
		
		void quitarPadre();					// Quita el nodo padre del nodo actual
		
		/* ----- Destructor ----- */
		
		~Nodo();							// Destructor
	
};

#endif
