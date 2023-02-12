// UNIVERSIDAD DE LA LAGUNA
// GRADO EN INGENIERIA INFORMATICA
// AUTOR: José Javier Díaz González
// FECHA: 10-03-2021
// E-MAIL: alu0101128894@ull.edu.es
// ASIGNATURA: Algoritmos y Estructras de datos Avanzados
// PRACTICA: P02 - Hormiga Laghton Modificada
// Referencias: https://es.wikipedia.org/wiki/Hormiga_de_Langton
// Nombre del archivo: main.cc

/*
Modificación crear un nuevo estado '0' y que se expanda x3

Tengo creado el nuevo estado, se expande pero x1 por falta de tiempo (lo que le conté en el correo)

Los cambios que hice está en el  world.cc y world.h

Subo tanto el fichero sin_modi como con_modi (este)
*/

#include <iostream>
#include <cstring>

#include "../include/rule_black.h"
#include "../include/rule_white.h"
#include "../include/universe.h"

int main(int argc, char const *argv[]) {
  if (argc != 3) {
    std::cerr << "Forma de uso: ./hormiga <celdas eje y> <celdas eje x>" << std::endl;
    return 0;
  }

  Universe universe(atoi(argv[1]), atoi(argv[2]));
  Ant ant;
  ant.AddRule(new RuleBlack); //instancias a las clases
  ant.AddRule(new RuleWhite);
  universe.SetAnt(ant);   // la paso al universo
  universe.Run();
  
  return 0;
}
