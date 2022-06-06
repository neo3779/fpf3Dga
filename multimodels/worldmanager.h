#ifndef _WORLDMANAGER_H_
#define _WORLDMANAGER_H_

#include <iostream>
#include <stdlib.h>
#include "glut.h"
#include "scene.h"


// Game Manager Object. 
// This object runs the game. 


class WorldManager{
   Scene *myscene; //sets up the scenery
 public:
  WorldManager(){return;} //default constructor
  ~WorldManager(){return;} //default destructor
  void initialise(); //routine that starts up the world.  
  void restart(); //routine that returns everything to the initial conditions
  void exec_loop(); //routine that sets up the game loop
  void render(); //routine that draws everything 

  //Links to the standard Open GL Call back funcions. 
  void keyboard(unsigned char key,int x,int y); //process game specific input
  void mouse(int button, int state, int x,int y); //
  void idle(); //Program executes when not waiting for input. 
};

#endif //_GAMEMANAGER_H_
