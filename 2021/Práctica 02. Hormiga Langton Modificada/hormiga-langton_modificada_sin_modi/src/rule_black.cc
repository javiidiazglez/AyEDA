// UNIVERSIDAD DE LA LAGUNA
// GRADO EN INGENIERIA INFORMATICA
// AUTOR: José Javier Díaz González
// FECHA: 10-03-2021
// E-MAIL: alu0101128894@ull.edu.es
// ASIGNATURA: Algoritmos y Estructras de datos Avanzados
// PRACTICA: P02 - Hormiga Laghton Modificada
// Referencias: https://es.wikipedia.org/wiki/Hormiga_de_Langton
// Nombre del archivo: rule_black.cc

#include "../include/rule_black.h"

RuleBlack::~RuleBlack() {}

bool RuleBlack::Execute(World& context, Ant& ant) {
  if (context.At(ant.position.y, ant.position.x) != BLACK) return false;  // si en la posicion que está != negro (no es tu regla)
  context.At(ant.position.y, ant.position.x) = WHITE; // si hay
  ++ant.rotation; // Tras la modificacion por cada -- o ++ se hacen 45 grados
  ant.position = ant.position + ant.rotation.GetDirection();  // desplazate hacia adelante, en esa dirección
  return true;
}
