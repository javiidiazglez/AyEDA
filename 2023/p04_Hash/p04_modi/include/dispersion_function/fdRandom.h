/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingenierıa Informatica
 * Asignatura: Algoritmos y Estructuras de Datos Avanzadas
 * Curso: 2º
 * Práctica 4: Búsqueda por dispersión
 *
 * @author José Javier Díaz González
 * Correo: alu0101128894@ull.edu.es
 *
 * @date 27/03/2023
 * @file fdRandom.h: clase fdRandom
 * @brief Contiene la declaracion de la clase fdRandom
 **/

#ifndef FD_RANDOM_H
#define FD_RANDOM_H

#include <cstdlib>

#include "DispersionFunction.h"

template <class Key>
class fdRandom : public DispersionFunction<Key> {
 public:
  fdRandom(const unsigned n) : tableSize(n) {}
  unsigned operator()(const Key& k) const;

 private:
  unsigned tableSize;
};

template <class Key>
unsigned fdRandom<Key>::operator()(const Key& k) const {
  srand(k);
  return rand() % tableSize;
}

#endif