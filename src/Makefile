CC=g++ -Wall -g
SFMLFLAGS=-lsfml-graphics

all: lsb_encode lsb_decode pixel_compare

lsb_encode: lsb_encode.o
	$(CC) -o lsb_encode lsb_encode.o $(SFMLFLAGS)

lsb_encode.o: lsb_encode.cpp
	$(CC) -c lsb_encode.cpp -o lsb_encode.o

lsb_decode: lsb_decode.o
	$(CC) -o lsb_decode lsb_decode.o $(SFMLFLAGS)

lsb_decode.o: lsb_decode.cpp
	$(CC) -c lsb_decode.cpp -o lsb_decode.o

pixel_compare: pixel_compare.o
	$(CC) -o pixel_compare pixel_compare.o $(SFMLFLAGS)

pixel_compare.o: pixel_compare.cpp
	$(CC) -c pixel_compare.cpp -o pixel_compare.o

clean:
	rm *o lsb_encode lsb_decode pixel_compare
