#define negro "\033[1;30m"
#define negrita   "\033[1m\033[30m"  
#define blanco "\033[1;39m"
#define blancofuerte   "\033[1m\033[37m"  
#define rojo "\033[1;31m"
#define rojofuerte     "\033[1m\033[31m" 
#define verde "\033[1;32m"
#define verdefuerte   "\033[1m\033[32m"
#define amarillo "\033[1;33m"
#define amarillofuerte  "\033[1m\033[33m"
#define azul "\033[1;34m"
#define azulfuerte     "\033[1m\033[34m" 
#define morado "\033[1;35m"
#define cian "\033[1;36m"
#define cianfuerte    "\033[1m\033[36m"
#define magenta "\033[35m"                   
#define magentafuerte "\033[1m\033[35m"          
   
#define rest "\033[0m"

#include <iostream>
#include <iomanip>
#include <string>
#include <stdlib.h>
#include "CristoFinity.h"

using namespace std;

CristoFinity::CristoFinity(){

	//Inicializacion del vector del Catalogo
	TotalMediaCatalogo = 0;
	Catalogo = new Media *[this->TotalMediaCatalogo+1];
    if (!this->Catalogo){
        cout << rojo << "Error en el sistema" << rest << endl;
        exit(-1);
    }

   	//Inicializacion del vector del Usuario
	TotalUsuarios = 0;
	VectorUsuarios = new Usuario *[this->TotalUsuarios+1];
    if (!this->VectorUsuarios){
        cout << rojo << "Error en el sistema" << rest << endl;
        exit(-1);
    }

    UsuarioActivo = 0;
    ValoracionesSistema = 0;
    ComentariosSistema = 0;
}

CristoFinity::~CristoFinity(){

	for(int i = 0; i < TotalMediaCatalogo; i++){
		Catalogo[i]->~Media();
	}

	delete[] Catalogo;
}

void CristoFinity::setValoracionesSistema(){

	for(int i = 0; i < TotalMediaCatalogo; i++){
		this->ValoracionesSistema = this->ValoracionesSistema + Catalogo[i]->getTotalValoraciones();
	}

	//cout << rojo << "val " << ValoracionesSistema << rest << endl;
}

void CristoFinity::setComentariosSistema(){

	for(int i = 0; i < TotalMediaCatalogo; i++){
		this->ComentariosSistema = this->ComentariosSistema + Catalogo[i]->getTotalComentarios();
	}
}

void CristoFinity::calcularFormula(){
	for(int i = 0; i < TotalMediaCatalogo; i++){
		Catalogo[i]->calcularFormulaGeneral(ValoracionesSistema, ComentariosSistema);
	}
}

int CristoFinity::getTotalMediaCatalogo(){
	return this->TotalMediaCatalogo;
}

int CristoFinity::getTotalUsuarios(){
	return this->TotalUsuarios;
}

float CristoFinity::consultarMediaGeneralDeMediaEnCatalogo(){
	if(TotalMediaCatalogo != 0){

		int opcion = 0;
		int posicion = 0;

		if(TotalMediaCatalogo != 0){
			cout << magentafuerte << "Bienvenido a la pestaña de eliminacion de un media " << endl;
			cout << "En primer lugar escoge el id del media que quieres eliminar " << rest << endl;

			printTitulosCatalogo();

			cin >> opcion;
			posicion = this->buscarMediaID(opcion);

			cout << azulfuerte << "La valoracion en el catalogo de " << cianfuerte << Catalogo[posicion]->getTitulo() << azulfuerte << " es de: " << cianfuerte << Catalogo[posicion]->getNotaGeneral() << rest << endl;;
		}
	}
}

void CristoFinity::resizeCatalogoMas(){

    TotalMediaCatalogo++;

    Media **c = new Media *[this->TotalMediaCatalogo+1]; 

    if (c == 0){
        cout << rojo << "Error. No hay memoria suficiente. Se abortará la ejecución" << rest << endl;
        exit(-1);
    }

    for(int i = 0; i < TotalMediaCatalogo; i++){
        c[i] = this->Catalogo[i];
    }

    delete[] this->Catalogo;
    this->Catalogo = c;
    c = 0;
}

void CristoFinity::resizeCatalogoMenos(){

	TotalMediaCatalogo--;

    Media **c = new Media *[this->TotalMediaCatalogo+1];

    if (c == 0){
        cout << rojo << "Error. No hay memoria suficiente. Se abortará la ejecución" << rest << endl;
        exit(-1);
    }

    for(int i = 0; i < TotalMediaCatalogo; i++){
        c[i] = this->Catalogo[i];
    }

    delete[] this->Catalogo;
    this->Catalogo = c;
    c = 0;
}

void CristoFinity::resizeUsuariosMas(){

    TotalUsuarios++;

    Usuario **c = new Usuario *[this->TotalUsuarios+1]; 

    if (c == 0){
        cout << rojo << "Error. No hay memoria suficiente. Se abortará la ejecución" << rest << endl;
        exit(-1);
    }

    for(int i = 0; i < TotalUsuarios; i++){
        c[i] = this->VectorUsuarios[i];
    }

    delete[] this->VectorUsuarios;
    this->VectorUsuarios = c;
    c = 0;
}

void CristoFinity::resizeUsuariosMenos(){

	TotalUsuarios--;

    Usuario **c = new Usuario *[this->TotalUsuarios+1];

    if (c == 0){
        cout << rojo << "Error. No hay memoria suficiente. Se abortará la ejecución" << rest << endl;
        exit(-1);
    }

    for(int i = 0; i < TotalUsuarios; i++){
        c[i] = this->VectorUsuarios[i];
    }

    delete[] this->VectorUsuarios;
    this->VectorUsuarios = c;
    c = 0;
}



void CristoFinity::MenuPrincipal(){

	int opcion = 0;
	bool MenusUsers = false;
	bool MenuPrincipal = false;
	UsuarioActivo = 0;
	int cont = 0;

	if(cont == 0){
		importarXML();
		cont++;
	}

	do{
		MenusUsers = false;
		UsuarioActivo = 0;
		cout << magentafuerte << "Bienvenido a CristoFinity, tu portal de contenido multimedia donde pasar horas y horas, logueate si eres miembro o registrate si aun no disfrutas de nuestro maravilloso portal " << rest << endl;
		cout << amarillofuerte << "[1] " << cianfuerte << "Acceder al portal de CristoFinity " << rest << endl;
		cout << amarillofuerte << "[2] " << cianfuerte << "Registrarte " << rest << endl;
		cout << amarillofuerte << "[3] " << cianfuerte << "Salir/Exportar y destruir " << rest << endl;

		cin >> opcion;

		if(opcion == 1){
			this->login();
		}else if(opcion == 2){
			this->usuarioNuevo();
		}else{
			MenuPrincipal = true;
		}

		if(Administrador *ad = dynamic_cast<Administrador *> (UsuarioActivo)){
			MenuAdministrador(MenusUsers);
		}else if(Normal *nor = dynamic_cast<Normal *> (UsuarioActivo)){
			MenuUserNormal(MenusUsers);
		}
	}while(MenuPrincipal == false);

	exportarXML();
}

void CristoFinity::MenuAdministrador(bool &acaba){

	int opcion = 0;

	do{
		cout << endl;
		cout << magentafuerte << "MENU DE ADMINISTRADOR " << rest << endl;
		cout << azulfuerte << "Usuario Activo: " << cianfuerte << UsuarioActivo->getLogin() << verdefuerte << " (Administrador) " << rest << endl;
		cout << endl;
		cout << amarillofuerte << "[1] " << cianfuerte << "Imprimir el catalogo de medias " << rest << endl;
		cout << amarillofuerte << "[2] " << cianfuerte << "Agregar un nuevo media al catalogo " << rest << endl;
		cout << amarillofuerte << "[3] " << cianfuerte << "Eliminar un media del catalogo " << rest << endl;
		cout << amarillofuerte << "[4] " << cianfuerte << "Modificar datos de un media " << rest << endl;
		cout << amarillofuerte << "[5] " << cianfuerte << "Consultar valoracion general de un media del catalogo" << rest << endl;
		cout << amarillofuerte << "[6] " << cianfuerte << "Buscar un media en el catalogo" << rest << endl;
		cout << amarillofuerte << "[7] " << cianfuerte << "Imprimir busquedas" << rest << endl;
		cout << amarillofuerte << "[8] " << cianfuerte << "Rankings " << rest << endl;
		cout << amarillofuerte << "[9] " << cianfuerte << "Agregar un usuario al sistema " << rest << endl;
		cout << amarillofuerte << "[10] " << cianfuerte << "Eliminar un usuario del sistema" << rest << endl;
		cout << amarillofuerte << "[11] " << cianfuerte << "Imprimir usuarios del sistema" << rest << endl;
		cout << amarillofuerte << "[12] " << cianfuerte << "Buscar un usuario en el sistema" << rest << endl;
		cout << amarillofuerte << "[13] " << cianfuerte << "Imprimir vector de busquedas de Usuarios normales" << rest << endl;
		cout << amarillofuerte << "[14] " << cianfuerte << "Modificar datos de un usuario del sistema" << rest << endl;
		cout << amarillofuerte << "[15] " << cianfuerte << "Añadir comentario a un media " << rest << endl;
		cout << amarillofuerte << "[16] " << cianfuerte << "Eliminar comentario de un media" << rest << endl;
		cout << amarillofuerte << "[17] " << cianfuerte << "Modificar valoracion de un media" << rest << endl;
		cout << amarillofuerte << "[18] " << cianfuerte << "Reiniciar vector de busquedas" << rest << endl;
		cout << amarillofuerte << "[19] " << cianfuerte << "Reiniciar vector de busquedas de usuarios" << rest << endl;
		cout << endl;
		cout << rojo << "[20] " << cianfuerte << "Salir/Cambiar Usuario" << rest << endl;

		cin >> opcion;

        switch(opcion){
            case 1:
            printCatalogo();break;           	
            case 2:
            CreacionMedia();break;
            case 3:
            eliminarMediaCatalogo();break;
            case 4:
            modificarDatosDeMedia();break;
            case 5:
            consultarMediaGeneralDeMediaEnCatalogo();
            pulsaparacontinuar();break;
            case 6:
           	Busquedas();
           	pulsaparacontinuar();break;
            case 7:
            printVectorBusquedas();break;
            case 8:
            Rankings();break;
            case 9:
            usuarioNuevo();break;
            case 10:
            eliminarUsuariosVectorUsuarios();break;
            case 11:
           	printUsuarios();break;
            case 12:
            BusquedasUsuarios();break;   
            case 13:
            printVectorAdministrador();break;			
            case 14:
            modificarDatosCualquierUsuario();
            pulsaparacontinuar();break;
            case 15:
            Comentar();
            pulsaparacontinuar();break;
            case 16:
            eliminarComentarioAdmin();
            pulsaparacontinuar();break; 
			case 17:
			modificarValoracionAdmin();
			pulsaparacontinuar();break; 
            case 18:
            vaciarVectorBusquedas();
            pulsaparacontinuar();break;   
            case 19:
            vaciarVectorBusquedasDeUsuario();
            pulsaparacontinuar();break;
            case 20:
            acaba = true;break;     
        }
	}while(acaba == false);
}

