//////////////////////////////////////////////////////////////////////////////////
// Universidad de La Laguna                                                     //
// Escuela Superior de Ingeniería y Tecnología                                  //
// Grado en Ingeniería Informática                                              //
// Algoritmos y Estructuras de datos Avanzados                                  //
// Fecha: 16/04/2021                                                            //
// Autor: José Javier Díaz González (alu0101128894)                             //
//                                                                              //
// Práctica 7. Tabla Hash con dispersión cerrada                                //
// Referencias: https://es.wikipedia.org/wiki/Tabla_hash                        //
// Nombre del archivo: dispersion_pseudorandom.h                                //
//////////////////////////////////////////////////////////////////////////////////

#ifndef DISPERSION_PSEUDORANDOM_H
#define DISPERSION_PSEUDORANDOM_H

#include <cstdlib>  // Uso de random
#include <iostream>

#include "dispersion.h"

template <typename Key>
class DispersionPsudorandom : public Dispersion<Key> {
 public:
  DispersionPsudorandom(size_t number_elements);
  virtual ~DispersionPsudorandom() {}

  size_t operator()(const Key& key) const;

 private:
  size_t number_elements_;
};

template <typename Key>
DispersionPsudorandom<Key>::DispersionPsudorandom(size_t number_elements) {
  number_elements_ = number_elements;
}

template <typename Key>
size_t DispersionPsudorandom<Key>::operator()(const Key& key) const {
  srand(key);
  return rand() % number_elements_;
}

#endif
