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
// Nombre del archivo: nodo.h                                                   //
//////////////////////////////////////////////////////////////////////////////////

#include <iostream>
#include <vector>
#include <queue>
#include <math.h>
#include <iostream>
#pragma once

using namespace std;

template <class T>
class nodoAVL
{
  private:
    int bal_;
    T clave_;
    nodoAVL<T> *izdo;
    nodoAVL<T> *dcho;

  public:
    nodoAVL();
    nodoAVL(T clave);
    ~nodoAVL();
    nodoAVL<T> *&get_izdo();
    nodoAVL<T> *&get_dcho();
    void set_izdo(nodoAVL<T> *izquierdo);
    void set_dcho(nodoAVL<T> *derecho);
    int get_bal();
    void set_bal(int bal);
    T get_clave();
    void set_clave(T clave);
    void imprimir_nodo();
};

//IMPLEMENTACIONES CLASE NODO
template <class T>
nodoAVL<T>::nodoAVL()
{
  bal_ = 0;
  clave_();
  izdo = NULL;
  dcho = NULL;
}

template <class T>
nodoAVL<T>::nodoAVL(T clave)
{
  bal_ = 0;
  clave_ = clave;
  izdo = NULL;
  dcho = NULL;
}

template <class T>
nodoAVL<T>::~nodoAVL()
{
}

template <class T>
nodoAVL<T> *&nodoAVL<T>::get_izdo()
{
  return izdo;
}

template <class T>
nodoAVL<T> *&nodoAVL<T>::get_dcho()
{
  return dcho;
}

template <class T>
void nodoAVL<T>::set_izdo(nodoAVL<T> *izquierdo)
{
  izdo = izquierdo;
}

template <class T>
void nodoAVL<T>::set_dcho(nodoAVL<T> *derecho)
{
  dcho = derecho;
}

template <class T>
int nodoAVL<T>::get_bal()
{
  return bal_;
}

template <class T>
void nodoAVL<T>::set_bal(int bal)
{
  bal_ = bal;
}

template <class T>
T nodoAVL<T>::get_clave()
{
  return clave_;
}

template <class T>
void nodoAVL<T>::set_clave(T clave)
{
  clave_ = clave;
}

template <class T>
void nodoAVL<T>::imprimir_nodo()
{
  cout << clave_ << " ";
  cout.flush();
}
