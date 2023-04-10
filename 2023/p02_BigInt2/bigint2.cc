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
 * @file bigint2.cc: clase bigint
 * @brief Contiene la declaracion de la clase bigint
 **/

#include "bigint2.h"

#include <unistd.h>

/**
 * @brief Construct a new Big Int< 2>:: Big Int object from a long
 *
 * @param number_x
 */
BigInt<2>::BigInt(long number_x) {
  // Convert normal number to binary
  // Sign
  bool sign = false;
  if (number_x < 0) {
    sign = true;
    number_x = -number_x;
  }
  // If number is 0, then the number is 00
  if (number_x == 0) {
    digits.push_back(0);
    digits.push_back(0);
  }

  while (number_x > 0) {
    digits.push_back(number_x % 2);
    number_x /= 2;
  }
  digits.push_back(0);

  // If the number is negative, then the number is 01
  if (sign) {
    *this = -*this;
  }
}

/**
 * @brief Construct a new Big Int< 2>:: Big Int object from a vector of bool
 *
 * @param digits
 */
BigInt<2>::BigInt(std::vector<bool> digits) { this->digits = digits; }

/**
 * @brief Construct a new Big Int< 2>:: Big Int object from another BigInt<2>
 *
 * @param number_x
 */
BigInt<2>::BigInt(const BigInt<2> &number_x) { digits = number_x.digits; }

/**
 * @brief Construct a new Big Int< 2>:: Big Int object from a string
 *
 * @param number_x
 */
BigInt<2>::BigInt(std::string number_x) {
  // if size is 0, then the number is 00
  if (number_x.size() == 0) {
    digits.push_back(0);
    digits.push_back(0);
  }
  // if size is 1, error because the number must be 00 or 01
  if (number_x.size() == 1) {
    std::cout << "Error: the number must be 00 or 01 the number not have more 2" << std::endl;
    std::cerr << "Erro->" << number_x << std::endl;
    throw std::invalid_argument("Error: the number must be 00 or 01");
  }
  for (int i = number_x.size() - 1; i >= 0; i--) {
    digits.push_back(number_x[i] - '0');
  }
}

/// Revisar/-----
BigInt<2>::BigInt(const std::vector<char> &digits_aux, const int &sign) {
  std::cerr << "Cuidado con el constructor en base 2 \n";
}

/**
 * @brief Operator [] to access to the digits of the number
 *
 * @param n
 * @return true
 * @return false
 */
bool BigInt<2>::operator[](size_t n) const { return digits[n]; }

/**
 * @brief Get the Size object
 *
 * @return size_t
 */
size_t BigInt<2>::size() const { return digits.size(); }

/**
 * @brief Operator = to assign a BigInt<2> to another BigInt<2>
 *
 * @param other
 * @return BigInt<2>
 */
BigInt<2> BigInt<2>::operator=(const BigInt<2> &other) {
  digits = other.digits;
  return *this;
}

/**
 * @brief Convert number internal to string representation
 *
 * @return std::string
 */
std::string BigInt<2>::to_string() const {
  std::string number_x;
  for (int i = digits.size() - 1; i >= 0; i--) {
    number_x += digits[i] + '0';
  }
  return number_x;
}
/**
 * @brief Get the Sign object
 *
 *
 * @return size_t
 */
std::vector<bool> BigInt<2>::GetDigits() const { return digits; }

/**
 * @brief Set the Sign object
 *
 * @param n
 * @return BigInt<2>
 */
BigInt<2> BigInt<2>::SetDigits(std::vector<bool> digits) {
  this->digits = digits;
  return *this;
}

/**
 * @brief Compare two BigInt<2> numbers and return true if they are equal
 *
 * @param other
 * @return true
 * @return false
 */
bool operator==(const BigInt<2> &first, const BigInt<2> &other) {
  // If signs are different return false

  BigInt<2> number_x;
  BigInt<2> number_y;
  // We need to control 0001 = 01 if size is different fill with sign
  if (first.size() < other.digits.size()) {
    number_x = first.FillSign(other.digits.size() - first.size());
    number_y = other;
  } else if (first.size() > other.digits.size()) {
    number_x = first;
    number_y = other.FillSign(first.size() - other.digits.size());
  } else {
    number_x = first;
    number_y = other;
  }
  for (size_t i = 0; i < number_x.digits.size(); i++) {
    if (number_x.digits[i] != number_y.digits[i]) {
      return false;
    }
  }
  return true;
}

/**
 * @brief Compare two BigInt<2> numbers and return true if they are not equal
 *
 * @param other
 * @return true
 * @return false
 */
