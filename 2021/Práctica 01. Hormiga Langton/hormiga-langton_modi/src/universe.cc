// UNIVERSIDAD DE LA LAGUNA
// GRADO EN INGENIERIA INFORMATICA
// AUTOR: José Javier Díaz González
// FECHA: 04-03-2021
// E-MAIL: alu0101128894@ull.edu.es
// ASIGNATURA: Algoritmos y Estructras de datos Avanzados
// PRACTICA: P01 - Hormiga Laghton
// Referencias: https://es.wikipedia.org/wiki/Hormiga_de_Langton
// Nombre del archivo: universe.cc

#include "../include/universe.h"

Universe::Universe(int rows, int columns) : world_(rows, columns) {
  rows_ = rows;
  columns_ = columns;
}

Universe::Universe(const Universe& universe) {
  *this = universe;
}

Universe::~Universe() {}

void Universe::Run() {
  while (true) {
    Universe aux = *this; // auxiliar (universo anterior)
    std::cout << "La hormiga esta en: " << ant_ << std::endl;
    ant_.Move(world_);  // nuevo movimiento del mundo de la hormiga, hormiga muevete en (mundo)
    std::cout << "Se desplaza al: " << ant_.rotation.ToString() << std::endl;  // sabemos la rotacion
    std::cout << aux << std::endl; // mostramos el estado anterior
    FixAntPosition(ant_); // mundo redondo, sin salir
    std::this_thread::sleep_for(std::chrono::milliseconds(1000)); // camino con ticks 
  }
}

void Universe::SetAnt(const Ant& ant) {
  ant_ = ant;
}

void Universe::FixAntPosition(Ant& ant) {   // Coordenadas de la hormiga sin salir
  if (ant.position.x < 0)
    ant.position.x = world_.Columns() - 1;
  else if (ant.position.x >= world_.Columns())
    ant.position.x = 0;

  if (ant.position.y < 0)
    ant.position.y = world_.Rows() - 1;
  else if (ant.position.y >= world_.Rows())
    ant.position.y = 0;
}

std::ostream& operator<<(std::ostream& os, const Universe& universe) { // Muestra por pantalla
  for (int i = 0; i < universe.world_.Rows(); ++i) {
    for (int j = 0; j < universe.world_.Columns(); ++j) { // cada casilla del mundo
      if (universe.ant_.position.x == j && universe.ant_.position.y == i) // está la hormiga?
        os << universe.ant_.rotation.GetRotation(); // caracter de la hormiga en cuestion
      else
        os << universe.world_.At(i, j); // mundo completo
    }
    std::cout << std::endl;
  }
  return os;
}

void Universe::operator=(const Universe& universe) {
  rows_ = universe.rows_;
  columns_ = universe.columns_;
  world_ = universe.world_;
  ant_ = universe.ant_;
}
