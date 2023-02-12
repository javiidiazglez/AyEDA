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
// Nombre del archivo: insersion.h                                              //
//////////////////////////////////////////////////////////////////////////////////

#ifndef INSERCION_H
#define INSERCION_H

#include "algorithm.h"

template <typename Type>
class insercion : public Algorithm<Type> {
 public:
  using Algorithm<Type>::Algorithm;
  ~insercion() {}
  std::vector<Type> metodo(std::vector<Type> a, int sz);
  void show_changes(int, int);

 private:
  int insercion_sz;
};

template <typename Type>
std::vector<Type> insercion<Type>::metodo(std::vector<Type> a, int sz) {
  // int contador_global=0;
  this->vector_ = a;
  insercion_sz = sz;

  int i, j;
  Type key;
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

template <typename Type>
void insercion<Type>::show_changes(int i, int h) {
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
