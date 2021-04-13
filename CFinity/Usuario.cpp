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
#include "Usuario.h"
using namespace std;

Usuario::Usuario(){

	Login = "NULL";
	Nombre = "NULL";
	Apellidos = "NULL";
	FotoPerfil = "NULL";

	//Inicializacion del vector de ListaBusqueda
	TotalBusquedas = 0;
	ListaBusqueda = new Media *[this->TotalBusquedas+1];
    if (!this->ListaBusqueda){
        cout << rojo << "Error en el sistema" << rest << endl;
        exit(-1);
    }
}

Usuario::Usuario(string Login, string Nombre, string Apellidos, string FotoPerfil){
	this->Login = Login;
	this->Nombre = Nombre;
	this->Apellidos = Apellidos;
	this->FotoPerfil = FotoPerfil;

	TotalBusquedas = 0;
	ListaBusqueda = new Media *[this->TotalBusquedas+1];
    if (!this->ListaBusqueda){
        cout << rojo << "Error en el sistema" << rest << endl;
        exit(-1);
    }
}

Usuario::~Usuario(){

	Login = "NULL";
	Nombre = "NULL";
	Apellidos = "NULL";
	FotoPerfil = "NULL";

	delete[] ListaBusqueda;
	ListaBusqueda = 0;

	TotalBusquedas = 0;
}

void Usuario::setLogin(string Login){
	this->Login = Login;
}

void Usuario::setNombre(string Nombre){
	this->Nombre = Nombre;
}

void Usuario::setApellidos(string Apellidos){
	this->Apellidos = Apellidos;
}

void Usuario::setFotoPerfil(string FotoPerfil){
	this->FotoPerfil = FotoPerfil;
}

//Gets
string Usuario::getLogin() const{
	return this->Login;
}

string Usuario::getNombre() const{
	return this->Nombre;
}

string Usuario::getApellidos() const{
	return this->Apellidos;
}

string Usuario::getFotoPerfil() const{
	return this->FotoPerfil;
}

int Usuario::getTotalBusquedas() const{
	return this->TotalBusquedas;
}

void Usuario::resizeBusquedasMas(){

    TotalBusquedas++;

    Media **c = new Media *[this->TotalBusquedas+1]; 

    if (c == 0){
        cout << rojo << "Error. No hay memoria suficiente. Se abortará la ejecución" << rest << endl;
        exit(-1);
    }

    for(int i = 0; i < TotalBusquedas; i++){
        c[i] = this->ListaBusqueda[i];
    }

    delete[] this->ListaBusqueda;
    this->ListaBusqueda = c;
    c = 0;
}

void Usuario::resizeBusquedasMenos(){

	TotalBusquedas--;

    Media **c = new Media *[this->TotalBusquedas+1];

    if (c == 0){
        cout << rojo << "Error. No hay memoria suficiente. Se abortará la ejecución" << rest << endl;
        exit(-1);
    }

    for(int i = 0; i < TotalBusquedas; i++){
        c[i] = this->ListaBusqueda[i];
    }

    delete[] this->ListaBusqueda;
    this->ListaBusqueda = c;
    c = 0;	
}



void Usuario::insertarMediaEnListaDeBusqueda(Media *m){
	ListaBusqueda[TotalBusquedas] = m;
	resizeBusquedasMas();
}

void Usuario::printVectorBusquedas(){
	for(int i = 0; i < TotalBusquedas; i++){
		if(Cancion *can = dynamic_cast<Cancion *> (ListaBusqueda[i])){
			//cout << rojo << "DEBUG PRINT MEDIAS POLIMORFICOS 1 " << rest << endl;
			cout << can << endl;
		}else if(Serie *ser = dynamic_cast<Serie *> (ListaBusqueda[i])){
			//cout << rojo << "DEBUG PRINT MEDIAS POLIMORFICOS 2 " << rest << endl;
			cout << ser << endl;
		}else if(Pelicula *pel = dynamic_cast<Pelicula *> (ListaBusqueda[i])){
			//cout << rojo << "DEBUG PRINT MEDIAS POLIMORFICOS 3 " << rest << endl;
			cout << pel << endl;
		}else if(Videojuego *vid = dynamic_cast<Videojuego *> (ListaBusqueda[i])){
			//cout << rojo << "DEBUG PRINT MEDIAS POLIMORFICOS 4 " << rest << endl;
			cout << vid << endl;
		}
	}
}

void Usuario::vaciarVectorBusquedas(){

    TotalBusquedas = 0;

    Media **c = new Media *[this->TotalBusquedas+1]; 

    if (c == 0){
        cout << rojo << "Error. No hay memoria suficiente. Se abortará la ejecución" << rest << endl;
        exit(-1);
    }

    delete[] this->ListaBusqueda;
    this->ListaBusqueda = c;
    c = 0;
}

bool Usuario::compruebaRank(Media *m){

	bool correcto = true;

	if(TotalBusquedas != 0){
		for(int i = 0; i < TotalBusquedas; i++){
			if(ListaBusqueda[i]->getIDMedia() == m->getIDMedia()){
				correcto = false;
			}
		}
	}

	return correcto;
}
/*
void Usuario::ordenaVectorBusquedasPorNotaGeneral(){
	int pos_min; //Posicion del vector desordenado donde se encuentra el elemento mas pequeño
	Media *aux = new Media;

	for(int i = 0; i < TotalBusquedas-1; i++){
		pos_min = i;	
		for (int j = i+1; j < TotalBusquedas; j++){
			if (ListaBusqueda[j]->getNotaGeneral() < ListaBusqueda[pos_min]->getNotaGeneral()){
				pos_min = j;
			}

		}
		aux = ListaBusqueda[i];
		ListaBusqueda[i] = ListaBusqueda[pos_min];
		ListaBusqueda[pos_min] = aux;
	}

	aux = 0;
}
*/
Usuario* Usuario::operator=(const Usuario *m){
	if(m != this){
		this->Login = m->Login;
		this->Nombre = m->Nombre;
		this->Apellidos = m->Apellidos;
		this->FotoPerfil = m->FotoPerfil;
	}

	return this;
}

ostream& operator<<(ostream &flujo, const Usuario *m){
	flujo << azul << "Login: " << cianfuerte << m->getLogin() << rest << endl;
	flujo << azul << "Nombre: " << cianfuerte << m->getNombre() << rest << endl;
	flujo << azul << "Apellidos: " << cianfuerte << m->getApellidos() << rest << endl;
	flujo << azul << "Foto de perfil: " << cianfuerte << m->getFotoPerfil() << rest << endl;
	flujo << endl;
}

istream& operator>>(istream &flujo, Usuario *m){

	cout << azulfuerte << "Introduce tu nombre: " << azul << endl;
	flujo.clear();
	flujo.ignore();
	getline(flujo, m->Nombre);

	cout << azulfuerte << "Introduce tus apellidos: " << azul << endl;
	flujo.clear();
	flujo.ignore();
	getline(flujo, m->Apellidos);

	cout << azulfuerte << "Introduce la URL de tu foto de perfil " << azul << endl;
	flujo.clear();
	flujo.ignore();
	getline(flujo, m->FotoPerfil);

	return flujo;
}