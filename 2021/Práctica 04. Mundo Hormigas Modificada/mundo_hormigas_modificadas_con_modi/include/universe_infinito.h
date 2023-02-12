//////////////////////////////////////////////////////////////////////////////////
// Universidad de La Laguna                                                     //
// Escuela Superior de Ingeniería y Tecnología                                  //
// Grado en Ingeniería Informática                                              //
// Algoritmos y Estructuras de datos Avanzados                                  //
// Fecha: 24/03/2021                                                            //
// Autor: José Javier Díaz González (alu0101128894)                             //
//                                                                              //
// Práctica 4: Mundo Hormigas Modifcado                                         //
// Referencias: https://es.wikipedia.org/wiki/Hormiga_de_Langton                //
// Nombre del archivo: universe_infinito.h                                      //
//////////////////////////////////////////////////////////////////////////////////

#ifndef UNIVERSE_INFINITO_H
#define UNIVERSE_INFINITO_H

#include "ant.h"
#include "world_infinito.h"
#include "universe.h"
#include <thread>  // std::this_thread::sleep_for
#include <chrono> // std::chrono::milliseconds

class Universe_Infinito : public Universe {
  public:
    Universe_Infinito(int rows, int columns);    // filas columnas
    Universe_Infinito(const Universe_Infinito& universe);
    ~Universe_Infinito();

    void Run();   // funcion sin clase derivada
    void SetAnt(const Ant* ant);
    void SetAnts(std::vector<Ant> &ants);
    void CheckAndExpand(Ant& ant);  // Comprobar y expande
    void operator=(const Universe_Infinito& universe);
    friend std::ostream& operator<<(std::ostream& os, const Universe_Infinito& universe);

  protected:
    World* world_; // almacena negro, blanco (no almacena ant) -> puntero
    Ant* ant_;     // hormiga 1
    std::vector<Ant> hormigas_;
};

#endif