void CristoFinity::MenuUserNormal(bool &acaba){

	int opcion = 0;

	do{
		cout << endl;
		cout << magentafuerte << "MENU DE USUARIO " << rest << endl;
		cout << azulfuerte << "Usuario Activo: " << cianfuerte << UsuarioActivo->getLogin() << verdefuerte << " (Usuario Normal) " << rest << endl;
		cout << endl;
		cout << amarillofuerte << "[1] " << cianfuerte << "Imprimir catalogo de CristoFinity " << rest << endl;
		cout << amarillofuerte << "[2] " << cianfuerte << "Agregar un media a lista de favoritos " << rest << endl;
		cout << amarillofuerte << "[3] " << cianfuerte << "Eliminar un media de la lista de favoritos " << rest << endl;
		cout << amarillofuerte << "[4] " << cianfuerte << "Consultar valoracion general de un media del catalogo" << rest << endl;
		cout << amarillofuerte << "[5] " << cianfuerte << "Buscar un media en el catalogo" << rest << endl;
		cout << amarillofuerte << "[6] " << cianfuerte << "Imprimir busquedas del usuario" << rest << endl;
		cout << amarillofuerte << "[7] " << cianfuerte << "Rankings " << rest << endl;
		cout << amarillofuerte << "[8] " << cianfuerte << "Consultar lista de favoritos " << rest << endl;
		cout << amarillofuerte << "[9] " << cianfuerte << "Consultar en detalle un media de lista de favoritos" << rest << endl;
		cout << amarillofuerte << "[10] " << cianfuerte << "Modificar datos personales" << rest << endl;
		cout << amarillofuerte << "[11] " << cianfuerte << "Añadir comentario a un media " << rest << endl;
		cout << amarillofuerte << "[12] " << cianfuerte << "Eliminar comentario de un media" << rest << endl;
		cout << amarillofuerte << "[13] " << cianfuerte << "Modificar valoracion de un media " << rest << endl;
		cout << amarillofuerte << "[14] " << cianfuerte << "Reiniciar vector de busquedas" << rest << endl;
		cout << endl;
		cout << rojo << "[15] " << cianfuerte << "Salir/Cambiar Usuario" << rest << endl;

		cin >> opcion;

        switch(opcion){
            case 1:
            printCatalogo();break;    
            case 2:
            asociarMediaUsuario();
            pulsaparacontinuar();break;
            case 3:
            desAsociarMediaUsuario();
            pulsaparacontinuar();break;
            case 4:
            consultarMediaGeneralDeMediaEnCatalogo();
            pulsaparacontinuar();break;
            case 5:
            Busquedas();
            pulsaparacontinuar();break;
            case 6:
           	printVectorBusquedas();break;
           	case 7:
           	Rankings();break;
            case 8:
            printAsociadosUsuario();
            pulsaparacontinuar();break;
            case 9:
            printMediaAsociadoDetalle();
            pulsaparacontinuar();break;
            case 10:
            modificarDatosUsuarioActivo();
            pulsaparacontinuar();break;
            case 11:
           	ComentarAsociado();
           	pulsaparacontinuar();break;
            case 12:
            eliminarComentarioDeListaAsociados();
            pulsaparacontinuar();break;
            case 13:
            modificarValoracionUserNormal();
            pulsaparacontinuar();break;
            case 14:
            vaciarVectorBusquedas();
            pulsaparacontinuar();break;
            case 15:
            acaba = true;break;   
        }

	}while(acaba == false);
}


void CristoFinity::login(){

    string loginabuscar;
    int pos_usuario = 0;

    if(TotalUsuarios != 0){
    	do{
	    	cout << magentafuerte << "¿Quien eres? Introduce tu login!, recuerda que debe de ser correcto" << rest << endl;
	    	cin >> loginabuscar;

	    	pos_usuario = buscarLoginUsuario(loginabuscar);
	    }while(pos_usuario == -1);
	    UsuarioActivo = VectorUsuarios[pos_usuario];
	}else{
		cout << rojo << "Lo siento, usted no tiene ninguna cuenta aun, le redirigiré a la pantalla de registro " << rest << endl;
		usuarioNuevo();
	}
}

void CristoFinity::CreacionMedia(){

	int opcion = 0;

	cout << magentafuerte << "Bienvenido a la pestaña de creacion de un media " << endl;
	cout << "En primer lugar escoge que tipo de media quieres crear " << endl;

	cout << azulfuerte << "[1] " << cianfuerte << "Serie " << rest << endl;
	cout << azulfuerte << "[2] " << cianfuerte << "Pelicula " << rest << endl;
	cout << azulfuerte << "[3] " << cianfuerte << "Videojuego " << rest << endl;
	cout << azulfuerte << "[4] " << cianfuerte << "Cancion " << rest << endl;

	cin >> opcion;

	if(opcion == 1){
		this->crearSerieInsertar();
	}else if(opcion == 2){
		this->crearPeliculaInsertar();
	}else if(opcion == 3){
		this->crearVideojuegoInsertar();
	}else if(opcion == 4){
		this->crearCancionInsertar();
	}
}

void CristoFinity::crearSerieInsertar(){
	Serie *s = new Serie;

	cin >> s;

	this->insertarMediaCatalogo(s);
}

void CristoFinity::crearPeliculaInsertar(){
	Pelicula *p = new Pelicula;

	cin >> p;

	this->insertarMediaCatalogo(p);
}

void CristoFinity::crearVideojuegoInsertar(){
	Videojuego *v = new Videojuego;

	cin >> v;

	this->insertarMediaCatalogo(v);
}

void CristoFinity::crearCancionInsertar(){
	Cancion *c = new Cancion;

	cin >> c;

	this->insertarMediaCatalogo(c);
}

void CristoFinity::insertarMediaCatalogo(Media *m){
	this->Catalogo[TotalMediaCatalogo] = m;
	this->resizeCatalogoMas();
	this->ordenarIDMedia();
}

void CristoFinity::ordenarIDMedia(){
	int IDMedia = 1;

	for (int i = 0; i < TotalMediaCatalogo; i++){
		Catalogo[i]->setIDMedia(IDMedia);
		IDMedia++;
	}
}

void CristoFinity::modificarDatosDeMedia(){

	int opcion = 0;
	int posicion = 0;

	if(TotalMediaCatalogo != 0){
		cout << magentafuerte << "Bienvenido a la pestaña de modificacion de un media " << endl;
		cout << "En primer lugar escoge el id del media que quieres modificar " << rest << endl;
		cout << verde << "AVISO: solo se modificaran sus datos, sus comentarios y valoraciones quedaran intactas " << rest << endl;

		printTitulosCatalogo();

		cin >> opcion;
		posicion = this->buscarMediaID(opcion);

		modificarDatosMediaDelCatalogo(Catalogo[posicion]);
	}else{
		cout << rojo << "Lo siento, actualmente no hay medias en el catalogo " << rest << endl;
	}
}

void CristoFinity::modificarDatosMediaDelCatalogo(Media *m){

	if(Cancion *can = dynamic_cast<Cancion *> (m)){
		cin >> can;
	}else if(Serie *ser = dynamic_cast<Serie *> (m)){
		cin >> ser;
	}else if(Pelicula *pel = dynamic_cast<Pelicula *> (m)){
		cin >> pel;
	}else if(Videojuego *vid = dynamic_cast<Videojuego *> (m)){
		cin >> vid;
	}	
}

void CristoFinity::printCatalogo(){

	int opcion = 0;

	if(TotalMediaCatalogo != 0){
		cout << magentafuerte << "Actualmente tenemos estos medias en el catalogo " << rest << endl;

		printTitulosCatalogo();

		cout << magentafuerte << "¿Que desea hacer? " << rest << endl;
		cout << amarillofuerte << "[1] Imprimir el catalogo entero " << rest << endl;
		cout << amarillofuerte << "[2] Imprimir un media en detalle " << rest << endl;

		cin >> opcion;

		if(opcion == 1){
			for(int i = 0; i < TotalMediaCatalogo; i++){
				if(Cancion *can = dynamic_cast<Cancion *> (Catalogo[i])){
					//cout << rojo << "DEBUG PRINT MEDIAS POLIMORFICOS 1 " << rest << endl;
					cout << can << endl;
				}else if(Serie *ser = dynamic_cast<Serie *> (Catalogo[i])){
					//cout << rojo << "DEBUG PRINT MEDIAS POLIMORFICOS 2 " << rest << endl;
					cout << ser << endl;
				}else if(Pelicula *pel = dynamic_cast<Pelicula *> (Catalogo[i])){
					//cout << rojo << "DEBUG PRINT MEDIAS POLIMORFICOS 3 " << rest << endl;
					cout << pel << endl;
				}else if(Videojuego *vid = dynamic_cast<Videojuego *> (Catalogo[i])){
					//cout << rojo << "DEBUG PRINT MEDIAS POLIMORFICOS 4 " << rest << endl;
					cout << vid << endl;
				}
			}
		}else if(opcion == 2){
			printMediaDetalle();
		}
	}else{
		cout << rojo << "Actualmente no hay medias en el catalogo " << rest << endl;
	}
}

void CristoFinity::printMediaDetalle(){

	int opcion = 0;
	int posicion = 0;

	cout << magentafuerte << "¿Que media desea imprimir en detalle?, introduce su ID" << rest << endl;
	cin >> opcion;

	posicion = buscarMediaID(opcion);

	if(Cancion *can = dynamic_cast<Cancion *> (Catalogo[posicion])){
		cout << can << endl;
	}else if(Serie *ser = dynamic_cast<Serie *> (Catalogo[posicion])){
		cout << ser << endl;
	}else if(Pelicula *pel = dynamic_cast<Pelicula *> (Catalogo[posicion])){
		cout << pel << endl;
	}else if(Videojuego *vid = dynamic_cast<Videojuego *> (Catalogo[posicion])){
		cout << vid << endl;
	}

}

void CristoFinity::printMediaAsociadoDetalle(){
	if(Normal *nor = dynamic_cast <Normal *> (UsuarioActivo)){
		nor->printMediaAsociadoDetalle();
	}
}

void CristoFinity::printTitulosCatalogo(){
	if(TotalMediaCatalogo != 0){
		for(int i = 0; i < getTotalMediaCatalogo(); i++){
			cout << amarillofuerte << "[" << Catalogo[i]->getIDMedia() << "]" << cianfuerte << Catalogo[i]->getTitulo() << rest << endl;
		}
	}else{
		cout << rojo << "Actualmente no hay medias en el catalogo " << rest << endl;
	}
}

void CristoFinity::eliminarMediaCatalogo(){

	if(TotalMediaCatalogo != 0){

		int opcion = 0;
		int posicion = 0;

		if(TotalMediaCatalogo != 0){
			cout << magentafuerte << "Bienvenido a la pestaña de eliminacion de un media " << endl;
			cout << "En primer lugar escoge el id del media que quieres eliminar " << rest << endl;

			printTitulosCatalogo();

			cin >> opcion;
			posicion = this->buscarMediaID(opcion);
			//DESASOCIAR EL MEDIA ELIMINADO DEL CATALOGO
			for(int i = 0; i < TotalUsuarios; i++){
				if(Normal *nor = dynamic_cast<Normal *> (VectorUsuarios[i])){
					nor->eliminarMediaAsociado(opcion);
				}
			}
			//FIN DEL DESASOCIO
			eliminarMedia(posicion);

			this->calcularFormulas();
		}else{
			cout << rojo << "Lo siento, no hay medias disponibles para borrar " << rest << endl;
		}
	}else{
		cout << rojo << "Actualmente no hay medias en el catalogo " << rest << endl;
	}
}

void CristoFinity::eliminarMedia(int posicion){

	Media *aux = new Media;

	aux = Catalogo[TotalMediaCatalogo-1];
	Catalogo[TotalMediaCatalogo-1] = Catalogo[posicion];
	Catalogo[posicion] = aux;

	aux = 0;
	Catalogo[TotalMediaCatalogo-1]->~Media();
	resizeCatalogoMenos();
	ordenarIDMedia();

}

