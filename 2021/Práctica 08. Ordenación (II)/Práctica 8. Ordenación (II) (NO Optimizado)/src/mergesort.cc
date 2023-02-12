
#include "../include/mergesort.h"

#include <iostream>
#include <vector>

mergesort::mergesort() {}
mergesort::~mergesort() {}

//template<class Clave>
std::vector<int> mergesort::metodo(std::vector<int> a, int sz)
{
  //contador_global = 0;
  merge_v = a;
  merge_sz = sz;
  auxilar = merge_v;
  merge_sort(0, merge_sz - 1);
  return merge_v;
}

//template <class Clave>
void mergesort::merge_sort(int inic, int fin)
{
  int centro, i, j, k;
  if (inic < fin)
  {
    centro = (inic + fin) / 2;
    merge_sort(inic, centro);
    merge_sort(centro + 1, fin);
    i = inic;
    j = centro + 1;
    k = inic;
    while ((i <= centro) && (j <= fin))
    {
      if (merge_v[i] < merge_v[j])
      {
        auxilar[k] = merge_v[i];
        show_merge_changes(k);
        i++;
      }
      else
      {
        auxilar[k] = merge_v[j];
        show_merge_changes(k);
        j++;
      }
      //contador_global++;
      k++;
    }
    if (i > centro)
    {
      while (j <= fin)
      {
        auxilar[k] = merge_v[j];
        show_merge_changes(k);
        j++;
        k++;
      }
    }
    else
    {
      while (i <= centro)
      {
        auxilar[k] = merge_v[i];
        show_merge_changes(k);
        i++;
        k++;
      }
    }
    merge_v = auxilar;
  }
}
//template <class Clave>
void mergesort::show_merge_changes(int i)
{
  //contador_swap++;
  std::cout << std::endl
  << "< ";
  for (int j = 0; j < merge_sz; j++)
  {
    if (j == i)
    {
      std::cout << "\033[1;32m" << auxilar[j] << "\033[0m, ";
    }
    else
    {
      std::cout << auxilar[j] << ", ";
    }
  }
  std::cout << ">";
  //std::cout << std::endl;
}
