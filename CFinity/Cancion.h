#ifndef CANCION_H
#define CANCION_H

#include <iostream>
#include "Media.h"
using namespace std;

class Cancion: public Media {
private:
	string Artista;
	string Album;
public:

	/**
	@brief Crea un objeto de la clase Cancion
	@autor Raúl Ruiz Idáñez
	@ver 1.0
	*/

	Cancion();

	/**
	@brief Crea un objeto de la clase Cancion por parametros
	@autor Raúl Ruiz Idáñez
	@ver 1.0
	*/

	Cancion(int IDMedia, string Titulo, string Genero, int DuracionEnSegundos, string Fecha_Publicacion, int Pegi, string Descripcion, string Artista, string Album);

	/**
	@brief Destruye el objeto de la clase Cancion
	@autor Raúl Ruiz Idáñez
	@ver 1.0
	*/

	~Cancion();

	//SETS

	/**
	@brief Inserta un artista pasado por parametros en el atributo Artista
	@autor Raúl Ruiz Idáñez
	@ver 1.0
	*/	

	void setArtista(string artista);

	/**
	@brief inserta el album de la cancion parado por parametros en el atributo Album
	@autor Raúl Ruiz Idáñez
	@ver 1.0
	*/	

	void setAlbum(string Album);

	//GETS

	/**
	@brief retorna el atributo Artista
	@autor Raúl Ruiz Idáñez
	@ver 1.0
	*/	

	string getArtista()const;

	/**
	@brief retorna el atributo Album
	@autor Raúl Ruiz Idáñez
	@ver 1.0
	*/	

	string getAlbum()const;	

	/**
	@brief sobrecarga el operador = 
	@pre el objeto const pasado por parametro debe tener los valores deseados y no estar vacio o con valores erroneos
	@pos el objeto Cancion *v se asigna a el objeto de tipo Cancion que llama a este metodo
	@autor Raúl Ruiz Idáñez
	@ver 1.0
	*/

	Cancion* operator=(const Cancion *c);

	/**
	@brief sobrecarga del operador de salida, imprimiendo este al completo solo con poner cout << <Cancion>
	@pre objeto debe estar creado 
	@pos el objeto imprimira todos sus atributos
	@autor Raúl Ruiz Idáñez
	@ver 1.0
	*/

	friend ostream& operator<<(ostream &flujo, const Cancion *c);

	/**
	@brief sobrecarga el operador de entrada
	@pre un objeto de tipo Cancion debe estar creado y pasado como parametro
	@pos el objeto sobreescribira sus atributos
	@autor Raúl Ruiz Idáñez
	@ver 1.0
	*/		

	friend istream& operator>>(istream &flujo, Cancion *c);
	
};

#endif