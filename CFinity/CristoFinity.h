#ifndef CRISTOFINITY_H
#define CRISTOFINITY_H

#include <iostream>
#include <fstream>
#include "Media.h"
#include "Videojuego.h"
#include "Serie.h"
#include "Pelicula.h"
#include "Cancion.h"
#include "Usuario.h"
#include "Administrador.h"
#include "Normal.h"
#include "pugixml.hpp"

#include "mysql_connection.h"
#include <cppconn/driver.h>
#include <cppconn/resultset.h>
 
#include <cppconn/statement.h>
#include <cppconn/exception.h>
using namespace std;

class CristoFinity{
private:

	Media **Catalogo; 
	int TotalMediaCatalogo;
	Usuario **VectorUsuarios;
	int TotalUsuarios;
	Usuario *UsuarioActivo; 
	int ValoracionesSistema;
	int ComentariosSistema;

	/**
	@brief redimensiona el vector de medias en +1 espacio para el vector, este metodo se utilizara cada vez que se inserte una media
	@pre debe haber minimo 1 media en el vector para utilizar la redimension
	@pos el vector quedara modificado y redimensionado
	@autor Raúl Ruiz Idáñez
	@ver 1.0
	*/

	void resizeCatalogoMas();

	/**
	@brief redimensiona el vector de medias en -1 espacio para el vector, este metodo se utilizara cada vez que se elimine una media
	@pre debe haber minimo 1 media en el vector para utilizar la redimension a menos
	@pos el vector quedara modificado y redimensionado
	@autor Raúl Ruiz Idáñez
	@ver 1.0
	*/

	void resizeCatalogoMenos();

	/**
	@brief redimensiona el vector de usuarios en +1 espacio para el vector, este metodo se utilizara cada vez que se inserte una usuario
	@pre debe haber minimo 1 usuario en el vector para utilizar la redimension
	@pos el vector quedara modificado y redimensionado
	@autor Raúl Ruiz Idáñez
	@ver 1.0
	*/

	void resizeUsuariosMas();

	/**
	@brief redimensiona el vector de usuarios en -1 espacio para el vector, este metodo se utilizara cada vez que se elimine una usuario
	@pre debe haber minimo 1 usuario en el vector para utilizar la redimension a menos
	@pos el vector quedara modificado y redimensionado
	@autor Raúl Ruiz Idáñez
	@ver 1.0
	*/

	void resizeUsuariosMenos();

public:

	/**
	@brief Construye un objeto de la clase CristoFinity
	@autor Raúl Ruiz Idáñez
	@ver 1.0
	*/

	CristoFinity();

	/**
	@brief Construye un objeto de la clase CristoFinity
	@autor Raúl Ruiz Idáñez
	@ver 1.0
	*/

	~CristoFinity();

	//SETS

	/**
	@brief calcula el total de valoraciones de todos los medias del catalogo
	@autor Raúl Ruiz Idáñez
	@ver 1.0
	*/

	void setValoracionesSistema();

	/**
	@brief calcula el total de comentarios de todos los medias del catalogo
	@autor Raúl Ruiz Idáñez
	@ver 1.0
	*/

	void setComentariosSistema();

	/**
	@brief calcula la formula general de todos los medias del catalogo utilizando todas las valoraciones del sistema y todos los comentarios del sistema
	@autor Raúl Ruiz Idáñez
	@ver 1.0
	*/

	void calcularFormula();

	//GETS

	/**
	@brief retorna el total de medias del catalogo
	@autor Raúl Ruiz Idáñez
	@ver 1.0
	*/

	int getTotalMediaCatalogo();

	/**
	@brief retorna el total de usuarios
	@autor Raúl Ruiz Idáñez
	@ver 1.0
	*/

	int getTotalUsuarios();

	/**
	@brief te da a elegir un media del catalogo del que quieres visualizar su nota general y te retorna el valor de la nota general
	@autor Raúl Ruiz Idáñez
	@ver 1.0
	*/

	float consultarMediaGeneralDeMediaEnCatalogo();

	//MENÚS

