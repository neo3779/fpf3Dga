#include "worldmanager.h"
// This is where you add your code

void WorldManager::initialise(){
  myscene=new Scene;
  myscene->initialise();
   return;
}

void WorldManager::restart(){
 

}

void WorldManager::exec_loop(){
  //exectuion loop.
  render();
}

void WorldManager::render(){

  //  Draw a scene
  myscene->render();
  // myscene->cdetect();
  //myscene->moveobjects();
}

void WorldManager::keyboard(unsigned char key,int x,int y){
  switch(key){
  case 27: exit(0); 
    break;
  }
  return;
}

void WorldManager::mouse(int button, int state, int x,int y){
  return;
}

void WorldManager::idle(){
      myscene->cdetect();
      myscene->spinballs();
      myscene->moveobjects();
  return;
}