bool BigInt<2>::operator!=(const BigInt<2> &other) const {
  return !(*this == other);
}

/**
 * @brief Compare two BigInt<2> numbers and return true if this is greater than
 * other
 *
 * @param other
 * @return true
 * @return false
 */
bool operator>(const BigInt<2> &first, const BigInt<2> &other) {
  // We need to control 0001 = 01 if size is different fill with zeros
  // Different sign case
  if (first[first.size() - 1] < other.digits[other.digits.size() - 1]) {
    return true;
  } else if (first[first.size() - 1] > other.digits[other.digits.size() - 1]) {
    return false;
  }
  // Same sign case
  bool sign = first[first.size() - 1];
  BigInt<2> number_x;
  BigInt<2> number_y;
  if (sign) {
    number_x = first.Abs();
    number_y = other.Abs();
  } else {
    number_x = first;
    number_y = other;
  }
  if (number_x.digits.size() > number_y.digits.size()) {
    number_y =
        number_y.FillSign(number_x.digits.size() - number_y.digits.size());
  } else if (number_x.digits.size() < number_y.digits.size()) {
    number_x =
        number_x.FillSign(number_y.digits.size() - number_x.digits.size());
  }
  for (long long i = number_x.digits.size() - 1; i >= 0; i--) {
    if (number_x.digits[i] > number_y.digits[i]) {
      return sign ? false : true;
    } else if (number_x.digits[i] < number_y.digits[i]) {
      return sign ? true : false;
    }
  }
  return false;
}

/**
 * @brief Compare two BigInt<2> numbers and return true if this is less than
 * other
 *
 * @param other
 * @return true
 * @return false
 */
bool operator<(const BigInt<2> &first, const BigInt<2> &other) {
  return !(first > other || first == other);
}

/**
 * @brief Compare two BigInt<2> numbers and return true if this is greater or
 * equal than other
 *
 * @param other
 * @return true
 * @return false
 */
bool BigInt<2>::operator>=(const BigInt<2> &other) const {
  return !(*this < other);
}

/**
 * @brief Compare two BigInt<2> numbers and return true if this is less or equal
 * than other
 *
 * @param other
 * @return true
 * @return false
 */
bool BigInt<2>::operator<=(const BigInt<2> &other) const {
  return !(*this > other);
}

void BigInt<2>::operator<<(size_t n) {
  std::vector<bool> aux;
  aux.insert(aux.begin(), digits.begin(), digits.end() - n);
  aux.insert(aux.end(), n, digits[digits.size() - 1]);
  digits = aux;
}

void BigInt<2>::operator>>(size_t n) {
  if (n > digits.size()) {
    digits.clear();
    digits.push_back(0);
    return;
  }
  std::vector<bool> aux;
  aux.insert(aux.begin(), n, digits[digits.size() - 1]);
  aux.insert(aux.end(), digits.begin() + n, digits.end());
  digits = aux;
}

/**
 * @brief Overload the operator + to add two BigInt<2>
 *
 * @param other
 * @return BigInt<2>
 */
BigInt<2> operator+(const BigInt<2> &first, const BigInt<2> &other) {
  std::vector<bool> number_x = first.digits;
  std::vector<bool> number_y = other.digits;
  bool carry = false;
  bool sum;
  // for posible overflow
  //  we need to add zeros to the smaller number
  if (number_x.size() > number_y.size()) {
    number_y = other.FillSign(number_x.size() - number_y.size()).digits;
  } else if (number_x.size() < number_y.size()) {
    number_x = first.FillSign(number_y.size() - number_x.size()).digits;
  }

  std::vector<bool> aux;
  for (size_t i = 0; i < number_x.size(); i++) {
    sum = number_x[i] ^ number_y[i] ^ carry;
    carry = (number_x[i] & number_y[i]) | (number_x[i] & carry) |
            (number_y[i] & carry);
    aux.push_back(sum);
  }
  // Overflow case
  // sign different not overflow
  // sign same may overflow
  if (!(first[first.size() - 1] != other[other.size() - 1])) {
    // if aux[aux.size() - 1] != first[first.size() - 1] overflow
    if (aux[aux.size() - 1] != first[first.size() - 1]) {
      aux.push_back(first[first.size() - 1]);
    }
  }

  BigInt<2> result(aux);
  return result;
}