	/**
	@brief menu que te da la opcion de logarte, registrarte o salir, si eliges logarte y no hay ningun usuario te redirigira a la pantalla de registro
	@pos segun seas usuario o admin, este menu hara un dynamic cast y te llevara al menu que te corresponda
	@autor Raúl Ruiz Idáñez
	@ver 1.0
	*/

	void MenuPrincipal();

	/**
	@brief menu
	@autor Raúl Ruiz Idáñez
	@ver 1.0
	*/

	void MenuAdministrador(bool &acaba);

	/**
	@brief retorna el total de usuarios
	@autor Raúl Ruiz Idáñez
	@ver 1.0
	*/

	void MenuUserNormal(bool &acaba);		

	//METODOS DE LA CLASE

	/**
	@brief te pide un login, si el login es correcto se asigna el usuario activo a ese login
	@pos tendras acceso a las opciones del admin o user segun lo que sea el usuario activo
	@autor Raúl Ruiz Idáñez
	@ver 1.0
	*/	

	void login();

	/**
	@brief pide al usuario que diga el tipo de media que quiere crear, el metodo llamara a los diferentes metodos de crear y los insertará
	@pos el elemento multimedia quedara insertado en el vector
	@autor Raúl Ruiz Idáñez
	@ver 1.0
	*/	

	void CreacionMedia();

	/**
	@brief crea un media de clase Serie y llama al insertar para meterlo en el catalogo
	@pre este metodo es llamado por creacionMedia
	@pos la serie quedara creada e insertada en el vector
	@autor Raúl Ruiz Idáñez
	@ver 1.0
	*/	

	void crearSerieInsertar();

	/**
	@brief crea un media de clase Pelicula y llama al insertar para meterlo en el catalogo
	@pre este metodo es llamado por creacionMedia
	@pos la Pelicula quedara creada e insertada en el vector
	@autor Raúl Ruiz Idáñez
	@ver 1.0
	*/

	void crearPeliculaInsertar();

	/**
	@brief crea un media de clase Videojuego y llama al insertar para meterlo en el catalogo
	@pre este metodo es llamado por creacionMedia
	@pos la Videojuego quedara creada e insertada en el vector
	@autor Raúl Ruiz Idáñez
	@ver 1.0
	*/

	void crearVideojuegoInsertar();

	/**
	@brief crea un media de clase Cancion y llama al insertar para meterlo en el catalogo
	@pre este metodo es llamado por creacionMedia
	@pos la Cancion quedara creada e insertada en el vector
	@autor Raúl Ruiz Idáñez
	@ver 1.0
	*/

	void crearCancionInsertar();

	/**
	@brief inserta un media en el vector del catalogo
	@pre se debe recibir un media por parametros, creado y con los atributos rellenados
	@pos el media quedara insertado en el vector de medias y el vector redimensionado
	@autor Raúl Ruiz Idáñez
	@ver 1.0
	*/	

	void insertarMediaCatalogo(Media *m);

	/**
	@brief reasigna los valores de los IDs de los medias, ordenandolos de 1 hasta n
	@pre debe haber un media en el vector de medias minimo
	@pos los IDs de media quedaran ordenados
	@autor Raúl Ruiz Idáñez
	@ver 1.0
	*/	

	void ordenarIDMedia();

	/**
	@brief metodo front que te pide el media que quieres modificar y llama al metodo que lo modifica
	@pre debe haber un media en el vector de medias minimo
	@pos los datos del media quedaran modificados
	@autor Raúl Ruiz Idáñez
	@ver 1.0
	*/	

	void modificarDatosDeMedia();

	/**
	@brief metodo que te pide que vuelvas a introducir los valores del media selecionado
	@pre el media que se pase debe estar en una posicion valida
	@pos los datos del media quedaran modificados
	@autor Raúl Ruiz Idáñez
	@ver 1.0
	*/	

	void modificarDatosMediaDelCatalogo(Media *m);

	/**
	@brief imprime el catalogo
	@pre debe haber un media en el vector de medias minimo
	@pos el catalogo quedara impreso
	@autor Raúl Ruiz Idáñez
	@ver 1.0
	*/	

