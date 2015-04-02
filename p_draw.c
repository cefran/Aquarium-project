#include <GL/glut.h>
#include <math.h>
#include "p_draw.h"

GLdouble Radius = 2.0;
GLdouble Twist = 1.0;
GLdouble Longitude = 1.0;
GLdouble Latitude = 1.0;

int Y_Start_Zoom;  
int X_Start_Move;  
int Y_Start_Move;

GLboolean Move_Flag = GL_FALSE;  
GLboolean Zoom_Flag  = GL_FALSE;  

float alpha=-20;
static GLfloat beta=0.0000;
double lambda=0.0;
static GLfloat gamma=0.0000;
double teta=0.0000;
double Dxrequin=0.000;
double Dyrequin=0.000;
double Rrequin=0.000;

int test=0;
int test2=0;
int test3=0;

double posX=0;
double posX2=0;
double posY=0;
double posY2=0;

double x=0;
double x2=0;

double rot=0;
double rot2=0;
double rotMar=0;
double rotTor1=20;
double rotTor2=20;
double rotTor3=0;
double rotC=90;
double rotTor=0;

int inc=0;
int incM=0;
double inc2=90;
double inc3=90;
int ind1;
int indC;

int test4;
int test5;
int test6;
int test7;
int test8;
int test9;
int test10;
int test11;
int test12;
int test13;
int test14;
int j,i;

double algue;
double algue2;
double algue3;

GLfloat WhiteAmbient[] = {0.0, 0.0, 0.0, 1.0};

