// UNIVERSIDAD DE LA LAGUNA
// GRADO EN INGENIERIA INFORMATICA
// AUTOR: José Javier Díaz González
// FECHA: 10-03-2021
// E-MAIL: alu0101128894@ull.edu.es
// ASIGNATURA: Algoritmos y Estructras de datos Avanzados
// PRACTICA: P02 - Hormiga Laghton Modificada
// Referencias: https://es.wikipedia.org/wiki/Hormiga_de_Langton
// Nombre del archivo: point2d.h

#ifndef POINT2D_H
#define POINT2D_H

template <typename Type>
class Point2d {
  public:
    Point2d();
    Point2d(Type x, Type y);
    Point2d(const Point2d<Type>& point);

    Point2d<Type> operator+(const Point2d<Type>& point_b); // sumar entre puntos
    Point2d<Type> operator-(const Point2d<Type>& point_b); // restar entre puntos

    void operator=(const Point2d<Type>& point); // igualar
  public:
    Type x;
    Type y;
};

typedef Point2d<int> Point2di;    // int
typedef Point2d<float> Point2df;  // float

template <typename Type>
Point2d<Type>::Point2d() {  // Type
  x = 0;
  y = 0;
}

template <typename Type>
Point2d<Type>::Point2d(Type x, Type y) {  // x e y
  this->x = x;
  this->y = y;
}
template <typename Type>
Point2d<Type>::Point2d(const Point2d<Type>& point) { // Punto 2d
  *this = point;
}

template <typename Type>
void Point2d<Type>::operator=(const Point2d<Type>& point) {  // Igualar
  x = point.x;
  y = point.y;
}

template <typename Type>
Point2d<Type> Point2d<Type>::operator+(const Point2d<Type>& point_b) { // sumar
  Point2d<Type> result;
  result.x = x + point_b.x;
  result.y = y + point_b.y;
  return result;
}

template <typename Type>
Point2d<Type> Point2d<Type>::operator-(const Point2d<Type>& point_b) {  // restar
  Point2d<Type> result;
  result.x = x - point_b.x;
  result.y = y - point_b.y;
  return result;
}

#endif
