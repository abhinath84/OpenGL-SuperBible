/*
 * color.h
 *
 *  Created on: 26-Mar-2016
 *      Author: abhi
 */

#ifndef COLOR_H_
#define COLOR_H_

#include <iostream>
#include <math.h>

#if defined(_WIN64) || defined(_WIN32)
  #include <freeglut.h>
#elif __linux
  #include <GL/glut.h>
#endif

using namespace std;

template<class T>
class Color {
public:
  // default ctor (0,0,0,0)
  Color()
  :r(0),
   g(0),
   b(0),
   a(1)
  {
  }

  Color(T r, T g, T b)
  :r(r),
   g(g),
   b(b),
   a(1)
  {
  }

  Color(T r, T g, T b, T a)
  :r(r),
   g(g),
   b(b),
   a(a)
  {
  }

  Color(const Color &other)
  {
    r = other.r;
    g = other.g;
    b = other.b;
    a = other.a;
  }

  ~Color()
  {
  }

  Color& operator=(const Color &other)
  {
    if(this != &other)
    {
      r = other.r;
      g = other.g;
      b = other.b;
      a = other.a;
    }

    return(*this);
  }

  bool operator==(const Color &other) const
  {
    bool state = false;

    if((r == other.r) && (g == other.g) && (b == other.b) && (a == other.a))
      state = true;

    return(state);
  }

  bool operator!=(const Color &other) const
  {
    return( !(*this == other));
  }

public:
  T r;
  T g;
  T b;
  T a;
};

#endif /* COLOR_H_ */
