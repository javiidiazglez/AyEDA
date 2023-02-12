// UNIVERSIDAD DE LA LAGUNA
// GRADO EN INGENIERIA INFORMATICA
// AUTOR: José Javier Díaz González
// FECHA: 04-03-2021
// E-MAIL: alu0101128894@ull.edu.es
// ASIGNATURA: Algoritmos y Estructras de datos Avanzados
// PRACTICA: P01 - Hormiga Laghton
// Referencias: https://es.wikipedia.org/wiki/Hormiga_de_Langton
// Nombre del archivo: rule_black90.h

#ifndef RULE_BLACK90_H
#define RULE_BLACK90_H

#include "rule.h"
#include "ant.h"

class RuleBlack90 : public Rule {
    public:
    virtual ~RuleBlack90();
    bool Execute(World& context, Ant& ant); // metodo execute (el padre)
};

#endif
