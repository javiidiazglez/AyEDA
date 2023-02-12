#include "../include/seleccion.h"

#include <iostream>
#include <vector>

seleccion::seleccion() {}
seleccion::~seleccion() {}

//template <class Clave>
std::vector<int> seleccion::metodo(std::vector<int> a, int sz)
{
  //int contador_global=0;	// establecemos el contador a 0
  select_v = a; // guardamos el vector y su size
  select_sz = sz;

  // ejecucion del algortimo
  int min = 0;
  for (int i = 0; i < (sz - 1); i++)
  {
    min = i;
    for (int j = i + 1; j < sz; j++)
    {

      if (select_v[j] < select_v[min])
      {
        min = j;
      }
      //contador_global++;
    }
    swap_pos(min, i);
  }
  return select_v;
}

//template <class Clave>
void seleccion::swap_pos(int i, int j)
{
  if (i != j)
  {
    int aux;
    aux = select_v[i];
    select_v[i] = select_v[j];
    select_v[j] = aux;
    std::cout << std::endl
    << "< ";
    for (int h = 0; h < select_sz; h++)
    {
      if (h == i)
      {
        std::cout << "\033[1;31m" << select_v[h] << "\033[0m, "; // rojo, select, reset
      }
      if (h == j)
      {
        std::cout << "\033[1;32m" << select_v[h] << "\033[0m, "; // verde, select, reset
      }
      if (h != i && h != j)
      {
        std::cout << select_v[h] << ", ";
      }
    }
    std::cout << ">";
    //std::cout << std::endl;
  }
}
