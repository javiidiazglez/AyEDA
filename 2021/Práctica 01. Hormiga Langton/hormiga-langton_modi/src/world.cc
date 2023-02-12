// UNIVERSIDAD DE LA LAGUNA
// GRADO EN INGENIERIA INFORMATICA
// AUTOR: José Javier Díaz González
// FECHA: 04-03-2021
// E-MAIL: alu0101128894@ull.edu.es
// ASIGNATURA: Algoritmos y Estructras de datos Avanzados
// PRACTICA: P01 - Hormiga Laghton
// Referencias: https://es.wikipedia.org/wiki/Hormiga_de_Langton
// Nombre del archivo: world.cc

#include "../include/world.h"

World::World() {
}

World::World(int rows, int columns) : world_map_(rows, columns) {
  world_map_.Fill(WHITE);
}

World::World(const World& world) {
  *this = world;
}

World::~World() {}

char& World::At(int row, int column) {
  return world_map_[row][column];
}

const char& World::At(int row, int column) const {
  return world_map_[row][column];
}

void World::operator=(const World& world) {
  world_map_ = world.world_map_;
}

std::ostream& operator<<(std::ostream& os, const World& world) {
  for (size_t i = 0; i < world.world_map_.Rows(); ++i) {
    for (size_t j = 0; j < world.world_map_.Columns(); ++j) {
      os << world.world_map_[i][j];
    }
    os << std::endl;
  }
  return os;
}
