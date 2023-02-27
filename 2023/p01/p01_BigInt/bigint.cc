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
 * @file bigint.cc: clase bigint
 * @brief Contiene definición de la clase bigint
**/

#include "bigint.h"

// Un constructor que toma un largo como argumento y establece el signo en 1 y los dígitos en el largo.
template <size_t Base>
BigInt<Base>::BigInt(long n) {
  if (n == 0) {
    sign_ = 0;
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
    n /= Base;  // Dividiendo el número por la base.
  }
}

// Un constructor que toma una cadena como argumento.
template <size_t Base>
BigInt<Base>::BigInt(std::string &number_string) {
  // Si es vacio
  if (number_string.empty()) {
    sign_ = 1;
    digits_.push_back(0);
    return;
  }
  std::string n_big = number_string;
  digits_.clear();
  if (n_big[0] == '-') {  // Comprobando si el primer carácter de la cadena n_big es un signo menos.
    sign_ = -1;
    n_big.erase(0, 1);  // Eliminando el primer carácter de la cadena.
  } else {
    sign_ = 1;
  }
  for (int pos_i = n_big.size() - 1; pos_i >= 0; pos_i--) {
    // Comprobando si n_big[pos_i] es un dígito.
    if (isdigit(n_big[pos_i])) {
      digits_.push_back(n_big[pos_i] - '0');                  // Si el valor del dígito d es menor de 10, se convierte al carácter ‘0’+d.
    } else if (n_big[pos_i] >= 'A' && n_big[pos_i] <= 'F') {  // Comprobando si el número está entre A y F.
      digits_.push_back(n_big[pos_i] - 'A' + 10);             // Si el valor del dígito d es igual o mayor de 10, y menor de 16, se convierte al carácter ‘A’ +d-10.
    } else {
      throw std::invalid_argument("Constructor(string): caracter invalido");
    }
  }
}
// / Un constructor que toma un puntero a un carácter como argumento.
template <size_t Base>
BigInt<Base>::BigInt(const char *number_pointer) {
  size_t size_number = std::char_traits<char>::length(number_pointer);
  // Si es vacio
  if (size_number == 0) {
    sign_ = 1;
    digits_.push_back(0);
    return;
  }
  digits_.clear();
  if (number_pointer[0] == '-') {  // Comprobando si el primer carácter de number_pointer es un signo '-'.
    sign_ = -1;
    number_pointer++;
    size_number--;
  } else {
    sign_ = 1;
  }
  for (int pos_i = size_number - 1; pos_i >= 0; --pos_i) {
    if (isdigit(number_pointer[pos_i])) {
      digits_.push_back(number_pointer[pos_i] - '0');  // Si el valor del dígito d es menor de 10, se convierte al carácter ‘0’+d.
    } else if (number_pointer[pos_i] >= 'A' && number_pointer[pos_i] <= 'F') {
      digits_.push_back(number_pointer[pos_i] - 'A' + 10);  // Si el valor del dígito d es igual o mayor de 10, y menor de 16, se convierte al carácter ‘A’ +d-10.
    } else {
      std::cout << (int)number_pointer[pos_i] << std::endl;
      throw std::invalid_argument("Constructor(char): Caracter invalido");  // error, no se visualiza
    }
  }
}

// Un constructor que toma un vector de caracteres y un int como argumentos.
template <size_t Base>
BigInt<Base>::BigInt(const std::vector<char> &digits_aux, const int &sign_aux) {
  char max_digit = static_cast<char>(Base);
  for (size_t pos_i = 0; pos_i < digits_aux.size(); pos_i++) {
    // Comprobando si el dígito en la posición actual es mayor o igual que el dígito máximo.
    if (digits_aux[pos_i] >= max_digit) {
      throw std::invalid_argument("Constructor(vector): Digito invalido");
    }
  }
  digits_ = digits_aux;
  sign_ = sign_aux;
}

