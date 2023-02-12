#include <unistd.h>

#include <fstream>
#include <iostream>

#include "../include/cell.h"
#include "../include/grid.h"

int instructions(std::string path) {
  std::ifstream instFile(path, std::ios::in);
  if (!instFile.is_open()) {
    std::cout << std::endl << "Error al cargar instrucciones!" << std::endl;
    return 1;
  }
  std::cout << instFile.rdbuf() << std::endl;
  return 0;
}

void checkError(int& opc) {
  while (std::cin.fail()) {
    std::cin.clear();
    std::cin.ignore(99, '\n');
    std::cout << "Introduzca un número válido: ";
    std::cin >> opc;
  }
}

Grid playLife() {
  int rows;
  int cols, turnos;
  std::cout << "¡Bienvenido al juego de la vida!" << std::endl;
  std::cout << "\nEscriba las dimensiones del tablero:" << std::endl;

  do {
    std::cout << "- Introduzca el número de filas [M]: ";
    std::cin >> rows;
    checkError(rows);
    std::cout << "- Introduzca el número de columnas [N]: ";
    std::cin >> cols;
    checkError(cols);
    if ((rows * cols) < 1) {
      std::cout << "\nBorde insuficiente." << std::endl;
      std::cout << "Escriba de nuevo: "
                << "\n"
                << std::endl;
    }
  } while ((rows * cols) < 1);

  std::cout << "\n- Introduzca cuántos turnos a jugar: ";
  std::cin >> turnos;
  checkError(turnos);
  while (turnos < 0) {
    std::cout << "¡Turnos fuera de rango!\n- Introduzca un Turno positivo: ";
    std::cin >> turnos;
  }

  Grid mundo(rows, cols, turnos);

  int vivas, i, j;

  std::cout << "\nEn el tablero de matriz [" << rows << " x " << cols
            << "]\n ¿Número de células vivas inicialmente? (Mínimo 1): ";
  std::cin >> vivas;
  checkError(vivas);
  while (vivas <= 0) {
    std::cout
        << "\n¡Números de células fuera de rango!\n- Introduzca una célula "
           "dentro del rango (Mínimo 1): ";
    std::cin >> vivas;
  }
  std::cout << "\nIntroduzca posiciones de las [" << vivas
            << "] celulas: " << std::endl;
  for (int k = 0; k < vivas; k++) {
    std::cout << "\nCélula [" << k << "]: " << std::endl;
    std::cout << "   Fila    : ";
    std::cin >> i;
    checkError(i);
    while (i > rows || i <= 0) {
      std::cout
          << "¡Fila fuera de rango!\n- Introduzca una nueva Fila válida: ";
      std::cin >> i;
    }
    std::cout << "   Columna : ";
    std::cin >> j;
    checkError(j);
    while (j > cols || j <= 0) {
      std::cout << "¡Columna fuera de rango!\n- Introduzca una nueva Columna "
                   "válida: ";
      std::cin >> j;
    }
    //grid_[i][j].setState(viva);
    mundo.getCell(i,j).setState(viva);
  }
  return mundo;
}

int main(int argc, char* argv[]) {
  if (argc > 1) {
    instructions("instruction.txt");
    return 0;
  }

  Grid play = playLife();  // empezar juego de la vida

  play.nextGeneration();

  return 0;
}
