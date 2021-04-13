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
#include "Videojuego.h"

using namespace std;

Videojuego::Videojuego() : Media(){
	Desarrollador = "NULL";
	Editor = "NULL";
	Jugadores = 0;
	Plataformas = "NULL";
}

Videojuego::Videojuego(int IDMedia, string Titulo, string Genero, int DuracionEnSegundos, string Fecha_Publicacion, int Pegi, string Descripcion, string Desarrollador, string Editor, int Jugadores, string Plataformas){
	this->IDMedia = IDMedia;
	this->Titulo = Titulo;
	this->Genero = Genero;
	this->DuracionEnSegundos = DuracionEnSegundos;
	this->Fecha_Publicacion = Fecha_Publicacion;
	this->Pegi = Pegi;
	this->Descripcion = Descripcion;
	this->Desarrollador = Desarrollador;
	this->Editor = Editor;
	this->Jugadores = Jugadores;
	this->Plataformas = Plataformas;
}

Videojuego::~Videojuego(){
	Desarrollador = "NULL";
	Editor = "NULL";
	Jugadores = 0;
	Plataformas = "NULL";
}

void Videojuego::setDesarrollador(string Desarrollador){
	this->Desarrollador = Desarrollador;
}

void Videojuego::setEditor(string Editor){
	this->Editor = Editor;
}

void Videojuego::setJugadores(int Jugadores){
	this->Jugadores = Jugadores;
}

void Videojuego::setPlataformas(string Plataformas){
	this->Plataformas = Plataformas;
}

string Videojuego::getDesarrollador() const{
	return this->Desarrollador;
}

string Videojuego::getEditor() const{
	return this->Editor;
}

int Videojuego::getJugadores() const{
	return this->Jugadores;
}

string Videojuego::getPlataformas() const{
	return this->Plataformas;
}

Videojuego* Videojuego::operator=(const Videojuego *v){
	if(v != this){
		this->IDMedia = v->IDMedia;
		this->Titulo = v->Titulo;
		this->Genero = v->Genero;
		this->DuracionEnSegundos = v->DuracionEnSegundos;
		this->Fecha_Publicacion = v->Fecha_Publicacion;
		this->Pegi = v->Pegi;
		this->Descripcion = v->Descripcion;
		this->Desarrollador = v->Desarrollador;
		this->Editor = v->Editor;
		this->Jugadores = v->Jugadores;
		this->Plataformas = v->Plataformas;
	}
}

ostream& operator<<(ostream &flujo, const Videojuego *v){

	int opcion = 0;
	flujo << endl;
	flujo << amarillofuerte << "Videojuego " << rest << endl;
	flujo << endl;
	flujo << azul << "ID del Media: " << cianfuerte << v->getIDMedia() << rest << endl;
	flujo << azul << "Titulo: " << cianfuerte << v->getTitulo() << rest << endl;
	flujo << azul << "Genero: " << cianfuerte << v->getGenero() << rest << endl;
	flujo << azul << "Duracion en segundos: " << cianfuerte << v->getDuracionSegundos() << rest << endl;
	flujo << azul << "Fecha de publicacion: " << cianfuerte << v->getFecha_Publicacion() << rest << endl;
	flujo << azul << "Pegi: " << cianfuerte << v->getPegi() << rest << endl;
	flujo << azul << "Nota Media: " << cianfuerte << v->getNotaMedia() << rest << endl;
	flujo << azul << "Nota General en catalogo: " << cianfuerte << v->getNotaGeneral() << rest << endl;
	flujo << azul << "Me Gusta: " << cianfuerte << v->getMeGusta() << rest << endl;
	flujo << azul << "Descripcion: " << cianfuerte << v->getDescripcion() << rest << endl;
	flujo << azul << "Plataformas: " << cianfuerte << v->getPlataformas() << rest << endl;
	flujo << azul << "Editor: " << cianfuerte << v->getEditor() << rest << endl;
	flujo << azul << "Jugadores: " << cianfuerte << v->getJugadores() << rest << endl;
	flujo << azul << "Plataformas: " << cianfuerte << v->getPlataformas() << rest << endl;
	flujo << azul << "Comentarios: " << cianfuerte << v->getTotalComentarios() << rest << endl;
	flujo << azul << "Valoraciones: " << cianfuerte << v->getTotalValoraciones() << rest << endl;
	flujo << endl;

	if(v->TotalComentarios != 0){
		flujo << azul << "¿Desea imprimir los comentarios? " << rest << endl;
		flujo << verde << "[1] " << amarillofuerte << "SI" << rest << endl;
		flujo << rojo << "[2] " << amarillofuerte << "NO" << rest << endl;
		cin >> opcion;

		if(opcion == 1){
			cout << endl;
			for(int i = 0; i < v->TotalComentarios; i++){
				cout << amarillofuerte << "Comentario " << v->VectorComentarios[i]->getIDComentario() << rest << endl;
				cout << v->VectorComentarios[i];
			}
		}

	}else{
		cout << rojo << "Este videojuego aun no tiene comentarios " << rest << endl;
	}

	if(v->TotalValoraciones != 0){
		flujo << azul << "¿Desea imprimir las valoraciones? " << rest << endl;
		flujo << verde << "[1] " << amarillofuerte << "SI" << rest << endl;
		flujo << rojo << "[2] " << amarillofuerte << "NO" << rest << endl;
		cin >> opcion;

		if(opcion == 1){
			cout << endl;
			for(int i = 0; i < v->TotalValoraciones; i++){
				cout << amarillofuerte << "Valoracion " << i+1 << rest << endl;
				cout << v->VectorValoraciones[i];
			}
		}

	}else{
		cout << rojo << "Este videojuego aun no tiene valoraciones " << rest << endl;
	}

	return flujo;
}

istream& operator>>(istream &flujo, Videojuego *v){

	cout << azulfuerte << "Introduce un Titulo: " << rest << endl;
	flujo.clear();
	flujo.ignore();
	getline(flujo, v->Titulo);

	cout << azulfuerte << "Introduce un genero: " << azul << endl;
	flujo.clear();
	getline(flujo, v->Genero);

	cout << azulfuerte << "Introduce la duracion en segundos: " << azul << endl;
	flujo >> v->DuracionEnSegundos;

	cout << azulfuerte << "Introduce una fecha de publicacion: " << azul << endl;
	flujo.clear();
	flujo.ignore();
	getline(flujo, v->Fecha_Publicacion);

	cout << azulfuerte << "Introduce una edad recomendada: " << azul << endl;
	flujo >> v->Pegi;

	cout << azulfuerte << "Introduce una descripcion: " << azul << endl;
	flujo.clear();
	flujo.ignore();
	getline(flujo, v->Descripcion);

	cout << azulfuerte << "Introduce el desarrollador: " << azul << endl;
	flujo.clear();
	getline(flujo, v->Desarrollador);

	cout << azulfuerte << "Introduce el editor: " << azul << endl;
	flujo.clear();
	getline(flujo, v->Editor);

	cout << azulfuerte << "Introduce los jugadores actuales: " << azul << endl;
	flujo >> v->Jugadores;

	cout << azulfuerte << "Introduce las plataformas donde esta disponible este videojuego: " << azul << endl;
	flujo.clear();
	getline(flujo, v->Plataformas);	

	return flujo;
}