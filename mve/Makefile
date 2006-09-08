CC = g++
OBJ = main.o cpu.o cart.o
CFLAGS = -g -c -Wall `sdl-config --cflags`

main: $(OBJ)
	g++ $(OBJ)  SDLMain.o -o main -Wall  `sdl-config --libs` # SDLMain.o !
main.o: main.cpp common.h
	g++ main.cpp $(CFLAGS)
cpu.o:	cpu.cpp
	g++ cpu.cpp $(CFLAGS)
cart.o:	cart.cpp
	g++ cart.cpp $(CFLAGS)