#define negro "\033[1;30m"
#define negrita   "\033[1m\033[30m"  
#define blanco "\033[1;39m"
#define blancofuerte   "\033[1m\033[37m"  
#define rojo "\033[1;31m"
#define rojofuerte     "\033[1m\033[31m" 
#define verde "\033[1;32m"
#define verdefuerte   "\033[1m\033[32m"
#define amarillo "\033[1;33m"
#define amarillofuerte  "\033[1m\033[33m"
#define azul "\033[1;34m"
#define azulfuerte     "\033[1m\033[34m" 
#define morado "\033[1;35m"
#define cian "\033[1;36m"
#define cianfuerte    "\033[1m\033[36m"
#define magenta "\033[35m"                   
#define magentafuerte "\033[1m\033[35m"          
   
#define rest "\033[0m"

#include <iostream>
#include <iomanip>
#include <string>
#include <stdlib.h>
#include "Valoracion.h"
#include "Comentario.h"
#include "Media.h"
#include "Pelicula.h"
#include "Cancion.h"

using namespace std;

int main(){

	Media *m = new Media;

	Comentario *c = new Comentario;

	c->setLogin("Josemita");
	c->setTexto("Bueno, ha sido una gran pelicula");

	m->insertarComentario(c);

	Valoracion *ca = new Valoracion;

	ca->setLogin("Josemita");
	ca->setPuntuacion(9);

	m->insertarValoracion(ca);

	Comentario *r = new Comentario;

	r->setLogin("Raruid");
	r->setTexto("Ni fu ni fá");

	m->insertarComentario(r);

	Valoracion *ra = new Valoracion;

	ra->setLogin("Raruid");
	ra->setPuntuacion(5);

	m->insertarValoracion(ra);

	Comentario *g = new Comentario;

	g->setLogin("Jaime");
	g->setTexto("Horrible vaya mierda de serie");

	m->insertarComentario(g);

	Valoracion *gu = new Valoracion;

	gu->setLogin("Jaime");
	gu->setPuntuacion(2);

	m->insertarValoracion(gu);

	Comentario *b = new Comentario;

	b->setLogin("Pablete");
	b->setTexto("La mejor juego del mundo ");

	m->insertarComentario(b);

	Valoracion *o = new Valoracion;

	o->setLogin("Pablete");
	o->setPuntuacion(10);

	m->insertarValoracion(o);	




	m->printComentarios();

	m->printValoraciones();

	m->borrarComentario(4);

	m->borrarValoracion(4);

	cout << rojofuerte << "BORRANDO COMENTARIOS... " << rest << endl;

	m->printComentarios();

	m->printValoraciones();

	Pelicula *p = new Pelicula;

	cin >> p;
	cout << p;

	Cancion *c = new Cancion;

	cin >> c;
	cout << c;
	
}