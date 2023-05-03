CXX = g++
CXXFLAGS = -g
NAMEGLAGS = -o
SRC = src
TARGET = p06_arbol
TARGET_TRAZA = traza_arbol

make:
	$(CXX) $(CXXFLAGS) -DSINTRAZA ./$(SRC)/*.cc $(NAMEGLAGS) $(TARGET)

traza:
	$(CXX) $(CXXFLAGS) -DTRAZA ./$(SRC)/*.cc $(NAMEGLAGS) $(TARGET_TRAZA)

.PHONY: all clean

	$(CXX) $(CXXFLAGS) -c $<

clean :
	rm -f $(TARGET) *.o
	rm -f $(TARGET_TRAZA) *.o
	rm -rf *~ basura b i