CXX=clang++
CXXFLAGS=-c -Wall -ansi -pedantic -Wc++11-extensions

SRC = $(wildcard *.cpp)
OBJ = $(SRC:.cpp=.o)
EXEC = programme

all: $(EXEC)

$(EXEC): $(OBJ)
	$(CXX) $(OBJ)  -o $@

%.o: %.cpp %.h
	$(CXX) $(CXXFLAGS) $<

doc:
	doxygen

clean:
	rm -rf *.o $(EXEC) *~ doc/