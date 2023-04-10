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
 * @file sequence.h: clase sequence
 * @brief Contiene la declaracion de la clase sequence
**/

#ifndef SEQUENCE_H
#define SEQUENCE_H

#include <iostream>

template<class Key>
class Sequence {
 public:
  Sequence() {};
  virtual ~Sequence() {};
  virtual bool search(const Key& k) const = 0;
  virtual bool insert(const Key& k) = 0;
  virtual bool isFull() const = 0;
  virtual void print() = 0;
};

#endif