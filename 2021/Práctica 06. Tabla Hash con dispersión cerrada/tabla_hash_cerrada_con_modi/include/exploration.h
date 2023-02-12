//////////////////////////////////////////////////////////////////////////////////
// Universidad de La Laguna                                                     //
// Escuela Superior de Ingeniería y Tecnología                                  //
// Grado en Ingeniería Informática                                              //
// Algoritmos y Estructuras de datos Avanzados                                  //
// Fecha: 16/04/2021                                                            //
// Autor: José Javier Díaz González (alu0101128894)                             //
//                                                                              //
// Práctica 7. Tabla Hash con dispersión cerrada                                //
// Referencias: https://es.wikipedia.org/wiki/Tabla_hash                        //
// Nombre del archivo: exploration.h                                            //
//////////////////////////////////////////////////////////////////////////////////

#ifndef EXPLORATION_H
#define EXPLORATION_H

#include <iostream>

template <class Key>
class Exploration {
 public:
  Exploration(size_t size) : size_(size) {}
  virtual ~Exploration() {}
  virtual size_t operator()(const Key& key, size_t index) const = 0;

 protected:
  size_t size_;
};

#endif
