/*
  Universidad de La Laguna
  Escuela Superior de Ingeniería y Tecnología
  Grado en Ingeniería Informática          
  Algoritmos y Estructuras de datos Avanzados
  Fecha: 19/05/2022     
  Autor: José Javier Díaz González (alu0101128894)
  Práctica 7: Implementación de árboles binarios de búsqueda (ABB)                       
  Referencias: https://es.wikipedia.org/wiki/%C3%81rbol_binario
  Nombre del archivo: node.h                  
*/

#ifndef NODE_H
#define NODE_H

#include <iostream>
#include <ostream>

template <class T> struct Node {
  Node<T> *left;
  Node<T> *right;
  T data;

  static unsigned int counter;

  Node(T data, Node<T> *left = nullptr, Node<T> *right = nullptr);
  Node();
  ~Node();
};

// Inicializando el contador de variables estáticas a 0.
template <class T> unsigned int Node<T>::counter = 0;

// Un constructor para la clase Node.
template <class T> Node<T>::Node(T data, Node<T> *left, Node<T> *right) {
  this->data = data;
  this->left = left;
  this->right = right;
}

template <class T> Node<T>::Node() {
  left = nullptr;
  right = nullptr;
}

// El destructor de la clase Node.
template <class T> Node<T>::~Node() {
  left = nullptr;
  right = nullptr;
}

// Sobrecarga del operador << para la clase Node.
template <class T>
std::ostream& operator<<(std::ostream& os, const Node<T>& node) {
  os << node.data;
  return os;
}

// Una función de plantilla que compara dos nodos.
template <class T>
bool operator==(const Node<T> &lhs, const Node<T> &rhs) {
  ++Node<T>::counter;
  return lhs.data == rhs.data;
}

template <class T>
bool operator==(const Node<T> &lhs, const T &rhs) {
  ++Node<T>::counter;
  return lhs.data == rhs;
}

#endif