	void printCatalogo();

	/**
	@brief imprime un media del catalogo en detalle
	@pre debe haber un media minimo insertado
	@pos el media quedara impreso
	@autor Raúl Ruiz Idáñez
	@ver 1.0
	*/	

	void printMediaDetalle();

	/**
	@brief comprueba si es el usuario normal el que llama al metodo y llama al metodo printMediaAsociadoDetalle del usuario normal
	@pre debe haber un media minimo insertado
	@pos el media quedara impreso
	@autor Raúl Ruiz Idáñez
	@ver 1.0
	*/	

	void printMediaAsociadoDetalle();

	/**
	@brief imprime los titulos de los medias del catalogo
	@pre debe haber un media en el vector de medias minimo
	@pos los titulos del catalogo quedaran impresos
	@autor Raúl Ruiz Idáñez
	@ver 1.0
	*/	

	void printTitulosCatalogo();

	/**
	@brief metodo front que pide los datos sobre que media se quiere eliminar
	@pre debe haber un media en el catalogo, minimo
	@pos el media quedara eliminado del catalogo y el vector redimensionado
	@autor Raúl Ruiz Idáñez
	@ver 1.0
	*/

	void eliminarMediaCatalogo();

	/**
	@brief elimina el media del vector de medias mediante el intercambio 
	@pre debe haber minimo 1 media en el catalogo para poder eliminarlo
	@pos el media quedara eliminado del vector
	@autor Raúl Ruiz Idáñez
	@ver 1.0
	*/

	void eliminarMedia(int posicion);

	//BUSQUEDAS

	/**
	@brief metodo front que pide al usuario buscar por el parametro que el desee
	@pre debe haber medias para buscar 
	@pos en el vector de busquedas del usuario quedaran insertadas las busquedas hechas en el catalogo
	@autor Raúl Ruiz Idáñez
	@ver 1.0
	*/

	void Busquedas();

	/**
	@brief busca un media en el catalogo, dentro, el usuario activo llama a un metodo para insertar esas busquedas en el vector de busquedas que tiene este ultimo
	@pre debe haber un media en el catalogo, minimo
	@pos retornara la posicion del media en el catalogo
	@autor Raúl Ruiz Idáñez
	@ver 1.0
	*/

	int buscarMediaID(int id);

	/**
	@brief busca un media en el catalogo por titulo, dentro, el usuario activo llama a un metodo para insertar esas busquedas en el vector de busquedas que tiene este ultimo
	@pre debe haber un media en el catalogo, minimo
	@pos retornara la posicion del media en el catalogo
	@autor Raúl Ruiz Idáñez
	@ver 1.0
	*/

	int buscarMediaTituloEinsertarEnVectorDelUsuario(string titulo);

	/**
	@brief busca un media en el catalogo por su nota media exacta, dentro, el usuario activo llama a un metodo para insertar esas busquedas en el vector de busquedas que tiene este ultimo
	@pre debe haber un media en el catalogo, minimo
	@pos retornara la posicion del media en el catalogo
	@autor Raúl Ruiz Idáñez
	@ver 1.0
	*/

	int buscarMediaNotaMediaEinsertarEnVectorDelUsuario(float notaMedia);

	/**
	@brief busca un media en el catalogo por el mayor de la nota que le introduzcas, dentro, el usuario activo llama a un metodo para insertar esas busquedas en el vector de busquedas que tiene este ultimo
	@pre debe haber un media en el catalogo, minimo
	@pos retornara la posicion del media en el catalogo
	@autor Raúl Ruiz Idáñez
	@ver 1.0
	*/

	int buscarMediaNotaMediaMayorEinsertarEnVectorDelUsuario(float notaMinima);

	/**
	@brief busca un media en el catalogo por el menor de la nota que le introduzcas, dentro, el usuario activo llama a un metodo para insertar esas busquedas en el vector de busquedas que tiene este ultimo
	@pre debe haber un media en el catalogo, minimo
	@pos retornara la posicion del media en el catalogo
	@autor Raúl Ruiz Idáñez
	@ver 1.0
	*/

