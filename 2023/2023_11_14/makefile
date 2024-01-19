CC=g++
CFLAGS=-c -Wall

all: main.exe

main.exe: main.o
	$(CC) main.o -o main.exe

main.o: main.cpp
	$(CC) $(CFLAGS) main.cpp