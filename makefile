Main:Main.o Matriz.o
	g++ Main.o Matriz.o -o Ejecutable
Main.o: Main.cpp
	g++ -c Main.cpp
Matriz.o: Matriz.h Matriz.cpp
	g++ -c Matriz.cpp