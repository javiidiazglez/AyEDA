/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingenierıa Informatica
 * Asignatura: Algoritmos y Estructuras de Datos Avanzadas
 * Curso: 2º
 * Práctica 5: Algoritmos de Ordenación
 *
 * @author José Javier Díaz González
 * Correo: alu0101128894@ull.edu.es
 *
 * @date 19/04/2023
 * @file ShellSort.h: clase ShellSort
 * @brief Contiene la declaracion de la clase ShellSort
 **/

#ifndef SHELL_SORT_H
#define SHELL_SORT_H

#include "Sort.hpp"

template <class Key>
class ShellSort : public SortMethod<Key> {
 public:
  ShellSort(std::vector<Key> seq, unsigned size) {
    SortMethod<Key>::SetSeq(seq);
    SortMethod<Key>::SetSize(size);
  }
  void Sort() {
    std::cout << "Método de ordenación: ShellSort\n" << std::endl;
    std::vector<Key> seq_cp = SortMethod<Key>::GetSeq();
    int n = seq_cp.size();
    int swap_count = 0;  // contador de intercambios
    for (int gap = n / 2; gap > 0; gap /= 2) {
      for (int i = gap; i < n; i += 1) {
        Key temp = seq_cp[i];
        int j;
        for (j = i; j >= gap && seq_cp[j - gap] > temp; j -= gap) {
          seq_cp[j] = seq_cp[j - gap];
          swap_count++;  // incrementar el contador de intercambios
          PrintSeq(seq_cp, j, j - gap);
        }
        seq_cp[j] = temp;
        if (j != i) {
          swap_count++;  // incrementar el contador de intercambios
          PrintSeq(seq_cp, j, i);
        }
      }
    }
    // Sequence sorted
    std::cout << "\nResultado:\033[33m [ ";
    for (unsigned int i = 0; i < seq_cp.size(); i++) {
      std::cout << seq_cp[i] << " ";
    }
    std::cout << "]\033[0m\n";
    std::cout << "Número de intercambios: " << swap_count << std::endl;  // imprimir el número de intercambios
  }
  void PrintSeq(std::vector<Key>& seq, int idx1, int idx2) {
    for (unsigned int i = 0; i < seq.size(); i++) {
      if (i == idx1) {
        std::cout << "\033[32m" << seq[i] << " \033[0m";
      } else if (i == idx2) {
        std::cout << "\033[31m" << seq[i] << " \033[0m";
      } else {
        std::cout << seq[i] << " ";
      }
    }
    std::cout << "\n";
  }
};

#endif