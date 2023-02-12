// UNIVERSIDAD DE LA LAGUNA
// GRADO EN INGENIERIA INFORMATICA
// AUTOR: José Javier Díaz González
// FECHA: 04-03-2021
// E-MAIL: alu0101128894@ull.edu.es
// ASIGNATURA: Algoritmos y Estructras de datos Avanzados
// PRACTICA: P01 - Hormiga Laghton
// Referencias: https://es.wikipedia.org/wiki/Hormiga_de_Langton
// Nombre del archivo: rule_white90.cc

#include "../include/rule_white90.h"

RuleWhite90::~RuleWhite90() {}

bool RuleWhite90::Execute(World& context, Ant& ant) {
  if (context.At(ant.position.y, ant.position.x) != WHITE) return false; // si en la posicion que está != blanco (no es tu regla)
  context.At(ant.position.y, ant.position.x) = BLACK; // si hay
  --ant.rotation; // gira 90 a la izquierda
  ant.position = ant.position + ant.rotation.GetDirection();    // desplazate hacia adelante, en esa dirección
  return true;
}
