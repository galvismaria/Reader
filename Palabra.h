#ifndef PALABRA
#define PALABRA

#include "Global.h"

using namespace std;

/*

	Clase que representa una palabra.
	Solo hay un objeto Palabra por cada palabra del art�culo,
	ya que todas sus coincidencias se guardan en los contenedores list de sus atributos.

*/

class Palabra{
	
	private:
		
		/* ----- ATRIBUTOS ----- */
		
		string palabra;								// Representa la palabra que almacena el objeto
		list<int> *paginas;							// list que guarda las p�ginas donde aparece la palabra
		list<int> *lineas;							// list que guarda las lineas donde aparece la palabra
		
	public:
		
		/* ----- M�TODOS ----- */
		
		/* ----- Constructores ----- */
		
		Palabra();									// Constructor sin par�metros
		Palabra(string pb, int linea, int pagina);	// Constructor con par�metros
		Palabra(Palabra *p);						// Constructor con par�metros
		
		/* ----- Getters ----- */
		
		string getPalabra();						// Devuelve el string de la palabra que se guarda en el objeto
		
		/* ----- Procedimientos ----- */
					
		void imprimir();							// Imprime la palabra que se almacena en el objeto
		
		void mostrarPaginas();						// Imprime las p�ginas en las que aparece la palabra
		
		void mostrarLineas();						// Imprime las l�neas en las que aparece la palabra
		
		void agregarPagina(int pag);				// Agrega una p�gina al list de palabras
													// si la p�gina ya se encuentra en el list, no la a�ade nuevamente
													
		void agregarLinea(int ln);					// Agrega una linea al list de palabras
													// si la linea ya se encuentra en el list, no la a�ade nuevamente
		
		bool esUnica();								// Verifica si una palabra es unica
													// Se sobreentiente que una palabra es unica si aparece solo una vez en una linea y en una pagina
													// Devuelve true si la palabra es �nica, y false en caso contrario
		
		/* ----- Destructor ----- */
													
		~Palabra();									// Destructor de la clase
			
};

#endif