void CristoFinity::Busquedas(){

	if(TotalMediaCatalogo != 0){
		int opcion = 0;
		int ID = 0;
		int ID_Pos = 0;
		string titulo;
		float nota = 0.0;

		cout << magentafuerte << "Bienvenido a la pestaña de busquedas, aqui podras buscar por diferentes parametros, los distintos medias que tenemos en el catalogo " << endl;
		cout << "Introduce el parametro por el que deseas buscar " << rest << endl;
		cout << amarillofuerte << "[1] " << cianfuerte << "Por ID del media " << rest << endl;
		cout << amarillofuerte << "[2] " << cianfuerte << "Por titulo " << rest << endl;
		cout << amarillofuerte << "[3] " << cianfuerte << "Por nota media exacta " << rest << endl;
		cout << amarillofuerte << "[4] " << cianfuerte << "Por nota media mayor que.. " << rest << endl;
		cout << amarillofuerte << "[5] " << cianfuerte << "Por nota media menor que.. " << rest << endl;

		cin >> opcion;

		if(opcion == 1){
			cout << magentafuerte << "Introduce el ID del media que quieres buscar " << endl;
			cin >> ID;

			ID_Pos = buscarMediaID(ID);

			if(ID_Pos != -1){
				UsuarioActivo->insertarMediaEnListaDeBusqueda(Catalogo[ID_Pos]);
			}

		}else if(opcion == 2){
			cout << magentafuerte << "Introduce el titulo del media que quieres buscar " << endl;
			cin.clear();
			cin.ignore();
			getline(cin, titulo);

			buscarMediaTituloEinsertarEnVectorDelUsuario(titulo);

		}else if(opcion == 3){
			cout << magentafuerte << "Introduce la nota media exacta del media que quieres buscar " << endl;
			cin >> nota;

			buscarMediaNotaMediaEinsertarEnVectorDelUsuario(nota);

		}else if(opcion == 4){
			cout << magentafuerte << "Introduce la nota media minima del media que quieres buscar " << endl;
			cin >> nota;

			buscarMediaNotaMediaMayorEinsertarEnVectorDelUsuario(nota);

		}else if(opcion == 5){
			cout << magentafuerte << "Introduce la nota media maxima del media que quieres buscar " << endl;
			cin >> nota;

			buscarMediaNotaMediaMenorEinsertarEnVectorDelUsuario(nota);
		}
	}else{
		cout << rojo << "Actualmente no hay medias en el catalogo " << rest << endl;
	}
}

int CristoFinity::buscarMediaID(int id){
	int posicion = -1;

	for(int i = 0; i < TotalMediaCatalogo; i++){
		if(Catalogo[i]->getIDMedia() == id){
			posicion = i;
		}
	}
	return posicion;
}

int CristoFinity::buscarMediaTituloEinsertarEnVectorDelUsuario(string titulo){

	bool encontrado = false;
	int cont = 0;

	for(int i = 0; i < TotalMediaCatalogo; i++){
		if(encontrado == Catalogo[i]->getTitulo().find(titulo)){
			UsuarioActivo->insertarMediaEnListaDeBusqueda(Catalogo[i]);
			cont++;
		}
	}

	if(cont != 0){
		cout << verde << "Se han encontrado " << cianfuerte << cont << " resultados " << rest << endl;
	}else{
		cout << rojo << "Lo siento, no ha habido ningun resultado " << rest << endl;
	}
}

int CristoFinity::buscarMediaNotaMediaEinsertarEnVectorDelUsuario(float notaMedia){

	int cont = 0;

	for(int i = 0; i < TotalMediaCatalogo; i++){
		if(Catalogo[i]->getNotaMedia() == notaMedia){
			UsuarioActivo->insertarMediaEnListaDeBusqueda(Catalogo[i]);
			cont++;
		}
	}

	if(cont != 0){
		cout << verde << "Se han encontrado " << cianfuerte << cont << " resultados " << rest << endl;
	}else{
		cout << rojo << "Lo siento, no ha habido ningun resultado " << rest << endl;
	}
}

int CristoFinity::buscarMediaNotaMediaMayorEinsertarEnVectorDelUsuario(float notaMinima){

	int cont = 0;

	for(int i = 0; i < TotalMediaCatalogo; i++){
		if(Catalogo[i]->getNotaMedia() > notaMinima){
			UsuarioActivo->insertarMediaEnListaDeBusqueda(Catalogo[i]);
			cont++;
		}
	}

	if(cont != 0){
		cout << verde << "Se han encontrado " << cianfuerte << cont << " resultados " << rest << endl;
	}else{
		cout << rojo << "Lo siento, no ha habido ningun resultado " << rest << endl;
	}
}

int CristoFinity::buscarMediaNotaMediaMenorEinsertarEnVectorDelUsuario(float notaMaxima){

	int cont = 0;

	for(int i = 0; i < TotalMediaCatalogo; i++){
		if(Catalogo[i]->getNotaMedia() < notaMaxima){
			UsuarioActivo->insertarMediaEnListaDeBusqueda(Catalogo[i]);
			cont++;
		}
	}

	if(cont != 0){
		cout << verde << "Se han encontrado " << cianfuerte << cont << " resultados " << rest << endl;
	}else{
		cout << rojo << "Lo siento, no ha habido ningun resultado " << rest << endl;
	}
}

void CristoFinity::BusquedasUsuarios(){
	if(Administrador *ad = dynamic_cast<Administrador *> (UsuarioActivo)){

			int opcion = 0;
			string login;
			int Login_Pos = 0;
			string nombre;
			string apellido;

			cout << magentafuerte << "Bienvenido a la pestaña de busquedas de usuarios, aqui podras buscar por diferentes parametros los usuarios normales del sistema " << endl;
			cout << "Introduce el parametro por el que deseas buscar " << rest << endl;
			cout << amarillofuerte << "[1] " << cianfuerte << "Por login (es unico) " << rest << endl;
			cout << amarillofuerte << "[2] " << cianfuerte << "Por nombre " << rest << endl;
			cout << amarillofuerte << "[3] " << cianfuerte << "Por apellido " << rest << endl;

			cin >> opcion;

			if(opcion == 1){
				cout << magentafuerte << "Introduce el login del usuario que quieres buscar " << endl;
				cin >> login;

				Login_Pos = buscarLoginUsuario(login);

				ad->insertarUsuarioEnVectorBusquedasUsuario(VectorUsuarios[Login_Pos]);

			}else if(opcion == 2){
				cout << magentafuerte << "Introduce el nombre del usuario que quieres buscar " << endl;
				cin.clear();
				cin.ignore();
				getline(cin, nombre);

				buscarUsuarioPorNombreEinsertarEnVectorDeAdministrador(nombre);

			}else if(opcion == 3){
				cout << magentafuerte << "Introduce el/los apellidos del usuario que quieres buscar " << endl;
				cin.clear();
				cin.ignore();
				getline(cin, apellido);

				buscarUsuarioPorApellidoEinsertarEnVectorDeAdministrador(apellido);

			}
	}else{
		cout << rojo << "Esta operacion no esta disponible para usted " << rest << endl;
	}
}

void CristoFinity::buscarUsuarioPorNombreEinsertarEnVectorDeAdministrador(string nombre){

	if(Administrador *ad = dynamic_cast<Administrador *> (UsuarioActivo)){
		bool encontrado = false;
		int cont = 0;

		for(int i = 0; i < TotalUsuarios; i++){
			if(encontrado == VectorUsuarios[i]->getNombre().find(nombre)){
				ad->insertarUsuarioEnVectorBusquedasUsuario(VectorUsuarios[i]);
				cont++;
			}
		}

		//cout << rojo << "DEBUG BUSQUEDAS USUARIO 4" << rest << endl;

		if(cont != 0){
			cout << verde << "Se han encontrado " << cianfuerte << cont << " resultados " << rest << endl;
		}else{
			cout << rojo << "Lo siento, no ha habido ningun resultado " << rest << endl;
		}

	}else{
		cout << rojo << "Lo siento esta operacion no esta disponible para usted " << rest << endl;
	}
}

void CristoFinity::buscarUsuarioPorApellidoEinsertarEnVectorDeAdministrador(string apellido){

	if(Administrador *ad = dynamic_cast<Administrador *> (UsuarioActivo)){
		bool encontrado = false;
		int cont = 0;

		for(int i = 0; i < TotalUsuarios; i++){
			if(encontrado == VectorUsuarios[i]->getApellidos().find(apellido)){
				ad->insertarUsuarioEnVectorBusquedasUsuario(VectorUsuarios[i]);
				cont++;
			}
		}

		if(cont != 0){
			cout << verde << "Se han encontrado " << cianfuerte << cont << " resultados " << rest << endl;
		}else{
			cout << rojo << "Lo siento, no ha habido ningun resultado " << rest << endl;
		}

	}else{
		cout << rojo << "Lo siento esta operacion no esta disponible para usted " << rest << endl;
	}
}

void CristoFinity::printVectorBusquedas(){
	if(UsuarioActivo->getTotalBusquedas() != 0){
		UsuarioActivo->printVectorBusquedas();
	}else{
		cout << rojo << "Lo siento, aun no has buscado nada " << rest << endl;
	}
}

void CristoFinity::vaciarVectorBusquedas(){
	UsuarioActivo->vaciarVectorBusquedas();
	cout << endl;
	cout << verdefuerte << "Borrado del vector de busquedas correcto " << rest << endl;
	cout << endl;
}

void CristoFinity::printVectorAdministrador(){

	if(Administrador *ad = dynamic_cast<Administrador *> (UsuarioActivo)){
		cout << ad->getTotalUsuariosBuscados() << endl;
		if(ad->getTotalUsuariosBuscados() != 0){
			ad->printVectorUsuariosBuscados();
		}else{
			cout << rojo << "Lo siento ahora mismo no hay busquedas guardadas " << rest << endl;
		}
	}
}

void CristoFinity::vaciarVectorBusquedasDeUsuario(){
	if(Administrador *ad = dynamic_cast<Administrador *> (UsuarioActivo)){
		cout << endl;
		ad->vaciarVectorUsuariosBuscados();
		cout << verdefuerte << "Borrado del vector de busquedas correcto " << rest << endl;
		cout << endl;
	}
}

void CristoFinity::Rankings(){

	int opcion = 0;

	cout << magentafuerte << "Bienvenido a la pestaña de Rankings, aqui podras consultar los medias mas TOP que tenemos en nuestro catalogo " << endl;
	cout << "Introduce el ranking que quieres consultar " << rest << endl;
	cout << endl;
	cout << rojo << "AVISO: Es recomendable reiniciar el vector de busquedas antes de seleccionar cualquier busqueda" << rest << endl;
	cout << endl;

	cout << amarillofuerte << "[1] " << cianfuerte << "TOP 3 por nota general " << rest << endl;
	cout << amarillofuerte << "[2] " << cianfuerte << "TOP 3 por tipo de media " << rest << endl;
	cout << amarillofuerte << "[3] " << cianfuerte << "Ranking de usuarios " << rest << endl;

	cin >> opcion;

	if(opcion == 1){
		this->top3NotaGeneral();
	}else if(opcion == 2){
		this->top3TipoMedia();
	}else if(opcion == 3){
		this->rankingUsuarios();
	}
}


// (RANKINGS PENDIENTES DE HACER)

void CristoFinity::top3NotaGeneral(){

	int opcion = 0;

	cout << magentafuerte << "Dentro de la clasificacion de medias tenemos los distintos rankings " << rest << endl;
	cout << rojo << "Nota: este tipo de busquedas no se haran sobre medias cuya nota general sea 0 " << rest << endl;

	cout << amarillofuerte << "[1] " << cianfuerte << "Top 3 mejores medias del catalogo " << rest << endl;
	cout << amarillofuerte << "[2] " << cianfuerte << "Media Hated " << rest << endl;
	cout << amarillofuerte << "[3] " << cianfuerte << "Media Polemic " << rest << endl;

	cin >> opcion;

	if(opcion == 1){
		this->calcularTop3eInsertarEnVectorBusquedas();
	}else if(opcion == 2){
		this->calcularMediaHatedeInsertarEnVectorBusquedas();
	}else if(opcion == 3){
		this->calcularMediaPolemiceInsertarEnVectorBusquedas();
	}	
}

void CristoFinity::calcularTop3eInsertarEnVectorBusquedas(){
	int posicion_mayor = 0;

	for(int a = 0; a < 3; a++){
		for(int i = 0; i < TotalMediaCatalogo; i++){
			for(int j = 0; j < TotalMediaCatalogo; j++){
				if(UsuarioActivo->compruebaRank(Catalogo[j]) == true){
					if(Catalogo[i]->getIDMedia() != Catalogo[j]->getIDMedia()){
						if(Catalogo[i]->getNotaGeneral() <= Catalogo[j]->getNotaGeneral()){
							posicion_mayor = j;
						}
					}
				}
			}	
		}
		UsuarioActivo->insertarMediaEnListaDeBusqueda(Catalogo[posicion_mayor]);
	}
}

