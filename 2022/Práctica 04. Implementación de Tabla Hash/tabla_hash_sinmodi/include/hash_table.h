/*
  Universidad de La Laguna
  Escuela Superior de Ingeniería y Tecnología
  Grado en Ingeniería Informática          
  Algoritmos y Estructuras de datos Avanzados
  Fecha: 08/04/2022     
  Autor: José Javier Díaz González (alu0101128894)
  Práctica 4. Tabla Hash                            
  Referencias: https://es.wikipedia.org/wiki/Tabla_hash
  Nombre del archivo: hash_table.h                    
*/

#ifndef TABLA_HASH_H
#define TABLA_HASH_H

#include <iostream>
#include <vector>

#include "dispersion.h"
#include "list.h"

template <class Key>
class HashTable {
 public:
  virtual ~HashTable();

  virtual bool Search(const Key& key) const = 0;
  virtual bool Insert(const Key& key) = 0;
  virtual std::ostream& Write(std::ostream& os) const { return os; }
};

template <typename Key>
HashTable<Key>::~HashTable() {}

template <typename Key>
std::ostream& operator<<(std::ostream& os, const HashTable<Key>& table) {
  return table.Write(os);
}

#endif
