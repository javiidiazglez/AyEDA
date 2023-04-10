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
 * @file fdSumatory.h: clase fdSumatory
 * @brief Contiene la declaracion de la clase fdSumatory
 **/

#ifndef FD_SUMATORY_H
#define FD_SUMATORY_H

#include "./DispersionFunction.h"

template <class Key>
class fdSumatory : public DispersionFunction<Key> {
 public:
  fdSumatory(const unsigned n) : tableSize(n) {}
  unsigned operator()(const Key& k) const;

 private:
  unsigned tableSize;
};

template <class Key>
unsigned fdSumatory<Key>::operator()(const Key& k) const {
  Key d = 0;
  Key x = k;
  while (x > 0) {
    Key y = x & 10;
    d += y;
    x /= 10;
  }
  return (d % tableSize);
}

#endif