/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingenierıa Informatica
 * Asignatura: Algoritmos y Estructuras de Datos Avanzadas
 * Curso: 2º
 * Práctica 1: Representación de números grandes en notación posiciona
 *
 * @author José Javier Díaz González
 * Correo: alu0101128894@ull.edu.es
 *
 * @date 14/02/2023
 * @file calculator.cc: clase calculator
 * @brief Contiene definición de la clase calculator
**/

#include "calculator.h"

// El constructor de la clase.
template <class C>
Calculator<C>::Calculator() {
  Operations();
}

// Una referencia a un vector de vectores de cadenas.
template <class C>
void Calculator<C>::SetClave(
    const std::vector<std::vector<std::string>>& claves) {
  this->claves = claves;
}

template <class C>
void Calculator<C>::Operations() {
  // Operaciones
  operadores["+"] = [](C a, C b) { return a + b; };
  operadores["-"] = [](C a, C b) { return a - b; };
  operadores["*"] = [](C a, C b) { return a * b; };
  operadores["/"] = [](C a, C b) { return a / b; };
  operadores["%"] = [](C a, C b) { return a % b; };
  operadores["^"] = [](C a, C b) { return a ^ b; };
  operadores["=="] = [](C a, C b) { return a == b; };
  operadores["!="] = [](C a, C b) { return a != b; };
  operadores["<"] = [](C a, C b) { return a < b; };
  operadores["<="] = [](C a, C b) { return a <= b; };
  operadores[">"] = [](C a, C b) { return a > b; };
  operadores[">="] = [](C a, C b) { return a >= b; };
  operadores["="] = [](C a, C b) { return a = b; };
  operadores["+="] = [](C a, C b) { return a += b; };

  // Operadores Unarios
  operadores_unarios["++"] = [](C a) { return ++a; };
  operadores_unarios["--"] = [](C a) { return --a; };
  operadores_unarios["-"] = [](C a) { return -a; };
}

// Operar Una función que toma un vector de cadenas y devuelve una C.
template <class C>
C Calculator<C>::Operate(std::vector<std::string> claves_lineas) {
  for (auto& clave : claves_lineas) {
    if (operadores.count(clave) == 1) {                 // Comprobando si el operador está en el mapa.
      C a = stack.top();                                // Obtener el elemento superior de la stack y asignarlo a una variable.
      stack.pop();                                      // Quitar el elemento superior de la stack.
      C b = stack.top();                                // Obtener el elemento superior de la stack y asignarlo a una variable.
      stack.pop();                                      // Quitar el elemento superior de la stack.
      stack.push(operadores[clave](b, a));              // Empujando el resultado de la operación en la stack.
    } else if (operadores_unarios.count(clave) == 1) {  // Comprobando si el operador es un operador unario.
      C a = stack.top();
      stack.pop();
      stack.push(operadores_unarios[clave](a));  // Empujando el resultado de la operación en la stack.
    } else if (variables.count(clave) == 1) {    // Comprobando si la variable está en el mapa.
      stack.push(variables[clave]);              // Empujando el valor de la variable en la stack.
    } else {
      while (!stack.empty()) {
        stack.pop();
      }
      C a;
      return a;
    }
  }
  return stack.top();
}

template <class C>
void Calculator<C>::ProcessClaves() {
  // Iterando a través del vector de vectores de cadenas.
  for (auto& linea : claves) {
    // Comprobando si la línea tiene 3 elementos y si el segundo elemento es igual a "=".
    if (linea.size() == 3 && linea[1] == "=") {
      // Comprobando si la variable está en el mapa.
      if (variables.count(linea[2]) == 1) {
        variables[linea[0]] = variables[linea[2]];  // Asignando el valor de la variable en linea[2] a la variable en linea[0].
      } else {
        // for (auto& calculate_var : linea[2]) { // Comprobando que es un digito
        //   if (!isdigit(calculate_var)) {
        //     std::cout << "Error in linea: ";
        //     for (auto& clave : linea) {
        //       std::cout << clave << " ";
        //     }
        //     continue;
        //   }
        // }
        variables[linea[0]] = C(linea[2]);  // Convertir la cadena en un número.
      }

    } else if (linea.size() > 3) {
      std::vector<std::string> claves_lineas(linea.begin() + 2, linea.end());
      variables[linea[0]] = Operate(claves_lineas);
    } else {
      std::cout << "Error en la linea: ";
      for (auto& clave : linea) {
        std::cout << clave << " ";
      }
    }
  }
}

template <class U>
std::ostream& operator<<(std::ostream& os, const Calculator<U>& calculate_var) {
  for (auto& var : calculate_var.variables) {
    os << var.first << " = " << var.second << std::endl;
  }
  return os;
}