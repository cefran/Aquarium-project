#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <GL/glut.h>
#include <GL/glu.h>
#include "p_draw.h"
#include <math.h>


void Resize ( int Width, int Height );

void Initialize (int Width,int Height)

{
glClearColor( 0.0, 0.0, 0.0, 1.0 );
  Resize(Width , Height);
  glMatrixMode(GL_PROJECTION);
  
  
  //Appel de la fonction Resize
  Resize(Width , Height);
  
  glMatrixMode(GL_MODELVIEW);
}

void Resize ( int Width, int Height )

{ 
GLdouble Aspect;  
   
  glViewport(0, 0, (GLsizei)Width, (GLsizei)Height);

  Aspect = (GLdouble)Width / (GLdouble)Height;

  glMatrixMode( GL_PROJECTION );

  glLoadIdentity();
  gluPerspective( 45.0, Aspect, 10.0, 300.0);
 
  glMatrixMode( GL_MODELVIEW);
}

 

void Keyfunc ( unsigned char Key, int X, int Y)

{

 switch (Key)

 {

 case 'f' :

 printf("f\n");

 break;

 case 's' : 

 printf("s\n");

 break;

 }

}

void Menu ( int Value )

{

 if (Value == 1)

 NULL;

 else

 if (Value == 2)

 NULL;

 else

 if (Value == 3)

NULL;
 else
exit (0);
}

int main(int argc, char **argv)

{

 glutInit(&argc, argv);

 glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE |GLUT_DEPTH);
 glutCreateWindow("OpenGL & Glut: Programme de base");
 
 glutDisplayFunc(Drawscene);
 glutReshapeFunc(Resize);
 glutKeyboardFunc(Keyfunc);
 
 Initialize(200,200);
 glutMouseFunc(Mousefunc);
 glutMotionFunc(Mousemove);
 glutIdleFunc(Drawscene);

 glutMainLoop();

 return 0;

}
