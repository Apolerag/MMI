CXX=g++
CXXFLAGS=-c -Wall -ansi -pedantic

all: Programme.exe

Programme.exe: main.o image.o imageniveauxgris.o histogramme.o
		$(CXX) main.o image.o imageniveauxgris.o histogramme.o -o Programme.exe

main.o: main.cpp image.h imageniveauxgris.h histogramme.h
		$(CXX) $(CXXFLAGS) main.cpp -o main.o

image.o: image.cpp
		$(CXX) $(CXXFLAGS) image.cpp

imageniveauxgris.o: imageniveauxgris.cpp
		$(CXX) $(CXXFLAGS) imageniveauxgris.cpp

histogramme.o: histogramme.cpp imageniveauxgris.h
		$(CXX) $(CXXFLAGS) histogramme.cpp

clean:
		rm -rf *.o *.exe