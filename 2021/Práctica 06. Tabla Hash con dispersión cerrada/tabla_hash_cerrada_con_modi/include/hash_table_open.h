//////////////////////////////////////////////////////////////////////////////////
// Universidad de La Laguna                                                     //
// Escuela Superior de Ingeniería y Tecnología                                  //
// Grado en Ingeniería Informática                                              //
// Algoritmos y Estructuras de datos Avanzados                                  //
// Fecha: 16/04/2021                                                            //
// Autor: José Javier Díaz González (alu0101128894)                             //
//                                                                              //
// Práctica 7. Tabla Hash con dispersión cerrada                                //
// Referencias: https://es.wikipedia.org/wiki/Tabla_hash                        //
// Nombre del archivo: hash_table_open.h                                        //
//////////////////////////////////////////////////////////////////////////////////

#ifndef TABLA_HASH_OPEN_H
#define TABLA_HASH_OPEN_H

#include <iostream>
#include <vector>

#include "dispersion.h"
#include "hashtable.h"
#include "list.h"

template <typename Key>
class HashTableOpen : public HashTable<Key> {
 public:
  HashTableOpen(size_t table_size, Dispersion<Key>* dispersion_function);
  virtual ~HashTableOpen();

  virtual bool Search(const Key& key);
  virtual bool Insert(const Key& key);

  std::ostream& Write(std::ostream& os) const;

  template <typename K>
  friend std::ostream& operator<<(std::ostream& os, const HashTableOpen<K>& hash_table);

 protected:
  std::vector<List<Key>> elements_;
  Dispersion<Key>* dispersion_function_;  // Uso de patrón estrategia
};

template <typename Key>
HashTableOpen<Key>::HashTableOpen(size_t table_size, Dispersion<Key>* dispersion_function) {
  elements_.resize(table_size);
  dispersion_function_ = dispersion_function;
}

template <typename Key>
HashTableOpen<Key>::~HashTableOpen() {
  if (dispersion_function_ != NULL)
    delete dispersion_function_;
}

template <typename Key>
bool HashTableOpen<Key>::Search(const Key& key) {
  return elements_[(*dispersion_function_)(key)].Search(key);
}

template <typename Key>
bool HashTableOpen<Key>::Insert(const Key& key) {
  return elements_[(*dispersion_function_)(key)].Insert(key);
}

template <typename Key>
std::ostream& HashTableOpen<Key>::Write(std::ostream& os) const {
  os << "keys: " << elements_.size() << '\n';
  os << "Index\tValues\n";
  size_t index = 0;
  for (const auto& element : elements_)
    os << index++ << "\t" << element << '\n';
  return os;
}

template <typename Key>
std::ostream& operator<<(std::ostream& os, const HashTableOpen<Key>& hash_table) {
  return hash_table.Write(os);
}

#endif
