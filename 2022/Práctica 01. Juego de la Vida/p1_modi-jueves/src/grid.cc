#include <iostream>
#include <cassert>
#include "../include/grid.h"

void error_1 (int &opc){
	while (cin.fail()){
		cin.clear();
		cin.ignore(99, '\n');
		cout << "Introduzca un número válido: ";
		cin >> opc;
  }
}
//implementacion de metodos de clase grid
Grid::Grid(int m, int n, int t){
  row_ = m;
  col_ = n;
  turns_ = t; // turnos
  build();
}

Grid::~Grid() { destroy(); }

inline int Grid::get_row(){ 
  return row_; 
}

inline int Grid::get_col(){ 
  return col_; 
}

const int Grid::get_row() const { 
  return row_; 
}

const Cell& Grid::getCell(int i, int j) const {
  return grid_[i][j];        
}

void Grid::nextGeneration(){
  int vivas, i, j;
  cout << "\nEn el tablero de matriz [" << row_ << " x " << col_ << "]\n ¿Número de células vivas inicialmente? (Mínimo 1): ";
  cin >> vivas;
  error_1(vivas);
  while (vivas <= 0) {
    cout << "\n¡Números de células fuera de rango!\n- Introduzca una célula dentro del rango (Mínimo 1): ";
    cin >> vivas;
  }
  cout << "\nIntroduzca posiciones de las [" << vivas << "] celulas: " << endl;
  for (int k = 0; k < vivas; k++) {
    cout << "\nCélula [" << k << "]: " << endl;
    cout << "   Fila    : "; cin >> i;
    error_1(i);
    while (i > row_ || i <= 0){
      cout << "¡Fila fuera de rango!\n- Introduzca una nueva Fila válida: ";
      cin >> i;
    }
    cout << "   Columna : "; cin >> j;
    error_1(j);
    while (j > col_ || j <= 0){
      cout << "¡Columna fuera de rango!\n- Introduzca una nueva Columna válida: ";
      cin >> j;
    }
    grid_[i][j].setState(viva);   // mundo.getCell(i,j).setState(viva);
  }
  std::cout << "\nTurno [0]:" << std::endl;
  imprimirGrid();                 // imprimes el original

  for (int i = 1; i <= turns_; i++) {      // recorre los turnos
    for (int j = 1; j <= row_; j++) {      // recorre los filas (desde i hasta el borde sin pasarse (el +2))
      for (int k = 1; k <= col_; k++) {    // recorre los columnas
          grid_[j][k].neighbors(*this);    // calcula los vecinos (this = pasas los vecinos)
      }
    }
    for (int j = 1; j <= row_; j++) {
      for (int k = 1; k <= col_; k++) {
          grid_[j][k].updateState();     // actualizas las celulas
      }
    }
    std::cout << "Turno [" << i << "]:" << std::endl;
    imprimirGrid();                      // imprimes
  }
}

void Grid::imprimirGrid(){            
  for(int i = 1; i <= row_ ; i++){    // comienzo por 1  => i = 0 y row_ +1 (bordes)
    for(int k = 1; k <= col_ ; k++){
        cout << grid_[i][k];          //se mete en la celula
    }
    cout << endl;
  }
}

// Build
void Grid::build(){
  grid_ = NULL;
  if (row_ != 0 || col_ != 0){
    grid_ = new Cell* [row_ + 2];
    for (int i = 0; i < row_ + 2; i++){
      grid_[i] = new Cell [col_ + 2];
      for (int h = 0; h < col_ + 2; h++){
        grid_[i][h] = Cell(i,h);
      }
    }
  } 
}

// Destroy
void Grid::destroy(){
  if (grid_ != NULL){
    for (int i = 0; i < row_; i++){
        delete [] grid_[i];
    }
    delete [] grid_;
  }
  row_ = 0;
  col_ = 0;
}