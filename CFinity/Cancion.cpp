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
#include "Cancion.h"

using namespace std;

Cancion::Cancion() : Media(){
	Artista = "NULL";
	Album = "NULL";
}

Cancion::Cancion(int IDMedia, string Titulo, string Genero, int DuracionEnSegundos, string Fecha_Publicacion, int Pegi, string Descripcion, string Artista, string Album){
	this->IDMedia = IDMedia;
	this->Titulo = Titulo;
	this->Genero = Genero;
	this->DuracionEnSegundos = DuracionEnSegundos;
	this->Fecha_Publicacion = Fecha_Publicacion;
	this->Pegi = Pegi;
	this->Descripcion = Descripcion;
	this->Artista = Artista;
	this->Album = Album;
}

Cancion::~Cancion(){
	Artista = "NULL";
	Album = "NULL";
}

void Cancion::setArtista(string artista){
	this->Artista = artista;
}

void Cancion::setAlbum(string album){
	this->Album = album;
}

string Cancion::getArtista() const{
	return this->Artista;
}

string Cancion::getAlbum() const{
	return this->Album;
}

Cancion* Cancion::operator=(const Cancion *c){
	if(c != this){
	this->IDMedia = c->IDMedia;
	this->Titulo = c->Titulo;
	this->Genero = c->Genero;
	this->DuracionEnSegundos = c->DuracionEnSegundos;
	this->Fecha_Publicacion = c->Fecha_Publicacion;
	this->Pegi = c->Pegi;
	this->Descripcion = c->Descripcion;
	this->Artista = c->Artista;
	this->Album = c->Album;
	}

	return this;
}

ostream& operator<<(ostream &flujo, const Cancion *c){

	int opcion = 0;

	flujo << endl;
	flujo << amarillofuerte << "Cancion " << rest << endl;
	flujo << endl;
	flujo << azul << "ID del Media: " << cianfuerte << c->getIDMedia() << rest << endl;
	flujo << azul << "Titulo: " << cianfuerte << c->getTitulo() << rest << endl;
	flujo << azul << "Genero: " << cianfuerte << c->getGenero() << rest << endl;
	flujo << azul << "Duracion en segundos: " << cianfuerte << c->getDuracionSegundos() << rest << endl;
	flujo << azul << "Fecha de publicacion: " << cianfuerte << c->getFecha_Publicacion() << rest << endl;
	flujo << azul << "Pegi: " << cianfuerte << c->getPegi() << rest << endl;
	flujo << azul << "Nota Media: " << cianfuerte << c->getNotaMedia() << rest << endl;
	flujo << azul << "Nota General en catalogo: " << cianfuerte << c->getNotaGeneral() << rest << endl;
	flujo << azul << "Me Gusta: " << cianfuerte << c->getMeGusta() << rest << endl;
	flujo << azul << "Descripcion: " << cianfuerte << c->getDescripcion() << rest << endl;
	flujo << azul << "Artista " << cianfuerte << c->getArtista() << rest << endl;
	flujo << azul << "Album " << cianfuerte << c->getAlbum() << rest << endl;
	flujo << azul << "Comentarios: " << cianfuerte << c->getTotalComentarios() << rest << endl;
	flujo << azul << "Valoraciones: " << cianfuerte << c->getTotalValoraciones() << rest << endl;
	flujo << endl;

	if(c->TotalComentarios != 0){
		flujo << azul << "¿Desea imprimir los comentarios? " << rest << endl;
		flujo << verde << "[1] " << amarillofuerte << "SI" << rest << endl;
		flujo << rojo << "[2] " << amarillofuerte << "NO" << rest << endl;
		cin >> opcion;

		if(opcion == 1){
			cout << endl;
			for(int i = 0; i < c->TotalComentarios; i++){
				cout << amarillofuerte << "Comentario " << c->VectorComentarios[i]->getIDComentario() << rest << endl;
				cout << c->VectorComentarios[i];
			}
		}

	}else{
		cout << rojo << "Esta cancion aun no tiene comentarios " << rest << endl;
	}

	if(c->TotalValoraciones != 0){
		flujo << azul << "¿Desea imprimir las valoraciones? " << rest << endl;
		flujo << verde << "[1] " << amarillofuerte << "SI" << rest << endl;
		flujo << rojo << "[2] " << amarillofuerte << "NO" << rest << endl;
		cin >> opcion;

		if(opcion == 1){
			cout << endl;
			for(int i = 0; i < c->TotalValoraciones; i++){
				cout << amarillofuerte << "Valoracion " << i+1 << rest << endl;
				cout << c->VectorValoraciones[i];
			}
		}

	}else{
		cout << rojo << "Esta cancion aun no tiene valoraciones " << rest << endl;
	}

	return flujo;
}

istream& operator>>(istream &flujo, Cancion *c){


	cout << azulfuerte << "Introduce un Titulo: " << rest << endl;
	flujo.clear();
	flujo.ignore();
	getline(flujo, c->Titulo);

	cout << azulfuerte << "Introduce un genero: " << azul << endl;
	flujo.clear();
	getline(flujo, c->Genero);

	cout << azulfuerte << "Introduce la duracion en segundos: " << azul << endl;
	flujo >> c->DuracionEnSegundos;

	cout << azulfuerte << "Introduce una fecha de publicacion: " << azul << endl;
	flujo.clear();
	flujo.ignore();
	getline(flujo, c->Fecha_Publicacion);

	cout << azulfuerte << "Introduce una edad recomendada: " << azul << endl;
	flujo >> c->Pegi;

	cout << azulfuerte << "Introduce una descripcion: " << azul << endl;
	flujo.clear();
	flujo.ignore();
	getline(flujo, c->Descripcion);

	cout << azulfuerte << "Introduce una artista: " << azul << endl;
	flujo.clear();
	getline(flujo, c->Artista);

	cout << azulfuerte << "Introduce una album: " << azul << endl;
	flujo.clear();
	getline(flujo, c->Album);	

	return flujo;
}