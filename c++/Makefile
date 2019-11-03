BINS=stod setlocale sizeof

all: $(BINS)

stod: stod.cpp
	gcc cstod.c -c
	g++ -c -std=c++11 stod.cpp -Wall
	g++ -g -std=c++11 cstod.o stod.o -o stod -Wall

setlocale: setlocale.cpp
	g++ -g setlocale.cpp -o setlocale -Wall

sizeof: sizeof.cpp
	g++ sizeof.cpp -o sizeof -Wall

clean:
	rm *.o $(BINS)
