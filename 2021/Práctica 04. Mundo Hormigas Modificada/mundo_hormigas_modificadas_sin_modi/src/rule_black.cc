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
// Nombre del archivo: rule_black.cc                                            //
//////////////////////////////////////////////////////////////////////////////////

#include "../include/rule_black.h"

RuleBlack::~RuleBlack() {}

void RuleBlack::rotateAnt(Ant& ant) {
  if (ant.getModifiedAnt() == true) {
    ++ant.rotation;   // 45 grados -> modificada
  } else if (ant.getModifiedAnt() == false) {
    ++ant.rotation;   // 90  -> hormiga normal
    ++ant.rotation;
  }
}

void RuleBlack::moveAnt(Ant& ant) {
  ant.position = ant.position + ant.rotation.GetDirection();  // desplazate hacia adelante, en esa dirección
}

bool RuleBlack::Execute(World* context, Ant& ant) { // puntero (usamos ->)
  if (context->At(ant.position.y, ant.position.x) != BLACK) return false;  // si en la posicion que está != negro (no es tu regla)
  context->At(ant.position.y, ant.position.x) = WHITE; // si hay
  rotateAnt(ant);
  moveAnt(ant);
  return true;
}
