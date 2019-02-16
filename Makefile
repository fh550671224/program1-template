CFLAGS= -g -Wall -std=c++14 -DDEBUG -Wextra
all: program1

program1: program1.o Star.o Vector.o List.o
	g++ $(CFLAGS) program1.o Star.o Vector.o List.o -o program1

program1.o: program1.cpp Star.cpp Star.h Vector.cpp Vector.h List.cpp List.h 
	g++ $(CFLAGS) -c program1.cpp -o program1.o

Star.o: Star.cpp Star.h
	g++ $(CFLAGS) -c Star.cpp -o Star.o

Vector.o: Vector.cpp Vector.h
	g++ $(CFLAGS) -c Vector.cpp -o Vector.o

List.o: List.cpp List.h
	g++ $(CFLAGS) -c List.cpp -o List.o

run:
	./program1

memcheck: program1.o Star.o Vector.o List.o
	g++ $(CFLAGS) program1.o Star.o Vector.o List.o -o program1
	valgrind ./program1

clean:
	rm -rf *.o program1