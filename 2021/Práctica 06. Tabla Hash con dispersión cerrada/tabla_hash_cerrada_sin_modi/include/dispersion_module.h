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
// Nombre del archivo: dispersion_module.h                                      //
//////////////////////////////////////////////////////////////////////////////////

#ifndef DISPERSION_MODULE_H
#define DISPERSION_MODULE_H

#include <iostream>

#include "dispersion.h"

template <typename Key>
class DispersionModule : public Dispersion<Key> {
 public:
  DispersionModule(size_t number_elements);
  virtual ~DispersionModule() {}

  size_t operator()(const Key& key) const;

 private:
  size_t number_elements_;
};

template <typename Key>
DispersionModule<Key>::DispersionModule(size_t number_elements) {
  number_elements_ = number_elements;
}

template <typename Key>
size_t DispersionModule<Key>::operator()(const Key& key) const {
  return key % number_elements_;
}

#endif
