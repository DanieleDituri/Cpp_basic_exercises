main.exe: test_roman.o roman.o
	g++ test_roman.o roman.o -o main.exe

test_roman.o: test_roman.cpp
	g++ -c test_roman.cpp -o test_roman.o

roman.o: roman.cpp
	g++ -c roman.cpp -o roman.o