/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingenierıa Informatica
 * Asignatura: Algoritmos y Estructuras de Datos Avanzadas
 * Curso: 2º
 * Práctica 6: Arboles
 *
 * @author José Javier Díaz González
 * Correo: alu0101128894@ull.edu.es
 *
 * @date 3/05/2023
 * @file AVL.h: clase AVL
 * @brief Contiene la declaracion de la clase AVL
 **/

#pragma once

#include "ABB.h"
#include "NodeB.h"

template <typename Key>
class NodeAVL : public NodeB<Key> {
 private:
  int bal_;  // factor balanceo del nodo
 public:
  NodeAVL(const Key& k, NodeB<Key>* left = NULL, NodeB<Key>* right = NULL)
      : NodeB<Key>(k, left, right), bal_(0) {}
  ~NodeAVL() {}

  // convertir el puntero devuelto por getLeft() en un puntero a un objeto de la clase NodeAVL<Key>
  NodeAVL<Key>* get_left_avl() const { return reinterpret_cast<NodeAVL<Key>*>(this->getLeft()); }
  NodeAVL<Key>*& get_left_avl() { return reinterpret_cast<NodeAVL<Key>*&>(this->getLeft()); }
  NodeAVL<Key>* get_right_avl() const { return reinterpret_cast<NodeAVL<Key>*>(this->getRight()); }
  NodeAVL<Key>*& get_right_avl() { return reinterpret_cast<NodeAVL<Key>*&>(this->getRight()); }

  int getBal() const { return bal_; }
  void setBal(int bal) { bal_ = bal; }
};

template <typename Key>
class AVL : public ABB<Key> {
 public:
  AVL() : ABB<Key>(){};
  ~AVL(){};

  bool insertar(const Key& k);
  // void Insertar(const Key& k);
  NodeAVL<Key>* get_raiz_avl() const { return reinterpret_cast<NodeAVL<Key>*>(this->raiz_); }
  NodeAVL<Key>*& get_raiz_avl() { return reinterpret_cast<NodeAVL<Key>*&>(this->raiz_); }

 private:
  void insertarRama(const Key& k, NodeAVL<Key>* nodo, bool& crece);
  void inserta_bal(NodeAVL<Key>*& nodo, NodeAVL<Key>* nuevo, bool& crece);
  void insert_re_balancea_izda(NodeAVL<Key>*& nodo, bool& crece);
  void insert_re_balancea_dcha(NodeAVL<Key>*& nodo, bool& crece);
  void rotacion_II(NodeAVL<Key>*& nodo);
  void rotacion_DD(NodeAVL<Key>*& nodo);
  void rotacion_ID(NodeAVL<Key>*& nodo);
  void rotacion_DI(NodeAVL<Key>*& nodo);
};

template <typename Key>
bool AVL<Key>::insertar(const Key& k) {
  if (this->buscar(k)) return false;
  NodeAVL<Key>* nuevo = new NodeAVL<Key>(k);
  bool crece = false;
  inserta_bal(get_raiz_avl(), nuevo, crece);
  return true;
}

template <typename Key>
void AVL<Key>::inserta_bal(NodeAVL<Key>*& nodo, NodeAVL<Key>* nuevo, bool& crece) {
  if (nodo == NULL) {
    nodo = nuevo;
    crece = true;
  } else if (nuevo->getData() < nodo->getData()) {
    inserta_bal(nodo->get_left_avl(), nuevo, crece);    // El nodo hacia la izquierda
    if (crece) insert_re_balancea_izda(nodo, crece);    // Inserta rebalanceo izq
  } else {
    inserta_bal(nodo->get_right_avl(), nuevo, crece);   // El nodo hacia la derc
    if (crece) insert_re_balancea_dcha(nodo, crece);    // Inserta rebalanceo derc
  }
}

// ReBalanceo Izq
template <typename Key>
void AVL<Key>::insert_re_balancea_izda(NodeAVL<Key>*& nodo, bool& crece) {
  switch (nodo->getBal()) {
    case -1:
      nodo->setBal(0);    // El árbol se equilibró después de insertar un nuevo nodo en la rama izquierda.
      crece = false;      // El árbol no crece más después de la inserción.
      break;
    case 0:
      nodo->setBal(1);    // El árbol continúa creciendo después de la inserción.
      break;
    case 1:
      NodeAVL<Key>* nodo1 = nodo->get_left_avl();
      if (nodo1->getBal() == 1) {
        rotacion_II(nodo);   // Se realiza una rotación simple a la derecha para reequilibrar el árbol.
      } else {
        rotacion_ID(nodo);   // Se realiza una rotación doble a la derecha para reequilibrar el árbol.
      }
      crece = false;
      break;
  }
}
// ReBalanceo Derecha
template <typename Key>
void AVL<Key>::insert_re_balancea_dcha(NodeAVL<Key>*& nodo, bool& crece) {
  switch (nodo->getBal()) {
    case 1:
      nodo->setBal(0);
      crece = false;
      break;
    case 0:
      nodo->setBal(-1);
      break;
    case -1:
      NodeAVL<Key>* nodo1 = nodo->get_right_avl();
      if (nodo1->getBal() == -1) {
        rotacion_DD(nodo);
      } else {
        rotacion_DI(nodo);
      }
      crece = false;
      break;
  }
}

