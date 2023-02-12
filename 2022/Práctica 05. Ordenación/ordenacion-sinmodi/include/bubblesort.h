/*
  Universidad de La Laguna
  Escuela Superior de Ingeniería y Tecnología
  Grado en Ingeniería Informática          
  Algoritmos y Estructuras de datos Avanzados
  Fecha: 29/04/2022     
  Autor: José Javier Díaz González (alu0101128894)
  Práctica 5. Ordenación                           
  Referencias: https://es.wikipedia.org/wiki/Algoritmo_de_ordenamiento 
  Nombre del archivo: bubblesort.h                  
*/

#ifndef BUBBLESORT_H
#define BUBBLESORT_H

#include "algorithm.h"

template <class Clave>
class bubblesort : public Algorithm<Clave> {
 public:
  using Algorithm<Clave>::Algorithm;
  std::vector<Clave> metodo(std::vector<Clave> a, int sz);
  void swap_pos(int, int);

 private:
  std::vector<Clave> bubble_v;
  int bubble_sz;
};

template <class Clave>
std::vector<Clave> bubblesort<Clave>::metodo(std::vector<Clave> a, int sz) {
  int contador_swap = 0;
  bubble_v = a;
  bubble_sz = sz;
  int contador_global = 0;
  for (int i = 1; i < bubble_sz; i++) {
    for (int j = bubble_sz - 1; j >= i; j--) {
      if (bubble_v[j] < bubble_v[j - 1]) {
        swap_pos(j, j - 1);
      }
      contador_global++;
    }
  }
  return bubble_v;
}

template <class Clave>
void bubblesort<Clave>::swap_pos(int i, int j) {
  if (i != j) {
    // contador_swap++;
    Clave aux = bubble_v[i];
    bubble_v[i] = bubble_v[j];
    bubble_v[j] = aux;

    std::cout << std::endl << "< ";
    for (int h = 0; h < bubble_sz; h++) {
      if (h == i) {
        std::cout << "\033[1;31m" << bubble_v[h] << "\033[0m, ";
      }
      if (h == j) {
        std::cout << "\033[1;32m" << bubble_v[h] << "\033[0m, ";
      }
      if (h != i && h != j) {
        std::cout << bubble_v[h] << ", ";
      }
    }
    std::cout << ">";
    // cout << endl;
  }
}

#endif
