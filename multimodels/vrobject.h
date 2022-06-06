#ifndef _VROBJECTS_H_
#define _VROBJECTS_H_

#include <windows.h>
#include "enums.h"
#include "worldmanager.h"
#include "camera.h"
#include "viewer.h"
#include <GL\glu.h>

camera *Viewer::mycamera;
WorldManager *Viewer::vrman;
int Viewer::BufType;
int Viewer::WinWidth;
int Viewer::WinHeight;
float Viewer::aim[3];
float Viewer::eye[3];
float Viewer::upright[3];
GLubyte theTexture[512][512][3];
#endif //_VROBJECTS_H_
