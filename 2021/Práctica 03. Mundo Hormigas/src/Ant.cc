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
// Nombre del archivo: ant.cc                                                   //
//////////////////////////////////////////////////////////////////////////////////

#include "../include/ant.h"

Ant::Ant() {
  this->position = Point2di(0, 0);  // Posicion de la hormiga en el (5,5)
}
void Ant::set_pos(int x,int y) {
  this->position = Point2di(x, y);
}
Ant::Ant(const Point2di& position) {
  this->position = position;
}

Ant::Ant(const Ant& ant) {
  *this = ant;
}

Ant::~Ant() {
}

void Ant::Move(World& context) {  // Poliformismo dinámico
  bool stop = false;
  for (size_t i = 0; i < rules_.Size(); ++i) {    // Ejemplo: regla[0] es la regla que estoy? si? = paro
    stop = rules_[i]->Execute(context, *this);    // itera todas las reglas (negra, o blancas) (interfaz) (execute)
    if (stop) break;    // si encuentra = para
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
  os <<"x: "<< ant.position.x << ", y: " << ant.position.y; // posiciones x e y del mundo
  return os;
}

bool operator< (const Ant& ant1, const Ant& ant2)
{
    return (ant1.position.x*10)+ant1.position.y < (ant2.position.x*10)+ant2.position.y;
}
