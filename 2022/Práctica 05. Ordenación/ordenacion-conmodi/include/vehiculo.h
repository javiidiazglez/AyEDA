#ifndef Vehiculo_H
#define Vehiculo_H

#include <iostream>
#include <string>

class Vehiculo {
 public:
  Vehiculo() : matricula_() {}
  Vehiculo(const std::string& matricula) : matricula_(matricula){}

  // Sobrecarga
  friend bool operator<(const Vehiculo& Vehiculo1, const Vehiculo& Vehiculo2);
  friend bool operator>(const Vehiculo& Vehiculo1, const Vehiculo& Vehiculo2);
  friend bool operator==(const Vehiculo& Vehiculo1, const Vehiculo& Vehiculo2);
  friend std::ostream& operator<<(std::ostream& os, const Vehiculo& Vehiculo);
  void operator=(const Vehiculo& Vehiculo) {
    matricula_ = Vehiculo.matricula_;
  }

 private:
  std::string matricula_;
};

bool operator<(const Vehiculo& Vehiculo1, const Vehiculo& Vehiculo2) {
  return Vehiculo1.matricula_ < Vehiculo2.matricula_; // por matricula_
}

bool operator>(const Vehiculo& Vehiculo1, const Vehiculo& Vehiculo2) {
  return Vehiculo1.matricula_ > Vehiculo2.matricula_;
}

bool operator==(const Vehiculo& Vehiculo1, const Vehiculo& Vehiculo2) {
  return Vehiculo1.matricula_ == Vehiculo2.matricula_;
}

std::ostream& operator<<(std::ostream& os, const Vehiculo& Vehiculo) {
  os << "matricula: " << Vehiculo.matricula_ << std::endl;
  return os;
}

#endif
