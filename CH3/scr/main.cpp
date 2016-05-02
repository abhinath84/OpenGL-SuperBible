/*
 * main.cpp
 *
 *  Created on: 20-Mar-2016
 *      Author: abhi
 */

#include <iostream>
#include <math.h>
#include "triangle.h"
#include "Lines.h"

using namespace std;


int main(int argc, char **argv)
{
  /// Lines related examples
  /*GLWidget *lines = new Lines(100, 50, 800, 600, "Lines related Example");
  lines->setDisplayModeGL(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
  lines->mainloopGL(argc, argv);*/

  /// Triangle Culling Example
  GLWidget *triangle_ptr = new Triangle(100, 50, 800, 600, "Triangle Culling Example");
  triangle_ptr->setDisplayModeGL(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
  triangle_ptr->mainloopGL(argc, argv);

  return(0);
}
