#ifndef SERIE_H
#define SERIE_H

#include <iostream>
#include "Pelicula.h"

using namespace std;

class Serie: public Pelicula{
private:
	int Temporadas;
	int Capitulos;
	bool Acabada;
public:

	/**
	@brief Crea un objeto de la clase Serie
	@autor Raúl Ruiz Idáñez
	@ver 1.0
	*/

	Serie();

	/**
	@brief Crea un objeto de la clase Serie mediante parametros
	@autor Raúl Ruiz Idáñez
	@ver 1.0
	*/

	Serie(int IDMedia, string Titulo, string Genero, int DuracionEnSegundos, string Fecha_Publicacion, int Pegi, string Descripcion, string Director, string Reparto, string Guion, string Productor, int Temporadas, int Capitulos, bool Acabada);

	/**
	@brief Destruye un objeto de la clase Serie
	@autor Raúl Ruiz Idáñez
	@ver 1.0
	*/

	~Serie();

	//SETS

	/**
	@brief Inserta el nº de temporadas en el atributo Temporadas de la clase Serie
	@autor Raúl Ruiz Idáñez
	@ver 1.0
	*/

	void setTemporadas(int Temporadas);

	/**
	@brief Inserta el parametro @cap en el atributo Capitulos del objeto Serie
	@autor Raúl Ruiz Idáñez
	@ver 1.0
	*/

	void setCapitulos(int Capitulos);

	/**
	@brief Inserta el parametro @acab en el atributo Acabada del objeto Serie
	@autor Raúl Ruiz Idáñez
	@ver 1.0
	*/

	void setAcabada(bool Acabada);
	
	//GETS

	/**
	@brief Retorna el valor de Temporadas del objeto Serie
	@autor Raúl Ruiz Idáñez
	@ver 1.0
	*/

	int getTemporadas() const;

	/**
	@brief Retorna el valor Capitulos del objeto Serie
	@autor Raúl Ruiz Idáñez
	@ver 1.0
	*/

	int getCapitulos() const;

	/**
	@brief Retorna el valor Acabada del objeto Serie
	@autor Raúl Ruiz Idáñez
	@ver 1.0
	*/

	bool getAcabada() const;

	//METODOS DE LA CLASE

	/**
	@brief sobrecarga el operador = 
	@pre el objeto const pasado por parametro debe tener los valores deseados y no estar vacio o con valores erroneos
	@pos el objeto Serie *v se asigna a el objeto de tipo Serie que llama a este metodo
	@autor Raúl Ruiz Idáñez
	@ver 1.0
	*/

	Serie* operator=(const Serie *s);

	/**
	@brief sobrecarga del operador de salida, imprimiendo este al completo solo con poner cout << <Serie>
	@pre objeto debe estar creado 
	@pos el objeto imprimira todos sus atributos
	@autor Raúl Ruiz Idáñez
	@ver 1.0
	*/

	friend ostream& operator<<(ostream &flujo, const Serie *s);

	/**
	@brief sobrecarga el operador de entrada
	@pre un objeto de tipo Serie debe estar creado y pasado como parametro
	@pos el objeto sobreescribira sus atributos
	@autor Raúl Ruiz Idáñez
	@ver 1.0
	*/		

	friend istream& operator>>(istream &flujo, Serie *s);

};

#endif