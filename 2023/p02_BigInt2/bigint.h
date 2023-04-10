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
 * @file bigint.h: clase bigint
 * @brief Contiene la declaracion de la clase bigint
 **/

#ifndef BIGINT_H
#define BIGINT_H

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include <unistd.h>

template <size_t Base>
class BigInt {
 public:
  // Constructor
  BigInt(long n = 0);
  BigInt(std::string &);
  BigInt(const char *);
  BigInt(const BigInt<Base> &);
  BigInt(const std::vector<char> &,const int & );
  // Conversion
  explicit operator BigInt<2>();
  

  // Asingment
  BigInt<Base> &operator=(const BigInt<Base> &);

  // Input/Output
  template <size_t Base_t>
  friend std::ostream &operator<<(std::ostream &, const BigInt<Base_t> &);
  template <size_t Base_t>
  friend std::istream& operator>>(std::istream&, BigInt<Base_t>&);

  // Getters and Setters
  BigInt<Base> SetSign(int);
  BigInt<Base> SetDigits(std::vector<char>);
  std::vector<char> GetDigits() const;
  int GetSign() const;

  std::string to_string() const;

  // Access
  int sign() const;
  char operator[](size_t) const;
  size_t size() const;

  //Modifications or checks
  BigInt<Base> fill_zeros(unsigned) const ;
  bool IsZero() const;
  BigInt<Base> Abs() const;
  BigInt<Base> PushBack(char);


  // Comparison
  template <size_t Base_t>
  friend bool operator==(const BigInt<Base> &, const BigInt<Base> &);

  bool operator!=(const BigInt<Base> &) const;
  template <size_t Base_t>
  friend bool operator>(const BigInt<Base> &, const BigInt<Base> &);
  bool operator>=(const BigInt<Base> &) const;
  template <size_t Base_t>
  friend bool operator<(const BigInt<Base> &, const BigInt<Base> &);
  bool operator<=(const BigInt<Base> &) const;

  // Increment/Decrement
  BigInt<Base> &operator++();    // pre-increment
  BigInt<Base> operator++(int);  // post-increment
  BigInt<Base> &operator--();    // pre-decrement
  BigInt<Base> operator--(int);  // post-decrement

  // Arithmetic
  template <size_t Base_t>
  friend BigInt<Base_t> operator+(const BigInt<Base_t> &, const BigInt<Base_t> &);

  BigInt<Base> operator-(const BigInt<Base> &) const;
  BigInt<Base> operator-() const;
  BigInt<Base> operator*(const BigInt<Base> &) const;

  template <size_t Base_t>
  friend BigInt<Base> operator/(const BigInt<Base> &, const BigInt<Base> &);
  BigInt<Base> operator%(const BigInt<Base> &) const;
  // Power
  template <size_t Base_t>
  friend BigInt<Base> pow(const BigInt<Base> &, const BigInt<Base> &);
  BigInt<Base> operator^(const BigInt<Base> &) const;

  BigInt<Base> operator!() const;

 private:
  std::vector<char> digits_;
  int sign_;  // 1: positive, -1: negative
};

#include "bigint2.h"
#include "bigint.cc"

#endif  // BIGINT_H