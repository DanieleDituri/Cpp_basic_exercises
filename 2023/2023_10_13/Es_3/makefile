main.exe: test_date.o date.o
	g++ test_date.o date.o -o main.exe

test_date.o: test_date.cpp
	g++ -c test_date.cpp -o test_date.o

roman.o: date.cpp
	g++ -c date.cpp -o date.o