void DrawCoffre(void)
{
	GLdouble eqn[4] = {1.0, 0.0, 0.0, 0.0};
	glPushMatrix();
	glColor3f(0.55,0.27,0.074);
     glTranslatef(-50,0,-3.5);
     glScalef(1,2,1);
    glutSolidCube(7);
    glPopMatrix();
    glPushMatrix();
    glRotatef(90,0,1,0);
    glRotatef(90,1,0,0);
    glTranslatef(7,-50,-7);
    
    if(rotC>=80)
    {
    	test13=1;
    }
    else
    {
    	if(rotC<=-10)
    	{
    		test13=0;
    	}
    }
    
    if(test13==1)
    {
    	rotC-=0.1;
    }
    else
    {
    	if(test13==0)
    	{
    		rotC+=0.1;
    	}
    }
    glTranslatef(0,1.5,0);
	glRotatef(rotC,0,0,1);
	glTranslatef(0,-1.5,0);
    
    GLUquadricObj* params = gluNewQuadric();
    gluQuadricDrawStyle(params,GLU_FILL );
    glClipPlane (GL_CLIP_PLANE0, eqn);
    glEnable (GL_CLIP_PLANE0);
	glColor3f(0.55,0.27,0.074); 
    glScalef(1,1.25,1);
    gluCylinder(params,3,3,14,10,5);
    glRotatef(180, 1,0,0); 
    gluDisk(params, 0.0, 3, 10, 1); 
    glRotatef(180, 1,0,0); 
    glTranslatef(0.0, 0.0, 14); 
    gluDisk(params, 0.0, 3, 10, 1); 
    glTranslatef(0.0, 0.0, -50);
    glDisable (GL_CLIP_PLANE0);
    
    glPopMatrix();
	
}
void DrawEpave(void)
{
	GLdouble eqn[4] = {0.0, 0.0, 1.0, 0.0};
	
	glPushMatrix();
	GLUquadricObj* params = gluNewQuadric();
    gluQuadricDrawStyle(params,GLU_FILL );
    glTranslatef(0,0,-8);
    glRotatef (40.0, 0.0, 1.0, 0.0);
    glClipPlane (GL_CLIP_PLANE0, eqn);
    glEnable (GL_CLIP_PLANE0); 
	glColor3f(0.55,0.27,0.15);
	glScalef(20,7,8);
	gluSphere(params,3,10,10);
    glDisable (GL_CLIP_PLANE0);   
    glPopMatrix(); 
    glRotatef (40.0, 0.0, 1.0, 0.0);
    glTranslatef(0,0,-60);
    gluCylinder(params,3,3,70,10,5);
    
    rotTor+=0.05;
    glRotatef (-rotTor, 0.0, 0.0, 1.0);
    glTranslatef(0,9,30);
    Tortue();
	glPopMatrix();
}
void Tortue(void)
{
	GLdouble eqn[4] = {0.0, 0.0, -1.0, 0.0};
	
	glPushMatrix();
	GLUquadricObj* params = gluNewQuadric();
    gluQuadricDrawStyle(params,GLU_FILL );
    glClipPlane (GL_CLIP_PLANE0, eqn);
    glEnable (GL_CLIP_PLANE0); 
	glColor3f(0,0.39,0);
	glScalef(2,1.5,1);
	gluSphere(params,2,10,10);
    glRotatef (90.0, 0.0, 1.0, 0.0);
    glDisable (GL_CLIP_PLANE0);   
    glPopMatrix(); 
    glPushMatrix();
    glTranslatef(3.5,0,-0.25);
    if(rotTor3>=20)
    {
    	test12=1;
    }
    else
    {
    	if(rotTor3<=-20)
    	{
    		test12=0;
    	}
    }
    
    if(test12==1)
    {
    	rotTor3-=0.1;
    }
    else
    {
    	if(test12==0)
    	{
    		rotTor3+=0.1;
    	}
    }
	glRotatef(rotTor3,0,0,1);
    glRotatef(90,0,1,0);
    glColor3f(0.2,0.8,0.2);
    gluCylinder(params,0.4,0.4,1,10,5);
    glTranslatef(0,0,1);
    gluCylinder(params,0.9,0.2,2,10,5);
    
    glPopMatrix();
    glPushMatrix();
    
    if(rotTor1>=20)
    {
    	test10=1;
    }
    else
    {
    	if(rotTor1<=-20)
    	{
    		test10=0;
    	}
    }
    
    if(test10==1)
    {
    	rotTor1-=0.1;
    }
    else
    {
    	if(test10==0)
    	{
    		rotTor1+=0.1;
    	}
    }
	glRotatef(rotTor1,1,0,0);
	 glTranslatef(0,0,2);
	glRotatef(90,0,0,1);    
	glRotatef(20,0,1,0);
    glBegin(GL_TRIANGLES);
      glColor3f(0.2,0.8,0.2);
      glVertex3f( 2.0f, 1.0f, -2.0f);       
      glVertex3f( 2.0f,-2.0f, 1.0f);
      glVertex3f( 2.0f,-2.0f, -2.0f);   
      glEnd();  
      
    glTranslatef(4,1,0);
    glRotatef(180,0,0,1);
    glBegin(GL_TRIANGLES);
      glColor3f(0.2,0.8,0.2);         
      glVertex3f( 2.0f, 1.0f, -2.0f);       
      glVertex3f( 2.0f,-2.0f, 1.0f);
      glVertex3f( 2.0f,-2.0f, -2.0f);   
      glEnd();
    
    glPopMatrix();
    glPushMatrix();
     if(rotTor2>=25)
    {
    	test11=1;
    }
    else
    {
    	if(rotTor2<=-25)
    	{
    		test11=0;
    	}
    }
    
    if(test11==1)
    {
    	rotTor2-=0.1;
    }
    else
    {
    	if(test11==0)
    	{
    		rotTor2+=0.1;
    	}
    }
    glPopMatrix();
    glPushMatrix();
    glTranslatef(-0.5,0.5,1.25);
    glRotatef(90,0,0,1);
    glRotatef(180,0,0,1);
    glTranslatef(0,0,-2);
	glRotatef(-rotTor1,0,1,0);
	glTranslatef(0,0,2);
	
    
    glBegin(GL_TRIANGLES);
      glColor3f(0.2,0.8,0.2);
      glVertex3f( 2.0f, 1.0f, -2.0f);       
      glVertex3f( 2.0f,-2.0f, 1.0f);
      glVertex3f( 2.0f,-2.0f, -2.0f);   
      glEnd();  
      
    glTranslatef(4,1,0);
    glRotatef(180,0,0,1);
    glBegin(GL_TRIANGLES);
      glColor3f(0.2,0.8,0.2);          
      glVertex3f( 2.0f, 1.0f, -2.0f);       
      glVertex3f( 2.0f,-2.0f, 1.0f);
      glVertex3f( 2.0f,-2.0f, -2.0f);   
      glEnd();
	glTranslatef(0,-4,-14.5);
    glRotatef(90,0,0,1);
    glRotatef(-20,0,1,0);
    
    glPopMatrix();
               
	   	  
}
void Polarview ( GLdouble Radius,GLdouble Twist,GLdouble Longitude,GLdouble Latitude )
{
          glTranslated( 0.0, 0.0, -Radius );
          glRotated( -Twist,    0.0, 0.0, 1.0 );
          glRotated( -Latitude, 1.0, 0.0, 0.0 );
          glRotated( Longitude, 0.0, 1.0, 0.0 );
}

