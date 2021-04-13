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
#include "Valoracion.h"
#include "Comentario.h"
#include "Media.h"

using namespace std;

Media::Media(){

	IDMedia = 0;
	Titulo = "NULL";
	Genero = "NULL";
	DuracionEnSegundos = 0;
	Fecha_Publicacion = "NULL";
	Pegi = 0;
	NotaMedia = 0;
	NotaGeneralCatalogo = 0;
	MeGusta = 0;
	Descripcion = "NULL";

	//Creacion de el puntero a vector de punteros de comentarios
	TotalComentarios = 0;
	VectorComentarios = new Comentario *[this->TotalComentarios+1];
    if (!this->VectorComentarios){
        cout << rojo << "Error en el sistema" << rest << endl;
        exit(-1);
    }

	//Creacion de el puntero a vector de punteros de comentarios
	TotalValoraciones = 0;
	VectorValoraciones = new Valoracion *[this->TotalValoraciones+1];
    if (!this->VectorValoraciones){
        cout << rojo << "Error en el sistema" << rest << endl;
        exit(-1);
    }
}

Media::~Media(){

	//cout << rojo << "DEBUG: DESTRUCTOR DE MEDIA " << rest << endl;

	IDMedia = 0;
	Titulo = "NULL";
	Genero = "NULL";
	DuracionEnSegundos = 0;
	Fecha_Publicacion = "NULL";
	Pegi = 0;
	NotaMedia = 0;
	NotaGeneralCatalogo = 0;
	MeGusta = 0;
	Descripcion = "NULL";

	//cout << rojo << "DEBUG DESTRUCTOR MEDIA 1 " << rest << endl;
	//Borrado del vector de comentarios
	for (int i = 0; i < TotalComentarios; i++){
		delete VectorComentarios[i];
	}
	//cout << rojo << "DEBUG DESTRUCTOR MEDIA 2 " << rest << endl;
	delete[] VectorComentarios;
	VectorComentarios = 0;
	TotalComentarios = 0;

	//cout << rojo << "DEBUG DESTRUCTOR MEDIA 3 " << rest << endl;
	//Borrado del vector de valoraciones
	for (int i = 0; i < TotalValoraciones; i++){
		delete VectorValoraciones[i];
	}

	//cout << rojo << "DEBUG DESTRUCTOR MEDIA 4 " << rest << endl;
	delete[] VectorValoraciones;
	VectorValoraciones = 0;
	TotalValoraciones = 0;
}

void Media::setIDMedia(int ID){
	this->IDMedia = ID;
}

void Media::setTitulo(string tit){
	this->Titulo = tit;
}

void Media::setGenero(string gen){
	this->Genero = gen;
}

void Media::setDuracionSeg(int duracion){
	this->DuracionEnSegundos = duracion;
}

void Media::setFecha_Publicacion(string fecha){
	this->Fecha_Publicacion = fecha;
}

void Media::setPegi(int peg){
	this->Pegi = peg;
}

void Media::setDescripcion(string descrip){
	this->Descripcion = descrip;
}

void Media::calcularNotaMedia(){

	if(TotalValoraciones != 0){
		float suma = 0;

		for(int i = 0; i < TotalValoraciones; i++){
			suma = suma + VectorValoraciones[i]->getPuntuacion();
		}

		this->NotaMedia = suma/TotalValoraciones;
	}
}

void Media::calcularFormulaGeneral(int ValoracionesSistema, int ComentariosSistema){

	float operacion1 = 0;
	float operacion2 = 0;
	float operacion3 = 0;

	operacion1 = 0.5 * NotaMedia; 

	//cout << rojo << "Operacion 1 = " << operacion1 << rest << endl;


	//cout << rojo << MeGusta << rest << endl;
	//cout << rojo << ValoracionesSistema << rest << endl;

	operacion2 = 0.3 * (MeGusta/ValoracionesSistema);

	//cout << rojo << "Operacion 2 = " << operacion2 << rest << endl;

	operacion3 = 0.2 * (TotalComentarios/ComentariosSistema);

	//cout << rojo << "Operacion 3 = " << operacion3 << rest << endl;

	this->NotaGeneralCatalogo = operacion1 + operacion2 + operacion3;
}

void Media::setMeGustaMas(){
	this->MeGusta++;
}

void Media::setMeGustaMenos(){
	this->MeGusta--;
}

int Media::getIDMedia() const{
	return this->IDMedia;
}

string Media::getTitulo() const{
	return this->Titulo;
}

string Media::getGenero() const{
	return this->Genero;
}

int Media::getDuracionSegundos() const{
	return this->DuracionEnSegundos;
}

string Media::getFecha_Publicacion() const{
	return this->Fecha_Publicacion;
}

int Media::getPegi() const{
	return this->Pegi;
}

float Media::getNotaMedia() const{
	return this->NotaMedia;
}

float Media::getNotaGeneral() const{
	return this->NotaGeneralCatalogo;
}

int Media::getMeGusta() const{
	return this->MeGusta;
}

string Media::getDescripcion() const{
	return this->Descripcion;
}

