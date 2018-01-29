CC=g++
CCFLAGS=-Wall -g
SFMLFLAGS=-lsfml-system -lsfml-graphics -lsfml-window

all: lsb

lsb: lsb.o
	g++ -Wall -g -o lsb lsb.o $(SFMLFLAGS)

lsb.o: lsb.cpp
	g++ -Wall -g -c lsb.cpp -o lsb.o

clean:
	rm *o lsb
