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
 * @file bigint.cc: clase bigint
 * @brief Contiene definición de la clase bigint
 **/

#include "bigint.h"

#include <iostream>
#include <string>
#include <vector>
/**
 * @brief Construct a new Big Int< Base>:: Big Int object
 *
 * @param Base
 * @param n
 */
template <size_t Base>
BigInt<Base>::BigInt(long n) {
  if (n == 0) {
    sign_ = 1;
    digits_.push_back(0);
    return;
  }
  if (n < 0) {
    sign_ = -1;
    n = -n;
  } else {
    sign_ = 1;
  }
  while (n > 0) {
    digits_.push_back(n % Base);
    n /= Base;
  }
}

/**
 * @brief Construct a new Big Int< Base>:: Big Int object
 *
 * @param Base
 * @param number_str
 */
template <size_t Base>
BigInt<Base>::BigInt(std::string &number_str) {
  // Si es vacio
  if (number_str.empty()) {
    sign_ = 1;
    digits_.push_back(0);
    return;
  }
  std::string number_big = number_str;
  digits_.clear();
  if (number_big[0] == '-') {
    sign_ = -1;
    number_big.erase(0, 1);
  } else {
    sign_ = 1;
  }
  for (int i = number_big.size() - 1; i >= 0; i--) {
    if (isdigit(number_big[i])) {
      digits_.push_back(number_big[i] - '0');
    } else if (number_big[i] >= 'A' && number_big[i] <= 'F') {
      digits_.push_back(number_big[i] - 'A' + 10);
    } else {
      throw std::invalid_argument("Constructor(string): Invalid character");
    }
  }
}

/**
 * @brief Construct a new Big Int< Base>:: Big Int object
 *
 * @param Base
 * @param number_ptr
 */
template <size_t Base>
BigInt<Base>::BigInt(const char *number_ptr) {
  size_t size_number = std::char_traits<char>::length(number_ptr);
  // Si es vacio
  if (size_number == 0) {
    sign_ = 1;
    digits_.push_back(0);
    return;
  }
  digits_.clear();
  if (number_ptr[0] == '-') {
    sign_ = -1;
    number_ptr++;
    size_number--;
  } else {
    sign_ = 1;
  }
  for (int i = size_number - 1; i >= 0; --i) {
    if (isdigit(number_ptr[i])) {
      digits_.push_back(number_ptr[i] - '0');
    } else if (number_ptr[i] >= 'A' && number_ptr[i] <= 'F') {
      digits_.push_back(number_ptr[i] - 'A' + 10);
    } else {
      std::cout << (int)number_ptr[i] << std::endl;
      throw std::invalid_argument("Constructor(char): Invalid character");
    }
  }
}

/**
 * @brief Construct a new Big Int< Base>:: Big Int object
 *
 * @param Base
 * @param digits_aux
 * @param sign_aux
 */
template <size_t Base>
BigInt<Base>::BigInt(const std::vector<char> &digits_aux, const int &sign_aux) {
  char max_digit = static_cast<char>(Base);
  for (size_t i = 0; i < digits_aux.size(); i++) {
    if (digits_aux[i] >= max_digit) {
      throw std::invalid_argument("Constructor(vector): Invalid digit");
    }
  }
  digits_ = digits_aux;
  sign_ = sign_aux;
}

/**
 * @brief Construct a new Big Int< Base>:: Big Int object
 *
 * @param Base
 * @param number_big
 */
template <size_t Base>
BigInt<Base>::BigInt(const BigInt<Base> &number_big) {
  sign_ = number_big.sign_;
  digits_ = number_big.digits_;
}

/**
 * @brief Overload operator= for copy a BigInt
 *
 * @tparam Base
 * @param number_big
 * @return BigInt<Base>&
 */
template <size_t Base>
BigInt<Base> &BigInt<Base>::operator=(const BigInt<Base> &number_big) {
  sign_ = number_big.sign_;
  digits_ = number_big.digits_;
  return *this;
}
/**
 * @brief Set the Sign object
 *
 * @tparam Base
 * @param sign_aux
 * @return BigInt<Base>
 */
template <size_t Base>
BigInt<Base> BigInt<Base>::SetSign(int sign_aux) {
  sign_ = sign_aux;
  return *this;
}

/**
 * @brief Set the Digits object
 *
 * @param Base
 * @param digits_aux
 * @return BigInt<Base>
 */
template <size_t Base>
BigInt<Base> BigInt<Base>::SetDigits(std::vector<char> digits_aux) {
  digits_ = digits_aux;
  return *this;
}

/**
 * @brief Get the Digits object
 *
 * @param Base
 * @return std::vector<char>
 */