void CristoFinity::calcularMediaHatedeInsertarEnVectorBusquedas(){
	int posicion_mayor = 0;

	for(int i = 0; i < TotalMediaCatalogo; i++){
		for(int j = 0; j < TotalMediaCatalogo; j++){
			if(Catalogo[i]->getNotaGeneral() != 0.0 && Catalogo[j]->getNotaGeneral() != 0.0){
				if(Catalogo[i]->getNotaGeneral() >= Catalogo[j]->getNotaGeneral()){
					if(Catalogo[posicion_mayor]->getNotaGeneral() >= Catalogo[j]->getNotaGeneral()){
						posicion_mayor = j;
					}
				}
			}
		}	
	}
	UsuarioActivo->insertarMediaEnListaDeBusqueda(Catalogo[posicion_mayor]);
}

//ARREGLAR MEDIA POLEMIC
void CristoFinity::calcularMediaPolemiceInsertarEnVectorBusquedas(){

	int dimensionvectoresaux = 50;

	Media **aux1 = new Media*[dimensionvectoresaux];
	Media **aux2 = new Media*[dimensionvectoresaux];

	for(int i = 0; i < TotalMediaCatalogo && i < dimensionvectoresaux; i++){
		aux1[i] = Catalogo[i];
		aux2[i] = Catalogo[i];
	}

	//ORDENAR VECTOR POR MAYOR COMENTARIOS AUXILIAR 1

	Media *auxgeneral = new Media;

	int posmin1; //Posicion del vector desordenado donde se encuentra el elemento mas pequeño

	for(int i = 0; i < TotalMediaCatalogo && i < dimensionvectoresaux; i++){
		posmin1 = i;	
		for (int j = i+1; j < TotalMediaCatalogo && j < dimensionvectoresaux; j++){
			if (aux1[posmin1]->getTotalComentarios() < aux1[j]->getTotalComentarios()){
				posmin1 = j;
			}

		}
		auxgeneral = aux1[i];
		aux1[i] = aux1[posmin1];
		aux1[posmin1] = auxgeneral;
	}

	auxgeneral = 0;

	//FIN ORDENACION POR MAYOR DE COMENTARIOS VECTOR AUXILIAR 1

	//ORDENAR VECTOR POR MENOR NOTA GENERAL AUXILIAR 2

	int pos_min2 = 0;

	for(int i = 0; i < TotalMediaCatalogo && i < dimensionvectoresaux; i++){
		pos_min2 = i;	
		for (int j = i+1; j < TotalMediaCatalogo && j < dimensionvectoresaux; j++){
			if (aux2[j]->getNotaGeneral() < aux2[pos_min2]->getNotaGeneral()){
				pos_min2 = j;
			}

		}
		auxgeneral = aux2[i];
		aux2[i] = aux2[pos_min2];
		aux2[pos_min2] = auxgeneral;
	}

	auxgeneral = 0;

	//FIN ORDENACION VECTOR POR MENOR NOTA GENERAL AUXILIAR 2

	int posicion_correcta = 0;
	int suma = 0;
	int sumaactual = 1000;

	for(int i = 0; i < TotalMediaCatalogo && i < dimensionvectoresaux; i++){
		for(int j = 0; j < TotalMediaCatalogo && j < dimensionvectoresaux; j++){
			if(aux1[i]->getIDMedia() == aux2[j]->getIDMedia()){
				suma = (i+1) + (j+1);
				cout << rojo << "suma" << suma << rest << endl;
				if(suma < sumaactual){
					sumaactual = suma;
					cout << rojo << "sumaactual" << sumaactual << rest << endl;
					posicion_correcta = aux1[i]->getIDMedia();
				}
			}
		}
	}

	UsuarioActivo->insertarMediaEnListaDeBusqueda(Catalogo[posicion_correcta-1]);
}

	//INICIO RANKING 2

void CristoFinity::top3TipoMedia(){

	int opcion = 0;

	cout << magentafuerte << "Elige el ranking en base al tipo de media que quieres ver " << rest << endl;

	cout << amarillofuerte << "[1] " << cianfuerte << "Top 3 Series " << rest << endl;
	cout << amarillofuerte << "[2] " << cianfuerte << "Top 3 Peliculas" << rest << endl;
	cout << amarillofuerte << "[3] " << cianfuerte << "Top 3 Videojuegos " << rest << endl;
	cout << amarillofuerte << "[4] " << cianfuerte << "Top 3 Canciones " << rest << endl;

	cin >> opcion;

	if(opcion == 1){
		this->top3Series();
	}else if(opcion == 2){
		this->top3Peliculas();
	}else if(opcion == 3){
		this->top3Videojuegos();
	}else if(opcion == 4){
		this->top3Canciones();
	}	
}

void CristoFinity::top3Series(){
	int opcion = 0;

	cout << magentafuerte << "Dentro de la clasificacion de series tenemos los distintos rankings " << rest << endl;

	cout << amarillofuerte << "[1] " << cianfuerte << "Top 3 mejores series del catalogo " << rest << endl;
	cout << amarillofuerte << "[2] " << cianfuerte << "Serie Hated " << rest << endl;
	cout << amarillofuerte << "[3] " << cianfuerte << "Serie Polemic " << rest << endl;

	cin >> opcion;

	if(opcion == 1){
		this->calcularTop3SerieseInsertarEnVectorBusquedas();
	}else if(opcion == 2){
		this->mediaHatedSerieseInsertarEnVectorDeBusquedas();
	}else if(opcion == 3){
		this->mediaPolemicSerieseInsertarEnVectorDeBusquedas();
	}
}

void CristoFinity::calcularTop3SerieseInsertarEnVectorBusquedas(){

	int posicion_mayor = 0;

	for(int a = 0; a < 3; a++){
		for(int i = 0; i < TotalMediaCatalogo; i++){
			if(Serie *ser1 = dynamic_cast<Serie *> (Catalogo[i])){
				for(int j = 0; j < TotalMediaCatalogo; j++){
					if(Serie *ser2 = dynamic_cast<Serie *> (Catalogo[j])){
						if(UsuarioActivo->compruebaRank(ser2) == true){
							if(ser1->getIDMedia() != ser2->getIDMedia()){
								if(ser1->getNotaGeneral() <= ser2->getNotaGeneral()){
									posicion_mayor = j;
								}
							}
						}
					}
				}	
			}		
		}
		UsuarioActivo->insertarMediaEnListaDeBusqueda(Catalogo[posicion_mayor]);
	}
}

void CristoFinity::top3Peliculas(){
	int opcion = 0;

	cout << magentafuerte << "Dentro de la clasificacion de peliculas tenemos los distintos rankings " << rest << endl;

	cout << amarillofuerte << "[1] " << cianfuerte << "Top 3 mejores peliculas del catalogo " << rest << endl;
	cout << amarillofuerte << "[2] " << cianfuerte << "Pelicula Hated " << rest << endl;
	cout << amarillofuerte << "[3] " << cianfuerte << "Pelicula Polemic " << rest << endl;

	cin >> opcion;

	if(opcion == 1){
		this->calcularTop3PeliculaseInsertarEnVectorBusquedas();
	}else if(opcion == 2){
		this->mediaHatedPeliculaseInsertarEnVectorDeBusquedas();
	}else if(opcion == 3){
		this->mediaPolemicPeliculaseInsertarEnVectorDeBusquedas();
	}
}

void CristoFinity::calcularTop3PeliculaseInsertarEnVectorBusquedas(){

	int posicion_mayor = 0;

	for(int a = 0; a < 3; a++){
		for(int i = 0; i < TotalMediaCatalogo; i++){
			if(Pelicula *pel1 = dynamic_cast<Pelicula *> (Catalogo[i])){
				for(int j = 0; j < TotalMediaCatalogo; j++){
					if(Pelicula *pel2 = dynamic_cast<Pelicula *> (Catalogo[j])){
						if(UsuarioActivo->compruebaRank(pel2) == true){
							if(pel1->getIDMedia() != pel2->getIDMedia()){
								if(pel1->getNotaGeneral() <= pel2->getNotaGeneral()){
									posicion_mayor = j;
								}
							}
						}
					}
				}	
			}		
		}
		UsuarioActivo->insertarMediaEnListaDeBusqueda(Catalogo[posicion_mayor]);
	}
}

void CristoFinity::top3Videojuegos(){
	int opcion = 0;

	cout << magentafuerte << "Dentro de la clasificacion de videojuegos tenemos los distintos rankings " << rest << endl;

	cout << amarillofuerte << "[1] " << cianfuerte << "Top 3 mejores videojuegos del catalogo " << rest << endl;
	cout << amarillofuerte << "[2] " << cianfuerte << "Videojuego Hated " << rest << endl;
	cout << amarillofuerte << "[3] " << cianfuerte << "Videojuego Polemic " << rest << endl;

	cin >> opcion;

	if(opcion == 1){
		this->calcularTop3VideojuegoseInsertarEnVectorBusquedas();
	}else if(opcion == 2){
		this->mediaHatedVideojuegoseInsertarEnVectorDeBusquedas();
	}else if(opcion == 3){
		this->mediaPolemiVideojuegoseInsertarEnVectorDeBusquedas();
	}
}

void CristoFinity::calcularTop3VideojuegoseInsertarEnVectorBusquedas(){
	int posicion_mayor = 0;

	for(int a = 0; a < 3; a++){
		for(int i = 0; i < TotalMediaCatalogo; i++){
			if(Videojuego *vid1 = dynamic_cast<Videojuego *> (Catalogo[i])){
				for(int j = 0; j < TotalMediaCatalogo; j++){
					if(Videojuego *vid2 = dynamic_cast<Videojuego *> (Catalogo[j])){
						if(UsuarioActivo->compruebaRank(vid2) == true){
							if(vid1->getIDMedia() != vid2->getIDMedia()){
								if(vid1->getNotaGeneral() <= vid2->getNotaGeneral()){
									posicion_mayor = j;
								}
							}
						}
					}
				}	
			}		
		}
		UsuarioActivo->insertarMediaEnListaDeBusqueda(Catalogo[posicion_mayor]);
	}
}

void CristoFinity::top3Canciones(){
	int opcion = 0;

	cout << magentafuerte << "Dentro de la clasificacion de canciones tenemos los distintos rankings " << rest << endl;

	cout << amarillofuerte << "[1] " << cianfuerte << "Top 3 mejores canciones del catalogo " << rest << endl;
	cout << amarillofuerte << "[2] " << cianfuerte << "Cancion Hated " << rest << endl;
	cout << amarillofuerte << "[3] " << cianfuerte << "Cancion Polemic " << rest << endl;

	cin >> opcion;

	if(opcion == 1){
		this->calcularTop3CancioneseInsertarEnVectorBusquedas();
	}else if(opcion == 2){
		this->mediaHatedCancioneseInsertarEnVectorDeBusquedas();
	}else if(opcion == 3){
		this->mediaPolemicCancioneseInsertarEnVectorDeBusquedas();
	}
}

void CristoFinity::calcularTop3CancioneseInsertarEnVectorBusquedas(){
	int posicion_mayor = 0;

	for(int a = 0; a < 3; a++){
		for(int i = 0; i < TotalMediaCatalogo; i++){
			if(Cancion *can1 = dynamic_cast<Cancion *> (Catalogo[i])){
				for(int j = 0; j < TotalMediaCatalogo; j++){
					if(Cancion *can2 = dynamic_cast<Cancion *> (Catalogo[j])){
						if(UsuarioActivo->compruebaRank(can2) == true){
							if(can1->getIDMedia() != can2->getIDMedia()){
								if(can1->getNotaGeneral() <= can2->getNotaGeneral()){
									posicion_mayor = j;
								}
							}
						}
					}
				}	
			}		
		}
		UsuarioActivo->insertarMediaEnListaDeBusqueda(Catalogo[posicion_mayor]);
	}
}

	//FIN DE RANKING 2

void CristoFinity::rankingUsuarios(){

}

