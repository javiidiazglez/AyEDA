#ifndef EMPLEADO_H
#define EMPLEADO_H

#include <iostream>
#include <string>

class Empleado {
 public:
  Empleado() {}
  Empleado(int id) : id_(id) {}

  // Sobrecarga
  friend bool operator<(const Empleado& empleado1, const Empleado& empleado2);
  friend bool operator>(const Empleado& empleado1, const Empleado& empleado2);
  friend bool operator==(const Empleado& empleado1, const Empleado& empleado2);
  friend std::ostream& operator<<(std::ostream& os, const Empleado& empleado);
  void operator=(const Empleado& empleado) {
    id_ = empleado.id_;
  }

 private:
  int id_;
};

bool operator<(const Empleado& empleado1, const Empleado& empleado2) {
  return empleado1.id_ < empleado2.id_; // por id_
}

bool operator>(const Empleado& empleado1, const Empleado& empleado2) {
  return empleado1.id_ > empleado2.id_;
}

bool operator==(const Empleado& empleado1, const Empleado& empleado2) {
  return empleado1.id_ == empleado2.id_;
}

std::ostream& operator<<(std::ostream& os, const Empleado& empleado) {
  os << empleado.id_ << " ";
  return os;
}

#endif
