#ifndef _SCENE_H_
#define _SCENE_H_

#include <windows.h>
#include <GL\gl.h>
#include <GL\glu.h>
#include "glut.h"
#include <math.h>
#include "ball.h"

class Scene{
    //float x,y,z;
    int nBalls;
    Ball *myBall;
 public:
  Scene(){return;}
  ~Scene(){return;}

 void initialise();
 void render();
 void moveobjects();
 void cdetect();
 void spinballs();
};

#endif //_SCENE_H_
