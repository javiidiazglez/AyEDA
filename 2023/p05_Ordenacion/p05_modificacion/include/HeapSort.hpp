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
 * @file HeapSort.h: clase HeapSort
 * @brief Contiene la declaracion de la clase HeapSort
 **/

#ifndef HEAP_SORT_H
#define HEAP_SORT_H

#include <chrono>
#include <iostream>
#include <thread>
#include <vector>

#include "Sort.hpp"

template <class Key>
class HeapSort : public SortMethod<Key> {
 public:
  HeapSort(std::vector<Key> seq, unsigned size) {
    SortMethod<Key>::SetSeq(seq);
    SortMethod<Key>::SetSize(size);
  }
  void Sort() {
    std::cout << "Método de ordenación: HeapSort\n";
    std::vector<Key> seq_cp = SortMethod<Key>::GetSeq();
    int n = seq_cp.size();
    for (int i = n / 2 - 1; i >= 0; i--) {
      Heapify(seq_cp, n, i);
    }
    for (int i = n - 1; i >= 0; i--) {
      try {
        std::swap(seq_cp[0], seq_cp[i]);
      } catch (const std::out_of_range& e) {
        std::cerr << "Out of range error: " << e.what() << std::endl;
        return;
      }
      PrintSeq(seq_cp, i, 0);  // Llamada a función para imprimir los cambios
      Heapify(seq_cp, i, 0);
    }
    // Sequence sorted
    for (unsigned int i = 0; i < seq_cp.size(); i++) {
      std::cout << seq_cp[i] << " ";
    }
    std::cout << "\n";

    // Sequence sorted
    std::cout << "\nResultado:\033[33m [ ";
    for (unsigned int i = 0; i < seq_cp.size(); i++) {
      std::cout << seq_cp[i] << " ";
    }
    std::cout << "]\033[0m\n";
  }
  void Heapify(std::vector<Key>& seq, int n, int i) {
    int largest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;
    try {
      if (l < n && seq[l] > seq[largest]) {
        largest = l;
      }
      if (r < n && seq[r] > seq[largest]) {
        largest = r;
      }
      if (largest != i) {
        std::swap(seq[i], seq[largest]);
        PrintSeq(seq, n, largest);  // Llamada a función para imprimir los cambios
        Heapify(seq, n, largest);
      }
    } catch (const std::out_of_range& e) {
      std::cerr << "Out of range error: " << e.what() << std::endl;
      return;
    }
  }
  void PrintSeq(std::vector<Key>& seq, int n = -1, int largest = -1) {
    for (unsigned int i = 0; i < seq.size(); i++) {
      if (i == n) {
        std::cout << "\033[32m" << seq[i] << "\033[0m ";  // Valor a cambiar en verde
      } else if (i == largest) {
        std::cout << "\033[31m" << seq[i] << "\033[0m ";  // Valor a comparar en rojo
      } else {
        std::cout << seq[i] << " ";
      }
    }
    std::cout << "\n";
  }
};

#endif