// Un constructor de copias.
template <size_t Base>
BigInt<Base>::BigInt(const BigInt<Base> &n_big) {
  sign_ = n_big.sign_;
  digits_ = n_big.digits_;
}

// Operador de asignación.
template <size_t Base>
BigInt<Base> &BigInt<Base>::operator=(const BigInt<Base> &n_big) {
  sign_ = n_big.sign_;
  digits_ = n_big.digits_;
  return *this;
}
// Setter Sign
template <size_t Base>
BigInt<Base> BigInt<Base>::SetSign(int sign_aux) {
  sign_ = sign_aux;
  return *this;
}
// Setter Digits
template <size_t Base>
BigInt<Base> BigInt<Base>::SetDigits(std::vector<char> digits_aux) {
  digits_ = digits_aux;
  return *this;
}
// Getter Digits
template <size_t Base>
std::vector<char> BigInt<Base>::GetDigits() const {
  return digits_;
}
// Getter Sign int
template <size_t Base>
int BigInt<Base>::GetSign() const {
  return sign_;
}
template <size_t Base>
int BigInt<Base>::sign() const {
  return sign_;
}
template <size_t Base>
size_t BigInt<Base>::size() const {
  return digits_.size();
}

// Acceso operator []
template <size_t Base>
char BigInt<Base>::operator[](size_t position) const {
  if (position < 0 || position >= digits_.size()) {
    throw std::out_of_range("operator[]: Posicion invalida.");
  }
  return digits_[position];
}

// Comparador ==
template <size_t Base_t>
bool operator==(const BigInt<Base_t> &number_1, const BigInt<Base_t> &number_2) {
  BigInt<Base_t> number_1_aux = number_1;
  BigInt<Base_t> number_2_aux = number_2;
  if (number_1_aux.IsZero() && number_2_aux.IsZero()) {  // Comprobando si el punto es el punto en el infinito.
    return true;
  }
  if (number_1.GetSign() != number_2.GetSign()) {  // Comprobando si los signos de los dos números son diferentes.
    return false;
  }
  // Comprobando si el número de dígitos en los dos números es igual.
  if (number_1.GetDigits().size() != number_2.GetDigits().size()) {
    size_t size_diff = std::abs(static_cast<int>(number_1.GetDigits().size()) - static_cast<int>(number_2.GetDigits().size()));
    if (number_1.GetDigits().size() > number_2.GetDigits().size()) {
      number_2_aux.rellenar_ceros(size_diff);
    } else {
      number_1_aux.rellenar_ceros(size_diff);
    }
  }
  // Recorriendo la cadena number_1 y comprobando cada carácter.
  for (size_t pos_i = 0; pos_i < number_1.size(); pos_i++) {
    if (number_1[pos_i] != number_2[pos_i]) {
      return false;
    }
  }
  return true;
}

// Comparador =/=
template <size_t Base>
bool BigInt<Base>::operator!=(const BigInt<Base> &number_2) const {
  return !(*this == number_2);  // Comprobando si los dos números no son iguales.
}
// Comparador >
template <size_t Base_t>
bool operator>(const BigInt<Base_t> &number_1, const BigInt<Base_t> &number_2) {
  if (number_1.GetSign() > number_2.GetSign()) {
    return true;
  } else if (number_1.GetSign() < number_2.GetSign()) {
    return false;
  }
  size_t number_digit_diff = abs(number_1.GetDigits().size() - number_2.GetDigits().size());
  BigInt<Base_t> number_2_aux;
  BigInt<Base_t> number_1_aux;

  // Comprobando si el número de dígitos en number_1 es mayor que el número de dígitos en number_2.
  if (number_1.GetDigits().size() > number_2.GetDigits().size()) {
    number_2_aux = number_2.rellenar_ceros(number_digit_diff);
    number_1_aux = number_1;
  } else if (number_1.GetDigits().size() < number_2.GetDigits().size()) {
    number_1_aux = number_1.rellenar_ceros(number_digit_diff);
    number_2_aux = number_2;
  } else {
    number_1_aux = number_1;
    number_2_aux = number_2;
  }

  // Iterando a través de los dígitos del objeto number_1_aux.
  for (int pos_i = number_1_aux.GetDigits().size() - 1; pos_i >= 0; pos_i--) {
    if (number_1_aux.GetDigits()[pos_i] > number_2_aux.GetDigits()[pos_i]) {
      return number_1_aux.GetSign() == 1 ? true : false;  // Comprobando si el número es positivo o negativo.
    } else if (number_1_aux.GetDigits()[pos_i] < number_2_aux.GetDigits()[pos_i]) {
      return number_1_aux.GetSign() == 1 ? false : true;
    }
  }
  return false;
}