template <size_t Base>
std::vector<char> BigInt<Base>::GetDigits() const {
  return digits_;
}

/**
 * @brief Get the Sign object
 *
 * @param Base
 * @return int
 */
template <size_t Base>
int BigInt<Base>::GetSign() const {
  return sign_;
}

/**
 * @brief Get the Size object
 *
 * @param Base
 * @return size_t
 */
template <size_t Base>
int BigInt<Base>::sign() const {
  return sign_;
}

/**
 * @brief Get the Size object
 *
 * @tparam Base
 * @return size_t
 */
template <size_t Base>
size_t BigInt<Base>::size() const {
  return digits_.size();
}
/**
 * @brief Method for to access to the digits of the number
 * this method check if the position is valid and return the digit
 * if the position is invalid throw a out_of_range exception
 * @tparam Base
 * @param position
 * @return char
 */
template <size_t Base>
char BigInt<Base>::operator[](size_t position) const {
  if (position < 0 || position >= digits_.size()) {
    std::cout << "position: " << position << " Size " << digits_.size()
              << std::endl;
    throw std::out_of_range("operator[]: Invalid position");
  }
  return digits_[position];
}

/**
 * @brief Check if 2 BigInt are equal
 *
 * @tparam Base_t
 * @param number_x
 * @param number_y
 * @return true
 * @return false
 */
template <size_t Base_t>
bool operator==(const BigInt<Base_t> &number_x,
                const BigInt<Base_t> &number_y) {
  BigInt<Base_t> number_x_aux = number_x;
  BigInt<Base_t> number_y_aux = number_y;
  if (number_x_aux.IsZero() && number_y_aux.IsZero()) {
    return true;
  }
  if (number_x.GetSign() != number_y.GetSign()) {
    return false;
  }
  if (number_x.GetDigits().size() != number_y.GetDigits().size()) {
    // fill with zeros
    size_t size_difference =
        std::abs(static_cast<int>(number_x.GetDigits().size()) -
                 static_cast<int>(number_y.GetDigits().size()));
    if (number_x.GetDigits().size() > number_y.GetDigits().size()) {
      number_y_aux = number_y_aux.fill_zeros(size_difference);
    } else if (number_x.GetDigits().size() < number_y.GetDigits().size()) {
      number_x_aux = number_x_aux.fill_zeros(size_difference);
    }
  }

  for (size_t i = 0; i < number_x_aux.size(); i++) {
    if (number_x_aux[i] != number_y_aux[i]) {
      return false;
    }
  }
  return true;
}

/**
 * @brief Check if 2 BigInt are not equal
 *
 * @tparam Base
 * @param number_y
 * @return true
 * @return false
 */
template <size_t Base>
bool BigInt<Base>::operator!=(const BigInt<Base> &number_y) const {
  return !(*this == number_y);
}

/**
 * @brief Check if a BigInt is greater than other
 *
 * @tparam Base_t
 * @param number_x
 * @param number_y
 * @return true
 * @return false
 */
template <size_t Base_t>
bool operator>(const BigInt<Base_t> &number_x, const BigInt<Base_t> &number_y) {
  if (number_x.GetSign() > number_y.GetSign()) {
    return true;
  } else if (number_x.GetSign() < number_y.GetSign()) {
    return false;
  }
  size_t number_digit_different =
      abs(number_x.GetDigits().size() - number_y.GetDigits().size());
  BigInt<Base_t> number_y_aux;
  BigInt<Base_t> number_x_aux;
  if (number_x.GetDigits().size() > number_y.GetDigits().size()) {
    number_y_aux = number_y.fill_zeros(number_digit_different);
    number_x_aux = number_x;
  } else if (number_x.GetDigits().size() < number_y.GetDigits().size()) {
    number_x_aux = number_x.fill_zeros(number_digit_different);
    number_y_aux = number_y;
  } else {
    number_x_aux = number_x;
    number_y_aux = number_y;
  }

  for (int i = number_x_aux.GetDigits().size() - 1; i >= 0; i--) {
    if (number_x_aux.GetDigits()[i] > number_y_aux.GetDigits()[i]) {
      return number_x_aux.GetSign() == 1 ? true : false;
    } else if (number_x_aux.GetDigits()[i] < number_y_aux.GetDigits()[i]) {
      return number_x_aux.GetSign() == 1 ? false : true;
    }
  }
  return false;
}

/**
 * @brief Check if a BigInt is greater or equal than other
 *
 * @tparam Base
 * @param number_y
 * @return true
 * @return false
 */
template <size_t Base>
bool BigInt<Base>::operator>=(const BigInt<Base> &number_y) const {
  return (*this > number_y || *this == number_y);
}

