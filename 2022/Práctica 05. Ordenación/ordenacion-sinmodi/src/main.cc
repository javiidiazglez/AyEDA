/*
  Universidad de La Laguna
  Escuela Superior de Ingeniería y Tecnología
  Grado en Ingeniería Informática          
  Algoritmos y Estructuras de datos Avanzados
  Fecha: 29/04/2022     
  Autor: José Javier Díaz González (alu0101128894)
  Práctica 5. Ordenación                           
  Referencias: https://es.wikipedia.org/wiki/Algoritmo_de_ordenamiento 
  Nombre del archivo: main.cc                  
*/

#include <cstdlib>  // rand
#include <ctime>    // time
#include <iostream>
#include <vector>
#include <string>
#include <fstream>

#include "../include/heapsort.h"
#include "../include/insercion.h"
#include "../include/mergesort.h"
#include "../include/quicksort.h"
#include "../include/seleccion.h"
#include "../include/shellsort.h"
#include "../include/radixsort.h"
#include "../include/sacudida.h"
#include "../include/bubblesort.h"

std::vector<int> aux;  // {10, 288, 2, 182, 94, 923, 873, 9};

void resultado(Algorithm<int>* algoritmo) {
  auto solucion = aux;
  // Vector generado
  std::cout << "\n-> Vector generado: "; 
  for (int i = 0; i < aux.size(); i++) {
    std::cout << aux[i] << " ";
  }
  std::cout << std::endl;
  solucion = algoritmo->metodo(aux, aux.size());

  // Vector Final
  std::cout << "\n\n-> Vector final: \n< ";
  for (int i = 0; i < solucion.size(); i++) {
    std::cout << "\033[1;33m" << solucion[i] << ", " << "\033[0m";  // amarillo
  }
  std::cout << ">";
  std::cout << std::endl;

  if (algoritmo != NULL) {
    delete algoritmo;
    algoritmo = NULL;
  }
}

void error (int &opc){
	while (std::cin.fail()){
		std::cin.clear();
		std::cin.ignore(99, '\n');
		std::cout << "-> Error. Introduzca un número válido: ";
		std::cin >> opc;
	}
}
int instrucciones(std::string path) {
  std::ifstream instFile(path, std::ios::in);
  if (!instFile.is_open()) {
    std::cout << std::endl << "\033[0;31m" <<"Error al cargar instrucciones!" << std::endl;
    return 1;
  }
  std::cout << instFile.rdbuf() <<  std::endl;
  return 0;
}

int main(int argc, char* argv[]) {
  if (argc > 1) {
    instrucciones("instrucciones.txt");
    return 0;
  }
  Algorithm<int>* algoritmo = NULL;
  bool is_break = false;

  int vectorSize, opcion = 0;
  std::cout << "\nIntroducir tamaño del vector: ";
  std::cin >> vectorSize;
  error(vectorSize);
  bool sup = false;
  while(sup != true) {
    std::cout << "\n1. Introducir vector manualmente." << std::endl;
    std::cout << "2. Generar vector aleatorio." << std::endl;
    std::cout << "-> Introduce una opción: ";
    std::cin >> opcion;
    error(opcion);
    std::cin.clear();
    switch (opcion) {
      case 1:
        std::cout << "\n- Introduzca el vector y pulser ENTER: " << std::endl;
        for (int i = 0; i < vectorSize; i++) {
          std::cin >> opcion;
          error(opcion);
          aux.push_back(opcion);
        }
        std::cout << "\n- Vector = < ";
        for (int i = 0; i < aux.size(); i++) {
          std::cout << aux[i] << " ";
        }
        std::cout << ">";
        std::cout << "\n- Tamaño: " << vectorSize << std::endl;
        sup = true;
        break;
      case 2:
        srand(time(NULL));
        std::cout << "\n- Generar vector aleatorio = < ";
        for (int i = 0; i < vectorSize; i++) {
          opcion = rand() % (9999 + 1 - 1000) + 1000;  // 1000 y 9999
          aux.push_back(opcion);
          std::cout << opcion << " ";
        }
        std::cout << ">" << std::endl;
        std::cout << "- Tamaño: " << vectorSize << std::endl;
        sup = true;
        break;
      default:
        std::cout << "\nIntroduzca una opcion valida. Selecciona de nuevo.\n";
    }
  }
  opcion = 0;
  auto solucion = aux; // instanciando el aux 
  do {
    std::cout << "\n- Algoritmos de Ordenación -" << std::endl;
    std::cout << "1. Selección" << std::endl
              << "2. QuickSort" << std::endl
              << "3. ShellSort" << std::endl
              << "4. Heapsort" << std::endl
              << "5. Radixsort" << std::endl
              << "6. Mergesort" << std::endl
              << "7. Insercción" << std::endl
              << "8. Sacudida" << std::endl
              << "9. Bubblesort" << std::endl
              << "10. Salir" << std::endl;
    std::cout << "-> Introduzca el algoritmo a ejecutar: ";
    std::cin >> opcion;
    error(opcion);
    std::cin.clear();

    switch (opcion) {
      // Seleccion
      case 1: {
        std:: cout << "\nSeleccion: \n";
        algoritmo = new seleccion<int>;
        resultado(algoritmo);
        break;
      }
      // Quicksort
      case 2: {
        std:: cout << "\nQuicksort: \n";
        algoritmo = new quicksort<int>;
        resultado(algoritmo);
        break;
      }
      // Shellsort
      case 3: {
        std:: cout << "\nShellsort: \n";
        algoritmo = new shellsort<int>;
        resultado(algoritmo);
        break;
      }
      // Heapsort
      case 4: {
        std:: cout << "\nHeapsort: \n";
        algoritmo = new heapsort<int>;
        resultado(algoritmo);
        break;
      }
      // radixsort
      // case 5: {
      //   std:: cout << "\nRadixsort: \n";
      //   algoritmo = new radixsort<int>;
      //   resultado(algoritmo);
      //   break;
      // }
      // Mergesort
      case 6: {
        std:: cout << "\nMergesort: \n";
        algoritmo = new mergesort<int>;
        resultado(algoritmo);
        break;
      }
      // Insercion
      case 7: {
        std:: cout << "\nInserción: \n";
        algoritmo = new insercion<int>;
        resultado(algoritmo);
        break;
      }
      // Sacudida
      case 8: {
        std:: cout << "\nSacudida: \n";
        algoritmo = new sacudida<int>;
        resultado(algoritmo);
        break;
      }
      // Bubblesort
      case 9: {
        std:: cout << "\nBubblesort: \n";
        algoritmo = new bubblesort<int>;
        resultado(algoritmo);
        break;
      }
      // Salida
      case 10: {
        return 0;
        break;
      }
      default:
        std::cout << "\nIntroduzca una opción valida. Selecciona de nuevo.\n\n";
          break;
    }

    if (is_break) break;

  } while (opcion != 10);
}