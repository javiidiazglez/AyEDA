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
// Nombre del archivo: main.cc                                                  //
//////////////////////////////////////////////////////////////////////////////////

#include <cstdlib>  // rand
#include <ctime>    // time
#include <iostream>
#include <vector>

#include "../include/heapsort.h"
#include "../include/insercion.h"
#include "../include/mergesort.h"
#include "../include/quicksort.h"
#include "../include/seleccion.h"
#include "../include/shellsort.h"

template <typename Type>
void programa();

int main() {
  std::vector<int> aux;  // {10, 288, 2, 182, 94, 923, 873, 9};
  Algorithm<int>* algoritmo = NULL;
  bool is_break = false;

  int vectorSize, opcion = 0;
  std::cout << "\nIntroducir tamaño del vector: ";
  std::cin >> vectorSize;
  std::cout << "\n1. Introducir vector." << std::endl;
  std::cout << "2. Generar vector aleatorio." << std::endl;
  std::cout << "-> Introduce una opción: ";
  std::cin >> opcion;
  std::cin.clear();
  switch (opcion) {
    case 1:
      std::cout << "\n- Introduzca el vector y pulser ENTER: " << std::endl;
      for (int i = 0; i < vectorSize; i++) {
        std::cin >> opcion;
        aux.push_back(opcion);
      }
      std::cout << "\n- Vector = < ";
      for (int i = 0; i < aux.size(); i++) {
        std::cout << aux[i] << " ";
      }
      std::cout << ">";
      std::cout << "\n- Tamaño: " << vectorSize << std::endl;
      break;
    case 2:
      srand(time(NULL));
      std::cout << "\n- Generar vector aleatorio = < ";
      for (int i = 0; i < vectorSize; i++) {
        opcion = rand() % 1000 + 1;  // 1 y 1000
        aux.push_back(opcion);
        std::cout << opcion << " ";
      }
      std::cout << ">" << std::endl;
      std::cout << "- Tamaño: " << vectorSize << std::endl;
      break;
    default:
      std::cout << "\nIntroduzca una opcion valida. \n"
                << "--> Selecciona de nuevo.\n";
      return main();
  }
  opcion = 0;
  auto solucion = aux; // instanciando el aux 
  do {
    std::cout << "\n- Algoritmos de Ordenación -" << std::endl;
    std::cout << "1. Insercción" << std::endl
              << "2. QuickSort" << std::endl
              << "3. ShellSort" << std::endl
              << "4. Selección" << std::endl
              << "5. Heapsort" << std::endl
              << "6. Mergesort" << std::endl
              << "7. Salir" << std::endl;
    std::cout << "-> Introduzca el algoritmo a ejecutar: ";
    std::cin >> opcion;
    std::cin.clear();

      switch (opcion) {
    case 1: {
      std:: cout << "\nInserción: \n";
      algoritmo = new insercion<int>;
      break;
    }
    case 2: {
      std:: cout << "\nQuicksort: \n";
      algoritmo = new quicksort<int>;
      break;
    }
    // Shellsort
    case 3: {
      std:: cout << "\nShellsort: \n";
      algoritmo = new shellsort<int>;
      break;
    }
    // Seleccion
    case 4: {
      std:: cout << "\nSeleccion: \n";
      algoritmo = new seleccion<int>;
      break;
    }
    // Heapsort
    case 5: {
      std:: cout << "\nHeapsort: \n";
      algoritmo = new heapsort<int>;
      break;
    }
    // Mergesort
    case 6: {
      std:: cout << "\nMergesort: \n";
      algoritmo = new mergesort<int>;
      break;
    }
    default:
      std::cout << "\nIntroduzca una opcion valida. \n"
                << "-> Selecciona de nuevo.\n\n";
      break;
  }

    if (is_break) break;

    // Vector generado
    std::cout << "\n-> Vector generado: "; 
    for (int i = 0; i < aux.size(); i++) {
      std::cout << aux[i] << " ";
    }
    std::cout << std::endl;
    solucion = algoritmo->metodo(aux, aux.size());

     // Vector Final
    std::cout << "\n\n-> Vector final: \n< ";
    for (int i = 0; i < solucion.size(); i++) {
      std::cout << "\033[1;33m" << solucion[i] << ", " << "\033[0m";  // amarillo
    }
    std::cout << ">";
    std::cout << std::endl;

    if (algoritmo != NULL) {
      delete algoritmo;
      algoritmo = NULL;
    }
  } while (opcion != 7);
}
