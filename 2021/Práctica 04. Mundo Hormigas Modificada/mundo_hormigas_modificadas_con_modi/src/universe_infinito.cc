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
// Nombre del archivo: universe_infinito.cc                                     //
//////////////////////////////////////////////////////////////////////////////////

#include "../include/universe_infinito.h"

Universe_Infinito::Universe_Infinito(int rows, int columns) {   // filas y columnas 
  // world_->At(0,0) = ROJO estado nuevo (probar)
    world_ = new WorldInfinito(rows, columns); // instacion mundo rows y columns
}
Universe_Infinito::Universe_Infinito(const Universe_Infinito& universe) {
  *this = universe;
}

Universe_Infinito::~Universe_Infinito() {}


void Universe_Infinito::Run() {
  while (true) {
    Universe_Infinito aux = *this; // auxiliar (universo anterior) ( a donde se desplaza la hormiga?) no sabemos el futuro, guardar el estado anterior
    //std::cout << "La hormiga esta en: " << ant_ << std::endl;
    for (int tmp = 0; tmp < hormigas_.size(); tmp++)
    {
      hormigas_[tmp].Move(world_);
      std::cout << "- La hormiga (" << tmp << ") está en " << hormigas_[tmp] 
      << " y se desplaza al: " << hormigas_[tmp].rotation.ToString() << std::endl;
    }
    std::cout << "\n";
    //ant_.Move(world_);  // nuevo movimiento del mundo de la hormiga, hormiga muevete en (mundo)
    //std::cout << "Se desplaza al: " << ant_.rotation.ToString() << std::endl; // sabemos la rotacion
    std::cout << aux << std::endl;  // mostramos el estado anterior
    for (int tmp = 0; tmp < hormigas_.size(); tmp++)
    {
      CheckAndExpand(hormigas_[tmp]);
    }
    //CheckAndExpand(ant_);
    std::this_thread::sleep_for(std::chrono::milliseconds(1000));
  }
}

void Universe_Infinito::SetAnt(const Ant& ant) { //Modi
  ant_ = ant;
}

void Universe_Infinito::SetAnts(std::vector<Ant> &ants)
{
  /* Copiamos las Hormigas en el vector de la clase.
    El problema es que machaca/borra el valor de ModifiedAnt y los coloca todos a false.
    Para solucionarlo, copiamos ese valor del vector ants en su hormiga correspondiente
    del vector hormigas_.
    Ahora distinguimos entre Hormigas de Langton Normales y Modificadas.
  */
  hormigas_= ants;
  for (int i = 0; i < hormigas_.size(); i++) {
    hormigas_[i].setModifiedAnt(ants[i].getModifiedAnt());
  }
}
void Universe_Infinito::CheckAndExpand(Ant& ant) {   // dado una hormiga
  world_->CheckLimits(ant.position.y, ant.position.x);  // comprueba dentro de sus posiciones con los limites
}

std::ostream& operator<<(std::ostream& os, const Universe_Infinito& universe) {  // Muestra por pantalla
  bool is_in_position = false;
  for (int i = universe.world_->MinRows(); i < universe.world_->MaxRows(); ++i) {   //
    for (int j = universe.world_->MinColumns(); j < universe.world_->MaxColumns(); ++j) { // cada casilla del mundo (min y max)
      is_in_position = false;
      for (int aux = 0; aux < universe.hormigas_.size() && !is_in_position; aux++) {
        if (universe.hormigas_[aux].position.x== j && universe.hormigas_[aux].position.y == i) {     // está la hormiga? se imprime ->
          os << universe.hormigas_[aux].rotation.GetRotation();   // caracter de la hormiga en cuestion
          is_in_position = true;        
        }
      }
      if (!is_in_position) {
        os << universe.world_->At(i, j); // mundo completo
      }
    }
    os << std::endl;
  }
  return os;
}

void Universe_Infinito::operator=(const Universe_Infinito& universe) {
  world_ = universe.world_;
  ant_ = universe.ant_;
  hormigas_ = universe.hormigas_;
}