	int buscarMediaNotaMediaMenorEinsertarEnVectorDelUsuario(float notaMaxima);

	/**
	@brief metodo front que pide al administrador buscar un usuario por los parametros diponibles
	@pre debe haber usuarios normales para buscar 
	@pos en el vector de busquedas del administrador quedaran guardadas las busquedas
	@autor Raúl Ruiz Idáñez
	@ver 1.0
	*/

	void BusquedasUsuarios();

	/**
	@brief busca un usuario normal por el nombre de usuario, si lo encuentra, llama a un metodo propio de administrador para insertarlo en el vector de busquedas de usuario
	@pre para que el metodo haga su funcion debe existir un usuario con el nombre pasado por parametros
	@pos el o los usuarios que tengan ese nombre quedaran insertados en el vector del administrador
	@autor Raúl Ruiz Idáñez
	@ver 1.0
	*/

	void buscarUsuarioPorNombreEinsertarEnVectorDeAdministrador(string nombre);

	/**
	@brief busca un usuario normal por el apellido de usuario, si lo encuentra, llama a un metodo propio de administrador para insertarlo en el vector de busquedas de usuario
	@pre para que el metodo haga su funcion debe existir un usuario con el apellido pasado por parametros
	@pos el usuario que tenga ese apellido o apellidos quedara insertado en el vector del administrador
	@autor Raúl Ruiz Idáñez
	@ver 1.0
	*/

	void buscarUsuarioPorApellidoEinsertarEnVectorDeAdministrador(string apellido);

	/**
	@brief llama a un metodo propio de administrador para imprimir el vector de usuarios
	@pre para que el metodo haga su funcion debe existir un usuario insertado en el vector de usuarios
	@pos el vector de usuarios quedara impreso
	@autor Raúl Ruiz Idáñez
	@ver 1.0
	*/

	void printVectorAdministrador();

	/**
	@brief llama mediante el usuario activo a el print del usuario
	@autor Raúl Ruiz Idáñez
	@ver 1.0
	*/

	void printVectorBusquedas();

	/**
	@brief metodo que llama a otro metodo del usuario, mediante el usuarioactivo, el cual vacia el vector de busquedas de este ultimo
	@pre para eliminar el vector de busquedas es recomendable que este contenga medias
	@pos el vector de busquedas quedara reiniciado
	@autor Raúl Ruiz Idáñez
	@ver 1.0
	*/

	void vaciarVectorBusquedas();

	/**
	@brief metodo que llama a otro metodo del administrador, mediante el usuarioactivo, el cual vacia el vector de busquedas de usuarios 
	@pre para eliminar el vector de busquedas es recomendable que este contenga usuarios
	@pos el vector de busquedas de usuarios quedara reiniciado
	@autor Raúl Ruiz Idáñez
	@ver 1.0
	*/

	void vaciarVectorBusquedasDeUsuario();

	/**
	@brief metodo front que pide al usuario elegir entre los distintos rankings y segun el que introduzcas llama al metodo pertinente
	@pre 
	@pos el vector de busquedas del usuario quedara actualizado
	@autor Raúl Ruiz Idáñez
	@ver 1.0
	*/

	void Rankings();

	/**
	@brief metodo front que te muestra 3 opciones, top 3, media hated y media polemic y tu eliges la que quieres guardar en tu vector de busquedas
	@autor Raúl Ruiz Idáñez
	@ver 1.0
	*/

	void top3NotaGeneral();

	/**
	@brief calcula los 3 mejores medias en cuanto a nota general en catalogo y los guarda en orden en el vector de busquedas del usuario generico
	@pre debe haber 3 medias insertados minimo
	@pos guardara en el vector de busquedas del usuario, los 3 mejores medias del catalogo en cuanto a nota general
	@autor Raúl Ruiz Idáñez
	@ver 1.0
	*/

	void calcularTop3eInsertarEnVectorBusquedas();

