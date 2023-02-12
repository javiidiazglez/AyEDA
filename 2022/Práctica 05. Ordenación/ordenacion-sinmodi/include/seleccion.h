/*
  Universidad de La Laguna
  Escuela Superior de Ingeniería y Tecnología
  Grado en Ingeniería Informática          
  Algoritmos y Estructuras de datos Avanzados
  Fecha: 29/04/2022     
  Autor: José Javier Díaz González (alu0101128894)
  Práctica 5. Ordenación                           
  Referencias: https://es.wikipedia.org/wiki/Algoritmo_de_ordenamiento 
  Nombre del archivo: seleccion.h                  
*/

#ifndef SELECCION_H
#define SELECCION_H

#include "algorithm.h"

template <class Clave>
class seleccion : public Algorithm<Clave> {
 public:
  using Algorithm<Clave>::Algorithm;
  ~seleccion() {}
  std::vector<Clave> metodo(std::vector<Clave> a, int sz);
  void swap_pos(int i, int j);

 private:
  int select_sz;
};

template <class Clave>
std::vector<Clave> seleccion<Clave>::metodo(std::vector<Clave> a, int sz) {
  // int contador_global=0;	// establecemos el contador a 0
  this->vector_ = a;  // guardamos el this->vector_ y su size
  select_sz = sz;

  // ejecucion del algortimo
  int min = 0;
  for (int i = 0; i < (sz - 1); i++) {
    min = i;
    for (int j = i + 1; j < sz; j++) {
      if (this->vector_[j] < this->vector_[min]) {
        min = j;
      }
      // contador_global++;
    }
    swap_pos(min, i);
  }
  return this->vector_;
}

template <class Clave>
void seleccion<Clave>::swap_pos(int i, int j) {
  if (i != j) {
    Clave aux;
    aux = this->vector_[i];
    this->vector_[i] = this->vector_[j];
    this->vector_[j] = aux;
    std::cout << std::endl << "< ";
    for (int h = 0; h < select_sz; h++) {
      if (h == i) {
        std::cout << "\033[1;31m" << this->vector_[h] << "\033[0m, ";  // rojo, select, reset
      }
      if (h == j) {
        std::cout << "\033[1;32m" << this->vector_[h] << "\033[0m, ";  // verde, select, reset
      }
      if (h != i && h != j) {
        std::cout << this->vector_[h] << ", ";
      }
    }
    std::cout << ">";
    // std::cout << std::endl;
  }
}

#endif
