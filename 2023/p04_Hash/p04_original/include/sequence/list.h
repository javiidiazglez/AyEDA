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
 * @file list.h: clase list
 * @brief Contiene la declaracion de la clase list
**/

#ifndef LIST_H
#define LIST_H

#include <iostream>
#include <vector>
#include <algorithm>

#include "sequence.h"

template<class Key>
class List : public Sequence<Key> {
 public:
  virtual ~List() {}
  List() {};
  bool search(const Key& k) const;
  bool insert(const Key& k);
  bool isFull() const;
  void print();

 private:
  std::vector<Key> lista_;
	unsigned nSinonimos_;
};

template<class Key>
bool List<Key>::search(const Key& k) const {
	for (size_t i{0}; i < lista_.size(); ++i){
    if (lista_[i] == k) return true;
  }
  return false;
}

template<class Key>
bool List<Key>::insert(const Key& k) {
	if (!search(k)) {
    lista_.push_back(k);
    return true;
  } else return false;
}

template<class Key>
bool List<Key>::isFull() const {
  return false;
}

template<class Key>
void List<Key>::print() {
  for (auto const& key : lista_) std::cout << key << " ";
}

#endif