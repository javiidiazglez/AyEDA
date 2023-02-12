
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
// Nombre del archivo: quicksort.cc                                             //
//////////////////////////////////////////////////////////////////////////////////

#include "../include/quicksort.h"

#include <iostream>
#include <vector>

quicksort::quicksort() {}
quicksort::~quicksort() {}

std::vector<int> quicksort::metodo(std::vector<int> a, int sz)
{
  Quicksort_v = a;
  Quicksort_sz = sz;
  quickie(0, Quicksort_sz - 1);
  return Quicksort_v;
}

void quicksort::quickie(int inicial, int fin)
{
  int p;
  int i, f;
  i = inicial;
  f = fin;
  if (fin == (inicial + 1))
  {
    if (Quicksort_v[fin] < Quicksort_v[inicial])
    {
      swap_pos(fin, inicial);
    }
    return;
  }
  p = Quicksort_v[(i + f) / 2];

  while (i < f)
  {
    while (Quicksort_v[i] < p)
    {
      //if (mostar_algoritmos == true)
      show_quickie(i, (i + f) / 2);
      i++;
      //contador_global++;
    }
    while (p < Quicksort_v[f])
    {
      //if (mostar_algoritmos == true)
      show_quickie(f, (i + f) / 2);
      f--;
      //contador_global++;
    }
    if (i < f)
    {
      swap_pos(i, f);
      i++;
      f--;
    }
  }

  if (inicial < f)
    quickie(inicial, f);
  if (i < fin)
    quickie(i, fin);
}

void quicksort::swap_pos(int i, int j)
{
  if (i != j)
  {
    //contador_swap++;
    int aux = Quicksort_v[i];
    Quicksort_v[i] = Quicksort_v[j];
    Quicksort_v[j] = aux;
    if (true)
    {
      std::cout << std::endl
                << "< ";
      for (int h = 0; h < Quicksort_sz; h++)
      {
        if (h == i)
        {
          std::cout << "\033[1;31m" << Quicksort_v[h] << "\033[0m, ";
        }
        if (h == j)
        {
          std::cout << "\033[1;32m" << Quicksort_v[h] << "\033[0m, ";
        }
        if (h != i && h != j)
        {
          std::cout << Quicksort_v[h] << ", ";
        }
      }
      std::cout << ">";
      std::cout << std::endl;
    }
  }
}

void quicksort::show_quickie(int i, int h)
{
  if (i != h)
  {
    std::cout << std::endl
              << "< ";
    for (int j = 0; j < Quicksort_sz; j++)
    {
      if (j == i)
      {
        std::cout << "\033[1;32m" << Quicksort_v[j] << "\033[0m, ";
      }
      if (j == h)
      {
        std::cout << "\033[1;31m" << Quicksort_v[j] << "\033[0m, ";
      }
      if (i != j && j != h)
      {
        std::cout << Quicksort_v[j] << ", ";
      }
    }
    std::cout << ">";
    std::cout << std::endl;
  }
}
