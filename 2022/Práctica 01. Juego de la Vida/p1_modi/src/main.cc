#include <iostream>
#include <unistd.h>
#include <fstream>
#include <string>
#include "cell.h"
#include "grid.h"

using namespace std;

int instrucciones(string path) {
  ifstream instFile(path, ios::in);
  if (!instFile.is_open()) {
    cout << endl << "Error al cargar instrucciones!" << endl;
    return 1;
  }
  cout << instFile.rdbuf() << endl;
  return 0;
}

void error (int &opc){
	while (cin.fail()){
		cin.clear();
		cin.ignore(99, '\n');
		cout << "Introduzca un número válido: ";
		cin >> opc;
	}
}

Grid juego_vida(){
  int rows, cols, turnos;
  cout << "¡Bienvenido al juego de la vida!" << endl;
  cout << "\nEscriba las dimensiones del tablero:" << endl;

  do {
    cout << "- Introduzca el número de filas [M]: "; 
    cin >> rows;
    error(rows);
    cout << "- Introduzca el número de columnas [N]: "; 
    cin >> cols;
    error(cols);
    if ((rows * cols) < 1){
      cout << "\nBorde insuficiente." << endl;
      cout << "Escriba de nuevo: " << "\n" << endl;
    }
  } while ((rows * cols) < 1);
  
  cout << "\n- Introduzca cuántos turnos a jugar: ";
  cin >> turnos;
  error(turnos);
  while (turnos < 0) {
    cout << "¡Turnos fuera de rango!\n- Introduzca un Turno positivo: ";
    cin >> turnos;
  }

  Grid mundo(rows, cols, turnos);

  return mundo;
}

int  main(int argc, char* argv[]) {
    if (argc > 1) {
      instrucciones("instrucciones.txt");
      return 0;
    }

    Grid juego = juego_vida(); // empezar juego de la vida

    juego.nextGeneration();

    
    return 0;
} 


/*
    
*/