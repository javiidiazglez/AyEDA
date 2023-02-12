#ifndef GRID_H
#define GRID_H

#include <iostream>
#include <cassert>
#include "cell.h"

//using namespace std;

class Grid{
  private:
    Cell** grid_; 
    int row_;
    int col_;
    int turns_;
    
  public:
    Grid(int m, int n, int t); // turnos agregado
    ~Grid();

    int get_row();
    int get_col();
    const int get_row() const;
    
    const Cell& getCell(int, int) const;
    // Cell& getCell(int, int);

    void nextGeneration();

    void imprimirGrid();

    void build();
    void destroy();
};

#endif