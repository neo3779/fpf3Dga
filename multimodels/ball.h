#ifndef _BALL_H_
#define _BALL_H_

#include <windows.h>
#include <GL\gl.h>
#include <GL\glu.h>
#include "glut.h"
#include "3dsloader.h"
#include "otypes.h"


class Ball{

    float x,y,z; // position in space
    float vx,vy,vz; //movement vector
    float theta;
	 obj_type object;
	 char fileloaded;
	
	public:
    Ball(){}
    Ball(float tx,float ty, float tz){x=tx;y=ty;z=tz;}

    void initialise(float tx,float ty, float tz){
		
      x=tx;y=ty;z=tz;
    }

    void loadfile(){fileloaded=Load3DS (&object,"spaceship.3ds");}
    void setangle(){theta = 0.0f;}
    void spin(){
			if (theta >= 360)
				theta = 0.0f;
         else
             theta += 5.0f;
    }
    float getx(){return x;}
    float gety(){return y;}
    float getz(){return z;}
    
    float getvx(){return vx;}
    float getvy(){return vy;}
    float getvz(){return vz;}

    void setx(float tx){x=tx;}
    void sety(float ty){y=ty;}
    void setz(float tz){z=tz;}

    void setvx(float tx){vx=tx;}
    void setvy(float ty){vy=ty;}
    void setvz(float tz){vz=tz;}
    
    void move(){x+=vx;y+=vy;z+=vz;}

    void draw();

};
#endif //_BALL_H_
