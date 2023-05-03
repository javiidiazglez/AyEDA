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
 * @file AB.h: clase AB
 * @brief Contiene la declaracion de la clase AB
 **/

#pragma once

#include <iostream>
#include <queue>

#include "NodeB.h"

template <typename Key>
class AB {
 protected:
  NodeB<Key>* raiz_;

 public:
  virtual ~AB() { Podar(raiz_); };
  AB() : raiz_(nullptr){};
  AB(NodeB<Key>* raiz) : raiz_(raiz){};
  // Getter
  NodeB<Key>* get_raiz() const { return raiz_; }
  NodeB<Key>*& get_raiz() { return raiz_; }
  // Virtual
  virtual bool insertar(const Key& k) = 0;
  virtual bool buscar(const Key& k) const = 0;
  virtual bool eliminar(const Key& k) = 0;

  std::ostream& operator>>(std::ostream& os);

  // IRD
  void inorden(NodeB<Key>* nodo) const {
    if (nodo == nullptr) return;
    inorden(nodo->getLeft());
    std::cout << nodo->getData() << " ";
    inorden(nodo->getRight());
  }
  // RID
  void preorden(NodeB<Key>* nodo) const {
    if (nodo == nullptr) return;
    std::cout << nodo->getData() << " ";
    preorden(nodo->getLeft());
    preorden(nodo->getRight());
  }
  // IDR
  void postorden(NodeB<Key>* nodo) const {
    if (nodo == nullptr) return;
    postorden(nodo->getLeft());
    postorden(nodo->getRight());
    std::cout << nodo->getData() << " ";
  }

 private:
  void Podar(NodeB<Key>* nodo);
};

template <typename Key>
void AB<Key>::Podar(NodeB<Key>* nodo) {
  if (nodo == NULL) return;
  Podar(nodo->getLeft());
  Podar(nodo->getRight());
  delete nodo;
  nodo = nullptr;
}

template <typename Key>
std::ostream& AB<Key>::operator>>(std::ostream& os) {
  std::queue<std::pair<NodeB<Key>*, int>> Q;
  std::pair<NodeB<Key>*, int> aux_Q;
  NodeB<Key>* nodo;
  int nivel, Nivel_actual = 0;

  aux_Q.first = get_raiz();
  aux_Q.second = 0;
  Q.push(aux_Q);

  os << "\nNivel 0: ";
  while (!Q.empty()) {
    aux_Q = Q.front();
    nodo = aux_Q.first;
    nivel = aux_Q.second;
    Q.pop();

    if (nivel > Nivel_actual) {  // Incremento de nivel
      Nivel_actual = nivel;
      os << "\nNivel " << Nivel_actual << ": ";
    }

    if (nodo != NULL) {
      os << "[" << nodo->getData() << "]";      // Raiz
      aux_Q.second = nivel + 1;
      aux_Q.first = nodo->getLeft();            // Izq
      Q.push(aux_Q);
      aux_Q.first = nodo->getRight();           // Der
      Q.push(aux_Q);
    } else {
      os << "[.]";  // Subarbol vacío
    }
  }
  os << std::endl;

  return os;
}
