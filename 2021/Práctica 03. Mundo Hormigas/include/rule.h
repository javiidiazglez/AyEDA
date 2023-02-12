//////////////////////////////////////////////////////////////////////////////////
// Universidad de La Laguna                                                     //
// Escuela Superior de Ingeniería y Tecnología                                  //
// Grado en Ingeniería Informática                                              //
// Algoritmos y Estructuras de datos Avanzados                                  //
// Fecha: 17/03/2021                                                            //
// Autor: José Javier Díaz González (alu0101128894)                             //
//                                                                              //
// Práctica 3: Mundo Hormigas                                                   //
// Referencias: https://es.wikipedia.org/wiki/Hormiga_de_Langton                //
// Nombre del archivo: rule.h                                                   //
//////////////////////////////////////////////////////////////////////////////////

#ifndef RULE_H
#define RULE_H

#include <cmath>
#include <iostream>

#include "world.h"
#include "point2d.h"
#include "ant.h"

class Ant;

class Rule {
  public:
    virtual ~Rule();
    virtual bool Execute(World& context, Ant& ant) = 0; // interfaz = metodo que no está implementado
};

#endif