/**
 * @brief Check if a BigInt is less than other
 *
 * @tparam Base_t
 * @param number_x
 * @param number_y
 * @return true
 * @return false
 */
template <size_t Base_t>
bool operator<(const BigInt<Base_t> &number_x, const BigInt<Base_t> &number_y) {
  return !(number_x >= number_y);
}

/**
 * @brief Check if a BigInt is less or equal than other
 *
 * @tparam Base
 * @param number_y
 * @return true
 * @return false
 */
template <size_t Base>
bool BigInt<Base>::operator<=(const BigInt<Base> &number_y) const {
  return !(*this > number_y);
}

/**
 * @brief Check if a BigInt is zero
 *
 * @tparam Base
 * @return true
 * @return false
 */
template <size_t Base>
bool BigInt<Base>::IsZero() const {
  // Check if the number is zero or not
  for (size_t i = 0; i < digits_.size(); i++) {
    if (digits_[i] != 0) {
      return false;
    }
  }
  return true;
}

/**
 * @brief insert zeros at the begin of the number
 *
 * @tparam Base
 * @param number_zero
 * @return BigInt<Base>
 */
template <size_t Base>
BigInt<Base> BigInt<Base>::fill_zeros(unsigned number_zero) const {
  std::string number_str = this->to_string();
  number_str.insert(number_str.begin(), number_zero, '0');
  return BigInt<Base>(number_str);
}

/**
 * @brief Get absolute value of a BigInt
 *
 * @tparam Base
 * @return BigInt<Base>
 */
template <size_t Base>
BigInt<Base> BigInt<Base>::Abs() const {
  BigInt<Base> number_aux = *this;
  number_aux.SetSign(1);
  return number_aux;
}

/**
 * @brief Convert a BigInt to string
 * this function is used to print the number
 * For example, if the number is 1234, the string will be "4321"
 *
 * @tparam Base
 * @return std::string
 */
template <size_t Base>
std::string BigInt<Base>::to_string() const {
  std::string number_str;
  if (sign_ == -1) {
    number_str += '-';
  }
  for (int i = digits_.size() - 1; i >= 0; i--) {
    if (digits_[i] < 10) {
      number_str += digits_[i] + '0';
    } else {
      number_str += digits_[i] - 10 + 'A';
    }
  }
  return number_str;
}

/**
 * @brief Negate a BigInt
 *
 * @tparam Base
 * @return BigInt<Base>
 */
template <size_t Base>
BigInt<Base> BigInt<Base>::operator-() const {
  BigInt<Base> number_aux = *this;
  number_aux.SetSign(-number_aux.GetSign());
  return number_aux;
}

/**
 * @brief Add two BigInt
 *
 * @tparam Base_t
 * @param number_x
 * @param number_y
 * @return BigInt<Base_t>
 */
template <size_t Base_t>
BigInt<Base_t> operator+(const BigInt<Base_t> &number_x,
                         const BigInt<Base_t> &number_y) {
  int carry = 0;
  size_t number_digit_different =
      abs(number_x.GetDigits().size() - number_y.GetDigits().size());
  BigInt<Base_t> number_y_aux;
  BigInt<Base_t> number_x_aux;
  if (number_x.GetDigits().size() > number_y.GetDigits().size()) {
    number_y_aux = number_y.fill_zeros(number_digit_different);
    number_x_aux = number_x;
  } else if (number_x.GetDigits().size() < number_y.GetDigits().size()) {
    number_x_aux = number_x.fill_zeros(number_digit_different);
    number_y_aux = number_y;
  } else {
    number_x_aux = number_x;
    number_y_aux = number_y;
  }
  // We need control the sign of the result of the operands because the sign is defined by the sign of the major operand
  if (number_x_aux.GetSign() != number_y_aux.GetSign()) {
    if (number_x_aux.GetSign() == -1) {
      return number_y_aux - (-number_x_aux);
    } else {
      return number_x_aux - (-number_y_aux);
    }
  }

  std::vector<char> digits_sum;
  for (size_t i = 0; i < number_x_aux.GetDigits().size(); i++) {
    int sum = number_x_aux[i] + number_y_aux[i] + carry;
    digits_sum.push_back(sum % Base_t);
    carry = sum / Base_t;
  }
  if (carry != 0) {
    digits_sum.push_back(carry);
  }
  return BigInt<Base_t>(digits_sum, number_x_aux.GetSign());
}

/**
 * @brief Subtract two BigInt
 *
 * @tparam Base
 * @param number_y
 * @return BigInt<Base>
 */