BigInt<2> BigInt<2>::sum_overflow(const BigInt<2> &first,
                                  const BigInt<2> &other) const {
  std::vector<bool> number_x = first.digits;
  std::vector<bool> number_y = other.digits;
  bool carry = false;
  bool sum;
  //  we need to add zeros to the smaller number
  if (number_x.size() > number_y.size()) {
    number_y = other.FillSign(number_x.size() - number_y.size()).digits;
  } else if (number_x.size() < number_y.size()) {
    number_x = first.FillSign(number_y.size() - number_x.size()).digits;
  }

  std::vector<bool> aux;
  for (size_t i = 0; i < number_x.size(); i++) {
    sum = number_x[i] ^ number_y[i] ^ carry;
    carry = (number_x[i] & number_y[i]) | (number_x[i] & carry) |
            (number_y[i] & carry);
    aux.push_back(sum);
  }
  BigInt<2> result(aux);
  return result;
}

/**
 * @brief Overload the operator - to substract two BigInt<2>
 *
 * @param other
 * @return BigInt<2>
 */
BigInt<2> BigInt<2>::operator-(const BigInt<2> &other) const {
  BigInt<2> number_y = other.ConvertToTwosComplement();
  BigInt<2> result = *this + number_y;
  return result;
}

/**
 * @brief Overload the operator << to shift left a BigInt<2>
 *
 * @param other
 */
void BigInt<2>::operator>>(BigInt<2> &other) {
  // Example 0001 >> 1001 = 0100 1100
  std::vector<bool> aux;
  aux.insert(aux.end(), digits.begin(), digits.end() - 1);
  aux.insert(aux.begin(), digits[0]);
  std::vector<bool> aux2;
  aux2.insert(aux2.end(), other.digits.begin(), other.digits.end() - 1);
  aux2.insert(aux2.begin(), digits[digits.size() - 1]);
  this->SetDigits(aux);
  other.SetDigits(aux2);
}

/**
 * @brief Overload the operator >> to shift right a BigInt<2>
 *
 * @param other
 */
void BigInt<2>::operator<<(BigInt<2> &other) {
  // Example 0110 << 0100 = 1100 1000
  std::vector<bool> aux;
  aux.insert(aux.end(), digits.begin() + 1, digits.end());
  aux.push_back(other.digits[0]);
  std::vector<bool> aux2;
  aux2.insert(aux2.end(), other.digits.begin() + 1, other.digits.end());
  aux2.push_back(other.digits[other.digits.size() - 1]);
  this->SetDigits(aux);
  other.SetDigits(aux2);
}

/**
 * @brief Insert a by begining a BigInt<2>
 * example 0001.push_back(1) = 10001
 *
 * @param digit
 */
void BigInt<2>::push_back(bool digit) { digits.push_back(digit); }

/**
 * @brief Overload the operator * to multiply two BigInt<2>
 *
 * @param other
 * @return BigInt<2>
 */
BigInt<2> BigInt<2>::operator*(const BigInt<2> &other) const {
  // sumar other veces this
  //  Algorithm Robertson
  //  A and M n + 1 bits
  //  Q n bits
  //  we need to add zeros to the smaller number

  BigInt<2> number_M = *this;
  BigInt<2> number_Q = other;

  if (number_M.digits.size() > number_Q.digits.size()) {
    number_Q = other.FillSign(number_M.digits.size() - number_Q.digits.size());
  } else if (number_M.digits.size() < number_Q.digits.size()) {
    number_M = this->FillSign(number_Q.digits.size() - number_M.digits.size());
  }
  number_M.push_back(number_M.digits[number_M.digits.size() - 1]);
  size_t n = number_M.digits.size();
  std::vector<bool> aux(n, false);
  BigInt<2> number_A(aux);
  for (size_t i = 0; i < number_Q.digits.size() - 1; i++) {
    if (number_Q.digits[0]) {
      number_A = sum_overflow(number_A, number_M);
    }
    number_Q << number_A;
  }
  if (number_Q.digits[0]) {
    number_A = number_A - number_M;
  }
  number_Q << number_A;
  std::vector<bool> result;
  result.insert(result.begin(), number_Q.digits.begin(), number_Q.digits.end());
  result.insert(result.end(), number_A.digits.begin(),
                number_A.digits.end() - 1);
  // Clear the sign bit

  while (result.size() > 2 && (result.back() == *(result.end() - 2))) {
    result.erase(result.end() - 1);
  }
  // while result.begin == sign and result.begin+1 == sign erase result.begin

  return BigInt<2>(result);
}

/**
 * @brief Overload the operator / to divide two BigInt<2>
 *
 * @param other
 * @return BigInt<2>
 */
