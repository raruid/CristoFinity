#ifndef MEDIA_H
#define MEDIA_H

#include <iostream>
#include "Comentario.h"
#include "Valoracion.h"
using namespace std;

class Media {
protected:
	int IDMedia;
	string Titulo;
	string Genero;
	int DuracionEnSegundos;
	string Fecha_Publicacion;
	int Pegi;
	string Descripcion;
	float NotaMedia;
	float NotaGeneralCatalogo;
	int MeGusta;
	Comentario **VectorComentarios;
	int TotalComentarios;
	Valoracion **VectorValoraciones;
	int TotalValoraciones;

	/**
	@brief redimensiona el vector de comentarios en +1 espacio para el vector, este metodo se utilizara cada vez que se inserte un comentario
	@pre debe haber minimo 1 comentario en el vector para utilizar la redimension
	@pos el vector quedara modificado y redimensionado
	@autor Raúl Ruiz Idáñez
	@ver 1.0
	*/

	void resizeComentariosMas();

	/**
	@brief redimensiona el vector de comentarios en -1 espacio para el vector, este metodo se utilizara cada vez que se elimine un comentario
	@pre debe haber minimo 1 comentario en el vector para utilizar la redimension a menos
	@pos el vector quedara modificado y redimensionado
	@autor Raúl Ruiz Idáñez
	@ver 1.0
	*/

	void resizeComentariosMenos();

	/**
	@brief redimensiona el vector de valoraciones en +1 espacio para el vector, este metodo se utilizara cada vez que se inserte una valoracion
	@pre debe haber minimo 1 valoracion en el vector para utilizar la redimension
	@pos el vector quedara modificado y redimensionado
	@autor Raúl Ruiz Idáñez
	@ver 1.0
	*/

	void resizeValoracionesMas();

	/**
	@brief redimensiona el vector de valoraciones en -1 espacio para el vector, este metodo se utilizara cada vez que se elimine una valoracion
	@pre debe haber minimo 1 valoracion en el vector para utilizar la redimension a menos
	@pos el vector quedara modificado y redimensionado
	@autor Raúl Ruiz Idáñez
	@ver 1.0
	*/

	void resizeValoracionesMenos();

public:

	//Constructor y destructor

	/**
	@brief Construye un objeto de la clase Media
	@autor Raúl Ruiz Idáñez
	@ver 1.0
	*/

	Media();

	/**
	@brief Construye un objeto de la clase Media 
	@autor Raúl Ruiz Idáñez
	@ver 1.0
	*/

	Media(int IDMedia, string Titulo, string Genero, int DuracionEnSegundos, string Fecha_Publicacion, int Pegi, string Descripcion);

	/**
	@brief inserta un identificador para el media
	@autor Raúl Ruiz Idáñez
	@ver 1.0
	*/	

	virtual ~Media();

	//SETS

	/**
	@brief inserta un identificador para el media
	@autor Raúl Ruiz Idáñez
	@ver 1.0
	*/

	void setIDMedia(int ID);

	/**
	@brief inserta un titulo para el objeto media
	@autor Raúl Ruiz Idáñez
	@ver 1.0
	*/

	void setTitulo(string tit);

	/**
	@brief inserta un genero al objeto media
	@autor Raúl Ruiz Idáñez
	@ver 1.0
	*/

	void setGenero(string gen);

	/**
	@brief inserta la duracion en segundos del objeto media
	@autor Raúl Ruiz Idáñez
	@ver 1.0
	*/

	void setDuracionSeg(int duracion);

	/**
	@brief inserta la fecha de salida del objeto media
	@autor Raúl Ruiz Idáñez
	@ver 1.0
	*/

	void setFecha_Publicacion(string fecha);

	/**
	@brief inserta la edad recomendada(pegi) del objeto media
	@autor Raúl Ruiz Idáñez
	@ver 1.0
	*/

	void setPegi(int peg);

	/**
	@brief inserta una descripcion sobre el objeto media
	@autor Raúl Ruiz Idáñez
	@ver 1.0
	*/

	void setDescripcion(string descrip);

	/**
	@brief recorre el vector de valoraciones y calcula la media de las valoraciones
	@pre el media debe tener una valoracion para que la formula se pueda calcular
	@pos la nota del media quedara actualizada
	@autor Raúl Ruiz Idáñez
	@ver 1.0
	*/

	void calcularNotaMedia();

	/**
	@brief calcula una formula general con la estructura: 0,5 * notamedia + 0,3 * me gusta/todaslasvaloraciones + 0,2 * comentarios del media/todos los comentarios
	@pre el media debe tener una valoracion para que la formula se pueda calcular
	@pos la nota del media quedara actualizada
	@autor Raúl Ruiz Idáñez
	@ver 1.0
	*/

