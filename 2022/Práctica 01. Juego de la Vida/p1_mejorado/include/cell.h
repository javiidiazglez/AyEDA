#ifndef CELL_H
#define CELL_H

#include <iostream>
#include <vector>

class Grid;

enum State { muerta, viva };

class Cell {
 public:
  Cell(int i = 0, int j = 0);
  ~Cell();
  State getState() const;
  State setState(State state);

  void updateState();
  int neighbors(const Grid& grid);

 private:
  State state_;  // estado true (vivo), false (muerto)
  int i_;
  int j_;         // posicion en rejilla
  int neighbor_;  // vecinos vivos
};

std::ostream& operator<<(std::ostream& os, const Cell& b);

#endif
