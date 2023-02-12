#ifndef GRID_H
#define GRID_H

#include <cassert>
#include <iostream>

#include "../include/cell.h"

class Grid {
 public:
  Grid(int m, int n, int t);  // turnos agregado
  ~Grid();

  int getRow(); 
  int getCol();
  const int getRow() const;
  const int getCol() const { return col_; }

  const Cell& getCell(int, int) const;
  Cell& getCell(int, int);

  void nextGeneration();
  // void printGrid();  // printGrid
  friend std::ostream& operator<<(std::ostream& os, const Grid& print);

 private:
  Cell** grid_;
  int row_;
  int col_;
  int turns_;
};

#endif