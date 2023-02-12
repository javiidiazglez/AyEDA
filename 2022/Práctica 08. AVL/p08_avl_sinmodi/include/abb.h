/*
  Universidad de La Laguna
  Escuela Superior de Ingeniería y Tecnología
  Grado en Ingeniería Informática          
  Algoritmos y Estructuras de datos Avanzados
  Fecha: 25/05/2022     
  Autor: José Javier Díaz González (alu0101128894)
  Práctica 8: Implementación de árboles binarios de búsqueda balanceado (AVL)                       
  Referencias: https://es.wikipedia.org/wiki/%C3%81rbol_binario
  Nombre del archivo: abb.h                  
*/

#ifndef ABB_H
#define ABB_H

#include "ab.h"
#include "node.h"
#include <cstddef>
#include <exception>
#include <vector>

template <class Key> class Abb : public Ab<Key> {
public:
  Abb() = default;
  ~Abb() = default;

  int Depth(Node<Key> *current) const;
  bool Insert(const Key &data) override;
  bool Find(const Key &data) const override;
  bool Remove(const Key &data) override;

private:
  bool FindR(const Key &data, Node<Key> *current) const; //  Una función recursiva que devuelve verdadero si los datos se encuentran en el árbol. 
  bool InsertR(Node<Key> *&current, const Key &data); // Insertar un nuevo nodo en el árbol.
  
  Node<Key> *RemoveBranch(Node<Key> *&current, const Key &data); // Esta función se utiliza para eliminar un nodo del árbol.
  Node<Key> *MinimumValueNode(Node<Key> *current); // Esta función se utiliza para encontrar el valor mínimo del árbol.

  // Una variable booleana que se utiliza para comprobar si se ha eliminado un nodo.
  bool deleted_;
};

template <class Key> Node<Key> *Abb<Key>::MinimumValueNode(Node<Key> *current) {
  
  Node<Key> *current_it = current; // Un puntero al nodo actual.

  // Comprobando si el nodo actual no es nullptr y si el hijo izquierdo del nodo actual no es nullptr.
  while (current_it && current_it->left != nullptr) // 
    current = current->left; // Cambian el nodo actual al hijo izquierdo del nodo actual.

  return current; //  Devolviendo el nodo actual.
}

// Declarar una función llamada Remove que toma una clave const &data como parámetro.
template <class Key> bool Abb<Key>::Remove(const Key &data) {
  deleted_ = false;
  RemoveBranch(this->root_, data);
  return deleted_; 
}

template <class Key>
Node<Key> *Abb<Key>::RemoveBranch(Node<Key> *&current, const Key &data) {
  
  //Comprobando si el nodo actual es nullptr. Si es así, devuelve 0.
  if (current == nullptr) { 
    return current;
  } else if (data < current->data) { // Comprobando si los datos son menores que los datos actuales. Si es así, cambia el nodo actual al nodo izquierdo.
    current->left = RemoveBranch(current->left, data);
  } else if (data > current->data) {
    current->right = RemoveBranch(current->right, data); // Comprobando si los datos son mayores que los datos actuales. Si es así, cambia el nodo actual al nodo derecho.
  } else {
    deleted_ = true;
    if (current->left == nullptr && current->right == nullptr) { // Verifica si el nodo actual es un nodo hoja. Si es así, se establece en nullptr.
      current = nullptr;
    } else if (current->left == nullptr) { // Verifica si el nodo actual es un nodo hoja. Si es así, se establece en nullptr.
      Node<Key> *temp = current;
      current = current->right; // Cambia el nodo actual al hijo derecho del nodo actual.
      temp = nullptr;
    } else if (current->right == nullptr) { // Verifica si el nodo actual es un nodo hoja. Si es así, lo establece en nullptr.
      Node<Key> *temp = current;
      current = current->left; // Cambian el nodo actual al hijo izquierdo del nodo actual.
      temp = nullptr;
    } else {
      Node<Key> *temp = MinimumValueNode(current->right); // Encontrar el valor mínimo de la rama derecha.
      current->data = temp->data; // Reemplazando los datos del nodo actual con los datos del nodo de valor mínimo.
      current->right = RemoveBranch(current->right, temp->data);
    }
  }
  // Devolviendo el nodo actual.
  return current;
}

//Buscando un dato en el árbol binario.
template <class Key> bool Abb<Key>::Find(const Key &data) const {
  Node<Key> *current = this->root_;
  while (current != nullptr) {
    if (*current == data)       // Comparando los datos del nodo actual con los datos que se están buscando.
      return true;
    if (current->data < data)   // Comprobando si los datos del nodo actual son menores que los datos que se están buscando, si es así.
      current = current->right; // Cambia el nodo actual al hijo derecho del nodo actual.
    if (current->data > data)   // Comprobando si los datos del nodo actual son mayores que los datos que se están buscando, si es así. 
      current = current->left; // Cambian el nodo actual al hijo izquierdo del nodo actual.
  }
  return false; // Devolviendo falso si los datos no se encuentran en el árbol.
}


template <class Key>
bool Abb<Key>::FindR(const Key &data, Node<Key> *current) const {
  // Comprobando si el nodo actual es nullptr. Si lo es, devuelve falso.
  if (!current)
    return false;

  // Comparando los datos del nodo actual con los datos que se están buscando.
  if (*current == data)
    return true;

  // Comprobando si los datos están en la rama izquierda o derecha.
  return FindR(data, current->left) || FindR(data, current->right);
}

template <class Key> bool Abb<Key>::Insert(const Key &data) {
  Node<Key> *current = this->root_; // Crear un puntero al nodo raíz del árbol.

  if (!current) {
    this->root_ = new Node<Key>(data); // Verificar si el nodo actual es nullptr. Si es así, crea un nuevo nodo con los datos y devuelve verdadero.

    return true;
  }

  // Este es un ciclo que verifica si los datos ya están en el árbol. 
  do {
    if (*current == data)
      return false;
    if (current->data < data) {   // Si lo es, devuelve falso. Si no es así, comprueba si los datos son inferiores a los datos actuales. 
      if (current->right)
        current = current->right;   // Si es así, comprueba si el nodo correcto es nullptr. Si no es así, cambia el nodo actual al nodo derecho. 
      else {
        current->right = new Node<Key>(data);   // Si es así, crea un nuevo nodo con los datos y devuelve verdadero. 
        return true;
      }
    }
    if (current->data > data) {   // Si los datos no son menores que los datos actuales, verifica si los datos son mayores que los datos actuales. 
      if (current->left)
        current = current->left;   // Si es así, comprueba si el nodo izquierdo es nullptr. Si no es así, cambia el nodo actual al nodo izquierdo. 
      else {
        current->left = new Node<Key>(data);  // Si es así, crea un nuevo nodo con los datos y devuelve verdadero.
        return true;
      }
    }
  } while (current != nullptr);

  return false; // Devolviendo falso si los datos no se encuentran en el árbol.
}

// Una función recursiva que devuelve la profundidad del árbol.
template <class Key> int Abb<Key>::Depth(Node<Key> *current) const {
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