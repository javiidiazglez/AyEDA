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
// Nombre del archivo: mergesort.h                                              //
//////////////////////////////////////////////////////////////////////////////////

#ifndef MERGESORT_H
#define MERGESORT_H

#include "algorithm.h"

template <typename Type>
class mergesort : public Algorithm<Type> {
 public:
  using Algorithm<Type>::Algorithm;
  ~mergesort() {}
  std::vector<Type> metodo(std::vector<Type> a, int sz);
  void merge_sort(int inic, int fin);
  void show_merge_changes(int i);

 private:
  std::vector<Type> auxilar;
  int merge_sz;
};

template <typename Type>
std::vector<Type> mergesort<Type>::metodo(std::vector<Type> a, int sz) {
  // contador_global = 0;
  this->vector_ = a;
  merge_sz = sz;
  auxilar = this->vector_;
  merge_sort(0, merge_sz - 1);
  return this->vector_;
}

template <typename Type>
void mergesort<Type>::merge_sort(int inic, int fin) {
  int centro, i, j, k;
  if (inic < fin) {
    centro = (inic + fin) / 2;
    merge_sort(inic, centro);
    merge_sort(centro + 1, fin);
    i = inic;
    j = centro + 1;
    k = inic;
    while ((i <= centro) && (j <= fin)) {
      if (this->vector_[i] < this->vector_[j]) {
        auxilar[k] = this->vector_[i];
        show_merge_changes(k);
        i++;
      } else {
        auxilar[k] = this->vector_[j];
        show_merge_changes(k);
        j++;
      }
      // contador_global++;
      k++;
    }
    if (i > centro) {
      while (j <= fin) {
        auxilar[k] = this->vector_[j];
        show_merge_changes(k);
        j++;
        k++;
      }
    } else {
      while (i <= centro) {
        auxilar[k] = this->vector_[i];
        show_merge_changes(k);
        i++;
        k++;
      }
    }
    this->vector_ = auxilar;
  }
}

template <typename Type>
void mergesort<Type>::show_merge_changes(int i) {
  // contador_swap++;
  std::cout << std::endl << "< ";
  for (int j = 0; j < merge_sz; j++) {
    if (j == i) {
      std::cout << "\033[1;32m" << auxilar[j] << "\033[0m, ";
    } else {
      std::cout << auxilar[j] << ", ";
    }
  }
  std::cout << ">";
  // std::cout << std::endl;
}

#endif
