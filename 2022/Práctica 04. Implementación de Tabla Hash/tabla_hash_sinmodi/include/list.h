/*
  Universidad de La Laguna
  Escuela Superior de Ingeniería y Tecnología
  Grado en Ingeniería Informática          
  Algoritmos y Estructuras de datos Avanzados
  Fecha: 08/04/2022     
  Autor: José Javier Díaz González (alu0101128894)
  Práctica 4. Tabla Hash                            
  Referencias: https://es.wikipedia.org/wiki/Tabla_hash
  Nombre del archivo: list.h                        
*/

#ifndef LIST_H
#define LIST_H

#include <iostream>
#include <list>
#include <algorithm>

template <typename Type>
class List : public std::list<Type> {
 public:
  virtual ~List();

  size_t GetSize() const;
  bool Search(const Type& value) const;   // encontrar elemento lista
  virtual bool Insert(const Type& value); // insertar

  template <typename K>
  friend std::ostream& operator<<(std::ostream& os, const List<K>& list);
};

template <typename Type>
  List<Type>::~List() { // Destructor List
}

template <typename Type>
bool List<Type>::Search(const Type& value) const {
  auto it = std::find(this->begin(), this->end(), value); // encuentra
  return it != this->end();
}

template <typename Type>
bool List<Type>::Insert(const Type& value) { // Insert
  if (Search(value) == true) // comprueba search (elementos no duplicados)
    return false;
  this->push_front(value); // push hacia adelante
  return true;
}

template <typename Type>
size_t List<Type>::GetSize() const {
  return this->size();
}

template <typename Type>
std::ostream& operator<<(std::ostream& os, const List<Type>& list) {
  for (auto& value : list)
    os << value << " "; 
  return os;
}

#endif
