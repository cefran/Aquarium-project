#include <GL/glut.h>

void Drawscene ( void );
void DrawAxes(void);
void Polarview ( GLdouble Radius,GLdouble Twist,GLdouble Longitude,GLdouble Latitude );
void Mousefunc ( int Button, int State, int X , int Y );
void Mousemove ( int X, int Y);

void Mousemotionmove ( int X, int Y);
void Mousemotionzoom ( int X, int Y );
