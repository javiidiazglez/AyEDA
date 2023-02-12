#include <cstring>
#include <fstream>
#include <iostream>
#include <stdlib.h>

#include "ab.h"
#include "avl.h"
#include "abb.h"
#include "abe.h"
#include "dummy.cc"

void error (int &opc);
int instrucciones(std::string path);
void Menu();
bool ReadInput(Ab<int> *tree);
void InsertOption(Ab<int> *tree);
void RemoveOptions(Ab<int> *tree);
void FindOption(Ab<int> *tree);

void error (int &opc){
	while (std::cin.fail()){
		std::cin.clear();
		std::cin.ignore(99, '\n');
		std::cout << "\033[0;31m" << "\n   ➔  Error. ";
    std::cout << "\033[37m" << "Introduzca una Clave válida: ";
		std::cin >> opc;
	}
}

int instrucciones(std::string path) {
  std::ifstream instFile(path, std::ios::in);
  if (!instFile.is_open()) {
    std::cout << "\033[0;31m" << "\nError al cargar instrucciones!" << "\033[0m" << std::endl;
    return 1;
  }
  std::cout << instFile.rdbuf() << std::endl;
  return 0;
}

unsigned Dummy::counter;

int main(int argc, char *argv[]) {
  // if (argc == 2 && strcmp(argv[1], "TRAZA") == 0) {
  //   std::cout << "\033[36m" << "\nModo TRAZA activada!" << "\033[0m" << std::endl;
  //   trace = true;
  // } else if (argc == 1) {
  //   trace = false;
  //   std::cout << "\033[36m" << "\nModo SIN TRAZA activada!" << "\033[0m" << std::endl;
  // } else {
  //   instrucciones("instrucciones.txt");
  //   return 0;
  // }

  // Ab<int> *tree = new Avl<int>();
  // Ab<int> *tree2 = new Abe<int>();
  // Ab<int> *tree3 = new Abb<int>();

  Abe<Dummy> abe;
  Abb<Dummy> abb;
  Avl<Dummy> avl;

  for(int i = 0; i < 1000; i++) {
    int opcion = rand() % (1000 - 0 + 1) + 1000;

    abe.Insert(opcion);
    abb.Insert(opcion);
    avl.Insert(opcion);
  }

  for(int i = 0; i < 50; i++) {
    int opcion = rand() % (1000 - 0 + 1) + 1000;
    Dummy::counter = 0;

    abe.Find(opcion)
    std::cout << Dummy::counter << std::endl;
  }


  // tree->Find<Key> avl;
  // do {
  //   Menu();
  //   std::cout << std::endl;
  // } while (ReadInput(tree));
}

// void Menu() {
//   std::cout << "\033[33m" << "\n[0] Salir" << "\033[0m" << std::endl;
//   std::cout << "\033[33m" << "[1] Insertar Clave" << "\033[0m" << std::endl;
//   std::cout << "\033[33m" << "[2] Buscar Clave" << "\033[0m" << std::endl;
//   std::cout << "\033[33m" << "[3] Mostrar Árbol" << "\033[0m" << std::endl;
//   std::cout << "\033[33m" << "[4] Mostrar Árbol InOrden" << "\033[0m" << std::endl;
//   std::cout << "\033[33m" << "[5] Eliminar Clave" << "\033[0m" << std::endl;
// }

// void InsertOption(Ab<int> *tree) {
//   std::cout << "\n➔  Introduzca una Clave: ";
//   int clave;
//   std::cin >> clave;
//   error(clave);
//   if (tree->Insert(clave)) {
//     std::cout << "\033[0;32m" << "\nLa Clave '" << clave << "' ha sido insertada correctamente!" << "\033[0m" << std::endl;
//   } else {
//     std::cout << "\033[0;31m" << "\nError: Clave '" << clave << "' ya existente!" << "\033[0m" << std::endl;
//   }
// }

// void FindOption(Ab<int> *tree) {
//   std::cout << "\n➔  Introduzca una Clave: ";
//   int clave2;
//   std::cin >> clave2;
//   error(clave2);
//   if (tree->Find(clave2)) {
//     std::cout << "\033[0;32m" << "\nLa Clave '" << clave2 << "' ha sido encontrada!" << "\033[0m" << std::endl;
//   } else {
//     std::cout << "\033[0;31m" << "\nError: La Clave '" << clave2 << "' no ha sido encontrada!" << "\033[0m" << std::endl;
//   }
// }

// void RemoveOptions(Ab<int> *tree) {
//   std::cout << "\n➔  Introduzca una Clave: ";
//   int clave;
//   std::cin >> clave;
//   error(clave);
//   if (tree->Remove(clave)) {
//     std::cout << "\033[0;32m" << "\nLa Clave '" << clave << "' ha sido eliminada correctamente!" << "\033[0m" << std::endl;
//   } else {
//     std::cout << "\033[0;31m" << "\nError: La Clave '" << clave << "' no ha sido encontrada!" << "\033[0m" << std::endl;
//   }
// }

// bool ReadInput(Ab<int> *tree) {
//   int opcion;
//   std::cout << "Introduzca una opción: ";
//   std::cin >> opcion;
//   error(opcion);
//   switch (opcion) {
//     case 0:
//       std::cout << "\nSaliendo correctamente..." << std::endl;
//       return false;
//     case 1:
//       InsertOption(tree);
//       break;
//     case 2:
//       FindOption(tree);
//       break;
//     case 3:
//       tree->Print();
//       std::cout << std::endl;
//       break;
//     case 4:
//       std::cout << std::endl;
//       std::cout << "➔  El Árbol InOrden es: ";
//       tree->PrintInorder();
//       std::cout << std::endl;
//       break;
//     case 5:
//       RemoveOptions(tree);
//       break;
//       break;
//   }
//   return true;
// }