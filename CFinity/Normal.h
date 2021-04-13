#ifndef NORMAL_H
#define NORMAL_H

#include <iostream>
#include "Usuario.h"
#include "Media.h"
#include "Comentario.h"
using namespace std;

class Normal : public Usuario{
private:
	Media **VectorAsociados;
	int TotalAsociados;
	float mediaGeneralAsociados;

	/**
	@brief redimensiona el vector de medias asociados en +1 espacio para el vector, este metodo se utilizara cada vez que se inserte un media asociado
	@pre debe haber minimo 1 media en el vector para utilizar la redimension a mas
	@pos el vector quedara modificado y redimensionado
	@autor Raúl Ruiz Idáñez
	@ver 1.0
	*/

	void resizeVectorAsociadosMas();

	/**
	@brief redimensiona el vector de medias asociados en -1 espacio para el vector, este metodo se utilizara cada vez que se elimine un media asociado
	@pre debe haber minimo 1 media en el vector para utilizar la redimension a menos
	@pos el vector quedara modificado y redimensionado
	@autor Raúl Ruiz Idáñez
	@ver 1.0
	*/

	void resizeVectorAsociadosMenos();

public:

	/**
	@brief Construye un objeto de la clase Normal
	@autor Raúl Ruiz Idáñez
	@ver 1.0
	*/

	Normal();

	/**
	@brief Construye un objeto de la clase Normal por parametros
	@autor Raúl Ruiz Idáñez
	@ver 1.0
	*/

	Normal(string Login, string Nombre, string Apellidos, string FotoPerfil);

	/**
	@brief Destruye un objeto de la clase Normal
	@autor Raúl Ruiz Idáñez
	@ver 1.0
	*/

	~Normal();

	//SETS

	void calcularMediaNotaMediaAsociados();

	//GETS

	/**
	@brief retorna el valor de todos los medias asociados al usuario normal
	@autor Raúl Ruiz Idáñez
	@ver 1.0
	*/

	int getTotalAsociados() const;

	/**
	@brief retorna el valor de la media de los favoritos asociados
	@autor Raúl Ruiz Idáñez
	@ver 1.0
	*/

	float getMediaFavoritos() const;

	/**
	@brief retorna el valor de el id de la media de la posicion i del vector de medias asociados
	@pre la posicion i debe ser una posicion valida del vector de asociados
	@autor Raúl Ruiz Idáñez
	@ver 1.0
	*/

	int getIDMediasAsociados(int i);

	/**
	@brief recibe un media por parametros y lo inserta en el vector de asociados
	@pre este metodo se tiene que llamar desde el asociar media del cristofinity
	@pos el media quedara insertado en la posicion libre del vector de asociados y redimensionara el vector
	@autor Raúl Ruiz Idáñez
	@ver 1.0
	*/

	void insertarEnVectorAsociados(Media *m);

	/**
	@brief imprime el vector de favoritos
	@autor Raúl Ruiz Idáñez
	@ver 1.0
	*/

	void printMediaAsociados();

	/**
	@brief te imprime el titulo de tus medias asociados y te da a elegir si quieres imprimir uno en detalle
	@autor Raúl Ruiz Idáñez
	@ver 1.0
	*/

	void printMediaAsociadoDetalle();

	/**
	@brief elimina un media del vector de asociaciones
	@pre debe de haber medias en el vector de asociados
	@pos el media ya no formara parte del vector de asociaciones
	@autor Raúl Ruiz Idáñez
	@ver 1.0
	*/

	void eliminarMediaAsociado(int opcion);

	/**
	@brief 
	@pre 
	@pos 
	@autor Raúl Ruiz Idáñez
	@ver 1.0
	*/

	void eliminarMeGustas();

	/**
	@brief busca un media en los medias asociados, dentro, el usuario activo 
	@pre debe haber un media en el vector, minimo
	@pos retornara la posicion del media en el vector
	@autor Raúl Ruiz Idáñez
	@ver 1.0
	*/

	int buscarMediaID(int id);

	/**
	@brief te da la opcion de seleccionar un media asociado a tu vector para comentarlo
	@pre debe haber medias en favoritos
	@pos el comentario se insertara en el media
	@autor Raúl Ruiz Idáñez
	@ver 1.0
	*/

	void ComentarAsociado();

	/**
	@brief pasa por parametro la posicion del media al que le quiere escribir el comentario, lo crea y lo inserta en el media
	@pre debe haber medias en favoritos
	@pos el comentario se insertara en el media
	@autor Raúl Ruiz Idáñez
	@ver 1.0
	*/

	void escribirComentario(int posicion);

	/**
	@brief recibe un media por parametros y comprueba si esta en la lista de asociados, si esta devolvera un true, si no lo esta devolvera un false
	@pre debe haber medias en favoritos
	@pos devolvera true o false
	@autor Raúl Ruiz Idáñez
	@ver 1.0
	*/

	bool comprobarMedia(Media *m);

	/**
	@brief sobrecarga el operador = 
	@pre el objeto const pasado por parametro debe tener los valores deseados y no estar vacio o con valores erroneos
	@pos el objeto Normal *v se asigna a el objeto de tipo Normal que llama a este metodo
	@autor Raúl Ruiz Idáñez
	@ver 1.0
	*/

	Normal* operator=(const Normal *m);

	/**
	@brief sobrecarga el operador de entrada
	@pre un objeto de tipo Normal debe estar creado y pasado como parametro
	@pos el objeto sobreescribira sus atributos
	@autor Raúl Ruiz Idáñez
	@ver 1.0
	*/

	friend istream& operator>>(istream &flujo, Normal *m);

	/**
	@brief sobrecarga del operador de salida, imprimiendo este al completo solo con poner cout << <Normal>
	@pre objeto debe estar creado m
	@pos el objeto imprimira todos sus atributos
	@autor Raúl Ruiz Idáñez
	@ver 1.0
	*/

	friend ostream& operator<<(ostream &flujo, const Normal *m);
	
};

#endif