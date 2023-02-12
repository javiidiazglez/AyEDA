CXX		  := g++
CXX_FLAGS := -Wextra -std=c++17 -ggdb 

SRC		:= src
INCLUDE	:= include

EXECUTABLE	:= hash

all: $(EXECUTABLE)

run: clean all
	clear
	./$(EXECUTABLE)

$(EXECUTABLE): $(SRC)/*.cc
	$(CXX) $(CXX_FLAGS) -I$(INCLUDE) $^ -o $@ 

clean:
	-rm $(EXECUTABLE)