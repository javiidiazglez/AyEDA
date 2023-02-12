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
// Nombre del archivo: list.h                                                   //
//////////////////////////////////////////////////////////////////////////////////

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
  bool Search(const Type& value) const;
  virtual bool Insert(const Type& value);

  template <typename K>
  friend std::ostream& operator<<(std::ostream& os, const List<K>& list);
};

template <typename Type>
List<Type>::~List() {
}

template <typename Type>
bool List<Type>::Search(const Type& value) const {
  auto it = std::find(this->begin(), this->end(), value);
  return it != this->end();
}

template <typename Type>
bool List<Type>::Insert(const Type& value) {
  if (Search(value) == true)
    return false;
  this->push_front(value);
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
