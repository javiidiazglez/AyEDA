/*
  Universidad de La Laguna
  Escuela Superior de Ingeniería y Tecnología
  Grado en Ingeniería Informática          
  Algoritmos y Estructuras de datos Avanzados
  Fecha: 25/05/2022     
  Autor: José Javier Díaz González (alu0101128894)
  Práctica 7: Implementación de árboles binarios de búsqueda (ABB)                       
  Referencias: https://es.wikipedia.org/wiki/%C3%81rbol_binario
  Nombre del archivo: ab.h                  
*/

#ifndef AB_H
#define AB_H

#include "node.h"
#include <ostream>
#include <queue>
#include <utility>
#include <vector>

// Una clase que se utilizará como clase base para el árbol de búsqueda binaria.
template <class Key> class Ab {
public:
  Ab();
  ~Ab();

  virtual bool Insert(const Key &data) = 0;
  virtual bool Find(const Key &data) const = 0;
  virtual bool Remove(const Key& data) = 0;

  void PrintInorder(std::ostream &os = std::cout) const;
  void Print(std::ostream &os = std::cout) const;

  template <class U>
  friend std::ostream &operator<<(std::ostream &os, const Ab<U> &tree);

protected:
  Node<Key> *root_;

  void PrintInorderR(Node<Key> *current, std::ostream &os = std::cout) const;
  void PrintR(Node<Key> *prev, std::ostream &os = std::cout) const;
};

// El constructor de la clase Ab.
template <class Key> Ab<Key>::Ab() : root_(nullptr) {}

//Borrando la raíz del árbol.
template <class Key> Ab<Key>::~Ab() {
  if (root_)
    delete root_;
}

// Llamando a la función recursiva PrintInorderR.
template <class Key> void Ab<Key>::PrintInorder(std::ostream &os) const {
  PrintInorderR(root_, os);
}

//Imprimiendo el árbol InOrder
template <class Key>
void Ab<Key>::PrintInorderR(Node<Key> *current, std::ostream &os) const {
  if (!current) // Comprobando si el nodo actual es nullptr, si lo es, regresa.
    return;
  // Al verificar si el nodo actual tiene un hijo izquierdo, si lo tiene, llama a la función nuevamente con el hijo izquierdo como el nodo actual.
  if (current->left)
    PrintInorderR(current->left); 
  os << *current << " | "; // Imprimiendo los datos del nodo actual.
  // Al verificar si el nodo actual tiene un hijo derecho, si lo tiene, llama a la función nuevamente con el hijo derecho como el nodo actual.
  if (current->right)
    PrintInorderR(current->right); 
}

// Llamando a la función recursiva Print.
template <class Key> void Ab<Key>::Print(std::ostream &os) const {
  PrintR(root_, os);
}

// Imprimiendo el árbol en un orden de nivel.
template <class Key> 
void Ab<Key>::PrintR(Node<Key> *prev, std::ostream &os) const {
  std::queue<std::pair<Node<Key> *, int>> queue; // Creando una cola de pares de un puntero a un nodo y un int.
  Node<Key> *node;

  int level, current_level = 0;

  std::pair<Node<Key> *, int> paux(prev, 0); // Creando un par de un puntero a un nodo y un int.
  os << "\nNivel " << current_level << ": "; // Imprimiendo el nivel actual.
  queue.push(paux); // Empujando a la pareja paux a la cola.
  while (!queue.empty()) { // Verificando si la cola está vacía, si lo está, regresa.
    std::pair<Node<Key> *, int> aux = queue.front(); // Obteniendo el primer elemento de la cola y asignándolo a la variable aux.
    queue.pop(); // Eliminando el primer elemento de la cola.
    level = std::get<1>(aux); // Obteniendo el segundo elemento del par aux.
    node = std::get<0>(aux); //   Obteniendo el primer elemento del par aux.

    // Esto es verificar si el nivel del nodo actual es mayor que el nivel actual, si lo es, cambia el nivel actual al nivel del nodo actual e imprime el nuevo nivel.
    if (level > current_level) {
      current_level = level;
      os << "\nNivel " << current_level << ": ";
    }
    // Verificando si el nodo actual es nullptr, si lo es, imprime un punto, si no lo es, imprime los datos del nodo y empuja los hijos izquierdo y derecho del nodo a la cola.
    if (node != nullptr) {
      os << "[" << node->data << "] ";
      std::pair<Node<Key> *, int> paux1(node->left, level + 1);
      queue.push(paux1); // Empujando el hijo izquierdo del nodo actual a la cola.

      std::pair<Node<Key> *, int> paux2(node->right, level + 1);
      queue.push(paux2); // Empujando el hijo derecho del nodo actual a la cola.

    } else {
      os << "[.] "; // Subarbol vacio
    }
  }
}

// Una función de amigo que se utiliza para imprimir el árbol.
template <class U>
std::ostream &operator<<(std::ostream &os, const Ab<U> &tree) {
  tree.Print(os); // Llamar a la función Imprimir, que está llamando a la función ImprimirR, que está imprimiendo el árbol en un orden de nivel.
  return os;
}

#endif