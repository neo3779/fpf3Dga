#include "ball.h"

void Ball::draw(){
    //glPushMatrix();
    //glTranslatef(x,y,z);
    //glutWireSphere(1.0f,20,20);
    //glPopMatrix();

    int l_index;
	glPushMatrix();
  	glColor3f(0.0f,1.0f,0.0f);
  	glTranslatef(x,y,z);
  
  	if (fileloaded){
   glScalef(0.01f,0.01f,0.01f);
   glRotatef(theta,1.0f,0.0f,0.0f);
	glBegin(GL_TRIANGLES); // glBegin and glEnd delimit the vertices that define a primitive (in our case triangles)
    for (l_index=0;l_index<object.polygons_qty;l_index++)
    {
        //----------------- FIRST VERTEX -----------------
        
        glVertex3f( object.vertex[ object.polygon[l_index].a ].x,
                    object.vertex[ object.polygon[l_index].a ].y,
                    object.vertex[ object.polygon[l_index].a ].z); //Vertex definition

        //----------------- SECOND VERTEX -----------------
        // Coordinates of the second vertex
        glVertex3f( object.vertex[ object.polygon[l_index].b ].x,
                    object.vertex[ object.polygon[l_index].b ].y,
                    object.vertex[ object.polygon[l_index].b ].z);
        
        //----------------- THIRD VERTEX -----------------
        // Coordinates of the Third vertex
        glVertex3f( object.vertex[ object.polygon[l_index].c ].x,
                    object.vertex[ object.polygon[l_index].c ].y,
                    object.vertex[ object.polygon[l_index].c ].z);
    }
    glEnd(); 
  }
  else
   {
    	glScalef(0.05f,0.05f,0.05f);
		glutSolidCube(5.0);
   }
  glPopMatrix();
}
