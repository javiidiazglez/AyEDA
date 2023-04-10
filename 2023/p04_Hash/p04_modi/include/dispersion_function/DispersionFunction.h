/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingenierıa Informatica
 * Asignatura: Algoritmos y Estructuras de Datos Avanzadas
 * Curso: 2º
 * Práctica 4: Búsqueda por dispersión
 *
 * @author José Javier Díaz González
 * Correo: alu0101128894@ull.edu.es
 *
 * @date 27/03/2023
 * @file DispersionFunction.h: clase DispersionFunction
 * @brief Contiene la declaracion de la clase DispersionFunction
 **/

#ifndef DISPERSION_FUNCTION_H
#define DISPERSION_FUNCTION_H

#include <iostream>

template <class Key>
class DispersionFunction {
 public:
  DispersionFunction(){};
  virtual ~DispersionFunction(){};
  virtual unsigned operator()(const Key& k) const = 0;
};

#endif