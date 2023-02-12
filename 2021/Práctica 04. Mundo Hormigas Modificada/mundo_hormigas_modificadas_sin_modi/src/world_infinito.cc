//////////////////////////////////////////////////////////////////////////////////
// Universidad de La Laguna                                                     //
// Escuela Superior de Ingeniería y Tecnología                                  //
// Grado en Ingeniería Informática                                              //
// Algoritmos y Estructuras de datos Avanzados                                  //
// Fecha: 24/03/2021                                                            //
// Autor: José Javier Díaz González (alu0101128894)                             //
//                                                                              //
// Práctica 4: Mundo Hormigas Modifcado                                         //
// Referencias: https://es.wikipedia.org/wiki/Hormiga_de_Langton                //
// Nombre del archivo: world_infinito.cc                                        //
//////////////////////////////////////////////////////////////////////////////////

#include "../include/world_infinito.h"

void WorldInfinito::CheckLimits(int row, int column) {
  if (row < min_rows_) {
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
