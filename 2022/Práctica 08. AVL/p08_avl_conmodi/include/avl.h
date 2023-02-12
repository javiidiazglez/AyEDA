/*
  Universidad de La Laguna
  Escuela Superior de Ingeniería y Tecnología
  Grado en Ingeniería Informática          
  Algoritmos y Estructuras de datos Avanzados
  Fecha: 25/05/2022     
  Autor: José Javier Díaz González (alu0101128894)
  Práctica 8: Implementación de árboles binarios de búsqueda balanceado (AVL)                       
  Referencias: https://es.wikipedia.org/wiki/%C3%81rbol_binario
  Nombre del archivo: avl.h                  
*/

#ifndef AVL_H
#define AVL_H

#include <cstddef>
#include <exception>
#include <iostream>
#include <vector>

#include "ab.h"
#include "node.h"

bool trace = false;

template <class Key>
class Avl : public Ab<Key> {
 public:
  Avl() = default;
  ~Avl() = default;

  int Depth(Node<Key> *current) const;
  bool Insert(const Key &data) override;
  bool Find(const Key &data) const override;
  bool Remove(const Key &data) override;

 private:
  bool FindR(const Key &data, Node<Key> *current) const;
  Node<Key> *RemoveBranch(Node<Key> *&current, const Key &data);
  Node<Key> *MinimumValueNode(Node<Key> *current);

  void InsertBal(Node<Key> *&node, Node<Key> *new_node, bool &increase);
  void InsertReBalLeft(Node<Key> *&node, bool &increase);
  void InsertReBalRight(Node<Key> *&node, bool &increase);

// El código anterior son las cuatro rotaciones que se utilizan en el árbol AVL.
  void RotationII(Node<Key> *&node);
  void RotationDD(Node<Key> *&node);
  void RotationID(Node<Key> *&node);
  void RotationDI(Node<Key> *&node);

  void DeleteBranch(Node<Key> *&node, Key data, bool &decrease); // Eliminación de un nodo del árbol.
  void DeleteRecBalRight(Node<Key> *&node, bool &decrease);
  void DeleteRecBalLeft(Node<Key> *&node, bool &decrease);
  void Replace(Node<Key> *&deleted, Node<Key> *&sust, bool &decrease); // Reemplazando el nodo a eliminar por el nodo que lo va a reemplazar.

  bool deleted_;
  bool inserted_;
};

template <class Key>
bool Avl<Key>::Insert(const Key &data) {
  Node<Key> *new_node = new Node<Key>(data); // Creando un nuevo nodo con los datos pasados como parámetro.
  bool increase = false;
  inserted_ = false;
  InsertBal(this->root_, new_node, increase); // Llamar a la función InsertBal con los parámetros root_, new_node y aumentar.
  return inserted_;
}

template <class Key>
bool Avl<Key>::Find(const Key &data) const {
  Node<Key> *current = this->root_; // Crear un puntero a la raíz del árbol.
  while (current != nullptr) {      // Comprobando si el nodo actual es nullptr.
    if (*current == data) return true; // Comprobando si el nodo actual es igual a los datos
    if (current->data < data) current = current->right; // Comprobar si los datos son mayores que el nodo actual, si lo es, va al nodo derecho
    if (current->data > data) current = current->left;  // Si no lo es, va a el nodo izquierdo.
  }
  return false;
}

template <class Key>
bool Avl<Key>::Remove(const Key &data) {
  bool decrease = false;
  deleted_ = false;
  DeleteBranch(this->root_, data, decrease); // Llamando a la función DeleteBranch con los parámetros raíz_, datos y disminución.
  return deleted_;
}

template <class Key>
void Avl<Key>::InsertBal(Node<Key> *&node, Node<Key> *new_node, bool &increase) {
  if (node == nullptr) { // Comprobando si el nodo actual es nullptr.
    node = new_node;    // Asignación del nuevo nodo al nodo actual.
    increase = true;    // El código anterior está creando una variable llamada aumento y estableciéndola en verdadero.

    // 1. Está comprobando si el nodo es un nodo hoja.
    // 2. Si es un nodo hoja, está insertando la clave y el valor en el nodo.
    // 3. Si no es un nodo hoja, está llamando a la función de inserción en el nodo secundario.
    // 4. Si el nodo secundario está lleno, se está dividiendo el nodo secundario.
    // 5. Está insertando la clave y el valor en el nodo.
    inserted_ = true;
  } else if (new_node->data < node->data) {

    // 1. Si el nodo es NULL, el new_node se inserta en esa posición.
    // 2. Si el nodo no es NULL, se inserta new_node en el subárbol izquierdo.
    // 3. La variable de aumento se pasa al subárbol izquierdo.
    InsertBal(node->left, new_node, increase);
    if (increase) InsertReBalLeft(node, increase);
  } else if (new_node->data > node->data) {
    
    // 1. Si el nodo es NULL, se inserta new_node.
    // 2. Si el nodo no es NULL, entonces el new_node se inserta a la  derecha del nodo.
    // 3. Si el nodo no es NULL, entonces el aumento se establece en 1.
    InsertBal(node->right, new_node, increase);
    if (increase) InsertReBalRight(node, increase); // Comprobando si el nodo está equilibrado. Si no es así, reequilibrará el árbol.
  } else {
    delete new_node; // Crear un nuevo nodo, asignarle un valor y luego eliminarlo.
    inserted_ = false;
  }
}