	void calcularFormulaGeneral(int ValoracionesSistema, int ComentariosSistema);

	/**
	@brief suma 1 al atributo me gusta
	@autor Raúl Ruiz Idáñez
	@ver 1.0
	*/

	void setMeGustaMas();

	/**
	@brief resta 1 al atributo me gusta
	@autor Raúl Ruiz Idáñez
	@ver 1.0
	*/

	void setMeGustaMenos();

	//GETS

	/**
	@brief devuelve el identificador del media
	@autor Raúl Ruiz Idáñez
	@ver 1.0
	*/

	int getIDMedia() const;

	/**
	@brief devuelve el titulo del media
	@autor Raúl Ruiz Idáñez
	@ver 1.0
	*/

	string getTitulo() const;

	/**
	@brief devuelve el genero del media
	@autor Raúl Ruiz Idáñez
	@ver 1.0
	*/

	string getGenero() const;

	/**
	@brief devuelve la duracion en segundos
	@autor Raúl Ruiz Idáñez
	@ver 1.0
	*/

	int getDuracionSegundos() const;

	/**
	@brief devuelve la fecha de publicacion del media
	@autor Raúl Ruiz Idáñez
	@ver 1.0
	*/

	string getFecha_Publicacion() const;

	/**
	@brief devuelve el pegi del media
	@autor Raúl Ruiz Idáñez
	@ver 1.0
	*/

	int getPegi() const;

	/**
	@brief retorna el valor de la nota media
	@autor Raúl Ruiz Idáñez
	@ver 1.0
	*/

	float getNotaMedia() const;

	/**
	@brief retorna el valor de la nota general en el catalogo
	@autor Raúl Ruiz Idáñez
	@ver 1.0
	*/

	float getNotaGeneral() const;

	/**
	@brief retorna el valor de los me gusta
	@autor Raúl Ruiz Idáñez
	@ver 1.0
	*/

	int getMeGusta() const;

	/**
	@brief devuelve la descripcion del media
	@autor Raúl Ruiz Idáñez
	@ver 1.0
	*/

	string getDescripcion() const;

	/**
	@brief retorna el valor del atributo TotalComentarios
	@autor Raúl Ruiz Idáñez
	@ver 1.0
	*/

	int getTotalComentarios() const;

	/**
	@brief retorna el valor del atributo TotalValoraciones
	@autor Raúl Ruiz Idáñez
	@ver 1.0
	*/

	int getTotalValoraciones() const;

	//METODOS DE LA CLASE 	

	/**
	@brief rinserta un comentario en el vector de comentarios
	@pre debe haber espacio disponible en el vector 
	@pos el comentario quedara insertado
	@autor Raúl Ruiz Idáñez
	@ver 1.0
	*/	

	void insertarComentario(Comentario *c);

	/**
	@brief rinserta una valoracion en el vector de valoraciones
	@pre debe haber espacio disponible en el vector 
	@pos la valoracion quedara insertada
	@autor Raúl Ruiz Idáñez
	@ver 1.0
	*/	

	void insertarValoracion(Valoracion *v);

	/**
	@brief ordena los ID de los comentarios
	@pre debe haber al menos 1 comentario en el vector para poder ordenar
	@pos los id de los comentarios quedaran ordenados
	@autor Raúl Ruiz Idáñez
	@ver 1.0
	*/

	void ordenarIDComentario();

	/**
	@brief busca un comentario en los comentarios asociados al media que llama desde cristofinity
	@pre debe haber un comentario en el vector, minimo
	@pos retornara la posicion del comentario en el vector
	@autor Raúl Ruiz Idáñez
	@ver 1.0
	*/

	int buscarComentarioID(int opcion);

	/**
	@brief reordena y elimina comentarios en memoria
	@pre debe haber al menos q comentario, insertado
	@pos el comentario y la valoracion quedaran borrados de sus vectores y estos redimensionados
	@autor Raúl Ruiz Idáñez
	@ver 1.0
	*/

	void borrarComentario(int id);

	void eliminarComentariosDeUsuario(string login);

	/**
	@brief reordena y elimina los comentarios y la valoracion en memoria
	@pre debe haber al menos q comentario con su valoracion, insertado
	@pos el comentario y la valoracion quedaran borrados de sus vectores y estos redimensionados
	@autor Raúl Ruiz Idáñez
	@ver 1.0
	*/

	void borrarValoracion(int posicion);

