// UNIVERSIDAD DE LA LAGUNA
// GRADO EN INGENIERIA INFORMATICA
// AUTOR: José Javier Díaz González
// FECHA: 04-03-2021
// E-MAIL: alu0101128894@ull.edu.es
// ASIGNATURA: Algoritmos y Estructras de datos Avanzados
// PRACTICA: P01 - Hormiga Laghton
// Referencias: https://es.wikipedia.org/wiki/Hormiga_de_Langton
// Nombre del archivo: ant.cc

#include "../include/ant.h"

Ant::Ant() {
  this->position = Point2di(5, 5); // Posicion de la hormiga en el (5,5)
}

Ant::Ant(const Point2di& position) {
  this->position = position;
}

Ant::Ant(const Ant& ant) {
  *this = ant;
}

Ant::~Ant() {
}

void Ant::Move(World& context) { // Poliformismo dinámico
  bool stop = false;
  for (size_t i = 0; i < rules_.Size(); ++i) {
    stop = rules_[i]->Execute(context, *this); // itera todas las reglas (negra, o blancas) (interfaz)
    if (stop) break;  // si encuentra = para
  }
}

void Ant::operator=(const Ant& ant) {
  position = ant.position;
  rotation = ant.rotation;
  rules_ = ant.rules_;
}

void Ant::AddRule(Rule* rule) {
  rules_.PushBack(rule);
}

std::ostream& operator<<(std::ostream& os, const Ant& ant) {
  os << ant.position.x << ", " << ant.position.y; // posiciones x e y del mundo
  return os;
}
