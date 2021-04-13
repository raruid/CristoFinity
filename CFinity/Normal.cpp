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
#include "Normal.h"
using namespace std;

Normal::Normal(): Usuario(){

	//Inicializacion del vector de VectorAsociados
	TotalAsociados = 0;
	VectorAsociados = new Media *[this->TotalAsociados+1];
    if (!this->VectorAsociados){
        cout << rojo << "Error en el sistema" << rest << endl;
        exit(-1);
    }

    mediaGeneralAsociados = 0.0;
}

Normal::Normal(string Login, string Nombre, string Apellidos, string FotoPerfil){
	this->Login = Login;
	this->Nombre = Nombre;
	this->Apellidos = Apellidos;
	this->FotoPerfil = FotoPerfil;

	//Inicializacion del vector de VectorAsociados
	TotalAsociados = 0;
	VectorAsociados = new Media *[this->TotalAsociados+1];
    if (!this->VectorAsociados){
        cout << rojo << "Error en el sistema" << rest << endl;
        exit(-1);
    }
}

Normal::~Normal(){
	delete[] VectorAsociados;
	VectorAsociados = 0;

	TotalAsociados = 0;
	mediaGeneralAsociados = 0.0;
}

void Normal::resizeVectorAsociadosMas(){

    TotalAsociados++;

    Media **c = new Media *[this->TotalAsociados+1]; 

    if (c == 0){
        cout << rojo << "Error. No hay memoria suficiente. Se abortará la ejecución" << rest << endl;
        exit(-1);
    }

    for(int i = 0; i < TotalAsociados; i++){
        c[i] = this->VectorAsociados[i];
    }

    delete[] this->VectorAsociados;
    this->VectorAsociados = c;
    c = 0;
}

void Normal::resizeVectorAsociadosMenos(){

	TotalAsociados--;

    Media **c = new Media *[this->TotalAsociados+1];

    if (c == 0){
        cout << rojo << "Error. No hay memoria suficiente. Se abortará la ejecución" << rest << endl;
        exit(-1);
    }

    for(int i = 0; i < TotalAsociados; i++){
        c[i] = this->VectorAsociados[i];
    }

    delete[] this->VectorAsociados;
    this->VectorAsociados = c;
    c = 0;
}

void Normal::calcularMediaNotaMediaAsociados(){

	float suma = 0.0;

	for(int i = 0; i < TotalAsociados; i++){
		suma = suma + VectorAsociados[i]->getNotaGeneral();
	}

	this->mediaGeneralAsociados = (suma / TotalAsociados);
}

int Normal::getTotalAsociados() const{
    return this->TotalAsociados;
}

float Normal::getMediaFavoritos() const{
	return this->mediaGeneralAsociados;
}

int Normal::getIDMediasAsociados(int i){
	return VectorAsociados[i]->getIDMedia();
}

void Normal::insertarEnVectorAsociados(Media *m){

	VectorAsociados[TotalAsociados] = m;
	resizeVectorAsociadosMas();
	m->setMeGustaMas();
}

void Normal::printMediaAsociadoDetalle(){

	int opcion = 0;
	int posicion = 0;

	cout << magentafuerte << "¿Que media desea imprimir en detalle?, introduce su ID" << rest << endl;

	printMediaAsociados();

	cin >> opcion;

	posicion = buscarMediaID(opcion);

	if(Cancion *can = dynamic_cast<Cancion *> (VectorAsociados[posicion])){
		cout << can << endl;
	}else if(Serie *ser = dynamic_cast<Serie *> (VectorAsociados[posicion])){
		cout << ser << endl;
	}else if(Pelicula *pel = dynamic_cast<Pelicula *> (VectorAsociados[posicion])){
		cout << pel << endl;
	}else if(Videojuego *vid = dynamic_cast<Videojuego *> (VectorAsociados[posicion])){
		cout << vid << endl;
	}
}

void Normal::printMediaAsociados(){
	for(int i = 0; i < TotalAsociados; i++){
		cout << amarillofuerte << "[" << VectorAsociados[i]->getIDMedia() << "]" << cianfuerte << VectorAsociados[i]->getTitulo() << rest << endl;
	}
}