template <class Key>
void Avl<Key>::InsertReBalLeft(Node<Key> *&node, bool &increase) {
  Node<Key> *node1;
  switch (node->bal) {
    case -1:
      node->bal = 0;
      increase = false;
      break;
    case 0:
      node->bal = 1;
      break;
    case 1:
      if (trace) {
        std::cout << "\nDesbalanceo:";
        this->Print();
      }
      node1 = node->left; // Node1 es un puntero al nodo izquierdo del nodo actual.
      if (node1->bal == 1)
        RotationII(node); // Girando el árbol a la derecha.
      else
        RotationID(node); // Llamar a la función RotationID() y pasar el nodo como argumento.

      increase = false;
      if (trace) {
        this->Print();
        std::cout << std::endl;
      }
      break;
  }
}

template <class Key>
void Avl<Key>::InsertReBalRight(Node<Key> *&node, bool &increase) {
  Node<Key> *node1;
  switch (node->bal) {
    case 1:
      node->bal = 0;
      increase = false;
      break;
    case 0:
      node->bal = -1;
      break;
    case -1:
      if (trace) {
        std::cout << "\nDesbalanceo:";
        this->Print();
      }
      node1 = node->right; // Asignando el nodo derecho del nodo actual al nodo1.
      if (node1->bal == -1)
        RotationDD(node);
      else
        RotationDI(node);
      increase = false;
      if (trace) {
        this->Print();
        std::cout << std::endl;
      }
      break;
  }
}

template <class Key>
void Avl<Key>::DeleteBranch(Node<Key> *&node, Key X, bool &decrease) {
  if (node == nullptr) return;
  if (X < node->data) {
    DeleteBranch(node->left, X, decrease); // Eliminación de la rama izquierda del nodo.
    if (decrease) DeleteRecBalLeft(node, decrease); // Eliminando el nodo y luego equilibrando el árbol.
  } else if (X > node->data) { // Si el valor de X es mayor que el valor del nodo, entonces el valor de X es mayor que el valor del nodo.
    DeleteBranch(node->right, X, decrease);
    if (decrease) DeleteRecBalRight(node, decrease);
  } else {
    deleted_ = true;
    Node<Key> *deleted = node;
    if (node->left == nullptr) {
      node = node->right; // Asignación del nodo derecho al nodo actual.
      decrease = true;
    } else if (node->right == nullptr) { // Si el nodo no tiene un hijo derecho, entonces el nodo se reemplaza por su hijo izquierdo.
      node = node->left;
      decrease = true;
    } else {
      Replace(deleted, node->left, decrease);
      if (decrease) DeleteRecBalLeft(node, decrease); // Borrando el nodo y balanceando el árbol.
    }
    delete deleted; // Borrando el nodo que ha sido borrado.
  }
}

template <class Key>
void Avl<Key>::DeleteRecBalLeft(Node<Key> *&node, bool &decrease) {
  Node<Key> *node1;
  switch (node->bal) {
    case -1:
      // Equilibrar el árbol después de una eliminación.
      if (trace) {
        std::cout << "\nDesbalanceo:";
        this->Print();
        std::cout << std::endl;
      }
      node1 = node->right;
      if (node1->bal > 0)
        RotationDI(node);
      else {
        if (node1->bal == 0) decrease = false;
        RotationDD(node);
      }
      if (trace) {
        this->Print();
        std::cout << std::endl;
      }
      break;
    case 0:
      node->bal = -1;
      decrease = false;
      break;
    case 1:
      node->bal = 0;
  }
}

