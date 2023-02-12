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
// Nombre del archivo: universe_finito.cc                                       //
//////////////////////////////////////////////////////////////////////////////////

#include "../include/universe_finito.h"

Universe_Finito::Universe_Finito(int rows, int columns) : world_(rows, columns) { // filas y columnas , y mundo filas y columnas
  rows_ = rows;     // declaro filas (protegida .h)
  columns_ = columns;
}

Universe_Finito::Universe_Finito(const Universe_Finito& universe) {
  *this = universe;
}

Universe_Finito::~Universe_Finito() {}

void Universe_Finito::Run() {
  while (true) {
    Universe_Finito aux = *this; // auxiliar (universo anterior) ( a donde se desplaza la hormiga?) no sabemos el futuro, guardar el estado anterior
    for (int tmp = 0; tmp < hormigas_.size(); tmp++)
    {
      hormigas_[tmp].Move(world_);
      std::cout << "- La hormiga (" << tmp << ") está en: " << hormigas_[tmp] 
      << " y se desplaza al: " << hormigas_[tmp].rotation.ToString() << std::endl;
    }
    std::cout << "\n";
    std::cout << aux << std::endl; // mostramos el estado anterior
    for (int tmp = 0; tmp < hormigas_.size(); tmp++)
    {
      FixAntPosition(hormigas_[tmp]);
    }
    //FixAntPosition(ant_); // mundo redondo, sin salir
    std::this_thread::sleep_for(std::chrono::milliseconds(600)); // camino con ticks
  }
}

void Universe_Finito::SetAnt(const Ant& ant) {
  ant_ = ant;
}
void Universe_Finito::SetAnts(std::vector<Ant> ants)
{
  hormigas_=ants;
}

void Universe_Finito::FixAntPosition(Ant& ant) {   // Coordenadas de la hormiga sin salir
  if (ant.position.x < 0)
    ant.position.x = world_.Columns() - 1;
  else if (ant.position.x >= world_.Columns())
    ant.position.x = 0;

  if (ant.position.y < 0)
    ant.position.y = world_.Rows() - 1;
  else if (ant.position.y >= world_.Rows())
    ant.position.y = 0;
}

std::ostream& operator<<(std::ostream& os, const Universe_Finito& universe) { // Muestra por pantalla
  for (int i = 0; i < universe.world_.Rows(); ++i) {
    for (int j = 0; j < universe.world_.Columns(); ++j) { // cada casilla del mundo
      for (int aux = 0; aux < universe.hormigas_.size(); aux++) {
      if (universe.hormigas_[aux].position.x== j && universe.hormigas_[aux].position.y == i) // está la hormiga? se imprime ->
        os << universe.hormigas_[aux].rotation.GetRotation(); // caracter de la hormiga en cuestion
      else
        os << universe.world_.At(i, j); // mundo completo
      }
    }
    std::cout << std::endl;
  }
  return os;
}

void Universe_Finito::operator=(const Universe_Finito& universe) {
  rows_ = universe.rows_;
  columns_ = universe.columns_;
  world_ = universe.world_;
  ant_ = universe.ant_;
  hormigas_ = universe.hormigas_;
}
