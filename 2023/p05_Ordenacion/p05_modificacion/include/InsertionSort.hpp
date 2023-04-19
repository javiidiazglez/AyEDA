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
 * @file InsertionSort.h: clase InsertionSort
 * @brief Contiene la declaracion de la clase InsertionSort
 **/

#ifndef INSERTION_SORT_H
#define INSERTION_SORT_H

#include "Sort.hpp"

template <class Key>
class InsertionSort : public SortMethod<Key> {
 private:
  int moves = 0;

 public:
  InsertionSort(std::vector<Key> seq, unsigned size) {
    SortMethod<Key>::SetSeq(seq);
    SortMethod<Key>::SetSize(size);
  }

  int GetMoves() const {
    return moves;
  }

  void Sort() {
    std::cout << "Método de ordenación: Inserción\n" << std::endl;
    std::vector<Key> seq_cp = SortMethod<Key>::GetSeq();
    // Iteracion 0
    for (unsigned int k = 0; k < seq_cp.size(); k++) {
      std::cout << seq_cp[k] << " ";
    }
    std::cout << "\n";
    bool swapped = true;
    for (unsigned int i = 1; i < seq_cp.size(); i++) {
      swapped = false;
      Key key = seq_cp[i];
      int j = i - 1;
      while (j >= 0 && seq_cp[j] > key) {
        seq_cp[j + 1] = seq_cp[j];
        j--;
        swapped = true;
        moves++;  // Incrementamos moves cada vez que se produce un desplazamiento
      }
      seq_cp[j + 1] = key;
      // Print changes in the sequence after each iteration
      if (swapped) {
        for (unsigned int k = 0; k < seq_cp.size(); k++) {
          if (k == j + 1) {
            std::cout << "\033[32m" << seq_cp[k] << "\033[0m ";
          } else if (k == i) {
            std::cout << "\033[31m" << seq_cp[k] << "\033[0m ";
          } else {
            std::cout << seq_cp[k] << " ";
          }
        }
        std::cout << "\n";
      }
    }

    // Sequence sorted
    std::cout << "\nResultado:\033[33m [ ";
    for (unsigned int i = 0; i < seq_cp.size(); i++) {
      std::cout << seq_cp[i] << " ";
    }
    std::cout << "]\033[0m\n";
    std::cout << "Número de desplazamientos: " << GetMoves() << std::endl;  // Imprimimos el número de desplazamientos y el resultado del getter GetMoves en la salida
  }
};

#endif