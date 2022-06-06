#ifndef _VIEWER_H_
#define _VIEWER_H_

#include <windows.h>
#include <iostream>
#include "glut.h"

#include "enums.h"
#include "camera.h"
#include "worldmanager.h"

class Viewer{

 
  char *WinName;
  float background[3];

  static float eye[3];
  static float aim[3];
  static float upright[3];
  
  static WorldManager *vrman;
  static camera *mycamera;
  void GLInit();
   
  static int BufType;
  static int WinWidth;
  static int WinHeight;
  static void Reshape(int w,int h);
  static void Display();
  static void Mouse(int button, int state,int x,int y);
  static void Idle();
  static void Keyboard(unsigned char key, int x, int y);
  static void SpecialKey(int key, int x, int y);
 /*  static void Reshape1(int w,int h); */
/*   static void Display1(); */
/*   static void Resahpe2(int w,int h); */
/*   static void Display2(); */

 public:
  void InitCamera();
  void InitWorld();
  void SetValue(myEnum PName,myEnum Type);
  void Init(int argc, char **argv);
  void Show();
  void CreateWin(char *Name,int Width,int Height);
  void SetCamera(float nvalue,float viewangle);
 Viewer();
  ~Viewer();
};

#endif //_VIEWER_H_
