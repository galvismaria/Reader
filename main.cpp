#include "Articulo.h"
#include "Global.h"

int main(){
	
	
	
	Palabra p1 ("hola", 1, 1);
	Palabra p2 ("adios", 2, 2);
	Palabra p3 ("lala", 3, 3);
	
	Articulo *a = new Articulo();
	
	a->crearArbol( "hola", 1, 1 );
	a->crearArbol( "adios", 1, 1) ;
	a->crearArbol( "lala", 1, 1 );
	a->imprimirTablaAlfabetica();
	
	
	
	//a->imprimirInOrden();
}
