#include <iostream>

using namespace std;

#include "vrobject.h"


int main(int argc, char **argv){

  Viewer *myViewer=new Viewer;
  myViewer->Init(argc,argv);
  myViewer->InitWorld();
  myViewer->SetValue(BUFFER,MDOUBLE);
  myViewer->CreateWin("Test",500,500);
  myViewer->InitCamera();
  myViewer->Show();

  return 0;
}
