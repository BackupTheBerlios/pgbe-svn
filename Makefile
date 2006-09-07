CC = g++
OBJ = main.o cpu.o
CFLAGS = -c -Wall `sdl-config --cflags`

main: $(OBJ)
	g++ $(OBJ)  SDLMain.o -o main -Wall  `sdl-config --libs` # SDLMain.o !
main.o: main.cpp
	g++ main.cpp $(CFLAGS)
cpu.o:	cpu.cpp
	g++ cpu.cpp $(CFLAGS)