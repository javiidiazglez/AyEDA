/*
  Universidad de La Laguna
  Escuela Superior de Ingeniería y Tecnología
  Grado en Ingeniería Informática          
  Algoritmos y Estructuras de datos Avanzados
  Fecha: 12/05/2022     
  Autor: José Javier Díaz González (alu0101128894)
  Práctica 6. Implementación de árboles binarios equilibrados                         
  Referencias: https://es.wikipedia.org/wiki/%C3%81rbol_binario
  Nombre del archivo: main.cc                  
*/

#include <iostream>
#include <string>
#include <fstream>
#include "abe.h"

void error (int &opc);
int instrucciones(std::string path);
void Menu();
bool ReadInput(Ab<int> *tree);
void InsertOption(Ab<int> *tree);
void FindOption(Ab<int> *tree);

void error (int &opc){
	while (std::cin.fail()){
		std::cin.clear();
		std::cin.ignore(99, '\n');
		std::cout << "\033[0;31m" << "  -> Error. ";
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
  std::cout << instFile.rdbuf() <<  std::endl;
  return 0;
}

int main(int argc, char* argv[]) {
  if (argc > 1) {
    instrucciones("instrucciones.txt");
    return 0;
  }
  Ab<int> *tree = new Abe<int>(); // abe
  do {
    Menu();
  } while (ReadInput(tree));
}

void Menu() {
  std::cout << "\033[33m" << "\n[0] Salir" << "\033[0m" << std::endl;
  std::cout << "\033[33m" << "[1] Insertar Clave" << "\033[0m" << std::endl;
  std::cout <<"\033[33m" <<  "[2] Buscar Clave" << "\033[0m" << std::endl;
  std::cout << "\033[33m" << "[3] Mostrar Árbol" << "\033[0m" << std::endl;
  std::cout << "\033[33m" << "[4] Mostrar Árbol Inorden" << "\033[0m" << std::endl;
}

void InsertOption(Ab<int> *tree) {
  std::cout << "\n-> Introduzca una Clave: ";
  int clave;
  std::cin >> clave;
  error(clave);
  if (tree->Insert(clave)) {
    std::cout << "\nClave insertada correctamente!" << std::endl;
  } else {
    std::cout << "\033[0;31m" << "\nError: Clave ya existente" << "\033[0m" << std::endl;
  }
}

void FindOption(Ab<int> *tree) {
  std::cout << "\n-> Introduzca una Clave: ";
  int clave2;
  std::cin >> clave2;
  error(clave2);
  if (tree->Find(clave2)) {
    std::cout << "\nClave encontrada!" << std::endl;
  } else {
    std::cout << "\033[0;31m" << "\nError: Clave no encontrada" << "\033[0m" << std::endl;
  }
}

bool ReadInput(Ab<int> *tree) {
  int opcion;
  std::cout << "\nIntroduzca una opción: ";
  std::cin >> opcion;
  error(opcion);
  switch (opcion) {
  case 0:
    std::cout << "\nSaliendo correctamente..." << std::endl;
    return false;
  case 1:
    InsertOption(tree);
    break;
  case 2:
    FindOption(tree);
    break;
  case 3:
    tree->Print();
    std::cout << std::endl;
    break;
  case 4:
    std::cout << std::endl;
    tree->PrintInorder();
    std::cout << std::endl;
    break;
  }
  return true;
}

