//////////////////////////////////////////////////////////////////////////////////
// Universidad de La Laguna                                                     //
// Escuela Superior de Ingeniería y Tecnología                                  //
// Grado en Ingeniería Informática                                              //
// Algoritmos y Estructuras de datos Avanzados                                  //
// Fecha: 24/03/2021                                                            //
// Autor: José Javier Díaz González (alu0101128894)                             //
//                                                                              //
// Práctica 4: Mundo Hormigas Modifcado                                         //
// Referencias: https://es.wikipedia.org/wiki/Hormiga_de_Langton                //
// Nombre del archivo: main.cc                                                  //
//////////////////////////////////////////////////////////////////////////////////

#include <iostream>
#include <cstring>
#include <algorithm>

#include "../include/rule_black.h"
#include "../include/rule_white.h"
#include "../include/universe_finito.h"
#include "../include/universe_infinito.h"

int protectedMain(Universe *universe) {
  int row, col, mode;
  int choice, option;
  int x, y, num, respuesta;
  std::vector<Ant> hormigas;

  std::cout << "Introduzca el numero de filas: ";
  std::cin >> row;
  std::cin.clear();
  std::cin.get();
  std::cout << "Introduzca el numero de columnas: ";
  std::cin >> col;
  std::cin.clear();
  std::cin.get();

  std::cout << "\n- Modo: Finito(0) - Infinito(1): ";
  std::cin >> mode;
  std::cin.clear();
  std::cin.get();
  if (mode == 1)
  {
    universe = new Universe_Infinito(row, col);
  }
  else
  {
    universe = new Universe_Finito(row, col);
  }
  std::cout << " \n- Número de hormigas: ";
  std::cin >> num;
  std::cin.clear();
  std::cin.get();
  hormigas.resize(num);
  std::cout << "\n- ¿Cuántas quieres que sean Hormigas Modificadas?: ";
  std::cin >> option;
  std::cin.clear();
  std::cin.get();
  if (option > num) {
    std::cout << "\nEl número de Hormigas Modificadas no puede ser superior al número de Hormigas introducido." << std::endl;
    return 1;
  }
  for (int i = 0; i < hormigas.size(); i++) {
    if (i < option) {
      hormigas[i].setModifiedAnt(true);
    } else {
      hormigas[i].setModifiedAnt(false);
    }
  }
  
  std::cout << "\n- ¿Desea colocarlas de forma aleatoria NO(0) - SI(1)?: ";
  std::cin >> respuesta;
  std::cout << "\n";
  std::cin.clear();
  std::cin.get();
  for (int i = 0; i < num; i++) {
    if (respuesta) {
      x = rand() % num + 1;
      y = rand() % num + 1;
    }
    else {
      std::cout << "- Posición Hormiga (" << i + 1 << ") en X: ";
      std::cin >> x;
      std::cout << "- Posición Hormiga (" << i + 1 << ") en Y: ";
      std::cin >> y;
      std::cout << "\n";
    }
    hormigas[i].set_pos(x, y); // x e y
    hormigas[i].AddRule(new RuleBlack); //instancias a las clases
    hormigas[i].AddRule(new RuleWhite);
    //universe.SetAnt(hormigas[i]);
  }
  std::sort(hormigas.begin(), hormigas.begin() + num); // ordenar
  universe->SetAnts(hormigas);
  do
  {
    std::cout
        << " 1 - Start the game.\n"
        << " 2 - Listar hormigas.\n"
        << " 3 - Nueva hormiga.\n"
        << " 4 - Salir.\n"
        << "- Introduzca la opción y pulse enter: ";

    std::cin >> choice;
    std::cin.clear();
    std::cin.get();
    switch (choice)
    {
    case 1:
      std::cout << "\n-------1-------" << '\n';
      universe->Run(); // run
      std::cout << "\n";
      break;
    case 2:
      std::cout << "\n-------2-------" << '\n';
      for (int i = 0; i < hormigas.size(); i++)
      {
        std::cout << "Hormiga (" << i << ") " << hormigas[i];
        if (hormigas[i].getModifiedAnt()) {
          std::cout << " -> Soy una Hormiga Modificada." << std::endl;
        } else if (hormigas[i].getModifiedAnt() == false) {
          std::cout << " -> Soy una Hormiga de Langton Normal." << std::endl;
        }
      }
      std::cout << "\n";
      break;
    case 3:
    {
      std::cout << "\n-------3-------" << '\n';
        Ant ant;
        ant.AddRule(new RuleBlack); //instancias a las clases
        ant.AddRule(new RuleWhite);
        universe->SetAnt(ant); // la paso al universo
        universe->Run();
      break;
    }
    case 4:
    {
      std::cout << "\n-------4-------" << '\n';
      std::cout << "Fin del programa.\n";
      break;
    }
    default:
      std::cout << "Introduzca una opcion valida. \n"
                << "Selecciona de nuevo.\n";
      break;
    }
  } while (choice != 4);
  return 0;
}

int main()
{
  Universe *universe;

  try
  {
    return protectedMain(universe);
  }
  // Aquí vienen todas excepciones que capturar y resolver.
  catch(const std::pair<int, int> excepciones)
  {
    int row = std::get<0>(excepciones);
    int col = std::get<1>(excepciones);
    std::cout << row << " y " << col << std::endl;
  }
}