BigInt<2> operator/(const BigInt<2> &first, const BigInt<2> &other) {
  // same size
  BigInt<2> number_f = first;
  BigInt<2> number_s = other;
  if (number_f.digits.size() > number_s.digits.size()) {
    number_s = other.FillSign(number_f.digits.size() - number_s.digits.size());
  } else if (number_f.digits.size() < number_s.digits.size()) {
    number_f = first.FillSign(number_s.digits.size() - number_f.digits.size());
  }
  //
  BigInt<2> number_M = number_s.Abs();
  std::vector<bool> aux_Q = number_f.Abs().digits;
  aux_Q.erase(aux_Q.end() - 1);
  BigInt<2> number_Q(aux_Q);
  std::vector<bool> aux_A(number_M.digits.size(), false);
  BigInt<2> number_A(aux_A);

  for (size_t i = 0; i < number_Q.digits.size(); i++) {
    number_Q >> number_A;
    number_A = number_A.sum_overflow(number_A, -number_M);
    if (number_A.digits[number_A.size() - 1]) {
      number_Q.digits[0] = false;
      number_A = number_A + number_M;
    } else {
      number_Q.digits[0] = true;
    }
  }
  // Only Cocient
  std::vector<bool> result;
  result.insert(result.begin(), number_Q.digits.begin(), number_Q.digits.end());
  // Clear the sign bit
  while (result.size() > 2 && (result.back() == *(result.end() - 2)) && result.back() == 0) {
    result.erase(result.end() - 1);
  }
  // Change the sign if first and second are different
  BigInt<2> number_Q_r(result);
  if (first.digits[first.digits.size() - 1] !=
      other.digits[other.digits.size() - 1]) {
    number_Q_r = number_Q_r.ConvertToTwosComplement();
  }
  return number_Q_r;
}

/**
 * @brief Overload the operator % to get the remainder of two BigInt<2>
 *
 * @param other
 * @return BigInt<2>
 */
BigInt<2> &BigInt<2>::operator++() {
  *this = *this + BigInt<2>("01");
  return *this;
}

/**
 * @brief Overload the operator ++ to increment a BigInt<2>
 *
 * @return BigInt<2>
 */
BigInt<2> BigInt<2>::operator++(int) {
  BigInt<2> aux = *this;
  (*this) = (*this) + BigInt<2>("01");
  return aux;
}

/**
 * @brief Overload the operator -- to decrement a BigInt<2>
 *
 * @return BigInt<2>&
 */
BigInt<2> &BigInt<2>::operator--() {
  *this = *this - BigInt<2>("01");
  return *this;
}

/**
 * @brief Overload the operator -- to decrement a BigInt<2>
 *
 * @return BigInt<2>
 */
BigInt<2> BigInt<2>::operator--(int) {
  BigInt<2> aux = *this;
  (*this) = (*this) - BigInt<2>("01");
  return aux;
}

/**
 * @brief Fill the number with zeros to the left
 *
 * @param n
 * @return BigInt<2>
 */
BigInt<2> BigInt<2>::FillSign(size_t n) const {
  std::string aux = this->to_string();
  char sign = aux[0];
  aux.insert(0, n, sign);
  BigInt<2> result(aux);
  return result;
}

/**
 * @brief Return the absolute value of a BigInt<2>
 *
 * @return BigInt<2>
 */
BigInt<2> BigInt<2>::Abs() const {
  if (digits[digits.size() - 1]) {
    return this->ConvertToTwosComplement();
  }
  return *this;
}

/**
 * @brief Convert a binary number to its two's complement
 *
 * @return BigInt<2>
 */
BigInt<2> BigInt<2>::ConvertToTwosComplement() const {
  std::vector<bool> aux;
  bool flag = false;
  // Case exceptional 1000 we need to add 0 to the left to make it 01000
  // for the algorithm to work
  bool number_exceptional = true;
  if (digits[digits.size() - 1]) {
    for (size_t i = 0; i < digits.size() - 1; i++) {
      if (digits[i] == 1) {
        number_exceptional = false;
        break;
      }
    }
  } else {
    number_exceptional = false;
  }
  BigInt<2> number = *this;
  if (number_exceptional) {
    number.push_back(1);
  }
  for (size_t i = 0; i < number.size(); i++) {
    if (number[i] == 1 && !flag) {
      flag = true;
      aux.push_back(number[i]);
    } else if (flag) {
      aux.push_back(!number[i]);
    } else {
      aux.push_back(number[i]);
    }
  }
  BigInt<2> result(aux);
  return result;
}

