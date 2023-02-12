//////////////////////////////////////////////////////////////////////////////////
// Universidad de La Laguna                                                     //
// Escuela Superior de Ingeniería y Tecnología                                  //
// Grado en Ingeniería Informática                                              //
// Algoritmos y Estructuras de datos Avanzados                                  //
// Fecha: 23/05/2021                                                            //
// Autor: José Javier Díaz González (alu0101128894)                             //
//                                                                              //
// Práctica 11. Práctica 11. AVL                                                //
// Referencias: https://es.wikipedia.org/wiki/Arbol_AVL                         //
// Nombre del archivo: main.cc                                                  //
//////////////////////////////////////////////////////////////////////////////////

#include "AVL.h"
#include <iostream>
#include <cstdio>
#include <time.h>
#include <stdlib.h>
#include <fstream>
//using namespace std;

// LLamadas a las funciones auxiliares
void menu();

int main(int argc, char *argv[])
{
   srand(time(NULL));

  AVL<int> *A;
  A = new AVL<int>;
  int opcion;
  int input_val;
  int in;

  do
  {
    menu();
    std::cout << "Seleccione: ";
    cin >> opcion;
    std::cout << std::endl;
    switch (opcion)
    {
    case 1:
    {
      cout << "Insertar: ";
      cin >> input_val;
      in = input_val;
      A->Insertar(in);
      A->Imprimir();
      getchar();
      std::cout << std::endl;
      std::cout << std::endl;
      break;
    }
    case 2:
    {
      cout << "Eliminar:";
      cin >> input_val;
      in = input_val;
      A->Eliminar(in);
      A->Imprimir();
      getchar();
      std::cout << std::endl;
      std::cout << std::endl;
      break;
    }
    case 3:
    {
      std::cout << "Mostrar:"<< std::endl;
      A->Imprimir();
      std::cout << std::endl;
      std::cout << std::endl;
      getchar();
      break;
    }
    case 4:
    {
      A->Cambiarmodo();
      std::cout << std::endl;
      getchar();
      break;
    }
    case 0:
      cout << "Saliendo del programa" << endl;
      break;
    default:
      cout << "Invalid option" << endl;
      break;
    }
  } while (opcion != 0);

  return 0;
}

void menu(void)
{

  cout << "  [0]Salir           " << endl;
  cout << "  [1]Insertar        " << endl;
  cout << "  [2]Eliminar        " << endl;
  cout << "  [3]Mostrar         " << endl;
  cout << "  [4]Activar / Desactivar Modo Traza         " << endl;
}
