#ifndef PALABRA
#define PALABRA

#include "Global.h"

using namespace std;

/*

	Clase que representa una palabra.
	Solo hay un objeto Palabra por cada palabra del artículo,
	ya que todas sus coincidencias se guardan en los contenedores list de sus atributos.

*/

class Palabra{
	
	private:
		
		/* ----- ATRIBUTOS ----- */
		
		string palabra;								// Representa la palabra que almacena el objeto
		list<int> *paginas;							// list que guarda las páginas donde aparece la palabra
		list<int> *lineas;							// list que guarda las lineas donde aparece la palabra
		
	public:
		
		/* ----- MÉTODOS ----- */
		
		/* ----- Constructores ----- */
		
		Palabra();									// Constructor sin parámetros
		Palabra(string pb, int linea, int pagina);	// Constructor con parámetros
		Palabra(Palabra *p);						// Constructor con parámetros
		
		/* ----- Getters ----- */
		
		string getPalabra();						// Devuelve el string de la palabra que se guarda en el objeto
		
		/* ----- Procedimientos ----- */
					
		void imprimir();							// Imprime la palabra que se almacena en el objeto
		
		void mostrarPaginas();						// Imprime las páginas en las que aparece la palabra
		
		void mostrarLineas();						// Imprime las líneas en las que aparece la palabra
		
		void agregarPagina(int pag);				// Agrega una página al list de palabras
													// si la página ya se encuentra en el list, no la añade nuevamente
													
		void agregarLinea(int ln);					// Agrega una linea al list de palabras
													// si la linea ya se encuentra en el list, no la añade nuevamente
		
		bool esUnica();								// Verifica si una palabra es unica
													// Se sobreentiente que una palabra es unica si aparece solo una vez en una linea y en una pagina
													// Devuelve true si la palabra es única, y false en caso contrario
		
		/* ----- Destructor ----- */
													
		~Palabra();									// Destructor de la clase
			
};

#endif
