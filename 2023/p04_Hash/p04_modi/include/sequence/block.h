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
 * @file block.h: clase block
 * @brief Contiene la declaracion de la clase block
 **/

#ifndef BLOCK_H
#define BLOCK_H

#include <iostream>
#include <vector>

#include "sequence.h"

template <class Key>
class Block : public Sequence<Key> {
 public:
  Block(size_t);
  bool search(const Key& k) const;
  bool insert(const Key& k);
  bool isFull() const;
  void print();

 private:
  std::vector<Key> lista_;  // Declarar un vector de tipo Key.
  size_t nSinonimos_;       // Una variable que almacena el número de sinónimos que se pueden almacenar en un bloque.
   int count_;
};

template <class Key>
Block<Key>::Block(size_t sinonimos) {
  nSinonimos_ = sinonimos;
  lista_.reserve(sinonimos);
}

template <class Key>
bool Block<Key>::search(const Key& k) const {
  bool found = false;
  int count = 0;
  for (size_t i{0}; i < lista_.size(); ++i) {  
    if (lista_[i] == k) {
      found = true;
      count++;
    }
  }
  std::cout << "es con contador: " << count << std::endl;
  return found;
}

template <class Key>
bool Block<Key>::insert(const Key& k) {
  if (!search(k) && !isFull()) {
    lista_.push_back(k);
    return true;
  } else
    return false;
}

template <class Key>
bool Block<Key>::isFull() const {
  return lista_.size() >= nSinonimos_;
}

template <class Key>
void Block<Key>::print() {
  for (auto const& key : lista_) std::cout << key << " ";
}

#endif