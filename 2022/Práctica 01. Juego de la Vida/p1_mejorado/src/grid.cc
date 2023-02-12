#include "../include/grid.h"

#include <cassert>
#include <iostream>

void error_1(int& opc) {
  while (std::cin.fail()) {
    std::cin.clear();
    std::cin.ignore(99, '\n');
    std::cout << "Introduzca un número válido: ";
    std::cin >> opc;
  }
}
// implementacion de metodos de clase grid
Grid::Grid(int m, int n, int t) {
  row_ = m;
  col_ = n;
  turns_ = t;  // turnos

  grid_ = NULL;
  if (row_ != 0 || col_ != 0) {
    grid_ = new Cell*[row_ + 2];
    for (int i = 0; i < row_ + 2; i++) {
      grid_[i] = new Cell[col_ + 2];
      for (int h = 0; h < col_ + 2; h++) {
        grid_[i][h] = Cell(i, h);
      }
    }
  }
}

Grid::~Grid() {
  if (grid_ != NULL) {
    for (int i = 0; i < row_; i++) {
      delete[] grid_[i];
    }
    delete[] grid_;
  }
  row_ = 0;
  col_ = 0;
}

inline int Grid::getRow() { return row_; }

inline int Grid::getCol() { return col_; }

const int Grid::getRow() const { return row_; }

const Cell& Grid::getCell(int i, int j) const { return grid_[i][j]; }
Cell& Grid::getCell(int i, int j) { return grid_[i][j]; }

void Grid::nextGeneration() {
  for (int i = 1; i <= turns_; i++) {  // recorre los turnos
    std::cout << "\nTurno [" << i << "]:" << std::endl;

    // printGrid();  // imprimes
    std::cout << *this;

    for (int j = 1; j <= row_; j++) {    // recorre los filas (desde i hasta el
                                         // borde sin pasarse (el +2))
      for (int k = 1; k <= col_; k++) {  // recorre los columnas
        grid_[j][k].neighbors(*this);  // calcula los vecinos (this = pasas los vecinos)
      }
    }
    for (int j = 1; j <= row_; j++) {
      for (int k = 1; k <= col_; k++) {
        grid_[j][k].updateState();  // actualizas las celulas
      }
    }
  }
}

// void Grid::printGrid() {
//   for (int i = 1; i <= row_; i++) {  // comienzo por 1  => i = 0 y row_ +1
//   (bordes)
//     for (int k = 1; k <= col_; k++) {
//       std::cout << grid_[i][k];  // se mete en la celula
//     }
//     std::cout << std::endl;
//   }
// }

// Sobrecarga printGrid
std::ostream& operator<<(std::ostream& os, const Grid& print) {
  for (int i = 1; i <= print.getRow(); i++) {  // comienzo por 1  => i = 0 y row_ +1 (bordes)
    for (int k = 1; k <= print.getCol(); k++) {
      os << print.grid_[i][k];  // se mete en la celula
    }
    os << std::endl;
  }
  return os;
}