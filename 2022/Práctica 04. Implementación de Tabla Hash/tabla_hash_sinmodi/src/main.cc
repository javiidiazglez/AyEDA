/*
  Universidad de La Laguna
  Escuela Superior de Ingeniería y Tecnología
  Grado en Ingeniería Informática          
  Algoritmos y Estructuras de datos Avanzados
  Fecha: 08/04/2022     
  Autor: José Javier Díaz González (alu0101128894)
  Práctica 4. Tabla Hash                            
  Referencias: https://es.wikipedia.org/wiki/Tabla_hash
  Nombre del archivo: main.cc                  
*/

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
#include "../include/hash_table_open.h"


size_t table_size;
Dispersion<int>* GetDispersionFunction(const std::string& dispersion_string);    // funcion de dispersión
Exploration<int>* GetExplorationFunction(const std::string& exploration_string); // funcion de exploración

int main() {
  std::string mode, mode_exploracion;
  size_t limit;
  std::cout << "Inserte el tamaño de la tabla: ";
  std::cin >> table_size;
  std::cout << "Inserte el tamaño de los elementos de las claves: ";
  std::cin >> limit;
  std::cout << "\nFunción de dispersión: \"MODULO\" | \"ALEATORIA\": ";
  std::cin >> mode;
  std::cout << "Función de exploración: \"LINEAL\" | \"DOBLE\" | \"CUADRATICA\" | \"REDISPERSION\": ";
  std::cin >> mode_exploracion;                                                                                         // Get = (parceador)(puntero especifico)
  
  HashTableClosed<int> table_closed(table_size, limit, GetDispersionFunction(mode), GetExplorationFunction(mode_exploracion)); // tabla = (size, limite, dispersion, exploracion)  
  HashTableOpen<int> table_open(table_size, GetDispersionFunction(mode)); 

  std::string type_table;

  std::cout << "\nInserte tipo de Tabla HASH: \"ABIERTA\" | \"CERRADA\": ";
  std::cin >> type_table;

  while (true) {
    if (type_table == "ABIERTA") {
      std::cout << "Inserte operación: \"INSERTAR\" | \"BUSCAR\" | \"SALIR\": ";
      std::cin >> mode;
      if (mode == "INSERTAR") {
        std::cout << "\n- Escriba el elemento a insertar: ";
        std::cin >> mode;
        table_open.Insert(stoi(mode));   // tabla entero, inserto string -> numero (modo)
        std::cout << table_open << std::endl;
      } else if (mode == "BUSCAR") {
        std::cout << "\n- Escriba el elemento a buscar: ";
        std::cin >> mode;
        std::cout << (table_open.Search(stoi(mode)) ? "\n-> El elemento fue encontrado" : "\n-> El elemento no fue encontrado");
        std::cout << std::endl;
      } else {
        std::cerr << "\n-> Se ha salido correctamente\n";
        exit(1);
      }

    } else if (type_table == "CERRADA") {
      std::cout << "\nInserte operación: \"INSERTAR\" | \"BUSCAR\" | \"SALIR\": ";
      std::cin >> mode;
      if (mode == "INSERTAR") {
        std::cout << "\n- Escriba el elemento a insertar: ";
        std::cin >> mode;
        table_closed.Insert(stoi(mode));   // tabla entero, inserto string -> numero (modo)
        std::cout << table_closed << std::endl;
      } else if (mode == "BUSCAR") {
        std::cout << "\n- Escriba el elemento a buscar: ";
        std::cin >> mode;
        std::cout << (table_closed.Search(stoi(mode)) ? "\n-> El elemento fue encontrado" : "\n-> El elemento no fue encontrado");
        std::cout << std::endl;
      } else {
        std::cerr << "\n-> Se ha salido correctamente\n";
        exit(1);
      }
    }
  }
}

//Declaracion de Dispersion
Dispersion<int>* GetDispersionFunction(const std::string& dispersion_string) { // Dispersión entero
  static std::map<std::string, std::function<Dispersion<int>*(void)>> callback_map = { // map = Clave: valor
      {"MODULO", []() -> Dispersion<int>* { return new DispersionModule<int>(table_size); }}, // funciones a cada uno (MODULO)
      {"ALEATORIA", []() -> Dispersion<int>* { return new DispersionPsudorandom<int>(table_size); }}};

  auto it = callback_map.find(dispersion_string); // string = tipo string
  if (it == callback_map.end()) {
    std::cerr << "Función de dispersión erronea\n";
    exit(1);
  }
  return callback_map[dispersion_string]();// encontrado -> mapa (modulo o aleatorio (tabla_size) )
}

//Declaracion de Exploración
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