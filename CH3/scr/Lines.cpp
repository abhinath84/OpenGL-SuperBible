/*
 * Lines.cpp
 *
 *  Created on: 03-May-2016
 *      Author: abhi
 */

#include "Lines.h"

Lines::Lines()
: GLWidget()
{
  // TODO Auto-generated constructor stub

}

Lines::Lines(int win_x, int win_y, int win_w, int win_h, const string &win_title)
: GLWidget(win_x, win_y, win_w, win_h, win_title)
{

}

Lines::~Lines()
{
  // TODO Auto-generated destructor stub
}

void Lines::initializeGL()
{
  // Black background
  glClearColor(0.0f, 0.0f, 0.0f, 1.0f );

  // Set drawing color to green
  glColor3f(0.0f, 1.0f, 0.0f);
}

void Lines::displayGL()
{
  //  Clear the window or more specifically the frame buffer...
  //  This happens by replacing all the contents of the frame
  //  buffer by the clear color
  glClear(GL_DEPTH_BUFFER_BIT | GL_COLOR_BUFFER_BIT | GL_STENCIL_BUFFER_BIT);

  //drawSpiral_3D();
  //drawLines_3D();
  drawLineStripLoop_3D();

  /// swap background buffer.
  glutSwapBuffers();
}

void Lines::reshapeGL(int w, int h)
{
  GLfloat nRange = 100.0f;

  // Prevent a divide by zero
  if(h == 0)
    h = 1;

  // Set Viewport to window dimensions
  glViewport(0, 0, w, h);

  // Reset projection matrix stack
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();

  // Establish clipping volume (left, right, bottom, top, near, far)
  if (w <= h)
    glOrtho (-nRange, nRange, -nRange*h/w, nRange*h/w, -nRange, nRange);
  else
    glOrtho (-nRange*w/h, nRange*w/h, -nRange, nRange, -nRange, nRange);

  // Reset Model view matrix stack
  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();
}

void Lines::drawSpiral_3D()
{
  GLfloat x, y, z, angle; // Storage for coordinates and angles
  GLfloat xRot = 45.0f;
  GLfloat yRot = 45.0f;

  // Save matrix state and do the rotation
  glPushMatrix();
  glRotatef(xRot, 1.0f, 0.0f, 0.0f);
  glRotatef(yRot, 0.0f, 1.0f, 0.0f);

  // Call only once for all remaining points
  glBegin(GL_POINTS);

  z = -50.0f;
  for(angle = 0.0f; angle <= (2.0f*GL_PI)*3.0f; angle += 0.1f)
  {
    x = 50.0f*sin(angle);
    y = 50.0f*cos(angle);

    // Specify the point and move the Z value up a little
    glVertex3f(x, y, z);

    z += 0.5f;
  }

  // Done drawing points
  glEnd();

  // Restore transformations
  glPopMatrix();
}

void Lines::drawLines_3D()
{
  GLfloat x, y, z, angle; // Storage for coordinates and angles
  GLfloat xRot = 45.0f;
  GLfloat yRot = 45.0f;

  // Save matrix state and do the rotation
  glPushMatrix();
  glRotatef(xRot, 1.0f, 0.0f, 0.0f);
  glRotatef(yRot, 0.0f, 1.0f, 0.0f);

  // Call only once for all remaining points
  glBegin(GL_LINES);

  // All lines lie in the xy plane.
  z = 0.0f;
  for(angle = 0.0f; angle <= GL_PI; angle += (GL_PI/20.0f))
  {
    // Top half of the circle
    x = 50.0f*sin(angle);
    y = 50.0f*cos(angle);
    glVertex3f(x, y, z); // First endpoint of line

    // Bottom half of the circle
    x = 50.0f*sin(angle + GL_PI);
    y = 50.0f*cos(angle + GL_PI);
    glVertex3f(x, y, z); // Second endpoint of line
  }

  // Done drawing points
  glEnd();

  // Restore transformations
  glPopMatrix();
}

void Lines::drawLineStripLoop_3D()
{
  GLfloat x, y, z, angle; // Storage for coordinates and angles
  GLfloat xRot = 45.0f;
  GLfloat yRot = 0.0f;

  // Save matrix state and do the rotation
  glPushMatrix();
  glRotatef(xRot, 1.0f, 0.0f, 0.0f);
  glRotatef(yRot, 0.0f, 1.0f, 0.0f);

  // Call only once for all remaining points
  glBegin(GL_LINE_STRIP);

  z = -50.0f;
  for(angle = 0.0f; angle <= (2.0f*GL_PI)*3.0f; angle += 0.1f)
  {
    x = 50.0f*sin(angle);
    y = 50.0f*cos(angle);

    // Specify the point and move the z value up a little
    glVertex3f(x, y, z);
    z += 0.5f;
  }

  // Done drawing points
  glEnd();

  // Restore transformations
  glPopMatrix();
}
