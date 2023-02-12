
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
// Nombre del archivo: shellsort.cc                                             //
//////////////////////////////////////////////////////////////////////////////////

#include "../include/shellsort.h"

#include <iostream>
#include <vector>

shellsort::shellsort() {}
shellsort::~shellsort() {}

std::vector<int> shellsort::metodo(std::vector<int> a, int sz)
{
  shell_v = a;
  shell_sz = sz;
  float alpha = 0;
  std::cout << "\nIntroduzca el valor alpha: ";
  std::cin >> alpha;
  if (alpha <= 0 || alpha >= 1)
  {
    std::cerr << "Valor de alpha inválido!" << std::endl;
    exit(1);
  }
  int delta = 0;
  int it = 0;
  delta = alpha * sz;
  cambio = false;
  int index = 0;
  while (delta > 0)
  {
    if (index + delta < sz)
    {
      if (shell_v[index] > shell_v[index + delta])
      {
        cambio = true;
        swap_pos(index, index + delta);
      }
      index += delta;
      //contador_global++;
    }
    else
    {
      if (it == delta)
      {
        it = 0;
        index = it;
        if (cambio == false)
          delta /= 2;
      }
      else
      {
        it++;
        index = it;
        cambio = false;
      }
    }
  }
  return shell_v;
}

void shellsort::swap_pos(int i, int j)
{
  if (i != j)
  {
    //contador_swap++;
    int aux = shell_v[i];
    shell_v[i] = shell_v[j];
    shell_v[j] = aux;
    if (true)
    {
      std::cout << std::endl
                << "< ";
      for (int h = 0; h < shell_sz; h++)
      {
        if (h == i)
        {
          std::cout << "\033[1;31m" << shell_v[h] << "\033[0m, ";
        }
        if (h == j)
        {
          std::cout << "\033[1;32m" << shell_v[h] << "\033[0m, ";
        }
        if (h != i && h != j)
        {
          std::cout << shell_v[h] << ", ";
        }
      }
      std::cout << ">";
      std::cout << std::endl;
    }
  }
}
