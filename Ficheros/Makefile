CC = g++
CFLAGS = -Wall -g

# Lista de archivos fuente
SRCS = main.cpp Alarma.cpp SensorCamara.cpp SHumedad.cpp SAire.cpp STemp.cpp SIluminacion.cpp CRgb.cpp CTermica.cpp Interfaz.cpp Usuario.cpp Administrador.cpp BDUsuarios.cpp BDSensores.cpp Login.cpp
OBJS = $(SRCS:.cpp=.o)

all: main

main: $(OBJS)
	$(CC) $(CFLAGS) -o main $(OBJS)

%.o: %.cpp
	$(CC) $(CFLAGS) -c $<

clean:
	rm -f *.o main