template <size_t Base>
BigInt<Base> BigInt<Base>::operator-(const BigInt<Base> &number_y) const {
  size_t number_digit_different =
      abs(this->GetDigits().size() - number_y.GetDigits().size());
  BigInt<Base> number_y_aux;
  BigInt<Base> number_x_aux;
  if (this->GetDigits().size() > number_y.GetDigits().size()) {
    number_y_aux = number_y.fill_zeros(number_digit_different);
    number_x_aux = *this;
  } else if (this->GetDigits().size() < number_y.GetDigits().size()) {
    number_x_aux = this->fill_zeros(number_digit_different);
    number_y_aux = number_y;
  } else {
    number_x_aux = *this;
    number_y_aux = number_y;
  }
  // Only for positive numbers and number_x_aux > number_y_aux we can control
  // this situation always

  if (number_x_aux < number_y_aux) {
    return BigInt<Base>(number_y_aux - number_x_aux).SetSign(-1);
  }
  if (number_x_aux.GetSign() == 1 && number_y_aux.GetSign() == -1) {
    return BigInt<Base>(number_x_aux + (-number_y_aux));
  } else if (number_x_aux.GetSign() == -1 && number_y_aux.GetSign() == 1) {
    return BigInt<Base>((-number_x_aux) + number_y_aux);
  } else if (number_x_aux.GetSign() == -1 && number_y_aux.GetSign() == -1) {
    return BigInt<Base>(number_x_aux + (-number_y_aux));
  }

  std::vector<char> digits_sub;
  int carry = 0;
  for (size_t i = 0; i < number_x_aux.size(); i++) {
    int sub = number_x_aux[i] - number_y_aux[i] - carry;
    if (sub < 0) {
      sub += Base;
      carry = 1;
    } else {
      carry = 0;
    }
    digits_sub.push_back(sub);
  }

  return BigInt<Base>(digits_sub, number_x_aux.GetSign());
}

/**
 * @brief Push back a digit to the BigInt
 *
 * @tparam Base
 * @param number_aux
 * @return BigInt<Base>
 */
template <size_t Base>
BigInt<Base> BigInt<Base>::PushBack(char number_aux) {
  digits_.push_back(static_cast<char>(number_aux));
  return *this;
}

/**
 * @brief Increment the BigInt
 *
 * @tparam Base
 * @return BigInt<Base>&
 */
template <size_t Base>
BigInt<Base> &BigInt<Base>::operator++() {
  BigInt<Base> One(1);
  *this = *this + One;
  return *this;
}

/**
 * @brief Increment the BigInt
 *
 * @tparam Base
 * @return BigInt<Base>
 */
template <size_t Base>
BigInt<Base> BigInt<Base>::operator++(int) {
  BigInt<Base> One(1);
  BigInt<Base> number_aux = *this;
  *this = *this + One;
  return number_aux;
}

/**
 * @brief Decrement the BigInt
 *
 * @tparam Base
 * @return BigInt<Base>&
 */
template <size_t Base>
BigInt<Base> &BigInt<Base>::operator--() {
  BigInt<Base> One(1);
  *this = *this - One;
  return *this;
}

/**
 * @brief Decrement the BigInt
 *
 * @tparam Base
 * @return BigInt<Base>
 */
template <size_t Base>
BigInt<Base> BigInt<Base>::operator--(int) {
  BigInt<Base> number_aux = *this;
  BigInt<Base> One(1);

  *this = *this - One;
  return number_aux;
}

/**
 * @brief Multiply two BigInt
 *
 * @tparam Base
 * @param number_y
 * @return BigInt<Base>
 */
template <size_t Base>
BigInt<Base> BigInt<Base>::operator*(const BigInt<Base> &number_y) const {
  size_t n = this->GetDigits().size();
  size_t m = number_y.GetDigits().size();
  std::vector<char> product(n + m, 0);

  if (this->IsZero() || number_y.IsZero()) {
    BigInt<Base> zero;
    return zero;
  }
  for (size_t i = 0; i < n; i++) {
    int carry = 0;
    for (size_t j = 0; j < m; j++) {
      int tmp = digits_[i] * number_y.digits_[j] + product[i + j] + carry;
      carry = tmp / Base;
      product[i + j] = (tmp % Base);
    }
    product[i + m] = (carry);
  }
  while (product.size() > 1 && product.back() == 0)
    product.pop_back();
  int sign = (this->GetSign() == number_y.GetSign()) ? 1 : -1;
  return BigInt(product, sign);
}

/**
 * @brief Divide two BigInt
 *
 * @tparam Base
 * @param number_x
 * @param number_y
 * @return BigInt<Base>
 */
