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
// Nombre del archivo: world_finito.cc                                          //
//////////////////////////////////////////////////////////////////////////////////

#include "../include/world_finito.h"

void WorldFinito::CheckLimits(int row, int column) {  // No hace falta, Negativos finitos ->  por defecto rodea bordes
  std::pair<int, int> posiciones = {row, column};
  if (row < min_rows_) { // < -1 (hacia la izquierda)
    std::cout << "No se puede expandir hacia la izquierda." << std::endl;
    throw posiciones;
  } else if (row >= max_rows_) {
    std::cout << "No se puede expandir hacia la derecha." << std::endl;
    throw posiciones;
  }

  if (column < min_columns_) {
    std::cout << "No se puede expandir hacia arriba." << std::endl;
    throw posiciones;
  } else if (column >= max_columns_) {
    std::cout << "No se puede expandir hacia abajo." << std::endl;
    throw posiciones;
  }
}
