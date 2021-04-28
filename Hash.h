#ifndef HASH
#define HASH

#include "Lista.h"
#include "Palabra.h"

/*
	Funci�n que implementa una tabla hash abierta, donde cada elemento est� asociado a una clave
	y varios objetos pueden estar asociados a la misma clave.
	Debido a los requerimientos del sistema, se implementan dos tipos hashing:
	
	-> Un hashing donde las claves se generan a partir de la letra inicial palabra que se quiere ingresar.
	De esta forma, hay una casilla correspondiente a cada letra del alfabeto y en cada una de ellas
	se almacenan las palabras que comienzan por dicha letra.
	
	-> Un hashing donde las claves se generan a partir del cap�tulo donde se haya encontrado la palabra que se quiere ingresar.
	De esta forma, hay una casilla correspondiente a cada cap�tulo que conforma el art�culo y en cada una de ellas se almacenan
	las palabras que aparecen en dicho cap�tulo.

*/

using namespace std;

class Hash{
	
	private:
		
		/* ----- ATRIBUTOS ----- */
		
		Lista *tabla[MAX_HASH];								// Arreglo de listas que representa la tabla hash
		
		/* ----- M�TODOS PRIVADOS ----- */
		
		/* ----- Procedimientos ----- */
		
		int hashing(string palabra);						// Funci�n hash que crea una clave a partir de la letra inicial de una palabra
															// Recibe como par�metro un string con una palabra y genera una clave hashing
															// a partir de la primera letra de la palabra.
															// Devuelve el n�mero correspondiente a la posici�n de esa letra en el alfabeto menos uno,
															// y este n�mero es correspondiente a la posici�n de la casilla en la tabla hash.
															
		int hashing(int capitulo);							// Funci�n hash que crea una clave a partir del cap�tulo donde aparece una palabra
															// Recibe como par�metro un int que representa el n�mero de un cap�tulo y genera una clave hashing
															// a partir de este dato. Devuelve el n�mero del cap�tulo menos uno,
															// y este n�mero es correspondiente a la posici�n de la casilla en la tabla hash.
		
	public:
		
		/* ----- M�TODOS P�BLICOS ----- */
		
		/* ----- Constructor ----- */
		
		Hash();												// Constructor sin par�metros
		
		void insertar(Palabra *palabra);					// Funci�n de inserci�n para una tabla hash alfabetica
															// Recibe un objeto Palabra para insertar en la tabla hash.
															// Para encontrar el lugar que ocupar� se genera una clave hash con la funci�n de hashing.
															// La clave hash se genera a partir de la letra por la cual inicial la palabra,
															// de modo que la palabra se inserta en la lista de la casilla correspondiente a dicha letra.


		
		void insertar(Palabra *palabra, int capitulo);		// Funci�n de insercion para una tabla hash de cap�tulos
															// Recibe un objeto Palabra para insertar en la tabla hash y el cap�tulo donde se encuentra.
															// Para encontrar el lugar que ocupar� se genera una clave hash con la funci�n de hashing.
															// La clave hash se genera a partir del cap�tulo donde se encuentra la palabra,
															// de modo que la palabra se inserta en la lista de la casilla correspondiente al cap�tulo.

		
		void eliminar(Palabra *palabra);					// Funci�n de elimintaci�n para una tabla hash alfabetica
															// Recibe el objeto Palabra que se desea eliminar
															// y se genera su clave hash para ir a la casilla donde deberia estar.
															// La clave hash se genera a partir de la letra por la cual
															// inicial la palabra, de modo que la palabra se busca en la lista de la casilla
															// correspondiente a dicha letra y, si se encuentra, se elimina.

		void eliminar(Palabra *palabra, int capitulo);		// Funci�n de eliminaci�n para una tabla hash de capitulos
															// Recibe el objeto Palabra que se desea eliminar y el cap�tulo donde deber�a encontrarse,
															// y se genera su clave hash para ir a la casilla donde deberia estar.
															// La clave hash se genera a partir del cap�tulo donde se encuentra
															// la palabra, de modo que la palabra se busca en la lista de la casilla correspondiente
															// a dicho cap�tulo y, si se encuentra, se elimina.

		
		bool pertenece(Palabra *palabra);					// Funci�n para verificar si el elemento existe en una tabla hash alfabetica
															// Recibe como par�metro un objeto Palabra. Para encontrar el lugar donde deber�a encontrarse
															// se genera una clave hash con la funci�n de hashing a partir de la primera letra de la palabra.
															//  Una vez en la casilla, se busca en la lista si se encuentra el objeto.
															// La funci�n retorna true si el objeto se encuentra en la tabla, y false en caso contrario.

		
		bool pertenece(Palabra *palabra, int capitulo);		// Funci�n para verificar si el elemento existe en una tabla hash de capitulos
															// Recibe como par�metro un objeto Palabra y el cap�tulo donde deber�a encontrarse.
															// Para encontrar el lugar donde deber�a encontrarse se genera una clave hash
															// con la funci�n de hashing a partir del n�mero de cap�tulo.
															// Una vez en la casilla, se busca en la lista si se encuentra el objeto.
															// La funci�n retorna true si el objeto se encuentra en la tabla, y false en caso contrario.

		
		Palabra* buscarPalabra(string pb);					// Funci�n de b�squeda para una tabla hash alfabetica
															// Recibe como par�metro un objeto Palabra.
															// Para encontrar el lugar donde deber�a encontrarse se genera
															// una clave hash con la funci�n de hashing a partir de la primera letra de la palabra.
															// Una vez en la casilla, se busca el objeto en la lista y se retorna.

		Palabra* buscarPalabra(string pb, int capitulo);	// Funci�n de b�squeda para una tabla hash de capitulos
															// Recibe como par�metro un objeto Palabra. Para encontrar el lugar donde deber�a
															// encontrarse se genera una clave hash con la funci�n de hashing a partir del n�mero
															// de cap�tulo. Una vez en la casilla, se busca en la lista si se encuentra el objeto.
															// Una vez en la casilla, se busca el objeto en la lista y se retorna.

		
		void imprimirPalabras();							// Imprime las palabras que se encuentran en la tabla.
		
        void imprimirPaginas();								// Imprime las palabras que se encuentran en la tabla mostrando en qu� p�ginas aparecen.
        
		void imprimirLineas();								// Imprime las palabras que se encuentran en la tabla, mostrando en qu� l�neas aparecen.

		void imprimirCapitulo( int capitulo );				// Recibe como par�metro un n�mero de cap�tulo e imprime las palabras
															// que se encuentren en ese cap�tulo.

		void mostrarCapitulos();							// Imprime la lista de cap�tulos de la tabla.
		
		/* ----- Destructor ----- */
		
		~Hash();											// Destructor de la clase
	
};

#endif
