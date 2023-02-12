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
// Nombre del archivo: universe_finito.h                                        //
//////////////////////////////////////////////////////////////////////////////////

#ifndef UNIVERSE_FINITO_H
#define UNIVERSE_FINITO_H

#include "ant.h"
#include "universe.h"
#include "world_finito.h"
#include <thread>
class Universe;

class Universe_Finito : public Universe  {
  public:
    Universe_Finito(int rows, int columns); // filas columnas
    Universe_Finito(const Universe_Finito& universe);
    virtual ~Universe_Finito();
    virtual void Run();   // funcion clase derivada

    void SetAnt(const Ant* ant);
    void SetAnts(std::vector<Ant> &ants);
    virtual void FixAntPosition(Ant& ant);   // Coordenadas de la hormiga sin salir
    void operator=(const Universe_Finito& universe);
    friend std::ostream& operator<<(std::ostream& os, const Universe_Finito& universe);

 protected:
    int rows_;       // filas protegidas
    int columns_;    // columnas protegidas
    World* world_;   // almacena negro, blanco (no almacena ant) -> puntero
    Ant* ant_;       // hormiga 1
    std::vector<Ant> hormigas_;
};

#endif
