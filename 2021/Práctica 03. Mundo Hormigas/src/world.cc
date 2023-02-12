//////////////////////////////////////////////////////////////////////////////////
// Universidad de La Laguna                                                     //
// Escuela Superior de Ingeniería y Tecnología                                  //
// Grado en Ingeniería Informática                                              //
// Algoritmos y Estructuras de datos Avanzados                                  //
// Fecha: 17/03/2021                                                            //
// Autor: José Javier Díaz González (alu0101128894)                             //
//                                                                              //
// Práctica 3: Mundo Hormigas                                                   //
// Referencias: https://es.wikipedia.org/wiki/Hormiga_de_Langton                //
// Nombre del archivo: world.cc                                                 //
//////////////////////////////////////////////////////////////////////////////////

#include "../include/world.h"

World::World() {
  min_columns_ = 0; // todo 0
  min_rows_ = 0;
  max_columns_ = 0;
  max_rows_ = 0;
}

World::World(int rows, int columns) : world_map_(rows, columns) {
  min_columns_ = 0;
  min_rows_ = 0;
  max_columns_ = columns;   // maximo columnas = columnas (al principio mundo (0,0)) + y se actualiza etc etc
  max_rows_ = rows;
  world_map_.Fill(WHITE);   // Rellenar de WHITE
}

World::World(const World& world) {
  *this = world;
}

World::~World() {}

char& World::At(int row, int column) {        // positivas
  std::pair<int, int> maped = Map(row, column);
  return world_map_[maped.first][maped.second];
}

const char& World::At(int row, int column) const {    // negativas
  std::pair<int, int> maped = Map(row, column);   // mapea las posiciones
  return world_map_[maped.first][maped.second];   // accede a la matriz 
}

void World::CheckLimits(int row, int column) {    // comprueba una fila o columna no existe (añade fila o columna)
  if (row < min_rows_) { // < -1 (hacia la izquierda)
    world_map_.AddRowFront(abs(min_rows_ - row), WHITE);    // crea una columna hacia la izquierda
    min_rows_ = row;
  } else if (row >= max_rows_) {
    world_map_.AddRowBack(abs((max_rows_ - row) + 1), WHITE);   // expande a la derecha
    max_rows_ += abs((max_rows_ - row) + 1);
  }

  if (column < min_columns_) {
    world_map_.AddColumnFront(abs(min_columns_ - column), WHITE);   // expande hacia arriba
    min_columns_ = column;
  } else if (column >= max_columns_) {
    world_map_.AddColumnBack(abs((max_columns_ - column) + 1), WHITE);  // expande hacia abajo
    max_columns_ += abs((max_columns_ - column) + 1);
  }
}

std::pair<int, int> World::Map(int row, int column) const { // Funcion de mapeado
  std::pair<int, int> maped;
  maped.first = abs(row - min_rows_);   // fila mapeada
  maped.second = abs(column - min_columns_);  // columna mapeada
  return maped;
}
/*
  minimo de filas y columnas, mapear x = -1 & y = -1 (Matrices 0 -> N)

                   columna(y) - mincolumna
    tam=10                                                                 filas columnas     
  -5      5              |-1-(-5)| = 4    -> x=-1 , en la posicion 4    matriz [4,4]
  -5      5              |-1 -(-5)| = 4   -> y=-1 , en la posicion 4                
                                                                           filas = abajo | columnas = ariiba
                    columna(x) - mincolumna                                  y                 x
*/

void World::operator=(const World& world) { // Igualar
  min_columns_ = world.min_columns_;
  min_rows_ = world.min_rows_;
  max_columns_ = world.max_columns_;
  max_rows_ = world.max_rows_;
  world_map_ = world.world_map_;
}

std::ostream& operator<<(std::ostream& os, const World& world) {
  for (size_t i = 0; i < world.world_map_.Rows(); ++i) {
    for (size_t j = 0; j < world.world_map_.Columns(); ++j) {
      os << world.world_map_[i][j];
    }
    os << std::endl;
  }
  return os;
}
