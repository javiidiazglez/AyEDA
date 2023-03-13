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
 * @file calculator.cc: clase calculator
 * @brief Contiene definición de la clase calculator
 **/

#include "calculator.h"

/**
 * @brief Construct a new Calculator< T>:: Calculator object
 *
 * @tparam T
 */
template <class T, class P>
Calculator<T, P>::Calculator() {
  InitOperations();
}

/**
 * @brief Set the Tokens object
 *
 * @tparam T
 * @param tokens
 */
template <class T, class P>
void Calculator<T, P>::SetTokens(
    const std::vector<std::vector<std::string>>& tokens) {
  this->tokens = tokens;
}

/**
 * @brief Initialize the operations
 *
 * @tparam T
 */
template <class T, class P>
void Calculator<T, P>::InitOperations() {
  // Operations
  operations["+"] = [](T a, T b) { return a + b; };
  operations["-"] = [](T a, T b) { return a - b; };
  operations["*"] = [](T a, T b) { return a * b; };
  operations["/"] = [](T a, T b) { return a / b; };
  operations["%"] = [](T a, T b) { return a % b; };
  operations["^"] = [](T a, T b) { return a ^ b; };
  operations["=="] = [](T a, T b) { return a == b; };
  operations["!="] = [](T a, T b) { return a != b; };
  operations["<"] = [](T a, T b) { return a < b; };
  operations["<="] = [](T a, T b) { return a <= b; };
  operations[">"] = [](T a, T b) { return a > b; };
  operations[">="] = [](T a, T b) { return a >= b; };
  operations["="] = [](T a, T b) { return a = b; };

  // Unary operations
  unary_operations["++"] = [](T a) { return ++a; };
  unary_operations["--"] = [](T a) { return --a; };
  unary_operations["-"] = [](T a) { return -a; };
  unary_operations["!"] = [](T a) { return !a; };
}

/**
 * @brief Operate with the tokens of a line
 * and return the result of the operation
 *
 * @tparam T
 * @param tokens_line
 * @return T
 */
template <class T, class P>
T Calculator<T, P>::Operate(std::vector<std::string> tokens_line) {
  for (auto& token : tokens_line) {
    if (operations.count(token) == 1) {
      if (stack.size() < 2) {
        goto error;
      }
      T a = stack.top();
      stack.pop();
      T b = stack.top();
      stack.pop();
      stack.push(operations[token](b, a));
    } else if (unary_operations.count(token) == 1) {
      if (stack.size() < 1) {
        goto error;
      }
      T a = stack.top();
      stack.pop();
      stack.push(unary_operations[token](a));
    } else if (variables.count(token) == 1) {
      stack.push(variables[token]);
    } else {
    error:
      // Error clear stack and return 0
      while (!stack.empty()) {
        stack.pop();
      }
      std::cerr << "Error in line: " << std::endl;
      T a;
      return a;
    }
  }

  return stack.top();
}

template <class T, class P>
void Calculator<T, P>::Process() {
  //  N2 = 426
  // E1 = N1 N2 +
  for (auto& line : tokens) {
    if (line.size() == 3 && line[1] == "=") {
      // Check if is a number or a variable
      if (variables.count(line[2]) == 1) {
        variables[line[0]] = variables[line[2]];
      } else {
        try {
          if (typeid(P) == typeid(BigInt<2>)) {
            BigInt<2> aux(line[2]);
            variables[line[0]] = aux;
          } else {
            P aux(line[2]);
            variables[line[0]] = aux.operator T();
          }
        } catch (std::invalid_argument& e) {
          std::cout << "Error in line: -";
          for (auto& token : line) {
            std::cout << token << " ";
          }
          continue;
        }
      }

    } else if (line.size() > 3) {
      // E1 = N1 N2 +  so E1 = operate(N1, N2, +)
      // we neet create a vector with N1, N2, + and pass it to operate
      if (line[1] != "=") {
        std::cout << "Error in line: ";
        for (auto& token : line) {
          std::cout << token << " ";
        }
        continue;
      }
      std::vector<std::string> tokens_line(line.begin() + 2, line.end());
      variables[line[0]] = Operate(tokens_line);
    } else {
      // Print error in line and continue
      std::cout << "Error in line: ";
      for (auto& token : line) {
        std::cout << token << " ";
      }
    }
  }
}

/**
 * @brief Overload the << operator to print the variables
 *
 * @tparam U
 * @param os
 * @param c
 * @return std::ostream&
 */
template <class H, class F>
std::ostream& operator<<(std::ostream& os, const Calculator<H, F>& c) {
  for (auto& var : c.variables) {
    if (typeid(F) == typeid(BigInt<2>)) {
      BigInt<2> aux = var.second;
      os << var.first << " = " << aux << std::endl;
    } else {
      F aux = var.second.operator F();
      os << var.first << " = " << aux << std::endl;
    }
  }

  return os;
}