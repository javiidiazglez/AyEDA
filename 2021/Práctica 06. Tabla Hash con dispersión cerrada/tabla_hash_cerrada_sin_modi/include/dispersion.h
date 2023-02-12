//////////////////////////////////////////////////////////////////////////////////
// Universidad de La Laguna                                                     //
// Escuela Superior de Ingeniería y Tecnología                                  //
// Grado en Ingeniería Informática                                              //
// Algoritmos y Estructuras de datos Avanzados                                  //
// Fecha: 15/04/2021                                                            //
// Autor: José Javier Díaz González (alu0101128894)                             //
//                                                                              //
// Práctica 6. Tabla Hash con dispersión cerrada                                //
// Referencias: https://es.wikipedia.org/wiki/Tabla_hash                        //
// Nombre del archivo: dispersion.h                                             //
//////////////////////////////////////////////////////////////////////////////////

#ifndef DISPERSION_H
#define DISPERSION_H

#include <iostream>

template <typename Key>
class Dispersion {
 public:
  virtual ~Dispersion() {}
  virtual size_t operator()(const Key& key) const = 0;
};

#endif
