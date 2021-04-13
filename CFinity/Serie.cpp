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
#include "Serie.h"

using namespace std;

Serie::Serie() : Pelicula(){
	Temporadas = 0;
	Capitulos = 0;
	bool Acabada = false;
}

Serie::Serie(int IDMedia, string Titulo, string Genero, int DuracionEnSegundos, string Fecha_Publicacion, int Pegi, string Descripcion, string Director, string Reparto, string Guion, string Productor, int Temporadas, int Capitulos, bool Acabada){
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
	this->Temporadas = Temporadas;
	this->Capitulos = Capitulos;
	this->Acabada = Acabada;
}

Serie::~Serie(){
	Temporadas = 0;
	Capitulos = 0;
	bool Acabada = false;
}

//SETS

void Serie::setTemporadas(int Temporadas){
	this->Temporadas = Temporadas;
}

void Serie::setCapitulos(int Capitulos){
	this->Capitulos = Capitulos;
}

void Serie::setAcabada(bool Acabada){
	this->Acabada = Acabada;
}

int Serie::getTemporadas() const{
	return this->Temporadas;
}

int Serie::getCapitulos() const{
	return this->Capitulos;
}

bool Serie::getAcabada() const{
	return this->Acabada;
}

Serie* Serie::operator=(const Serie *s){
	if(s != this){
		this->IDMedia = s->IDMedia;
		this->Titulo = s->Titulo;
		this->Genero = s->Genero;
		this->DuracionEnSegundos = s->DuracionEnSegundos;
		this->Fecha_Publicacion = s->Fecha_Publicacion;
		this->Pegi = s->Pegi;
		this->Descripcion = s->Descripcion;
		this->Director = s->Director;
		this->Reparto = s->Reparto;
		this->Guion = s->Guion;
		this->Productor = s->Productor;
		this->Temporadas = s->Temporadas;
		this->Capitulos = s->Capitulos;
		this->Acabada = s->Acabada;
	}
	return this;
}

ostream& operator<<(ostream &flujo, const Serie *s){

	int opcion = 0;

	flujo << endl;
	flujo << amarillofuerte << "Serie " << rest << endl;
	flujo << endl;
	flujo << azul << "ID del Media: " << cianfuerte << s->getIDMedia() << rest << endl;
	flujo << azul << "Titulo: " << cianfuerte << s->getTitulo() << rest << endl;
	flujo << azul << "Genero: " << cianfuerte << s->getGenero() << rest << endl;
	flujo << azul << "Duracion en segundos: " << cianfuerte << s->getDuracionSegundos() << rest << endl;
	flujo << azul << "Fecha de publicacion: " << cianfuerte << s->getFecha_Publicacion() << rest << endl;
	flujo << azul << "Pegi: " << cianfuerte << s->getPegi() << rest << endl;
	flujo << azul << "Nota Media: " << cianfuerte << s->getNotaMedia() << rest << endl;
	flujo << azul << "Nota General en catalogo: " << cianfuerte << s->getNotaGeneral() << rest << endl;
	flujo << azul << "Me Gusta: " << cianfuerte << s->getMeGusta() << rest << endl;
	flujo << azul << "Descripcion: " << cianfuerte << s->getDescripcion() << rest << endl;
	flujo << azul << "Director: " << cianfuerte << s->getDirector() << rest << endl;
	flujo << azul << "Reparto: " << cianfuerte << s->getReparto() << rest << endl;
	flujo << azul << "Guion: " << cianfuerte << s->getGuion() << rest << endl;
	flujo << azul << "Productor: " << cianfuerte << s->getProductor() << rest << endl;
	flujo << azul << "Temporadas: " << cianfuerte << s->getTemporadas() << rest << endl;
	flujo << azul << "Capitulos: " << cianfuerte << s->getCapitulos() << rest << endl;
	flujo << azul << "Estado: " <<  rest;
	if(s->getAcabada() == true){
		flujo << cianfuerte << "Acabada" << rest << endl; 
	}else{
		flujo << cianfuerte << "No acabada" << rest << endl;
	}
	flujo << azul << "Comentarios: " << cianfuerte << s->getTotalComentarios() << rest << endl;
	flujo << azul << "Valoraciones: " << cianfuerte << s->getTotalValoraciones() << rest << endl;

	if(s->TotalComentarios != 0){
		flujo << azul << "¿Desea imprimir los comentarios? " << rest << endl;
		flujo << verde << "[1] " << amarillofuerte << "SI" << rest << endl;
		flujo << rojo << "[2] " << amarillofuerte << "NO" << rest << endl;
		cin >> opcion;

		if(opcion == 1){
			cout << endl;
			for(int i = 0; i < s->TotalComentarios; i++){
				cout << amarillofuerte << "Comentario " << s->VectorComentarios[i]->getIDComentario() << rest << endl;
				cout << s->VectorComentarios[i];
			}
		}

	}else{
		cout << rojo << "Esta serie aun no tiene comentarios " << rest << endl;
	}

	if(s->TotalValoraciones != 0){
		flujo << azul << "¿Desea imprimir las valoraciones? " << rest << endl;
		flujo << verde << "[1] " << amarillofuerte << "SI" << rest << endl;
		flujo << rojo << "[2] " << amarillofuerte << "NO" << rest << endl;
		cin >> opcion;

		if(opcion == 1){
			cout << endl;
			for(int i = 0; i < s->TotalValoraciones; i++){
				cout << amarillofuerte << "Valoracion " << i+1 << rest << endl;
				cout << s->VectorValoraciones[i];
			}
		}

	}else{
		cout << rojo << "Esta serie aun no tiene valoraciones " << rest << endl;
	}


	flujo << endl;

	return flujo;
}

