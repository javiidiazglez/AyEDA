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
// Nombre del archivo: rule_white.cc                                            //
//////////////////////////////////////////////////////////////////////////////////

#include "../include/rule_white.h"

RuleWhite::~RuleWhite() {}

void RuleWhite::rotateAnt(Ant& ant) {
  if (ant.getModifiedAnt() == true) {
    --ant.rotation; // 45 grados -> modificada
  } else if (ant.getModifiedAnt() == false) {
    --ant.rotation;
    --ant.rotation; // 90 grados -> normal
  }
}

void RuleWhite::moveAnt(Ant& ant) {
  ant.position = ant.position + ant.rotation.GetDirection();    // desplazate hacia adelante, en esa dirección
}

bool RuleWhite::Execute(World* context, Ant& ant) { // puntero (usamos ->)
  if (context->At(ant.position.y, ant.position.x) != WHITE) return false;  // si en la posicion que está != blanco (no es tu regla)
  context->At(ant.position.y, ant.position.x) = BLACK;  // si hay
  rotateAnt(ant);
  moveAnt(ant);
  return true;
}
