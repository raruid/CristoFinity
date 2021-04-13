#ifndef COMENTARIO_H
#define COMENTARIO_H

#include <iostream>
using namespace std;

class Comentario {
private:
	int IDComentario;
	string Login_Usuario;
	string Texto_Comentario;

public:

	/**
	@brief Construye un objeto de la clase Comentario
	@pos El objeto de clase Comentario sera creado
	@autor Raúl Ruiz Idáñez
	@ver 1.0
	*/

	Comentario();

	/**
	@brief Construye un objeto de la clase Comentario por parametros
	@pos El objeto de clase Comentario sera creado en base a los parametros recibidos
	@autor Raúl Ruiz Idáñez
	@ver 1.0
	*/

	Comentario(int IDCom, string Login, string Texto);

	/**
	@brief Destruye un objeto de la clase Comentario
	@pre el objeto debe estar creado
	@pos El objeto de clase Comentario sera creado
	@autor Raúl Ruiz Idáñez
	@ver 1.0
	*/

	~Comentario();

	/**
	@brief Inserta el ID de un comentario en el atributo IDComentario
	@autor Raúl Ruiz Idáñez
	@ver 1.0
	*/

	void setIDComentario(int ID);

	/**
	@brief Inserta el login de el Usuario que ha publicado el comentario
	@autor Raúl Ruiz Idáñez
	@ver 1.0
	*/

	void setLogin(string login);

	/**
	@brief Inserta el texto del comentario, en el atributo Texto 
	@autor Raúl Ruiz Idáñez
	@ver 1.0
	*/

	void setTexto(string texto);

	//Gets

	/**
	@brief te devuelve el ID del comentario 
	@autor Raúl Ruiz Idáñez
	@ver 1.0
	*/

	int getIDComentario() const;

	/**
	@brief te devuleve el login del usuario que ha escrito el comentario  
	@autor Raúl Ruiz Idáñez
	@ver 1.0
	*/

	string getLogin() const;

	/**
	@brief te devuelve el texto del comentario 
	@autor Raúl Ruiz Idáñez
	@ver 1.0
	*/

	string getTexto() const;

	/**
	@brief imprime todos los atributos del objeto Comentario
	@pre el objeto debe tener introducidos los valores para su correcta impresion
	@pos el objeto quedara impreso
	@autor Raúl Ruiz Idáñez
	@ver 1.0
	*/

	void print();

	/**
	@brief sobrecarga el operador = 
	@pre el objeto const pasado por parametro debe tener valores correctos, para su correcta asignacion
	@pos el objeto Comentario *c se asigna a el objeto de tipo Comentario que llama a este metodo 
	@autor Raúl Ruiz Idáñez
	@ver 1.0
	*/

	Comentario* operator=(const Comentario *c);

	/**
	@brief imprime todos los atributos del objeto Comentario mediante la sobrecarga del operador de salida
	@pre el objeto debe tener introducidos los valores para su correcta impresion
	@pos el objeto quedara impreso
	@autor Raúl Ruiz Idáñez
	@ver 1.0
	*/

	friend ostream& operator<<(ostream &flujo, Comentario *c);
	
	/**
	@brief sobrecarga el operador de entrada
	@pre el objeto que deseamos modificar debe estar creado y pasado por parametro
	@pos el objeto sobreescribira sus atributos
	@autor Raúl Ruiz Idáñez
	@ver 1.0
	*/

	friend istream& operator>>(istream &flujo, Comentario *c);

};

#endif