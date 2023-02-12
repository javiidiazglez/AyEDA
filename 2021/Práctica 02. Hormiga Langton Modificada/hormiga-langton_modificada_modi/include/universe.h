// UNIVERSIDAD DE LA LAGUNA
// GRADO EN INGENIERIA INFORMATICA
// AUTOR: José Javier Díaz González
// FECHA: 10-03-2021
// E-MAIL: alu0101128894@ull.edu.es
// ASIGNATURA: Algoritmos y Estructras de datos Avanzados
// PRACTICA: P02 - Hormiga Laghton Modificada
// Referencias: https://es.wikipedia.org/wiki/Hormiga_de_Langton
// Nombre del archivo: universe.h

#ifndef UNIVERSE_H
#define UNIVERSE_H

#include "ant.h"
#include "world.h"
#include <thread>  // std::this_thread::sleep_for
#include <chrono> // std::chrono::milliseconds

class Universe {
  public:
    Universe(int rows, int columns);    // filas columnas
    Universe(const Universe& universe);
    ~Universe();
    void Run();   // funcion sin clase derivada

    void SetAnt(const Ant& ant);
    void CheckAndExpand(Ant& ant);  // Comprobar y expande
    void operator=(const Universe& universe);
    friend std::ostream& operator<<(std::ostream& os, const Universe& universe);

  protected:
    World world_; // almacena negro, blanco (no almacena ant)
    Ant ant_;     // hormiga 1
};

#endif