	/**
	@brief el media con peor valoracion en catalogo y lo guarda en el vector de busquedas del usuario
	@pre debe haber 1 media minimo en el vector
	@pos guardara en el vector de busquedas del usuario el media hated
	@autor Raúl Ruiz Idáñez
	@ver 1.0
	*/

	void calcularMediaHatedeInsertarEnVectorBusquedas();

	/**
	@brief 
	@pre 
	@pos 
	@autor Raúl Ruiz Idáñez
	@ver 1.0
	*/

	void calcularMediaPolemiceInsertarEnVectorBusquedas();

	/**
	@brief busca un media en el catalogo por el menor de la nota que le introduzcas, dentro, el usuario activo llama a un metodo para insertar esas busquedas en el vector de busquedas que tiene este ultimo
	@pre debe haber un media en el catalogo, minimo
	@pos retornara la posicion del media en el catalogo
	@autor Raúl Ruiz Idáñez
	@ver 1.0
	*/

	void top3TipoMedia();

	//TOP 3 SERIES

	/**
	@brief calcula las 3 mejores series en cuanto a nota general en catalogo y los guarda en orden en el vector de busquedas del usuario generico
	@pre debe haber 3 series insertadas minimo
	@pos guardara en el vector de busquedas del usuario, las 3 mejores series del catalogo en cuanto a nota general
	@autor Raúl Ruiz Idáñez
	@ver 1.0
	*/

	void calcularTop3SerieseInsertarEnVectorBusquedas();

	/**
	@brief calcula las 3 mejores peliculas en cuanto a nota general en catalogo y los guarda en orden en el vector de busquedas del usuario generico
	@pre debe haber 3 peliculas insertadas minimo
	@pos guardara en el vector de busquedas del usuario, las 3 mejores peliculas del catalogo en cuanto a nota general
	@autor Raúl Ruiz Idáñez
	@ver 1.0
	*/

	void calcularTop3PeliculaseInsertarEnVectorBusquedas();

	/**
	@brief calcula los 3 mejores videojuegos en cuanto a nota general en catalogo y los guarda en orden en el vector de busquedas del usuario generico
	@pre debe haber 3 videojuegos insertados minimo
	@pos guardara en el vector de busquedas del usuario, los 3 mejores videojuegos del catalogo en cuanto a nota general
	@autor Raúl Ruiz Idáñez
	@ver 1.0
	*/

	void calcularTop3VideojuegoseInsertarEnVectorBusquedas();

	/**
	@brief calcula las 3 mejores canciones en cuanto a nota general en catalogo y los guarda en orden en el vector de busquedas del usuario generico
	@pre debe haber 3 canciones insertados minimo
	@pos guardara en el vector de busquedas del usuario, las 3 mejores canciones del catalogo en cuanto a nota general
	@autor Raúl Ruiz Idáñez
	@ver 1.0
	*/

	void calcularTop3CancioneseInsertarEnVectorBusquedas();

	/**
	@brief busca un media en el catalogo por el menor de la nota que le introduzcas, dentro, el usuario activo llama a un metodo para insertar esas busquedas en el vector de busquedas que tiene este ultimo
	@pre debe haber un media en el catalogo, minimo
	@pos retornara la posicion del media en el catalogo
	@autor Raúl Ruiz Idáñez
	@ver 1.0
	*/	

	void rankingUsuarios();	

	void calcularFreakZizouEInsertar();
	void calcularSalvameDeluxeEInsertar();
	void calcularMessiEInsertar();

	/**
	@brief metodo front que pide al usuario que elija que tipo de usuario quiere crear, llama al metodo crear pertinente y luego a los insertar
	@pos el usuario quedara insertado en el vector de usuarios
	@autor Raúl Ruiz Idáñez
	@ver 1.0
	*/	

	void usuarioNuevo();

	/**
	@brief metodo que crea un usuario de tipo administrador y dentro de este, llama al insertar que lo inserta en el vector de usuarios de cristofinity
	@pre este metodo sera llamado por usuarioNuevo()
	@pos el usuario quedara creado y listo para insertarse
	@autor Raúl Ruiz Idáñez
	@ver 1.0
	*/	

