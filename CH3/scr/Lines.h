/*
 * Lines.h
 *
 *  Created on: 03-May-2016
 *      Author: abhi
 */

#ifndef LINES_H_
#define LINES_H_

#include <math.h>
#include <glwidget.h>

// Define a constant for the value of PI
#define GL_PI 3.1415f


class Lines: public GLWidget
{
public:
  Lines();
  Lines(int win_x, int win_y, int win_w, int win_h, const string &win_title);
  ~Lines();

  virtual void initializeGL();
  virtual void displayGL();
  virtual void reshapeGL(int w, int h);

private:
  void drawSpiral_3D();
  void drawLines_3D();
  void drawLineStripLoop_3D();
};

#endif /* LINES_H_ */
