CC=clang++
CXXFLAGS=-O3

all: prog

prog: course.o stock.o interpreter.o main.o
	$(CC) course.o stock.o interpreter.o main.o -o main.out

course.o:
	$(CC) -c course.cpp -o course.o

stock.o: 
	$(CC) -c stock.cpp -o stock.o

interpreter.o:
	$(CC) -c interpreter.cpp -o interpreter.o

main.o: 
	$(CC) -c main.cpp -o main.o

clean:
	rm -rf *.o prog