void DrawAxes(void)
{
          glColor3f( 1.0, 1.0, 1.0 );
              
          glBegin( GL_LINES );
          glVertex3f( 0.0, 0.0, 0.0);
          glVertex3f( 30, 0.0, 0.0);
          glVertex3f( 0.0, 0.0, 0.0);
          glVertex3f( 0.0, 30, 0.0);      
          glVertex3f( 0.0, 0.0, 0.0);
          glVertex3f( 0.0, 0.0, 30);      
          glEnd();
              
          glColor3f( 1, 1, 1);
          glBegin( GL_POLYGON );
          glVertex3f( 1.5,   0.0 , 0.0);
          glVertex3f( 1.35, -0.05, 0.0);
          glVertex3f( 1.35,  0.05, 0.0);
          glEnd();
              
          glColor3f( 1, 1.0, 1 );
          glBegin( GL_POLYGON );
          glVertex3f(  0.0,  1.5 , 0.0);
          glVertex3f( -0.05, 5, 0.0);
          glVertex3f(  0.05, 1.35, 0.0);
          glEnd();
              
          glColor3f( 1, 1, 1.0 );
          glBegin( GL_POLYGON );
          glVertex3f(  0.0,  0.0, 1.5 );
          glVertex3f( -0.05, 0.0, 1.35);
          glVertex3f(  0.05, 0.0, 1.35);
          glEnd();
}

void DrawFish(float taille)
{
	
	glPushMatrix();
	glColor3f(0,0,1);
	
	
    GLUquadricObj* params = gluNewQuadric();
    gluQuadricDrawStyle(params,GLU_FILL );
    gluCylinder(params,0.5,0,taille/2,10,5);
    glRotatef(180, 0.0, 1.0, 0);
	gluQuadricDrawStyle(params,GLU_FILL );
    gluCylinder(params,0.5,0,taille/2,10,5);
    
    if(alpha==30)
    {
    	test=1;
    }
    else
    {
    	if(alpha==-30)
    {
    	test=0;
    }
    }
    if(test==1)
    {
    	alpha-=0.5;
    }
    else
    {
    	alpha+=0.5;
    }
    
    
  
    
    glTranslatef(0,0,1.499);
    glRotatef(alpha, 0, 1, 0 );
    glTranslatef(0,0,-1.499);
    
    glColor3f(0,0,1);
    glBegin( GL_TRIANGLES );
    glVertex3f(  0, 0, taille/2 );
    glVertex3f( 0, 0,  taille/2+taille/4 );
    glVertex3f(  0,1, taille/2 );
    glEnd();

    
    glPopMatrix();
}

void DrawAlgue(void)
{
	glPushMatrix();
	glColor3f(0 ,0.39,0);
	GLUquadricObj* params = gluNewQuadric();
    gluQuadricDrawStyle(params,GLU_FILL );
    glTranslatef(0,0,-4);
    gluCylinder(params,0.5,0.5,4,10,5);
    glPopMatrix();
    glPushMatrix();
    glTranslatef(0,0,-6);
    if(algue>=0.12&&ind1==1)
    {
    	test7=1;
    	
    }
    else
    {
    	if(algue<=-0.12&&ind1==0)
    	{
    		test7=2;
    	}
    }
    
    if(test7==1)
    {
    	algue-=0.0001;
    }
    else
    {
    	algue+=0.0001;
    }
    glTranslatef(algue,0,0);
    gluCylinder(params,0.5,0.5,2,10,5);
    glPopMatrix();
     glPushMatrix();
    glTranslatef(0,0,-6);
    glTranslatef(0,0,-2);
    if(algue2>=0.25&&ind1==1)
    {
    	test8=1;
    }
    else
    {
    	if(algue2<=-0.25&&ind1==0)
    	{
    		test8=2;
    		
    	}
    }
    
    if(test8==1)
    {
    	algue2-=0.0001;
    }
    else
    {
    	algue2+=0.0001;
    }
    glTranslatef(algue2,0,0);
    glPopMatrix();
    glPushMatrix();
    gluCylinder(params,0.5,0.5,2,10,5);
    glTranslatef(0,0,-2);
     if(algue3>=0.5)
    {
    	test9=1;
    	ind1=1;
    }
    else
    {
    	if(algue3<=-0.5)
    	{
    		test9=2;
    		ind1=0;
    	}
    }
    
    if(test9==1)
    {
    	algue3-=0.0001;
    	
    }
    else
    {
    	algue3+=0.0001;
    }
    glTranslatef(algue3,0,0);
    gluCylinder(params,0.5,0.5,2,10,5);
	glPopMatrix();
}

