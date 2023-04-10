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
 * @file feLineal.h: clase feLineal
 * @brief Contiene la declaracion de la clase feLineal
 **/

#ifndef FE_LINEAL_H
#define FE_LINEAL_H

#include "ExplorationFunction.h"

template <class Key>
class feLineal : public ExplorationFunction<Key> {
 public:
  virtual ~feLineal() {}
  feLineal() {}
  unsigned operator()(const Key& k, unsigned i) const;
};

template <class Key>
unsigned feLineal<Key>::operator()(const Key& k, unsigned i) const {
  return i;
}

#endif