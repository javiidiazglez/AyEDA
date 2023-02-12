//////////////////////////////////////////////////////////////////////////////////
// Universidad de La Laguna                                                     //
// Escuela Superior de Ingeniería y Tecnología                                  //
// Grado en Ingeniería Informática                                              //
// Algoritmos y Estructuras de datos Avanzados                                  //
// Fecha: 16/04/2021                                                            //
// Autor: José Javier Díaz González (alu0101128894)                             //
//                                                                              //
// Práctica 7. Tabla Hash con dispersión cerrada                                //
// Referencias: https://es.wikipedia.org/wiki/Tabla_hash                        //
// Nombre del archivo: main.cc                                                  //
//////////////////////////////////////////////////////////////////////////////////

#include <functional>
#include <iostream>
#include <map>
#include <string>

#include "../include/dispersion_module.h"
#include "../include/dispersion_pseudorandom.h"
#include "../include/exploration_double.h"
#include "../include/exploration_lineal.h"
#include "../include/exploration_quadratic.h"
#include "../include/exploration_redispersion.h"
#include "../include/hash_table_closed.h"

#include "../include/test.h"

size_t table_size;
Dispersion<int>* GetDispersionFunction(const std::string& dispersion_string);
Exploration<int>* GetExplorationFunction(const std::string& exploration_string);

int main() {
  // std::string mode, aux;
  // size_t limit;
  // std::cout << "Inserte el tamaño de la tabla: ";
  // std::cin >> table_size;
  // std::cout << "Inserte el tamaño de los elementos de las claves: ";
  // std::cin >> limit;
  // std::cout << "Función de dispersión: \"MODULO\" | \"ALEATORIA\": ";
  // std::cin >> mode;
  // std::cout << "Función de dispersión: \"LINEAL\" | \"DOBLE\" | \"CUADRATICA\" | \"REDISPERSION\": ";
  // std::cin >> aux;
  // HashTableClosed<int> table(table_size, limit, GetDispersionFunction(mode), GetExplorationFunction(aux));

  // while (true) {
  //   std::cout << "Inserte operación \"INSERTAR\" | \"BUSCAR\" | \"SALIR\": ";
  //   std::cin >> mode;
  //   if (mode == "INSERTAR") {
  //     std::cout << "Escriba el elemento a insertar: ";
  //     std::cin >> mode;
  //     table.Insert(stoi(mode));
  //     std::cout << table << std::endl;
  //   } else if (mode == "BUSCAR") {
  //     std::cout << "Escriba el elemento a buscar: ";
  //     std::cin >> mode;
  //     std::cout << (table.Search(stoi(mode)) ? "El elemento fue encontrado" : "El elemento no fue encontrado");
  //     std::cout << std::endl;
  //   } else {
  //     break;
  //   }
  // }

  Test test1(5, 2, 10);
  test1.Run();

}

Dispersion<int>* GetDispersionFunction(const std::string& dispersion_string) {
  static std::map<std::string, std::function<Dispersion<int>*(void)>> callback_map = {
      {"MODULO", []() -> Dispersion<int>* { return new DispersionModule<int>(table_size); }},
      {"ALEATORIA", []() -> Dispersion<int>* { return new DispersionPsudorandom<int>(table_size); }}};
  auto it = callback_map.find(dispersion_string);
  if (it == callback_map.end()) {
    std::cerr << "Función de dispersión erronea\n";   
    exit(1);
  }
  return callback_map[dispersion_string]();
}

Exploration<int>* GetExplorationFunction(const std::string& exploration_string) {
  static std::map<std::string, std::function<Exploration<int>*(void)>> callback_map = {
      {"LINEAL", []() -> Exploration<int>* { return new ExplorationLineal<int>(table_size); }},
      {"DOBLE", []() -> Exploration<int>* { return new ExplorationDouble<int>(table_size); }},
      {"CUADRATICA", []() -> Exploration<int>* { return new ExplorationQuadratic<int>(table_size); }},
      {"REDISPERSION", []() -> Exploration<int>* { return new ExplorationRedispersion<int>(table_size); }}};
  auto it = callback_map.find(exploration_string);
  if (it == callback_map.end()) {
    std::cerr << "Función de exploración erronea\n";
    exit(1);
  }
  return callback_map[exploration_string]();
}