void DrawBanc(float tp, float bp)
{
	glPushMatrix();
	int np = bp/tp;
	
	float x,y,z=bp;
	int j,k,l;
	for(j=0;j<2*np;j+=1)
	{
		x=x-tp;
		glTranslatef(x,0,0);
		DrawFish(tp);
		glTranslatef(-x,0,0);
	}
	glPopMatrix();
	for(k=0;k<2*np;k+=1)
	{
		y=y-tp;
		glTranslatef(0,y,0);
		DrawFish(tp);
		glTranslatef(0,-y,0);
	}
	glPopMatrix();
	
	for(l=0;l<2*np;l+=1)
	{
		z=z-tp;
		glTranslatef(0,0,z);
		DrawFish(tp);
		glTranslatef(0,0,-z);
	}
	glPopMatrix();
	
}

void DrawRequin(void)
{
	
	glPushMatrix();
	glTranslatef(0,15,0);
	
	
    GLUquadricObj* params = gluNewQuadric();
    gluQuadricDrawStyle(params,GLU_FILL );
    glColor3f(0.37,0.48,0.55);
    gluCylinder(params,3,1.5,6,10,5);
    glRotatef(180,1,0,0);
    gluCylinder(params,3,0.5,7,10,5);
    glTranslatef(0,0,-6);
    glRotatef(180,1,0,0);
    
    if(fabs(30-teta) < 0.000001)
    {
    	test2=1;
    }
    else
    {
    	if(fabs(-30-teta) < 0.000001)
    {
    	test2=0;
    }
    }
    if(test2==1)
    {
    	teta-=0.1;
    }
    else
    {
    	teta+=0.1;
    }
    
    glRotatef(teta,0,1,0);
    
    gluCylinder(params,1.5,1,2,10,5);
    glRotatef(-teta,0,1,0);
    
        if(fabs(30-lambda) < 0.000001)
    {
    	test3=1;
    }
    else
    {
    	if(fabs(-30-lambda) < 0.000001)
    {
    	test3=0;
    }
    }
    if(test3==1)
    {
    	lambda-=0.1;
    }
    else
    {
    	lambda+=0.1;
    }
    
    
    
    glRotatef(lambda,0,1,0);
    
    glTranslatef(0,0,2);
    gluCylinder(params,1,0.5,3,10,5);
    
     glTranslatef(-2,0,5);
     glTranslatef(0,2,0);
	  glBegin(GL_QUADS);  
	  glColor3f(0.37,0.48,0.55);        // Dessin d'un quadrilatère
      glVertex3f(2.0f, 2.0f, 0.5);    // Haut Gauche
      glVertex3f( 2.0f,-2.0f, 0.5);    // Haut Droite
      glVertex3f( 2.0f,-6.0f, 4);    // Bas Droite
      glVertex3f( 2.0f,-2.0f, -3.0f);    // Bas Gauche
      glEnd();                 
	  glPopMatrix(); 
	
	glRotatef(180, 1,0,0);
	glTranslatef(0,-12,0);
    
    glBegin(GL_TRIANGLES);
    glColor3f(0.37,0.48,0.55);           // Rouge
    glVertex3f( 5.0f, 2.0f, -2.0f);       // Haut du triangle (Droit)          // Bleu
    glTranslatef(0,0,6);
	glVertex3f( 2.0f,-2.0f, 2.0f);       // Gauche du triangle (Droit)        // Vert
    glVertex3f( 2.0f,-2.0f, -2.0f);      // D
    glEnd();
	 
	glTranslatef(-4,0,0);
      
    glBegin(GL_TRIANGLES);
    glColor3f(0.37,0.48,0.55);           // Rouge
    glVertex3f( -2.0f, 2.0f, -2.0f);       // Haut du triangle (Droit)          // Bleu
    glVertex3f( 2.0f,-2.0f, 2.0f);       // Gauche du triangle (Droit)        // Vert
    glVertex3f( 2.0f,-2.0f, -2.0f);   
    glEnd();
   
    
    glRotatef(180,0,0,1);
    glTranslatef(-6,7,0);

	
	  glBegin(GL_TRIANGLES);
      glColor3f(0.37,0.48,0.55);           // Rouge
      glVertex3f( 2.0f, 1.0f, -2.0f);       // Haut du triangle (Droit)          // Bleu
      glVertex3f( 2.0f,-2.0f, 2.0f);       // Gauche du triangle (Droit)        // Vert
      glVertex3f( 2.0f,-2.0f, -2.0f);   
      glEnd();  
	  glPopMatrix();
}
void DrawRequinMarteau(void)
{
	
	glPushMatrix();
	glColor3f(0.37,0.48,0.55);
	glTranslatef(0,15,0);
	
	
    GLUquadricObj* params = gluNewQuadric();
    gluQuadricDrawStyle(params,GLU_FILL );
    gluCylinder(params,3,1.5,6,10,5);
    glRotatef(180,1,0,0);
    
    glTranslatef(0,0,-6);
    glRotatef(180,1,0,0);
    
    if(fabs(30-teta) < 0.000001)
    {
    	test2=1;
    }
    else
    {
    	if(fabs(-30-teta) < 0.000001)
    {
    	test2=0;
    }
    }
    if(test2==1)
    {
    	teta-=0.1;
    }
    else
    {
    	teta+=0.1;
    }
    
    glRotatef(teta,0,1,0);
    
    gluCylinder(params,1.5,1,2,10,5);
    glRotatef(-teta,0,1,0);
    
        if(fabs(30-lambda) < 0.000001)
    {
    	test3=1;
    }
    else
    {
    	if(fabs(-30-lambda) < 0.000001)
    {
    	test3=0;
    }
    }
    if(test3==1)
    {
    	lambda-=0.1;
    }
    else
    {
    	lambda+=0.1;
    }
    
    
    
    glRotatef(lambda,0,1,0);
    
    glTranslatef(0,0,2);
    gluCylinder(params,1,0.5,3,10,5);
    
     glTranslatef(-2,0,5);
     glTranslatef(0,2,0);
	  glBegin(GL_QUADS);  
	  glColor3f(0.37,0.48,0.55);          // Dessin d'un quadrilatère
      glVertex3f(2.0f, 2.0f, 0.5);    // Haut Gauche
      glVertex3f( 2.0f,-2.0f, 0.5);    // Haut Droite
      glVertex3f( 2.0f,-6.0f, 4);    // Bas Droite
      glVertex3f( 2.0f,-2.0f, -3.0f);    // Bas Gauche
      glEnd();                 
	  glPopMatrix(); 
	
	glRotatef(180, 1,0,0);
	glTranslatef(0,-12,0);
    
    glBegin(GL_TRIANGLES);
    glColor3f(0.37,0.48,0.55);          // Rouge
    glVertex3f( 5.0f, 2.0f, -2.0f);       // Haut du triangle (Droit)          // Bleu
    glTranslatef(0,0,6);
	glVertex3f( 2.0f,-2.0f, 2.0f);       // Gauche du triangle (Droit)        // Vert
    glVertex3f( 2.0f,-2.0f, -2.0f);      // D
    glEnd();
	 
	glTranslatef(-4,0,0);
      
    glBegin(GL_TRIANGLES);
    glColor3f(0.37,0.48,0.55);          // Rouge
    glVertex3f( -2.0f, 2.0f, -2.0f);       // Haut du triangle (Droit)          // Bleu
    glVertex3f( 2.0f,-2.0f, 2.0f);       // Gauche du triangle (Droit)        // Vert
    glVertex3f( 2.0f,-2.0f, -2.0f);   
    glEnd();
   
    
    glRotatef(180,0,0,1);
    glTranslatef(-6,7,0);

	
	  glBegin(GL_TRIANGLES);
      glColor3f(0.37,0.48,0.55);           // Rouge
      glVertex3f( 2.0f, 1.0f, -2.0f);       // Haut du triangle (Droit)          // Bleu
      glVertex3f( 2.0f,-2.0f, 2.0f);       // Gauche du triangle (Droit)        // Vert
      glVertex3f( 2.0f,-2.0f, -2.0f);   
      glEnd();  
	  

glTranslatef(2,-4,0);
gluCylinder(params,3,2,3,10,5);
glTranslatef(0,0,3);

if(rotMar>30)
{
	test6=1;
}
else
{
	if(rotMar<-30)
	{
		test6=2;
	}
}

if(test6==1)
{
	rotMar-=0.05;
}
else
{
	rotMar+=0.05;
}
glRotatef(rotMar,0,1,0);
gluCylinder(params,2,0.5,3,10,5);
glTranslatef(0,0,3);
glScalef(4,1.5,1);
glutSolidCube(2);               
glPopMatrix(); 

}
void Mousefunc ( int Button, int State, int X , int Y )
{
      switch (Button)
        {
        case GLUT_LEFT_BUTTON :
          switch (State)
    	{
    	case GLUT_DOWN :
    	  X_Start_Move = X;
    	  Y_Start_Move = Y;
    	  Move_Flag = GL_TRUE;
    	  break;
    	case GLUT_UP :
    	  Move_Flag = GL_FALSE;
    	  break;
    	}
          break;
        case GLUT_RIGHT_BUTTON :
          switch (State)
    	{
    	case GLUT_DOWN :
    	  Y_Start_Zoom = Y;
    	  Zoom_Flag = GL_TRUE;
    	  break;
    	case GLUT_UP :
    	  Zoom_Flag = GL_FALSE;
    	  break;
    	}
          break;
        case GLUT_MIDDLE_BUTTON :
          switch (State)
    	{
    	case GLUT_DOWN :
    	  break;
    	case GLUT_UP :
    	  break;
    	}
        }
}

