#include "Articulo.h"

Articulo::Articulo(){

	arbolPalabras = new ArbolAVL();
	tablaCapitulos = new Hash();
	tablaAlfabetica = new Hash();
	lineasTotales = 0;
	capitulosTotales = 0;
	paginasTotales = 0;
	palabrasUnicas = 0;

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

void Articulo::cargarTablaAlfabetica(){
	
    string nombreArchivo = "file.txt";
    
    ifstream archivo( nombreArchivo.c_str() );
    
    if (!archivo){
    	
       cout << "Error: No se consiguio el archivo"<< endl;
       return;
       
    }
    
    string linea;
    int line = 1, cap = 0, pag = 0;
    
    while ( getline (archivo, linea) ) {
        
        istringstream iss(linea);
        string palabra;
        
        if ( linea.find("capitulo") != std::string::npos ){
        	
        	capitulosTotales++;
        	cap = extraerNumero(linea);

        } else if (linea.find("pagina") != std::string::npos){
			
			paginasTotales++;
            pag = extraerNumero(linea);

        } else{
        	
        	while ( iss >> palabra ){
        		
        		transform (palabra.begin(), palabra.end(), palabra.begin(), ::tolower);
        		
        		string str;
        		
        		for( char c : palabra ) if( std::isalnum(c) ) str += c ;
  
        		arbolPalabras->insertarNodo( new Palabra (str, line, pag + 1 ), line, pag + 1 );
        		
        		palabrasTotales++;
        		
			}
        	
		}
        	
        line++;
        
	}
	
	lineasTotales = line;
    
    crearTablaAlfabetica( arbolPalabras->getRaiz(), true );
    palabrasUnicas = arbolPalabras->palabrasUnicas( arbolPalabras->getRaiz(), 0 );
     
};

void Articulo::cargarTablaCapitulos(){
	
    string nombreArchivo = "file.txt";
    
    ifstream archivo( nombreArchivo.c_str() );
    
    if (!archivo){
    	
       cout << "Error: No se consiguio el archivo"<< endl;
       return;
       
    }
    
    string linea;
    int line = 1, cap = 0, pag = 0;
    bool flag = false;
    
    while ( getline (archivo, linea) ) {
        
        istringstream iss(linea);
        string palabra;
        
        if ( linea.find( "capitulo" ) != std::string::npos ){
        
        	cap = extraerNumero(linea);
        	flag = true;

        } else if ( linea.find( "pagina" ) != std::string::npos ){
			
            pag = extraerNumero(linea);

        } else{
        	
        	while ( iss >> palabra ){
        		
        		transform (palabra.begin(), palabra.end(), palabra.begin(), ::tolower);
        		
        		string str;
        		
        		for( char c : palabra ) if( std::isalnum(c) ) str += c ;
  
        		arbolPalabras->insertarNodo( new Palabra (str, line, pag + 1 ), line, pag + 1 );
        		
			}

		}
		
		line++;
		
		if ( cap > 1 && flag ){
        		
        	crearTablaCapitulos( arbolPalabras->getRaiz(), true, cap - 1 );
        	arbolPalabras = new ArbolAVL();
        	flag = false;
        		
		}	
     
	}
		
    crearTablaCapitulos( arbolPalabras->getRaiz(), true, cap );

}

void Articulo::mostrarArchivo(){
	
	system("cls");
	
	setlocale(LC_ALL, "");
	
    string nombreArchivo = "file.txt";
    
    ifstream archivo(nombreArchivo.c_str());
    
    if (!archivo){
     	
       cout << "No se consiguio el archivo "<< endl;
       
    }
    
    string linea;
    int cap, pag;
    
    cout<< "\t----------------------------------- Contenido del archivo -----------------------------------\n\n"<<endl;
	
	int i = 1, x;
	
	while ( getline(archivo, linea) )	{
		
		if ( linea.find( "capitulo" ) != string::npos ){
			
			cap = extraerNumero(linea);
			
			getline(archivo, linea);
			
			if ( linea.find( "pagina" ) != string::npos ){
				
				pag = extraerNumero(linea);
				
			}
				
	      	printf( " \t\n\n-----------------------------------\033[1;93mInicio del capitulo %d - desde la pagina %d\033[0m", cap, pag );
			cout << "-----------------------------------\n\n" << endl;
			
			getline(archivo, linea);
	    }
	        
		cout << linea << endl;
		
	}
   
	system ("pause");
}

void Articulo::cargarTotalDocumento(){
	
	system("cls");
	
    cout << "\tNumero de lineas en total: "<< --lineasTotales << endl;
    cout << "\tNumero de palabras en total: "<< palabrasTotales<< endl;
    cout << "\tNumero de palabras unicas: " << palabrasUnicas << endl;
    cout << "\tNumero de capitulos en total: "<< capitulosTotales << endl;
    cout << "\tNumero de paginas en total: "<< paginasTotales << endl;
    cout<<endl;
     
	system("pause");
}

void Articulo::insertarPalabra( string palabra, int linea, int pagina ){
	
	arbolPalabras->insertarNodo( new Palabra (palabra, linea, pagina), linea, pagina );
	
}

void Articulo::crearTablaAlfabetica( Nodo *nodo, bool esRaiz ){
	
	if ( esRaiz )
		nodo = arbolPalabras->getRaiz();
	
	if ( nodo->getIzquierda() )
		crearTablaAlfabetica( nodo->getIzquierda(), false );
	
	if ( nodo->getInfo()->getPalabra() != "\0" )
		tablaAlfabetica->insertar( new Palabra ( nodo->getInfo() ) );
	
	if ( nodo->getDerecha() )
		crearTablaAlfabetica( nodo->getDerecha(), false );
	
}

void Articulo::crearTablaCapitulos( Nodo *nodo, bool esRaiz, int capitulo ){
	
	if ( esRaiz )
		nodo = arbolPalabras->getRaiz();
	
	if ( nodo->getIzquierda() )
		crearTablaCapitulos( nodo->getIzquierda(), false, capitulo );
	
	if ( nodo->getInfo()->getPalabra() != "\0" )
		tablaCapitulos->insertar( new Palabra ( nodo->getInfo() ), capitulo );
	
	if ( nodo->getDerecha() )
		crearTablaCapitulos( nodo->getDerecha(), false, capitulo );
	
}

void Articulo::indiceLineas(){
	
	bool flag = true;
	
	while ( flag ){
		
		system("cls");
		cout << "\n\n";
		tablaAlfabetica->imprimirLineas();
		flag = borrarIndiceAlfabetico();
	}
	
}

void Articulo::indicePaginas(){
	
	bool flag = true;
	
	while ( flag ){
		
		system("cls");
		cout << "\n\n";
		tablaAlfabetica->imprimirPaginas();
		flag = borrarIndiceAlfabetico();
		
	}
	
}

void Articulo::indiceCapitulo( int capitulo ){
	
	bool flag = true;
	
	while ( flag ){
		
		system("cls");
		cout << "\n\n";
		tablaCapitulos->imprimirCapitulo( capitulo );
		flag = borrarIndiceCapitulo(capitulo);
		
	}
	
}

void Articulo::mostrarCapitulos(){
	
	int opcion;
	
	system("cls");
	cout << "\n\n";
	tablaCapitulos->mostrarCapitulos();
	cout << "\n\tDesplegar indice del capitulo: ";
	
	cin >> opcion;
	
	indiceCapitulo( opcion );
	
}

void Articulo::busquedaPalabra(){
	
	string palabra;
	Palabra *resultado;
	
	system("cls");
	cout << "\n\n\tInserte palabra a buscar: ";
	
	cin >> palabra;
	
	resultado = tablaAlfabetica->buscarPalabra(palabra);
	
	if ( resultado->getPalabra() == "\0" ){
		
		system("cls");
		cout <<"\n\n\n\n\t\t";
		cout << "La busqueda no arrojo ningun resultado" << endl;
		cout <<"\n\n\t\t";
		system("pause");
		
	} else{
		
		system("cls");
		cout <<"\n\n\n\t\t";
		resultado->imprimir();
		cout <<"\n\n\t\tSe encuentra en las lineas: ";
		resultado->mostrarLineas();
		cout <<"\n\t\tSe encuentra en las paginas: ";
		resultado->mostrarPaginas();
		cout <<"\n\t\t";
		system("pause");
		
	}

}

bool Articulo::borrarIndiceAlfabetico(){
	
	string palabra;
	Palabra *resultado;
	
	cout << "\n\n\t(Ingrese 's' para salir)\n\tInserte palabra a eliminar:";
	
	cin >> palabra;
	
	if ( palabra == "s" ){
		
		return false;
		
	} else{
		
		resultado = tablaAlfabetica->buscarPalabra( palabra );
	
		if ( resultado->getPalabra() == "\0" ){
		
			cout <<"\n\n\n\n\t\t";
			cout << "La palabra no se encuentra en el indice" << endl;
			cout <<"\n\n\t\t";
			system("pause");
			return false;
			
		} else{
			
			tablaAlfabetica->eliminar( resultado );
			return true;
			
		}
		
	}
		
}

bool Articulo::borrarIndiceCapitulo( int capitulo ){
	
	string palabra;
	Palabra *resultado;
	
	cout << "\n\n\t(Ingrese 's' para salir)\n\tInserte palabra a eliminar:";
	
	cin >> palabra;
	
	if ( palabra == "s" ){
		
		return false;
		
	} else{
		
		resultado = tablaCapitulos->buscarPalabra( palabra, capitulo );
	
		if ( resultado->getPalabra() == "\0" ){
		
			cout <<"\n\n\n\n\t\t";
			cout << "La palabra no se encuentra en el indice" << endl;
			cout <<"\n\n\t\t";
			system("pause");
			return false;
			
		} else{
			
			tablaCapitulos->eliminar( resultado, capitulo );
			return true;
			
		}
		
	}
		
}

void Articulo::menuPrincipal(){
	
	cargarTablaAlfabetica();
	cargarTablaCapitulos();
	
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
		
		switch (opcion) {
			
			case(1):
				
				indiceLineas();						
				break;
				
			case(2):
				
				indicePaginas();
				break;
				
			case(3):
			
				mostrarCapitulos();
				break;
				
			case(4):
			
				busquedaPalabra();
				break;
					
			case(6):
			
				mostrarArchivo();
				break;	
			
			case(7):
			
				cargarTotalDocumento();
				break;
				
			case(8):
				
				salir();			
				
			default:
				
				break;
		}
		
	}
		
}

void Articulo::salir(){
	
	exit(0);
	
}
