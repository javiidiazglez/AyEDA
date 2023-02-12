//////////////////////////////////////////////////////////////////////////////////
// Universidad de La Laguna                                                     //
// Escuela Superior de Ingeniería y Tecnología                                  //
// Grado en Ingeniería Informática                                              //
// Algoritmos y Estructuras de datos Avanzados                                  //
// Fecha: 07/04/2021                                                            //
// Autor: José Javier Díaz González (alu0101128894)                             //
//                                                                              //
// Práctica 5. Tabla Hash con dispersión abierta                                //
// Referencias: https://es.wikipedia.org/wiki/Tabla_hash                        //
// Nombre del archivo: main.cc                                                  //
//////////////////////////////////////////////////////////////////////////////////

#include <functional>
#include <iostream>
#include <map>
#include <string>

#include "../include/dispersion_module.h"
#include "../include/dispersion_pseudorandom.h"
#include "../include/hash_table.h"

size_t table_size;
Dispersion<int>* GetDispersionFunction(const std::string& dispersion_string); // funcion de dispersión

int main() {
  std::string mode;
  std::cout << "Inserte el tamaño de la tabla: ";
  std::cin >> table_size;
  std::cout << "Función de dispersión: [ \"MODULO\" | \"PSALEATORIA\" ]: ";
  std::cin >> mode;
  HashTable<int> table(table_size, GetDispersionFunction(mode)); // tabla = size, modo (parceador)(puntero especifico)

  while (true) {
    std::cout << "Inserte operación: [ \"INSERTAR\" | \"BUSCAR\" | \"SALIR\" ] : ";
    std::cin >> mode;
    if (mode == "INSERTAR") {
      std::cout << "Escriba el elemento a insertar: ";
      std::cin >> mode;
      table.Insert(stoi(mode)); // tabla inserto string->numero (modo)
      std::cout << table << std::endl;
    } else if (mode == "BUSCAR") {
      std::cout << "Escriba el elemento a buscar: ";
      std::cin >> mode;
      std::cout << (table.Search(stoi(mode)) ? "-> El elemento fue encontrado" : "-> El elemento no fue encontrado");
      std::cout << std::endl;
    } else {
        std::cerr << "Se ha salido correctamente\n";
        exit(1);
    }
  }
}

//Declaracion de Dispersiones
Dispersion<int>* GetDispersionFunction(const std::string& dispersion_string) {
  static std::map<std::string, std::function<Dispersion<int>*(void)>> callbakc_map = {
      { "MODULO", []() -> Dispersion<int>* { return new DispersionModule<int>(table_size); } },       // new
      { "PSALEATORIA", []() -> Dispersion<int>* { return new DispersionPsudorandom<int>(table_size); } } //
  };
  auto it = callbakc_map.find(dispersion_string);   // busca
  if (it == callbakc_map.end()) { // si it llega al final -> no encontró
    std::cerr << "\n-> Modo erróneo, abortando...!\n\n";
    exit(1);
  }
  return callbakc_map[dispersion_string](); // encontrado -> mapa (modulo o aleatorio (tabla_size) )
}

//static std::map<std::string, std::function<Dispersion<int>*(void)>>::iterator -> auto
