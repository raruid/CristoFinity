#ifndef PELICULA_H
#define PELICULA_H

#include <iostream>
#include "Media.h"
using namespace std;

class Pelicula: public Media {
protected:
	string Director;
	string Reparto;
	string Guion;
	string Productor;
public:

	/**
	@brief Crea un objeto de la clase Pelicula
	@autor Raúl Ruiz Idáñez
	@ver 1.0
	*/

	Pelicula();

	/**
	@brief Crea un objeto de la clase Pelicula por parametros
	@autor Raúl Ruiz Idáñez
	@ver 1.0
	*/

	Pelicula(int IDMedia, string Titulo, string Genero, int DuracionEnSegundos, string Fecha_Publicacion, int Pegi, string Descripcion, string Director, string Reparto, string Guion, string Productor);

	/**
	@brief Destruye el objeto de la clase Pelicula
	@autor Raúl Ruiz Idáñez
	@ver 1.0
	*/

	virtual ~Pelicula();

	//SETS

	/**
	@brief Inserta un Director pasado por parametros en el atributo Director
	@autor Raúl Ruiz Idáñez
	@ver 1.0
	*/	

	void setDirector(string Director);

	/**
	@brief inserta el Reparto de la Pelicula parado por parametros en el atributo Reparto
	@autor Raúl Ruiz Idáñez
	@ver 1.0
	*/	

	void setReparto(string Reparto);

	/**
	@brief Inserta el Guion pasado por parametros en el atributo Guion
	@autor Raúl Ruiz Idáñez
	@ver 1.0
	*/	

	void setGuion(string Guion);

	/**
	@brief Inserta un Productor pasado por parametros en el atributo Productor
	@autor Raúl Ruiz Idáñez
	@ver 1.0
	*/	

	void setProductor(string Productor);

	//GETS

	/**
	@brief Retorna el valor director del objeto Pelicula
	@autor Raúl Ruiz Idáñez
	@ver 1.0
	*/

	string getDirector() const;

	/**
	@brief Retorna el valor de Reparto del objeto Pelicula
	@autor Raúl Ruiz Idáñez
	@ver 1.0
	*/

	string getReparto() const;

	/**
	@brief Retorna el valor Guion del objeto Pelicula
	@autor Raúl Ruiz Idáñez
	@ver 1.0
	*/

	string getGuion() const;

	/**
	@brief Retorna el valor Productor del objeto Pelicula
	@autor Raúl Ruiz Idáñez
	@ver 1.0
	*/

	string getProductor() const;

	/**
	@brief sobrecarga el operador = 
	@pre el objeto const pasado por parametro debe tener los valores deseados y no estar vacio o con valores erroneos
	@pos el objeto Pelicula *v se asigna a el objeto de tipo Pelicula que llama a este metodo
	@autor Raúl Ruiz Idáñez
	@ver 1.0
	*/

	Pelicula* operator=(const Pelicula *p);

	/**
	@brief sobrecarga del operador de salida, imprimiendo este al completo solo con poner cout << <Pelicula>
	@pre objeto debe estar creado 
	@pos el objeto imprimira todos sus atributos
	@autor Raúl Ruiz Idáñez
	@ver 1.0
	*/

	friend ostream& operator<<(ostream &flujo, const Pelicula *p);

	/**
	@brief sobrecarga el operador de entrada
	@pre un objeto de tipo Pelicula debe estar creado y pasado como parametro
	@pos el objeto sobreescribira sus atributos
	@autor Raúl Ruiz Idáñez
	@ver 1.0
	*/		

	friend istream& operator>>(istream &flujo, Pelicula *p);
	
};

#endif