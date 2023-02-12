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
// Nombre del archivo: world_infinito.h                                         //
//////////////////////////////////////////////////////////////////////////////////

#ifndef WORLD_INFINITO_H
#define WORLD_INFINITO_H

#include "world.h"

class WorldInfinito : public World {
  using World::World; // heredo el constructor
  void CheckLimits(int row, int column);
};

#endif
