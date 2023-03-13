/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingenierıa Informatica
 * Asignatura: Algoritmos y Estructuras de Datos Avanzadas
 * Curso: 2º
 * Práctica 2: Calculadora de números grandes en binario
 *
 * @author José Javier Díaz González
 * Correo: alu0101128894@ull.edu.es
 *
 * @date 27/02/2023
 * @file calculator.h: clase calculator
 * @brief Contiene la declaracion de la clase calculator
 **/

#ifndef CALCULATOR_H
#define CALCULATOR_H

#include <algorithm>
#include <functional>
#include <iostream>
#include <iterator>
#include <map>
#include <sstream>
#include <stack>
#include <string>
#include <typeinfo>
#include <vector>

#include "bigint.h"

template <class T, class P>
class Calculator {
 public:
  Calculator();
  void InitOperations();
  void SetTokens(const std::vector<std::vector<std::string>>& tokens);
  T Operate(std::vector<std::string> tokens_line);
  void Process();
  bool CheckStackEmpty();
  bool CheckIsOperands(const std::string&, const std::string&);

  template <class U, class F>
  friend std::ostream& operator<<(std::ostream& os, const Calculator<U, F>& c);

 private:
  std::vector<std::vector<std::string>> tokens;
  std::stack<T> stack;
  std::map<std::string, T> variables;
  std::map<std::string, std::function<T(T, T)>> operations;
  std::map<std::string, std::function<T(T)>> unary_operations;
};

#include "calculator.cc"

#endif  // CALCULATOR_H