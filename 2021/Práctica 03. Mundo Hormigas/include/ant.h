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
// Nombre del archivo: ant.h                                                    //
//////////////////////////////////////////////////////////////////////////////////

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
  void set_pos(int x, int y);

  virtual ~Ant();

  void AddRule(Rule* rule);
  void Move(World& context);

  friend std::ostream& operator<<(std::ostream& os, const Ant& ant);
  friend bool operator< (const Ant& ant1, const Ant& ant2);
  void operator=(const Ant& ant);

 private:
  Vector<Rule*> rules_; // vector de reglas
};

#endif