/**
 * @brief Calculate the module of two BigInt<2>
 *
 * @param other
 * @return BigInt<2>
 */
BigInt<2> BigInt<2>::operator%(const BigInt<2> &other) const {
  BigInt<2> number_f = *this;
  BigInt<2> number_s = other;
  if (number_f.digits.size() > number_s.digits.size()) {
    number_s = other.FillSign(number_f.digits.size() - number_s.digits.size());
  } else if (number_f.digits.size() < number_s.digits.size()) {
    number_f = this->FillSign(number_s.digits.size() - number_f.digits.size());
  }
  //
  BigInt<2> number_M = number_s.Abs();
  std::vector<bool> aux_Q = number_f.Abs().digits;
  aux_Q.erase(aux_Q.end() - 1);
  BigInt<2> number_Q(aux_Q);
  std::vector<bool> aux_A(number_M.digits.size(), false);
  BigInt<2> number_A(aux_A);

  for (size_t i = 0; i < number_Q.digits.size(); i++) {
    number_Q >> number_A;
    number_A = number_A - number_M;
    if (number_A.digits[number_A.size() - 1]) {
      number_Q.digits[0] = false;
      number_A = number_A + number_M;
    } else {
      number_Q.digits[0] = true;
    }
  }
  // Only Rest A0...An-1
  std::vector<bool> result;
  result.insert(result.begin(), number_A.digits.begin(),
                number_A.digits.end() - 1);
  BigInt<2> number_Q_r(result);
  return number_Q_r;
}

/**
 * @brief Pow
 * @param first
 * @param other
 * @return BigInt<2>
 */
BigInt<2> pow(const BigInt<2> &first, const BigInt<2> &other) {
  static BigInt<2> zero("00");
  static BigInt<2> one("01");
  static BigInt<2> two("010");
  if (other < zero) {
    return zero;
  }
  if (other == zero) {
    return one;
  } else if (other % two == zero) {
    BigInt<2> half = pow(first, other / two);
    return half * half;
  } else {
    BigInt<2> half = pow(first, (other - one) / two);
    return half * half * first;
  }
}

/**
 * @brief Operator ^ for BigInt<2> do pow operation
 *
 * @param other
 * @return BigInt<2>
 */
BigInt<2> BigInt<2>::operator^(const BigInt<2> &other) const {
  return pow(*this, other);
}

/**
 * @brief  Calculate the factorial of a number
 *
 * @return BigInt<2>
 */
BigInt<2> BigInt<2>::factorial() const {
  BigInt<2> result("01");
  BigInt<2> one("01");
  BigInt<2> zero("00");
  BigInt<2> i("01");
  while (i <= *this) {
    result = result * i;
    i = i + one;
  }
  return result;
}

/**
 * @brief Operator ! for BigInt<2> do factorial operation
 *
 * @return BigInt<2>
 */
BigInt<2> BigInt<2>::operator!() const {
  return this->factorial();
}

/**
 * @brief Return complement of a number
 *
 * @return BigInt<2>
 */
BigInt<2> BigInt<2>::operator-() const {
  return this->ConvertToTwosComplement();
}

/**
 * @brief Convert a BigInt<2> to a BigInt<base>
 *
 * @tparam base
 * @return BigInt<base>
 */
template <size_t base>
BigInt<2>::operator BigInt<base>() const {
  BigInt<base> result("0");
  BigInt<2> number = this->Abs();
  BigInt<base> expo("0");
  BigInt<base> one("1");
  BigInt<base> two(2);
  for (size_t i = 0; i < number.size(); i++) {
    if (number[i]) {
      result = result + pow(two, expo);
    }
    expo++;
  }
  // Divide result by Base to get the number into vector
  BigInt<base> aux = result;
  BigInt<base> zero("0");
  BigInt<base> base_number(base);
  std::vector<char> digits;
  while (aux != zero) {
    BigInt<base> mod = aux % base_number;
    digits.push_back(mod[0]);
    aux = aux / base_number;
  }
  int sign = this->digits[this->digits.size() - 1] ? -1 : 1;
  BigInt<base> result_final(digits, sign);
  return result_final;
}

/**
 * @brief Overload the operator << to print a BigInt<2> object
 *
 * @param os
 * @param number_x
 * @return std::ostream&
 */
std::ostream &operator<<(std::ostream &os, const BigInt<2> &number_x) {
  for (int i = number_x.digits.size() - 1; i >= 0; i--) {
    os << number_x.digits[i];
  }
  return os;
}