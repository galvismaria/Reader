#ifndef ARTICULO
#define ARTICULO

#include "ArbolAVL.h"
#include "Hash.h"
#include "Global.h"

using namespace std;

/*

	Clase donde se realiza el procesamiento del art�cul de texto,
	se genera el �rbol de palabras y se crean las tablas hash.

*/

class Articulo{
	

	private:
		
		/* ----- ATRIBUTOS ----- */

		ArbolAVL *arbolPalabras;        	// Arbol donde se almacenan las palabras.
		Hash *tablaCapitulos;   			// Tabla hash con casillas que representan los cap�tulos del archivo.
		Hash *tablaAlfabetica;   			// Tabla hash con casillas que representan las letras del alfabeto.

		int lineasTotales;              	// Cantidad de l�neas que el archivo tiene en total.
		int capitulosTotales;           	// Cantidad de cap�tulos que el archivo tiene en total.
		int paginasTotales;             	// Cantidad de p�inas que el archivo tiene en total.
		int palabrasTotales;            	// Cantidad de palabras que el archivo tiene en total.
		int palabrasUnicas;             	// Cantidad de palabras �icas que tiene el archivo.
		
	public:
		
		/* ----- M�TODOS ----- */
		
		/* ----- Constructores ----- */
		  
		Articulo();                    										// Constructor sin par�metros.

		/* ----- Procedimientos ----- */

		int extraerNumero(string str);   									// Retorna los n�meros que se encuentran en un string

		bool esNumero(string str);		 									// Retornar 'true' si el string recibido es un n�mero, y 'false' en caso contrario

		void cargarTablaCapitulos();     									// Llena el �rbol de palabras y carga las palabras en la tabla hash de cap�ulos.

		void cargarTablaAlfabetica();   									// Llena el �rbool de palabras y carga las palabras en la tabla hash alfab�tica.

		void mostrarArchivo();           									// Imprime el contenido del archivo.

		void conteoTotal();     											// Imprime el conteo total de cap�tulos, p�ginas, l�neas y palabras que tiene el archivo

		void insertarPalabra(string palabra, int linea, int pagina); 		// Inserta una palabra en el �rbol de palabras
	
		void crearTablaAlfabetica(Nodo *nodo, bool esRaiz);  				// Inserta cada una de las palabras en la tabla hash alfab�tica.        

		void crearTablaCapitulos(Nodo *nodo, bool esRaiz, int capitulo);	// Inserta cada una de las palabras en la tabla hash de cap�tulos.

		void indiceLineas();                								// Imprime el �ndice de palabras, mostrando en qu� l�neas aparece cada palabra.

		void indicePaginas();                								// Imprime el �ndice de palabras, mostrando en qu� p�ginas aparece cada palabra

		void indiceCapitulo(int capitulo);   								// Imprime las palabras que aparecen en un cap�tulo espec�fico.

		void mostrarCapitulos();             								// Imprime la lista de cap�tulos del art�culo.

		void busquedaPalabra();             								// Imprime las l�neas y los cap�tulos donde aparece la palabra que se desea buscar.

		bool borrarIndiceAlfabetico();            							// Elimina una palabra de la tabla hash alfab�tico.

		bool borrarIndiceCapitulo(int capitulo);  							// Elimina una palabra de la tabla hash de cap�tulos.

		void menuPrincipal();                     							// Imprime el men� principal del programa.

		void salir();                             							// Finaliza la ejecuci�n del programa.

		/* ----- Destructor ----- */
		
		~Articulo();														// Destructor de la clase
	
};

#endif
