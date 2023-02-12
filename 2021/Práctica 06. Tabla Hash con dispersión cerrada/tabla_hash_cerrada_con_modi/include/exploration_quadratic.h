//////////////////////////////////////////////////////////////////////////////////
// Universidad de La Laguna                                                     //
// Escuela Superior de Ingeniería y Tecnología                                  //
// Grado en Ingeniería Informática                                              //
// Algoritmos y Estructuras de datos Avanzados                                  //
// Fecha: 16/04/2021                                                            //
// Autor: José Javier Díaz González (alu0101128894)                             //
//                                                                              //
// Práctica 7. Tabla Hash con dispersión cerrada                                //
// Referencias: https://es.wikipedia.org/wiki/Tabla_hash                        //
// Nombre del archivo: exploration_quadratic.h                                  //
//////////////////////////////////////////////////////////////////////////////////

#ifndef EXPLORATION_QUADRATIC_H
#define EXPLORATION_QUADRATIC_H

#include <iostream>
#include <cmath>
#include "exploration.h"

template <class Key>
class ExplorationQuadratic : public Exploration<Key> {
 public:
  ExplorationQuadratic(size_t size) : Exploration<Key>(size) {}
  ~ExplorationQuadratic() {}
  size_t operator()(const Key& key, size_t index) const;
};

template <class Key>
size_t ExplorationQuadratic<Key>::operator()(const Key& key, size_t index) const {
  return (size_t)(pow(index, 2)) % this->size_;
}

#endif