	void eliminarValoracionesDeUsuario(string login);

	/**
	@brief imprime los comentarios 
	@pre debe haber al menos un comentario en el vector, para su impresion
	@pos el comentario quedara impreso
	@autor Raúl Ruiz Idáñez
	@ver 1.0
	*/	

	void printComentarios();

	/**
	@brief retorna el id del comentario de la posicion i del vector de comentarios
	@pre la posicion i debe ser valida en el vector de comentarios
	@autor Raúl Ruiz Idáñez
	@ver 1.0
	*/	

	int getIDComentario(int i);

	/**
	@brief retorna el login del comentario de la posicion i del vector de comentarios
	@pre la posicion i debe ser valida en el vector de comentarios
	@autor Raúl Ruiz Idáñez
	@ver 1.0
	*/	

	string getLoginComentario(int i);

	/**
	@brief retorna el texto del comentario de la posicion i del vector de comentarios
	@pre la posicion i debe ser valida en el vector de comentarios
	@autor Raúl Ruiz Idáñez
	@ver 1.0
	*/

	string getTextoComentario(int i);

	/**
	@brief retorna el login de la valoracion de la posicion i del vector de valoraciones
	@pre la posicion i debe ser valida en el vector de valoraciones
	@autor Raúl Ruiz Idáñez
	@ver 1.0
	*/

	string getLoginValoracion(int i);

	/**
	@brief retorna la puntuacion de la valoracion de la posicion i del vector de valoraciones
	@pre la posicion i debe ser valida en el vector de valoraciones
	@autor Raúl Ruiz Idáñez
	@ver 1.0
	*/

	int getPuntuacionValoracion(int i);

	/**
	@brief imprime los comentarios  que estan asociados al login pasado por referencia
	@pre para que se impriman, el login debe tener comentarios en el media seleccionado
	@pos los comentarios quedaran impresos
	@autor Raúl Ruiz Idáñez
	@ver 1.0
	*/	

	void printComentariosPorLogin(string login);

	/**
	@brief actualiza el login de los comentarios y las valoraciones, este metodo back se utilizara cuando haya una modificacion de datos
	@pre debe haber en este media, comentarios asociados a antiguo login, sino, no hara nada
	@pos el login de los comentarios y las valoraciones quedaran actualizados
	@autor Raúl Ruiz Idáñez
	@ver 1.0
	*/	

	void cambiarLoginComentariosValoracion(string antiguologin, string nuevologin);

	/**
	@brief imprime las valoraciones 
	@pre debe haber al menos una valoracion en el vector, para su impresion
	@pos la valoracion quedara impreso
	@autor Raúl Ruiz Idáñez
	@ver 1.0
	*/	

	void printValoraciones();

	/**
	@brief bool que comprueba si el login ha escrito ya una valoracion
	@pos devolvera true o false segun se cumpla o no la condicion
	@autor Raúl Ruiz Idáñez
	@ver 1.0
	*/	

	bool comprobarValoracion(string login);

	/**
	@brief busca una valoracion que este asociada con el login pasado por referencia
	@ver 1.0
	*/	

	void modificarValoracionPorLogin(string login);

	/**
	@brief imprime las valoraciones  que estan asociadas al login pasado por referencia
	@pre para que se impriman, el login debe tener valoraciones en el media seleccionado
	@pos las valoraciones quedaran impresos
	@autor Raúl Ruiz Idáñez
	@ver 1.0
	*/	

	void printValoracionPorLogin(string login);

	int contarComentariosPorLogin(string login);

	/**
	@brief sobrecarga el operador = 
	@pre el objeto const pasado por parametro debe tener los valores deseados y no estar vacio o con valores erroneos
	@pos el objeto Media *v se asigna a el objeto de tipo Media que llama a este metodo
	@autor Raúl Ruiz Idáñez
	@ver 1.0
	*/

	Media* operator=(const Media *m);

	/**
	@brief sobrecarga el operador de entrada
	@pre un objeto de tipo Media debe estar creado y pasado como parametro
	@pos el objeto sobreescribira sus atributos
	@autor Raúl Ruiz Idáñez
	@ver 1.0
	*/

	friend istream& operator>>(istream &flujo, Media *m);

	/**
	@brief sobrecarga del operador de salida, imprimiendo este al completo solo con poner cout << <Media>
	@pre objeto debe estar creado m
	@pos el objeto imprimira todos sus atributos
	@autor Raúl Ruiz Idáñez
	@ver 1.0
	*/

	friend ostream& operator<<(ostream &flujo, const Media *m);

};

#endif