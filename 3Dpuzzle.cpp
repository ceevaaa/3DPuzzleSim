
#include <stdlib.h>
#include <GL/glut.h>
#include <math.h>

// coordinates for cube
GLfloat vertices[][3] = {{-1.0,-1.0,-1.0},{1.0,-1.0,-1.0},
        				{1.0,1.0,-1.0}, {-1.0,1.0,-1.0}, {-1.0,-1.0,1.0},
       					{1.0,-1.0,1.0}, {1.0,1.0,1.0}, {-1.0,1.0,1.0}};

//coordinated for triangle/tetrahedron
typedef float point[3];
point v[]={{0.0,0.0,1.0},{0.0,1.0,0.0},{-1.0,-0.5,0.0}, {1.0,-0.5,0.0}};
int reset=0;

//Axis declaration for all objects
static GLfloat thetabox[] = {0.0,0.0,0.0};
static GLint axisbox ;

static GLfloat thetacube[] = {0.0,0.0,0.0};
static GLint axiscube ;

static GLfloat thetasphere[] = {0.0,0.0,0.0};
static GLint axissphere ;

static GLfloat thetatriangle[] = {0.0,0.0,0.0};
static GLint axistriangle ;

	float CIRCLE_RADIUS = 1.0f;
	int circle_points = 100;
	float PI=3.1415;
    double angle = 2*  PI/circle_points ;
	double angle1 = 0.0;
	
// draw a polygon via list of vertices 
void polygon(int a, int b, int c , int d){
    glBegin(GL_POLYGON);
 	  	glVertex3fv(vertices[a]);
        glVertex3fv(vertices[b]);
        glVertex3fv(vertices[c]);
        glVertex3fv(vertices[d]);
    glEnd();
}

//Create box for adding elements in
void box(void){
	if(reset==3){
		glColor3f(1.0,1.0,1.0);
		polygon(0,3,2,1);
		glColor3f(1.0,0.0,0.0);
		polygon(2,3,7,6);
        glColor3f(0.0,1.0,0.0);
		polygon(0,4,7,3);
		glColor3f(0.0,0.0,1.0);
        polygon(1,2,6,5);
        glColor3f(1.0,1.0,0.0);
        polygon(0,1,5,4);
	}
	else{
        glColor3f(1.0,1.0,1.0);
		polygon(0,3,2,1);
		glColor3f(1.0,0.0,0.0);
		polygon(2,3,7,6);
        glColor3f(0.0,1.0,0.0);
		polygon(0,4,7,3);
		glColor3f(0.0,0.0,1.0);
        polygon(1,2,6,5);
        glColor3f(1.0,1.0,0.0);
        polygon(0,1,5,4);
        glColor3f(1.0,0.0,1.0);
        polygon(4,5,6,7);
        
        //Hole for cube
        glPushMatrix();
		glTranslatef(-0.45,0.45,0.77);
        glScalef(0.25,0.25,0.25);
        glColor3f(1.0,1.0,1.0);
		polygon(4,5,6,7);
		glPopMatrix();

		//Hole for triangle
		glPushMatrix();
		glTranslatef(0.0,-0.45,1.01);
        glScalef(0.25,0.25,0.25);
        glColor3f(1.0,1.0,1.0);
		glBegin(GL_POLYGON);
			glVertex3fv(v[3]);
		  	glVertex3fv(v[2]);
		  	glVertex3fv(v[1]);
		glEnd();
		glPopMatrix();
		
		
		//Hole for circle
		glPushMatrix();
		glTranslatef(0.45,0.45,1.001);
        glScalef(0.25,0.25,0.25);
        glColor3f(1.0,1.0,1.0);
	    glBegin(GL_POLYGON);        
	    glVertex2d( CIRCLE_RADIUS * cos(0.0) , CIRCLE_RADIUS * sin(0.0));
	    for (int i = 0; i < circle_points; i++)
	    {
	        glVertex2d(CIRCLE_RADIUS * cos(angle1), CIRCLE_RADIUS *sin(angle1));
	        angle1 += angle ;
	    }
	    glEnd();
    	glPopMatrix();

	}
}

