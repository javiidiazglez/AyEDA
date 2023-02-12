//////////////////////////////////////////////////////////////////////////////////
// Universidad de La Laguna                                                     //
// Escuela Superior de Ingeniería y Tecnología                                  //
// Grado en Ingeniería Informática                                              //
// Algoritmos y Estructuras de datos Avanzados                                  //
// Fecha: 17/03/2021                                                            //
// Autor: José Javier Díaz González (alu0101128894)                             //
//                                                                              //
// Práctica 3: Mundo Hormigas                                                   //
// Referencias: https://es.wikipedia.org/wiki/Hormiga_de_Langton                //
// Nombre del archivo: vector.h                                                 //
//////////////////////////////////////////////////////////////////////////////////

#ifndef VECTOR2_H
#define VECTOR2_H

#include <stdlib.h>

#include <vector>
#include <cassert>
#include <iostream>

template <typename Type>
class Vector {
 public:
  Vector();
  Vector(size_t size);
  Vector(size_t size, Type fill_value);
  Vector(const Vector<Type>& vector);
  virtual ~Vector();

  void PushFront(const Type& value);    // PushFront
  void PushBack(const Type& value);     // PushBack
  void Resize(size_t new_size);         // Resize
  size_t Size() const;


  void Fill(Type fill_value);     // completar 
  Type& At(size_t index);         // aquí
  const Type& At(size_t index) const;
  Type& Back();
  const Type& Back() const;

  void operator=(const Vector<Type>& vector);
  Type& operator[](size_t index);
  const Type& operator[](size_t index) const;

 private:
  Type* vector_;
  size_t size_;

 private:
  void Build(size_t size);
  void Free();
};

template <typename Type>
Vector<Type>::Vector() {
  size_ = 0;
  vector_ = NULL;
}

template <typename Type>
Vector<Type>::Vector(size_t size) {
  vector_ = NULL;
  Build(size);
}

template <typename Type>
Vector<Type>::Vector(size_t size, Type fill_value) {
  vector_ = NULL;
  Build(size);
  Fill(fill_value);
}

template <typename Type>
Vector<Type>::Vector(const Vector<Type>& vector) {
  vector_ = NULL;
  size_ = 0;
  *this = vector;
}

template <typename Type>
Vector<Type>::~Vector() {
  Free();
}

template <typename Type>
void Vector<Type>::Build(size_t size) {
  if (vector_ != NULL) {
    Free();
    Build(size);
  } else {
    vector_ = new Type[size];
    size_ = size;
  }
}

template <typename Type>
void Vector<Type>::Resize(size_t new_size) {
  if (vector_ == NULL) {
    Build(new_size);
  } else {
    Vector<Type> old_vec = *this;
    Free();
    Build(new_size);
    for (size_t i = 0; i < old_vec.Size(); ++i) { 
      vector_[i] = old_vec[i];
    } 
  }
}

template <typename Type>
void Vector<Type>::PushBack(const Type& value) {    // PushBack -> lado izquierdo
  Resize(size_ + 1); // redimensiona + 1
  vector_[size_ - 1] = value; // insertas al final -1
}                                          // 0
                                           // *
template <typename Type>    // PushFront -> | 1 2 3 | tam 3  -> pushfront (4) | 4 1 2 3 |   -> lado derecho                       
void Vector<Type>::PushFront(const Type& value) {                                
  Vector<Type> aux = *this; // igualo al aux, vector original, copia  | 1 2 3 |
  Resize(size_ + 1);        // +1                         resize(3+1) | 1 2 3 x |
  vector_[0] = value;       //                     meto el 4 en el 1º | 4 2 3 x | 
  for (size_t i = 1; i < size_; ++i)
    vector_[i] = aux[i - 1]; // desplaza siguiente casilla            | 4 1 2 3 |   i < tam
} //                                                                    0 1 
//                                                                        *
template <typename Type>
void Vector<Type>::Free() {
  if (vector_ == NULL) return;
  delete[] vector_;
  vector_ = NULL;
  size_ = 0;
}

template <typename Type>
void Vector<Type>::Fill(Type fill_value) {
  for (size_t i = 0; i < size_; ++i) {
    vector_[i] = fill_value;
  }
}

template <typename Type>
Type& Vector<Type>::At(size_t index) {
  assert(index < size_);
  return vector_[index];
}

template <typename Type>
const Type& Vector<Type>::At(size_t index) const {
  assert(index < size_);
  return vector_[index];
}

template <typename Type>
Type& Vector<Type>::Back() {
  return vector_[size_ - 1];
}

template <typename Type>
const Type& Vector<Type>::Back() const {
  return vector_[size_ - 1];
}

template <typename Type>
void Vector<Type>::operator=(const Vector<Type>& vector) {
  Free();
  Build(vector.Size());
  for (size_t i = 0; i < vector.Size(); ++i) {
    vector_[i] = vector[i];
  }
}

template <typename Type>
Type& Vector<Type>::operator[](size_t index) {
  return At(index);
}

template <typename Type>
const Type& Vector<Type>::operator[](size_t index) const{
  return At(index);
}

template <typename Type>
size_t Vector<Type>::Size() const {
  return size_;
}

#endif
