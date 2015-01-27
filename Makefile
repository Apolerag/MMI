CXX=clang++
CXXFLAGS=-c -Wall -ansi -pedantic -Wc++11-extensions

#SRC = main.cpp image.cpp imageniveauxgris.cpp histogramme.cpp 
SRC = $(wildcard *.cpp)
OBJ = $(SRC:.cpp=.o)
EXEC = programme.exe

all: $(EXEC)

$(EXEC): $(OBJ)
	$(CXX) $(OBJ)  -o $@

%.o: %.cpp %.h
	$(CXX) $(CXXFLAGS) $<

doc:
	doxygen

clean:
	rm -rf *.o *.exe *~ doc/