//Create object cube
void cube(void)
{
        glColor3f(1.0,0.0,0.0);
		polygon(0,3,2,1);
        glColor3f(0.0,1.0,0.0);
		polygon(2,3,7,6);
		glColor3f(0.0,0.0,1.0);
        polygon(0,4,7,3);
        glColor3f(1.0,1.0,0.0);
        polygon(1,2,6,5);
        glColor3f(0.0,1.0,1.0);
        polygon(4,5,6,7);
        glColor3f(1.0,0.0,1.0);
        polygon(0,1,5,4);
}

//Display created Box
void displaybox(void)         
{
	glTranslatef(0.0,0.5,0.0);
	glScalef(1.1,1.1,1.1);
	glRotatef(thetabox[0], 1.0, 0.0, 0.0);
    glRotatef(thetabox[1], 0.0, 1.0, 0.0);
    glRotatef(thetabox[2], 0.0, 0.0, 1.0);
	box();
}

//Display created Cube
void displaycube(void)
{	
	//changing position of cube 
	if(reset==0){
		glTranslatef(-2.0,1.0,5.0); 
	}
	else if(reset==1)
	{
		glTranslatef(-1.0,1.0,5.0);
	}
	else if(reset==2){
		glTranslatef(-0.5,1.0,5.0);
	}
	else if(reset==3){
		glTranslatef(-0.5,1.0,0.0);
	}

	glRotatef(thetacube[0], 1.0, 0.0, 0.0);
    glRotatef(thetacube[1], 0.0, 1.0, 0.0);
    glRotatef(thetacube[2], 0.0, 0.0, 1.0);
	glScalef(0.25,0.25,0.25);//changing sixe/scale of cube
 	cube(); 
}

void displaysphere(void)
{
	glColor3f(1.0,0.0,0.0);	
	//changing position of sphere
	if(reset==0){
		glTranslatef(2.0,1.0,5.0);  
	}
	else if(reset==1){
		glTranslatef(1.0,1.0,5.0);
	}
	else if(reset==2){
		glTranslatef(0.5,1.0,5.0);
	}
	else if(reset==3){
		glTranslatef(0.5,1.0,0.0);
	}
    glRotatef(thetasphere[0], 1.0, 0.0, 0.0);
    glRotatef(thetasphere[1], 0.0, 1.0, 0.0);
    glRotatef(thetasphere[2], 0.0, 0.0, 1.0);
	glScalef(0.25,0.25,0.25);
	glutSolidSphere( 1.0,  20,  20);
}

void displaytriangle(void)
{
	//changing position of triangle 
	if(reset==0){
		glTranslatef(0.0,-1.5,5.0); 
	}
	else if(reset==1){
		glTranslatef(0.0,-0.5,5.0);
	}
	else if(reset==2){
		glTranslatef(0.0,0.0,5.0);
	}
	else if(reset==3){
		glTranslatef(0.0,0.0,0.0);
	}
	glRotatef(thetatriangle[0], 1.0, 0.0, 0.0);
    glRotatef(thetatriangle[1], 0.0, 1.0, 0.0);
    glRotatef(thetatriangle[2], 0.0, 0.0, 1.0);
 	glScalef(0.25,0.25,0.25);


	glBegin(GL_POLYGON);
	  glColor3f(1.0,0.0,0.0);
	  glVertex3fv(v[0]);
	  glVertex3fv(v[1]);
	  glVertex3fv(v[2]);
	glEnd();
	
	glBegin(GL_POLYGON);
	  glColor3f(0.0,1.0,0.0);
	  glVertex3fv(v[3]);
	  glVertex3fv(v[2]);
	  glVertex3fv(v[1]);
	glEnd();
	
	glBegin(GL_POLYGON);
	  glColor3f(0.0,0.0,1.0);
	  glVertex3fv(v[0]);
	  glVertex3fv(v[3]);
	  glVertex3fv(v[1]);
	glEnd();
 	
 	glBegin(GL_POLYGON);
	  glColor3f(0.0,1.0,1.0);
	  glVertex3fv(v[0]);
	  glVertex3fv(v[2]);
	  glVertex3fv(v[3]);
	glEnd();
	
}

void display(void)
{
/* display callback, clear frame buffer and z buffer,
   rotate cube and draw, swap buffers */

   glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
   glLoadIdentity();
   
glPushMatrix();
   displaybox();
    glPopMatrix();

    glPushMatrix();
    displaycube();
    glPopMatrix();
	
   glPushMatrix();
   displaysphere();
   glPopMatrix();
	
   glPushMatrix();
   displaytriangle();
   glPopMatrix();
	
   glFlush();
   glutSwapBuffers();
}

