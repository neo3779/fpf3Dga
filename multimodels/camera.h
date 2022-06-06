#ifndef _CAMERA_H_
#define _CAMERA_H_
#include <windows.h>
#include "glut.h"
#include "enums.h"

class camera{
  myEnum Type;
  bool Changed[2];
  bool KeepMatrix;
  float Position[3];
  float AimAt[3];
  float UpDirection[3];
  float myNear;
  float myFar;
  float Height;
  float Aspect;
  float YAngle;

 public:
  camera(myEnum Ctype);
  
  void Render();
  void SetValuev(myEnum Pname, float *v);

  void SetValue(myEnum PName, float v1, float v2, float v3);

  void SetValue(myEnum PName, float v); 

};

#endif //_CAMERA_H_
