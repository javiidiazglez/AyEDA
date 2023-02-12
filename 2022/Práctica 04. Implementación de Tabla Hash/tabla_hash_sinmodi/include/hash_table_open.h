/*
  Universidad de La Laguna
  Escuela Superior de Ingeniería y Tecnología
  Grado en Ingeniería Informática          
  Algoritmos y Estructuras de datos Avanzados
  Fecha: 08/04/2022     
  Autor: José Javier Díaz González (alu0101128894)
  Práctica 4. Tabla Hash                            
  Referencias: https://es.wikipedia.org/wiki/Tabla_hash
  Nombre del archivo: hash_table_open.h                   
*/

#ifndef TABLA_HASH_OPEN_H
#define TABLA_HASH_OPEN_H

#include <iostream>
#include <vector>

#include "dispersion.h"
#include "hashtable.h"
#include "list.h"

template <class Key>
class HashTableOpen : public HashTable<Key> {
 public:
  HashTableOpen(size_t table_size, Dispersion<Key>* dispersion_function); // tamaño, funcion de dispersión
  virtual ~HashTableOpen();

  virtual bool Search(const Key& key) const;
  virtual bool Insert(const Key& key);

  std::ostream& Write(std::ostream& os) const;

  template <typename K>
  friend std::ostream& operator<<(std::ostream& os, const HashTableOpen<K>& hash_table); 

 protected:
  std::vector<List<Key>> elements_;       // vector de lista de key
  Dispersion<Key>* dispersion_function_;  // Uso de patrón estrategia (MODULO O ALEATORIO) (Polimorfismo) Dispersion = Biblioteca
};
/*
  0  1  2  3  4    Insertar: 10 -> 10 % size = 10 % 5 = 0  | 11: 11%5 = 1
  10 11            Buscar:  10 ->  10 % 5 = 0                            -> funcion de dispersión
*/

template <typename Key>
HashTableOpen<Key>::HashTableOpen(size_t table_size, Dispersion<Key>* dispersion_function) {  //Constructor
  elements_.resize(table_size);   // resize
  dispersion_function_ = dispersion_function;
}

template <typename Key>
HashTableOpen<Key>::~HashTableOpen() { // Destructores
  if (dispersion_function_ != NULL) // cada new = delete
    delete dispersion_function_; // puntero*
}

template <typename Key>
bool HashTableOpen<Key>::Search(const Key& key) const {       
  return elements_[(*dispersion_function_)(key)].Search(key); // indice este elemento -> busca en la lista
}

template <typename Key>
bool HashTableOpen<Key>::Insert(const Key& key) {
  return elements_[(*dispersion_function_)(key)].Insert(key); // indice este elemento -> inserto en la lista
}

template <typename Key>
std::ostream& HashTableOpen<Key>::Write(std::ostream& os) const {
  os << "\nClaves: [" << elements_.size() << "]" << '\n'; // elementos N
  os << "Índice\tValores\n";
  size_t index = 0;
  for (const auto& element : elements_)
    os << index++ << "\t" << element << '\n';
  return os;
}

template <typename Key>
std::ostream& operator<<(std::ostream& os, const HashTableOpen<Key>& hash_table) { // sobrecarga
  return hash_table.Write(os);
}

#endif
