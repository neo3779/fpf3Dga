#include "camera.h"

camera::camera(myEnum CType){
  
  Type=CType;
  KeepMatrix=true;

  for(int i=0; i<3; i++)
    {
      if(i<2)
        Changed[i]=false;
      Position[i]=0.0;
      AimAt[i]=0.0;
      UpDirection[i]=0.0;
    }
  UpDirection[1]=1.0;
  AimAt[2]=-100.0;  
}

void camera::SetValuev(myEnum PName, float *v)
{
  float *temp;
  int i;

  switch(PName)
    {
    case POSITION:
      Changed[0]=true;
      temp=Position;
      break;
    case AIMAT:
      Changed[0]=true;
      temp=AimAt;
      break;
    case UPDIRECTION:
      Changed[0]=true;
      temp=UpDirection;
      break;
    default:
      break;
    }

  for(int i=0; i<3; i++)
    temp[i]=v[i];
}
void camera::SetValue(myEnum PName, float v1, float v2, float v3)
{
  float temp[]={v1, v2, v3};
  
  SetValuev(PName, temp);
}

void camera::SetValue(myEnum PName, float v)
{
  switch(PName)
    {
    case ASPECT:
      Changed[1]=true;
      Aspect=v;
      break;
    case MNEAR:
      Changed[1]=true;
      myNear=v;
      break;
    case MFAR:
      Changed[1]=true;
      myFar=v;
      break;
    case HEIGHT:
      if(Type==ORTHO)
        {
          Changed[1]=true;
          Height=v;
        }
      break;
 case YANGLE:
      if(Type==PERSPECTIVE)
        {
          Changed[1]=true;
          YAngle=v;
        }
      break;
    default:
      break;
    }
}
void camera::Render()
{
  float x1=0;
  float x2=Height*Aspect;
  float y1=-Height;
  float y2=0;

  if(Changed[1])
    {
      glMatrixMode(GL_PROJECTION);
      glLoadIdentity();
      if(Type==ORTHO)
        glOrtho(x1, x2, y1, y2, myNear, myFar);
      else
        gluPerspective(YAngle, Aspect, myNear, myFar);
      glMatrixMode(GL_MODELVIEW);
    }
  if(Changed[0])
    {
      glLoadIdentity();
      gluLookAt(Position[0], Position[1], Position[2], AimAt[0],
                AimAt[1], AimAt[2], UpDirection[0], UpDirection[1],
                UpDirection[2]);
    }
}
