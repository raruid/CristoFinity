#ifndef VALORACION_H
#define VALORACION_H

#include <iostream>
using namespace std;

class Valoracion {
private:
	string Login;
	float Puntuacion;

public:

	/**
	@brief Construye un objeto de la clase Valoracion
	@pos El objeto de clase Valoracion sera creado
	@autor Raúl Ruiz Idáñez
	@ver 1.0
	*/

	Valoracion();

	/**
	@brief Construye un objeto de la clase Valoracion mediante parametros
	@pre Se le debe de pasar como parametro, un valor float, como su atributo
	@pos El objeto de clase Valoracion sera creado mediante el parametro que haya recibido
	@autor Raúl Ruiz Idáñez
	@ver 1.0
	*/

	Valoracion(string login, float puntuacion);

	/**
	@brief Destruye un objeto de la clase Valoracion
	@pre Debe haber un objeto de la clase Valoracion, creado
	@pos El objeto de clase Valoracion sera destruido
	@autor Raúl Ruiz Idáñez
	@ver 1.0
	*/

	~Valoracion();

	/**
	@brief Iserta el parameto string valor, en el atributo Login
	@pre un objeto debe estar creado, se debe pasar por parametro un valor string
	@pos el atributo Login quedara sobreescrito
	@autor Raúl Ruiz Idáñez
	@ver 1.0
	*/

	void setLogin(string login);

	/**
	@brief Iserta el parameto float valor, en el atributo Puntuacion 
	@pre un objeto debe estar creado, se debe pasar por parametro un valor float
	@pos el atributo Puntuacion quedara sobreescrito
	@autor Raúl Ruiz Idáñez
	@ver 1.0
	*/

	void setPuntuacion(float valor);

	/**
	@brief retorna el valor del atributo Login
	@pre el atributo Login debe tener un valor no erroneo
	@pos te devolvera el atributo Login
	@autor Raúl Ruiz Idáñez
	@ver 1.0
	*/

	string getLogin() const;

	/**
	@brief retorna el valor del atributo Puntuacion
	@pre el atributo Puntuacion debe tener un valor no erroneo
	@pos te devolvera el atributo Puntuacion
	@autor Raúl Ruiz Idáñez
	@ver 1.0
	*/

	float getPuntuacion() const;

	/**
	@brief Imprime los atributos del objeto Valoracion
	@pre el objeto debe tener valores correctos
	@pos el objeto quedara impreso
	@autor Raúl Ruiz Idáñez
	@ver 1.0
	*/

	void print();

	/**
	@brief sobrecarga el operador = 
	@pre el objeto const pasado por parametro debe tener los valores deseados y no estar vacio o con valores erroneos
	@pos el objeto Valoracion *v se asigna a el objeto de tipo Valoracion que llama a este metodo
	@autor Raúl Ruiz Idáñez
	@ver 1.0
	*/

	Valoracion* operator=(const Valoracion *v);

	/**
	@brief sobrecarga el operador de entrada
	@pre un objeto de tipo Valoracion debe estar creado y pasado como parametro
	@pos el objeto sobreescribira sus atributos
	@autor Raúl Ruiz Idáñez
	@ver 1.0
	*/

	friend istream& operator>>(istream &flujo, Valoracion *v);

	/**
	@brief sobrecarga del operador de salida, imprimiendo este al completo solo con poner cout << <Valoracion>
	@pre objeto debe estar creado 
	@pos el objeto imprimira todos sus atributos
	@autor Raúl Ruiz Idáñez
	@ver 1.0
	*/

	friend ostream& operator<<(ostream &flujo, const Valoracion *v);
	
};

#endif