template <class Key>
void Avl<Key>::DeleteRecBalRight(Node<Key> *&node, bool &decrease) {
  Node<Key> *node1;
  switch (node->bal) {
    case 1:
      if (trace) {
        std::cout << "\nDesbalanceo:";
        this->Print();
        std::cout << std::endl;
      }
      node1 = node->left;
      if (node1->bal < 0)
        RotationID(node);
      else {
        if (node1->bal == 0) decrease = false;
        RotationII(node);
      }
      if (trace) {
        this->Print();
        std::cout << std::endl;
      }
      break;
    case 0:
      node->bal = 1;
      decrease = false;
      break;
    case -1:
      node->bal = 0;
      break;
  }
}
// Reemplazo del nodo eliminado con el nodo sucesor.
template <class Key>
void Avl<Key>::Replace(Node<Key> *&deleted, Node<Key> *&sust, bool &decrease) {
  if (sust->right != nullptr) {

    // El código anterior está reemplazando el nodo eliminado con el nodo sucesor.
    // El nodo sucesor es el nodo más a la izquierda en el subárbol derecho del nodo eliminado.
    // El nodo sucesor es el nodo más pequeño del subárbol derecho del nodo eliminado.
    // El nodo sucesor es el hijo derecho del nodo eliminado.
    // El nodo sucesor es el hijo izquierdo del nodo eliminado.
    // El nodo sucesor es el padre del nodo eliminado.
    // El nodo sucesor es el nodo más a la derecha en el subárbol izquierdo del nodo eliminado.
    Replace(deleted, sust->right, decrease); 
    if (decrease) DeleteRecBalRight(sust, decrease); // Eliminar el nodo que está siendo reemplazado por el sucesor.
  } else {
    deleted->data = sust->data; // Copiar los datos del nodo que se eliminará al nodo que lo reemplazará.
    
    // El código anterior está eliminando el nodo al que apunta el puntero sust.
    // El puntero sust apunta al nodo al que apunta el puntero eliminado
    deleted = sust;
    sust = sust->left; // Comprobando si el nodo a eliminar es un nodo hoja. Si es así, entonces se elimina.
    decrease = true; 
  }
}

template <class Key>
void Avl<Key>::RotationII(Node<Key> *&node) {
  if (trace) {
    std::cout << "\033[0;34m" << "\n➔  Rotacion II en [" << node->data << "]" << "\033[0m";
  }
  Node<Key> *node1 = node->left; // Asignando el nodo izquierdo del nodo actual al nodo1.
  node->left = node1->right;     // Asignando el nodo izquierdo del nodo actual al nodo derecho del nodo1.
  node1->right = node;           // Asignando el nodo a la derecha del nodo1 al nodo.
  if (node1->bal == 1) {
    node->bal = 0;
    node1->bal = 0;
  } else {
    node->bal = 1;
    node1->bal = -1;
  }
  node = node1;
}

template <class Key>
void Avl<Key>::RotationDD(Node<Key> *&node) {
  if (trace) {
    std::cout << "\033[0;34m" << "\n➔  Rotacion DD en [" << node->data << "]" << "\033[0m";
  }
  Node<Key> *node1 = node->right; // Asignando el nodo derecho del nodo actual al nodo1.
  node->right = node1->left;      // Asignando el nodo izquierdo del nodo1 al nodo derecho del nodo.
  node1->left = node;             // Asignando el nodo izquierdo del nodo1 al nodo.
  if (node1->bal == -1) {
    node->bal = 0;
    node1->bal = 0;
  } else {
    node->bal = -1;
    node1->bal = 1;
  }
  node = node1;
}

template <class Key>
void Avl<Key>::RotationID(Node<Key> *&node) {
  if (trace) {
    std::cout << "\033[0;34m" <<"\n➔  Rotacion ID en [" << node->data << "]" << "\033[0m";
  }
  Node<Key> *node1 = node->left;   // Asignando el nodo izquierdo del nodo actual al nodo1.
  Node<Key> *node2 = node1->right; // Asignando el nodo derecho del nodo actual al nodo2.
  node->left = node2->right;       // Asignando el nodo izquierdo del nodo actual al nodo derecho del nodo2.
  node2->right = node;             // Asignando el nodo a la derecha del nodo2 al nodo.
  node1->right = node2->left;      // Asignando el nodo izquierdo del nodo2 al nodo derecho del nodo1.
  node2->left = node1;             // Asignando el nodo1 a la izquierda del nodo2.
  if (node2->bal == -1)
    node1->bal = 1;
  else
    node1->bal = 0;

  if (node2->bal == 1)
    node->bal = -1;
  else
    node->bal = 0;

  node2->bal = 0;
  node = node2;
}

template <class Key>
void Avl<Key>::RotationDI(Node<Key> *&node) {
  if (trace) {
    std::cout << "\033[0;34m" <<"\n➔  Rotacion DI en [" << node->data << "]" << "\033[0m";
  }
  Node<Key> *node1 = node->right; // Asignando el nodo derecho del nodo actual al nodo1.
  Node<Key> *node2 = node1->left; // Asignando el nodo izquierdo del nodo actual al nodo2.
  node->right = node2->left;      // Asignando el nodo izquierdo del nodo2 al nodo derecho del nodo.
  node2->left = node;             // Asignando el nodo a la izquierda del nodo2 al nodo.
  node1->left = node2->right;     // Asignando el nodo izquierdo del nodo1 al nodo derecho del nodo2.
  node2->right = node1;           // Asignando el nodo1 a la derecha del nodo2.
  if (node2->bal == 1)
    node1->bal = -1;
  else
    node1->bal = 0;

  if (node2->bal == -1)
    node->bal = 1;
  else
    node->bal = 0;

  node2->bal = 0;
  node = node2;
}

#endif