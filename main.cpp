#include "ArbolAVL.h"
#include "Global.h"

int main(){
	
	Palabra p1 ("hola", 1, 1);
	Palabra p2 ("adios", 1, 1);
	Palabra p3 ("lala", 1, 1);
	
	ArbolAVL *a = new ArbolAVL();
	a->insertarNodo(p1);
	a->insertarNodo(p2);
	a->insertarNodo(p3);
	
	a->imprimirInOrden();
}
