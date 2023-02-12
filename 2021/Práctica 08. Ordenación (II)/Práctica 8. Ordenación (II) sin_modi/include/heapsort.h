//////////////////////////////////////////////////////////////////////////////////
// Universidad de La Laguna                                                     //
// Escuela Superior de Ingeniería y Tecnología                                  //
// Grado en Ingeniería Informática                                              //
// Algoritmos y Estructuras de datos Avanzados                                  //
// Fecha: 28/04/2021                                                            //
// Autor: José Javier Díaz González (alu0101128894)                             //
//                                                                              //
// Práctica 8. Ordenación (II)                                                  //
// Referencias: https://es.wikipedia.org/wiki/Algoritmo_de_ordenamiento         //
// Nombre del archivo: heapsort.h                                               //
//////////////////////////////////////////////////////////////////////////////////

#ifndef HEAPSORT_H
#define HEAPSORT_H

#include "algorithm.h"

template <typename Type>
class heapsort : public Algorithm<Type> {
 public:
  using Algorithm<Type>::Algorithm;
  ~heapsort() {}
  std::vector<Type> metodo(std::vector<Type> a, int sz);
  void baja(int i, int sz);
  void swap_pos(int i, int j);

 private:
  int heap_sz;
};

template <typename Type>
std::vector<Type> heapsort<Type>::metodo(std::vector<Type> a, int sz) {
  this->vector_ = a;
  heap_sz = sz;
  for (int i = heap_sz / 2 - 1; i >= 0; i--) {
    baja(i, heap_sz);
  }
  for (int i = heap_sz - 1; i >= 0; i--) {
    swap_pos(0, i);
    baja(0, i);
  }
  return this->vector_;
}

template <typename Type>
void heapsort<Type>::baja(int i, int sz) {
  int largest = i;
  int l = 2 * i + 1;
  int r = 2 * i + 2;
  if (l < sz && this->vector_[l] > this->vector_[largest]) largest = l;
  // contador_global++;
  if (r < sz && this->vector_[r] > this->vector_[largest]) largest = r;
  // contador_global++;
  if (largest != i) {
    swap_pos(i, largest);
    baja(largest, sz);
  }
  // contador_global++;
}

template <typename Type>
void heapsort<Type>::swap_pos(int i, int j) {
  if (i != j) {
    Type aux; // cualquier tipo de dato generico
    aux = this->vector_[i];
    this->vector_[i] = this->vector_[j];
    this->vector_[j] = aux;

    std::cout << std::endl << "< ";
    for (int h = 0; h < heap_sz; h++) {
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

#endif
