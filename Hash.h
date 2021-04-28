#ifndef HASH
#define HASH

#include "Lista.h"
#include "Palabra.h"

/*
	Función que implementa una tabla hash abierta, donde cada elemento está asociado a una clave
	y varios objetos pueden estar asociados a la misma clave.
	Debido a los requerimientos del sistema, se implementan dos tipos hashing:
	
	-> Un hashing donde las claves se generan a partir de la letra inicial palabra que se quiere ingresar.
	De esta forma, hay una casilla correspondiente a cada letra del alfabeto y en cada una de ellas
	se almacenan las palabras que comienzan por dicha letra.
	
	-> Un hashing donde las claves se generan a partir del capítulo donde se haya encontrado la palabra que se quiere ingresar.
	De esta forma, hay una casilla correspondiente a cada capítulo que conforma el artículo y en cada una de ellas se almacenan
	las palabras que aparecen en dicho capítulo.

*/

using namespace std;

class Hash{
	
	private:
		
		/* ----- ATRIBUTOS ----- */
		
		Lista *tabla[MAX_HASH];								// Arreglo de listas que representa la tabla hash
		
		/* ----- MÉTODOS PRIVADOS ----- */
		
		/* ----- Procedimientos ----- */
		
		int hashing(string palabra);						// Función hash que crea una clave a partir de la letra inicial de una palabra
															// Recibe como parámetro un string con una palabra y genera una clave hashing
															// a partir de la primera letra de la palabra.
															// Devuelve el número correspondiente a la posición de esa letra en el alfabeto menos uno,
															// y este número es correspondiente a la posición de la casilla en la tabla hash.
															
		int hashing(int capitulo);							// Función hash que crea una clave a partir del capítulo donde aparece una palabra
															// Recibe como parámetro un int que representa el número de un capítulo y genera una clave hashing
															// a partir de este dato. Devuelve el número del capítulo menos uno,
															// y este número es correspondiente a la posición de la casilla en la tabla hash.
		
	public:
		
		/* ----- MÉTODOS PÚBLICOS ----- */
		
		/* ----- Constructor ----- */
		
		Hash();												// Constructor sin parámetros
		
		void insertar(Palabra *palabra);					// Función de inserción para una tabla hash alfabetica
															// Recibe un objeto Palabra para insertar en la tabla hash.
															// Para encontrar el lugar que ocupará se genera una clave hash con la función de hashing.
															// La clave hash se genera a partir de la letra por la cual inicial la palabra,
															// de modo que la palabra se inserta en la lista de la casilla correspondiente a dicha letra.


		
		void insertar(Palabra *palabra, int capitulo);		// Función de insercion para una tabla hash de capítulos
															// Recibe un objeto Palabra para insertar en la tabla hash y el capítulo donde se encuentra.
															// Para encontrar el lugar que ocupará se genera una clave hash con la función de hashing.
															// La clave hash se genera a partir del capítulo donde se encuentra la palabra,
															// de modo que la palabra se inserta en la lista de la casilla correspondiente al capítulo.

		
		void eliminar(Palabra *palabra);					// Función de elimintación para una tabla hash alfabetica
															// Recibe el objeto Palabra que se desea eliminar
															// y se genera su clave hash para ir a la casilla donde deberia estar.
															// La clave hash se genera a partir de la letra por la cual
															// inicial la palabra, de modo que la palabra se busca en la lista de la casilla
															// correspondiente a dicha letra y, si se encuentra, se elimina.

		void eliminar(Palabra *palabra, int capitulo);		// Función de eliminación para una tabla hash de capitulos
															// Recibe el objeto Palabra que se desea eliminar y el capítulo donde debería encontrarse,
															// y se genera su clave hash para ir a la casilla donde deberia estar.
															// La clave hash se genera a partir del capítulo donde se encuentra
															// la palabra, de modo que la palabra se busca en la lista de la casilla correspondiente
															// a dicho capítulo y, si se encuentra, se elimina.

		
		bool pertenece(Palabra *palabra);					// Función para verificar si el elemento existe en una tabla hash alfabetica
															// Recibe como parámetro un objeto Palabra. Para encontrar el lugar donde debería encontrarse
															// se genera una clave hash con la función de hashing a partir de la primera letra de la palabra.
															//  Una vez en la casilla, se busca en la lista si se encuentra el objeto.
															// La función retorna true si el objeto se encuentra en la tabla, y false en caso contrario.

		
		bool pertenece(Palabra *palabra, int capitulo);		// Función para verificar si el elemento existe en una tabla hash de capitulos
															// Recibe como parámetro un objeto Palabra y el capítulo donde debería encontrarse.
															// Para encontrar el lugar donde debería encontrarse se genera una clave hash
															// con la función de hashing a partir del número de capítulo.
															// Una vez en la casilla, se busca en la lista si se encuentra el objeto.
															// La función retorna true si el objeto se encuentra en la tabla, y false en caso contrario.

		
		Palabra* buscarPalabra(string pb);					// Función de búsqueda para una tabla hash alfabetica
															// Recibe como parámetro un objeto Palabra.
															// Para encontrar el lugar donde debería encontrarse se genera
															// una clave hash con la función de hashing a partir de la primera letra de la palabra.
															// Una vez en la casilla, se busca el objeto en la lista y se retorna.

		Palabra* buscarPalabra(string pb, int capitulo);	// Función de búsqueda para una tabla hash de capitulos
															// Recibe como parámetro un objeto Palabra. Para encontrar el lugar donde debería
															// encontrarse se genera una clave hash con la función de hashing a partir del número
															// de capítulo. Una vez en la casilla, se busca en la lista si se encuentra el objeto.
															// Una vez en la casilla, se busca el objeto en la lista y se retorna.

		
		void imprimirPalabras();							// Imprime las palabras que se encuentran en la tabla.
		
        void imprimirPaginas();								// Imprime las palabras que se encuentran en la tabla mostrando en qué páginas aparecen.
        
		void imprimirLineas();								// Imprime las palabras que se encuentran en la tabla, mostrando en qué líneas aparecen.

		void imprimirCapitulo( int capitulo );				// Recibe como parámetro un número de capítulo e imprime las palabras
															// que se encuentren en ese capítulo.

		void mostrarCapitulos();							// Imprime la lista de capítulos de la tabla.
		
		/* ----- Destructor ----- */
		
		~Hash();											// Destructor de la clase
	
};

#endif
