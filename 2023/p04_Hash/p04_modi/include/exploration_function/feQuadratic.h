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
 * @file feQuadratic.h: clase feQuadratic
 * @brief Contiene la declaracion de la clase feQuadratic
 **/

#ifndef FE_QUADRATIC_H
#define FE_QUADRATIC_H

#include <cmath>

#include "ExplorationFunction.h"

template <class Key>
class feQuadratic : public ExplorationFunction<Key> {
 public:
  virtual ~feQuadratic() {}
  feQuadratic() {}
  unsigned operator()(const Key& k, unsigned i) const;
};

template <class Key>
unsigned feQuadratic<Key>::operator()(const Key& k, unsigned i) const {
  return (i * i);
}

#endif