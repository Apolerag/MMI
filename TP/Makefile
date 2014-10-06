CXX=g++
CXXFLAGS=-c -Wall -ansi -pedantic

SRC = $(wildcard *.cpp)
OBJ = $(SRC:.cpp=.o)
EXEC = programme.exe

all: $(EXEC)

$(EXEC): $(OBJ)
	$(CXX) $(OBJ)  -o $@

%.o: %.cpp %.h
	$(CXX) $(CXXFLAGS) $<

clean:
	rm -rf *.o *.exe