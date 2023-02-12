// UNIVERSIDAD DE LA LAGUNA
// GRADO EN INGENIERIA INFORMATICA
// AUTOR: José Javier Díaz González
// FECHA: 04-03-2021
// E-MAIL: alu0101128894@ull.edu.es
// ASIGNATURA: Algoritmos y Estructras de datos Avanzados
// PRACTICA: P01 - Hormiga Laghton
// Referencias: https://es.wikipedia.org/wiki/Hormiga_de_Langton
// Nombre del archivo: rule.h

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
    virtual bool Execute(World& context, Ant& ant) = 0; // iterfaz = metodo que no está implementado
};

#endif
