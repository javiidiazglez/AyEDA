
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
// Nombre del archivo: insercion.cc                                             //
//////////////////////////////////////////////////////////////////////////////////

#include "../include/insercion.h"

#include <iostream>
#include <vector>

insercion::insercion() {}
insercion::~insercion() {}

// void printVector(std::vector<int> a)
// {
//   for (int i = 0; i < a.size(); i++)
//   {
//     std::cout << a[i] << " ";
//   }
//   std::cout << std::endl;
// }

//template <class Clave>
std::vector<int> insercion::metodo(std::vector<int> a, int sz)
{
  int contador_global=0;
  insercion_v = a;
  insercion_sz = sz;

  int i, j;
  int key;
  for (i = 1; i < insercion_sz; i++)
  {
    key = insercion_v[i];
    j = i - 1;

    while (j >= 0 && insercion_v[j] > key)
    {
      //if (mostar_algoritmos == true)
      show_changes(j + 1, j);
      insercion_v[j + 1] = insercion_v[j];
      j--;
      contador_global++;
    }
    insercion_v[j + 1] = key;
  }
  std::cout << "Contador_global: " << contador_global << std::endl;
  return insercion_v;
}

//template <class Clave>
void insercion::show_changes(int i, int h)
{
  if (i != h)
  {
    std::cout << "\n< ";
    for (int j = 0; j < insercion_sz; j++)
    {
      if (j == i)
      {
        std::cout << "\033[1;32m" << insercion_v[j] << "\033[0m, ";
      }
      if (j == h)
      {
        std::cout << "\033[1;31m" << insercion_v[j] << "\033[0m, ";
      }
      if (i != j && j != h)
      {
        std::cout << insercion_v[j] << ", ";
      }
    }
    std::cout << ">";
    std::cout << std::endl;
  }
}
