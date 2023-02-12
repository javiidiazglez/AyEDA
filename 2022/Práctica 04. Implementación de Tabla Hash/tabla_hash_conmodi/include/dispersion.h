/*
  Universidad de La Laguna
  Escuela Superior de Ingeniería y Tecnología
  Grado en Ingeniería Informática          
  Algoritmos y Estructuras de datos Avanzados
  Fecha: 08/04/2022     
  Autor: José Javier Díaz González (alu0101128894)
  Práctica 4. Tabla Hash                            
  Referencias: https://es.wikipedia.org/wiki/Tabla_hash
  Nombre del archivo: dispersion.h               
*/

#ifndef DISPERSION_H
#define DISPERSION_H

#include <iostream>

template <class Key>
class Dispersion { // Interfaz
 public:
  virtual ~Dispersion() {}
  virtual size_t operator()(const Key& key) const = 0; // metodo puro (no tiene definicion) (No se instancia)
};

#endif
