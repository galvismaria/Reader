#include "Articulo.h"
  /* ---------------- Inicializador de los atributos de la clase Articulo----------------------*/
Articulo::Articulo(){

	arbolPalabras = new ArbolAVL();
	tablaCapitulos = new Hash();
	tablaAlfabetica = new Hash();
	capitulosTotales = 0;
	paginasTotales = 0;
	lineasTotales = 0;
	palabrasTotales = 0;
	palabrasUnicas = 0;

}
 
 /*------------------------------Extraer el número de un string---------------------------------*/ 
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

/*------------------------------Verificar si el stirng es un número-------------------------------*/ 
bool Articulo::esNumero( string str ){
	
    for (int i = 0; i < str.length(); i++)

        //Verifica si el string ingresado es una palabra o un número.
        if ( isdigit ( str[i] ) == false) 
            return false;    //En caso de que no sea un número.
 
    return true;   //En caso de que sea un número.
	
}

/*------------------------------Cargar la tabla hash alfabética------------------------------------*/ 
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
        //Busca los capítulos del archivo
        if ( linea.find("capitulo") != std::string::npos ){
        	
        	capitulosTotales++;          //Almacena la cantidad de capitulos que contiene el archivo.
        	cap = extraerNumero(linea);  //Extrae el número del capítulo.
		//Busca las páginas del archivo
        } else if (linea.find("pagina") != std::string::npos){
			
			paginasTotales++;            //Almacena la cantidad de páginas que contiene el archivo.
            pag = extraerNumero(linea);  //Extrae el número de la página.

        } else{
        	
        	while ( iss >> palabra ){  
        			/*Extrae las palsbras mayúsculas del archivo y las convierte en minúsculas */
        		transform (palabra.begin(), palabra.end(), palabra.begin(), ::tolower); 
        		
	        	string str;
	        		
				/* Verifica si la palabra tiene asociada un valor alfanumérico. */
	        	for( char c : palabra ) if( std::isalpha(c) ) str += c ;
	        			
	        	if ( !esNumero(str) ){
	        		/*Inserta las palabras en el árbol.*/
	        		arbolPalabras->insertarNodo( new Palabra (str, line, pag ), line, pag );
	        		
	        		palabrasTotales++; //Almacena la cantidad de palbras que contiene el archivo.
				}
        		
			}
        	
		}
        	
        line++; 
        
	}

	//Almacena la cantidad de páginas que contiene el archivo.
	lineasTotales = line; 
    crearTablaAlfabetica( arbolPalabras->getRaiz(), true );
    palabrasUnicas = arbolPalabras->palabrasUnicas( arbolPalabras->getRaiz(), 0 );
     
};

/*------------------------------Cargar la tabla hash de capítulos---------------------------------*/ 
void Articulo::cargarTablaCapitulos(){
	
    string nombreArchivo = "file.txt";
    
    ifstream archivo( nombreArchivo.c_str() );
    
    if (!archivo){
    	
       cout << "Error: No se consiguio el archivo"<< endl;
       return;
       
    }
    
    string linea;
    int line = 1, cap = 0, pag = 0;
    bool flag = true;
    
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
	        		
	        	for( char c : palabra ) if( std::isalpha(c) ) str += c ;
	        			
	        	if ( !esNumero(str) ){
							
					arbolPalabras->insertarNodo( new Palabra (str, line, pag ), line, pag );
					
				}
        		
			}

		}
		
		line++;
		
		if ( cap >= 0 && flag ){
        		
        	crearTablaCapitulos( arbolPalabras->getRaiz(), true, cap );
        	arbolPalabras = new ArbolAVL();
        	flag = false;
        		
		}	
     
	}
		
    crearTablaCapitulos( arbolPalabras->getRaiz(), true, cap );

}

/*--------------------------Imprime el contenido del archivo -------------------------------------------*/
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

/*----------------------------Imprime las variables totales del archivo-------------------------------*/
void Articulo::cargarTotalDocumento(){
	
	system("cls");
	
	cout<< "\n\n\t----------- Conteo total  -----------\n\n"<<endl;
	
    cout << "\tNumero de lineas en total: "<< --lineasTotales << endl;
    cout << "\tNumero de palabras en total: "<< palabrasTotales<< endl;
    cout << "\tNumero de palabras unicas: " << palabrasUnicas << endl;
    cout << "\tNumero de capitulos en total: "<< capitulosTotales << endl;
    cout << "\tNumero de paginas en total: "<< paginasTotales << endl;
    cout << "\n\n\t" << endl;
     
	system("pause");
}

/*----------------------------Inserta las palabras en el árbol-------------------------------*/
void Articulo::insertarPalabra( string palabra, int linea, int pagina ){
	
	arbolPalabras->insertarNodo( new Palabra (palabra, linea, pagina), linea, pagina );
	
}

