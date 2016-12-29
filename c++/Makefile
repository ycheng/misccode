all: stod setlocale

stod: stod.cpp
	gcc cstod.c -c
	g++ -c -std=c++11 stod.cpp -Wall
	g++ -g -std=c++11 cstod.o stod.o -o stod -Wall

setlocale: setlocale.cpp
	g++ -g setlocale.cpp -o setlocale -Wall

clean:
	rm stod setlocale *.o
