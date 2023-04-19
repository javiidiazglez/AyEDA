/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingenierıa Informatica
 * Asignatura: Algoritmos y Estructuras de Datos Avanzadas
 * Curso: 2º
 * Práctica 5: Algoritmos de Ordenación
 *
 * @author José Javier Díaz González
 * Correo: alu0101128894@ull.edu.es
 *
 * @date 19/04/2023
 * @file Sort.h: clase Sort
 * @brief Contiene la declaracion de la clase Sort
 **/

#ifndef SortMethod_ctn
#define SortMethod_ctn

#include <iostream>
#include <vector>

template <class Key>
class SortMethod {
 private:
  unsigned size_;
  std::vector<Key> seq_;

 public:
  virtual void Sort() = 0;
  // Setters
  void SetSeq(std::vector<Key> seq) {
    seq_ = seq;
  }
  void SetSize(unsigned size) {
    size_ = size;
  }
  // Getters
  std::vector<Key> GetSeq() {
    return seq_;
  }
  unsigned GetSize() {
    return size_;
  }
};

#endif