/*------------------------------Crea la tabla hash alfabética---------------------------------*/ 
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

/*------------------------------Crea la tabla hash de capítulos---------------------------------*/
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

/*--------------------------------Imprime el índice de las palabras-------------------------------*/
void Articulo::indiceLineas(){
	
	bool flag = true;
	
	while ( flag ){
		
		system("cls");
		cout << "\n\n";
		tablaAlfabetica->imprimirLineas();
		flag = borrarIndiceAlfabetico();
	}
	
}
 
/*----------------------------------Imprime el índice de las páginas--------------------------------*/ 
void Articulo::indicePaginas(){
	
	bool flag = true;
	
	while ( flag ){
		
		system("cls");
		cout << "\n\n";
		tablaAlfabetica->imprimirPaginas();
		flag = borrarIndiceAlfabetico();
		
	}
	
}
/*---------------------------Imprime el índice de los capítulos------------------------------*/ 
void Articulo::indiceCapitulo( int capitulo ){
	
	bool flag = true;
	
	while ( flag ){
		
		system("cls");
		cout << "\n\n";
		tablaCapitulos->imprimirCapitulo( capitulo );
		flag = borrarIndiceCapitulo(capitulo);
		
	}
	
}

/*------------------------------Imprime los capítulos--------------------------------------------*/ 
void Articulo::mostrarCapitulos(){
	
	int opcion;
	
	system("cls");
	cout << "\n\n";
	tablaCapitulos->mostrarCapitulos();
	cout << "\n\tDesplegar indice del capitulo: ";
	
	bool flag = false;
	
	while ( !flag ) {
			
		cin >> opcion;
			
		if ( (opcion >= 0) && (opcion <= capitulosTotales ) ){
			
			flag = true;
			
		}
				
		else{
			
			cout << "\n\n\tError, intente de nuevo.\n\t";
			cin.clear();
			cin.ignore(200, '\n');
				
		}
	}
	
	indiceCapitulo( opcion );
	
}

/*------------------------------Busca una palabra en la tabla hash alfabética -----------------------*/ 
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
		cout <<"\n\n\t\tSe encuentra en las lineas:\n\n";
		resultado->mostrarLineas();
		cout <<"\n\t\tSe encuentra en las paginas:\n\n";
		resultado->mostrarPaginas();
		cout <<"\n\t\t";
		system("pause");
		
	}

}

/*----------------------------Elimina una palabra en la tabla hash alfabética --------------------*/
bool Articulo::borrarIndiceAlfabetico(){
	
	string palabra;
	Palabra *resultado;
	
	cout << "\n\n\t(Ingrese 's' para salir)\n\tInserte palabra a eliminar:";
	
	cin >> palabra;
	
	if ( palabra == "s" || palabra == "S" ){
		
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

/*----------------------------Elimina una palabra en la tabla hash de capitulos --------------------*/
bool Articulo::borrarIndiceCapitulo( int capitulo ){
	
	string palabra;
	Palabra *resultado;
	
	cout << "\n\n\t(Ingrese 's' para salir)\n\tInserte palabra a eliminar:";
	
	cin >> palabra;
	
	if ( palabra == "s" || palabra == "S"){
		
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

/*------------------------------------Imprime el Menú principal--------------------------------------*/ 
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
				"\n\n\t\t5. Imprimir documento" <<
				"\n\n\t\t6. Conteo total" <<
				"\n\n\t\t7. Salir\n\n\n\n";
				
		cout << "\t----------------------------------------------------------------------------------------------------" << " \n\n\t\t";
	
		bool flag = false;
		int opcion;
	
		while ( !flag ) {
			
			cin >> opcion;
			
			if ( (opcion >= 1) && (opcion <= 7) ){  
			
				flag = true;
			
			}
				
			else{
			
				cout << "\n\n\tError, intente de nuevo.\n\t";
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
					
			case(5):
			
				mostrarArchivo();
				break;	
			
			case(6):
			
				cargarTotalDocumento();
				break;
				
			case(7):
				
				salir();			
				
			default:
				
				break;
		}
		
	}
		
}

/*--------------------------------------Salir del programa-----------------------------------------*/
void Articulo::salir(){
	
	exit(0);
	
}
 /*---------------------------------------Destructor de la clase------------------------------------*/
Articulo::~Articulo(){
	
	delete [] arbolPalabras;
	delete [] tablaCapitulos;
	delete [] tablaAlfabetica;
	delete &capitulosTotales;
	delete &paginasTotales;
	delete &lineasTotales;
	delete &palabrasTotales;
	delete &palabrasUnicas;
	
}
