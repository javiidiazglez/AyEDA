//////////////////////////////////////////////////////////////////////////////////
// Universidad de La Laguna                                                     //
// Escuela Superior de Ingeniería y Tecnología                                  //
// Grado en Ingeniería Informática                                              //
// Algoritmos y Estructuras de datos Avanzados                                  //
// Fecha: 17/03/2021                                                            //
// Autor: José Javier Díaz González (alu0101128894)                             //
//                                                                              //
// Práctica 3: Mundo Hormigas                                                   //
// Referencias: https://es.wikipedia.org/wiki/Hormiga_de_Langton                //
// Nombre del archivo: world.h                                                  //
//////////////////////////////////////////////////////////////////////////////////

#ifndef WORLD_H
#define WORLD_H

#include <utility> // Uso de pair

#include "matrix.h"

enum FILL
{
  WHITE = '.',
  BLACK = 'X'
};
// World mundo(10,10); Error!
// World* mundo = new WorldFinito(10, 10); 
class World
{
public:
  World();
  World(int rows, int columns);
  World(const World &world);
  ~World();

  inline int MinRows() const { return min_rows_; } // return min_rows
  inline int MaxRows() const { return max_rows_; }
  inline int MinColumns() const { return min_columns_; }
  inline int MaxColumns() const { return max_columns_; }

  inline size_t Rows() const { return world_map_.Rows(); } // inline = ventaja de ejecucion en vez de llamar void Rows();
  inline size_t Columns() const { return world_map_.Columns(); }

  char &At(int row, int column); // dato rows y columns
  void operator=(const World &world);
  //void ExpandLimits(int row, int column);  ya no hace falta
  virtual void CheckLimits(int row, int column) = 0; // es una interfaz (abtractas) (no se puede instanciar)
  const char &At(int row, int column) const;
  std::pair<int, int> Map(int rows, int columns) const; // Mapea cordenadas negativas a positivas
  friend std::ostream &operator<<(std::ostream &os, const World &world);

protected: // lo ponemos en protegido para poder heredar
  Matrix<char> world_map_;
  int min_rows_; // declarar min_rows
  int min_columns_;
  int max_rows_;
  int max_columns_;
};

#endif
