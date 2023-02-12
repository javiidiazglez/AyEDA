/*
  Universidad de La Laguna
  Escuela Superior de Ingeniería y Tecnología
  Grado en Ingeniería Informática          
  Algoritmos y Estructuras de datos Avanzados
  Fecha: 29/04/2022     
  Autor: José Javier Díaz González (alu0101128894)
  Práctica 5. Ordenación                           
  Referencias: https://es.wikipedia.org/wiki/Algoritmo_de_ordenamiento 
  Nombre del archivo: algorithm.h                  
*/

#ifndef ALGORITHM_H
#define ALGORITHM_H

#include <iostream>
#include <vector>

template <class Clave>
class Algorithm {
 public:
  Algorithm() : vector_() {}
  virtual ~Algorithm() {}
  virtual std::vector<Clave> metodo(std::vector<Clave> a, int sz) = 0;

 protected:
  std::vector<Clave> vector_; // vector_ (padre)
};
 
#endif