void keys(unsigned char key, int x, int y)
{
	// keys for box movement
	if(key == 'a') 
	{
		axisbox=0;
	    thetabox[axisbox] += 1.0;
        if( thetabox[axisbox] > 360.0 ) thetabox[axisbox] -= 360.0;
	}
	if(key == 's') 
	{
		axisbox=1;
	    thetabox[axisbox] += 1.0;
        if( thetabox[axisbox] > 360.0 ) thetabox[axisbox] -= 360.0;
	}
	if(key == 'd') 
	{
		axisbox=2;
	    thetabox[axisbox] += 1.0;
        if( thetabox[axisbox] > 360.0 ) thetabox[axisbox] -= 360.0;
	}
	// keys for cube movement
	if(key == 'q') 
	{
		axiscube=0;
	    thetacube[axiscube] += 1.0;
        if( thetacube[axiscube] > 360.0 ) thetacube[axiscube] -= 360.0;
	}
	if(key == 'w') 
	{
		axiscube=1;
	    thetacube[axiscube] += 1.0;
        if( thetacube[axiscube] > 360.0 ) thetacube[axiscube] -= 360.0;
	}
	if(key == 'e') 
	{
		axiscube=2;
	    thetacube[axiscube] += 1.0;
        if( thetacube[axiscube] > 360.0 ) thetacube[axiscube] -= 360.0;
	}	
	// keys for sphere movement
	if(key == 'r') 
	{
		axissphere=0;
	    thetasphere[axissphere] += 1.0;
        if( thetasphere[axissphere] > 360.0 ) thetasphere[axissphere] -= 360.0;
	}
	if(key == 't') 
	{
		axissphere=1;
	    thetasphere[axissphere] += 1.0;
        if( thetasphere[axissphere] > 360.0 ) thetasphere[axissphere] -= 360.0;
	}
	if(key == 'y') 
	{
		axissphere=2;
	    thetasphere[axissphere] += 1.0;
        if( thetasphere[axissphere] > 360.0 ) thetasphere[axissphere] -= 360.0;
	}
	// keys for triangle movement
	if(key == 'u') 
	{
		axistriangle=0;
	    thetatriangle[axistriangle] += 1.0;
        if( thetatriangle[axistriangle] > 360.0 ) thetatriangle[axistriangle] -= 360.0;
	}
	if(key == 'i') 
	{
		axistriangle=1;
	    thetatriangle[axistriangle] += 1.0;
        if( thetatriangle[axistriangle] > 360.0 ) thetatriangle[axistriangle] -= 360.0;
	}
	if(key == 'o') 
	{
		axistriangle=2;
	    thetatriangle[axistriangle] += 1.0;
        if( thetatriangle[axistriangle] > 360.0 ) thetatriangle[axistriangle] -= 360.0;
	}
	//To Move the objects into the box
	if(key == 'p') 
	{
		reset++;
	
		thetatriangle[0] = 0;
		thetatriangle[1] = 0;
		thetatriangle[2] = 0;
		thetacube[0] = 0;
		thetacube[1] = 0;
		thetacube[2] = 0;
		thetasphere[0] = 0;
		thetasphere[1] = 0;
		thetasphere[2] = 0;
		thetabox[0] = 0;
		thetabox[1] = 0;
		thetabox[2] = 0;
	
		if(reset>3)
			reset=0;
	}
		glutPostRedisplay();

}

void myReshape(int w, int h)
{
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    if (w <= h)
        glOrtho(-2.0, 2.0, -2.0 * (GLfloat) h / (GLfloat) w,2.0 * (GLfloat) h / (GLfloat) w, -10.0, 10.0);
    else
        glOrtho(-2.0 * (GLfloat) w / (GLfloat) h,2.0 * (GLfloat) w / (GLfloat) h, -2.0, 2.0, -10.0, 10.0);
    glMatrixMode(GL_MODELVIEW);
}


int main(int argc, char **argv)
{
    glutInit(&argc, argv);
/* need both double buffering and z buffer */
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(1920,1080);
    glutCreateWindow("CG Mini Project");
    glutReshapeFunc(myReshape);
    glutDisplayFunc(display);
    glutKeyboardFunc(keys);
    glEnable(GL_DEPTH_TEST); /* Enable hidden--surface--removal */
    glutMainLoop();
}


 

 







 