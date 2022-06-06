#include "sceneobjects.h"

void SceneObject::initialise(float nX,float nY, float nZ){
  x=nX;
  y=nY;
  z=nZ;
  shape=1;
  col=1;

}

void SceneObject::render(){

  glPushMatrix();
  if (col==1)glColor3f(1.0f,0.0f,0.0f);
  if (col==2)glColor3f(0.0f,1.0f,0.0f);
  if (col==3)glColor3f(0.0f,0.0f,1.0f);
  glTranslatef(x,y,z);
  // glScalef(10.0f,10.0f,10.0f);
  if (shape==1)glutSolidCube(5.0);
  if (shape==2)glutSolidTeapot(5.0);
  if (shape==3)glutSolidSphere(5.0,20,20);
  glPopMatrix();
}

void SceneObject::setcolor(int ncol){
	col = ncol;
}

void SceneObject::setshape(int nshape){
	shape = nshape;
}
