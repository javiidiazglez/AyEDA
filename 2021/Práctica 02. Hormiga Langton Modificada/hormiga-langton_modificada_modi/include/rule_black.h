// UNIVERSIDAD DE LA LAGUNA
// GRADO EN INGENIERIA INFORMATICA
// AUTOR: José Javier Díaz González
// FECHA: 10-03-2021
// E-MAIL: alu0101128894@ull.edu.es
// ASIGNATURA: Algoritmos y Estructras de datos Avanzados
// PRACTICA: P02 - Hormiga Laghton Modificada
// Referencias: https://es.wikipedia.org/wiki/Hormiga_de_Langton
// Nombre del archivo: rule_black.h

#ifndef RULE_BLACK_H
#define RULE_BLACK_H

#include "rule.h"
#include "ant.h"

class RuleBlack : public Rule {
  public:
    virtual ~RuleBlack();
    bool Execute(World& context, Ant& ant); // metodo execute (el padre)
};

#endif