// Comparador >=
template <size_t Base>
bool BigInt<Base>::operator>=(const BigInt<Base> &number_2) const {
  return (*this > number_2 || *this == number_2);
}
// Comparador <
template <size_t Base_t>
bool operator<(const BigInt<Base_t> &number_1, const BigInt<Base_t> &number_2) {
  return !(number_1 >= number_2);
}
// Comparador <=
template <size_t Base>
bool BigInt<Base>::operator<=(const BigInt<Base> &number_2) const {
  return !(*this > number_2);
}
// Es cero?
template <size_t Base>
bool BigInt<Base>::IsZero() const {
  for (size_t pos_i = 0; pos_i < digits_.size(); pos_i++) {
    if (digits_[pos_i] != 0) {
      return false;  // retorna false
    }
  }
  return true;
}

// Rellenar ceros
template <size_t Base>
BigInt<Base> BigInt<Base>::rellenar_ceros(unsigned number_zero) const {
  std::string number_string = this->to_string();  // Convertir el número en una cadena.
  number_string.insert(number_string.begin(), number_zero, '0');
  return BigInt<Base>(number_string);
}
// Una función que devuelve el valor absoluto de BigInt.
template <size_t Base>
BigInt<Base> BigInt<Base>::Abs() const {
  BigInt<Base> number_aux = *this;
  number_aux.SetSign(1);
  return number_aux;
}

// to_string
template <size_t Base>
std::string BigInt<Base>::to_string() const {
  std::string number_string;
  if (sign_ == -1) {
    number_string += '-';
  }
  for (int pos_i = digits_.size() - 1; pos_i >= 0; pos_i--) {
    if (digits_[pos_i] < 10) {  // Comprobando si el dígito en la posición actual es menor que 10.
      number_string += digits_[pos_i] + '0';
    } else {
      number_string += digits_[pos_i] - 10 + 'A';
    }
  }
  return number_string;
}

