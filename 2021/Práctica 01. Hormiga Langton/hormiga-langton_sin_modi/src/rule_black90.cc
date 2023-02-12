// UNIVERSIDAD DE LA LAGUNA
// GRADO EN INGENIERIA INFORMATICA
// AUTOR: José Javier Díaz González
// FECHA: 04-03-2021
// E-MAIL: alu0101128894@ull.edu.es
// ASIGNATURA: Algoritmos y Estructras de datos Avanzados
// PRACTICA: P01 - Hormiga Laghton
// Referencias: https://es.wikipedia.org/wiki/Hormiga_de_Langton
// Nombre del archivo: rule_black90.cc

#include "../include/rule_black90.h"

RuleBlack90::~RuleBlack90() {}

bool RuleBlack90::Execute(World& context, Ant& ant) {
  if (context.At(ant.position.y, ant.position.x) != BLACK) return false; // si en la posicion que está != negro (no es tu regla)
  context.At(ant.position.y, ant.position.x) = WHITE; // si hay
  ++ant.rotation; // gira 90 a la derecha (si ponemos otra ++ serían 90+90 = 180º)
  ant.position = ant.position + ant.rotation.GetDirection(); // desplazate hacia adelante, en esa dirección
  return true;
}
