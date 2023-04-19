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
 * @file main.cc: clase main
 * @brief Contiene definición de la clase
 **/

#include <iostream>
#include <string>
#include <fstream>
#include <limits>

#include "HeapSort.hpp"
#include "InsertionSort.hpp"
#include "MergeSort.hpp"
#include "RadixSort.hpp"
#include "ShellSort.hpp"
#include "Sort.hpp"

typedef long KeyType;

void Help() {
  std::ifstream file_in;
  file_in.open("help.txt", std::ios::in);

  if (file_in.fail()) {
    std::cout << "[!] No se pudo abrir el archivo" << std::endl;
    exit(1);
  }
  std::string aux;
  while (!file_in.eof()) {
    std::string aux;
    getline(file_in, aux);
    std::cout << aux << std::endl;
  }
  file_in.close();
}

int protectedMain(int argc, char* argv[]) {
  unsigned size_vector;
  int type_sort_method;
  while (true) {
    std::cout << "\n¿Qué método de ordenación desea utilizar?\n";
    std::cout << "[1] Insertion Method\n"
              << "[2] MergeSort Method\n"
              << "[3] ShellSort Method\n"
              << "[4] HeapSort Method\n"
              << "[5] RadixSort Method\n";
    std::cout << "-> Introduzca la opción [1|2|3|4|5]: ";
    std::cin >> type_sort_method;

    if (std::cin.fail()) {
      std::cout << "\t[!] Error: la opción debe ser un número." << std::endl;
      std::cin.clear();
      std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
      continue;  // Volver a imprimir el menú
    }
    if (type_sort_method < 1 || type_sort_method > 5) {
      std::cout << "\n\t[!] Error: la opción debe ser 1, 2, 3, 4 o 5." << std::endl;
      continue;  // Volver a imprimir el menú
    }
    break;  // La opción es válida, salir del bucle
  }

  std::cout << "\n-> Introduzca el tamaño del vector: ";
  std::cin >> size_vector;
  std::vector<KeyType> vector_to_sort(size_vector);
  int insertion_option;
  while (true) {
    std::cout << "\n¿Qué método de inserción desea utilizar?\n"
              << "[1] Por teclado\n"
              << "[2] Generar números aleatorios\n";
    std::cout << "-> Introduzca la opción [1|2]: ";
    std::cin >> insertion_option;

    if (std::cin.fail()) {
      std::cout << "\t[!] Error: la opción debe ser un número." << std::endl;
      std::cin.clear();
      std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
      continue;  // Volver a imprimir el menú
    }
    if (insertion_option != 1 && insertion_option != 2) {
      std::cout << "\t[!] Error: la opción debe ser 1 o 2." << std::endl;
      continue;  // Volver a imprimir el menú
    }
    break;  // La opción es válida, salir del bucle
  }

  std::cout << std::endl;
  switch (insertion_option) {
    case 1: {
      for (unsigned int i = 0; i < size_vector; i++) {
        std::cout << "- Introduzca el elemento [" << i << "]: ";
        int input;
        while (!(std::cin >> input) || input <= 0) {
          std::cout << "[!] Introduzca un numero entero positivo: ";
          std::cin.clear();
          std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
        vector_to_sort[i] = input;
      }
    } break;
    case 2: {
      // The random numbers are generate between 1000 and 9999
      for (unsigned int i = 0; i < size_vector; i++) {
        vector_to_sort[i] = std::rand() % 9000 + 1000;  // 0 - 8999 + 1000 = 9999
      }
    } break;
    default:
      std::cout << "\t[!] Opcion no encontrada" << std::endl;
      std::exit(1);
      break;
  }
  std::cout << "Vector: \033[34m";
  for (unsigned int i = 0; i < size_vector; i++) {
    std::cout << vector_to_sort[i] << " ";
  }
  std::cout << "\033[0m\n"; // Restablecer el color
  std::cout << std::endl;
  SortMethod<KeyType>* sort_method = nullptr;
  switch (type_sort_method) {
    case 1: {
      sort_method = new InsertionSort<KeyType>(vector_to_sort, size_vector);
    } break;
    case 2: {
      sort_method = new MergeSort<KeyType>(vector_to_sort, size_vector);
    } break;
    case 3: {
      sort_method = new ShellSort<KeyType>(vector_to_sort, size_vector);
    } break;
    case 4: {
      sort_method = new HeapSort<KeyType>(vector_to_sort, size_vector);
    } break;
    case 5: {
      sort_method = new RadixSort<KeyType>(vector_to_sort, size_vector);
    } break;
    default:
      std::cout << "\t[!] Opcion no encontrada\n";
      break;
  }
  sort_method->Sort();
}

void Menu(int argc, char* argv[]) {
  switch (argc) {
    case 1:
      std::cout << "José Javier Díaz González" << std::endl;
      std::cout << "Práctica 5: Algoritmos de Ordenación" << std::endl;
      break;
    case 2:
      Help();
      exit(0);
      break;
    default:
      exit(1);
  }
}
int main(int argc, char* argv[]) {
  Menu(argc, argv);
  try {
    return protectedMain(argc, argv);
  } catch (std::system_error& e) {
    std::cerr << e.what() << '\n';
    return 2;
  }
  return EXIT_SUCCESS;
}
