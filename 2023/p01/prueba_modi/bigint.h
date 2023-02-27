#ifndef BIGINT_H
#define BIGINT_H

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

template <size_t Base>
class BigInt {
 public:
  // Constructores
  BigInt(long n = 0);
  BigInt(std::string &);                           // Un constructor que toma una cadena como argumento.
  BigInt(const char *);                            // Un constructor que toma un puntero a un carácter como argumento.
  BigInt(const std::vector<char> &, const int &);  // Un constructor que toma un vector de caracteres y un int como argumentos.
  BigInt(const BigInt<Base> &);                    // Un constructor de copias.

  // Operador de asignación.
  BigInt<Base> &operator=(const BigInt<Base> &);

  // Input/Output
  template <size_t Base_t>
  friend std::ostream &operator<<(std::ostream &, const BigInt<Base_t> &);

  template <size_t Base_t>
  friend std::istream &operator>>(std::istream &, BigInt<Base_t> &);

  // Getters y Setters
  BigInt<Base> SetSign(int);
  BigInt<Base> SetDigits(std::vector<char>);
  std::vector<char> GetDigits() const;
  int GetSign() const;

  // Accesos
  int sign() const;
  char operator[](size_t) const; // Acceso al i-ésimo dígito
  size_t size() const;

  // Modifications or checks
  BigInt<Base> rellenar_ceros(unsigned) const;
  bool IsZero() const;
  BigInt<Base> Abs() const;  // Una función que devuelve el valor absoluto de BigInt.
  std::string to_string() const;
  BigInt<Base> PushBack(char);
  
  // Comparaciones
  template <size_t Base_t>
  friend bool operator==(const BigInt<Base> &, const BigInt<Base> &); // ==
  bool operator!=(const BigInt<Base> &) const;                        // !=

  template <size_t Base_t>
  friend bool operator>(const BigInt<Base> &, const BigInt<Base> &);
  bool operator>=(const BigInt<Base> &) const;                        // >=

  template <size_t Base_t>
  friend bool operator<(const BigInt<Base> &, const BigInt<Base> &);  // <
  bool operator<=(const BigInt<Base> &) const;                        // <=



  // Operadores aritméticos
  template <size_t Base_t>
  friend BigInt<Base_t> operator+(const BigInt<Base_t> &, const BigInt<Base_t> &);

  BigInt<Base> operator-(const BigInt<Base> &) const; // Operador -
  BigInt<Base> operator-() const;                     // Operador -
  BigInt<Base> operator*(const BigInt<Base> &) const; // Operador *

  template <size_t Base_t>
  friend BigInt<Base> operator/(const BigInt<Base> &, const BigInt<Base> &); // Operador /
  BigInt<Base> operator%(const BigInt<Base> &) const;                        // Operador *

  template <size_t Base_t>
  friend BigInt<Base> pow(const BigInt<Base> &, const BigInt<Base> &);       // Operador  pow
  BigInt<Base> operator^(const BigInt<Base> &) const;                         // ^

  BigInt<Base> operator!() const;


  // Incremento/decremento
  BigInt<Base> &operator++();    // pre-increment
  BigInt<Base> operator++(int);  // post-increment
  BigInt<Base> &operator--();    // pre-decrement
  BigInt<Base> operator--(int);  // post-decrement

 private:
  std::vector<char> digits_;
  int sign_;  // 1: positivo, -1: negativo
};

#include "bigint.cc"

#endif  // BIGINT_H