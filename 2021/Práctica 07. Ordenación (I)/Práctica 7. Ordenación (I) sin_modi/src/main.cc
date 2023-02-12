
//////////////////////////////////////////////////////////////////////////////////
// Universidad de La Laguna                                                     //
// Escuela Superior de Ingeniería y Tecnología                                  //
// Grado en Ingeniería Informática                                              //
// Algoritmos y Estructuras de datos Avanzados                                  //
// Fecha: 21/04/2021                                                            //
// Autor: José Javier Díaz González (alu0101128894)                             //
//                                                                              //
// Práctica 7. Ordenación (I)                                                   //
// Referencias: https://es.wikipedia.org/wiki/Algoritmo_de_ordenamiento         //
// Nombre del archivo: main.cc                                                  //
//////////////////////////////////////////////////////////////////////////////////

#include <iostream>
#include <vector>
#include <ctime>    // time  
#include <cstdlib> // rand 

#include "../include/insercion.h"
#include "../include/quicksort.h"
#include "../include/shellsort.h"

//template <class Clave>
int main()
{
  std::vector<int> aux;   // {10, 288, 2, 182, 94, 923, 873, 9};

  int vectorSize, opcion = 0; 
  std::cout << "\nIntroducir tamaño del vector: ";
  std::cin >> vectorSize;
  std::cout << "\n-> 1. Introducir vector." << std::endl;
  std::cout << "-> 2. Generar vector aleatorio." << std::endl;
  std::cout << "Introduce una opción: ";
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
    for (int i = 0; i < aux.size(); i++)
    {
      std::cout << aux[i] << " ";
    }
    std::cout << ">";
    std::cout << "\n- Tamaño: " << vectorSize << std::endl;
    break;
  case 2:
    srand (time(NULL));
    std::cout << "\n- Generar vector aleatorio = < ";
    for (int i = 0; i < vectorSize; i++) {
      opcion = rand() % 1000 + 1; // 1 y 1000
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
  do
  {
    std::cout
        << "\n1. Insercción" << std::endl
        << "2. QuickSort" << std::endl
        << "3. ShellSort" << std::endl
        << "4. Salir" << std::endl;
    std::cout << "Introduzca el algoritmo a ejecutar: ";
    std::cin >> opcion;
    std::cin.clear();
    switch (opcion)
    {
    case 1:
    {   
      std::cout << "\n-> Vector generado: ";
      for (int i = 0; i < aux.size(); i++)
      {
        std::cout << aux[i] << " ";
      }
      std::cout << std::endl;
      insercion algoritmo;
      aux = algoritmo.metodo(aux, aux.size());

      std::cout << "\n-> Vector final: \n< ";
        for (int i = 0; i < aux.size(); i++)
        { 
          std::cout << "\033[1;33m" << aux[i]  << ", " << "\033[0m";  //amarillo
        }
        std::cout << ">";
        std::cout << std::endl;
      break;
    }
    case 2:
    { 
      std::cout << "\n-> Vector generado: ";
      for (int i = 0; i < aux.size(); i++)
      {
        std::cout << aux[i] << " ";
      }
      std::cout << std::endl;
      quicksort algoritmo;
      aux = algoritmo.metodo(aux, aux.size());

      std::cout << "\n-> Vector final: \n< ";
        for (int i = 0; i < aux.size(); i++)
        { 
        std::cout << "\033[1;33m" << aux[i]  << ", " << "\033[0m";  // \033[1;32m
        }
        std::cout << ">";
        std::cout << std::endl;
      break;
      }
    case 3:
    { 
      std::cout << "\n-> Vector generado: ";
      for (int i = 0; i < aux.size(); i++)
      {
        std::cout << aux[i] << " ";
      }
      std::cout << std::endl;
      shellsort algoritmo;
      aux = algoritmo.metodo(aux, aux.size());

      std::cout << "\n-> Vector final: \n< ";
        for (int i = 0; i < aux.size(); i++)
        { 
          std::cout << "\033[1;33m" << aux[i]  << ", " << "\033[0m";  // \033[1;32m
        }
        std::cout << ">";
        std::cout << std::endl;
      break;
    }
    case 4:
      std::cout << "Fin del programa.\n";
      break;
    default:
      std::cout << "\nIntroduzca una opcion valida. \n"
                << "-> Selecciona de nuevo.\n\n";
      break;
    }
  } while (opcion != 4);
}
