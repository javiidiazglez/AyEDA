/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingenierıa Informatica
 * Asignatura: Algoritmos y Estructuras de Datos Avanzadas
 * Curso: 2º
 * Práctica 6: Arboles
 * 
 * @author José Javier Díaz González
 * Correo: alu0101128894@ull.edu.es
 *
 * @date 3/05/2023
 * @file main.cc: clase main
 * @brief Contiene definición de la clase
 **/

#include <fstream>
#include <iostream>
#include <limits>

#include "../include/AB.h"
#include "../include/ABB.h"
#include "../include/AVL.h"
#include "../include/NodeB.h"

void Help() {
  std::ifstream file_in;
  file_in.open("help.txt", std::ios::in);

  if (file_in.fail()) {
    std::cout << "[!] Error: No se pudo abrir el archivo" << std::endl;
    exit(1);
  }
  std::string aux;
  while (!file_in.eof()) {
    std::string aux;
    getline(file_in, aux);
    std::cout << aux << std::endl;
  }
  file_in.close();
}

int protectedMain(int argc, char* argv[]) {

  #ifdef TRAZA
    std::cout << "\033[36m" << "\nModo CON Traza!" << "\033[0m" << std::endl;
  #endif
  #ifdef SINTRAZA
    std::cout << "\033[36m" << "\nModo SIN Traza!" << "\033[0m" << std::endl;
  #endif

  int type;
  while (true) {
    std::cout << "\n¿Que tipo de arbol quiere crear?\n"
              << "[1] ABB\n"
              << "[2] AVL\n";
    std::cout << "- Introduzca una opción: ";
    std::cin >> type;

    if (std::cin.fail()) {
      std::cout << "\033[0;31m" << "\n\t[!] Error: La opción debe ser un número positivo."  << "\033[0m" << std::endl;
      std::cin.clear();
      std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
      continue;  // Volver a imprimir el menú
    }
    if (type != 1 && type != 2) {
      std::cout << "\033[0;31m" << "\n\t[!] Error: No se ha introducido un tipo de arbol valido" << "\033[0m" << std::endl;

      continue;  // Volver a imprimir el menú
    }
    break;  // La opción es válida, salir del bucle
  }

  AB<long>* arbol;
  if (type == 1) {
    arbol = new ABB<long>();
  } else if (type == 2) {
    arbol = new AVL<long>();
  }

  long Key;
  int option = -1;
  do {
    std::cout << "\n[0] Salir" << std::endl;
    std::cout << "[1] Insertar clave" << std::endl;
    std::cout << "[2] Buscar clave" << std::endl;
    std::cout << "[3] Mostrar Arbol" << std::endl;
    std::cout << "[4] Mostrar arbol Inorden" << std::endl;
    std::cout << "[5] Mostrar arbol Preorden" << std::endl;
    std::cout << "[6] Mostrar arbol Postorden" << std::endl;
    std::cout << "[7] Eliminar Clave" << std::endl;

    std::cout << "- Introduzca una opción: ";
    std::cin >> option;

    if (std::cin.fail() || option < 0 || (option != 0 && option != 1 && option != 2 && option != 3 && option != 4 && option != 5 && option != 6 && option != 7)) {
      std::cout << "\033[0;31m" << "\n\t[!] Error: Opción inválida! Por favor, ingrese un número entero positivo válido (0, 1, 2, 4, 5, 6, o 7)." << "\033[0m" << std::endl;
      std::cin.clear();
      std::cin.ignore(256, '\n');
    } else {
      switch (option) {
        case 0:
          std::cout << "\nSaliendo correctamente..." << std::endl;
          delete arbol;
          return 0;
        case 1:
          do {
            std::cout << "\n➔  Introduzca la clave a insertar: ";
            std::cin >> Key;
            if (std::cin.fail() || Key < 0 || std::cin.peek() != '\n') {
              std::cout << "\033[0;31m" << "\n\t[!] Error: Clave inválida! Por favor ingrese un número entero positivo." << "\033[0m" << std::endl;
              std::cin.clear();
              std::cin.ignore(256, '\n');
            } else {
              break;
            }
          } while (true);

          if (arbol->insertar(Key)) {
            std::cout << "\033[0;32m" << "\nLa Clave '" << Key << "' ha sido insertada correctamente!" << "\033[0m" << std::endl;
            arbol->operator>>(std::cout);
          } else {
            std::cout << "\033[0;31m" << "\n\t[!] Error: Clave '" << Key << "' ya existe!" << "\033[0m" << std::endl;
          }
          break;
        case 2:
          do {
            std::cout << "\n➔ Introduzca la clave a buscar: ";
            std::cin >> Key;
            if (std::cin.fail() || Key < 0 || std::cin.peek() != '\n') {
              std::cout << "\033[0;31m" << "\n\t[!] Error: Clave inválida! Por favor ingrese un número entero positivo."  << "\033[0m" << std::endl;
              std::cin.clear();
              std::cin.ignore(256, '\n');
            } else {
              break;
            }
          } while (true);

          if (arbol->buscar(Key))
            std::cout << "\033[0;32m"  << "\nLa Clave '" << Key << "' ha sido encontrada!"  << "\033[0m" << std::endl;
          else
            std::cout << "\033[0;31m"  << "\n\t[!] Error: La Clave '" << Key << "' no ha sido encontrada!"  << "\033[0m" << std::endl;
          break;
        case 3:
          arbol->operator>>(std::cout);
          break;
        case 4:
          std::cout << "\n➔  El Árbol InOrden es: ";
          arbol->inorden(arbol->get_raiz());
          std::cout << std::endl;
          break;
        case 5:
          std::cout << "\n➔  El Árbol PreOrden es: ";
          arbol->preorden(arbol->get_raiz());
          std::cout << std::endl;
          break;
        case 6:
          std::cout << "\n➔  El Árbol PostOrden es: ";
          arbol->postorden(arbol->get_raiz());
          std::cout << std::endl;
          break;
        case 7:
          do {
            std::cout << "\n➔  Eliminar una clave: ";
            std::cin >> Key;
            if (std::cin.fail() || Key < 0 || std::cin.peek() != '\n') {
              std::cout << "\033[0;31m" << "\n\t[!] Error: Clave inválida! Por favor ingrese un número entero positivo."  << "\033[0m" << std::endl;
              std::cin.clear();
              std::cin.ignore(256, '\n');
            } else {
              break;
            }
          } while (true);

          if (arbol->eliminar(Key)) {
            std::cout << "\033[0;32m" << "\nLa Clave '" << Key << "' ha sido eliminada correctamente!" << "\033[0m" << std::endl;
            arbol->operator>>(std::cout); 
          } else {
            std::cout << "\033[0;31m" << "\n\t[!] Error: La Clave '" << Key << "' no ha sido encontrada!" << "\033[0m" << std::endl;
          }
          break;

        default:
          std::cout << "\033[0;31m" << "\n\t[!] Error: Opcion no valida" << "\033[0m" << std::endl;
          break;
      }
    }
  } while (true);
}

void Menu(int argc, char* argv[]) {
  switch (argc) {
    case 1:
      std::cout << "José Javier Díaz González" << std::endl;
      std::cout << "Práctica 6: Arboles" << std::endl;
      break;
    case 2:
      Help();
      exit(0);
      break;
    default:
      exit(1);
  }
}

int main(int argc, char* argv[]) {
  Menu(argc, argv);
  try {
    return protectedMain(argc, argv);
  } catch (std::system_error& e) {
    std::cerr << e.what() << '\n';
    return 2;
  }
  return EXIT_SUCCESS;
}