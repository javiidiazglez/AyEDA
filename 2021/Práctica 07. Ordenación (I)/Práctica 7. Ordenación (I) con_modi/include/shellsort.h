
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
// Nombre del archivo: shellsort.h                                               //
//////////////////////////////////////////////////////////////////////////////////

#include <vector>

class shellsort
{
private:
  std::vector<int> shell_v;
  int shell_sz;
  bool cambio;

public:
  shellsort();
  ~shellsort();
  std::vector<int> metodo(std::vector<int> a, int sz);
  void swap_pos(int i, int j);
};
