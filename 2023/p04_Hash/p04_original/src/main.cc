/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingenierıa Informatica
 * Asignatura: Algoritmos y Estructuras de Datos Avanzadas
 * Curso: 2º
 * Práctica 4: Búsqueda por dispersión
 *
 * @author José Javier Díaz González
 * Correo: alu0101128894@ull.edu.es
 *
 * @date 27/03/2023
 * @file main.cc: clase main
 * @brief Contiene definición de la clase
 **/

#include <cstdlib>  //system(clear), rand
#include <fstream>
#include <iostream>
#include <stdexcept>
#include <system_error>

// #include "../hash_table/HashTable.h"
#include "hash_table/HashTable.h"

void Help() {
  std::ifstream file_in;
  file_in.open("help.txt", std::ios::in);

  if (file_in.fail()) {
    std::cout << "[!] No se pudo abrir el archivo" << std::endl;
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
  int size;
  bool validInput_size = false;

  do {
    std::cout << "\nIntroduzca el tamaño de la tabla: ";
    std::cin >> size;

    if (std::cin.fail()) {  // si la entrada falla (el usuario introduce letras)
      std::cout << "\t[!] La entrada debe ser un número positivo.\n";
      std::cin.clear();                                                    // limpiamos los flags de error
      std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');  // ignoramos lo que quede en el buffer
    } else if (size == 0) {
      std::cout << "\t[!] El tamaño de la tabla no puede ser 0.\n";
    } else if (size < 0) {
      std::cout << "\t[!] La entrada debe ser un número positivo.\n";
    } else {
      validInput_size = true;
    }
  } while (!validInput_size);

  DispersionFunction<long>* fd = nullptr;
  bool valid_input_fun = false;
  int fd_option;

  while (!valid_input_fun) {
    std::cout << "\n¿Qué función de dispersión desea utilizar? \n";
    std::cout << "[ 1 ] Modulo \n";
    std::cout << "[ 2 ] Pseudoaleatoria \n";
    std::cout << "[ 3 ] Basada en la suma \n";
    std::cout << "-> Introduce el tipo de dispersión [1|2|3]: ";
    std::cin >> fd_option;

    if (std::cin.fail()) {
      std::cout << "\t[!] La entrada debe ser un número. Introduzca [1|2|3].\n";
      std::cin.clear();
      std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    } else if (fd_option == 1 || fd_option == 2 || fd_option == 3) {
      switch (fd_option) {
        case 1:
          fd = new fdModule<long>(size);
          std::cout << "\n=> Se ha seleccionado la dispersión [Módulo]\n";
          break;
        case 2:
          fd = new fdRandom<long>(size);
          std::cout << "\n=> Se ha seleccionado la dispersión [Pseudoaleatoria]\n";
          break;
        case 3:
          fd = new fdSumatory<long>(size);
          std::cout << "\n=> Se ha seleccionado la dispersión [Basada en la suma]\n";
          break;
        default:
          std::cerr << "\n\t[!] Función de dispersión no válida. Introduzca [1|2|3]" << std::endl;
          continue;
      }
      valid_input_fun = true;
    } else {
      std::cout << "\t[!] Función de dispersión no válida. Introduzca [1|2|3].\n";
    }
  }

  int disper_option, fe_option;
  size_t block_size{0};
  ExplorationFunction<long>* fe = nullptr;

  bool valid_input_disp = false;
  while (!valid_input_disp) {
    std::cout << "\n¿Qué técnica de dispersión desea utilizar?\n";
    std::cout << "[ 1 ] Dispersión Abierta \n";
    std::cout << "[ 2 ] Dispersión Cerrada \n";
    std::cout << "-> Introduzca la técnica de dispersión [1|2]: ";
    std::cin >> disper_option;

    if (std::cin.fail()) {
      std::cout << "\t[!] La entrada debe ser un número. Introduzca [1|2].\n";
      std::cin.clear();
      std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    } else if (disper_option == 1 || disper_option == 2) {
      switch (disper_option) {
        case 1:
          std::cout << "\n=> Se ha seleccionado la técnica de dispersión [Abierta]\n" << std::endl;
          break;
        case 2:
          std::cout << "\n=> Se ha seleccionado la técnica de dispersión [Cerrada]\n";
          break;
      }
      valid_input_disp = true;
    } else {
      std::cout << "\t[!] Técnica de dispersión no válida. Introduzca [1|2].\n";
    }
  }

  if (disper_option == 2) {
    bool validInput_block_size = false;
    do {
      std::cout << "\nIntroduzca el tamaño del bloque: ";
      std::cin >> block_size;

      if (std::cin.fail() || block_size <= 0) {
        std::cout << "\t[!] La entrada debe ser un número positivo.\n";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
      } else {
        validInput_block_size = true;
      }
    } while (!validInput_block_size);

    bool valid_input_expl = false;
    while (!valid_input_expl) {
      std::cout << "\n¿Qué función de exploración va a utilizar? \n";
      std::cout << "[ 1 ] Lineal \n";
      std::cout << "[ 2 ] Cuadrática \n";
      std::cout << "[ 3 ] Doble Dispersión \n";
      std::cout << "[ 4 ] Redispersión \n";
      std::cout << "-> Introduzca la función de exploración [1|2|3|4]: ";
      std::cin >> fe_option;

      if (std::cin.fail()) {
        std::cout << "\t[!] La entrada debe ser un número. Introduzca [1|2|3|4]].\n";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
      } else if (fe_option == 1 || fe_option == 2 || fe_option == 3 || fe_option == 4) {
        switch (fe_option) {
          case 1:
            fe = new feLineal<long>();
            std::cout << "\n=> Se ha seleccionado la función de exploración [Lineal]\n"<< std::endl;
            break;
          case 2:
            fe = new feQuadratic<long>();
            std::cout << "\n=> Se ha seleccionado la función de exploración [Cuadrática]\n"<< std::endl;
            break;
          case 3:
            fe = new feDoubleDispersion<long>(*fd);
            std::cout << "\n=> Se ha seleccionado la función de exploración [Doble Dispersión]\n" << std::endl;
            break;
          case 4:
            fe = new feReDispersion<long>();
            std::cout << "\n=> Se ha seleccionado la función de exploración [Redispersión]\n" << std::endl;
            break;
          default:
            std::cerr << "[!] Función de dispersión no válida. Introduzca [1|2|3|4]" << std::endl;
            return (EXIT_FAILURE);
            break;
        }
        valid_input_expl = true;
      } else {
        std::cout << "\t[!] Función de exploración no válida. Introduzca [1|2|3|4].\n";
      }
    }
  }
  HashTable<long> table(size, fd, fe, block_size);

  bool valid_input_menu = false;
  int menu_option{-1};
  while (!valid_input_menu) {
    while (menu_option != 0) {
      std::cout << "Tamaño de la tabla: [" << size << "]" << std::endl;
      std::cout << "[ 0 ] Salir" << std::endl;
      std::cout << "[ 1 ] Insertar" << std::endl;
      std::cout << "[ 2 ] Buscar" << std::endl;
      std::cout << "[ 3 ] Mostrar Tabla" << std::endl;
      std::cout << "-> Introduzca una opción: ";
      std::cin >> menu_option;
      long dni;

      if (std::cin.fail()) {
        std::cout << "\t[!] La entrada debe ser un número. Introduzca [0|1|2|3].\n";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        valid_input_menu = false;
        menu_option = -1;
      } else if (menu_option == 0 || menu_option == 1 || menu_option == 2 || menu_option == 3) {
        switch (menu_option) {
          case 0:
            std::cout << "\nPrograma finalizado." << std::endl;
            break;
          case 1:
            do {
              std::cout << "\nIntroduzca la clave a [insertar]: ";
              std::cin >> dni;
              if (std::cin.fail()) {
                std::cout << "\t[!] La entrada debe ser un número positivo.\n";
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
              } else if (dni <= 0) {
                std::cout << "\t[!] La entrada debe ser un número positivo." << std::endl;
              }
            } while (dni <= 0);
            std::cout << "\n=> La clave (" << dni << ")" << (table.insert(dni) ? " se ha insertado correctamente!" : " NO se ha insertado") << std::endl;
            std::cin.ignore();  // Ignorar el carácter de nueva línea en el buffer
            break;
          case 2:
            do {
              std::cout << "\nIntroduzca la clave a [buscar]: ";
              std::cin >> dni;
              if (std::cin.fail()) {
                std::cout << "\t[!] La entrada debe ser un número positivo.\n";
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
              } else if (dni <= 0) {
                std::cout << "\t[!] La entrada debe ser un número positivo." << std::endl;
              }
            } while (dni <= 0);
            std::cout << "\n=> La clave (" << dni << ")" << (table.search(dni) ? " se ha encontrado!" : " NO se ha encontrado") << std::endl;
            std::cin.ignore();  // Ignorar el carácter de nueva línea en el buffer
            break;
          case 3:
            table.print();
            break;
          default:
            std::cout << "\t[!] Opción no válida. Introduzca [0|1|2|3]).\n" << std::endl;
            valid_input_menu = false;  // opción inválida, se mantiene el ciclo
            break;
        }
        if (menu_option != 0) {
          valid_input_menu = true;
          std::cout << std::endl;
        }
      } else {
        std::cout << "\t[!] Opción no válida. Introduzca [0|1|2|3].\n\n";
        valid_input_menu = false;
      }
    }
  }
  return EXIT_SUCCESS;
}
void Menu(int argc, char* argv[]) {
  switch (argc) {
    case 1:
      std::cout << "José Javier Díaz González\n";
      std::cout << "Práctica 4: Búsqueda por dispersión\n";
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