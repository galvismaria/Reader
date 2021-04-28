#ifndef ARTICULO
#define ARTICULO

#include "ArbolAVL.h"
#include "Hash.h"
#include "Global.h"

using namespace std;

/*

	Clase donde se realiza el procesamiento del artícul de texto,
	se genera el árbol de palabras y se crean las tablas hash.

*/

class Articulo{
	

	private:
		
		/* ----- ATRIBUTOS ----- */

		ArbolAVL *arbolPalabras;        	// Arbol donde se almacenan las palabras.
		Hash *tablaCapitulos;   			// Tabla hash con casillas que representan los capítulos del archivo.
		Hash *tablaAlfabetica;   			// Tabla hash con casillas que representan las letras del alfabeto.

		int lineasTotales;              	// Cantidad de líneas que el archivo tiene en total.
		int capitulosTotales;           	// Cantidad de capítulos que el archivo tiene en total.
		int paginasTotales;             	// Cantidad de páinas que el archivo tiene en total.
		int palabrasTotales;            	// Cantidad de palabras que el archivo tiene en total.
		int palabrasUnicas;             	// Cantidad de palabras úicas que tiene el archivo.
		
	public:
		
		/* ----- MÉTODOS ----- */
		
		/* ----- Constructores ----- */
		  
		Articulo();                    										// Constructor sin parámetros.

		/* ----- Procedimientos ----- */

		int extraerNumero(string str);   									// Retorna los números que se encuentran en un string

		bool esNumero(string str);		 									// Retornar 'true' si el string recibido es un número, y 'false' en caso contrario

		void cargarTablaCapitulos();     									// Llena el árbol de palabras y carga las palabras en la tabla hash de capíulos.

		void cargarTablaAlfabetica();   									// Llena el árbool de palabras y carga las palabras en la tabla hash alfabética.

		void mostrarArchivo();           									// Imprime el contenido del archivo.

		void conteoTotal();     											// Imprime el conteo total de capítulos, páginas, líneas y palabras que tiene el archivo

		void insertarPalabra(string palabra, int linea, int pagina); 		// Inserta una palabra en el árbol de palabras
	
		void crearTablaAlfabetica(Nodo *nodo, bool esRaiz);  				// Inserta cada una de las palabras en la tabla hash alfabética.        

		void crearTablaCapitulos(Nodo *nodo, bool esRaiz, int capitulo);	// Inserta cada una de las palabras en la tabla hash de capítulos.

		void indiceLineas();                								// Imprime el índice de palabras, mostrando en qué líneas aparece cada palabra.

		void indicePaginas();                								// Imprime el índice de palabras, mostrando en qué páginas aparece cada palabra

		void indiceCapitulo(int capitulo);   								// Imprime las palabras que aparecen en un capítulo específico.

		void mostrarCapitulos();             								// Imprime la lista de capítulos del artículo.

		void busquedaPalabra();             								// Imprime las líneas y los capítulos donde aparece la palabra que se desea buscar.

		bool borrarIndiceAlfabetico();            							// Elimina una palabra de la tabla hash alfabético.

		bool borrarIndiceCapitulo(int capitulo);  							// Elimina una palabra de la tabla hash de capítulos.

		void menuPrincipal();                     							// Imprime el menú principal del programa.

		void salir();                             							// Finaliza la ejecución del programa.

		/* ----- Destructor ----- */
		
		~Articulo();														// Destructor de la clase
	
};

#endif