// Una función que devuelve el negativo de BigInt.
template <size_t Base>
BigInt<Base> BigInt<Base>::operator-() const {
  BigInt<Base> number_aux = *this;
  number_aux.SetSign(-number_aux.GetSign());
  return number_aux;
}
// Operador +
template <size_t Base_t>
BigInt<Base_t> operator+(const BigInt<Base_t> &number_1, const BigInt<Base_t> &number_2) {
  int carry = 0;
  size_t number_digit_diff = abs(number_1.GetDigits().size() - number_2.GetDigits().size());

  BigInt<Base_t> number_2_aux;
  BigInt<Base_t> number_1_aux;
  // Comprobando si el número de dígitos en number_1 es mayor que el número de dígitos en number_2.
  if (number_1.GetDigits().size() > number_2.GetDigits().size()) {
    number_2_aux = number_2.rellenar_ceros(number_digit_diff);
    number_1_aux = number_1;
  } else if (number_1.GetDigits().size() < number_2.GetDigits().size()) {
    number_1_aux = number_1.rellenar_ceros(number_digit_diff);
    number_2_aux = number_2;
  } else {
    number_1_aux = number_1;
    number_2_aux = number_2;
  }
  // Comprobando si los signos de los dos números son diferentes.
  if (number_1_aux.GetSign() != number_2_aux.GetSign()) {
    if (number_1_aux.GetSign() == -1) {
      return number_2_aux - (-number_1_aux);
    } else {
      return number_1_aux - (-number_2_aux);
    }
  }

  std::vector<char> digits_sum;
  // Iterando a través de los dígitos del objeto number_1_aux.
  for (size_t pos_i = 0; pos_i < number_1_aux.GetDigits().size(); pos_i++) {
    int sum = number_1_aux[pos_i] + number_2_aux[pos_i] + carry;  // Sumando los dos números y el acarreo.
    digits_sum.push_back(sum % Base_t);                           // Sumando los dos números y almacenando el resultado en el vector de suma.
    carry = sum / Base_t;                                         // Sumar los dos números y almacenar el resultado en suma.
  }
  if (carry != 0) {
    digits_sum.push_back(carry);
  }
  return BigInt<Base_t>(digits_sum, number_1_aux.GetSign());  // Sumando dos BigInts juntos.
}
// Operador -
template <size_t Base>
BigInt<Base> BigInt<Base>::operator-(const BigInt<Base> &number_2) const {
  size_t number_digit_diff = abs(this->GetDigits().size() - number_2.GetDigits().size());

  BigInt<Base> number_2_aux;
  BigInt<Base> number_1_aux;
  if (this->GetDigits().size() > number_2.GetDigits().size()) {
    number_2_aux = number_2.rellenar_ceros(number_digit_diff);
    number_1_aux = *this;
  } else if (this->GetDigits().size() < number_2.GetDigits().size()) {
    number_1_aux = this->rellenar_ceros(number_digit_diff);
    number_2_aux = number_2;
  } else {
    number_1_aux = *this;
    number_2_aux = number_2;
  }

  if (number_1_aux < number_2_aux) {
    return BigInt<Base>(number_2_aux - number_1_aux).SetSign(-1);
  }
  if (number_1_aux.GetSign() == 1 && number_2_aux.GetSign() == -1) {  // Comprobando si el primer número es positivo y el segundo número es negativo.
    return BigInt<Base>(number_1_aux + (-number_2_aux));
  } else if (number_1_aux.GetSign() == -1 && number_2_aux.GetSign() == 1) {  // Comprobando si el primer número es negativo y el segundo número es positivo
    return BigInt<Base>((-number_1_aux) + number_2_aux);
  } else if (number_1_aux.GetSign() == -1 && number_2_aux.GetSign() == -1) {  // Comprobando si ambos números son negativos.
    return BigInt<Base>(number_1_aux + (-number_2_aux));
  }

  std::vector<char> digits_sub;
  int carry = 0;
  // Iterando a través del vector number_1_aux y agregando los valores al vector number_1.
  for (size_t pos_i = 0; pos_i < number_1_aux.size(); pos_i++) {
    int sub = number_1_aux[pos_i] - number_2_aux[pos_i] - carry;  // Restando los dos números.
    if (sub < 0) {
      sub += Base;
      carry = 1;
    } else {
      carry = 0;
    }
    digits_sub.push_back(sub);
  }

  return BigInt<Base>(digits_sub, number_1_aux.GetSign());  // Restando los dos números.
}

