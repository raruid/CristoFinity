#ifndef ADMINISTRADOR_H
#define ADMINISTRADOR_H

#include <iostream>
#include "Usuario.h"
#include "Normal.h"
using namespace std;

class Administrador: public Usuario{
private:
	Usuario **VectorBusquedasUsuarios;
	int TotalUsuariosBuscados;

	/**
	@brief redimensiona el vector de usuarios normales asociados en +1 espacio para el vector, este metodo se utilizara cada vez que se inserte un usuario normal asociado
	@pre debe haber minimo 1 usuario normal en el vector para utilizar la redimension a mas
	@pos el vector quedara modificado y redimensionado
	@autor Raúl Ruiz Idáñez
	@ver 1.0
	*/

	void resizeVectorUsuariosBuscadosMas();

	/**
	@brief redimensiona el vector de usuarios normales asociados en -1 espacio para el vector, este metodo se utilizara cada vez que se elimine un usuario normal asociado
	@pre debe haber minimo 1 usuario normal en el vector para utilizar la redimension a menos
	@pos el vector quedara modificado y redimensionado
	@autor Raúl Ruiz Idáñez
	@ver 1.0
	*/

	void resizeVectorUsuariosBuscadosMenos();
public:

	/**
	@brief Construye un objeto de la clase Administrador
	@autor Raúl Ruiz Idáñez
	@ver 1.0
	*/

	Administrador();

	/**
	@brief Construye un objeto de la clase Administrador por parametros
	@autor Raúl Ruiz Idáñez
	@ver 1.0
	*/

	Administrador(string Login, string Nombre, string Apellidos, string FotoPerfil);

	/**
	@brief Destruye un objeto de la clase Administrador
	@autor Raúl Ruiz Idáñez
	@ver 1.0
	*/

	~Administrador();

	/**
	@brief retorna el valor de las busquedas de usuarios
	@autor Raúl Ruiz Idáñez
	@ver 1.0
	*/

	int getTotalUsuariosBuscados();

	/**
	@brief inserta un usuario pasado por parametros en el vector de busquedas de usuarios de el administrador
	@pos el usuario quedara insertado y el vector redimensionado
	@autor Raúl Ruiz Idáñez
	@ver 1.0
	*/

	void insertarUsuarioEnVectorBusquedasUsuario(Usuario *n);

	/**
	@brief imprime el vector de busquedas de usuarios
	@autor Raúl Ruiz Idáñez
	@ver 1.0
	*/

	void printVectorUsuariosBuscados();

	/**
	@brief reinicia el vector de busquedas de usuario, creando un vector nuevo y reiniciando la dimension a 0
	@autor Raúl Ruiz Idáñez
	@ver 1.0
	*/

	void vaciarVectorUsuariosBuscados();

	/**
	@brief sobrecarga el operador = 
	@pre el objeto const pasado por parametro debe tener los valores deseados y no estar vacio o con valores erroneos
	@pos el objeto Administrador *v se asigna a el objeto de tipo Administrador que llama a este metodo
	@autor Raúl Ruiz Idáñez
	@ver 1.0
	*/

	Administrador* operator=(const Administrador *m);

	/**
	@brief sobrecarga el operador de entrada
	@pre un objeto de tipo Administrador debe estar creado y pasado como parametro
	@pos el objeto sobreescribira sus atributos
	@autor Raúl Ruiz Idáñez
	@ver 1.0
	*/

	friend istream& operator>>(istream &flujo, Administrador *m);

	/**
	@brief sobrecarga del operador de salida, imprimiendo este al completo solo con poner cout << <Administrador>
	@pre objeto debe estar creado m
	@pos el objeto imprimira todos sus atributos
	@autor Raúl Ruiz Idáñez
	@ver 1.0
	*/

	friend ostream& operator<<(ostream &flujo, const Administrador *m);
	
};

#endif