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
// Nombre del archivo: rule_black.h                                             //
//////////////////////////////////////////////////////////////////////////////////

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
