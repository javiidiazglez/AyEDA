#ifndef EMPLEADO_H
#define EMPLEADO_H

#include <iostream>
#include <string>

class Empleado {
 public:
  Empleado() : nombre_(), fecha_(), id_(-1) {}
  Empleado(const std::string& nombre, const std::string& fecha, int id) : nombre_(nombre), fecha_(fecha), id_(id) {}

  // Sobrecarga
  friend bool operator<(const Empleado& empleado1, const Empleado& empleado2);
  friend bool operator>(const Empleado& empleado1, const Empleado& empleado2);
  friend bool operator==(const Empleado& empleado1, const Empleado& empleado2);
  friend std::ostream& operator<<(std::ostream& os, const Empleado& empleado);
  void operator=(const Empleado& empleado) {
    nombre_ = empleado.nombre_;
    fecha_ = empleado.fecha_;
    id_ = empleado.id_;
  }

 private:
  std::string nombre_;
  std::string fecha_;
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
  os << "Nombre: " << empleado.nombre_ << ", id: " << empleado.id_ << ", fecha: " << empleado.fecha_ << std::endl;
  return os;
}

#endif