void CristoFinity::usuarioNuevo(){

	int opcion = 0;

	cout << magentafuerte << "Bienvenido a la pestaña de creacion de usuario " << endl;
	cout << "Introduce el tipo de usuario que quieres crear " << rest << endl;
	cout << endl;
	cout << amarillofuerte << "[1] " << cianfuerte << "Administrador " << rest << endl;
	cout << amarillofuerte << "[2] " << cianfuerte << "Usuario Normal " << rest << endl;
	cout << endl;

	cin >> opcion;

	if(opcion == 1){
		crearAdministradorInsertar();
	}else if(opcion == 2){
		crearNormalInsertar();
	}
}

void CristoFinity::crearAdministradorInsertar(){
	Administrador *a = new Administrador;
	string login;
	bool logincorrecto = true;

	do{
		cout << azulfuerte << "Introduce un login disponible: " << azul << endl;
		cin >> login;
		for(int i = 0; i < TotalUsuarios; i++){
			if(VectorUsuarios[i]->getLogin() == login){
				logincorrecto = false;
				cout << rojo << "Este login ya esta en uso " << rest << endl;
				i = TotalUsuarios;
			}else{
				logincorrecto = true;
			}
		}
	}while(logincorrecto == false);



	if(logincorrecto == true){
		a->setLogin(login);
	}

	cin >> a;

	insertarUsuario(a);
}

void CristoFinity::crearNormalInsertar(){
	Normal *n = new Normal;

	string login;
	bool logincorrecto = true;

	do{
		cout << azulfuerte << "Introduce un login disponible: " << azul << endl;
		cin >> login;
		for(int i = 0; i < TotalUsuarios; i++){
			if(VectorUsuarios[i]->getLogin() == login){
				logincorrecto = false;
				cout << rojo << "Este login ya esta en uso " << rest << endl;
				i = TotalUsuarios;
			}else{
				logincorrecto = true;
			}
		}
	}while(logincorrecto == false);


	if(logincorrecto == true){
		n->setLogin(login);
	}

	cin >> n;

	insertarUsuario(n);
}

void CristoFinity::insertarUsuario(Usuario *u){
	VectorUsuarios[TotalUsuarios] = u;
	resizeUsuariosMas();
}

void CristoFinity::printUsuarios(){

	cout << magentafuerte << "Estos son los usuarios que hay en el sistema actualmente " << rest << endl;

	for(int i = 0; i < getTotalUsuarios(); i++){
		if(Administrador *ad = dynamic_cast<Administrador *> (VectorUsuarios[i])){
			cout << amarillofuerte << "Administrador " << rest << endl;
			cout << ad << endl;
		}else if(Normal *nor = dynamic_cast<Normal *> (VectorUsuarios[i])){
			cout << amarillofuerte << "Usuario Normal " << rest << endl;
			cout << nor << endl;
		}
	}
}

void CristoFinity::printLoginUsuarios(){

	for(int i = 0; i < getTotalUsuarios(); i++){
		if(Administrador *ad = dynamic_cast<Administrador *> (VectorUsuarios[i])){
			cout << verdefuerte << "Administrador" << rest << endl;
			cout << amarillofuerte << "[" << i << "]" << cianfuerte << ad->getLogin() << rest << endl;
		}else if(Normal *no = dynamic_cast <Normal *> (VectorUsuarios[i])){
			cout << verdefuerte << "Usuario Normal" << rest << endl;
			cout << amarillofuerte << "[" << i << "]" << cianfuerte << no->getLogin() << rest << endl;
		}
	}

}

void CristoFinity::modificarDatosCualquierUsuario(){

	string login;
	string antiguologin;
	int posicion = 0;

	cout << magentafuerte << "Elija el usuario que quiere modificar " << endl;
	cout << "Introduce su login " << rest << endl;
	printLoginUsuarios();

	cin >> login;

	posicion = this->buscarLoginUsuario(login);

	if(posicion != -1){
		if(Normal *no = dynamic_cast <Normal *> (VectorUsuarios[posicion])){
			antiguologin = no->getLogin();
			//FILTRO DE LOGIN
			string login;
			bool logincorrecto = true;

			do{
				cout << azulfuerte << "Introduce un login disponible: " << azul << endl;
				cin >> login;
				for(int i = 0; i < TotalUsuarios; i++){
					if(VectorUsuarios[i]->getLogin() == login){
						logincorrecto = false;
						cout << rojo << "Este login ya esta en uso " << rest << endl;
						i = TotalUsuarios;
					}else{
						logincorrecto = true;
					}
				}
			}while(logincorrecto == false);

			if(logincorrecto == true){
				no->setLogin(login);
			}

			//FIN DE FILTRO DE LOGIN
			cin >> VectorUsuarios[posicion];
		}else{
			modificarDatosUsuarioActivo();
		}
		for(int i = 0; i < TotalMediaCatalogo; i++){
			Catalogo[i]->cambiarLoginComentariosValoracion(antiguologin, VectorUsuarios[posicion]->getLogin());
		}
	}
}

void CristoFinity::modificarDatosUsuarioActivo(){

	string antiguologin;

	if(Administrador *ad = dynamic_cast<Administrador *> (UsuarioActivo)){
		antiguologin = UsuarioActivo->getLogin();
			//FILTRO DE LOGIN
			string login;
			bool logincorrecto = true;

			do{
				cout << azulfuerte << "Introduce un login disponible: " << azul << endl;
				cin >> login;
				for(int i = 0; i < TotalUsuarios; i++){
					if(VectorUsuarios[i]->getLogin() == login){
						logincorrecto = false;
						cout << rojo << "Este login ya esta en uso " << rest << endl;
						i = TotalUsuarios;
					}else{
						logincorrecto = true;
					}
				}
			}while(logincorrecto == false);

			if(logincorrecto == true){
				ad->setLogin(login);
			}

			//FIN DE FILTRO DE LOGIN
		cin >> UsuarioActivo;
	}else if(Normal *no = dynamic_cast <Normal *> (UsuarioActivo)){
		antiguologin = UsuarioActivo->getLogin();
			//FILTRO DE LOGIN
			string login;
			bool logincorrecto = true;

			do{
				cout << azulfuerte << "Introduce un login disponible: " << azul << endl;
				cin >> login;
				for(int i = 0; i < TotalUsuarios; i++){
					if(VectorUsuarios[i]->getLogin() == login){
						logincorrecto = false;
						cout << rojo << "Este login ya esta en uso " << rest << endl;
						i = TotalUsuarios;
					}else{
						logincorrecto = true;
					}
				}
			}while(logincorrecto == false);

			if(logincorrecto == true){
				no->setLogin(login);
			}

			//FIN DE FILTRO DE LOGIN
		cin >> UsuarioActivo;
	}

	for(int i = 0; i < TotalMediaCatalogo; i++){
		Catalogo[i]->cambiarLoginComentariosValoracion(antiguologin, UsuarioActivo->getLogin());
	}
}

void CristoFinity::eliminarUsuariosVectorUsuarios(){

	string log;
	int posicion = 0;

	if(TotalUsuarios != 0){
		cout << magentafuerte << "Bienvenido a la pestaña de eliminacion de un usuario " << endl;
		cout << "Escoge el login del usuario que quieres eliminar " << rest << endl;

		printLoginUsuarios();

		cin >> log;

		posicion = this->buscarLoginUsuario(log);
		if(UsuarioActivo != VectorUsuarios[posicion]){
			if(posicion != -1){
				if(Normal *nor = dynamic_cast<Normal *> (VectorUsuarios[posicion])){
					nor->eliminarMeGustas();
					for(int i = 0; i < TotalMediaCatalogo; i++){
						Catalogo[i]->eliminarComentariosDeUsuario(nor->getLogin());
						Catalogo[i]->eliminarValoracionesDeUsuario(nor->getLogin());
					}
					eliminarUsuario(posicion);
				}else{
					cout << rojo << "Lo siento no puedes eliminar a un administrador " << rest << endl;
				}
			}else{
				cout << rojo << "No existe un usuario con ese login " << rest << endl;
			}
		}else{
			cout << rojo << "Lo siento, no puedes eliminarte tu mismo " << rest << endl;
		}
	}else{
		cout << rojo << "Lo siento, no hay usuarios disponibles para borrar " << rest << endl;
	}

	this->calcularFormulas();	
}

void CristoFinity::eliminarUsuario(int posicion){

	Usuario *aux = new Usuario;

	aux = VectorUsuarios[posicion];
	VectorUsuarios[posicion] = VectorUsuarios[TotalUsuarios-1];
	VectorUsuarios[TotalUsuarios-1] = aux;

	resizeUsuariosMenos();

	//CALCULOS PARA LA FORMULA GENERAL
	this->calcularFormulas();
}

int CristoFinity::buscarLoginUsuario(string login){

	int posicion = -1;

	for(int i = 0; i < TotalUsuarios; i++){
		if(VectorUsuarios[i]->getLogin() == login){
			posicion = i;
		}
	}

	return posicion;
}

void CristoFinity::asociarMediaUsuario(){

	if(TotalMediaCatalogo != 0){
		int opcion = 0;
		int posicion = 0;

		if(Normal *nor = dynamic_cast<Normal *> (UsuarioActivo)){
			cout << magentafuerte << "Escoge el media que quieres asociarte " << endl;
			cout << "Introduce su ID " << rest << endl;

			printTitulosCatalogo();

			cin >> opcion;

			posicion = buscarMediaID(opcion);

			if(nor->comprobarMedia(Catalogo[posicion]) == false){
				if(Catalogo[posicion]->comprobarValoracion(UsuarioActivo->getLogin()) == true){
					escribirComentario(posicion);
					escribirValoracion(posicion);
				}

				nor->insertarEnVectorAsociados(Catalogo[posicion]);

				//CALCULOS PARA LA FORMULA GENERAL
				this->calcularFormulas();	
			}else{
				cout << rojo << "Lo siento, ya te has asociado este media " << rest << endl; 
			}	
		}else{
			cout << rojo << "Lo siento, esta accion no esta disponible para usted " << rest << endl;
		}
	}
}

void CristoFinity::printAsociadosUsuario(){

	if(Normal *nor = dynamic_cast<Normal *> (UsuarioActivo)){
		if(nor->getTotalAsociados() != 0){
			cout << magentafuerte << "Estos son tus medias asociados actualmente " << endl;
			nor->printMediaAsociados();
		}else{
			cout << rojo << "Lo siento, aun no tienes medias asociados " << rest << endl;
		}
	}
}

void CristoFinity::desAsociarMediaUsuario(){

	if(Normal *nor = dynamic_cast<Normal *> (UsuarioActivo)){
		if(nor->getTotalAsociados() != 0){
			int opcion = 0;

			cout << magentafuerte << "Escoge el media que quieres desasociarte " << endl;
			cout << "Introduce su ID " << rest << endl;

			this->printAsociadosUsuario();

			cin >> opcion;

			nor->eliminarMediaAsociado(opcion);

			//CALCULOS PARA LA FORMULA GENERAL
			this->calcularFormulas();
		}else{
			cout << rojo << "Lo siento, aun no tienes medias asociados " << rest << endl;
		}
	}else{
		cout << rojo << "Lo siento, esta accion no esta disponible para usted " << rest << endl;
	}
}

void CristoFinity::Comentar(){

	int opcion = 0;
	int posicion = 0;

	cout << magentafuerte << "Elige el media del que quieres escribir un comentario " << rest << endl;

	printTitulosCatalogo();

	cin >> opcion;

	posicion = buscarMediaID(opcion);

	escribirComentario(posicion);

	//CALCULOS PARA LA FORMULA GENERAL
	this->calcularFormulas();
}

void CristoFinity::Valorar(){

	int opcion = 0;
	int posicion = 0;

	if(Administrador *ad = dynamic_cast <Administrador *> (UsuarioActivo)){

		cout << magentafuerte << "Elige el media del que quieres escribir un comentario " << rest << endl;

		printTitulosCatalogo();

		cin >> opcion;

		posicion = buscarMediaID(opcion);

		escribirValoracion(posicion);

		//CALCULOS PARA LA FORMULA GENERAL
		this->calcularFormulas();
	}else{
		cout << rojo << "Esta operacion no esta disponible para ti " << rest << endl;
	}
}