void Normal::eliminarMediaAsociado(int opcion){

	int posicion = 0;
	Media *aux = new Media;

	posicion = buscarMediaID(opcion);

	if(posicion != -1){
		VectorAsociados[posicion]->setMeGustaMenos();

		aux = VectorAsociados[TotalAsociados-1];
		VectorAsociados[TotalAsociados-1] = VectorAsociados[posicion];
		VectorAsociados[posicion] = aux;

		resizeVectorAsociadosMenos();
	}
}

void Normal::eliminarMeGustas(){
	for(int i = 0; i < TotalAsociados; i++){
		VectorAsociados[i]->setMeGustaMenos();
	}
}

int Normal::buscarMediaID(int id){
	int posicion = -1;

	for(int i = 0; i < TotalAsociados; i++){
		if(VectorAsociados[i]->getIDMedia() == id){
			posicion = i;
		}
	}
	return posicion;
}

void Normal::ComentarAsociado(){

	int opcion = 0;
	int posicion = 0;

	cout << magentafuerte << "Elige el media del que quieres escribir un comentario " << rest << endl;

	printMediaAsociados();

	cin >> opcion;

	posicion = buscarMediaID(opcion);

	escribirComentario(posicion);
}

void Normal::escribirComentario(int posicion){

	cout << magentafuerte << "Escribe un comentario para " << cianfuerte << VectorAsociados[posicion]->getTitulo() << rest << endl;

	Comentario *c = new Comentario;

	c->setLogin(this->getLogin());

	cin >> c;

	VectorAsociados[posicion]->insertarComentario(c);
}

bool Normal::comprobarMedia(Media *m){

	bool comprobado = false;

	for(int i = 0; i < TotalAsociados; i++){
		if(VectorAsociados[i]->getIDMedia() == m->getIDMedia()){
			comprobado = true;
		}
	}

	return comprobado;
}

Normal* Normal::operator=(const Normal *m){
	if(m != this){
		this->Login = m->Login;
		this->Nombre = m->Nombre;
		this->Apellidos = m->Apellidos;
		this->FotoPerfil = m->FotoPerfil;
	}

	return this;
}

ostream& operator<<(ostream &flujo, const Normal *m){

	int opcion = 0;

	flujo << azul << "Login: " << cianfuerte << m->getLogin() << rest << endl;
	flujo << azul << "Nombre: " << cianfuerte << m->getNombre() << rest << endl;
	flujo << azul << "Apellidos: " << cianfuerte << m->getApellidos() << rest << endl;
	flujo << azul << "Foto de perfil: " << cianfuerte << m->getFotoPerfil() << rest << endl;
	flujo << azul << "Nota media de favoritos: " << cianfuerte << m->getMediaFavoritos() << rest << endl;
	flujo << azul << "Medias asociados: " << cianfuerte << m->getTotalAsociados() << rest << endl;

	if(m->TotalAsociados != 0){
		flujo << azul << "¿Desea imprimir los medias asociados? " << rest << endl;
		flujo << verde << "[1] " << amarillofuerte << "SI" << rest << endl;
		flujo << rojo << "[2] " << amarillofuerte << "NO" << rest << endl;
		cin >> opcion;

		if(opcion == 1){
			cout << endl;
			for(int i = 0; i < m->TotalAsociados; i++){
				cout << amarillofuerte << "[" << m->VectorAsociados[i]->getIDMedia() << "]" << cianfuerte << m->VectorAsociados[i]->getTitulo() << rest << endl;
			}
		}
	}

	flujo << endl;
}

istream& operator>>(istream &flujo, Normal *m){

	cout << azulfuerte << "Introduce tu nombre: " << azul << endl;
	flujo.clear();
	flujo.ignore();
	getline(flujo, m->Nombre);

	cout << azulfuerte << "Introduce tus apellidos: " << azul << endl;
	flujo.clear();
	getline(flujo, m->Apellidos);

	cout << azulfuerte << "Introduce la URL de tu foto de perfil " << azul << endl;
	flujo.clear();
	getline(flujo, m->FotoPerfil);

	return flujo;
}