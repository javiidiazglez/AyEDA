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
  actual_ = 0;  // norte
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
    if (Rotations()[index] == new_rotation) {             // vector de rotaciones, accedemos al indice de la nueva rotacion
      found = true;   // encontrado
      break;          // salimos
    }
  }

  assert(found);
  actual_ = index;
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
  switch (actual_)
  {
  case 0:
    return "Norte";
    break;

  case 1:
    return "Este";
    break;
  
  case 2:
    return "Sur";
    break;

  case 3:
    return "Oeste";
    break;
  }
  return "";
}

Vector<RotationE> Rotation::Rotations() const {
  static Vector<RotationE> rotations;
  static bool is_first = true;
  if (is_first) {
    is_first = false;
    rotations.PushBack(UP);
    rotations.PushBack(DOWN);
    rotations.PushBack(LEFT);
    rotations.PushBack(RIGHT);
  }
  return rotations;
}

Vector<Point2di> Rotation::MapRotations() const {
  static Vector<Point2di> map_rotations;
  static bool is_first = true;
  if (is_first) {
    is_first = false;
    map_rotations.PushBack({0, -1});  // UP
    map_rotations.PushBack({0, 1});   // DOWN
    map_rotations.PushBack({-1, 0});   // LEFT
    map_rotations.PushBack({1, 0});  // RIGHT
  }
  return map_rotations;
}
