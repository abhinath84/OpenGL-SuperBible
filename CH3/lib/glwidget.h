/*
 * glwidget.h
 *
 *  Created on: 25-Mar-2016
 *      Author: abhi
 */

#ifndef GLWIDGET_H_
#define GLWIDGET_H_

#include <iostream>
#include <ctime>

// opengl related includes
#if (defined(_WIN64) || defined(_WIN32))
  #include <freeglut.h>
#elif __linux
  #include <GL/glut.h>
#endif

#include "point.h"

using namespace std;

typedef Point<int> Point2d;

typedef struct glWindow
{
  int     x;
  int     y;
  int     width;
  int     height;
  string  title;

  glWindow()
  {
    x       = 100;
    y       = 50;
    width   = 800;
    height  = 600;
    title   = "Default GLWindow";
  }

  glWindow(int x, int y, int w, int h, const string &title)
  {
    this->x = x;
    this->y = y;
    this->width = w;
    this->height = h;
    this->title.assign(title);
  }

}GLWindow;

class GLWidget
{
public:
  GLWidget();
  GLWidget(int win_x, int win_y, int win_w, int win_h, const string &win_title);
  virtual ~GLWidget() = 0;

  void    setWidth(int w);
  int     getWIdth() const;
  void    setHeight(int h);
  int     getHeight()const;
  void    setTitle(const string &title);
  string  getTitle()const;
  void    setPosition(int x, int y);
  Point2d getPostion()const;
  void    setDisplayModeGL(unsigned int displayMode);
  void    mainloopGL(int argc, char **argv);

protected:
  virtual void initializeGL();
  virtual void beforeMainLoopGL();
  virtual void setupMenu();

protected:
  virtual void displayGL();
  virtual void reshapeGL(int w, int h);
  virtual void specialGL(int key, int x, int y);
  virtual void keyboardGL(unsigned char key, int x, int y);
  virtual void overlayDisplayGL();
  virtual void mouseGL(int button, int state, int x, int y);
  virtual void motionGL(int x, int y);
  virtual void passiveMotionGL(int x, int y);
  virtual void visibilityGL(int state);
  virtual void entryGL(int state);
  virtual void spaceBallMotionGL(int x, int y, int z);
  virtual void spaceBallRotateGL(int x, int y, int z);
  virtual void spaceBallButtonGL(int button, int state);
  virtual void buttonBoxGL(int button, int state);
  virtual void dialsGL(int dial, int value);
  virtual void tableMotionGL(int x, int y);
  virtual void tableButtonGL(int button, int state, int x, int y);
  virtual void menuStatusGL(int status, int x, int y);
  virtual void idleGL();
  virtual void timerGL(int value);
  virtual void createMenuGL(int menu);

private:
  static void display();
  static void reshape(int w, int h);
  static void special(int key, int x, int y);
  static void keyboard(unsigned char key, int x, int y);
  static void overlayDisplay();
  static void mouse(int button, int state, int x, int y);
  static void motion(int x, int y);
  static void passiveMotion(int x, int y);
  static void visibility(int state);
  static void entry(int state);
  static void spaceBallMotion(int x, int y, int z);
  static void spaceBallRotate(int x, int y, int z);
  static void spaceBallButton(int button, int state);
  static void buttonBox(int button, int state);
  static void dials(int dial, int value);
  static void tableMotion(int x, int y);
  static void tableButton(int button, int state, int x, int y);
  static void menuStatus(int status, int x, int y);
  static void idle();
  static void timer(int value);
  static void createManu(int menu);

private:
  void setInstance();

private:
  static GLWidget   *instance;
  GLWindow          window;
  unsigned int      glutDisplayMode;
};

#endif /* GLWIDGET_H_ */
