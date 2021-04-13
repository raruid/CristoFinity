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
#include "Pelicula.h"

using namespace std;

Pelicula::Pelicula() : Media(){
	Director = "NULL";
	Reparto = "NULL";
	Guion = "NULL";
	Productor = "NULL";
}

Pelicula::Pelicula(int IDMedia, string Titulo, string Genero, int DuracionEnSegundos, string Fecha_Publicacion, int Pegi, string Descripcion, string Director, string Reparto, string Guion, string Productor){
	this->IDMedia = IDMedia;
	this->Titulo = Titulo;
	this->Genero = Genero;
	this->DuracionEnSegundos = DuracionEnSegundos;
	this->Fecha_Publicacion = Fecha_Publicacion;
	this->Pegi = Pegi;
	this->Descripcion = Descripcion;
	this->Director = Director;
	this->Reparto = Reparto;
	this->Guion = Guion;
	this->Productor = Productor;
}

Pelicula::~Pelicula(){
	Director = "NULL";
	Reparto = "NULL";
	Guion = "NULL";
	Productor = "NULL";	
}

void Pelicula::setDirector(string Director){
	this->Director = Director;
}

void Pelicula::setReparto(string Reparto){
	this->Reparto = Reparto;
}

void Pelicula::setGuion(string Guion){
	this->Guion = Guion;
}

void Pelicula::setProductor(string Productor){
	this->Productor = Productor;
}

string Pelicula::getDirector() const{
	return this->Director;
}

string Pelicula::getReparto() const{
	return this->Reparto;
}

string Pelicula::getGuion() const{
	return this->Guion;
}

string Pelicula::getProductor() const{
	return this->Productor;
}

Pelicula* Pelicula::operator=(const Pelicula *p){
	if(p != this){
		this->IDMedia = p->IDMedia;
		this->Titulo = p->Titulo;
		this->Genero = p->Genero;
		this->DuracionEnSegundos = p->DuracionEnSegundos;
		this->Fecha_Publicacion = p->Fecha_Publicacion;
		this->Pegi = p->Pegi;
		this->Descripcion = p->Descripcion;
		this->Director = p->Director;
		this->Reparto = p->Reparto;
		this->Guion = p->Guion;
		this->Productor = p->Productor;
	}

	return this;
}

ostream& operator<<(ostream &flujo, const Pelicula *p){

	int opcion = 0;

	flujo << endl;
	flujo << amarillofuerte << "Pelicula " << rest << endl;
	flujo << endl;
	flujo << azul << "ID del Media: " << cianfuerte << p->getIDMedia() << rest << endl;
	flujo << azul << "Titulo: " << cianfuerte << p->getTitulo() << rest << endl;
	flujo << azul << "Genero: " << cianfuerte << p->getGenero() << rest << endl;
	flujo << azul << "Duracion en segundos: " << cianfuerte << p->getDuracionSegundos() << rest << endl;
	flujo << azul << "Fecha de publicacion: " << cianfuerte << p->getFecha_Publicacion() << rest << endl;
	flujo << azul << "Pegi: " << cianfuerte << p->getPegi() << rest << endl;
	flujo << azul << "Nota Media: " << cianfuerte << p->getNotaMedia() << rest << endl;
	flujo << azul << "Nota General en catalogo: " << cianfuerte << p->getNotaGeneral() << rest << endl;
	flujo << azul << "Me Gusta: " << cianfuerte << p->getMeGusta() << rest << endl;
	flujo << azul << "Descripcion: " << cianfuerte << p->getDescripcion() << rest << endl;
	flujo << azul << "Director: " << cianfuerte << p->getDirector() << rest << endl;
	flujo << azul << "Reparto: " << cianfuerte << p->getReparto() << rest << endl;
	flujo << azul << "Guion: " << cianfuerte << p->getGuion() << rest << endl;
	flujo << azul << "Productor: " << cianfuerte << p->getProductor() << rest << endl;
	flujo << azul << "Comentarios: " << cianfuerte << p->getTotalComentarios() << rest << endl;
	flujo << azul << "Valoraciones: " << cianfuerte << p->getTotalValoraciones() << rest << endl;

	if(p->TotalComentarios != 0){
		flujo << azul << "¿Desea imprimir los comentarios? " << rest << endl;
		flujo << verde << "[1] " << amarillofuerte << "SI" << rest << endl;
		flujo << rojo << "[2] " << amarillofuerte << "NO" << rest << endl;
		cin >> opcion;

		if(opcion == 1){
			cout << endl;
			for(int i = 0; i < p->TotalComentarios; i++){
				cout << amarillofuerte << "Comentario " << p->VectorComentarios[i]->getIDComentario() << rest << endl;
				cout << p->VectorComentarios[i];
			}
		}

	}else{
		cout << rojo << "Esta pelicula aun no tiene comentarios " << rest << endl;
	}

	if(p->TotalValoraciones != 0){
		flujo << azul << "¿Desea imprimir las valoraciones? " << rest << endl;
		flujo << verde << "[1] " << amarillofuerte << "SI" << rest << endl;
		flujo << rojo << "[2] " << amarillofuerte << "NO" << rest << endl;
		cin >> opcion;

		if(opcion == 1){
			cout << endl;
			for(int i = 0; i < p->TotalValoraciones; i++){
				cout << amarillofuerte << "Valoracion " << i+1 << rest << endl;
				cout << p->VectorValoraciones[i];
			}
		}

	}else{
		cout << rojo << "Esta pelicula aun no tiene valoraciones " << rest << endl;
	}


	flujo << endl;
	return flujo;
}

istream& operator>>(istream &flujo, Pelicula *p){

	cout << azulfuerte << "Introduce un Titulo: " << rest << endl;
	flujo.clear();
	flujo.ignore();
	getline(flujo, p->Titulo);

	cout << azulfuerte << "Introduce un genero: " << azul << endl;
	flujo.clear();
	getline(flujo, p->Genero);

	cout << azulfuerte << "Introduce la duracion en segundos: " << azul << endl;
	flujo >> p->DuracionEnSegundos;

	cout << azulfuerte << "Introduce una fecha de publicacion: " << azul << endl;
	flujo.clear();
	flujo.ignore();
	getline(flujo, p->Fecha_Publicacion);

	cout << azulfuerte << "Introduce una edad recomendada: " << azul << endl;
	flujo >> p->Pegi;

	cout << azulfuerte << "Introduce una descripcion: " << azul << endl;
	flujo.clear();
	flujo.ignore();
	getline(flujo, p->Descripcion);

	cout << azulfuerte << "Introduce un director: " << azul << endl;
	flujo.clear();
	getline(flujo, p->Director);

	cout << azulfuerte << "Introduce el reparto: " << azul << endl;
	flujo.clear();
	getline(flujo, p->Reparto);

	cout << azulfuerte << "Introduce una guion: " << azul << endl;
	flujo.clear();
	getline(flujo, p->Guion);

	cout << azulfuerte << "Introduce una productor: " << azul << endl;
	flujo.clear();
	getline(flujo, p->Productor);	

	return flujo;
}

