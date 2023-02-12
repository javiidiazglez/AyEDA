//////////////////////////////////////////////////////////////////////////////////
// Universidad de La Laguna                                                     //
// Escuela Superior de Ingeniería y Tecnología                                  //
// Grado en Ingeniería Informática                                              //
// Algoritmos y Estructuras de datos Avanzados                                  //
// Fecha: 07/04/2021                                                            //
// Autor: José Javier Díaz González (alu0101128894)                             //
//                                                                              //
// Práctica 5. Tabla Hash con dispersión abierta                                //
// Referencias: https://es.wikipedia.org/wiki/Tabla_hash                        //
// Nombre del archivo: hash_table.h                                             //
//////////////////////////////////////////////////////////////////////////////////

#ifndef TABLA_HASH_H
#define TABLA_HASH_H

#include <iostream>
#include <vector>

#include "dispersion.h"
#include "list.h"

template <typename Key>
class HashTable {
  public:
    HashTable(size_t table_size, Dispersion<Key>* dispersion_function);
    ~HashTable();

    bool Search(const Key& key) const;
    bool Insert(const Key& key);

    template <typename K>
    friend std::ostream& operator<<(std::ostream& os, const HashTable<K>& hash_table);

  private:
    std::vector<List<Key>> elements_;         // vector de lista de key
    Dispersion<Key>* dispersion_function_;    // Uso de patrón estrategia (MODULO O ALEATORIO)
};
/*
  0  1   2   3   4       Insertar: 10 -> 10 % size = 10 % 5 = 0  | 11: 11%5=1
  10 11                  Buscar:  10 ->  10 % 5 = 0                            -> funcion de dispersión
*/

template <typename Key>
HashTable<Key>::HashTable(size_t table_size, Dispersion<Key>* dispersion_function) { //Constructor
  elements_.resize(table_size); // resize
  dispersion_function_ = dispersion_function; 
}

template <typename Key>
HashTable<Key>::~HashTable() {       // Destructores
  if (dispersion_function_ != NULL) // cada new = delete
    delete dispersion_function_;    // puntero*
}

template <typename Key>
bool HashTable<Key>::Search(const Key& key) const {
  return elements_[(*dispersion_function_)(key)].Search(key);   // indice este elemento -> busca en la lista
}

template <typename Key>
bool HashTable<Key>::Insert(const Key& key) {
  return elements_[(*dispersion_function_)(key)].Insert(key);   // indice este elemento -> inserto en la lista
}

template <typename Key>
std::ostream& operator<<(std::ostream& os, const HashTable<Key>& hash_table) {
  os << "keys: " << hash_table.elements_.size() << '\n'; // elementos N
  os << "Index\tValues\n";
  size_t index = 0;
  for (const auto& element : hash_table.elements_)
    os << index++ << "\t" << element << '\n';
  return os;
}

#endif