	void crearAdministradorInsertar();

	/**
	@brief metodo que crea un usuario de tipo normal y dentro de este, llama al insertar que lo inserta en el vector de usuarios de cristofinity
	@pre este metodo sera llamado por usuarioNuevo()
	@pos el usuario quedara creado y listo para insertarse
	@autor Raúl Ruiz Idáñez
	@ver 1.0
	*/	

	void crearNormalInsertar();

	/**
	@brief recibe un usuario por parametros y lo inserta en el vector de usuarios de cristofinity
	@pre el usuario debe estar definido y sus variables correctas
	@pos el usuario quedara insertado en el vector de usuarios y este ultimo quedara redimensionado
	@autor Raúl Ruiz Idáñez
	@ver 1.0
	*/	

	void insertarUsuario(Usuario *u);

	/**
	@brief imprime los usuarios del vector de usuarios
	@autor Raúl Ruiz Idáñez
	@ver 1.0
	*/	

	void printUsuarios();

	/**
	@brief imprime los logins de los usuarios del vector de usuarios
	@autor Raúl Ruiz Idáñez
	@ver 1.0
	*/	

	void printLoginUsuarios();

	/**
	@brief modifica los datos del usuario activo
	@autor Raúl Ruiz Idáñez
	@ver 1.0
	*/

	void modificarDatosUsuarioActivo();

	/**
	@brief modifica los datos de cualquier usuario normal sistema que haya disponible, si no hay usuarios normales, solo podras modificar los tuyos o salir
	@autor Raúl Ruiz Idáñez
	@ver 1.0
	*/

	void modificarDatosCualquierUsuario();

	/**
	@brief metodo front que te da a elegir el usuario que quieres borrar, y este llama a los metodos de busqueda de login y de eliminacion, pasandole la posicion donde ha encontrado 
	@pre para que el metodo funcione debe haber usuarios en el sistema
	@pos el usuario quedara eliminado y el vector redimensionado 
	@autor Raúl Ruiz Idáñez
	@ver 1.0
	*/	

	void eliminarUsuariosVectorUsuarios();

	/**
	@brief recibe un int que se correspondera con la posicion del vector del usuario que se quiere borrar
	@pre el vector en esa posicion debe de tener un usuario insertado 
	@pos el usuario se eliminara del vector de usuarios y redimensionara el vector
	@autor Raúl Ruiz Idáñez
	@ver 1.0
	*/

	void eliminarUsuario(int posicion);	

	/**
	@brief busca un el login de cada usuario del vector y comprueba si coincide o no con el pasado por parametros
	@pos si es correcto, devolvera la posicion correcta del vector donde se encuentra ese login, sino devolvera -1
	@autor Raúl Ruiz Idáñez
	@ver 1.0
	*/

	int buscarLoginUsuario(string login);

	/**
	@brief metodo front que comprueba si eres normal o administrador, si eres normal, te da a elegir el media que quieres asociarte y llama al insertar del usuario activo para insertarlo en el vector de favoritos
	@pre el usuario que llama al metodo debe ser normal, si es administrador no te dejara realizar la accion
	@pos el media quedara asociado al usuario normal
	@autor Raúl Ruiz Idáñez
	@ver 1.0
	*/

	void asociarMediaUsuario();

	/**
	@brief llama al metodo imprimir vector de asociados de el usuario normal
	@autor Raúl Ruiz Idáñez
	@ver 1.0
	*/

	void printAsociadosUsuario();

	/**
	@brief metodo front que imprime tu vector de asociados y te dice cual de ellos quieres desasociar
	@pre el usuario que llama al metodo debe ser normal
	@pos el media quedara desasociado al usuario normal
	@autor Raúl Ruiz Idáñez
	@ver 1.0
	*/

	void desAsociarMediaUsuario();

	/**
	@brief metodo front que te pide que introduzcas un media del que quieres escribir el comentario llama al metodo escribirComentario
	@pre debe de haber medias para escribirles un comentario
	@pos el comentario quedara insertado en el media
	@autor Raúl Ruiz Idáñez
	@ver 1.0
	*/

