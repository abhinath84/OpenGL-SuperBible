/*
 * point.h
 *
 *  Created on: 26-Mar-2016
 *      Author: abhi
 */

#ifndef POINT_H_
#define POINT_H_

#include <iostream>
#include <math.h>

#if defined(_WIN64) || defined(_WIN32)
  #include <freeglut.h>
#elif __linux
  #include <GL/glut.h>
#endif

using namespace std;

template<class T>
class Point
{
public:
  // Default constructor (0,0,0,1)
  Point();
  // Default constructor (x,y,0,1)
  Point(T x, T y);
  // Default constructor (x,y,z,1)
  Point(T x, T y, T z);
  // Create a point at (x,y,z,w)
  Point(T x, T y, T z, T w);
  // Copy ctor
  Point(const Point &other);
  ~Point();

  // Assigment operator
  Point& operator=(const Point &other);

  bool operator==(const Point &other) const;
  bool operator!=(const Point &other) const;

  /* Calculate the distance between the current point to
   * the given point.
   */
  T distance(const Point &other) const;

  /* Transform the point by the given matrix (homogenous)*/
  void transform(T matrix[3][3]);

  /* Set point to a new location (x,y,z,w). */
  void setPoint(T x, T y, T z, T w);

  /**
   * Display a point
   */
  friend std::ostream & operator<<(std::ostream &os, const Point &point)
  {
    return os << "Point: (" << point.x  << ", " << point.y << ", " << point.z << ", " << point.w << ")";
  }

public:
  T x;
  T y;
  T z;
  T w;
};

template <class T>
Point<T>::Point()
:x(0),
 y(0),
 z(0),
 w(1)
{
}

template <class T>
Point<T>::Point(T x, T y)
:x(x),
 y(y),
 z(0),
 w(1)
{
}

template <class T>
Point<T>::Point(T x, T y, T z)
:x(x),
 y(y),
 z(z),
 w(1)
{
}

template <class T>
Point<T>::Point(T x, T y, T z, T w)
:x(x),
 y(y),
 z(z),
 w(w)
{
}

template <class T>
Point<T>::Point(const Point<T> &other)
:x(other.x),
 y(other.y),
 z(other.z),
 w(other.w)
{
}

template <class T>
Point<T>::~Point()
{
}

template <class T>
Point<T>& Point<T>::operator=(const Point<T> &other)
{
  if(this != &other)
  {
    x = other.x;
    y = other.y;
    z = other.z;
    w = other.w;
  }

  return(*this);
}

template <class T>
T Point<T>::distance(const Point<T> &other) const
{
  return( sqrt((other.x - x)*(other.x - x) +
                (other.y - y)*(other.y - y) +
                (other.z - z)*(other.z - z)
              )
        );
}
template <class T>
void Point<T>::transform(T matrix[3][3])
{
  T value[] = { 0, 0, 0};

  // Matrix multiplication
  value[0] = matrix[0][0] * x + matrix[0][1] * y + matrix[0][2] * z + matrix[0][3] * w;
  value[1] = matrix[1][0] * x + matrix[1][1] * y + matrix[1][2] * z + matrix[1][3] * w;
  value[2] = matrix[2][0] * x + matrix[2][1] * y + matrix[2][2] * z + matrix[2][3] * w;

  x = value[0];
  y = value[1];
  z = value[2];
  w = 1.0;
}

template <class T>
void Point<T>::setPoint(T x, T y, T z, T w)
{
  this->x = x;
  this->y = y;
  this->z = z;
  this->w = w;
}

template <class T>
bool Point<T>::operator==(const Point<T> &other) const
{
  bool state = false;

  if((x == other.x) && (y == other.y) && (z == other.z) && (w == other.w))
    state = true;

  return(state);
}

template <class T>
bool Point<T>::operator!=(const Point<T> &other) const
{
  return( !(*this == other));
}

#endif /* POINT_H_ */