void CristoFinity::escribirComentario(int posicion){

	cout << magentafuerte << "Escribe un comentario para " << cianfuerte << Catalogo[posicion]->getTitulo() << rest << endl;

	Comentario *c = new Comentario;

	c->setLogin(UsuarioActivo->getLogin());

	cin >> c;

	Catalogo[posicion]->insertarComentario(c);
}

void CristoFinity::escribirValoracion(int posicion){

	cout << magentafuerte << "Que valoracion quieres darle a " << cianfuerte << Catalogo[posicion]->getTitulo() << rest << endl;


	Valoracion *v = new Valoracion;

	v->setLogin(UsuarioActivo->getLogin());

	cin >> v;
		
	Catalogo[posicion]->insertarValoracion(v);
}

void CristoFinity::ComentarAsociado(){

	if(Normal *nor = dynamic_cast <Normal *> (UsuarioActivo)){
		nor->ComentarAsociado();
	}	

	//CALCULOS PARA LA FORMULA GENERAL
	this->calcularFormulas();
}

void CristoFinity::eliminarComentarioDeListaAsociados(){

	if(Normal *nor = dynamic_cast <Normal *> (UsuarioActivo)){
		if(nor->getTotalAsociados() != 0){
			int opcion = 0;
			int posicion = 0;

			cout << endl;
			cout << magentafuerte << "Bienvenido a la pestaña de eliminacion de comentario, en primer lugar elige un media asociado " << rest << endl;
			nor->printMediaAsociados();

			cin >> opcion;

			posicion = buscarMediaID(opcion);

			cout << magentafuerte << "Estos son tus comentarios disponibles en este media: " << rest << endl;

			Catalogo[posicion]->printComentariosPorLogin(nor->getLogin());

			cout << magentafuerte << "Ahora introduce el ID del comentario que quieres eliminar " << rest << endl;

			cin >> opcion;

			if(posicion != -1){
				Catalogo[posicion]->borrarComentario(opcion);
			}else{
				cout << rojo << "No tienes comentarios en este media " << rest << endl;
			}
		}else{
			cout << rojo << "Aun no tienes medias asociados " << rest << endl;
		}
	}else{
		cout << rojo << "Esta opcion no esta disponible para ti " << rest << endl;
	}

	setValoracionesSistema();
	setComentariosSistema();
	calcularFormula();
}

void CristoFinity::modificarValoracionUserNormal(){

	if(Normal *nor = dynamic_cast <Normal *> (UsuarioActivo)){
		if(nor->getTotalAsociados() != 0){
			int opcion = 0;
			int posicion = 0;

			cout << endl;
			cout << magentafuerte << "Bienvenido a la pestaña de modificacion de valoracion, en primer lugar elige la valoracion de que media quieres modificar " << rest << endl;
			nor->printMediaAsociados();

			cin >> opcion;

			posicion = buscarMediaID(opcion);

			Catalogo[posicion]->modificarValoracionPorLogin(nor->getLogin());
		}
	}	

	setValoracionesSistema();
	setComentariosSistema();
	calcularFormula();
}

void CristoFinity::eliminarComentarioAdmin(){

	if(TotalMediaCatalogo != 0){
		int opcion = 0;
		int posicion = 0;

		if(Administrador *ad = dynamic_cast <Administrador *> (UsuarioActivo)){

			cout << magentafuerte << "Elige el media del que quieres escribir un comentario " << rest << endl;

			printTitulosCatalogo();

			cin >> opcion;

			posicion = buscarMediaID(opcion);

			if(Catalogo[posicion]->getTotalComentarios() != 0){

				cout << magentafuerte << "Elige el id del comentario que quieres borrar " << rest << endl;

				Catalogo[posicion]->printComentarios();

				cout << magentafuerte << "Introduce el ID del comentario que quieres borrar " << rest << endl;

				cin >> opcion;

				Catalogo[posicion]->borrarComentario(opcion);
			}

			setValoracionesSistema();
			setComentariosSistema();
			calcularFormula();
		}else{
			cout << rojo << "Este media no tiene actualmente comentarios " << rest << endl;
		}
	}else{
		cout << rojo << "Lo siento, no hay medias actualmente " << rest << endl;
	}
}

void CristoFinity::modificarValoracionAdmin(){
	if(Administrador *nor = dynamic_cast <Administrador *> (UsuarioActivo)){
		if(TotalMediaCatalogo != 0){
			int opcion = 0;
			int posicion = 0;
			string login;

			cout << endl;
			cout << magentafuerte << "Bienvenido a la pestaña de modificacion de valoracion, en primer lugar elige la valoracion de que media quieres modificar " << rest << endl;
			printTitulosCatalogo();

			cin >> opcion;

			posicion = buscarMediaID(opcion);

			Catalogo[posicion]->printValoraciones();

			cout << magentafuerte << "Introduce el login del usuario que quieres borrar la valoracion " << rest << endl;

			cin >> login;

			Catalogo[posicion]->modificarValoracionPorLogin(login);

			setValoracionesSistema();
			setComentariosSistema();
			calcularFormula();
		}
	}else{
		cout << rojo << "No hay medias actualmente " << rest << endl;
	}
}

