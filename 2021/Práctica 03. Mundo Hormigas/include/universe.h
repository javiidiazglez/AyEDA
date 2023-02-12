// UNIVERSIDAD DE LA LAGUNA
// GRADO EN INGENIERIA INFORMATICA
// AUTOR: José Javier Díaz González
// FECHA: 10-03-2021
// E-MAIL: alu0101128894@ull.edu.es
// ASIGNATURA: Algoritmos y Estructras de datos Avanzados
// PRACTICA: P02 - Hormiga Laghton Modificada
// Referencias: https://es.wikipedia.org/wiki/Hormiga_de_Langton
// Nombre del archivo: universe_infinito.h

#ifndef UNIVERSE_H
#define UNIVERSE_H

#include "ant.h"
#include "world.h"


class Universe {
  public:
    Universe();    // filas columnas
    ~Universe();
    virtual void Run() = 0;   // funcion sin clase derivada
    virtual void SetAnts(std::vector<Ant> ants) = 0;
};

#endif
