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
// Nombre del archivo: list.h                                                   //
//////////////////////////////////////////////////////////////////////////////////

#ifndef LIST_H
#define LIST_H

#include <iostream>

#include "node.h"

template <typename Type>
class List {
  public:
    ~List();

    bool Search(const Type& value) const; // encontrar elemento lista
    bool Insert(const Type& value);

    template <typename K>
    friend std::ostream& operator<<(std::ostream& os, const List<K>& list);

  protected:
    Node<Type>* head_; // nodo inicial
};

template <typename Type>
List<Type>::~List() {   // Destructor List
  // Al hacer delete de la raiz, sus hijos llamaran a su destructor e iran liberando memoria concurrentemente
  if (head_ != NULL)
    delete head_;
}

template <typename Type>
bool List<Type>::Search(const Type& value) const {   // Search
  Node<Type>* current = head_;  // Inicio: current = head
  while (current != NULL) {   // no nulo ->
    if (current->value == value) // current = valor
      return true;
    else
      current = current->next; // siguiente
  }
  return false;
}

template <typename Type>
bool List<Type>::Insert(const Type& value) {    // Insert
  if (Search(value) == true)    // Si N = true , no se inserta
    return false;

  Node<Type>*& current = head_; // Inicio: current = head
  while (true) {
    if (current == NULL) {
      current = new Node<Type>(value);
      break;
    } else if (current->next == NULL) { // siguiente = NULL
        current->next = new Node<Type>(value);
        break;
    } else {
        current = current->next; // siguiente
    }
  }
  return true; // insertado 
}

template <typename Type>
std::ostream& operator<<(std::ostream& os, const List<Type>& list) {
  Node<Type>* current = list.head_; // current = lista head
  while (current != NULL) {
    os << current->value << " "; 
    current = current->next; // siguiente
  }
  return os;
}

#endif
