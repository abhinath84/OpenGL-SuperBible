/*
 * triangle.cpp
 *
 *  Created on: 02-May-2016
 *      Author: abhi
 */

#include "triangle.h"

Triangle::Triangle()
: GLWidget(),
  iCull(0),
  iOutline(0),
  iDepth(0),
  xRot(0.0f),
  yRot(0.0f)
{
}

Triangle::Triangle(int win_x, int win_y, int win_w, int win_h, const string &win_title)
: GLWidget(win_x, win_y, win_w, win_h, win_title),
  iCull(0),
  iOutline(0),
  iDepth(0),
  xRot(0.0f),
  yRot(0.0f)
{
}

Triangle::~Triangle()
{
}

void Triangle::initializeGL()
{
  // Black background
  glClearColor(0.0f, 0.0f, 0.0f, 1.0f );

  // Set drawing color to green
  glColor3f(0.0f, 1.0f, 0.0f);

  // Set color shading model to flat
  glShadeModel(GL_FLAT);

  // Clock wise wound polygons are front facing, this is reversed
  // because we are using triangle fans
  glFrontFace(GL_CW);
}

void Triangle::displayGL()
{
  GLfloat x,y,angle;  // Storage for coordinates and angles
  int iPivot = 1;   // Used to flag alternating colors

  // Clear the window and the depth buffer
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

  // Turn culling on if flag is set
  if(iCull)
    glEnable(GL_CULL_FACE);
  else
    glDisable(GL_CULL_FACE);

  // Enable depth testing if flag is set
  if(iDepth)
    glEnable(GL_DEPTH_TEST);
  else
    glDisable(GL_DEPTH_TEST);

  // Draw back side as a polygon only, if flag is set
  if(iOutline)
    glPolygonMode(GL_BACK,GL_LINE);
  else
    glPolygonMode(GL_BACK,GL_FILL);


  // Save matrix state and do the rotation
  glPushMatrix();
  glRotatef(xRot, 1.0f, 0.0f, 0.0f);
  glRotatef(yRot, 0.0f, 1.0f, 0.0f);


  // Begin a triangle fan
  glBegin(GL_TRIANGLE_FAN);

  // Pinnacle of cone is shared vertex for fan, moved up Z axis
  // to produce a cone instead of a circle
  glVertex3f(0.0f, 0.0f, 75.0f);

  // Loop around in a circle and specify even points along the circle
  // as the vertices of the triangle fan
  for(angle = 0.0f; angle < (2.0f*GL_PI); angle += (GL_PI/8.0f))
    {
    // Calculate x and y position of the next vertex
    x = 50.0f*sin(angle);
    y = 50.0f*cos(angle);

    // Alternate color between red and green
    if((iPivot %2) == 0)
      glColor3f(0.0f, 1.0f, 0.0f);
    else
      glColor3f(1.0f, 0.0f, 0.0f);

    // Increment pivot to change color next time
    iPivot++;

    // Specify the next vertex for the triangle fan
    glVertex2f(x, y);
    }

  // Done drawing fan for cone
  glEnd();


  // Begin a new triangle fan to cover the bottom
  glBegin(GL_TRIANGLE_FAN);

  // Center of fan is at the origin
  glVertex2f(0.0f, 0.0f);
  for(angle = 0.0f; angle < (2.0f*GL_PI); angle += (GL_PI/8.0f))
    {
    // Calculate x and y position of the next vertex
    x = 50.0f*sin(angle);
    y = 50.0f*cos(angle);

    // Alternate color between red and green
    if((iPivot %2) == 0)
      glColor3f(0.0f, 1.0f, 0.0f);
    else
      glColor3f(1.0f, 0.0f, 0.0f);

    // Increment pivot to change color next time
    iPivot++;

    // Specify the next vertex for the triangle fan
    glVertex2f(x, y);
    }

  // Done drawing the fan that covers the bottom
  glEnd();

  // Restore transformations
  glPopMatrix();


    glutSwapBuffers();
}

void Triangle::reshapeGL(int w, int h)
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

void Triangle::specialGL(int key, int x, int y)
{
  if(key == GLUT_KEY_UP)
    xRot-= 5.0f;

  if(key == GLUT_KEY_DOWN)
    xRot += 5.0f;

  if(key == GLUT_KEY_LEFT)
    yRot -= 5.0f;

  if(key == GLUT_KEY_RIGHT)
    yRot += 5.0f;

  if(key > 356.0f)
    xRot = 0.0f;

  if(key < -1.0f)
    xRot = 355.0f;

  if(key > 356.0f)
    yRot = 0.0f;

  if(key < -1.0f)
    yRot = 355.0f;

  // Refresh the Window
  glutPostRedisplay();
}

void Triangle::createMenuGL(int menu)
{
  switch(menu)
  {
    case 1:
      iDepth = !iDepth;
      break;

    case 2:
      iCull = !iCull;
      break;

    case 3:
      iOutline = !iOutline;
      break;

    default:
      break;
  }

  glutPostRedisplay();
}

void Triangle::setupMenu()
{
  glutAddMenuEntry("Toggle depth test",1);
  glutAddMenuEntry("Toggle cull backface",2);
  glutAddMenuEntry("Toggle outline back",3);
  glutAttachMenu(GLUT_RIGHT_BUTTON);
}