void CristoFinity::importarXML(){

	pugi::xml_document doc;
	pugi::xml_parse_result result = doc.load_file("cristofinity.xml");
	string tipo;
	string Cadenaxml;
	bool serieacabada = false;

	for(pugi::xml_node node = doc.child("cristofinity").child("catalogo").child("media"); node; node = node.next_sibling("media")){
		cout << endl;
		tipo = node.child("tipo").child_value();

		if(tipo == "Pelicula"){

			Pelicula *p = new Pelicula;

			p->setTitulo(node.child("titulo").child_value());
			p->setGenero(node.child("genero").child_value());
			Cadenaxml = node.child("duracionensegundos").child_value();
			p->setDuracionSeg(atoi(Cadenaxml.c_str()));
			p->setFecha_Publicacion(node.child("fechapublicacion").child_value());
			Cadenaxml = node.child("pegi").child_value();
			p->setPegi(atoi(Cadenaxml.c_str()));
			p->setDescripcion(node.child("descripcion").child_value());
			p->setDirector(node.child("direccion").child_value());
			p->setReparto(node.child("reparto").child_value());
			p->setGuion(node.child("guion").child_value());
			p->setProductor(node.child("productor").child_value());

			this->insertarMediaCatalogo(p);

			cout << "Tipo: " << node.child("tipo").child_value() << endl;
			cout << "IDMedia: " << node.child("idmedia").child_value() << endl;
			cout << "Titulo: " << node.child("titulo").child_value() << endl;
			cout << "Genero: " << node.child("genero").child_value() << endl;
			cout << "Duracion en Segundos: " << node.child("duracionensegundos").child_value() << endl;
			cout << "Fecha de publicacion: " << node.child("fechapublicacion").child_value() << endl;
			cout << "Pegi: " << node.child("pegi").child_value() << endl;
			cout << "Descripcion: " << node.child("descripcion").child_value() << endl;

			cout << "Reparto: " << node.child("reparto").child_value() << endl;
			cout << "Director: " << node.child("direccion").child_value() << endl;
			cout << "Guion: " << node.child("guion").child_value() << endl;
			cout << "Productor: " << node.child("productor").child_value() << endl;

			cout << "Puntuacion: " << node.child("puntuacion").child_value() << endl;
			cout << "Me gusta: " << node.child("totalmegusta").child_value() << endl;
			cout << "Comentarios: " << node.child("totalcomentarios").child_value() << endl;
			cout << endl;	

			cout << "Lista de Comentarios: " << node.child("listacomentarios").child_value() << endl;
			for(pugi::xml_node node2 = node.child("listacomentarios").child("comentario"); node2; node2 = node2.next_sibling("comentario")){

				Comentario *c = new Comentario;

				c->setLogin(node2.child("login").child_value());
				c->setTexto(node2.child("texto").child_value());

				p->insertarComentario(c);

				cout << endl;
				cout << "IDComentario: " << node2.child("idcomentario").child_value() << endl;
				cout << "Login: " << node2.child("login").child_value() << endl;
				cout << "Texto: " << node2.child("texto").child_value() << endl;	
				cout << endl;
			}

			cout << "Lista de Valoraciones: " << node.child("totalvaloraciones").child_value() << endl;
			for(pugi::xml_node node3 = node.child("valoraciones").child("valoracion"); node3; node3 = node3.next_sibling("valoracion")){

				Valoracion *v = new Valoracion;

				v->setLogin(node3.child("idusuario").child_value());
				Cadenaxml = node3.child("puntuacion").child_value();
				v->setPuntuacion(atoi(Cadenaxml.c_str()));
				
				p->insertarValoracion(v);

				cout << endl;
				cout << "Login: " << node3.child("idusuario").child_value() << endl;
				cout << "Puntuacion: " << node3.child("puntuacion").child_value() << endl;	
				cout << endl;
			}

		}else if(tipo == "Cancion"){

			Cancion *c = new Cancion;

			c->setTitulo(node.child("titulo").child_value());
			c->setGenero(node.child("genero").child_value());
			Cadenaxml = node.child("duracionensegundos").child_value();
			c->setDuracionSeg(atoi(Cadenaxml.c_str()));
			c->setFecha_Publicacion(node.child("fechapublicacion").child_value());
			Cadenaxml = node.child("pegi").child_value();
			c->setPegi(atoi(Cadenaxml.c_str()));
			c->setDescripcion(node.child("descripcion").child_value());
			c->setArtista(node.child("artista").child_value());
			c->setAlbum(node.child("album").child_value());

			this->insertarMediaCatalogo(c);

			cout << "Tipo: " << node.child("tipo").child_value() << endl;
			cout << "IDMedia: " << node.child("idmedia").child_value() << endl;
			cout << "Titulo: " << node.child("titulo").child_value() << endl;
			cout << "Genero: " << node.child("genero").child_value() << endl;
			cout << "Duracion en Segundos: " << node.child("duracionensegundos").child_value() << endl;
			cout << "Fecha de publicacion: " << node.child("fechapublicacion").child_value() << endl;
			cout << "Pegi: " << node.child("pegi").child_value() << endl;
			cout << "Descripcion: " << node.child("descripcion").child_value() << endl;

			cout << "Artista: " << node.child("artista").child_value() << endl;
			cout << "Album: " << node.child("album").child_value() << endl;

			cout << "Puntuacion: " << node.child("puntuacion").child_value() << endl;
			cout << "Me gusta: " << node.child("totalmegusta").child_value() << endl;
			cout << "Comentarios: " << node.child("totalcomentarios").child_value() << endl;
			cout << endl;	

			cout << "Lista de Comentarios: " << node.child("listacomentarios").child_value() << endl;
			for(pugi::xml_node node2 = node.child("listacomentarios").child("comentario"); node2; node2 = node2.next_sibling("comentario")){

				Comentario *com = new Comentario;

				com->setLogin(node2.child("login").child_value());
				com->setTexto(node2.child("texto").child_value());

				c->insertarComentario(com);

				cout << endl;
				cout << "IDComentario: " << node2.child("idcomentario").child_value() << endl;
				cout << "Login: " << node2.child("login").child_value() << endl;
				cout << "Texto: " << node2.child("texto").child_value() << endl;	
				cout << endl;
			}

			cout << "Lista de Valoraciones: " << node.child("totalvaloraciones").child_value() << endl;
			for(pugi::xml_node node3 = node.child("valoraciones").child("valoracion"); node3; node3 = node3.next_sibling("valoracion")){

				Valoracion *v = new Valoracion;

				v->setLogin(node3.child("idusuario").child_value());
				Cadenaxml = node3.child("puntuacion").child_value();
				v->setPuntuacion(atoi(Cadenaxml.c_str()));
				
				c->insertarValoracion(v);

				cout << endl;
				cout << "Login: " << node3.child("idusuario").child_value() << endl;
				cout << "Puntuacion: " << node3.child("puntuacion").child_value() << endl;	
				cout << endl;
			}

		}else if(tipo == "Videojuego"){

			Videojuego *v = new Videojuego;

			v->setTitulo(node.child("titulo").child_value());
			v->setGenero(node.child("genero").child_value());
			Cadenaxml = node.child("duracionensegundos").child_value();
			v->setDuracionSeg(atoi(Cadenaxml.c_str()));
			v->setFecha_Publicacion(node.child("fechapublicacion").child_value());
			Cadenaxml = node.child("pegi").child_value();
			v->setPegi(atoi(Cadenaxml.c_str()));
			v->setDescripcion(node.child("descripcion").child_value());
			v->setDesarrollador(node.child("desarrollador").child_value());
			v->setEditor(node.child("editor").child_value());
			Cadenaxml = node.child("jugadores").child_value();
			v->setJugadores(atoi(Cadenaxml.c_str()));
			v->setPlataformas(node.child("plataformas").child_value());

			this->insertarMediaCatalogo(v);

			cout << "Tipo: " << node.child("tipo").child_value() << endl;
			cout << "IDMedia: " << node.child("idmedia").child_value() << endl;
			cout << "Titulo: " << node.child("titulo").child_value() << endl;
			cout << "Genero: " << node.child("genero").child_value() << endl;
			cout << "Duracion en Segundos: " << node.child("duracionensegundos").child_value() << endl;
			cout << "Fecha de publicacion: " << node.child("fechapublicacion").child_value() << endl;
			cout << "Pegi: " << node.child("pegi").child_value() << endl;
			cout << "Descripcion: " << node.child("descripcion").child_value() << endl;

			cout << "Desarrollador: " << node.child("desarrollador").child_value() << endl;
			cout << "Plataformas: " << node.child("plataformas").child_value() << endl;
			cout << "Editor: " << node.child("editor").child_value() << endl;
			cout << "Jugadores: " << node.child("jugadores").child_value() << endl;

			cout << "Puntuacion: " << node.child("puntuacion").child_value() << endl;
			cout << "Me gusta: " << node.child("totalmegusta").child_value() << endl;
			cout << "Comentarios: " << node.child("totalcomentarios").child_value() << endl;
			cout << endl;	

			cout << "Lista de Comentarios: " << node.child("listacomentarios").child_value() << endl;
			for(pugi::xml_node node2 = node.child("listacomentarios").child("comentario"); node2; node2 = node2.next_sibling("comentario")){

				Comentario *c = new Comentario;

				c->setLogin(node2.child("login").child_value());
				c->setTexto(node2.child("texto").child_value());

				v->insertarComentario(c);

				cout << endl;
				cout << "IDComentario: " << node2.child("idcomentario").child_value() << endl;
				cout << "Login: " << node2.child("login").child_value() << endl;
				cout << "Texto: " << node2.child("texto").child_value() << endl;	
				cout << endl;
			}

			cout << "Lista de Valoraciones: " << node.child("totalvaloraciones").child_value() << endl;
			for(pugi::xml_node node3 = node.child("valoraciones").child("valoracion"); node3; node3 = node3.next_sibling("valoracion")){

				Valoracion *val = new Valoracion;

				val->setLogin(node3.child("idusuario").child_value());
				Cadenaxml = node3.child("puntuacion").child_value();
				val->setPuntuacion(atoi(Cadenaxml.c_str()));
				
				v->insertarValoracion(val);

				cout << endl;
				cout << "Login: " << node3.child("idusuario").child_value() << endl;
				cout << "Puntuacion: " << node3.child("puntuacion").child_value() << endl;	
				cout << endl;
			}

		}else if(tipo == "Serie"){

			Serie *s = new Serie;

			s->setTitulo(node.child("titulo").child_value());
			s->setGenero(node.child("genero").child_value());
			Cadenaxml = node.child("duracionensegundos").child_value();
			s->setDuracionSeg(atoi(Cadenaxml.c_str()));
			s->setFecha_Publicacion(node.child("fechapublicacion").child_value());
			Cadenaxml = node.child("pegi").child_value();
			s->setPegi(atoi(Cadenaxml.c_str()));
			s->setDescripcion(node.child("descripcion").child_value());
			s->setDirector(node.child("direccion").child_value());
			s->setReparto(node.child("reparto").child_value());
			s->setGuion(node.child("guion").child_value());
			s->setProductor(node.child("productor").child_value());
			Cadenaxml = node.child("temporadas").child_value();
			s->setTemporadas(atoi(Cadenaxml.c_str()));
			Cadenaxml = node.child("capitulos").child_value();
			s->setCapitulos(atoi(Cadenaxml.c_str()));

			Cadenaxml = node.child("estado").child_value();
			if(Cadenaxml == "finalizada"){
				s->setAcabada(false);
			}else{
				s->setAcabada(true);
			}

			this->insertarMediaCatalogo(s);

			cout << "Tipo: " << node.child("tipo").child_value() << endl;
			cout << "IDMedia: " << node.child("idmedia").child_value() << endl;
			cout << "Titulo: " << node.child("titulo").child_value() << endl;
			cout << "Genero: " << node.child("genero").child_value() << endl;
			cout << "Duracion en Segundos: " << node.child("duracionensegundos").child_value() << endl;
			cout << "Fecha de publicacion: " << node.child("fechapublicacion").child_value() << endl;
			cout << "Pegi: " << node.child("pegi").child_value() << endl;
			cout << "Descripcion: " << node.child("descripcion").child_value() << endl;

			cout << "Reparto: " << node.child("reparto").child_value() << endl;
			cout << "Director: " << node.child("direccion").child_value() << endl;
			cout << "Guion: " << node.child("guion").child_value() << endl;
			cout << "Productor: " << node.child("productor").child_value() << endl;
			cout << "Temporadas: " << node.child("temporadas").child_value() << endl;
			cout << "Capitulos: " << node.child("capitulos").child_value() << endl;
			cout << "Estado: " << node.child("estado").child_value() << endl;		

			cout << "Puntuacion: " << node.child("puntuacion").child_value() << endl;
			cout << "Me gusta: " << node.child("totalmegusta").child_value() << endl;
			cout << "Comentarios: " << node.child("totalcomentarios").child_value() << endl;
			cout << endl;	

			cout << "Lista de Comentarios: " << node.child("listacomentarios").child_value() << endl;
			for(pugi::xml_node node2 = node.child("listacomentarios").child("comentario"); node2; node2 = node2.next_sibling("comentario")){

				Comentario *c = new Comentario;

				c->setLogin(node2.child("login").child_value());
				c->setTexto(node2.child("texto").child_value());

				s->insertarComentario(c);

				cout << endl;
				cout << "IDComentario: " << node2.child("idcomentario").child_value() << endl;
				cout << "Login: " << node2.child("login").child_value() << endl;
				cout << "Texto: " << node2.child("texto").child_value() << endl;	
				cout << endl;
			}

			cout << "Lista de Valoraciones: " << node.child("totalvaloraciones").child_value() << endl;
			for(pugi::xml_node node3 = node.child("valoraciones").child("valoracion"); node3; node3 = node3.next_sibling("valoracion")){

				Valoracion *v = new Valoracion;

				v->setLogin(node3.child("idusuario").child_value());
				Cadenaxml = node3.child("puntuacion").child_value();
				v->setPuntuacion(atoi(Cadenaxml.c_str()));

				s->insertarValoracion(v);
				
				cout << endl;
				cout << "Login: " << node3.child("idusuario").child_value() << endl;
				cout << "Puntuacion: " << node3.child("puntuacion").child_value() << endl;	
				cout << endl;
			}
		}
	}

	string tipousuario;

	for(pugi::xml_node node = doc.child("cristofinity").child("usuarios").child("usuario"); node; node = node.next_sibling("usuario")){

		tipousuario = node.child("tipousuario").child_value();

		if(tipousuario == "admin"){

		Administrador *a = new Administrador;

		a->setLogin(node.child("login").child_value());
		a->setNombre(node.child("nombre").child_value());
		a->setApellidos(node.child("apellidos").child_value());
		a->setFotoPerfil(node.child("urlfotoperfil").child_value());

		this->insertarUsuario(a);

		cout << endl;
		cout << "Tipo: " << node.child("tipousuario").child_value() << endl;
		cout << "Login: " << node.child("login").child_value() << endl;
		cout << "Nombre: " << node.child("nombre").child_value() << endl;
		cout << "Apellidos: " << node.child("apellidos").child_value() << endl;
		cout << "Foto de perfil: " << node.child("urlfotoperfil").child_value() << endl;
		}

		if(tipousuario == "normal"){

		Normal *n = new Normal;

		n->setLogin(node.child("login").child_value());
		n->setNombre(node.child("nombre").child_value());
		n->setApellidos(node.child("apellidos").child_value());
		n->setFotoPerfil(node.child("urlfotoperfil").child_value());

		string aux = node.child("listamedia").child_value(), aux2;
		cout << aux << endl;

		for(int i = 0; i < aux.size(); i++){
			if(aux[i] != ' '){
				aux2 += aux[i];
				n->insertarEnVectorAsociados(Catalogo[atoi(aux2.c_str()) - 1]);
			}else if(aux[i] == ' ' && i != 0){
				aux2.clear();
			}
		}

		this->insertarUsuario(n);

		cout << endl;
		cout << "Tipo: " << node.child("tipousuario").child_value() << endl;
		cout << "Login: " << node.child("login").child_value() << endl;
		cout << "Nombre: " << node.child("nombre").child_value() << endl;
		cout << "Apellidos: " << node.child("apellidos").child_value() << endl;
		cout << "Foto de perfil: " << node.child("urlfotoperfil").child_value() << endl;

		cout << "Lista de favoritos: " << node.child("totallistamedia").child_value() << endl;
		cout << "Lista de media: " << node.child("listamedia").child_value() << endl;

		}
		cout << endl;
	}

	this->calcularFormulas();
}

