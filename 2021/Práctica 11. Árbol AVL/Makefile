CXX		  := g++
CXX_FLAGS := -w -std=c++17 -ggdb 

BIN		:= bin
SRC		:= src
INCLUDE	:= include

EXECUTABLE	:= arbol

all: $(BIN)/$(EXECUTABLE)

run: clean all
	clear
	./$(BIN)/$(EXECUTABLE)

$(BIN)/$(EXECUTABLE): $(SRC)/*.cc
	$(CXX) $(CXX_FLAGS) -I$(INCLUDE) $^ -o $@ 

clean:
	-rm $(BIN)/*
