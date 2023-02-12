// UNIVERSIDAD DE LA LAGUNA
// GRADO EN INGENIERIA INFORMATICA
// AUTOR: José Javier Díaz González
// FECHA: 04-03-2021
// E-MAIL: alu0101128894@ull.edu.es
// ASIGNATURA: Algoritmos y Estructras de datos Avanzados
// PRACTICA: P01 - Hormiga Laghton
// Referencias: https://es.wikipedia.org/wiki/Hormiga_de_Langton
// Nombre del archivo: vector.h

#ifndef VECTOR2_H
#define VECTOR2_H

#include <stdlib.h>

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

  void PushBack(Type value); 
  void Resize(size_t new_size);
  size_t Size() const;

  void Fill(Type fill_value); // completar  
  Type& At(size_t index);     // aquí
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
void Vector<Type>::PushBack(Type value) {
  Resize(size_ + 1);
  vector_[size_ - 1] = value;
}

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
