// Clase de una calculadora con notacion polaca inversa

#ifndef CALCULATOR_H
#define CALCULATOR_H

#include <algorithm>
#include <iostream>
#include <iterator>
#include <map>
#include <sstream>
#include <stack>
#include <string>
#include <vector>
#include <functional>

#include "bigint.h"

template <class C>
class Calculator {
 public:
  Calculator();
  void Operations();
  void SetClave(const std::vector<std::vector<std::string>>& claves);
  C Operate(std::vector<std::string> claves_lineas);
  void ProcessClaves();

  template <class U>
  friend std::ostream& operator<<(std::ostream& os, const Calculator<U>& calculate_var);

 private:
  std::vector<std::vector<std::string>> claves;
  std::stack<C> stack;
  std::string input;
  std::string output;
  std::map<std::string, C> variables;
  std::map<std::string, std::function<C(C, C)>> operadores;
  std::map<std::string, std::function<C(C)>> operadores_unarios;

};

#include "calculator.cc"

#endif  // CALCULATOR_H