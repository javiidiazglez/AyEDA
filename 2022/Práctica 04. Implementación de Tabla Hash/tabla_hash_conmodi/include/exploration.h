/*
  Universidad de La Laguna
  Escuela Superior de Ingeniería y Tecnología
  Grado en Ingeniería Informática          
  Algoritmos y Estructuras de datos Avanzados
  Fecha: 08/04/2022     
  Autor: José Javier Díaz González (alu0101128894)
  Práctica 4. Tabla Hash                            
  Referencias: https://es.wikipedia.org/wiki/Tabla_hash
  Nombre del archivo: exploration.h                 
*/

#ifndef EXPLORATION_H
#define EXPLORATION_H

#include <iostream>

template <class Key>
class Exploration { // Función Padre Exploracion
 public:
  Exploration(size_t size) : size_(size) {}
  virtual ~Exploration() {}
  virtual size_t operator()(const Key& key, size_t index) const = 0;

 protected:
  size_t size_;
};

#endif
