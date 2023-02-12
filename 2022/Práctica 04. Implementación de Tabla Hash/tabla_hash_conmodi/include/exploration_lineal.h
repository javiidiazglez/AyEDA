/*
  Universidad de La Laguna
  Escuela Superior de Ingeniería y Tecnología
  Grado en Ingeniería Informática          
  Algoritmos y Estructuras de datos Avanzados
  Fecha: 08/04/2022     
  Autor: José Javier Díaz González (alu0101128894)
  Práctica 4. Tabla Hash                            
  Referencias: https://es.wikipedia.org/wiki/Tabla_hash
  Nombre del archivo: exploration_lineal.h                
*/

#ifndef EXPLORATION_LINEAL_H
#define EXPLORATION_LINEAL_H

#include <iostream>

#include "exploration.h"

template <class Key>
class ExplorationLineal : public Exploration<Key> {
 public:
  ExplorationLineal(size_t size) : Exploration<Key>(size) {}
  ~ExplorationLineal() {}
  size_t operator()(const Key& key, size_t index) const;
};

template <class Key>
size_t ExplorationLineal<Key>::operator()(const Key& key, size_t index) const {
  return (index + 1) % this->size_;
}

#endif