int Media::getTotalComentarios() const{
	return this->TotalComentarios;
}

int Media::getTotalValoraciones() const{
	return this->TotalValoraciones;
}


void Media::resizeComentariosMas(){
    TotalComentarios++;

    Comentario **c = new Comentario *[this->TotalComentarios+1]; 

    if (c == 0){
        cout << rojo << "Error. No hay memoria suficiente. Se abortará la ejecución" << rest << endl;
        exit(-1);
    }

    for(int i = 0; i < TotalComentarios; i++){
        c[i] = this->VectorComentarios[i];
    }

    delete[] this->VectorComentarios;
    this->VectorComentarios = c;
    c = 0;
}

void Media::resizeComentariosMenos(){

	TotalComentarios--;

    Comentario **c = new Comentario *[this->TotalComentarios+1];

    if (c == 0){
        cout << rojo << "Error. No hay memoria suficiente. Se abortará la ejecución" << rest << endl;
        exit(-1);
    }

    for(int i = 0; i < TotalComentarios; i++){
        c[i] = this->VectorComentarios[i];
    }

    delete[] this->VectorComentarios;
    this->VectorComentarios = c;
    c = 0;
}

void Media::resizeValoracionesMas(){
    TotalValoraciones++;

    Valoracion **v = new Valoracion *[this->TotalValoraciones+1]; 

    if (v == 0){
        cout << rojo << "Error. No hay memoria suficiente. Se abortará la ejecución" << rest << endl;
        exit(-1);
    }

    for(int i = 0; i < TotalValoraciones; i++){
        v[i] = this->VectorValoraciones[i];
    }

    delete[] this->VectorValoraciones;
    this->VectorValoraciones = v;
    v = 0;
}

void Media::resizeValoracionesMenos(){

	TotalValoraciones--;

    Valoracion **v = new Valoracion *[this->TotalValoraciones+1]; 

    if (v == 0){
        cout << rojo << "Error. No hay memoria suficiente. Se abortará la ejecución" << rest << endl;
        exit(-1);
    }

    for(int i = 0; i < TotalValoraciones; i++){
        v[i] = this->VectorValoraciones[i];
    }

    delete[] this->VectorValoraciones;
    this->VectorValoraciones = v;
    v = 0;
}

void Media::insertarComentario(Comentario *c){
	VectorComentarios[TotalComentarios] = c;
	resizeComentariosMas();
	ordenarIDComentario();
}

void Media::insertarValoracion(Valoracion *v){
	VectorValoraciones[TotalValoraciones] = v;
	resizeValoracionesMas();
	calcularNotaMedia();
}

void Media::ordenarIDComentario(){
	int ID = 1;

	//cout << rojo << "Debug: ORDENAR ID 1" << rest << endl;
	for (int i = 0; i < TotalComentarios; i++){
		VectorComentarios[i]->setIDComentario(ID);
		ID++;
	}
	//cout << rojo << "Debug: ORDENAR ID 2" << rest << endl;
}

int Media::buscarComentarioID(int opcion){

	int posicion = -1;

	for(int i = 0; i < TotalValoraciones; i++){
		if(VectorComentarios[i]->getIDComentario() == opcion){
			posicion = i;
		}
	}
	return posicion;
}

void Media::borrarComentario(int id){

	Comentario *auxc = new Comentario;

	auxc = VectorComentarios[TotalComentarios-1];
	VectorComentarios[TotalComentarios-1] = VectorComentarios[id-1];
	VectorComentarios[id-1] = auxc;

	resizeComentariosMenos();
	ordenarIDComentario();
}

void Media::eliminarComentariosDeUsuario(string login){

	for(int i = 0; i < TotalComentarios; i++){
		if(VectorComentarios[i]->getLogin() == login){
			borrarComentario(VectorComentarios[i]->getIDComentario());
		}
	}
}

void Media::borrarValoracion(int posicion){

	Valoracion *auxv = new Valoracion;

	auxv = VectorValoraciones[TotalValoraciones-1];
	VectorValoraciones[TotalValoraciones-1] = VectorValoraciones[posicion-1];
	VectorValoraciones[posicion-1] = auxv;
	resizeValoracionesMenos();
	calcularNotaMedia();
}

void Media::eliminarValoracionesDeUsuario(string login){

	int posicion_mas_uno = 0;

	for(int i = 0; i < TotalValoraciones; i++){
		if(VectorValoraciones[i]->getLogin() == login){
			posicion_mas_uno = i + 1;
			borrarValoracion(posicion_mas_uno);
		}
	}
}

void Media::printComentarios(){

	cout << magentafuerte <<"Estos son los comentarios disponibles: " << rest << endl;

	for(int i = 0; i < TotalComentarios; i++){
		cout << VectorComentarios[i];
	}
}

int Media::getIDComentario(int i){
		return VectorComentarios[i]->getIDComentario();	
}

string Media::getLoginComentario(int i){
		return VectorComentarios[i]->getLogin();
}

string Media::getTextoComentario(int i){
		return VectorComentarios[i]->getTexto();
}

