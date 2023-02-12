CXX		  := g++
CXX_FLAGS := -std=c++17

SRC		:= src
INCLUDE	:= include

EXECUTABLE	:= abb

all: $(EXECUTABLE)

run: clean all
	clear
	./$(EXECUTABLE)

$(EXECUTABLE): $(SRC)/*.cc $(INCLUDE)/*.h
	$(CXX) $(CXX_FLAGS) -I$(INCLUDE) $^ -o $@ 

clean:
	-rm $(EXECUTABLE)