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
// Nombre del archivo: node.h                                                   //
//////////////////////////////////////////////////////////////////////////////////

#ifndef NODE_H
#define NODE_H

#include <iostream>

template <typename Type>
class Node {
  public:
    Type value;       // valor
    Node<Type>* next; // siguiente valor

    Node();
    Node(const Type& value, Node<Type>* next = NULL);
    ~Node();
};

template <typename Type>
Node<Type>::Node() {    // Constructor por defecto
  next = NULL;
  value = Type();
}

template <typename Type>
Node<Type>::Node(const Type& value, Node<Type>* next) {   // Constructor por parámetros
  this->next = next;
  this->value = value;
}

template <typename Type>
Node<Type>::~Node() {     // Destructor
  if (next != NULL)
    delete next;
}

#endif
