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
 * @file ABB.h: clase ABB
 * @brief Contiene la declaracion de la clase ABB
 **/

#pragma once

#include "AB.h"
#include "NodeB.h"

template <typename Key>
class ABB : public AB<Key> {
 public:
  ABB() : AB<Key>(){};
  ~ABB(){};

  bool insertar(const Key& k);
  bool eliminar(const Key& k);

  virtual bool buscar(const Key& k) const;

 private:
  NodeB<Key>* buscarRama(const Key& k, NodeB<Key>* nodo) const;
  void insertarRama(const Key& k, NodeB<Key>* nodo);
  void eliminarRama(const Key& k, NodeB<Key>*& nodo);
};

template <typename Key>
NodeB<Key>* ABB<Key>::buscarRama(const Key& k, NodeB<Key>* nodo) const {
  if (nodo == nullptr) return nullptr;          // si el nodo es nulo, devuelve nulo
  if (k == nodo->getData()) return nodo;        // Si la clave es igual a la raiz, devuelve la raiz
  if (k < nodo->getData()) return buscarRama(k, nodo->getLeft()); // Si la clave k es menor que la clave del nodo actual devuelve para buscar la rama hacia la izquierda
  return buscarRama(k, nodo->getRight());     // caso contrario, hacia la derecha
}

template <typename Key>
bool ABB<Key>::buscar(const Key& k) const {
  return buscarRama(k, this->raiz_) != nullptr;
}

template <typename Key>
void ABB<Key>::insertarRama(const Key& k, NodeB<Key>* nodo) {
  if (k < nodo->getData()) {                 // Si la clave k es menor que la clave del nodo actual, se busca en el subárbol izquierdo.
    if (nodo->getLeft() != nullptr)         // Si el nodo izquierdo  no tiene hijos se marca como nulo e inserta por la izquierda
      insertarRama(k, nodo->getLeft());
    else                                    // marcamos hacia la izquierda
      nodo->setLeft(new NodeB<Key>(k));
  } else {
    if (nodo->getRight() != nullptr)        // Si el nodo derecho no tiene hijo, se marca como nulo e inserta por la derecha
      insertarRama(k, nodo->getRight());
    else
      nodo->setRight(new NodeB<Key>(k));
  }
}

template <typename Key>
bool ABB<Key>::insertar(const Key& k) {
  if (buscar(k)) return false;
  if (this->raiz_ == nullptr) {         // Si la raiz es nulo, crea un nuevo nodo
    this->raiz_ = new NodeB<Key>(k);
  } else
    insertarRama(k, this->raiz_);     // Inserta la rama
  return true;
}

template <typename Key>
void ABB<Key>::eliminarRama(const Key& k, NodeB<Key>*& nodo) {
  if (nodo == nullptr) return;              // Si el nodo actual es nulo, la clave k no se encontró en el árbol, así que se devuelve inmediatamente.

  if (k < nodo->getData()) {                // Si la clave k es menor que la clave del nodo actual, se busca en el subárbol izquierdo.
    eliminarRama(k, nodo->getLeft());
  } else if (k > nodo->getData()) {         // Si la clave k es mayor que la clave del nodo actual, se busca en el subárbol derecho.
    eliminarRama(k, nodo->getRight());
  } else {                                  // Si se encontró el nodo que contiene la clave k.
    if (nodo->getLeft() == nullptr && nodo->getRight() == nullptr) {     // Si el nodo no tiene hijos, simplemente se elimina y se marca como nulo.
      delete nodo;
      nodo = nullptr;
    } else if (nodo->getLeft() == nullptr) {         // Si el nodo tiene un único hijo derecho, se elimina y se sustituye por ese hijo.
      NodeB<Key>* temp = nodo;
      nodo = nodo->getRight();
      delete temp;
    } else if (nodo->getRight() == nullptr) {        // Si el nodo tiene un único hijo izquierdo, se elimina y se sustituye por ese hijo.
      NodeB<Key>* temp = nodo;
      nodo = nodo->getLeft();
      delete temp;
    } else {                                          // Si el nodo tiene 2 hijos, encuentra el sucesor, si es izq marca izq, si es derecho, marca derecho
      NodeB<Key>* sucesor = nodo->getRight();
      while (sucesor->getLeft() != nullptr) {
        sucesor = sucesor->getLeft();
      }
      nodo->setData(sucesor->getData());
      eliminarRama(sucesor->getData(), nodo->getRight());
    }
  }
}

template <typename Key>
bool ABB<Key>::eliminar(const Key& k) {
  if (!buscar(k)) return false;
  eliminarRama(k, this->raiz_);     // elimina la rama
  return true;
}
