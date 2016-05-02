/*
 * triangle.h
 *
 *  Created on: 02-May-2016
 *      Author: abhi
 */

#ifndef TRIANGLE_H_
#define TRIANGLE_H_

#include "glwidget.h"
#include "point.h"
#include "color.h"

// Define a constant for the value of PI
#define GL_PI 3.1415f


class Triangle: public GLWidget
{
public:
  Triangle();
  Triangle(int win_x, int win_y, int win_w, int win_h, const string &win_title);
  ~Triangle();

  virtual void initializeGL();
  virtual void displayGL();
  virtual void reshapeGL(int w, int h);
  virtual void specialGL(int key, int x, int y);
  virtual void createMenuGL(int menu);
  virtual void setupMenu();

private:
  int iCull;
  int iOutline;
  int iDepth;

  GLfloat xRot;
  GLfloat yRot;
};

#endif /* TRIANGLE_H_ */
