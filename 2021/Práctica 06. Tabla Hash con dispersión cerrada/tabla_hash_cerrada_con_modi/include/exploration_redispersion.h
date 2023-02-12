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
// Nombre del archivo: exploration_redispersion.h                               //
//////////////////////////////////////////////////////////////////////////////////
#ifndef EXPLORATION_REDISPERSION_H
#define EXPLORATION_REDISPERSION_H

#include <cstdlib>
#include <iostream>

#include "exploration.h"

template <class Key>
class ExplorationRedispersion : public Exploration<Key> {
 public:
  ExplorationRedispersion(size_t size) : Exploration<Key>(size) {}
  ~ExplorationRedispersion() {}
  size_t operator()(const Key& key, size_t index) const;
};

template <class Key>
size_t ExplorationRedispersion<Key>::operator()(const Key& key, size_t index) const {
  srand(key);
  return (rand() + index) % this->size_;
}

#endif
