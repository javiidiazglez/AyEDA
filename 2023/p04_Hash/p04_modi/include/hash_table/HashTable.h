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
 * @file HashTable.h: clase HashTable
 * @brief Contiene la declaracion de la clase HashTable
 **/

#ifndef HASH_TABLE_H
#define HASH_TABLE_H

#include <deque>
#include <iostream>

#include "../dispersion_function/fdModule.h"
#include "../dispersion_function/fdRandom.h"
#include "../dispersion_function/fdSumatory.h"
#include "../exploration_function/feDoubleDispersion.h"
#include "../exploration_function/feLineal.h"
#include "../exploration_function/feQuadratic.h"
#include "../exploration_function/feRedispersion.h"
#include "../sequence/block.h"
#include "../sequence/list.h"

template <class Key>
class HashTable {
 public:
  virtual ~HashTable() {}
  HashTable();
  HashTable(unsigned size, DispersionFunction<Key>* fd, ExplorationFunction<Key>* fe = nullptr, size_t blockSize = 0) {
    TableSize_ = size;
    fd_ = fd;
    fe_ = fe;
    blockSize_ = blockSize;

    table_ = new Sequence<Key>*[TableSize_];  // Creación de una nueva matriz de punteros a los objetos Sequence<Key>.

    // Creación de una nueva lista o bloque en función de la función de exploración.
    if (fe_ == nullptr) {
      for (size_t i{0}; i < TableSize_; ++i) {  // Creando una nueva lista para cada posición de la tabla.
        table_[i] = new List<Key>();
      }
    } else {
      for (size_t i{0}; i < TableSize_; ++i) {  // Creando un nuevo bloque para cada posición de la mesa.
        table_[i] = new Block<Key>(blockSize_);
      }
    }
  }
  bool search(const Key& k) const;
  bool insert(const Key& k);
  void print();

 private:
  unsigned TableSize_;
  Sequence<Key>** table_;  // Un puntero a un puntero a un objeto Sequence<Key>.
  DispersionFunction<Key>* fd_;
  size_t blockSize_;  // El tamaño del bloque.
  ExplorationFunction<Key>* fe_;
};

/**
 * @brief retorna el valor booleano true si el valor k del tipo Key está
 * guardado en la secuencia. En otro caso retorna el valor false.
 * @param k
 */

template <class Key>
bool HashTable<Key>::search(const Key& k) const {
  unsigned table_pos = (*fd_)(k);
  // Comprobando si la clave está en la tabla.
  if (fe_ != nullptr) {
    for (size_t i{0}; i < TableSize_; ++i) {
      unsigned exploration_value = (*fe_)(k, i);
      if (table_[(table_pos + exploration_value) % TableSize_]->search(k))
        return true;
      else if (!table_[table_pos]->isFull())
        return false;
    }
  } else {
    if (table_[table_pos]->search(k))  // Comprobando si el valor k está en la tabla.
      return true;
    else
      return false;
  }
}

/**
 * @brief retorna el valor booleano true si se inserta el valor k del tipo Key en la secuencia. 
 * En otro caso, si el valor ya estaba guardado en la secuencia, se retorna el valor booleano false.
 * @param k
 */

template <class Key>
bool HashTable<Key>::insert(const Key& k) {
  unsigned table_pos = (*fd_)(k);
  if (fe_ != nullptr) {
    for (size_t i{0}; i < TableSize_; ++i) {
      unsigned exploration_value = (*fe_)(k, i);
      if (!table_[(table_pos + exploration_value) % TableSize_]->search(k) && !table_[(table_pos + exploration_value) % TableSize_]->isFull()) {
        table_[(table_pos + exploration_value) % TableSize_]->insert(k);
        return true;
      } else if (table_[(table_pos + exploration_value) % TableSize_]->search(k))
        return false;
    }
    return false;
  } else {
    if (table_[table_pos]->search(k))
      return false;
    else {
      table_[table_pos]->insert(k);
      return true;
    }
  }
}

// Metodo para imprimir por pantalla

template <class Key>
void HashTable<Key>::print() {
  std::cout << "\nIndice\tValores\n";
  for (size_t i{0}; i < TableSize_; ++i) {
    std::cout << i << "\t";
    table_[i]->print();
    std::cout << std::endl;
  }
}
#endif