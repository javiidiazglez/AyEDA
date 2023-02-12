// UNIVERSIDAD DE LA LAGUNA
// GRADO EN INGENIERIA INFORMATICA
// AUTOR: José Javier Díaz González
// FECHA: 04-03-2021
// E-MAIL: alu0101128894@ull.edu.es
// ASIGNATURA: Algoritmos y Estructras de datos Avanzados
// PRACTICA: P01 - Hormiga Laghton
// Referencias: https://es.wikipedia.org/wiki/Hormiga_de_Langton
// Nombre del archivo: universe.h

#ifndef UNIVERSE_H
#define UNIVERSE_H

#include "ant.h"
#include "world.h"
#include <thread>

class Universe {
  public:
    Universe(int rows, int columns); // protected rows y columns
    Universe(const Universe& universe);
    virtual ~Universe();
    virtual void Run();

    void SetAnt(const Ant& ant);
    virtual void FixAntPosition(Ant& ant);
    void operator=(const Universe& universe);
    friend std::ostream& operator<<(std::ostream& os, const Universe& universe);

 protected:
    int rows_;
    int columns_;
    World world_;   // almacena negro, blanco (no almacena ant)
    Ant ant_; // hormiga 1
};

#endif
