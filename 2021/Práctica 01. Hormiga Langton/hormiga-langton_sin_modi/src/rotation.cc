// UNIVERSIDAD DE LA LAGUNA
// GRADO EN INGENIERIA INFORMATICA
// AUTOR: José Javier Díaz González
// FECHA: 04-03-2021
// E-MAIL: alu0101128894@ull.edu.es
// ASIGNATURA: Algoritmos y Estructras de datos Avanzados
// PRACTICA: P01 - Hormiga Laghton
// Referencias: https://es.wikipedia.org/wiki/Hormiga_de_Langton
// Nombre del archivo: rotation.cc

#include "../include/rotation.h"

Rotation::Rotation() {
  actual_ = 0;    // 0 = Empieza por el Norte por defecto
}

Rotation::Rotation(RotationE actual) {
  actual_ = 0;
  Set(actual);
}

Rotation::Rotation(const Rotation& rotation) {
  actual_ = 0;
  *this = rotation;
}

void Rotation::Set(RotationE new_rotation) {
  bool found = false;
  size_t index;

  // Buscamos la nueva rotacion en el conjunto de rotaciones
  for (index = 0; index < Rotations().Size(); ++index) {
    if (Rotations()[index] == new_rotation) {       // vector de rotaciones, accedemos al indice de la nueva rotacion 
      found = true;   // encontrado                                       // new_rotation (UP,DOWN...)
      break;          // salimos
    }
  }

  assert(found);
  actual_ = index; // actual = 0? (UP), 1? (DOWN)
}

char Rotation::GetRotation() const{
  return Rotations()[actual_];
}

Point2di Rotation::GetDirection() const{
  return MapRotations()[actual_];
}

Point2di Rotation::operator++() {
  ++actual_;
  if (actual_ >= Rotations().Size())
    actual_ = 0;

  return MapRotations()[actual_];
}

Point2di Rotation::Rotation::operator--() {
  if (actual_ == 0)
    actual_ = Rotations().Size() - 1;
  else
    --actual_;

  return MapRotations()[actual_];
}

void Rotation::operator=(const Rotation& rotation) {
  actual_ = rotation.actual_;
}

std::string Rotation::ToString() {
  std::string cardinal;
  switch (actual_)
  {
  case 0:
    cardinal ="Norte";
    break;

  case 1:
    cardinal ="Este";
    break;
  
  case 2:
    cardinal = "Sur";
    break;

  case 3:
    cardinal = "Oeste";
    break;
  }
  return cardinal;
}

Vector<RotationE> Rotation::Rotations() const {   // Rotacion
  static Vector<RotationE> rotations;
  static bool is_first = true;
  if (is_first) {
    is_first = false;   
    rotations.PushBack(UP);     // almacenar los elementos del vector 1º UP
    rotations.PushBack(RIGHT);
    rotations.PushBack(DOWN);
    rotations.PushBack(LEFT);
  }
  return rotations;
}

Vector<Point2di> Rotation::MapRotations() const { //  direcciones
  static Vector<Point2di> map_rotations;
  static bool is_first = true;
  if (is_first) {
    is_first = false;
    map_rotations.PushBack({0, -1});  // UP
    map_rotations.PushBack({1, 0});   // RIGHT
    map_rotations.PushBack({0, 1});   // DOWN
    map_rotations.PushBack({-1, 0});  // LEFT
  }
  return map_rotations;
}
