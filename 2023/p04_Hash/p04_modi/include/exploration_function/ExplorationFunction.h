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
 * @file ExplorationFunction.h: clase ExplorationFunction
 * @brief Contiene la declaracion de la clase ExplorationFunction
 **/

#ifndef EXPLORATION_FUNCTION_H
#define EXPLORATION_FUNCTION_H

template <class Key>
class ExplorationFunction {
 public:
  virtual ~ExplorationFunction() {}
  ExplorationFunction() {}
  virtual unsigned operator()(const Key& k, unsigned i) const = 0;
};

#endif