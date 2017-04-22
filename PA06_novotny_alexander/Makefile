PROGRAM_NAME=bintree
CFLAGS=-c -Wall -std=c++11
OBJECTS=PA06.o BinarySearchTree.o

all:main

# Main program for assignment
main: $(OBJECTS)
	g++ $(OBJECTS) -o $(PROGRAM_NAME)

%.o: %.cpp %.h
	g++ $(CFLAGS) $<

clean:
	rm *.o
