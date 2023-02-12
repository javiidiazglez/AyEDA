// UNIVERSIDAD DE LA LAGUNA
// GRADO EN INGENIERIA INFORMATICA
// AUTOR: José Javier Díaz González
// FECHA: 10-03-2021
// E-MAIL: alu0101128894@ull.edu.es
// ASIGNATURA: Algoritmos y Estructras de datos Avanzados
// PRACTICA: P02 - Hormiga Laghton Modificada
// Referencias: https://es.wikipedia.org/wiki/Hormiga_de_Langton
// Nombre del archivo: universe.cc

#include "../include/universe.h"

Universe::Universe(int rows, int columns) : world_(rows, columns) {   // filas y columnas , y mundo filas y columnas
  // world_.At(0,0) = ROJO estado nuevo (probar)
}

Universe::Universe(const Universe& universe) {
  *this = universe;
}

Universe::~Universe() {}

void Universe::Run() {
  while (true) {
    Universe aux = *this; // auxiliar (universo anterior) ( a donde se desplaza la hormiga?) no sabemos el futuro, guardar el estado anterior
    std::cout << "La hormiga esta en: " << ant_ << std::endl;
    ant_.Move(world_);  // nuevo movimiento del mundo de la hormiga, hormiga muevete en (mundo)
    std::cout << "Se desplaza al: " << ant_.rotation.ToString() << std::endl; // sabemos la rotacion
    std::cout << aux << std::endl;  // mostramos el estado anterior
    CheckAndExpand(ant_);
    std::this_thread::sleep_for(std::chrono::milliseconds(600));
  }
}

void Universe::SetAnt(const Ant& ant) {
  ant_ = ant;
}

void Universe::CheckAndExpand(Ant& ant) {   // dado una hormiga 
  world_.CheckLimits(ant.position.y, ant.position.x);  // comprueba dentro de sus posiciones con los limites
}

std::ostream& operator<<(std::ostream& os, const Universe& universe) {  // Muestra por pantalla
  for (int i = universe.world_.MinRows(); i < universe.world_.MaxRows(); ++i) {   // 
    for (int j = universe.world_.MinColumns(); j < universe.world_.MaxColumns(); ++j) { // cada casilla del mundo (min y max)
      if (universe.ant_.position.x== j && universe.ant_.position.y == i)     // está la hormiga? se imprime ->           
        os << universe.ant_.rotation.GetRotation();   // caracter de la hormiga en cuestion
      else
        os << universe.world_.At(i, j); // mundo completo
    }
    std::cout << std::endl;
  }
  return os;
}

void Universe::operator=(const Universe& universe) {
  world_ = universe.world_;
  ant_ = universe.ant_;
}
