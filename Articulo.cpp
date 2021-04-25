#include "Articulo.h"

Articulo::Articulo(){

	arbolPalabras = new ArbolAVL();
	tablaCapitulos = new Hash();
	tablaAlfabetica = new Hash();

}

int Articulo::extraerNumero( string str ){
	
    stringstream ss;    
    ss << str;
    
    string temp;
    int found;
    
    while ( !ss.eof() ) {
  
        ss >> temp;
  
        if ( stringstream(temp) >> found )
            return found;

        temp = "";
    }
    
}

void Articulo::leerArchivo(){
	
    setlocale( LC_ALL, "" );
    string nombreArchivo = "textoprueba-corto.txt";
    
    ifstream archivo( nombreArchivo.c_str() );
    
    if (!archivo){
       cout << "Error: No se consiguio el archivo"<< endl;
       return;
    }
    
    string linea;
    int line = 1, cap = 1, pag = 1;
    
    while ( getline (archivo, linea) ) {
        
        istringstream iss(linea);
        string palabra;
        
        if ( linea.find("capitulo") != std::string::npos ){
        	
        	cap = extraerNumero(linea);
            //cout << "Capitulo: "<< cap << endl;

        } else if (linea.find("pagina") != std::string::npos){
			
            pag = extraerNumero(linea);
            //cout << "Pagina: "<< pag << endl;
        } else{
        	
        	while ( iss >> palabra ){
  
        		arbolPalabras->insertarNodo( new Palabra (palabra, line, pag + 1 ), line, pag + 1 );
        		
			}
        	
		}
        	
        line++;
        
	}
    
     cout << "Numero de lineas en total: "<< --line << endl;
     cout << "Numero de capitulos en total: "<< cap << endl;
     cout << "Numero de paginas: "<< pag << endl;
     
    indicePaginas();
     
};


void Articulo::insertarPalabra( string palabra, int linea, int pagina ){
	
	arbolPalabras->insertarNodo( new Palabra (palabra, linea, pagina), linea, pagina );
	
}

void Articulo::cargar(){
	
	insertarPalabra( "hola", 1, 2);
	insertarPalabra( "adios", 3, 4) ;
	insertarPalabra( "lala", 45, 6);
	insertarPalabra( "lala", 23, 4);
	
}

void Articulo::crearTablaAlfabetica( Nodo *nodo, bool esRaiz ){
	
	if ( esRaiz )
		nodo = arbolPalabras->getRaiz();
	
	if ( nodo->getIzquierda() )
		crearTablaAlfabetica( nodo->getIzquierda(), false );
	
	if ( nodo->getInfo()->getPalabra() != "\0" )
		tablaAlfabetica->insertar( nodo->getInfo() );
	
	if ( nodo->getDerecha() )
		crearTablaAlfabetica( nodo->getDerecha(), false );
	
}

void Articulo::crearTablaCapitulos( Nodo *nodo, bool esRaiz, int capitulo ){
	
	if ( esRaiz )
		nodo = arbolPalabras->getRaiz();
	
	if ( nodo->getIzquierda() )
		crearTablaCapitulos( nodo->getIzquierda(), false, capitulo );
	
	if ( nodo->getInfo()->getPalabra() != "\0" )
		tablaCapitulos->insertar( nodo->getInfo(), capitulo );
	
	if ( nodo->getDerecha() )
		crearTablaCapitulos( nodo->getDerecha(), false, capitulo );
	
}

void Articulo::indiceLineas(){
	
	crearTablaAlfabetica( arbolPalabras->getRaiz() , true );
	tablaAlfabetica->imprimirLineas();
	system("pause");
	
}

void Articulo::indicePaginas(){
	
	crearTablaAlfabetica( arbolPalabras->getRaiz() , true );
	tablaAlfabetica->imprimirPaginas();
	system("pause");
	
}

void Articulo::menuPrincipal(){
	
	while (true){
		
		system("cls");
		cout << "\n\n";
	
		cout << "\t----------------------------------------------------------------------------------------------------" << " \n\n";
		
		cout << "\n\n\n\n\t\t\t\t* * * Reader C++ * * *";
	
		cout << "\n\n\n\t\t1. Indice por lineas" <<
				"\n\n\t\t2. Indice por paginas"<<
				"\n\n\t\t3. Indice por capitulos" <<
				"\n\n\t\t4. Buscar palabra" <<
				"\n\n\t\t5. Eliminar palabra" <<
				"\n\n\t\t6. Imprimir documento" <<
				"\n\n\t\t7. Conteo total" <<
				"\n\n\t\t8. Salir\n\n\n\n";
				
		cout << "\t----------------------------------------------------------------------------------------------------" << " \n\n\t\t";
	
		bool flag = false;
		int opcion;
	
		while ( !flag ) {
			
			cin >> opcion;
			
			if ( (opcion >= 1) && (opcion <= 8) ){
			
				flag = true;
			
			}
				
			else{
			
				cout << "Error, intente de nuevo.\n";
				cin.clear();
				cin.ignore(200, '\n');
				
			}
		}
		
		cargar();
		
		switch (opcion) {
			
			case(1):
				
				indiceLineas();						
				break;
				
			case(2):
				
				indicePaginas();
				break;	
			
			case(8):
				
				salir();			
				
			default:
				
				break;
		}
		
		delete arbolPalabras;
		delete tablaCapitulos;
		delete tablaAlfabetica;
				
	}
		
}

void Articulo::salir(){
	
	exit(0);
	
}