istream& operator>>(istream &flujo, Serie *s){

	int opcion = 0;

	cout << azulfuerte << "Introduce un Titulo: " << rest << endl;
	flujo.clear();
	flujo.ignore();
	getline(flujo, s->Titulo);

	cout << azulfuerte << "Introduce un genero: " << azul << endl;
	flujo.clear();
	getline(flujo, s->Genero);

	cout << azulfuerte << "Introduce la duracion en segundos: " << azul << endl;
	flujo >> s->DuracionEnSegundos;

	cout << azulfuerte << "Introduce una fecha de publicacion: " << azul << endl;
	flujo.clear();
	flujo.ignore();
	getline(flujo, s->Fecha_Publicacion);

	cout << azulfuerte << "Introduce una edad recomendada: " << azul << endl;
	flujo >> s->Pegi;

	cout << azulfuerte << "Introduce una descripcion: " << azul << endl;
	flujo.clear();
	flujo.ignore();
	getline(flujo, s->Descripcion);

	cout << azulfuerte << "Introduce un director: " << azul << endl;
	flujo.clear();
	getline(flujo, s->Director);

	cout << azulfuerte << "Introduce el reparto: " << azul << endl;
	flujo.clear();
	getline(flujo, s->Reparto);

	cout << azulfuerte << "Introduce una guion: " << azul << endl;
	flujo.clear();
	getline(flujo, s->Guion);

	cout << azulfuerte << "Introduce una productor: " << azul << endl;
	flujo.clear();
	getline(flujo, s->Productor);	

	cout << azulfuerte << "Introduce el numero de temporadas: " << azul << endl;
	flujo >> s->Temporadas;

	cout << azulfuerte << "Introduce el numero de capitulos: " << azul << rest << endl;
	flujo >> s->Capitulos;

	cout << azulfuerte << "¿Ha acabado? " << azul << endl;
	cout << verde << "[1] SI " << rest << endl;
	cout << rojo << "[2] NO " << rest << endl;

	flujo >> opcion; 

	if(opcion == 1){
		s->setAcabada(true);
	}else{
		s->setAcabada(false);
	}

	return flujo;
}