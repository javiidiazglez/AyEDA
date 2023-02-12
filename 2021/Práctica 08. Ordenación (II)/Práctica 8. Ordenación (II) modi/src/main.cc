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

#include "../include/empleado.h"
#include "../include/heapsort.h"
#include "../include/insercion.h"
#include "../include/mergesort.h"
#include "../include/quicksort.h"
#include "../include/seleccion.h"
#include "../include/shellsort.h"

template <typename Type>
void programa();

int main() {

  // std::vector<int> aux;  // {10, 288, 2, 182, 94, 923, 873, 9};
  // Algorithm<int>* algoritmo = NULL;
  // bool is_break = false;

  // int vectorSize, opcion = 0;
  // std::cout << "\nIntroducir tamaño del vector: ";
  // std::cin >> vectorSize;
  // std::cout << "\n1. Introducir vector." << std::endl;
  // std::cout << "2. Generar vector aleatorio." << std::endl;
  // std::cout << "-> Introduce una opción: ";
  // std::cin >> opcion;
  // std::cin.clear();
  // switch (opcion) {
  //   case 1:
  //     std::cout << "\n- Introduzca el vector y pulser ENTER: " << std::endl;
  //     for (int i = 0; i < vectorSize; i++) {
  //       std::cin >> opcion;
  //       aux.push_back(opcion);
  //     }
  //     std::cout << "\n- Vector = < ";
  //     for (int i = 0; i < aux.size(); i++) {
  //       std::cout << aux[i] << " ";
  //     }
  //     std::cout << ">";
  //     std::cout << "\n- Tamaño: " << vectorSize << std::endl;
  //     break;
  //   case 2:
  //     srand(time(NULL));
  //     std::cout << "\n- Generar vector aleatorio = < ";
  //     for (int i = 0; i < vectorSize; i++) {
  //       opcion = rand() % 1000 + 1;  // 1 y 1000
  //       aux.push_back(opcion);
  //       std::cout << opcion << " ";
  //     }
  //     std::cout << ">" << std::endl;
  //     std::cout << "- Tamaño: " << vectorSize << std::endl;
  //     break;
  //   default:
  //     std::cout << "\nIntroduzca una opcion valida. \n"
  //               << "--> Selecciona de nuevo.\n";
  //     return main();
  // }
  // opcion = 0;
  // auto solucion = aux;
  // do {
  //   std::cout << "\n- Algoritmos de Ordenación -" << std::endl;
  //   std::cout << "1. Insercción" << std::endl
  //             << "2. QuickSort" << std::endl
  //             << "3. ShellSort" << std::endl
  //             << "4. Selección" << std::endl
  //             << "5. Heapsort" << std::endl
  //             << "6. Mergesort" << std::endl
  //             << "7. Salir" << std::endl;
  //   std::cout << "-> Introduzca el algoritmo a ejecutar: ";
  //   std::cin >> opcion;
  //   std::cin.clear();

  //   switch (opcion) {
  //     case 1: {
  //       algoritmo = new insercion<int>;
  //       break;
  //     }
  //     case 2: {
  //       algoritmo = new quicksort<int>;
  //       break;
  //     }
  //     // Shellsort
  //     case 3: {
  //       algoritmo = new shellsort<int>;
  //       break;
  //     }
  //     // Seleccion
  //     case 4: {
  //       algoritmo = new seleccion<int>;
  //       break;
  //     }
  //     // Heapsort
  //     case 5: {
  //       algoritmo = new heapsort<int>;
  //       break;
  //     }
  //     // Mergesort
  //     case 6: {
  //       algoritmo = new mergesort<int>;
  //       break;
  //     }
  //     // Exit
  //     case 7:
  //       std::cout << "Fin del programa.\n";
  //       is_break = true;
  //       break;
  //     default:
  //       std::cout << "\nIntroduzca una opcion valida. \n"
  //                 << "-> Selecciona de nuevo.\n\n";
  //       break;
  //   }

  //   if (is_break) break;

  //   std::cout << "\n\n-> Vector generado: ";
  //   for (int i = 0; i < aux.size(); i++) {
  //     std::cout << aux[i] << " ";
  //   }
  //   std::cout << std::endl;
  //   solucion = algoritmo->metodo(aux, aux.size());

  //   std::cout << "\n-> Vector final: \n< ";
  //   for (int i = 0; i < solucion.size(); i++) {
  //     std::cout << "\033[1;33m" << solucion[i] << ", "
  //               << "\033[0m";  // \033[1;32m
  //   }
  //   std::cout << ">";
  //   std::cout << std::endl;

  //   if (algoritmo != NULL) {
  //     delete algoritmo;
  //     algoritmo = NULL;
  //   }
  // } while (opcion != 7);

  std::vector<Empleado> vec = {{"a", "f1", 4}, {"b", "f1", 3}, {"c", "f1", 2}, {"d", "f1", 1}};
  std::vector<Empleado> solucion;
  //Algorithm<Empleado>* algoritmo;
  Algorithm<Empleado>* algoritmo = new insercion<Empleado>;
//   int opcion;
//   std::cin >> opcion;
// 
//   switch (opcion) {
//     case 1: {
//       algoritmo = new insercion<Empleado>;
//       break;
//     }
//     case 2: {
//       algoritmo = new quicksort<Empleado>;
//       break;
//     }
//     // Shellsort
//     case 3: {
//       algoritmo = new shellsort<Empleado>;
//       break;
//     }
//     // Seleccion
//     case 4: {
//       algoritmo = new seleccion<Empleado>;
//       break;
//     }
//     // Heapsort
//     case 5: {
//       algoritmo = new heapsort<Empleado>;
//       break;
//     }
//     // Mergesort
//     case 6: {
//       algoritmo = new mergesort<Empleado>;
//       break;
//     }
// 
//     default:
//       std::cout << "\nIntroduzca una opcion valida. \n"
//                 << "-> Selecciona de nuevo.\n\n";
//       break;
//   }

  solucion = algoritmo->metodo(vec, vec.size());
  // Mostrar solucion
  std::cout << std::endl;
  std::cout << "Solucion: "<< std::endl;
  for (auto& empleado : solucion) // instanciamos
    std::cout << empleado; // solucion final 
  std::cout << std::endl;

  delete algoritmo;
}
