
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
// Nombre del archivo: insercion.h                                              //
//////////////////////////////////////////////////////////////////////////////////

//template<class int>
#include <vector>

class insercion
{
  private:
    std::vector<int> insercion_v;
    int insercion_sz;

  public:
    insercion();
    ~insercion();
    std::vector<int> metodo(std::vector<int> a, int sz);
    void show_changes(int, int);
};
