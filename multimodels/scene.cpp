#include "scene.h"
#include "ball.h"

void Scene::initialise(){
    // x=0.0;
    //y=0.0;
    //z=0.0;
    float startarray[4][6]={{9.0f,9.0f,0.0f,0.1f,-0.25f,0.0f},
                            {7.0f,9.0f,0.0f,0.05,-0.05f,0.0f},
                            {3.0f,9.0f,0.0f,0.01f,-0.02f,0.0f},
                            {0.0f,9.0f,0.0f,0.03f,-0.076f,0.0f}
    };
    nBalls=4;
    myBall=new Ball[nBalls];

	for(int i=0;i<nBalls;i++){
		myBall[i].initialise(0.0f,0.0f,0.0f);
	}

    for(int i=0;i<nBalls;i++){
        myBall[i].setx(startarray[i][0]);
        myBall[i].sety(startarray[i][1] );
		myBall[i].setz(startarray[i][2]  );

        myBall[i].setvx(startarray[i][3] );
        myBall[i].setvy(startarray[i][4] );
        myBall[i].setvz(startarray[i][5] );
       
		myBall[i].loadfile();
        myBall[i].setangle();
    }
 
}
 
void Scene::spinballs(){
  for(int i=0;i<nBalls;i++){
      myBall[i].spin();
    }
}

void Scene::moveobjects(){
    for(int i=0;i<nBalls;i++){
      myBall[i].move();
    }
}

void Scene::render(){
  glColor3f(1.0f,0.0f,0.0f);
//  glTranslatef(x,y,z);
  // glScalef(10.0f,10.0f,10.0f);
  //glutSolidCube(5.0);
  for(int i=0;i<nBalls;i++){
     //glutSolidCube(1.0);
	  myBall[i].draw();
  }
}

void Scene::cdetect(){
   
    for(int i=0;i<nBalls;i++){
      if((myBall[i].getx()<-10.0)||(myBall[i].getx()>10.0))
        myBall[i].setvx(myBall[i].getvx()*-1.0f);

      if((myBall[i].gety()<-10.0)||(myBall[i].gety()>10.0))
        myBall[i].setvy(myBall[i].getvy()*-1.0f);
    }

    for(int i=0;i<nBalls;i++){
	for(int j=i+1;j<nBalls;j++){
	    float tx=myBall[i].getx()-myBall[j].getx();
	    float ty=myBall[i].gety()-myBall[j].gety();
	    float tz=myBall[i].getz()-myBall[j].getz();

            float dist=sqrt(tx*tx+ty*ty+tz*tz);
            if(dist<0.9f){
                float temp=myBall[i].getvx();
                myBall[i].setvx(myBall[j].getvx());
                myBall[j].setvx(temp);
                temp=myBall[i].getvy();
                myBall[i].setvy(myBall[j].getvy());
                myBall[j].setvy(temp);
                temp=myBall[i].getvz();
                myBall[i].setvz(myBall[j].getvz());
                myBall[j].setvz(temp);
	    }
	}
    }


  

}
