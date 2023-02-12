/*
  Universidad de La Laguna
  Escuela Superior de Ingeniería y Tecnología
  Grado en Ingeniería Informática          
  Algoritmos y Estructuras de datos Avanzados
  Fecha: 29/04/2022     
  Autor: José Javier Díaz González (alu0101128894)
  Práctica 5. Ordenación                           
  Referencias: https://es.wikipedia.org/wiki/Algoritmo_de_ordenamiento 
  Nombre del archivo: insercion.h                  
*/

#ifndef INSERCION_H
#define INSERCION_H

#include "algorithm.h"

template <class Clave>
class insercion : public Algorithm<Clave> {
 public:
  using Algorithm<Clave>::Algorithm;
  ~insercion() {}
  std::vector<Clave> metodo(std::vector<Clave> a, int sz);
  void show_changes(int, int);

 private:
  int insercion_sz;
};

template <class Clave>
std::vector<Clave> insercion<Clave>::metodo(std::vector<Clave> a, int sz) {
  // int contador_global=0;
  this->vector_ = a;
  insercion_sz = sz;

  int i, j;
  Clave key;
  for (i = 1; i < insercion_sz; i++) {
    key = this->vector_[i];
    j = i - 1;

    while (j >= 0 && this->vector_[j] > key) {
      show_changes(j + 1, j);
      this->vector_[j + 1] = this->vector_[j];
      j--;
      // contador_global++;
    }
    this->vector_[j + 1] = key;
  }
  // std::cout << "Contador_global: " << contador_global << std::endl;
  return this->vector_;
}

template <class Clave>
void insercion<Clave>::show_changes(int i, int h) {
  if (i != h) {
    std::cout << std::endl << "< ";
    for (int j = 0; j < insercion_sz; j++) {
      if (j == i) {
        std::cout << "\033[1;32m" << this->vector_[j] << "\033[0m, ";
      }
      if (j == h) {
        std::cout << "\033[1;31m" << this->vector_[j] << "\033[0m, ";
      }
      if (i != j && j != h) {
        std::cout << this->vector_[j] << ", ";
      }
    }
    std::cout << ">";
    // std::cout << std::endl;
  }
}

#endif
