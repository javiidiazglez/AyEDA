//////////////////////////////////////////////////////////////////////////////////
// Universidad de La Laguna                                                     //
// Escuela Superior de Ingeniería y Tecnología                                  //
// Grado en Ingeniería Informática                                              //
// Algoritmos y Estructuras de datos Avanzados                                  //
// Fecha: 28/04/2021                                                            //
// Autor: José Javier Díaz González (alu0101128894)                             //
//                                                                              //
// Práctica 8. Ordenación (II)                                                  //
// Referencias: https://es.wikipedia.org/wiki/Algoritmo_de_ordenamiento         //
// Nombre del archivo: algorithm.h                                              //
//////////////////////////////////////////////////////////////////////////////////

#ifndef ALGORITHM_H
#define ALGORITHM_H

#include <iostream>
#include <vector>

template <typename Type>
class Algorithm {
 public:
  Algorithm() : vector_() {}
  virtual ~Algorithm() {}
  virtual std::vector<Type> metodo(std::vector<Type> a, int sz) = 0;

 protected:
  std::vector<Type> vector_;
};

#endif