void Mousemotionmove ( int X, int Y)
{
      Longitude = Longitude + (GLdouble)(X - X_Start_Move);
      Latitude = Latitude - (GLdouble)(Y - Y_Start_Move);
    
      X_Start_Move = X;
      Y_Start_Move = Y;
      glutPostRedisplay();
}

void Mousemotionzoom ( int X, int Y )
{
      Radius = Radius - (GLdouble)(Y - Y_Start_Zoom) / 10.0;
      Y_Start_Zoom = Y;
      glutPostRedisplay();
}
void Mousemove ( int X, int Y)
{
      if (Move_Flag)
        Mousemotionmove(X,Y);
      else
        if (Zoom_Flag)
          Mousemotionzoom(X,Y);
}



void DrawGrid(int nbCase, float taille)
{
	float l = taille/nbCase;
	float xmin=-taille/2;
	float ymin=-taille/2;
	float xmax=taille/2;
	float ymax=taille/2;
	float x,y;
	int a,b;
	a=0;
	for(x=xmin;x<=xmax;x+=l)
	{
	b=a;
		for(y=ymin;y<=ymax;y+=l)
		{
			b=b+1;
			if((b%2)==0)
			{
				glColor3f(0.9,0.86,0.5);
			}
			else
			{
				glColor3f(1,0.96,0.56);
			}
			
			 glBegin(GL_QUADS);
			 glVertex2f(x,y);
			 glVertex2f(x+l,y);
			 glVertex2f(x+l,y+l);
			 glVertex2f(x,y+l);
			 glEnd();
		}
	a=a+1;
	}
}


