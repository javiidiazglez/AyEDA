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
// Nombre del archivo: rotation.h                                               //
//////////////////////////////////////////////////////////////////////////////////

#ifndef ROTATION_H
#define ROTATION_H

#include <cassert>
#include <iostream>
#include <string>
#include <map>
#include "point2d.h"
#include "vector.h"

enum RotationE { UP = '^',    
                 DOWN = 'v',
                 RIGHT = '>',
                 LEFT = '<',
                 UP_RIGHT = 'a',
                 UP_LEFT = 'b',
                 DOWN_LEFT = 'd',
                 DOWN_RIGHT = 'c'
};

class Rotation {
 public:
  Rotation(); 
  Rotation(RotationE actual); 
  Rotation(const Rotation& rotation);

  std::string ToString();             // convierte la rotacion UP, DOWN -> rotacion.cc (sale norte, sur, este, oeste)
  void Set(RotationE new_rotation);   // nueva rotacion
  char GetRotation() const;           // ^ v > < a b d c
  Point2di GetDirection() const;      // const (constante = evita modificar)

  Point2di operator++();            // sentido derecho -> ^ a > c v d < b     (para arriba es negativo)   
  Point2di operator--();            // sentido izquierdo -> ^ b < d v c > a  vector tamaño 1 [0,1]
  void operator=(const Rotation& rotation);

 private:
  size_t actual_;

  Vector<RotationE> Rotations() const;  // rotaciones  MAPEADO en un vector 
  Vector<Point2di> MapRotations() const;  // direcciones
};

#endif
