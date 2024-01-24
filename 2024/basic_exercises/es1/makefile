main.exe: test_nsqrt.o nsqrt.o
	g++ test_nsqrt.o nsqrt.o -o main.exe

test_nsqrt.o: test_nsqrt.cpp
	g++ -c test_nsqrt.cpp -o test_nsqrt.o

nsqrt.o: nsqrt.cpp
	g++ -c nsqrt.cpp -o nsqrt.o