void Drawscene ( void )

{
 glEnable(GL_DEPTH_TEST); //Pour effet de profondeur    
        static GLfloat whiteColor[]={1.0,1.0,1.0};
        glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
        glColor3fv(whiteColor);
        glLoadIdentity(); // On ignore tout ce qu'il y a avant
        
        //-------------Champ de vision------------
        glTranslatef(0.0,0.0,-150.0);
        Polarview(Radius,Twist,Longitude,Latitude );
        DrawAxes();
        glPopMatrix();
        glPushMatrix();
 
 glTranslatef(0,120,0);
 glRotatef(90,1,0,0);
 glPopMatrix();
 
 glTranslatef(0,30,0); 
 glTranslatef(0,0,15);
 // deplacement requin//
 
    //distance par translation//
    	if(x<=70&&test4==0)
{
x+=0.01;	
}
else
{
	if(inc2>=90)
	{
inc+=1;
x=0;
test4=1;
inc2=0;
}
}

   //Vitesse de mouvement//
if(test4==0)
{
if(inc==0)
{
	posX-=0.01;
}
else
{
if(inc==1)
{
	posY+=0.01;
}
else
{
	if(inc==2)
	{
		posX+=0.01;
	}
	else
	{
		if(inc==3)
		{
			posY-=0.01;
		}
		else
		{
			if(inc==4)
			{
				inc=0;
			}
		}
	}
}
}
}
else
{
	inc2+=0.1;
	rot+=0.1;
}

if(inc2>=90)
{
	test4=0;
}


glTranslatef(posY,0,posX);
glRotatef(-rot,0,1,0);
glTranslatef(-posY,0,-posX);
glPushMatrix();
glTranslatef(5,4,0);
glPopMatrix();
glTranslatef(posY,0,posX);
DrawRequin();
glPopMatrix();

glLoadIdentity();
 glTranslatef(0.0,0.0,-150.0);
        Polarview(Radius,Twist,Longitude,Latitude );
        DrawAxes();
         glPushMatrix();
 glRotatef(90,1,0,0);
 
 glPopMatrix();
  //---------Rotations & Translation--------
   beta+=0.0050;
   gamma+=0.00001;
  glRotatef(beta, 0, 1, 0 );
  glTranslatef(0,0,70);
  glRotatef(90,0,1,0);
  glRotatef(gamma, 0,1,0);
  glTranslatef(0,0,-70);
  glTranslatef(0.0,0.0,70.0);
  glTranslatef(0,15,0);
DrawBanc(4,9);
glPopMatrix();
glLoadIdentity();

        glTranslatef(0.0,0.0,-150.0);
        Polarview(Radius,Twist,Longitude,Latitude );
        DrawAxes();
 glRotatef(90,1,0,0);
 DrawGrid(5,200);
 glPushMatrix();
 glTranslatef(0,15,0);
 glRotatef(-90,1,0,0);
 glTranslatef(0,-15,0);
 glTranslatef(-30,15,15);
 
 // deplacement requin//
 
    //distance par translation//
    	if(x2<=200&&test5==0)
{
x2+=0.01;	
}
else
{
	if(inc3>=90)
	{
incM+=1;
x2=0;
test5=1;
inc3=0;
}
}

   //Vitesse de mouvement//
if(test5==0)
{
if(incM==0)
{
	posX2-=0.005;
}
else
{
if(incM==1)
{
	posY2+=0.005;
}
else
{
	if(incM==2)
	{
		posX2+=0.005;
	}
	else
	{
		if(incM==3)
		{
			posY2-=0.005;
		}
		else
		{
			if(incM==4)
			{
				incM=0;
			}
		}
	}
}
}
}
else
{
	inc3+=0.1;
	rot2+=0.1;
}

if(inc3>=90)
{
	test5=0;
}


glTranslatef(posY2,0,posX2);
glRotatef(-rot2,0,1,0);
glTranslatef(-posY2,0,-posX2);
glPushMatrix();
glTranslatef(5,4,0);
glPopMatrix();
glTranslatef(posY2,0,posX2);
 DrawRequinMarteau();
 glPopMatrix();
 DrawCoffre();
 glPopMatrix();
 glPushMatrix();
 glTranslatef(0,-30,-2);
 DrawAlgue();
 glTranslatef(0,-2,0);
 DrawAlgue();
 glTranslatef(0,-30,0);
 DrawAlgue();
 glTranslatef(-5,0,0);
  DrawAlgue();
  glTranslatef(0,-4,0);
  DrawAlgue();
 glPopMatrix();
 glPushMatrix();
 glTranslatef(-30,0,-2);
  DrawAlgue();
  glTranslatef(0,-6,0);
  DrawAlgue();
  glTranslatef(0,-6,0);
  DrawAlgue();
  glTranslatef(-3,0,0);
  DrawAlgue();
  glTranslatef(0,6,0);
  DrawAlgue();
   glTranslatef(0,6,0);
  DrawAlgue();
  glTranslatef(-3,-2,0);
  DrawAlgue();
  glTranslatef(0,-6,0);
  DrawAlgue();
glPopMatrix();
 glPushMatrix();
 glTranslatef(50,0,-2);
 DrawAlgue();
glPopMatrix();
 DrawEpave();
 glPopMatrix();
 glPopMatrix();
 glutSwapBuffers();
 
}

				             
