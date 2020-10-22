CC=g++
CFLAGS=-std=c++11

all:Matrix main
	$(CC) $(CFLAGS) Matrix.o main.o -o out
	
Matrix:
	$(CC) $(CFLAGS) -c Matrix.cpp
   
main:
	$(CC) $(CFLAGS) -c main.cpp