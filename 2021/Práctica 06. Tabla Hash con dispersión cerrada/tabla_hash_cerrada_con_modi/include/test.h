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
// Nombre del archivo: test.h                                                   //
//////////////////////////////////////////////////////////////////////////////////

/* BANCO DE PRUEBAS (MODIFICACION) */

#ifndef TEST_H
#define TEST_H

#include <cstdlib>
#include <ctime>

#include "dispersion_module.h"
#include "dispersion_pseudorandom.h"
#include "exploration_double.h"
#include "exploration_lineal.h"
#include "exploration_quadratic.h"
#include "exploration_redispersion.h"
#include "hash_table_closed.h"

class Test {
 public:
  Test(size_t tam_tabla, size_t limit_columna, size_t numero_elementos_insertar);
  void Run();
  void Fill();

 private:
  size_t tam_tabla_;
  size_t limit_columna_;
  size_t numero_elementos_insertar_;
  HashTableClosed<int>* table_;
};

Test::Test(size_t tam_tabla, size_t limit_columna, size_t numero_elementos_insertar) {
  table_ = NULL;
  tam_tabla_ = tam_tabla;
  limit_columna_ = limit_columna;
  numero_elementos_insertar_ = numero_elementos_insertar;
}

void Test::Run() {
  // el resultado es la suma de todas las soluciones
  // el resultado / numero de casos

  // lineal
  table_ = new HashTableClosed<int>(tam_tabla_, limit_columna_,
                                    new DispersionModule<int>(tam_tabla_), new ExplorationLineal<int>(tam_tabla_));
  Fill();
  table_->Search(10);
  std::cout << "lineal: " << table_->contador << std::endl;
  delete table_;
  table_ = NULL;

  // cuadratica
  table_ = new HashTableClosed<int>(tam_tabla_, limit_columna_,
                                    new DispersionModule<int>(tam_tabla_), new ExplorationQuadratic<int>(tam_tabla_));
  Fill();
  table_->Search(10);
  std::cout << "cuadratica: " << table_->contador << std::endl;
  delete table_;
  table_ = NULL;

  // redispersion
  table_ = new HashTableClosed<int>(tam_tabla_, limit_columna_,
                                    new DispersionModule<int>(tam_tabla_), new ExplorationRedispersion<int>(tam_tabla_));
  Fill();
  table_->Search(10);
  std::cout << "redispersion: " << table_->contador << std::endl;
  delete table_;
  table_ = NULL;

  // doble
  table_ = new HashTableClosed<int>(tam_tabla_, limit_columna_,
                                    new DispersionModule<int>(tam_tabla_), new ExplorationDouble<int>(tam_tabla_));
  Fill();
  table_->Search(10);
  std::cout << "doble: " << table_->contador << std::endl;
  delete table_;
  table_ = NULL;
}

void Test::Fill() {
  srand(time(NULL));
  for (size_t i = 0; i < numero_elementos_insertar_; ++i) {
    table_->Insert(rand() % 100);
  }
}

#endif
