// UNIVERSIDAD DE LA LAGUNA
// GRADO EN INGENIERIA INFORMATICA
// AUTOR: José Javier Díaz González
// FECHA: 10-03-2021
// E-MAIL: alu0101128894@ull.edu.es
// ASIGNATURA: Algoritmos y Estructras de datos Avanzados
// PRACTICA: P02 - Hormiga Laghton Modificada
// Referencias: https://es.wikipedia.org/wiki/Hormiga_de_Langton
// Nombre del archivo: rule_white.h


#ifndef RULE_WHITE_H
#define RULE_WHITE_H

#include "rule.h"
#include "ant.h"

class RuleWhite : public Rule {
  public:
    virtual ~RuleWhite();
    bool Execute(World& context, Ant& ant); // metodo execute (el padre)
};

#endif
