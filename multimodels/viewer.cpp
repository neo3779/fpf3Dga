#include "viewer.h"


Viewer::Viewer(){
  
  
  WinName="";
  BufType=GLUT_SINGLE;
  
  for(int i=0;i<3;i++){
    background[i]=0.0f;
  }

}

Viewer::~Viewer(){
  return;
}

void Viewer::Init(int argc,char **argv){

  eye[0]=0.0f;
  eye[1]=0.5;
  eye[2]=25.0;

  aim[0]=0.0f;
  aim[1]=0.0f;
  aim[2]=0.0f;

  upright[0]=0.0f;
  upright[1]=1.0f;
  upright[2]=0.0f;
    
  glutInit(&argc,argv);
 
}

void Viewer::CreateWin(char *Name,int Width,int Height){
  WinName=Name;
  WinWidth=Width;
  WinHeight=Height;
}

void Viewer::SetValue(myEnum PName,myEnum Type){

  switch(PName){
  case BUFFER:
    if(Type==MDOUBLE)
      BufType=GLUT_DOUBLE;
    else
      if(Type==SINGLE)
        BufType=GLUT_SINGLE;
    break;
  case BACKCOLOUR:
    break;
  default:
    break;
  }
}


void Viewer::InitWorld(){
  vrman=new WorldManager;
  vrman->initialise();
 
}
void Viewer::InitCamera(){
  mycamera=new camera(PERSPECTIVE);
  mycamera->SetValue(MNEAR,5.0f);
  mycamera->SetValue(YANGLE,45.0f);


  mycamera->SetValuev(AIMAT, aim);
  mycamera->SetValuev(UPDIRECTION, upright);
  mycamera->SetValuev(POSITION, eye);
  
  mycamera->SetValue(MFAR,33.0f);
  mycamera->SetValue(HEIGHT,WinHeight);
  mycamera->SetValue(ASPECT,1.0f);
}

void Viewer::SetCamera(float nvalue,float viewangle){
  mycamera->SetValue(MNEAR, nvalue);
  mycamera->SetValue(YANGLE, viewangle);

}

void Viewer::Show(){
  
  GLInit();
  glutMainLoop();

}


void Viewer::GLInit(){
  glutInitDisplayMode(BufType |GLUT_RGB |GLUT_DEPTH);
  glutInitWindowSize(WinWidth, WinHeight);
  glutCreateWindow(WinName);
  glutReshapeFunc(Reshape);
  glutDisplayFunc(Display);
  glutMouseFunc(Mouse);
  glutIdleFunc(Idle);
  glutKeyboardFunc(Keyboard);
  glutSpecialFunc(SpecialKey); 
 //  glEnable(GL_DEPTH_TEST);
  glClearColor(0.0f,0.0f,0.0f,1.0f);

}


void Viewer::Display(){
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

  vrman->exec_loop();
  
 
  glFlush();
  if(BufType==GLUT_DOUBLE){

    glutSwapBuffers();
  }
  

}

void Viewer::Reshape(int w,int h){

  glViewport(0,0,(GLsizei)w,(GLsizei)h);
  WinWidth=w;
  WinHeight=h;
  mycamera->SetValuev(POSITION,eye);
  mycamera->SetValuev(AIMAT,aim);
  mycamera->Render();
 
}

void Viewer::Mouse(int button,int state,int x,int y){

  vrman->mouse(button,state,x,y);
  Display();
}

void Viewer::Idle(){
  vrman->idle();
  Display();
}

void Viewer::Keyboard(unsigned char key,int x,int y){

  switch(key){
  case 0x14b:
  case GLUT_KEY_UP:
    eye[2]-=0.5;
    aim[2]-=0.5;
    break;
  case GLUT_KEY_DOWN:
    eye[2]+=0.5;
    aim[2]+=0.5;
    break;
  case GLUT_KEY_LEFT:
    eye[0]-=0.5;
    aim[0]-=0.5;
    break;
  case GLUT_KEY_RIGHT:
    eye[0]+=0.5;
    aim[0]+=0.5;
    break;
  default:
     vrman->keyboard((unsigned char)key,x,y);
     break;
  }
  
  Display();
}

void Viewer::SpecialKey(int key, int x, int y){
 switch(key){
 case GLUT_KEY_F1:
      upright[0]=0.0f;
      upright[1]=0.0f;
      upright[2]=-1.0f;
      aim[0]=0.0f;
      aim[1]=0.0f;
      aim[2]=0.0f;
      eye[0]=0.0f;
      eye[1]=25.0f;
      eye[2]=0.0f;
      break;
 case GLUT_KEY_F2:
      upright[0]=0.0f;
      upright[1]=1.0f;
      upright[2]=0.0f;
      aim[0]=0.0f;
      aim[1]=0.0f;
      aim[2]=0.0f;
      eye[0]=0.0f;
      eye[1]=0.5f;
      eye[2]=25.0f;
      break;
  case GLUT_KEY_F12:
    vrman->restart();
    break;
  case GLUT_KEY_UP:
    eye[2]-=0.5;
    aim[2]-=0.5;
    break;
  case GLUT_KEY_DOWN:
    eye[2]+=0.5;
    aim[2]+=0.5;
    break;
  case GLUT_KEY_LEFT:
    eye[0]-=0.5;
    aim[0]-=0.5;
    break;
  case GLUT_KEY_RIGHT:
    eye[0]+=0.5;
    aim[0]+=0.5;
    break;
 case GLUT_KEY_PAGE_UP:
   eye[1]+=0.5;
   aim[1]+=0.5;
   break;
 case GLUT_KEY_PAGE_DOWN:
   eye[1]-=0.5;
   aim[1]-=0.5;
   break;
  default:
     vrman->keyboard((unsigned char)key,x,y);
     break;
  }
 mycamera->SetValuev(UPDIRECTION,upright);
 mycamera->SetValuev(POSITION,eye);
 mycamera->SetValuev(AIMAT,aim);
 mycamera->Render();
 Display();
}