// Operador *
template <size_t Base>
BigInt<Base> BigInt<Base>::operator*(const BigInt<Base> &number_2) const {
  BigInt<Base> number_1_aux = this->Abs();     // Crear una copia del objeto que está llamando a la función.
  BigInt<Base> number_2_aux = number_2.Abs();  // Crear una copia del objeto number_2 y asignarla al objeto number_2_aux.
  BigInt<Base> result("0");                    // Crear un objeto BigInt llamado resultado e inicializarlo a 0.

  BigInt<Base> pos_i("0");
  for (; pos_i < number_2_aux; ++pos_i) {  // Comprobando si number_2_aux es menor que pos_i. Si es así, agregará 1 a pos_i.
    result = result + number_1_aux;
  }
  // Comprobando si los signos de los dos números son diferentes.
  if (this->GetSign() != number_2.GetSign()) {
    result = -result;
  }
  return result;
}
// Operador /
template <size_t Base>
BigInt<Base> operator/(const BigInt<Base> &number_1, const BigInt<Base> &number_2) {
  BigInt<Base> number_1_aux = number_1.Abs();
  BigInt<Base> number_2_aux = number_2.Abs();
  BigInt<Base> result("0");
  BigInt<Base> pos_i("0");
  if (number_2_aux == result) {
    throw std::invalid_argument("No se puede dividir por 0");
  }
  // Comprobando si number_1_aux es mayor o igual que number_2_aux. Si es así, incrementará pos_i.
  for (; number_1_aux >= number_2_aux; ++pos_i) {
    number_1_aux = number_1_aux - number_2_aux;
  }
  // Comprobando si los signos de los dos números son diferentes. Si lo son, devuelve -pos_i.
  if (number_1.GetSign() != number_2.GetSign()) {
    return -pos_i;
  }
  return pos_i;
}
// Operador %
template <size_t Base>
BigInt<Base> BigInt<Base>::operator%(const BigInt<Base> &number_2) const {
  BigInt<Base> number_1_aux = this->Abs();
  BigInt<Base> number_2_aux = number_2.Abs();
  BigInt<Base> result("0");
  if (number_2_aux == result) {
    throw std::invalid_argument("No se puede dividir por 0");
  }
  for (; number_1_aux >= number_2_aux; ++result) {
    number_1_aux = number_1_aux - number_2_aux;
  }
  // Comprobando si el signo del número es negativo.
  if (this->GetSign() == -1) {
    return -result;
  }
  return result;
}

// Operador pow
template <size_t Base>
BigInt<Base> pow(const BigInt<Base> &number_1, const BigInt<Base> &number_2) {
  BigInt<Base> number_1_aux = number_1.Abs();
  BigInt<Base> number_2_aux = number_2.Abs();
  BigInt<Base> result("1");
  BigInt<Base> pos_i("0");
  if (number_2_aux == pos_i) {  // si numero == 0
    return result;              // devuelve 1
  }
  // Multiplicando number_1_aux por sí mismo number_2_aux veces.
  for (; pos_i < number_2_aux; ++pos_i) {
    result = result * number_1_aux;
  }
  return result;
}

// Operador ^
template <size_t Base>
BigInt<Base> BigInt<Base>::operator^(const BigInt<Base> &number_2) const {
  return pow(*this, number_2);
}

// PushBack
template <size_t Base>
BigInt<Base> BigInt<Base>::PushBack(char number_aux) {
  digits_.push_back(static_cast<char>(number_aux));
  return *this;
}

// Un operador de preincremento.
template <size_t Base>
BigInt<Base> &BigInt<Base>::operator++() {
  BigInt<Base> uno(1);
  *this = *this + uno;
  return *this;
}
// Un operador de incremento de postfijo.
template <size_t Base>
BigInt<Base> BigInt<Base>::operator++(int) {
  BigInt<Base> uno(1);
  BigInt<Base> number_aux = *this;
  *this = *this + uno;
  return number_aux;
}
// Un operador de pre-decremento.
template <size_t Base>
BigInt<Base> &BigInt<Base>::operator--() {
  BigInt<Base> uno(1);
  *this = *this - uno;
  return *this;
}
// Un operador de decremento postfijo.
template <size_t Base>
BigInt<Base> BigInt<Base>::operator--(int) {
  BigInt<Base> number_aux = *this;
  BigInt<Base> uno(1);

  *this = *this - uno;
  return number_aux;
}

// Input
template <size_t Base_aux>
std::ostream &operator<<(std::ostream &os, const BigInt<Base_aux> &number_aux) {
  std::string number_string = number_aux.to_string();
  os << number_string;
  return os;
}

// Output
template <size_t Base_t>
std::istream &operator>>(std::istream &, BigInt<Base_t> &number_1) {
  std::string number_string;
  std::cin >> number_string;
  number_1 = BigInt<Base_t>(number_string);
  return std::cin;
}