string Media::getLoginValoracion(int i){
		return VectorValoraciones[i]->getLogin();
}

int Media::getPuntuacionValoracion(int i){
		return VectorValoraciones[i]->getPuntuacion();
}

void Media::printComentariosPorLogin(string login){

	bool tienecomentarios = false;

	for(int i = 0; i < TotalComentarios; i++){
		if(VectorComentarios[i]->getLogin() == login){
			cout << VectorComentarios[i];
			tienecomentarios = true;
		}
	}

	if(tienecomentarios == false){
		cout << rojo << "No tienes comentarios disponibles de este media " << rest << endl;
	}
}

void Media::cambiarLoginComentariosValoracion(string antiguologin, string nuevologin){
	for(int i = 0; i < TotalComentarios; i++){
		if(VectorComentarios[i]->getLogin() == antiguologin){
			VectorComentarios[i]->setLogin(nuevologin);
		}
	}

	for(int i = 0; i < TotalValoraciones; i++){
		if(VectorValoraciones[i]->getLogin() == antiguologin){
			VectorValoraciones[i]->setLogin(nuevologin);
		}
	}
}

void Media::printValoraciones(){

	cout << magentafuerte <<"Estos son las valoraciones disponibles: " << rest << endl;

	for(int i = 0; i < TotalComentarios && i < TotalValoraciones; i++){
		cout << VectorValoraciones[i];
	}
}

bool Media::comprobarValoracion(string login){

	bool correcto = true;

	for(int i = 0; i < TotalValoraciones; i++){
		//cout << rojo << "DEBUG : Login: " << VectorValoraciones[i]->getLogin() << rest << endl;
		if(VectorValoraciones[i]->getLogin() == login){
			//cout << rojo << VectorValoraciones[i]->getLogin() << rest << endl;
			correcto = false;
		}
	}

	return correcto;
}

void Media::modificarValoracionPorLogin(string login){
	for(int i = 0; i < TotalValoraciones; i++){
		if(VectorValoraciones[i]->getLogin() == login){
			cin >> VectorValoraciones[i];
		}
	}
	calcularNotaMedia();
}

void Media::printValoracionPorLogin(string login){

	bool tienevaloraciones = false;

	for(int i = 0; i < TotalValoraciones; i++){
		if(VectorValoraciones[i]->getLogin() == login){
			cout << VectorComentarios[i];
			tienevaloraciones = true;
		}
	}

	if(tienevaloraciones == false){
		cout << rojo << "No tienes valoraciones disponibles de este media " << rest << endl;
	}
}

int Media::contarComentariosPorLogin(string login){

	int cont = 0;

	for(int i = 0; i < TotalComentarios; i++){
		if(VectorComentarios[i]->getLogin() == login){
			cont++;
		}
	}

	return cont;
}

Media* Media::operator=(const Media *m){
	if(m != this){
	this->IDMedia = m->IDMedia;
	this->Titulo = m->Titulo;
	this->Genero = m->Genero;
	this->DuracionEnSegundos = m->DuracionEnSegundos;
	this->Fecha_Publicacion = m->Fecha_Publicacion;
	this->Pegi = m->Pegi;
	this->Descripcion = m->Descripcion;
	}

	return this;
}

ostream& operator<<(ostream &flujo, const Media *m){
	flujo << azul << "ID del Media: " << cianfuerte << m->getIDMedia() << rest << endl;
	flujo << azul << "Titulo: " << cianfuerte << m->getTitulo() << rest << endl;
	flujo << azul << "Genero: " << cianfuerte << m->getGenero() << rest << endl;
	flujo << azul << "Duracion en segundos: " << cianfuerte << m->getDuracionSegundos() << rest << endl;
	flujo << azul << "Fecha de publicacion: " << cianfuerte << m->getFecha_Publicacion() << rest << endl;
	flujo << azul << "Pegi: " << cianfuerte << m->getPegi() << rest << endl;
	flujo << azul << "Descripcion: " << cianfuerte << m->getDescripcion() << rest << endl;
	flujo << azul << "Comentarios: " << cianfuerte << m->getTotalComentarios() << rest << endl;
	flujo << azul << "Valoraciones: " << cianfuerte << m->getTotalValoraciones() << rest << endl;
	flujo << endl;
}

istream& operator>>(istream &flujo, Media *m){

	cout << azulfuerte << "Introduce un Titulo: " << rest << endl;
	flujo.clear();
	flujo.ignore();
	getline(flujo, m->Titulo);

	cout << azulfuerte << "Introduce un genero: " << azul << endl;
	flujo.clear();
	flujo.ignore();
	getline(flujo, m->Genero);

	cout << azulfuerte << "Introduce una fecha de publicacion: " << azul << endl;
	flujo.clear();
	flujo.ignore();
	getline(flujo, m->Fecha_Publicacion);

	cout << azulfuerte << "Introduce una edad recomendada: " << azul << endl;
	flujo >> m->Pegi;

	cout << azulfuerte << "Introduce una descripcion: " << azul << endl;
	flujo.clear();
	flujo.ignore();
	getline(flujo, m->Descripcion);

	return flujo;
}