void CristoFinity::exportarXML(){
	string nombre_fich = "cristofinityexp.xml";

	ofstream fs;
	fs.open(nombre_fich.c_str());

	fs << "<totalcatalogo>" << TotalMediaCatalogo << "</totalcatalogo>" << endl;
	fs << "<totalusuarios>" << TotalUsuarios << "</totalusuarios>" << endl;
	cout << endl;
	fs << "\t<catalogo>" << endl;
	for(int i = 0; i < TotalMediaCatalogo; i++){
		fs << "\t\t<media>" << endl;
		if(Cancion *can = dynamic_cast<Cancion *> (Catalogo[i])){
			fs << "\t\t\t<tipo>Cancion</tipo>" << endl;
			fs << "\t\t\t<idmedia>" << can->getIDMedia() << "</idmedia>" << endl;
			fs << "\t\t\t<titulo>" << can->getTitulo() << "</titulo>" << endl;
			fs << "\t\t\t<genero>" << can->getGenero() << "</genero>" << endl;
			fs << "\t\t\t<duracionensegundos>" << can->getDuracionSegundos() << "</duracionensegundos>" << endl;
			fs << "\t\t\t<pegi>" << can->getPegi() << "</pegi>" << endl;
			fs << "\t\t\t<descripcion>" << can->getDescripcion() << "</descripcion>" << endl;
			fs << "\t\t\t<artista> " << can->getArtista() << "</artista>" << endl;
			fs << "\t\t\t<album>" << can->getAlbum() << "</album>" << endl;
			fs << "\t\t\t<puntuacion>" << can->getNotaMedia() << "</puntuacion>" << endl;
			fs << "\t\t\t<totalmegusta>" << can->getMeGusta() << "</totalmegusta>" << endl;
			fs << "\t\t\t<totalcomentarios>" << can->getTotalComentarios() << "</totalcomentarios>" << endl;
			fs << "\t\t\t<listacomentarios>" << endl;
			for(int i = 0; i < can->getTotalComentarios(); i++){

				fs << "\t\t\t\t<comentario>" << endl;
				fs << "\t\t\t\t\t<idcomentario> " << can->getIDComentario(i) << "</idcomentario>" << endl;
				fs << "\t\t\t\t\t<login>" << can->getLoginComentario(i) << "</login>" << endl;
				fs << "\t\t\t\t\t<texto>" << can->getTextoComentario(i) << "</texto>" << endl;
				fs << "\t\t\t\t</comentario>" << endl;
			}
			fs << "\t\t\t</listacomentarios>" << endl;

			fs << "\t\t\t<totalvaloraciones>" << can->getTotalValoraciones() << "</totalvaloraciones>" << endl;
			fs << "\t\t\t<valoraciones>" << endl;
			for(int i = 0; i < can->getTotalValoraciones(); i++){
				fs << "\t\t\t\t<valoracion>" << endl;
				fs << "\t\t\t\t\t<idusuario>" << can->getLoginValoracion(i) << "</idusuario>" << endl;
				fs << "\t\t\t\t\t<puntuacion>" << can->getPuntuacionValoracion(i) << "</puntuacion>" << endl;
				fs << "\t\t\t\t</valoracion>" << endl;
			}
			fs << "\t\t\t</valoraciones>" << endl;

		}else if(Serie *ser = dynamic_cast<Serie *> (Catalogo[i])){
			fs << "\t\t\t<tipo>Serie</tipo>" << endl;
			fs << "\t\t\t<idmedia>" << ser->getIDMedia() << "</idmedia>" << endl;
			fs << "\t\t\t<titulo>" << ser->getTitulo() << "</titulo>" << endl;
			fs << "\t\t\t<genero>" << ser->getGenero() << "</genero>" << endl;
			fs << "\t\t\t<duracionensegundos>" << ser->getDuracionSegundos() << "</duracionensegundos>" << endl;
			fs << "\t\t\t<pegi>" << ser->getPegi() << "</pegi>" << endl;
			fs << "\t\t\t<descripcion>" << ser->getDescripcion() << "</descripcion>" << endl;
			fs << "\t\t<reparto>" << ser->getReparto() << "</reparto>" << endl;
			fs << "\t\t<direccion>" << ser->getDirector() << "</direccion>" << endl;
			fs << "\t\t<guion>" << ser->getGuion() << "</guion>" << endl;
			fs << "\t\t<productor>" << ser->getProductor() << "</productor>" << endl;
			fs << "\t\t<temporadas>" << ser->getTemporadas() << "</temporadas>" << endl;
			fs << "\t\t<capitulos>" << ser->getCapitulos() << "</capitulos>" << endl;
			fs << "\t\t<estado>";

			if(ser->getAcabada() == true){
				fs <<  "Acabada"; 
			}else{
				fs << "No acabada";
			}
			fs << "</estado>" << endl;
			fs << "\t\t\t<puntuacion>" << ser->getNotaMedia() << "</puntuacion>" << endl;
			fs << "\t\t\t<totalmegusta>" << ser->getMeGusta() << "</totalmegusta>" << endl;
			fs << "\t\t\t<totalcomentarios>" << ser->getTotalComentarios() << "</totalcomentarios>" << endl;
			fs << "\t\t\t<listacomentarios>" << endl;
			for(int i = 0; i < ser->getTotalComentarios(); i++){

				fs << "\t\t\t\t<comentario>" << endl;
				fs << "\t\t\t\t\t<idcomentario> " << ser->getIDComentario(i) << "</idcomentario>" << endl;
				fs << "\t\t\t\t\t<login>" << ser->getLoginComentario(i) << "</login>" << endl;
				fs << "\t\t\t\t\t<texto>" << ser->getTextoComentario(i) << "</texto>" << endl;
				fs << "\t\t\t\t</comentario>" << endl;
			}
			fs << "\t\t\t</listacomentarios>" << endl;

			fs << "\t\t\t<totalvaloraciones>" << ser->getTotalValoraciones() << "</totalvaloraciones>" << endl;
			fs << "\t\t\t<valoraciones>" << endl;
			for(int i = 0; i < ser->getTotalValoraciones(); i++){
				fs << "\t\t\t\t<valoracion>" << endl;
				fs << "\t\t\t\t\t<idusuario>" << ser->getLoginValoracion(i) << "</idusuario>" << endl;
				fs << "\t\t\t\t\t<puntuacion>" << ser->getPuntuacionValoracion(i) << "</puntuacion>" << endl;
				fs << "\t\t\t\t</valoracion>" << endl;
			}
			fs << "\t\t\t</valoraciones>" << endl;

		}else if(Pelicula *pel = dynamic_cast<Pelicula *> (Catalogo[i])){
			fs << "\t\t\t<tipo>Pelicula</tipo>" << endl;
			fs << "\t\t\t<idmedia>" << pel->getIDMedia() << "</idmedia>" << endl;
			fs << "\t\t\t<titulo>" << pel->getTitulo() << "</titulo>" << endl;
			fs << "\t\t\t<genero>" << pel->getGenero() << "</genero>" << endl;
			fs << "\t\t\t<duracionensegundos>" << pel->getDuracionSegundos() << "</duracionensegundos>" << endl;
			fs << "\t\t\t<pegi>" << pel->getPegi() << "</pegi>" << endl;
			fs << "\t\t\t<descripcion>" << pel->getDescripcion() << "</descripcion>" << endl;
			fs << "\t\t<reparto>" << pel->getReparto() << "</reparto>" << endl;
			fs << "\t\t<direccion>" << pel->getDirector() << "</direccion>" << endl;
			fs << "\t\t<guion>" << pel->getGuion() << "</guion>" << endl;
			fs << "\t\t<productor>" << pel->getProductor() << "</productor>" << endl;
			fs << "\t\t\t<puntuacion>" << pel->getNotaMedia() << "</puntuacion>" << endl;
			fs << "\t\t\t<totalmegusta>" << pel->getMeGusta() << "</totalmegusta>" << endl;
			fs << "\t\t\t<totalcomentarios>" << pel->getTotalComentarios() << "</totalcomentarios>" << endl;
			fs << "\t\t\t<listacomentarios>" << endl;
			for(int i = 0; i < pel->getTotalComentarios(); i++){

				fs << "\t\t\t\t<comentario>" << endl;
				fs << "\t\t\t\t\t<idcomentario> " << pel->getIDComentario(i) << "</idcomentario>" << endl;
				fs << "\t\t\t\t\t<login>" << pel->getLoginComentario(i) << "</login>" << endl;
				fs << "\t\t\t\t\t<texto>" << pel->getTextoComentario(i) << "</texto>" << endl;
				fs << "\t\t\t\t</comentario>" << endl;
			}
			fs << "\t\t\t</listacomentarios>" << endl;

			fs << "\t\t\t<totalvaloraciones>" << pel->getTotalValoraciones() << "</totalvaloraciones>" << endl;
			fs << "\t\t\t<valoraciones>" << endl;
			for(int i = 0; i < pel->getTotalValoraciones(); i++){
				fs << "\t\t\t\t<valoracion>" << endl;
				fs << "\t\t\t\t\t<idusuario>" << pel->getLoginValoracion(i) << "</idusuario>" << endl;
				fs << "\t\t\t\t\t<puntuacion>" << pel->getPuntuacionValoracion(i) << "</puntuacion>" << endl;
				fs << "\t\t\t\t</valoracion>" << endl;
			}
			fs << "\t\t\t</valoraciones>" << endl;
		}else if(Videojuego *vid = dynamic_cast<Videojuego *> (Catalogo[i])){
			fs << "\t\t\t<tipo>Videojuego</tipo>" << endl;
			fs << "\t\t\t<idmedia>" << vid->getIDMedia() << "</idmedia>" << endl;
			fs << "\t\t\t<titulo>" << vid->getTitulo() << "</titulo>" << endl;
			fs << "\t\t\t<genero>" << vid->getGenero() << "</genero>" << endl;
			fs << "\t\t\t<duracionensegundos>" << vid->getDuracionSegundos() << "</duracionensegundos>" << endl;
			fs << "\t\t\t<pegi>" << vid->getPegi() << "</pegi>" << endl;
			fs << "\t\t\t<descripcion>" << vid->getDescripcion() << "</descripcion>" << endl;
			fs << "\t\t\t<desarrollador>" << vid->getDesarrollador() << "</desarrollador>" << endl;
			fs << "\t\t\t<editor>" << vid->getEditor() << "</editor>" << endl;
			fs << "\t\t\t<jugadores>" << vid->getJugadores() << "</jugadores>" << endl;
			fs << "\t\t\t<plataformas>" << vid->getPlataformas() << "</plataformas>" << endl;
			fs << "\t\t\t<puntuacion>" << vid->getNotaMedia() << "</puntuacion>" << endl;
			fs << "\t\t\t<totalmegusta>" << vid->getMeGusta() << "</totalmegusta>" << endl;
			fs << "\t\t\t<totalcomentarios>" << vid->getTotalComentarios() << "</totalcomentarios>" << endl;

			fs << "\t\t\t<listacomentarios>" << endl;
			for(int i = 0; i < vid->getTotalComentarios(); i++){

				fs << "\t\t\t\t<comentario>" << endl;
				fs << "\t\t\t\t\t<idcomentario> " << vid->getIDComentario(i) << "</idcomentario>" << endl;
				fs << "\t\t\t\t\t<login>" << vid->getLoginComentario(i) << "</login>" << endl;
				fs << "\t\t\t\t\t<texto>" << vid->getTextoComentario(i) << "</texto>" << endl;
				fs << "\t\t\t\t</comentario>" << endl;
			}
			fs << "\t\t\t</listacomentarios>" << endl;

			fs << "\t\t\t<totalvaloraciones>" << vid->getTotalValoraciones() << "</totalvaloraciones>" << endl;
			fs << "\t\t\t<valoraciones>" << endl;
			for(int i = 0; i < vid->getTotalValoraciones(); i++){
				fs << "\t\t\t\t<valoracion>" << endl;
				fs << "\t\t\t\t\t<idusuario>" << vid->getLoginValoracion(i) << "</idusuario>" << endl;
				fs << "\t\t\t\t\t<puntuacion>" << vid->getPuntuacionValoracion(i) << "</puntuacion>" << endl;
				fs << "\t\t\t\t</valoracion>" << endl;
			}
			fs << "\t\t\t</valoraciones>" << endl;
		}
		fs << "\t\t</media>" << endl;	
	}
	fs << "\t</catalogo>" << endl;
	fs << "\t<usuarios>" << endl;
	for(int i = 0; i < TotalUsuarios; i++){
		fs << "\t\t<usuario>" << endl;

		if(Administrador *ad = dynamic_cast<Administrador *> (VectorUsuarios[i])){
			fs << "\t\t\t<tipousuario>admin</tipousuario>" << endl;
			fs << "\t\t\t<login>" << ad->getLogin() <<  "</login>" << endl;
			fs << "\t\t\t<nombre>" << ad->getNombre() <<  "</nombre>" << endl;
			fs << "\t\t\t<apellidos>" << ad->getApellidos() <<  "</apellidos>" << endl;
			fs << "\t\t\t<urlfotoperfil>" << ad->getFotoPerfil() <<  "</urlfotoperfil>" << endl;
		}else if(Normal *nor = dynamic_cast<Normal *> (VectorUsuarios[i])){
			fs << "\t\t\t<tipousuario>normal</tipousuario>" << endl;
			fs << "\t\t\t<login>" << nor->getLogin() <<  "</login>" << endl;
			fs << "\t\t\t<nombre>" << nor->getNombre() <<  "</nombre>" << endl;
			fs << "\t\t\t<apellidos>" << nor->getApellidos() <<  "</apellidos>" << endl;
			fs << "\t\t\t<urlfotoperfil>" << nor->getFotoPerfil() <<  "</urlfotoperfil>" << endl;
			fs << "\t\t\t<totallistamedia>" << nor->getTotalAsociados() << "</totallistamedia>" << endl;
			fs << "\t\t\t<listamedia>";
			for(int k = 0; k < nor->getTotalAsociados(); k++){
				fs << nor->getIDMediasAsociados(k) << ' ';
			}
			fs << "</listamedia>" << endl;
		}
		fs << "\t\t</usuario>" << endl;
	}
	fs << "\t</usuarios>" << endl;

	fs.close();
}

void CristoFinity::calcularFormulas(){
	setValoracionesSistema();
	setComentariosSistema();
	calcularFormula();	
}

void CristoFinity::correcto(){
	cout << verde << "La operacion se ha completado satisfactoriamente " << rest << endl;
}

void CristoFinity::pulsaparacontinuar(){
	string tecla;

	cout << verde << "Pulsa una tecla para continuar " << rest << endl;
	cin >> tecla;
}


