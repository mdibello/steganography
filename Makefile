CC=g++
CCFLAGS=-Wall -g
SFMLFLAGS=-lsfml-graphics

all: lsb_encode lsb_decode

lsb_encode: lsb_encode.o
	g++ -Wall -g -o lsb_encode lsb_encode.o $(SFMLFLAGS)

lsb_encode.o: lsb_encode.cpp
	g++ -Wall -g -c lsb_encode.cpp -o lsb_encode.o

lsb_decode: lsb_decode.o
	g++ -Wall -g -o lsb_decode lsb_decode.o $(SFMLFLAGS)

lsb_decode.o: lsb_decode.cpp
	g++ -Wall -g -c lsb_decode.cpp -o lsb_decode.o

clean:
	rm *o lsb_encode lsb_decode
