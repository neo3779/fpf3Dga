#ifndef _SCENEOBJECTS_H_
#define _SCENEOBJECTS_H_

#include <windows.h>
#include <GL\gl.h>
#include <GL\glu.h>
#include "glut.h"
//#include <sceneobjects.h>

class SceneObject{
  float x,y,z;
  int shape,col;
 public:
  SceneObject(){return;}
  ~SceneObject(){return;}

 void initialise(float,float,float);

 void render();
 void setcolor(int);
 void setshape(int);
};

#endif //_SCENEOBJECTS_H_
