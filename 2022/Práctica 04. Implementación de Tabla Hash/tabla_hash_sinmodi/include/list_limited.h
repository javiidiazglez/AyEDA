/*
  Universidad de La Laguna
  Escuela Superior de Ingeniería y Tecnología
  Grado en Ingeniería Informática          
  Algoritmos y Estructuras de datos Avanzados
  Fecha: 08/04/2022     
  Autor: José Javier Díaz González (alu0101128894)
  Práctica 4. Tabla Hash                            
  Referencias: https://es.wikipedia.org/wiki/Tabla_hash
  Nombre del archivo: list_limited.h                      
*/

#ifndef LIST_LIMITED_H
#define LIST_LIMITED_H

#include "list.h"

template <typename Type>
class ListLimited : public List<Type> { // hereda lista abierta , quitando el comportamiento heredado (insertar, buscar)
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
  if (IsFull() || this->Search(value)) // si lleno o no encontrado, no inserta
    return false;

  this->push_front(value); // push hacia adelante
  return true;
}

template <typename Type>
bool ListLimited<Type>::IsFull() const {
  return this->size() == max_size_; // numeros de elementos == al maximo numeros de elementos
}

#endif
