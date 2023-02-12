/*
  Universidad de La Laguna
  Escuela Superior de Ingeniería y Tecnología
  Grado en Ingeniería Informática          
  Algoritmos y Estructuras de datos Avanzados
  Fecha: 29/04/2022     
  Autor: José Javier Díaz González (alu0101128894)
  Práctica 5. Ordenación                           
  Referencias: https://es.wikipedia.org/wiki/Algoritmo_de_ordenamiento 
  Nombre del archivo: sacudida.h                  
*/

#ifndef SACUDIDA_H
#define SACUDIDA_H

#include "algorithm.h"

template <class Clave>
class sacudida : public Algorithm<Clave> {
 private:
  std::vector<Clave> sacudida_v;
  int sacudida_sz;

 public:
  using Algorithm<Clave>::Algorithm;
  std::vector<Clave> metodo(std::vector<Clave> a, int sz);
  void swap_pos(int i, int j);
};

template <class Clave>
std::vector<Clave> sacudida<Clave>::metodo(std::vector<Clave> a, int sz) {
  int contador_swap = 0;
  int contador_global = 0;
  sacudida_v = a;
  sacudida_sz = sz;
  int inicial = 1, fin = sacudida_sz - 1, cambio = sacudida_sz;
  while (inicial < fin) {
    for (int j = fin; j >= inicial; j--) {
      if (sacudida_v[j] < sacudida_v[j - 1]) {
        swap_pos(j, j - 1);
        cambio = j;
      }
      contador_global++;
    }
    inicial = cambio + 1;
    for (int j = inicial; j <= fin; j++) {
      if (sacudida_v[j] < sacudida_v[j - 1]) {
        swap_pos(j, j - 1);
        cambio = j;
      }
      contador_global++;
    }
    fin = cambio - 1;
  }
  //std::cout << std::endl;

  return sacudida_v;
}

template <class Clave>
void sacudida<Clave>::swap_pos(int i, int j) {
  // contador_swap++;
  Clave aux = sacudida_v[i];
  sacudida_v[i] = sacudida_v[j];
  sacudida_v[j] = aux;

  std::cout << std::endl << "< ";
  for (int h = 0; h < sacudida_sz; h++) {
    if (h == i) {
      std::cout << "\033[1;31m" << sacudida_v[h] << "\033[0m, ";
    }
    if (h == j) {
      std::cout << "\033[1;32m" << sacudida_v[h] << "\033[0m, ";
    }
    if (h != i && h != j) {
      std::cout << sacudida_v[h] << ", ";
    }
  }
  std::cout << ">";
  //std::cout << std::endl;
}

#endif