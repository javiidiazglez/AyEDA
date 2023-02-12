
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
// Nombre del archivo: quicksort.h                                              //
//////////////////////////////////////////////////////////////////////////////////

#include <vector>

class quicksort
{
  private:
    std::vector<int> Quicksort_v;
    int Quicksort_sz;

  public:
    quicksort();
    ~quicksort();

    std::vector<int> metodo(std::vector<int> a, int sz);
    void quickie(int inicial, int fin);
    void swap_pos(int i, int j);
    void show_quickie(int i, int h);

};
