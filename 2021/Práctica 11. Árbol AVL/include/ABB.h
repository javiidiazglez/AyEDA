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
// Nombre del archivo: ABB.h                                                    //
//////////////////////////////////////////////////////////////////////////////////

#include "nodo.h"
#pragma once
#include <stdio.h>

template <class T>
class ArbolBB
{
  protected:
    nodoAVL<T> *raiz;
    int numerodenodos_;
    std::vector<int> dato;

  public:
    ArbolBB();
    ~ArbolBB();
    void Imprimir(void);
    void contarnodos();
    void cuenta(nodoAVL<T> *nodo);
    std::vector<int> recorridoInorden(nodoAVL<T> *&nodo);
    nodoAVL<T> *Buscar(T clave_dada);
    nodoAVL<T> *BuscarRama(nodoAVL<T> *nodo, T clave_dada);

    //Funciones virtuales->Herencia.
    virtual void Insertar(T clave_dada);
    virtual void InsertarRama(nodoAVL<T> *&nodo, T clave_dada);
    virtual void Eliminar(T clave_dada);
    virtual void EliminarRama(nodoAVL<T> *&nodo, T clave_dada);
    virtual void sustituye(nodoAVL<T> *&eliminado, nodoAVL<T> *&sust);
};

template <class T>
ArbolBB<T>::ArbolBB()
{
  raiz = NULL;
}

template <class T>
ArbolBB<T>::~ArbolBB()
{
}

template <class T>
nodoAVL<T> *ArbolBB<T>::Buscar(T clave_dada)
{
  return BuscarRama(raiz, clave_dada);
}

template <class T>
nodoAVL<T> *ArbolBB<T>::BuscarRama(nodoAVL<T> *nodo, T clave_dada)
{
  if (nodo == NULL)
    return NULL;
  if (clave_dada == nodo->get_clave())
    return nodo;
  if (clave_dada < nodo->get_clave())
    return BuscarRama(nodo->get_izdo(), clave_dada);
  return BuscarRama(nodo->get_dcho(), clave_dada);
}

template <class T>
void ArbolBB<T>::Insertar(T clave_dada)
{
  InsertarRama(raiz, clave_dada);
}

template <class T>
void ArbolBB<T>::InsertarRama(nodoAVL<T> *&nodo, T clave_dada)
{
  if (nodo == NULL)
    nodo = new nodoAVL<T>(clave_dada);
  else if (clave_dada < nodo->get_clave())
    InsertarRama(nodo->get_izdo(), clave_dada);
  else
    InsertarRama(nodo->get_dcho(), clave_dada);
}

template <class T>
void ArbolBB<T>::Eliminar(T clave_dada)
{
  EliminarRama(raiz, clave_dada);
}

template <class T>
void ArbolBB<T>::EliminarRama(nodoAVL<T> *&nodo, T clave_dada)
{
  if (nodo == NULL)
    return;
  if (clave_dada < nodo->get_clave())
    EliminarRama(nodo->get_izdo(), clave_dada);
  else if (clave_dada > nodo->get_clave())
    EliminarRama(nodo->get_dcho(), clave_dada);
  else
  {
    nodoAVL<T> *Eliminado = nodo;
    if (nodo->get_dcho() == NULL)
      nodo = nodo->get_izdo();
    else if (nodo->get_izdo() == NULL)
      nodo = nodo->get_dcho();
    else
      sustituye(Eliminado, nodo->get_izdo());
    delete Eliminado;
  }
}

template <class T>
void ArbolBB<T>::contarnodos()
{
  numerodenodos_ = 0;
  cuenta(raiz);
}

template <class T>
void ArbolBB<T>::cuenta(nodoAVL<T> *nodo)
{
  numerodenodos_++;
  if (nodo->get_izdo() != NULL)
    cuenta(nodo->get_izdo());
  if (nodo->get_dcho() != NULL)
    cuenta(nodo->get_dcho());
}

template <class T>
void ArbolBB<T>::Imprimir()
{

  if (raiz != NULL)
  {
    queue<nodoAVL<T> *> lista;
    lista.push(raiz);
    int j = 0;
    int i = 1;
    int k = 0;
    contarnodos();
    printf("Nivel 0:");
    while (k < numerodenodos_ && !lista.empty())
    {
      if (lista.front() != NULL)
      {
        lista.push(lista.front()->get_izdo());
        lista.push(lista.front()->get_dcho());
      }
      else
      {
        lista.push(NULL);
        lista.push(NULL);
      }
      if (lista.front() != NULL)
      {
        for (int l = 0; l < 2; l++)
          printf(" ");
        printf("[");
        cout << lista.front()->get_clave();
        printf("]");
      }
      else
      {
        for (int l = 0; l < 2; l++)
          printf(" ");
        printf("[.]");
        k--;
      }
      lista.pop();
      if (i == pow(2, j))
      {
        j++;
        printf("\n");
        printf("Nivel %d:", j);
        i = 0;
      }

      i++;
      k++;
    }
  }
  else
  {
    printf("Arbol vacío\n");
    printf("Nivel 0: [.]");
  }
  printf("\n");
}

template <class T>
void ArbolBB<T>::sustituye(nodoAVL<T> *&eliminado, nodoAVL<T> *&sust)
{
  if (sust->get_dcho() != NULL)
    sustituye(eliminado, sust->get_dcho());
  else
  {
    eliminado->set_clave(sust->get_clave());
    eliminado = sust;
    sust = sust->get_izdo();
  }
}

template <class T>
std::vector<int> ArbolBB<T>::recorridoInorden(nodoAVL<T> *&nodo)
{
  if (nodo != NULL)
  {
    recorridoInorden(nodo->get_dcho());
    nodo->imprimir_nodo();
    //dato.push_back(nodo->dato);   //Procesar(nodo->dato)
    recorridoInorden(nodo->get_izdo());
  }
}
