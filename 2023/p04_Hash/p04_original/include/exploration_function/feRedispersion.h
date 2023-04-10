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
 * @file feRedispersion.h: clase feRedispersion
 * @brief Contiene la declaracion de la clase feRedispersion
 **/

#ifndef FE_REDISPERSION_H
#define FE_REDISPERSION_H

#include <cstdlib>

#include "ExplorationFunction.h"

template <class Key>
class feReDispersion : public ExplorationFunction<Key> {
 public:
  virtual ~feReDispersion() {}
  feReDispersion() {}
  unsigned operator()(const Key& k, unsigned i) const;

 private:
  DispersionFunction<Key>* fd_;
};

template <class Key>
unsigned feReDispersion<Key>::operator()(const Key& k, unsigned i) const {
  unsigned value;
  srand(k);
  for (int j{0}; j < i; ++j) value = rand();  // Generación de un número aleatorio.
  return (i) * ((*fd_)(value));               // Multiplicando el valor de la función de dispersión por el número de iteraciones.
}

#endif