template <typename Key>
void AVL<Key>::rotacion_II(NodeAVL<Key>*& nodo) {
#ifdef TRAZA
  std::cout << "\033[0;33m" << "\nDesbalanceo" << "\033[0m" << std::endl;
  this->operator>>(std::cout);
  std::cout << "\033[0;33m" << "\nRotación II en [" << nodo->getData() << "]" << "\033[0m" << std::endl;
#endif

  NodeAVL<Key>* nodo1 = nodo->get_left_avl(); // Se obtiene un puntero al hijo izquierdo del nodo actual y se guarda en el nodo1
  nodo->setLeft(nodo1->getRight());           // Se establece el hijo derecho de nodo1 como nuevo hijo izquierdo de nodo
  nodo1->setRight(nodo);                      // Se establece nodo como el nuevo hijo derecho de nodo1
  if (nodo1->getBal() == 1) {                 // Si el bal es = 1, entonces se ajusta a nodo y nodo1 como bal 0
    nodo->setBal(0);
    nodo1->setBal(0);
  } else {
    nodo->setBal(1);                         // si no, nodo bal = 1, y nodo1, bal=-1
    nodo1->setBal(-1);
  }
  nodo = nodo1;
}

template <typename Key>
void AVL<Key>::rotacion_DD(NodeAVL<Key>*& nodo) {
#ifdef TRAZA
  std::cout << "\033[0;33m" << "\nDesbalanceo" << "\033[0m" << std::endl;
  this->operator>>(std::cout);
  std::cout << "\033[0;33m"  << "\nRotación DD en [" << nodo->getData() << "]"  << "\033[0m" << std::endl;
#endif

  NodeAVL<Key>* nodo1 = nodo->get_right_avl();  // Se obtiene un puntero al hijo derecho del nodo actual y se guarda en el nodo1
  nodo->setRight(nodo1->getLeft());             // Se establece el hijo izquierdo de nodo1 como nuevo hijo derecho de nodo
  nodo1->setLeft(nodo);                         // Se establece nodo como el nuevo hijo izquierdo de nodo1
  if (nodo1->getBal() == -1) {                  // Si el bal es = -1, entonces se ajusta a nodo y nodo1 como bal 0
    nodo->setBal(0);
    nodo1->setBal(0);
  } else {  
    nodo->setBal(-1);                           // si no, nodo bal = -1, y nodo1, bal=1
    nodo1->setBal(1);
  }
  nodo = nodo1;
}

template <typename Key>
void AVL<Key>::rotacion_ID(NodeAVL<Key>*& nodo) {
#ifdef TRAZA
  std::cout << "\033[0;33m" << "\nDesbalanceo"  << "\033[0m" << std::endl;
  this->operator>>(std::cout);
  std::cout << "\033[0;33m" << "\nRotación ID en [" << nodo->getData() << "]" << "\033[0m" << std::endl;
#endif

  NodeAVL<Key>* nodo1 = nodo->get_left_avl();   // Se obtiene un puntero al hijo izquierdo del nodo actual y se guarda en el nodo1
  NodeAVL<Key>* nodo2 = nodo1->get_right_avl(); // Se obtiene un puntero al hijo derecho del nodo actual y se guarda en el nodo2
  nodo->setLeft(nodo2->getRight());             // Establecer el subárbol izquierdo del nodo como el subárbol derecho del hijo derecho
  nodo2->setRight(nodo);                        // Establecer el hijo derecho del hijo derecho como el nodo actual
  nodo1->setRight(nodo2->getLeft());            // Establecer el subárbol derecho del hijo izquierdo como el subárbol izquierdo del hijo derecho
  nodo2->setLeft(nodo1);                        // Establecer el hijo izquierdo del hijo derecho como el hijo izquierdo del hijo izquierdo
  if (nodo2->getBal() == -1)                    // si bal = -1
    nodo1->setBal(1);
  else
    nodo1->setBal(0);                          // si bal = 0
  if (nodo2->getBal() == 1)
    nodo->setBal(-1);
  else
    nodo->setBal(0);
  nodo2->setBal(0);
  nodo = nodo2;
}

template <typename Key>
void AVL<Key>::rotacion_DI(NodeAVL<Key>*& nodo) {
#ifdef TRAZA
  std::cout << "\033[0;33m" << "\nDesbalanceo"  << "\033[0m" << std::endl;
  this->operator>>(std::cout);
  std::cout << "\033[0;33m" << "\nRotación DI en [" << nodo->getData() << "]" << "\033[0m" << std::endl;
#endif

  NodeAVL<Key>* nodo1 = nodo->get_right_avl();
  NodeAVL<Key>* nodo2 = nodo1->get_left_avl();
  nodo->setRight(nodo2->getLeft());
  nodo2->setLeft(nodo);
  nodo1->setLeft(nodo2->getRight());
  nodo2->setRight(nodo1);
  if (nodo2->getBal() == 1)
    nodo1->setBal(-1);
  else
    nodo1->setBal(0);
  if (nodo2->getBal() == -1)
    nodo->setBal(1);
  else
    nodo->setBal(0);
  nodo2->setBal(0);
  nodo = nodo2;
}

template <typename Key>
std::ostream& operator<<(std::ostream& os, const AVL<Key>& avl) {
  os << avl.get_raiz()->getData() << std::endl;
  return os;
}