	void Comentar();

	/**
	@brief metodo front que te pide que primero comprueba si eres administrador (porque un usuario normal ya valora cuando se asocia el media) y pide que introduzcas un media del que quieres escribir la valoracion llama al metodo escribirValoracion
	@pre debe de haber medias para escribirles una valoracion
	@pos la valoracion quedara insertada en el media
	@autor Raúl Ruiz Idáñez
	@ver 1.0
	*/

	void Valorar();

	/**
	@brief metodo que te hace escribir un comentario para el media de la posicion pasada por referencia, y llama al insertar comentario del media
	@pre se debe pasar la posicion del vector de un media por parametros
	@pos el comentario quedara insertado en el media pertinente
	@autor Raúl Ruiz Idáñez
	@ver 1.0
	*/

	void escribirComentario(int posicion);

	/**
	@brief metodo que te hace escribir una valoracion para el media de la posicion pasada por referencia, y llama al insertar valoracion del media
	@pre se debe pasar la posicion del vector de un media por parametros
	@pos la valoracion quedara insertados en el media pertinente
	@autor Raúl Ruiz Idáñez
	@ver 1.0
	*/

	void escribirValoracion(int posicion);

	/**
	@brief metodo que filtra si eres normal y llama a traves del usuario activo a el metodo comentar de el usuario
	@autor Raúl Ruiz Idáñez
	@ver 1.0
	*/

	void ComentarAsociado();

	/**
	@brief metodo front que a traves del usuario activo te muestra tus medias asociados, al seleccionar el media, te muestra tus comentarios en ese media y te da a elegir cual quieres eliminar
	@pre debe haber medias asociados y comentarios del usuario activo en ese media
	@pos el comentario del usuario activo seleccionado del media asociado seleccionado quedara eliminado
	@autor Raúl Ruiz Idáñez
	@ver 1.0
	*/

	void eliminarComentarioDeListaAsociados();

	/**
	@brief metodo front que a traves del usuario activo te muestra tus medias asociados y te dice de cual de ellos quieres modificar la valoracion
	@pre debe haber medias asociados
	@pos la valoracion del media asociado quedara modificada
	@autor Raúl Ruiz Idáñez
	@ver 1.0
	*/

	void modificarValoracionUserNormal();

	/**
	@brief metodo front que te muestra todos los medias y todos los comentarios de este al seleccionarlo y te da a elegir cual quieres eliminar
	@pre debe haber medias en el catalogo
	@pos el comentario elegido se eliminara del sistema
	@autor Raúl Ruiz Idáñez
	@ver 1.0
	*/

	void eliminarComentarioAdmin();

	/**
	@brief metodo front que te muestra todos los medias y te dice que valoracion de que media quieres modificar
	@pre debe haber medias en el catalogo
	@pos la valoracion elegida quedara modificada en el sistema
	@autor Raúl Ruiz Idáñez
	@ver 1.0
	*/

	void modificarValoracionAdmin();

	/**
	@brief importa el xml de cristofinity
	@autor Raúl Ruiz Idáñez
	@ver 1.0
	*/

	void importarXML();

	/**
	@brief exporta los datos del programa en un fichero xml
	@autor Raúl Ruiz Idáñez
	@ver 1.0
	*/

	void exportarXML();

	void calcularMediaUsuarioNormal();

	/**
	@brief calcula el total de comentarios y valoraciones del sistema e inmediatamente despues la formula general de cada media
	@autor Raúl Ruiz Idáñez
	@ver 1.0
	*/

	void calcularFormulas();

	int contarComentariosPorLogin(string login);

	void conexionBaseDatos();

	void insertarEnBaseDeDatos(string sentencia);

	void imprimirBaseDeDatos();

	void borrarTuplaDeUsuario(string sentencia);

	void borrarBaseDatos();


	//FILTRO VISUAL

	void correcto();

	void pulsaparacontinuar();
};

#endif