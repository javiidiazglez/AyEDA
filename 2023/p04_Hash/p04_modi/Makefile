CXX = g++
CXXFLAGS = -g -w
NAMEGLAGS = -o
SRC = src
INCLUDE	:= include
TARGET = hashTable

make:
	$(CXX) $(CXXFLAGS) ./$(SRC)/*.cc -I$(INCLUDE) $(NAMEGLAGS) $(TARGET)

.PHONY: all clean

	$(CXX) $(CXXFLAGS) -c $<

clean :
	rm -f $(TARGET) *.o
	rm -rf *~ basura b i