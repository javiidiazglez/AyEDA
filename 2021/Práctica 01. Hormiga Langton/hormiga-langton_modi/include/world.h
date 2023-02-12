// UNIVERSIDAD DE LA LAGUNA
// GRADO EN INGENIERIA INFORMATICA
// AUTOR: José Javier Díaz González
// FECHA: 04-03-2021
// E-MAIL: alu0101128894@ull.edu.es
// ASIGNATURA: Algoritmos y Estructras de datos Avanzados
// PRACTICA: P01 - Hormiga Laghton
// Referencias: https://es.wikipedia.org/wiki/Hormiga_de_Langton
// Nombre del archivo: world.h

#ifndef WORLD_H
#define WORLD_H

#include "matrix.h"

enum FILL {WHITE = 'O', BLACK = 'X'};  // modificacion = Whites = 0

class World {
  public:
    World();
    World(int rows, int columns);
    World(const World& world);
    ~World();

    inline size_t Rows() const { return world_map_.Rows(); } // inline = ventaja de ejecucion en vez de llamarr void Rows();
    inline size_t Columns() const { return world_map_.Columns(); }
    char& At(int row, int column); // dato en la fila y en la columna
    const char& At(int row, int column) const;
    void operator=(const World& world);
    friend std::ostream& operator<<(std::ostream& os, const World& world);

  private:
    Matrix<char> world_map_;
};

#endif  
