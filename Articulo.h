#ifndef ARTICULO
#define ARTICULO

#include "ArbolAVL.h"
#include "Hash.h"
#include "Global.h"

using namespace std;


class Articulo{
	
	
	private:
		/* ----- ATRIBUTOS ----- */

		ArbolAVL *arbolPalabras;        //Arbol donde se almacenan las palabras.
		Hash *tablaCapitulos;    //Tabla hash para asociar la clave con el número de capitulos del archivo. 
		Hash *tablaAlfabetica;   //Tabla hash para asociar la clave con las palabras por orden alfabético del archivo.

		int lineasTotales;              // Cantidad de líneas que el archivo tiene en total.
		int capitulosTotales;           // Cantidad de capítulos que el archivo tiene en total.
		int paginasTotales;             // Cantidad de páginas que el archivo tiene en total.
		int palabrasTotales;            // Cantidad de palabras que el archivo tiene en total.
		int palabrasUnicas;             // Cantidad de palabras únicas que tiene el archivo.
		
	public:
		  /* ----- MÉTODOS ----- */
		
<<<<<<< HEAD
		  /* ----- Constructores ----- */
		Articulo();                    //Constructor sin parámetros.

		  /* ----- Procedimientos ----- */

		int extraerNumero(string str);   // Retornar el valor numérico que se encuentra en un string.

		bool esNumero(string str);		 // Retornar 'true' si el string recibido es un valor numérico, y 'false' en caso contrario

		void cargarTablaCapitulos();     //Llena de árbol de palabras y carga las palabras en la tabla hash capítulos.

		void cargarTablaAlfabetica();    //Llena de árbol de palabras y carga las palabras en la tabla hash alfabética.

		void mostrarArchivo();           //Imprime el contenido del archivo.

		void cargarTotalDocumento();     //Imprime las palabras, las líneas, los capítulos y páginas en total que tiene el archivo.

		//Inserta las palbras en el árbol.
		void insertarPalabra(string palabra, int linea, int pagina); 

		//Inserta cada una de las palabras en la tabla hash alfabética.
		void crearTablaAlfabetica(Nodo *nodo, bool esRaiz);          

		//Inserta cada una de las palabras en la tabla hash de capítulos.
		void crearTablaCapitulos(Nodo *nodo, bool esRaiz, int capitulo);  

		void indiceLineas();                 //Imprime el índice de palabras, mostrando en qué líneas aparece cada palabra.

		void indicePaginas();                //Imprime el índice de palabras, mostrando en qué páginas aparece cada palabra

		void indiceCapitulo(int capitulo);   // Imprime las palabras que aparece en un capítulo.

		void mostrarCapitulos();             // Imprime la lista de capítulos del artículo.

		void busquedaPalabra();             // Imprime las líneas y los capítulos donde aparece la palabra que se desea buscar.

		bool borrarIndiceAlfabetico();            //Elimina una palabra de la tabla hash alfabético.

		bool borrarIndiceCapitulo(int capitulo);  //Elimina una palabra de la tabla hash de capítulos.

		void menuPrincipal();                     //Imprime el menú principal del programa.

		void salir();                             //Finaliza la ejecución del programa.

 
		/* ----- Destructor ----- */
=======
		Articulo();
		int extraerNumero(string str);
		bool esNumero(string str);
		void cargarTablaCapitulos();
		void cargarTablaAlfabetica();
		void mostrarArchivo();
		void insertarPalabra(string palabra, int linea, int pagina);
		void crearTablaAlfabetica(Nodo *nodo, bool esRaiz);
		void crearTablaCapitulos(Nodo *nodo, bool esRaiz, int capitulo);
		void indiceLineas();
		void indicePaginas();
		void indiceCapitulo(int capitulo);
		void mostrarCapitulos();
		void busquedaPalabra();
		bool borrarIndiceAlfabetico();
		bool borrarIndiceCapitulo(int capitulo);
		void menuPrincipal();
		void salir();
>>>>>>> 70c18445d6046bf2b92e557aef159853d1e917d1
		~Articulo();
	
};

#endif
