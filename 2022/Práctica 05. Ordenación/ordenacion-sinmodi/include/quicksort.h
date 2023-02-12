/*
  Universidad de La Laguna
  Escuela Superior de Ingeniería y Tecnología
  Grado en Ingeniería Informática          
  Algoritmos y Estructuras de datos Avanzados
  Fecha: 29/04/2022     
  Autor: José Javier Díaz González (alu0101128894)
  Práctica 5. Ordenación                           
  Referencias: https://es.wikipedia.org/wiki/Algoritmo_de_ordenamiento 
  Nombre del archivo: quicksort.h                  
*/

#ifndef QUICKSORT_H
#define QUICKSORT_H

#include "algorithm.h"

template <class Clave>
class quicksort : public Algorithm<Clave> {
 public:
  using Algorithm<Clave>::Algorithm;
  ~quicksort() {}

  std::vector<Clave> metodo(std::vector<Clave> a, int sz);
  void quickie(int inicial, int fin);
  void swap_pos(int i, int j);
  void show_quickie(int i, int h);

 private:
  int Quicksort_sz;
};

template <class Clave>
std::vector<Clave> quicksort<Clave>::metodo(std::vector<Clave> a, int sz) {
  this->vector_ = a;
  Quicksort_sz = sz;
  quickie(0, Quicksort_sz - 1);
  return this->vector_;
}

template <class Clave>
void quicksort<Clave>::quickie(int inicial, int fin) {
  Clave p;
  int i, f;
  i = inicial;
  f = fin;
  if (fin == (inicial + 1)) {
    if (this->vector_[fin] < this->vector_[inicial]) {
      swap_pos(fin, inicial);
    }
    return;
  }
  p = this->vector_[(i + f) / 2];

  while (i < f) {
    while (this->vector_[i] < p) {
      show_quickie(i, (i + f) / 2);
      i++;
      // contador_global++;
    }
    while (p < this->vector_[f]) {
      show_quickie(f, (i + f) / 2);
      f--;
      // contador_global++;
    }
    if (i < f) {
      swap_pos(i, f);
      i++;
      f--;
    }
  }

  if (inicial < f) quickie(inicial, f);
  if (i < fin) quickie(i, fin);
}

template <class Clave>
void quicksort<Clave>::swap_pos(int i, int j) {
  if (i != j) {
    Clave aux = this->vector_[i];
    this->vector_[i] = this->vector_[j];
    this->vector_[j] = aux;
    if (true) {
      std::cout << std::endl << "< ";
      for (int h = 0; h < Quicksort_sz; h++) {
        if (h == i) {
          std::cout << "\033[1;31m" << this->vector_[h] << "\033[0m, ";
        }
        if (h == j) {
          std::cout << "\033[1;32m" << this->vector_[h] << "\033[0m, ";
        }
        if (h != i && h != j) {
          std::cout << this->vector_[h] << ", ";
        }
      }
      std::cout << ">";
      // std::cout << std::endl;
    }
  }
}

template <class Clave>
void quicksort<Clave>::show_quickie(int i, int h) {
  if (i != h) {
    std::cout << std::endl << "< ";
    for (int j = 0; j < Quicksort_sz; j++) {
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
