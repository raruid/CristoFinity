all: PracticasJunio

PracticasJunio: main.o pugixml.o CristoFinity.o Usuario.o Administrador.o Normal.o Media.o Pelicula.o Cancion.o Videojuego.o Serie.o Comentario.o Valoracion.o 
	g++ -o PracticasJunio main.o pugixml.o CristoFinity.o Usuario.o Administrador.o Normal.o Media.o Pelicula.o Cancion.o Videojuego.o Serie.o Comentario.o Valoracion.o -lmysqlcppconn

main.o: main.cpp
	g++ -c main.cpp

CristoFinity.o: CristoFinity.cpp
	g++ -c CristoFinity.cpp

pugixml.o: pugixml.cpp
	g++ -c pugixml.cpp

Usuario.o: Usuario.cpp
	g++ -c Usuario.cpp

Administrador.o: Administrador.cpp
	g++ -c Administrador.cpp

Normal.o: Normal.cpp
	g++ -c Normal.cpp

Media.o: Media.cpp
	g++ -c Media.cpp

Pelicula.o: Pelicula.cpp
	g++ -c Pelicula.cpp

Cancion.o: Cancion.cpp
	g++ -c Cancion.cpp

Videojuego.o: Videojuego.cpp
	g++ -c Videojuego.cpp

Serie.o: Serie.cpp
	g++ -c Serie.cpp

Comentario.o: Comentario.cpp
	g++ -c Comentario.cpp

Valoracion.o: Valoracion.cpp
	g++ -c Valoracion.cpp

clean:
	rm -f PracticasJunio *.o
