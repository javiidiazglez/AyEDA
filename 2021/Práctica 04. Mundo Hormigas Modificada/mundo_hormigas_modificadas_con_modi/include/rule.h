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
    virtual bool Execute(World* context, Ant& ant) = 0; // interfaz = metodo que no está implementado -> puntero
    virtual void rotateAnt(Ant& ant) = 0;
    virtual void moveAnt(Ant& ant) = 0;
};

#endif