template <size_t Base>
BigInt<Base> operator/(const BigInt<Base> &number_x,
                       const BigInt<Base> &number_y) {
  BigInt<Base> a = number_x;
  BigInt<Base> b = number_y;
  if (a < b) {
    return BigInt<Base>();
  }
  if (a == b) {
    return BigInt<Base>(1);
  }
  long i, lgcat = 0, cc;
  long n = a.GetDigits().size();
  std::vector<char> cat(n, 0);
  BigInt<Base> t;
  BigInt<Base> aux_base(Base);
  for (i = n - 1; i >= 0 && (t * aux_base) + BigInt<Base>(a[i]) < b; i--) {
    t = t * aux_base;
    t = t + BigInt<Base>((int)a[i]);
  }
  for (; i >= 0; i--) {
    t = (t * Base) + BigInt<Base>((int)a[i]);
    for (cc = Base - 1; b * cc > t; cc--)
      ;
    t = t - (b * cc);
    cat[lgcat++] = cc;
  }

  std::vector<char> result(cat.size(), 0);

  for (i = 0; i < lgcat; i++)
    result[i] = cat[lgcat - i - 1];
  int sign = (a.GetSign() == b.GetSign()) ? 1 : -1;

  // resultado
  while (result.size() > 1 && result.back() == 0)
    result.pop_back();

  BigInt<Base> r(result, sign);
  return r;
}

/**
 * @brief Modulo of two BigInt
 *
 * @tparam Base
 * @param number_y
 * @return BigInt<Base>
 */
template <size_t Base>
BigInt<Base> BigInt<Base>::operator%(const BigInt<Base> &number_y) const {
  return *this - (*this / number_y) * number_y;
}

template <size_t Base>
BigInt<Base> pow(const BigInt<Base> &number_x, const BigInt<Base> &number_y) {
  static BigInt<Base> zero;
  static BigInt<Base> one(1);
  static BigInt<Base> two(2);
  if (number_y < zero) {
    return zero;
  }
  if (number_y == zero) {
    return one;
  } else if (number_y % two == zero) {
    BigInt<Base> half = pow(number_x, number_y / two);
    return half * half;
  } else {
    BigInt<Base> half = pow(number_x, (number_y - one) / two);
    return half * half * number_x;
  }
}

/**
 * @brief Power of two BigInt
 *
 * @tparam Base
 * @param number_y
 * @return BigInt<Base>
 */
template <size_t Base>
BigInt<Base> BigInt<Base>::operator^(const BigInt<Base> &number_y) const {
  return pow(*this, number_y);
}

/**
 * @brief Output operator for BigInt
 *
 * @tparam Base_aux
 * @param os
 * @param number_aux
 * @return std::ostream&
 */
template <size_t Base_aux>
std::ostream &operator<<(std::ostream &os, const BigInt<Base_aux> &number_aux) {
  std::string number_str = number_aux.to_string();
  os << number_str;
  return os;
}

/**
 * @brief Input operator for BigInt
 *
 * @tparam Base_t
 * @param number_x
 * @return std::istream&
 */
template <size_t Base_t>
std::istream &operator>>(std::istream &, BigInt<Base_t> &number_x) {
  std::string number_str;
  std::cin >> number_str;
  number_x = BigInt<Base_t>(number_str);
  return std::cin;
}

template <size_t Base>
BigInt<Base> BigInt<Base>::operator!() const {
  BigInt<Base> number_aux = this->Abs();
  BigInt<Base> result("1");
  BigInt<Base> i("1");
  BigInt<Base> zero("0");
  if (number_aux == zero) {
    return result;
  }
  for (; i <= number_aux; ++i) {
    result = result * i;
  }
  return result;
}

/**
 * @brief Convert a BigInt to a BigInt<2>
 *
 * @tparam Base
 * @return BigInt<2>
 *
 */
template <size_t Base>
BigInt<Base>::operator BigInt<2>() {
  BigInt<Base> number_aux = this->Abs();  // Crear una copia del número y luego tomar su valor absoluto.
  BigInt<Base> zero;
  BigInt<Base> two(2);
  std::vector<bool> result;
  if (number_aux == zero) {
    result.push_back(false);
    result.push_back(0);
    return BigInt<2>(result);
  }
  while (number_aux != zero) {
    result.push_back(number_aux % two == zero ? false : true);
    number_aux = number_aux / two;
  }
  // pongo el signo
  result.push_back(0);

  // Comprobando si el signo del número es negativo.
  if (this->GetSign() == -1) {
    BigInt<2> aux(result);
    return -aux;
  }
  BigInt<2> aux(result);
  return aux;
}