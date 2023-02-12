/*
  Universidad de La Laguna
  Escuela Superior de Ingeniería y Tecnología
  Grado en Ingeniería Informática          
  Algoritmos y Estructuras de datos Avanzados
  Fecha: 08/04/2022     
  Autor: José Javier Díaz González (alu0101128894)
  Práctica 4. Tabla Hash                            
  Referencias: https://es.wikipedia.org/wiki/Tabla_hash
  Nombre del archivo: exploration_double.h                
*/

#ifndef EXPLORATION_DOUBLE_H
#define EXPLORATION_DOUBLE_H

#include <cstdlib>
#include <iostream>

#include "exploration.h"

template <class Key>
class ExplorationDouble : public Exploration<Key> { // hereda de la padre, todos sus atributos
 public:
  ExplorationDouble(size_t size) : Exploration<Key>(size) {}
  ~ExplorationDouble() {}
  size_t operator()(const Key& key, size_t index) const;

 private:
  size_t AveragePrime(size_t) const;
};

template <class Key>
size_t ExplorationDouble<Key>::operator()(const Key& key, size_t index) const {
  size_t prime = AveragePrime(this->size_);
  size_t h = prime - key % prime;
  return (index * h) % this->size_;
}

template <class Key>
size_t ExplorationDouble<Key>::AveragePrime(size_t size) const { // numero primo cercano a la tabla
  size_t max;
  bool is_prime;

  for (size_t i = size - 1; i > 2; --i) {
    is_prime = true;
    for (size_t j = 2; j < i; ++j) {
      if (!(i % j)) {
        is_prime = false;
      }
      max = i;
    }
    if (is_prime) {
      return max; // numero primo mas cercano a la tabla
    }
  }
  return max;
}

#endif
