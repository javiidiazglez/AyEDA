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
 * @file fdModule.h: clase fdModule
 * @brief Contiene la declaracion de la clase fdModule
 **/

#ifndef FD_MODULE_H
#define FD_MODULE_H

#include "DispersionFunction.h"

template <class Key>
class fdModule : public DispersionFunction<Key> {
 public:
  fdModule(const unsigned n) : tableSize(n) {}
  unsigned operator()(const Key& k) const;

 private:
  unsigned tableSize;
};

// Sobrecarga operador funcion como método nulo
template <class Key>
unsigned fdModule<Key>::operator()(const Key& k) const {
  return k % tableSize;
}

#endif