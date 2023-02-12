/*
  Universidad de La Laguna
  Escuela Superior de Ingeniería y Tecnología
  Grado en Ingeniería Informática          
  Algoritmos y Estructuras de datos Avanzados
  Fecha: 08/04/2022     
  Autor: José Javier Díaz González (alu0101128894)
  Práctica 4. Tabla Hash                            
  Referencias: https://es.wikipedia.org/wiki/Tabla_hash
  Nombre del archivo: hash_table_closed.h                 
*/

#ifndef HASH_TABLE_CLOSE_H
#define HASH_TABLE_CLOSE_H

#include <iostream>

#include "dispersion.h"
#include "exploration.h"
#include "hash_table.h"
#include "list_limited.h"

template <class Key>
class HashTableClosed : public HashTable<Key> {
 public:
  HashTableClosed(size_t table_size, size_t limit, Dispersion<Key>* dispersion_function, Exploration<Key>* exploration_function);
  ~HashTableClosed();

  bool Search(const Key& key) const;
  bool Insert(const Key& key);

  std::ostream& Write(std::ostream& os) const;

 protected:
  std::vector<ListLimited<Key>> elements_; 
  Dispersion<Key>* dispersion_function_;   // Uso de patrón estrategia (MODULO O ALEATORIO) (Polimorfismo) Dispersion = Biblioteca
  Exploration<Key>* exploration_function_; // Uso de patrón estrategia (LINEAL, DOBLE, CUADRATICA, REDISPERSION) (Polimorfismo)
}; // punteros genéricos

// Constructor
template <typename Key>
HashTableClosed<Key>::HashTableClosed(size_t table_size, size_t limit, Dispersion<Key>* dispersion_function, Exploration<Key>* exploration_function) : HashTable<Key>(), elements_(table_size, {limit}) {
  exploration_function_ = exploration_function;
  dispersion_function_ = dispersion_function;
  exploration_function_ = exploration_function;
}

// Destructor
template <typename Key>
HashTableClosed<Key>::~HashTableClosed() {
  if (exploration_function_ != NULL)
    delete exploration_function_;
  if (dispersion_function_ != NULL)
    delete dispersion_function_;
}

template <typename Key>
bool HashTableClosed<Key>::Search(const Key& key) const {
  size_t i = (*this->dispersion_function_)(key);  // Toma inicialmente e valor de la funcion de dispersion
  size_t counter = 0;
  while (counter < this->elements_.size()) { // numeros de intentos < columnas (tamaño)
    if (this->elements_[i].Search(key))     // lo encontramos = true
      return true;
    else if (!this->elements_[i].IsFull()) // si no lo encontramos y no lleno = no elemento
      break;

    i = (*this->exploration_function_)(key, i); // si está lleno, buscar indice nuevo, devuelve el indice,
    ++counter;
  }

  return false;
}

template <typename Key>
bool HashTableClosed<Key>::Insert(const Key& key) {
  if (Search(key))    // no elementos duplicados, primero una busqueda y despues insertas
    return false;

  size_t i = (*this->dispersion_function_)(key);  // Toma inicialmente e valor de la funcion de dispersion
  size_t counter = 0;
  while (counter < this->elements_.size()) {

    if (this->elements_[i].Insert(key))
      return true;
    else if (!this->elements_[i].IsFull()) 
      break;

    i = (*this->exploration_function_)(key, i);
    ++counter;
  }

  return false;
}

template <typename Key>
std::ostream& HashTableClosed<Key>::Write(std::ostream& os) const {
  os << "\nClaves: [" << elements_.size() << "]" << '\n'; // elementos N
  os << "Índice\tValores\n";
  size_t index = 0;
  for (const auto& element : elements_)
    os << index++ << "\t" << element << '\n';
  return os;
}

template <typename Key>
std::ostream& operator<<(std::ostream& os, const HashTableClosed<Key>& hash_table) {
  return hash_table.Write(os);
}

#endif
