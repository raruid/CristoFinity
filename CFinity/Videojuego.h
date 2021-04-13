#ifndef VIDEOJUEGO_H
#define VIDEOJUEGO_H

#include <iostream>
#include "Media.h"
using namespace std;

class Videojuego: public Media{
private:
	string Desarrollador;
	string Editor;
	int Jugadores;
	string Plataformas;
public:

	/**
	@brief Crea un objeto de la clase Videojuego
	@autor Raúl Ruiz Idáñez
	@ver 1.0
	*/

	Videojuego();

	/**
	@brief Crea un objeto de la clase Videojuego por parametros
	@autor Raúl Ruiz Idáñez
	@ver 1.0
	*/

	Videojuego(int IDMedia, string Titulo, string Genero, int DuracionEnSegundos, string Fecha_Publicacion, int Pegi, string Descripcion, string Desarrollador, string Editor, int Jugadores, string Plataformas);

	/**
	@brief Crea un objeto de la clase Videojuego
	@autor Raúl Ruiz Idáñez
	@ver 1.0
	*/

	~Videojuego();

	/**
	@brief Crea un objeto de la clase Videojuego
	@autor Raúl Ruiz Idáñez
	@ver 1.0
	*/

	/**
	@brief Inserta el desarrollador en el atributo desarrollador de la clase Videojuego
	@autor Raúl Ruiz Idáñez
	@ver 1.0
	*/

	//SETS

	void setDesarrollador(string Desarrollador);

	/**
	@brief Inserta el parametro @edit en el atributo Editor del objeto Videojuego
	@autor Raúl Ruiz Idáñez
	@ver 1.0
	*/

	void setEditor(string Editor);

	/**
	@brief Inserta el parametro @players en el atributo Jugadores del objeto Videojuego
	@autor Raúl Ruiz Idáñez
	@ver 1.0
	*/

	void setJugadores(int Jugadores);

	/**
	@brief Inserta el parametro @plat en el atributo Plataformas del objeto Videojuego
	@autor Raúl Ruiz Idáñez
	@ver 1.0
	*/

	void setPlataformas(string Plataformas);

	//GETS	
	
	/**
	@brief Retorna el valor de Desarrollador del objeto Videojuego
	@autor Raúl Ruiz Idáñez
	@ver 1.0
	*/

	string getDesarrollador() const;

	/**
	@brief Retorna el valor Editor del objeto Videojuego
	@autor Raúl Ruiz Idáñez
	@ver 1.0
	*/

	string getEditor() const;

	/**
	@brief Retorna el valor Juegadores del objeto Videojuego
	@autor Raúl Ruiz Idáñez
	@ver 1.0
	*/

	int getJugadores() const;

	/**
	@brief Retorna el valor Plataformas del objeto Videojuego
	@autor Raúl Ruiz Idáñez
	@ver 1.0
	*/

	string getPlataformas() const;

	/**
	@brief sobrecarga el operador = 
	@pre el objeto const pasado por parametro debe tener los valores deseados y no estar vacio o con valores erroneos
	@pos el objeto Videojuego *v se asigna a el objeto de tipo Videojuego que llama a este metodo
	@autor Raúl Ruiz Idáñez
	@ver 1.0
	*/

	Videojuego* operator=(const Videojuego *v);

	/**
	@brief sobrecarga del operador de salida, imprimiendo este al completo solo con poner cout << <Videojuego>
	@pre objeto debe estar creado 
	@pos el objeto imprimira todos sus atributos
	@autor Raúl Ruiz Idáñez
	@ver 1.0
	*/

	friend ostream& operator<<(ostream &flujo, const Videojuego *v);

	/**
	@brief sobrecarga el operador de entrada
	@pre un objeto de tipo Videojuego debe estar creado y pasado como parametro
	@pos el objeto sobreescribira sus atributos
	@autor Raúl Ruiz Idáñez
	@ver 1.0
	*/		

	friend istream& operator>>(istream &flujo, Videojuego *v);
};

#endif