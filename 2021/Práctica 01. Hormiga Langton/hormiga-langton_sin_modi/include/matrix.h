// UNIVERSIDAD DE LA LAGUNA
// GRADO EN INGENIERIA INFORMATICA
// AUTOR: José Javier Díaz González
// FECHA: 04-03-2021
// E-MAIL: alu0101128894@ull.edu.es
// ASIGNATURA: Algoritmos y Estructras de datos Avanzados
// PRACTICA: P01 - Hormiga Laghton
// Referencias: https://es.wikipedia.org/wiki/Hormiga_de_Langton
// Nombre del archivo: matrix.h

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
  size_t Rows() const;    // conseguir filas 

  void Fill(Type fill_value); // para rellenarlo
  Matrix<Type> Transpose();

  // Sobrecarga de operadores
  const Type& At(size_t row, size_t column) const;
  Type& At(size_t row, size_t column);
  void operator=(const Matrix& matrix); // igualar
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
void Matrix<Type>::Build(size_t rows, size_t columns) {
  rows_ = rows;
  columns_ = columns;
  matrix_.Resize(rows);
  for (size_t i = 0; i < matrix_.Size(); ++i) {
    matrix_[i].Resize(columns);
  }
}

template <typename Type>
size_t Matrix<Type>::Columns() const {    // Columnas
  return columns_;
}

template <typename Type>  
size_t Matrix<Type>::Rows() const {   // Filas
  return rows_;   
}

template <typename Type>
void Matrix<Type>::Fill(Type fill_value) {
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
Type& Matrix<Type>::At(size_t row, size_t column) {   // at
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
