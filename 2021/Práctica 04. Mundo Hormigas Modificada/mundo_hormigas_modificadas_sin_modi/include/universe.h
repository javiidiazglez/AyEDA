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
// Nombre del archivo: universe.h                                               //
//////////////////////////////////////////////////////////////////////////////////
#ifndef UNIVERSE_H
#define UNIVERSE_H

#include "ant.h"
#include "world.h"


class Universe {
  public:
    Universe();    // filas columnas
    ~Universe();
    virtual void Run()=0;   // funcion sin clase derivada. Este es el método que actualiza el mundo.
    virtual void SetAnts(std::vector<Ant> &ants) = 0;
};

#endif
