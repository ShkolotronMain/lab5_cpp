CC = clang++
CXXFLAGS = -Wall -g

all: prog

prog: course.o stock.o interpreter.o main.o
	$(CC) $(CXXFLAGS) course.o stock.o interpreter.o main.o -o main.out

course.o:
	$(CC) $(CXXFLAGS) -c course.cpp -o course.o

stock.o: 
	$(CC) $(CXXFLAGS) -c stock.cpp -o stock.o

interpreter.o:
	$(CC) $(CXXFLAGS) -c interpreter.cpp -o interpreter.o

main.o: 
	$(CC) $(CXXFLAGS) -c main.cpp -o main.o

clean:
	rm -rf *.o prog