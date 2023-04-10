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
 * @file feDoubleDispersion.h: clase feDoubleDispersion
 * @brief Contiene la declaracion de la clase feDoubleDispersion
 **/

#ifndef FE_DOUBLE_DISPERSION_H
#define FE_DOUBLE_DISPERSION_H

#include "../dispersion_function/DispersionFunction.h"
#include "ExplorationFunction.h"

template <class Key>
class feDoubleDispersion : public ExplorationFunction<Key> {
 public:
  virtual ~feDoubleDispersion() {}
  feDoubleDispersion(DispersionFunction<Key>& fd) : fd_(fd) {}
  unsigned operator()(const Key& k, unsigned i) const;

 private:
  DispersionFunction<Key>& fd_;
};

template <class Key>
unsigned feDoubleDispersion<Key>::operator()(const Key& k, unsigned i) const {
  return i * ((fd_)(k));
}

#endif