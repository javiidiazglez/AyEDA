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
// Nombre del archivo: shellsort.h                                              //
//////////////////////////////////////////////////////////////////////////////////

#ifndef SHELLSORT_H
#define SHELLSORT_H

#include "algorithm.h"

template <typename Type>
class shellsort : public Algorithm<Type> {
 public:
  using Algorithm<Type>::Algorithm;
  ~shellsort() {}
  std::vector<Type> metodo(std::vector<Type> a, int sz);
  void swap_pos(int i, int j);

 private:
  int shell_sz;
  bool cambio;
};

template <typename Type>
std::vector<Type> shellsort<Type>::metodo(std::vector<Type> a, int sz) {
  this->vector_ = a;
  shell_sz = sz;
  float alpha = 0;
  std::cout << "\nIntroduzca el valor alpha {0.1-0.9}: ";
  std::cin >> alpha;
  std::cin.clear();
  if (alpha <= 0 || alpha >= 1) {
    std::cerr << "Valor de alpha inválido!" << std::endl << "--> Introduzca de nuevo" << std::endl;

    return shellsort<Type>::metodo(a, sz);
  }

  int delta = 0.5; // 0.5  tamaño 2 (CAMBIO A 0.5 MODIFICACION)
  int it = 0;
  delta = alpha * sz; // 4 * 0.4 = 0.4 -> 0
  cambio = false;     // 8 * 0.2 = 1.6 -> 1
  int index = 0;
  while (delta > 0) {
    if (index + delta < sz) {
      if (this->vector_[index] > this->vector_[index + delta]) {
        cambio = true;
        swap_pos(index, index + delta);
      }
      index += delta;
      // contador_global++;
    } else {
      if (it == delta) {
        it = 0;
        index = it;
        if (cambio == false) delta /= 2;
      } else {
        it++;
        index = it;
        cambio = false;
      }
    }
  }
  return this->vector_;
}

template <typename Type>
void shellsort<Type>::swap_pos(int i, int j) {
  if (i != j) {
    Type aux = this->vector_[i];
    this->vector_[i] = this->vector_[j];
    this->vector_[j] = aux;
    if (true) {
      std::cout << std::endl << "< ";
      for (int h = 0; h < shell_sz; h++) {
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

#endif
