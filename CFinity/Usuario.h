#ifndef USUARIO_H
#define USUARIO_H

#include <iostream>
#include "Media.h"
#include "Videojuego.h"
#include "Serie.h"
#include "Pelicula.h"
#include "Cancion.h"
using namespace std;

class Usuario {
protected:
	string Login;
	string Nombre;
	string Apellidos;
	string FotoPerfil;
	Media **ListaBusqueda;
	int TotalBusquedas;

	/**
	@brief redimensiona el vector de medias en +1 espacio para el vector, este metodo se utilizara cada vez que se inserte una media
	@pre debe haber minimo 1 media en el vector para utilizar la redimension
	@pos el vector quedara modificado y redimensionado
	@autor Raúl Ruiz Idáñez
	@ver 1.0
	*/

	void resizeBusquedasMas();

	/**
	@brief redimensiona el vector de medias en -1 espacio para el vector, este metodo se utilizara cada vez que se elimine una media
	@pre debe haber minimo 1 media en el vector para utilizar la redimension a menos
	@pos el vector quedara modificado y redimensionado
	@autor Raúl Ruiz Idáñez
	@ver 1.0
	*/

	void resizeBusquedasMenos();


public:

	/**
	@brief Construye un objeto de la clase Usuario
	@autor Raúl Ruiz Idáñez
	@ver 1.0
	*/

	Usuario();

	/**
	@brief Construye un objeto de la clase Usuario por parametros
	@autor Raúl Ruiz Idáñez
	@ver 1.0
	*/

	Usuario(string Login, string Nombre, string Apellidos, string FotoPerfil);

	/**
	@brief Construye un objeto de la clase Usuario
	@autor Raúl Ruiz Idáñez
	@ver 1.0
	*/

	virtual ~Usuario();

	/**
	@brief introduce el login pasado por referencia en el atributo login 
	@autor Raúl Ruiz Idáñez
	@ver 1.0
	*/

	void setLogin(string Login);

	/**
	@brief introduce el nombre del usuario en el atributo nombre
	@autor Raúl Ruiz Idáñez
	@ver 1.0
	*/

	void setNombre(string Nombre);

	/**
	@brief instroduce los apellidos del usuario en el atributo apellidos
	@autor Raúl Ruiz Idáñez
	@ver 1.0
	*/


	void setApellidos(string Apellidos);

	/**
	@brief instroduce la foto de perfil del usuario en el atributo FotoPerfil
	@autor Raúl Ruiz Idáñez
	@ver 1.0
	*/


	void setFotoPerfil(string FotoPerfil);

	//Gets

	/**
	@brief retorna el login del usuario
	@autor Raúl Ruiz Idáñez
	@ver 1.0
	*/


	string getLogin() const;

	/**
	@brief retorna el nombre del usuario
	@autor Raúl Ruiz Idáñez
	@ver 1.0
	*/


	string getNombre() const;

	/**
	@brief retorna los apellidos del usuario
	@autor Raúl Ruiz Idáñez
	@ver 1.0
	*/


	string getApellidos() const;

	/**
	@brief retorna la foto de perfil del usuario
	@autor Raúl Ruiz Idáñez
	@ver 1.0
	*/


	string getFotoPerfil() const;

	/**
	@brief retorna la dimension de las busquedas del usuario
	@autor Raúl Ruiz Idáñez
	@ver 1.0
	*/


	int getTotalBusquedas() const;

	/**
	@brief retorna la dimension del total de medias asociadas
	@autor Raúl Ruiz Idáñez
	@ver 1.0
	*/

	/**
	@brief inserta el media encontrado como resultado de la busqueda, en el vector de busquedas
	@pre debe haber medias que añadir a este vector de busquedas
	@pos en el vector de busquedas quedara actualizado y redimensionado
	@autor Raúl Ruiz Idáñez
	@ver 1.0
	*/

	void insertarMediaEnListaDeBusqueda(Media *m);

	/**
	@brief imprime el vector de las busquedas hechas anteriormente
	@pre debe haber un media en el vector de busquedas
	@pos el vector de busquedas quedara impreso
	@autor Raúl Ruiz Idáñez
	@ver 1.0
	*/

	void printVectorBusquedas();

	/**
	@brief metodo que vacia el vector de busquedas 
	@pre para eliminar el vector de busquedas es recomendable que este contenga medias
	@pos el vector de busquedas quedara reiniciado
	@autor Raúl Ruiz Idáñez
	@ver 1.0
	*/

	void vaciarVectorBusquedas();

	/**
	@brief metodo que comprueba si el media pasado por parametro, se encuentra en el vector de busquedas
	@pre para que funcione debe haber medias en el vector de busquedas, si no hay, no hara nada, retornara true
	@pos retornara true o false segun se cumpla o no 
	@autor Raúl Ruiz Idáñez
	@ver 1.0
	*/

	bool compruebaRank(Media *m);

	//void ordenaVectorBusquedasPorNotaGeneral();

	/**
	@brief sobrecarga el operador = 
	@pre el objeto const pasado por parametro debe tener los valores deseados y no estar vacio o con valores erroneos
	@pos el objeto Valoracion *v se asigna a el objeto de tipo Valoracion que llama a este metodo
	@autor Raúl Ruiz Idáñez
	@ver 1.0
	*/

	Usuario* operator=(const Usuario *m);

	/**
	@brief sobrecarga el operador de entrada
	@pre un objeto de tipo Usuario debe estar creado y pasado como parametro
	@pos el objeto sobreescribira sus atributos
	@autor Raúl Ruiz Idáñez
	@ver 1.0
	*/

	friend istream& operator>>(istream &flujo, Usuario *m);

	/**
	@brief sobrecarga del operador de salida, imprimiendo este al completo solo con poner cout << <Usuario>
	@pre objeto debe estar creado m
	@pos el objeto imprimira todos sus atributos
	@autor Raúl Ruiz Idáñez
	@ver 1.0
	*/

	friend ostream& operator<<(ostream &flujo, const Usuario *m);
	
};

#endif