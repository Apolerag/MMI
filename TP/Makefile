CXX=g++
CXXFLAGS=-c -Wall -ansi -pedantic

SRC = $(wildcard *.cpp)
OBJ = $(SRC:.cpp=.o)
EXEC = programme.exe

<<<<<<< HEAD
Programme.exe: main.o image.o imageniveauxgris.o histogramme.o
		$(CXX) main.o image.o imageniveauxgris.o histogramme.o -o Programme.exe

main.o: main.cpp image.h imageniveauxgris.h histogramme.h
		$(CXX) $(CXXFLAGS) main.cpp -o main.o
=======
all: $(EXEC)

$(EXEC): $(OBJ)
	$(CXX) $(OBJ)  -o $@
>>>>>>> 88f2ed5ea1fd6dbfc443c2aab12dfd4c77ae44c8

%.o: %.cpp %.h
	$(CXX) $(CXXFLAGS) $<

histogramme.o: histogramme.cpp imageniveauxgris.h
		$(CXX) $(CXXFLAGS) histogramme.cpp

clean:
	rm -rf *.o *.exe