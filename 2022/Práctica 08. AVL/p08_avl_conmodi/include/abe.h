/*
  Universidad de La Laguna
  Escuela Superior de Ingeniería y Tecnología
  Grado en Ingeniería Informática          
  Algoritmos y Estructuras de datos Avanzados
  Fecha: 25/05/2022     
  Autor: José Javier Díaz González (alu0101128894)
  Práctica 8: Implementación de árboles binarios de búsqueda balanceado (AVL)                       
  Referencias: https://es.wikipedia.org/wiki/%C3%81rbol_binario
  Nombre del archivo: abe.h                  
*/

#ifndef ABE_H
#define ABE_H

#include "ab.h"
#include <vector>

// El código anterior es una clase de plantilla que hereda de la clase Ab. Tiene un constructor y un destructor. 
// También tiene una función de profundidad que devuelve la profundidad del árbol. 
// Tiene una función Insertar que inserta un nodo en el árbol. 
// Tiene una función Remove que elimina un nodo en el árbol. 
// Tiene una función InsertR que inserta recursivamente un nodo en el árbol. 
// Tiene una función de búsqueda que encuentra un nodo en el árbol. 
// Tiene una función FindR que encuentra recursivamente un nodo en el árbol.

template <class Key> class Abe : public Ab<Key> {
public:
  Abe() = default;
  ~Abe() = default;

  int Depth(Node<Key> *current) const;
  bool Insert(const Key &data) override;
  bool Find(const Key &data) const override;
  bool Remove(const Key &data) override;

private:
  bool FindR(const Key &data, Node<Key> *current) const;
  bool InsertR(Node<Key> *&current, const Key &data);
};

// Llamando a la función recursiva Remove.
template <class Key> bool Abe<Key>::Remove(const Key &data) {
  return false;
}
// Llamando a la función recursiva FindR.
template <class Key> bool Abe<Key>::Find(const Key &data) const {
  return FindR(data, this->root_);
}

// Una función recursiva que devuelve verdadero si los datos se encuentran en el árbol.
template <class Key>
bool Abe<Key>::FindR(const Key &data, Node<Key> *current) const {
  // Comprobando si el nodo actual es nullptr. Si lo es, devuelve falso.
  if (!current)
    return false;
  
  // Comparando los datos del nodo actual con los datos que se están buscando.
  if (*current == data)
    return true;
  
  // Comprobando si los datos están en la rama izquierda o derecha.
  return FindR(data, current->left) || FindR(data, current->right);
}

template <class Key> bool Abe<Key>::Insert(const Key &data) {
  if (!this->root_) {
    this->root_ = new Node<Key>(data); // Creando un nuevo nodo con los datos.
    return true;  //  Devolviendo verdadero si los datos se encuentran en el árbol.
  }

  // Comprobando si los datos ya están en el árbol.
  if (this->Find(data))
    return false;

  return InsertR(this->root_, data);
}

// Insertar un nodo en el árbol.
template <class Key>
bool Abe<Key>::InsertR(Node<Key> *&current, const Key &data) {

  int left_depth = Depth(current->left);
  int right_depth = Depth(current->right);
  int diff = left_depth - right_depth;
  switch (diff) {
  case -1:
    // Comprobando si el nodo izquierdo es nullptr. Si es así, crea un nuevo nodo con los datos.
    if (current->left)
      return InsertR(current->left, data);
    else {
      current->left = new Node<Key>(data);
      return true; // Devolviendo verdadero si los datos se encuentran en el árbol.

    }
    break;
  case 0:
    // Comprobando si el nodo izquierdo es nullptr.
    if (current->left)
      return InsertR(current->left, data);
    else {
      current->left = new Node<Key>(data);
      
      return true;
    }
    break;
  case 1:
    // Comprobando si el nodo correcto es nullptr. Si es así, crea un nuevo nodo con los datos.
    if (current->right)
      return InsertR(current->right, data);
    else {
      current->right = new Node<Key>(data);
      return true;
    }
    break;
  }
  // Devolviendo falso si los datos no se encuentran en el árbol.
  return false;
}

// Una función recursiva que devuelve la profundidad del árbol.
template <class Key> int Abe<Key>::Depth(Node<Key> *current) const {
  int depth = 0;
  if (current == nullptr) // Comprobando si el nodo actual es nullptr. Si es así, devuelve 0.
    return 0;

  // Cálculo de la profundidad del árbol.
  int left_depth = Depth(current->left);
  int right_depth = Depth(current->right);
  if (left_depth > right_depth)
    depth = left_depth + 1;
  else
    depth = right_depth + 1;
  return depth;
}

#endif