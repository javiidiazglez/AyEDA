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
// Nombre del archivo: rule_black.h                                             //
//////////////////////////////////////////////////////////////////////////////////

#ifndef RULE_BLACK_H
#define RULE_BLACK_H

#include "rule.h"
#include "ant.h"

class RuleBlack : public Rule { // heredas del rule
  public:
    virtual ~RuleBlack();

    bool Execute(World* context, Ant& ant); // metodo execute (el padre) -> puntero
    void rotateAnt(Ant& ant);
    void moveAnt(Ant& ant);
};

#endif
