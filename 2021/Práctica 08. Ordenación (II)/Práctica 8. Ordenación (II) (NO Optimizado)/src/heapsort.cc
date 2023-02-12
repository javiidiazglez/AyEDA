#include "../include/heapsort.h"

#include <iostream>
#include <vector>

heapsort::heapsort() {}
heapsort::~heapsort() {}

//template <class Clave>
std::vector<int> heapsort::metodo(std::vector<int> a, int sz)
{
  heap_v = a;
  heap_sz = sz;
  for (int i = heap_sz / 2 - 1; i >= 0; i--)
  {
    baja(i, heap_sz);
  }
  for (int i = heap_sz - 1; i >= 0; i--)
  {
    swap_pos(0, i);
    baja(0, i);
  }
  return heap_v;
}

//template <class Clave>
void heapsort::baja(int i, int sz)
{
  int largest = i;
  int l = 2 * i + 1;
  int r = 2 * i + 2;
  if (l < sz && heap_v[l] > heap_v[largest])
    largest = l;
  //contador_global++;
  if (r < sz && heap_v[r] > heap_v[largest])
    largest = r;
  //contador_global++;
  if (largest != i)
  {
    swap_pos(i, largest);
    baja(largest, sz);
  }
  //contador_global++;
}
//template <class Clave>
void heapsort::swap_pos(int i, int j)
{
  if (i != j)
  { 
    int aux;
    aux = heap_v[i];
    heap_v[i] = heap_v[j];
    heap_v[j] = aux;

    std::cout << std::endl
    << "< ";
    for (int h = 0; h < heap_sz; h++)
    {
      if (h == i)
      {
        std::cout << "\033[1;31m" << heap_v[h] << "\033[0m, ";
      }
      if (h == j)
      {
        std::cout << "\033[1;32m" << heap_v[h] << "\033[0m, ";
      }
      if (h != i && h != j)
      {
        std::cout << heap_v[h] << ", ";
      }
    }
    std::cout << ">";
    //std::cout << std::endl;
  }
}
