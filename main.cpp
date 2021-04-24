#include "Articulo.h"
#include "Global.h"

int main(){
	
	Articulo *a = new Articulo();
	
	a->insertarPalabra( "hola", 1, 2);
	a->insertarPalabra( "adios", 3, 4) ;
	a->insertarPalabra( "lala", 45, 6);
	a->insertarPalabra( "lala", 23, 4);
	
	
	
	a->crearTablaAlfabetica();

	
	
	
	//a->imprimirInOrden();
}
