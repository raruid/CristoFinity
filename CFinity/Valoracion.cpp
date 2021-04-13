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
using namespace std;

Valoracion::Valoracion(){
	this->Login = "NULL";
	this->Puntuacion = 0;
}

Valoracion::Valoracion(string login, float puntuacion){
	this->Login = login;
	this->Puntuacion = puntuacion;
}

Valoracion::~Valoracion(){
	this->Login = "NULL";
	this->Puntuacion = 0;
}

void Valoracion::setLogin(string login){
	this->Login = login;
}

void Valoracion::setPuntuacion(float valor){
	this->Puntuacion = valor;
}

string Valoracion::getLogin() const{
	return this->Login;
}

float Valoracion::getPuntuacion() const{
	return this->Puntuacion;
}

void Valoracion::print(){
	cout << azul << "Usuario: " << cianfuerte << this->getLogin() << rest << endl;
	cout << azul << "Puntuacion: " << cianfuerte << this->getPuntuacion() << rest << endl;
}

Valoracion* Valoracion::operator=(const Valoracion *v){
	if(v != this){
		this->Login = v->Login;
		this->Puntuacion = v->Puntuacion;
	}
	return this;
}

istream& operator>>(istream &flujo, Valoracion *v){

	cout << azulfuerte << "Introduce una puntuacion: " << azul << endl;
	flujo >> v->Puntuacion;
	cout << rest;

	return flujo;
}

ostream& operator<<(ostream &flujo, const Valoracion *v){
	flujo << azul << "Login " << cianfuerte << v->getLogin() << rest << endl;
	flujo << azul << "Puntuacion " << cianfuerte << v->getPuntuacion() << rest << endl;
	flujo << endl;

	return flujo;
}