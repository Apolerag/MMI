CXX=g++
CXXFLAGS=-c -Wall -ansi -pedantic

all: Programme.exe

Programme.exe: main.o image.o imageniveauxgris.o
		$(CXX) main.o image.o imageniveauxgris.o -o Programme.exe

main.o: main.cpp image.h imageniveauxgris.h
		$(CXX) $(CXXFLAGS) main.cpp -o main.o

image.o: image.cpp
		$(CXX) $(CXXFLAGS) image.cpp

imageniveauxgris.o: imageniveauxgris.cpp
		$(CXX) $(CXXFLAGS) imageniveauxgris.cpp

clean:
		rm -rf *.o *.exe