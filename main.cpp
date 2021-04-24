#include "Articulo.h"
#include "Global.h"

int main(){
	
	
	
	Palabra p1 ("hola");
	Palabra p2 ("adios");
	Palabra p3 ("lala");
	
	Articulo *a = new Articulo();
	
	a->crearArbol( "hola" );
	a->crearArbol( "adios") ;
	a->crearArbol( "lala");
	a->imprimirTablaAlfabetica();
	
	
	
	//a->imprimirInOrden();
}
