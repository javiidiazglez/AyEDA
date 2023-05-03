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
 * @file NodeB.h: clase NodeB
 * @brief Contiene la declaracion de la clase NodeB
 **/

#pragma once

#include <iostream>

template <typename Key>
class NodeB {
 protected:
  Key data_;
  NodeB<Key>* left_;
  NodeB<Key>* right_;

 public:
  NodeB(const Key& k, NodeB<Key>* left = NULL, NodeB<Key>* right = NULL)
      : data_(k), left_(left), right_(right) {}
  ~NodeB() {}

  // Getters
  Key getData() const { return data_; }
  NodeB<Key>* getLeft() const { return left_; }
  NodeB<Key>* getRight() const { return right_; }
  NodeB<Key>*& getLeft() { return left_; }
  NodeB<Key>*& getRight() { return right_; }
  
  // Setters
  void setData(const Key& k) { data_ = k; }
  void setLeft(NodeB<Key>* left) { left_ = left; }
  void setRight(NodeB<Key>* right) { right_ = right; }
};

template <typename Key>
std::ostream& operator<<(std::ostream& os, const NodeB<Key>& node) {
  os << "[" << node.getData() << "]";
  return os;
}