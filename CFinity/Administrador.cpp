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
#include "Administrador.h"
using namespace std;

Administrador::Administrador(): Usuario(){
	//Inicializacion del vector de VectorBusquedasUsuarios
	//cout << rojo << "DEBUG: CONSTRUCTOR ADMIN " << rest << endl;
	TotalUsuariosBuscados = 0;
	VectorBusquedasUsuarios = new Usuario *[this->TotalUsuariosBuscados+1];
    if (!this->VectorBusquedasUsuarios){
        cout << rojo << "Error en el sistema" << rest << endl;
        exit(-1);
    }
}

Administrador::Administrador(string Login, string Nombre, string Apellidos, string FotoPerfil){
	this->Login = Login;
	this->Nombre = Nombre;
	this->Apellidos = Apellidos;
	this->FotoPerfil = FotoPerfil;

	//Inicializacion del vector de VectorBusquedasUsuarios
	//cout << rojo << "DEBUG: CONSTRUCTOR ADMIN " << rest << endl;
	TotalUsuariosBuscados = 0;
	VectorBusquedasUsuarios = new Usuario *[this->TotalUsuariosBuscados+1];
    if (!this->VectorBusquedasUsuarios){
        cout << rojo << "Error en el sistema" << rest << endl;
        exit(-1);
    }
}

Administrador::~Administrador(){

	//cout << rojo << "DEBUG: DESTRUCTOR ADMIN " << rest << endl;

	delete[] VectorBusquedasUsuarios;
	VectorBusquedasUsuarios = 0;

	TotalUsuariosBuscados = 0;
}

int Administrador::getTotalUsuariosBuscados(){
	return TotalUsuariosBuscados;
}

void Administrador::resizeVectorUsuariosBuscadosMas(){

    TotalUsuariosBuscados++;

    Usuario **c = new Usuario *[this->TotalUsuariosBuscados+1]; 

    if (c == 0){
        cout << rojo << "Error. No hay memoria suficiente. Se abortará la ejecución" << rest << endl;
        exit(-1);
    }

    for(int i = 0; i < TotalUsuariosBuscados; i++){
        c[i] = this->VectorBusquedasUsuarios[i];
    }

    delete[] this->VectorBusquedasUsuarios;
    this->VectorBusquedasUsuarios = c;
    c = 0;
}

void Administrador::resizeVectorUsuariosBuscadosMenos(){

	TotalUsuariosBuscados--;

    Usuario **c = new Usuario *[this->TotalUsuariosBuscados+1];

    if (c == 0){
        cout << rojo << "Error. No hay memoria suficiente. Se abortará la ejecución" << rest << endl;
        exit(-1);
    }

    for(int i = 0; i < TotalUsuariosBuscados; i++){
        c[i] = this->VectorBusquedasUsuarios[i];
    }

    delete[] this->VectorBusquedasUsuarios;
    this->VectorBusquedasUsuarios = c;
    c = 0;
}

void Administrador::insertarUsuarioEnVectorBusquedasUsuario(Usuario *n){
	VectorBusquedasUsuarios[TotalUsuariosBuscados] = n;
	resizeVectorUsuariosBuscadosMas();
}

void Administrador::printVectorUsuariosBuscados(){
	
	for(int i = 0; i < TotalUsuariosBuscados; i++){
		if(Normal *nor = dynamic_cast<Normal *> (VectorBusquedasUsuarios[i])){
			cout << nor;
		}
	}
}

void Administrador::vaciarVectorUsuariosBuscados(){

    TotalUsuariosBuscados = 0;

    Usuario **c = new Usuario *[this->TotalUsuariosBuscados+1]; 

    if (c == 0){
        cout << rojo << "Error. No hay memoria suficiente. Se abortará la ejecución" << rest << endl;
        exit(-1);
    }

    delete[] this->VectorBusquedasUsuarios;
    this->VectorBusquedasUsuarios = c;
    c = 0;
}

Administrador* Administrador::operator=(const Administrador *m){
	if(m != this){
		this->Login = m->Login;
		this->Nombre = m->Nombre;
		this->Apellidos = m->Apellidos;
		this->FotoPerfil = m->FotoPerfil;
	}

	return this;
}

ostream& operator<<(ostream &flujo, const Administrador *m){
	flujo << azul << "Login: " << cianfuerte << m->getLogin() << rest << endl;
	flujo << azul << "Nombre: " << cianfuerte << m->getNombre() << rest << endl;
	flujo << azul << "Apellidos: " << cianfuerte << m->getApellidos() << rest << endl;
	flujo << azul << "Foto de perfil: " << cianfuerte << m->getFotoPerfil() << rest << endl;
	flujo << endl;
}

istream& operator>>(istream &flujo, Administrador *m){

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