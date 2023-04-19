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
 * @file MergeSort.h: clase MergeSort
 * @brief Contiene la declaracion de la clase MergeSort
 **/

#ifndef MERGE_SORT_H
#define MERGE_SORT_H

#include "Sort.hpp"

template <class Key>
class MergeSort : public SortMethod<Key> {
 public:
  MergeSort(std::vector<Key> seq, unsigned size) {
    SortMethod<Key>::SetSeq(seq);
    SortMethod<Key>::SetSize(size);
  }
  void Sort() {
    std::cout << "Método de ordenación: MergeSort\n" << std::endl;
    try {
      std::vector<Key> seq_cp = SortMethod<Key>::GetSeq();
      MergeSortAux(seq_cp, 0, seq_cp.size() - 1);
      // Sequence sorted
      std::cout << "\nResultado:\033[33m [ ";
      for (unsigned int i = 0; i < seq_cp.size(); i++) {
        std::cout << seq_cp[i] << " ";
      }
      std::cout << "]\033[0m\n";
    } catch (const std::exception& e) {
      std::cerr << "Exception caught: " << e.what() << "\n";
    }
  }
  void MergeSortAux(std::vector<Key>& seq, int left, int right) {
    try {
      if (left < right) {
        int middle = (left + right) / 2;
        MergeSortAux(seq, left, middle);
        MergeSortAux(seq, middle + 1, right);
        Merge(seq, left, middle, right);
        PrintSeq(seq, left, middle, right);  // llamada a la función de impresión
      }
    } catch (const std::exception& e) {
      throw std::runtime_error("Error en MergeSortAux: " + std::string(e.what()));
    }
  }
  void Merge(std::vector<Key>& seq, int left, int middle, int right) {
    try {
      int i, j, k;
      int n1 = middle - left + 1;
      int n2 = right - middle;
      std::vector<Key> left_seq(n1);
      std::vector<Key> right_seq(n2);
      for (i = 0; i < n1; i++) {
        left_seq[i] = seq[left + i];
      }
      for (j = 0; j < n2; j++) {
        right_seq[j] = seq[middle + 1 + j];
      }
      i = 0;
      j = 0;
      k = left;
      while (i < n1 && j < n2) {
        if (left_seq[i] <= right_seq[j]) {
          seq[k] = left_seq[i];
          i++;
        } else {
          seq[k] = right_seq[j];
          j++;
        }
        k++;
      }
      while (i < n1) {
        seq[k] = left_seq[i];
        i++;
        k++;
      }
      while (j < n2) {
        seq[k] = right_seq[j];
        j++;
        k++;
      }
    } catch (const std::exception& e) {
      throw std::runtime_error("Error en Merge: " + std::string(e.what()));
    }
  }
  void PrintSeq(std::vector<Key>& seq, int left, int middle, int right) {
    // static_cast<unsigned int>(left)
    for (unsigned int i = 0; i < seq.size(); i++) {
      if (i >= left && i <= middle) {
        std::cout << "\033[32m" << seq[i] << "\033[0m" << " ";  // verde para valores actualizados
      } else if (i > middle && i <= right) {
        std::cout << "\033[31m" << seq[i] << "\033[0m" << " ";  // rojo para valores a comparar
      } else {
        std::cout << seq[i] << " ";
      }
    }
    std::cout << "\n";
  }
};

#endif
