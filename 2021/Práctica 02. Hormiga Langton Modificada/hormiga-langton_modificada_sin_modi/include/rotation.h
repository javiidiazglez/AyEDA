// UNIVERSIDAD DE LA LAGUNA
// GRADO EN INGENIERIA INFORMATICA
// AUTOR: José Javier Díaz González
// FECHA: 10-03-2021
// E-MAIL: alu0101128894@ull.edu.es
// ASIGNATURA: Algoritmos y Estructras de datos Avanzados
// PRACTICA: P02 - Hormiga Laghton Modificada
// Referencias: https://es.wikipedia.org/wiki/Hormiga_de_Langton
// Nombre del archivo: rotacion.h

#ifndef ROTATION_H
#define ROTATION_H

#include <cassert>
#include <iostream>
#include <string>

#include "point2d.h"
#include "vector.h"

enum RotationE { UP = '^',    // enumerar
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
