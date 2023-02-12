
/*
  Universidad de La Laguna
  Escuela Superior de Ingeniería y Tecnología
  Grado en Ingeniería Informática          
  Algoritmos y Estructuras de datos Avanzados
  Fecha: 08/04/2022     
  Autor: José Javier Díaz González (alu0101128894)
  Práctica 4. Tabla Hash                            
  Referencias: https://es.wikipedia.org/wiki/Tabla_hash
  Nombre del archivo: dispersion_module.h              
*/
                        
#ifndef DISPERSION_MODULE_H
#define DISPERSION_MODULE_H

#include <iostream>

#include "dispersion.h"

template <class Key>
class DispersionModule : public Dispersion<Key> {
 public:
  DispersionModule(size_t number_elements);
  virtual ~DispersionModule() {}

  size_t operator()(const Key& key) const; // interfaz, virtual, inserto el key (buscar o insertar)

 private:
  size_t number_elements_; // size tabla
};

template <typename Key>
DispersionModule<Key>::DispersionModule(size_t number_elements) {  // pasar el size (constructor)
  number_elements_ = number_elements;
}

template <typename Key>
size_t DispersionModule<Key>::operator()(const Key& key) const { 
  return key % number_elements_; // N % size
}

#endif
