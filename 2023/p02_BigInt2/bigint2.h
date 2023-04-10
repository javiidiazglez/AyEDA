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
 * @file bigint2.h: clase bigint
 * @brief Contiene la declaracion de la clase bigint
 **/

#ifndef BIGINT2_H
#define BIGINT2_H

#include <algorithm>
#include <cmath>
#include <vector>

#include "bigint.h"

template <>
class BigInt<2> {
 public:
  BigInt(long number_x = 0);
  BigInt(const BigInt<2> &other);
  BigInt(std::vector<bool> digits);
  BigInt(const std::vector<char> &, const int &);
  BigInt(std::string number_x);
  BigInt operator=(const BigInt<2> &other);

  // Conversion
  template <size_t base>
  explicit operator BigInt<base>() const;

  // Getters and Setters
  std::vector<bool> GetDigits() const;
  BigInt<2> SetDigits(std::vector<bool> digits);

  bool operator[](size_t) const;
  size_t size() const;
  void push_back(bool digit);

  // Modifications or checks
  bool IsZero() const;
  BigInt<2> Abs() const;

  // factorial
  BigInt<2> factorial() const;
  BigInt<2> operator!() const;

  friend bool operator==(const BigInt<2> &, const BigInt<2> &);
  // Comparison operators
  bool operator!=(const BigInt<2> &other) const;
  friend bool operator>(const BigInt<2> &, const BigInt<2> &);
  bool operator>=(const BigInt<2> &other) const;
  friend bool operator<(const BigInt<2> &, const BigInt<2> &);
  bool operator<=(const BigInt<2> &other) const;

  // Increment/Decrement
  BigInt<2> &operator++();    // pre-increment
  BigInt<2> operator++(int);  // post-increment
  BigInt<2> &operator--();    // pre-decrement
  BigInt<2> operator--(int);  // post-decrement

  // arithmetic operators
  friend BigInt<2> operator+(const BigInt<2> &first, const BigInt<2> &other);
  BigInt<2> sum_overflow(const BigInt<2> &first, const BigInt<2> &other) const;
  BigInt<2> operator-() const;
  BigInt<2> operator-(const BigInt<2> &other) const;
  BigInt<2> operator*(const BigInt<2> &other) const;
  friend BigInt<2> operator/(const BigInt<2> &first, const BigInt<2> &other);
  BigInt<2> operator%(const BigInt<2> &other) const;

  friend BigInt<2> pow(const BigInt<2> &first, const BigInt<2> &other);
  BigInt<2> operator^(const BigInt<2> &other) const;

  // Displacement operators
  void operator<<(size_t n);
  void operator>>(size_t n);

  // Controlled operators
  BigInt<2> FillSign(size_t n) const;
  BigInt<2> ConvertToTwosComplement() const;

  // Input/Output
  friend std::ostream &operator<<(std::ostream &os, const BigInt<2> &number_x);

  std::string to_string() const;

 private:
  void operator<<(BigInt<2> &other);
  void operator>>(BigInt<2> &other);

  std::vector<bool> digits;
};
#include "bigint2.cc"

#endif  // BIGINT2_H