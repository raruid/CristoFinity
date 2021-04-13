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
#include "Comentario.h"
using namespace std;

Comentario::Comentario(){
	this->IDComentario = 0;
	this->Login_Usuario = "NULL";
	this->Texto_Comentario = "NULL";
}

Comentario::Comentario(int IDCom, string Login, string Texto){
	this->IDComentario = IDCom;
	this->Login_Usuario = Login;
	this->Texto_Comentario = Texto;
}

Comentario::~Comentario(){
	this->IDComentario = 0;
	this->Login_Usuario = "NULL";
	this->Texto_Comentario = "NULL";
}

void Comentario::setIDComentario(int ID){
	this->IDComentario = ID;
}

void Comentario::setLogin(string login){
	this->Login_Usuario = login;
}

void Comentario::setTexto(string texto){
	this->Texto_Comentario = texto;
}

int Comentario::getIDComentario() const{
	return this->IDComentario;
}

string Comentario::getLogin() const{
	return this->Login_Usuario;
}

string Comentario::getTexto() const{
	return this->Texto_Comentario;
}

void Comentario::print(){
	cout << azul << "ID del Comentario: " << cianfuerte << this->getIDComentario() << rest << endl;
	cout << azul << "Lo ha escrito: " << cianfuerte << this->getLogin() << rest << endl;
	cout << azul << "Texto: " << cianfuerte << this->getTexto() << rest << endl;
}

Comentario* Comentario::operator=(const Comentario *c){
	if(c != this){
		this->IDComentario = c->IDComentario;
		this->Login_Usuario = c->Login_Usuario;
		this->Texto_Comentario = c->Login_Usuario;
	}

	return this;
}

ostream& operator<<(ostream &flujo, Comentario *c){
	flujo << azul << "ID del Comentario: " << cianfuerte << c->getIDComentario() << rest << endl;
	flujo << azul << "Lo ha escrito: " << cianfuerte << c->getLogin() << rest << endl;
	flujo << azul << "Texto: " << cianfuerte << c->getTexto() << rest << endl;
	flujo << endl;

	return flujo;
}

istream& operator>>(istream &flujo, Comentario *c){

	cout << azulfuerte << "Introduce un Texto: " << azul << endl;
	flujo.clear();
	flujo.ignore();
	getline(flujo, c->Texto_Comentario);
	cout << rest;

	cout << endl;

	return flujo;
}

