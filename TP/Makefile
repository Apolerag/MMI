CXX=clang++
CXXFLAGS=-c -Wall -ansi -pedantic

SRC = main.cpp image.cpp imageniveauxgris.cpp histogramme.cpp 
OBJ = $(SRC:.cpp=.o)
EXEC = programme.exe

all: $(EXEC)

$(EXEC): $(OBJ)
	$(CXX) $(OBJ)  -o $@

%.o: %.cpp %.h
	$(CXX) $(CXXFLAGS) $<

clean:
	rm -rf *.o *.exe