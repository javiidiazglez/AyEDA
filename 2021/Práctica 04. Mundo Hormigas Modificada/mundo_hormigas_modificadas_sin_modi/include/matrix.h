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
// Nombre del archivo: matrix.h                                                 //
//////////////////////////////////////////////////////////////////////////////////

#ifndef MATRIX_H
#define MATRIX_H

#include <iostream>

#include "vector.h"

template <typename Type>
class Matrix {
 public:
  Matrix(); // constructor defecto  
  Matrix(size_t rows, size_t columns); // por tamaño
  Matrix(size_t rows, size_t columns, Type fill_value); // por completado
  Matrix(const Matrix& matrix); // constructor copia
  virtual ~Matrix();

  size_t Columns() const; // conseguir columnas
  size_t Rows() const;  // conseguir filas 

  void AddColumnFront(size_t to_add, Type value);   // AddColumnFront
  void AddColumnBack(size_t to_add, Type value);    // AddColumnBck

  void AddRowFront(size_t to_add, Type value);      // AddrowFront
  void AddRowBack(size_t to_add, Type value);       // AddRowBack

  void Fill(Type fill_value);   // para rellenarlo
  Matrix<Type> Transpose();

  // Sobrecarga de operadores
  const Type& At(size_t row, size_t column) const;
  Type& At(size_t row, size_t column);
  void operator=(const Matrix& matrix);   // igualar
  Vector<Type>& operator[](size_t index);
  const Vector<Type>& operator[](size_t index) const;

 protected: 
  Vector<Vector<Type>> matrix_; // vector de vector de tipos de datos (vectores = filas | columnas = posiciones del vector)
  size_t rows_;     // filas
  size_t columns_;  // columnas

  void Build(size_t rows, size_t columns);
};

template <typename Type>
Matrix<Type>::Matrix() {
  rows_ = 0;
  columns_ = 0;
}

template <typename Type>
Matrix<Type>::Matrix(size_t rows, size_t columns) {
  rows_ = 0;
  columns_ = 0;
  Build(rows, columns);
}

template <typename Type>
Matrix<Type>::Matrix(size_t rows, size_t columns, Type fill_value) {
  rows_ = 0;
  columns_ = 0;
  Build(rows, columns);
  Fill(fill_value);
}

template <typename Type>
Matrix<Type>::Matrix(const Matrix& matrix) {
  rows_ = 0;
  columns_ = 0;
  *this = matrix;
}

template <typename Type>
Matrix<Type>::~Matrix() {}

template <typename Type>
void Matrix<Type>::Build(size_t rows, size_t columns) {  // Build
  rows_ = rows;
  columns_ = columns;
  matrix_.Resize(rows);
  for (size_t i = 0; i < matrix_.Size(); ++i) {
    matrix_[i].Resize(columns);
  }
}

template <typename Type>
size_t Matrix<Type>::Columns() const {   // Columnas
  return columns_;
}

template <typename Type>
size_t Matrix<Type>::Rows() const {   // Filas
  return rows_;
}

// Redimensionar mundos
template <typename Type>
void Matrix<Type>::AddColumnFront(size_t to_add, Type value) {    // AddColumnFront  (añade al principio de la fila)
  for (size_t i = 0; i < rows_; ++i) { 
    for (size_t j = 0; j < to_add; ++j) {
      matrix_[i].PushFront(value);   //PushFront
    }
  }
  columns_ += to_add;
}

template <typename Type>
void Matrix<Type>::AddColumnBack(size_t to_add, Type value) {   // AddColumnBack (añade al final de la columna)
  for (size_t i = 0; i < rows_; ++i) {
    for (size_t j = 0; j < to_add; ++j) {
      matrix_[i].PushBack(value); // PushBack
    }
  }
  columns_ += to_add;
}

template <typename Type>
void Matrix<Type>::AddRowFront(size_t to_add, Type value) { // AddRowFront    to_add = numero de filas
  Vector<Type> new_row(columns_, value);   // nueva fila, con su tamaño     (por arriba)
  for (size_t i = 0; i < to_add; ++i) {
    matrix_.PushFront(new_row);    // PushFront
  }
  rows_ += to_add;
}

template <typename Type>
void Matrix<Type>::AddRowBack(size_t to_add, Type value) {    // AddRowBack (por abajo)
  Vector<Type> new_row(columns_, value);  // nueva fila
  for (size_t i = 0; i < to_add; ++i) {
    matrix_.PushBack(new_row);  // PushBack
  }
  rows_ += to_add;
}
/*  
    filas = vectores -> ◻◻◻ (pushback de un nuevo vector)
    columas =  posiciones del vector -> ◻ (aumentar +1 el tamaño de los vectores de cada fila)
    pushfront = x     pushback = y
    addrowfront = a   addrowback = b
   
     a
    ◻ -> x◻◻◻
    ◻ -> ◻◻◻y
    b
*/

template <typename Type>
void Matrix<Type>::Fill(Type fill_value) {      // Fill
  for (size_t i = 0; i < matrix_.Size(); ++i) {
    for (size_t j = 0; j < matrix_[i].Size(); ++j) {
      matrix_[i][j] = fill_value;
    }
  }
}

template <typename Type>
Matrix<Type> Matrix<Type>::Transpose() {
  Matrix<Type> transpose(columns_, rows_);
  for (size_t i = 0; i < rows_; ++i) {
    for (size_t j = 0; j < columns_; ++j) {
      transpose[j][i] = matrix_[i][j];
    }
  }
  return transpose;
}

template <typename Type>
Type& Matrix<Type>::At(size_t row, size_t column) {   // At
  assert(row < rows_ && column < columns_);
  return matrix_[row][column];
}

template <typename Type>
const Type& Matrix<Type>::At(size_t row, size_t column) const {
  assert(row < rows_ && column < columns_);
  return matrix_[row][column];
}

template <typename Type>
void Matrix<Type>::operator=(const Matrix& matrix) {    // Igualar
  Build(matrix.Rows(), matrix.Columns());
  for (size_t i = 0; i < rows_; ++i) {
    for (size_t j = 0; j < columns_; ++j) {
      matrix_[i][j] = matrix[i][j];
    }
  }
}

template <typename Type>
Vector<Type>& Matrix<Type>::operator[](size_t index) {    // []
  assert(index < rows_);
  return matrix_[index];
}

template <typename Type>
const Vector<Type>& Matrix<Type>::operator[](size_t index) const {
  assert(index < rows_);
  return matrix_[index];
}

#endif
