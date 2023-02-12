// /*
//   Universidad de La Laguna
//   Escuela Superior de Ingeniería y Tecnología
//   Grado en Ingeniería Informática          
//   Algoritmos y Estructuras de datos Avanzados
//   Fecha: 29/04/2022     
//   Autor: José Javier Díaz González (alu0101128894)
//   Práctica 5. Ordenación                           
//   Referencias: https://es.wikipedia.org/wiki/Algoritmo_de_ordenamiento 
//   Nombre del archivo: radixsort.h                  
// */

// #ifndef RADIXSORT_H
// #define RADIXSORT_H

// #include "algorithm.h"

// template <class Clave>
// class radixsort : public Algorithm<Clave> {
//  public:
//   using Algorithm<Clave>::Algorithm;
//   ~radixsort() {}
//   std::vector<Clave> metodo(std::vector<Clave> vector, int sz);
//   int getMax(std::vector<Clave> vector, int sz);
//   void countingSort(std::vector<Clave> vector, int sz, int div);

//  private:
//   int sz;
// };

// template <class Clave>
// int radixsort<Clave>::getMax(std::vector<Clave> vector, int sz) {

//   int max = vector[0];
//   for (int i = 1; i < sz; i++) {
//     if (vector[i] > max)
//     max = vector[i];
//   }
//   return max;
// }

// template <class Clave>
// void radixsort<Clave>::countingSort(std::vector<Clave> vector, int sz, int div) {

//   int output[sz];
//   int count[10] = {0};

//   for(int i = 0; i < sz; i++)
//     count[ (vector[i]/div)%10 ]++;

//   for(int i = 1; i < 10; i++)
//     count[i] += count[i - 1];
  
//   for(int i = sz - 1; i >= 0; i--) {
//     output[count[(vector[i] / div) % 10] - 1] = vector[i];
//     count[ (vector[i] / div) % 10 ]--;
//   }

//   for(int i = 0; i < sz; i++) {
//     vector[i] = output[i];
//   }

//   for (int i = 0; i < sz; i++) {
//     std::cout << vector[i] << " ";
//   }

// }
// template <class Clave>
// std::vector<Clave> radixsort<Clave>::metodo(std::vector<Clave> vector, int sz) {
//   unsigned m = getMax(vector, sz); // valor maximo
  
//   for (int div = 1; m/div > 0; div *= 10) {
//     countingSort(vector, sz, div); // ordena
//   }
//   //return m;
// }

// #endif