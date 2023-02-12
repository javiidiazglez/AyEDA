// UNIVERSIDAD DE LA LAGUNA
// GRADO EN INGENIERIA INFORMATICA
// AUTOR: José Javier Díaz González
// FECHA: 04-03-2021
// E-MAIL: alu0101128894@ull.edu.es
// ASIGNATURA: Algoritmos y Estructras de datos Avanzados
// PRACTICA: P01 - Hormiga Laghton
// Referencias: https://es.wikipedia.org/wiki/Hormiga_de_Langton
// Nombre del archivo: ant.h

#ifndef ANT_H
#define ANT_H

#include <iostream>

#include "point2d.h"
#include "rotation.h"
#include "rule.h"
#include "vector.h"
#include "world.h"

class Rule;

class Ant {
  public:
    Point2di position;
    Rotation rotation;

    Ant();
    Ant(const Point2di& position);
    Ant(const Ant& ant);

    virtual ~Ant();

    void AddRule(Rule* rule);
    void Move(World& context);

    friend std::ostream& operator<<(std::ostream& os, const Ant& ant);
    void operator=(const Ant& ant);

  private:
    Vector<Rule*> rules_;
};

#endif
