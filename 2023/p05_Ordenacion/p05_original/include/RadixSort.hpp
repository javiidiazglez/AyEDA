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
 * @file RadixSort.h: clase RadixSort
 * @brief Contiene la declaracion de la clase RadixSort
 **/

#ifndef RADIX_SORT_H
#define RADIX_SORT_H

#include "Sort.hpp"

#define GREEN "\033[32m"
#define RED "\033[31m"
#define RESET "\033[0m"

template <class Key>
class RadixSort : public SortMethod<Key> {
 public:
  RadixSort(std::vector<Key> seq, unsigned size) {
    SortMethod<Key>::SetSeq(seq);
    SortMethod<Key>::SetSize(size);
  }
  void Sort() {
    std::cout << "Método de ordenación: RadixSort\n" << std::endl;
    std::vector<Key> seq_cp = SortMethod<Key>::GetSeq();
    int n = seq_cp.size();
    int m = GetMax(seq_cp, n);
    for (int exp = 1; m / exp > 0; exp *= 10) {
      CountSort(seq_cp, n, exp);
    }
    // Sequence sorted
    std::cout << "\nResultado:\033[33m [ ";
    for (unsigned int i = 0; i < seq_cp.size(); i++) {
      std::cout << seq_cp[i] << " ";
    }
    std::cout << "]\033[0m\n";
  }
  int GetMax(std::vector<Key>& seq, int n) {
    int max = seq[0];
    for (int i = 1; i < n; i++) {
      if (seq[i] > max) {
        max = seq[i];
      }
    }
    return max;
  }
  void CountSort(std::vector<Key>& seq, int n, int exp) {
    int output[n];
    int i, count[10] = {0};
    for (i = 0; i < n; i++) {
      // Resaltar el valor que se va a cambiar
      std::cout << GREEN << seq[i] << RESET << " ";
      count[(seq[i] / exp) % 10]++;
    }
    std::cout << "\n";
    for (i = 1; i < 10; i++) {
      count[i] += count[i - 1];
    }
    for (i = n - 1; i >= 0; i--) {
      // Resaltar el valor que se va a utilizar
      std::cout << RED << seq[i] << RESET << " ";
      output[count[(seq[i] / exp) % 10] - 1] = seq[i];
      count[(seq[i] / exp) % 10]--;
    }
    for (i = 0; i < n; i++) {
      seq[i] = output[i];
    }
    // Imprimir la secuencia después de esta iteración
    std::cout << "\nExponente = [" << exp << "]: ";
    for (unsigned int i = 0; i < seq.size(); i++) {
      std::cout << seq[i] << " ";
    }
    std::cout << "\n";
  }
};

#endif