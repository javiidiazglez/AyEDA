// UNIVERSIDAD DE LA LAGUNA
// GRADO EN INGENIERIA INFORMATICA
// AUTOR: José Javier Díaz González
// FECHA: 04-03-2021
// E-MAIL: alu0101128894@ull.edu.es
// ASIGNATURA: Algoritmos y Estructras de datos Avanzados
// PRACTICA: P01 - Hormiga Laghton
// Referencias: https://es.wikipedia.org/wiki/Hormiga_de_Langton
// Nombre del archivo: rotacion.h

#ifndef ROTATION_H
#define ROTATION_H

#include <cassert>
#include <string>
#include <iostream>

#include "vector.h"
#include "point2d.h"

enum RotationE { UP = '^',    // enumerar
                 DOWN = 'v',
                 RIGHT = '>',
                 LEFT = '<' };

class Rotation {
  public:
    Rotation();
    Rotation(RotationE actual);
    Rotation(const Rotation& rotation);

    std::string ToString(); // convierte la rotacion UP, DOWN -> rotacion.cc (sale norte, sur, este, oeste)
    void Set(RotationE new_rotation);   // nueva rotacion
    char GetRotation() const;   // ^ v > <
    Point2di GetDirection() const; // const (constante = evita modificar)

    Point2di operator++();  // sentido derecho -> ^ > v <     (para arriba es negativo)   
    Point2di operator--();  // sentido izquierdo -> ^ < v >   vector tamaño 1 [0,1]    
    void operator=(const Rotation& rotation);

 private:
    size_t actual_;

    Vector<RotationE> Rotations() const; // rotaciones  MAPEADO en un vector 
    Vector<Point2di> MapRotations() const; // direcciones
};

#endif
