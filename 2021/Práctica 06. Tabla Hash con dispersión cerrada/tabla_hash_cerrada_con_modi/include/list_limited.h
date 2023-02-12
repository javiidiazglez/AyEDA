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
// Nombre del archivo: list_limited.h                                           //
//////////////////////////////////////////////////////////////////////////////////

#ifndef LIST_LIMITED_H
#define LIST_LIMITED_H

#include "list.h"

template <typename Type>
class ListLimited : public List<Type> {
 public:
  ListLimited(size_t max_size);
  ~ListLimited();

  bool Insert(const Type& value);
  bool IsFull() const;

 private:
  size_t max_size_;
};

template <typename Type>
ListLimited<Type>::ListLimited(size_t max_size) {
  max_size_ = max_size;
}

template <typename Type>
ListLimited<Type>::~ListLimited() {
}

template <typename Type>
bool ListLimited<Type>::Insert(const Type& value) {
  if (IsFull() || this->Search(value))
    return false;

  this->push_front(value);
  return true;
}

template <typename Type>
bool ListLimited<Type>::IsFull() const {
  return this->size() == max_size_;
}

#endif
