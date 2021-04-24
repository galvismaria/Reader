
struct Capitulo{
    int pag, Capitulos;
    string palabras;
};

void Archivo(){
    Capitulo  letra;
    setlocale(LC_ALL, "");
    string nombreArchivo = "textoprueba-corto.txt";
    ifstream archivo(nombreArchivo.c_str());
     if (!archivo){
       cout << "No se consiguio el archivo "<< endl;
    }
    string linea;
    int Line = 1, capitulos = 0, Pag = 0;
    // Obtener línea de archivo, y almacenar contenido en "linea"
    while (getline(archivo, linea)) {
        // Lo vamos imprimiendo
        
        if (linea.find("capitulo") != std::string::npos){
            capitulos++;
            cout << linea << endl;

        }
          if (linea.find("pagina") != std::string::npos){
             Pag++;
             cout << linea << endl;
        }
             Line++ ;
             //cout << linea << endl;
    }
     cout << "Numero de lineas en total: "<< --Line << endl;
     cout << "Numero de capitulos en total: "<<capitulos << endl;
     cout << "Numero de paginas: "<< Pag << endl;
}
 
