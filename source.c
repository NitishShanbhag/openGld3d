#include <stdio.h>
#include <math.h>
#include <GL/glut.h>
#define ROT_INC         0.1
#define TRS_INC         0.5
#define GL_PI 3.1415f
GLfloat fogDensity = 55555.0;
static int s=0;
double animation = 0.0;
static GLfloat fog_color[] = {0.8, 0.8, 0.8, 1.0};
GLfloat fLightPos[4]   = { -100.0f, 100.0f, 50.0f, 1.0f };  // Point source
GLfloat fLightPos1[4]   = { 100.0f, -100.0f, 50.0f, 1.0f };  // Point source
GLfloat fLightPosMirror[4] = { -100.0f, -100.0f, 50.0f, 1.0f };
GLfloat fNoLight[] = { 0.0f, 0.0f, 0.0f, 0.0f };
GLfloat fLowLight[] = { 0.50f, 0.50f, 0.50f, 1.0f };
GLfloat fBrightLight[] = { 1.0f, 1.0f, 1.0f, 1.0f };
static GLfloat g_rotate = 0;
static GLfloat g_rotInc = ROT_INC;
static GLfloat g_trns=0;
void drawButterFly(void);
static void (*drawPrimP)(void) = drawButterFly; //initial
static int x=1,y=1,z=1;
GLfloat teta;
void drawSphere(void)
{
	glColor3f(0.0,0.0,0.0);
	glutWireSphere(5.5,30,30);
}
void drawCube(void)
{
	glColor3f(0.0,0.0,1.0);
	glutWireCube(7.0);
}
void drawCone(void)
{
	glColor3f(-0.5,1.0,-0.5);
	glutWireCone(5.0, 6.0, 30, 30);
}

void drawTorus(void)
{	
	glColor3f(0.5,0.0,1.5);
	glutWireTorus(1.0, 6.0, 10, 20);
}
void drawIcos(void)
{
	glColor3f(1.0,0.0,0.0);
	glPushMatrix();
	glScalef(6.0,6.0,6.0);
	glutWireIcosahedron();
	glPopMatrix();
}
void drawTeapot(void)
{
	glColor3f(1.0,0.0,1.0);
	glutWireTeapot(3.80);
}
void drawCuboid(void)
{
	glColor3f(1.5,0.0,0.5);
	glPushMatrix();
	glScalef(2.0f, 1.0f, 2.0f);
	glutWireCube(5.0);
	glPopMatrix();
}
void drawDodeca(void)
{
	glColor3f(1.75,0.0,1.0);
	glPushMatrix();
	glScalef(3.0,3.0,3.0);
	glutWireDodecahedron();
	glPopMatrix();
}
void drawOcta(void)
{
	glColor3f(0.8,0.5,0.5);
	glPushMatrix();
	glScalef(6.0,6.0,6.0);
	glutWireOctahedron();
	glPopMatrix();
}
void drawTetra(void)
{
	glColor3f(1.0,0.5,0.0);
	glPushMatrix();
	glScalef(6.0,6.0,6.0);
	glutWireTetrahedron();
	glPopMatrix();
 
}
void drawSDodeca(void)
{
	glColor3f(0.0,1.0,0.0);
	glPushMatrix();
	glScalef(6.0,6.0,6.0);
	glBegin(GL_POLYGON);
	teta=(g_rotate/50);
	glVertex2f(cos(teta),sin(teta));
	glVertex2f(-sin(teta),cos(teta));
	glVertex2f(-cos(teta),-sin(teta));
	glVertex2f(sin(teta),-cos(teta));
	glEnd();
	glPopMatrix();
}
void drawSTetra(void)
{
	glColor3f(0.3,0.8,0.5);
	glPushMatrix();
	glScalef(6.0,6.0,6.0);
	glutSolidTetrahedron();
	glPopMatrix();
}
void drawSOcta(void)
{
	glColor3f(0.5,0.0,0.0);
	glPushMatrix();
	glScalef(6.0,6.0,6.0);
	glutSolidOctahedron();
	glPopMatrix();
}
void drawSCuboid(void)
{
	glColor3f(0.5,0.0,0.5);
	glPushMatrix();
	glScalef(2.0f, 1.0f, 2.0f);
	glutSolidCube(4.5);
	glPopMatrix();
}
void drawSTeapot(void)
{
	glColor3f(0.5,0.5,0.0);
	glutSolidTeapot(3.80);
}
void drawSIcos(void)
{
	glColor3f(0.8,0.5,0.5);
	glPushMatrix();
	glScalef(6.0,6.0,6.0);
	glutSolidIcosahedron();
	glPopMatrix();
}
void drawSTorus(void)
{
	glColor3f(1.0,0.5,0.0);
	glutSolidTorus(1.0, 5.0, 10, 20);
}
void drawSCone(void)
{
	glColor3f(1.5,0.0,0.2);
	glutSolidCone(5.0, 6.0, 30, 30);
}
void drawSSphere(void)
{
	glColor3f(0.5,0.0,1.0);
	glutSolidSphere(5.5,30,30);
}
void drawSCube(void)
{
	glColor3f(0.5,1.0,0.5);
	glutSolidCube(7.0);
}
void drawButterFly(void)
{
  int i;
  double e = 2.71828182845904523536;
  double power;
  double green, blue, red;
  double x, y, z;
  glBegin(GL_POINTS);
  for(i = 0; i < 10000; i++){
    power = pow(e, cos(i));
    x = sin(i)*(power-2*cos(4*i)-(sin(i/12)*sin(i/12)*sin(i/12)*sin(i/12)*sin(i/12)));
    y = cos(i)*(power-2*cos(4*i)-(sin(i/12)*sin(i/12)*sin(i/12)*sin(i/12)*sin(i/12)));
                if (x < 0.5 && x > -0.5){
                        if(i%2 == 0){
                                z = (x*x)-0.25;
                        } else {
                                z = -(x*x)+0.25;
                        }
                } else {
        z = animation*(x*x);
                }
                blue = cos(i/x);
                green = pow(e, cos(i/y));

    glColor3f(1, blue, green);
    glVertex3f(x, y, z);
  }
  glEnd();
  glFlush();
}
void setPrim(int value)
 {
	switch(value) {
	case 1:
		drawPrimP = drawSphere;
		break;
	case 2:
		drawPrimP = drawCube;
		break;
	case 3:
		drawPrimP = drawCone;
		break;
	case 4:
		drawPrimP = drawTorus;
		break;
	case 5:
		drawPrimP = drawIcos;
		break;
	case 6:
		drawPrimP = drawTeapot;
		break;
	case 7:
		drawPrimP = drawCuboid;
		break;
	case 8:
		drawPrimP = drawDodeca;
		break;
	case 9:
		drawPrimP = drawOcta;
		break;
	case 10:
		drawPrimP = drawTetra;
		break;
	case 11:
		drawPrimP = drawSSphere;
		break;
	case 12:
		drawPrimP = drawSCube;
		break;
	case 13:
		drawPrimP = drawSCone;
		break;
	case 14:
		drawPrimP = drawSTorus;
		break;
	case 15:
		drawPrimP = drawSIcos;
		break;
	case 16:
		drawPrimP = drawSTeapot;
		break;
	case 17:
		drawPrimP = drawSCuboid;
		break;
	case 18:
		drawPrimP = drawSDodeca;
		break;
	case 19:
		drawPrimP = drawSOcta;
		break;
	case 20:
		drawPrimP = drawSTetra;
		break;
	case 21:
		drawPrimP =drawButterFly;
		break;
	
	default:
		fprintf(stderr, "3dPrim: unknown menu option %d\n", value);
		break;
	}
}
void keys(unsigned char key,int x,int y)
{
	if(key=='z')
	{
		z=((++z)%2);
	}
	if(key=='q')
	{
		exit(0);
	}
	if(key=='s')
	{ 
		if(s==0)
		{
			g_rotInc=0.1;
		}
		else
		{
			 g_rotInc=0.0;
		}
		s=((++s)%2);	
	}
	if(key=='d')
	{
    		fogDensity *= 1.10;
    		glFogf(GL_FOG_DENSITY, fogDensity);
    		glutPostRedisplay();
    	}
  	if(key=='l')
	{
    		fogDensity /= 1.10;
    		glFogf(GL_FOG_DENSITY, fogDensity);
    		glutPostRedisplay();
    	}
		
}
void spec_keys(int key,int x,int y)
{
	if(key == GLUT_KEY_UP)
	{		
		g_rotInc += ROT_INC;
	}	
	if(key == GLUT_KEY_DOWN)
	{
		g_rotInc -= ROT_INC;
	}
	 if(key == GLUT_KEY_LEFT)
        {
                g_trns -= TRS_INC;
        }
	 if(key == GLUT_KEY_RIGHT)
        {
                g_trns += TRS_INC;
        }

}
void DrawWorld(void)
{
    
    glPushMatrix();
        glTranslatef(g_trns, 10.0f, -9.0f);
         glRotatef(g_rotate,x,y,z);
       (*drawPrimP)();

    glPopMatrix();
}
void DrawGround(void)
{
    GLfloat fExtent = 20.0f;
    GLfloat fStep = 0.5f;
    GLfloat y = 0.0f;
    GLfloat fColor;
    GLfloat iStrip, iRun;
    GLint iBounce = 0;
    
    glShadeModel(GL_FLAT);
    for(iStrip = -fExtent; iStrip <= fExtent; iStrip += fStep)
        {
        glBegin(GL_TRIANGLE_STRIP);
            for(iRun = fExtent; iRun >= -fExtent; iRun -= fStep)
                {
                if((iBounce %2) == 0)
                    fColor = 1.0f;
                else
                    fColor = 0.0f;
                    
                glColor4f(fColor, fColor, fColor, 0.5f);
                glVertex3f(iStrip, y, iRun);
                glVertex3f(iStrip + fStep, y, iRun);
                
                iBounce++;
                }
        glEnd();
        }
    glShadeModel(GL_SMOOTH);
}
void display(void)
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
 	glPushMatrix();
        // Move light under floor to light the "reflected" world
        glLightfv(GL_LIGHT0, GL_POSITION, fLightPosMirror);
	glLightfv(GL_LIGHT1, GL_POSITION, fLightPosMirror);
        glPushMatrix();
            glFrontFace(GL_CW);             // geometry is mirrored, swap orientation
           glScalef(1.0f, -1.0f, 1.0f);
		
	DrawWorld();
   
            glFrontFace(GL_CCW);
        glPopMatrix();
    
        // Draw the ground transparently over the reflection
        glDisable(GL_LIGHTING);
        glEnable(GL_BLEND);
        glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
        DrawGround();
        glDisable(GL_BLEND);
        glEnable(GL_LIGHTING);
        
        // Restore correct lighting and draw the world correctly
        glLightfv(GL_LIGHT0, GL_POSITION, fLightPos);
	glLightfv(GL_LIGHT1, GL_POSITION, fLightPos1);
		
	DrawWorld();
	
    glPopMatrix();
        
    // Do the buffer Swap
    glutSwapBuffers();
    
	
}

void SetupRC()
{
    // Grayish background
	glClearColor(fLowLight[0], fLowLight[1], fLowLight[2], fLowLight[3]);
   //Cull backs of polygons
   glCullFace(GL_BACK);
    glFrontFace(GL_CCW);
   glEnable(GL_CULL_FACE);
   glEnable(GL_DEPTH_TEST);
    
	// Setup light parameters for light zero
			glLightModelfv(GL_LIGHT_MODEL_AMBIENT, fNoLight);
			glLightfv(GL_LIGHT0, GL_AMBIENT, fLowLight);
			glLightfv(GL_LIGHT0, GL_DIFFUSE, fBrightLight);
			glLightfv(GL_LIGHT0, GL_SPECULAR, fBrightLight);
			glEnable(GL_LIGHTING);
			glEnable(GL_LIGHT0);

	// Setup light parameters for light 0ne
			glLightModelfv(GL_LIGHT_MODEL_AMBIENT, fNoLight);
			glLightfv(GL_LIGHT1, GL_AMBIENT, fLowLight);
			glLightfv(GL_LIGHT1, GL_DIFFUSE, fBrightLight);
			glLightfv(GL_LIGHT1, GL_SPECULAR, fBrightLight);
			glEnable(GL_LIGHTING);
			glEnable(GL_LIGHT1);
	//Setup Fog parameters
			 glEnable(GL_FOG);
			 glFogi(GL_FOG_MODE, GL_EXP);
			 glFogf(GL_FOG_DENSITY, fogDensity);
             glFogfv(GL_FOG_COLOR, fog_color);
             glClearColor(0.8, 0.8, 0.8, 1.0);
    // Mostly use material tracking

    glEnable(GL_COLOR_MATERIAL);
    glColorMaterial(GL_FRONT, GL_AMBIENT_AND_DIFFUSE);
    glMateriali(GL_FRONT_AND_BACK, GL_SHININESS, 50000);
}

void myReshape(int w, int h)
{
 GLfloat fAspect;

    // Prevent a divide by zero, when window is too short
    // (you cant make a window of zero width).
    if(h == 0)
        h = 1;

    glViewport(0, 0, w, h);
        
    fAspect = (GLfloat)w / (GLfloat)h;

    // Reset the coordinate system before modifying
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
	
    // Set the clipping volume
    gluPerspective(60.0f, fAspect, 0.1f, 40.0f);
        
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();    
   glTranslatef(0.0f, -0.6f, -21.0f);
}
void myIdleFunc(void) {

	g_rotate += g_rotInc;

	/* force glut to call the display function */
	glutPostRedisplay();
}
int main(int argc, char **argv)
{
	int nSolidMenu;
	int nWireMenu;
	int nMainMenu;
	/* glutInit MUST be called before any other GLUT/OpenGL calls */
    glutInit(&argc, argv);

	/* set double buffering, note no z buffering */
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);
    glutInitWindowSize(1366,768);
    glutCreateWindow("Phong_Reflection_Model");
	 glutReshapeFunc(myReshape);
    glutDisplayFunc(display);
	glutIdleFunc(myIdleFunc);
	SetupRC();
	glutKeyboardFunc(keys);

	nWireMenu = glutCreateMenu(setPrim);
	// Create the Menu
	//glutCreateMenu();
	glutAddMenuEntry("Sphere",1);
	glutAddMenuEntry("Cube",2);
	glutAddMenuEntry("Cone",3);
	glutAddMenuEntry("Torus",4);
	glutAddMenuEntry("Icosahedron",5);
	glutAddMenuEntry("Teapot",6);
	glutAddMenuEntry("Cuboid",7);
	glutAddMenuEntry("Dodecahedron",8);
	glutAddMenuEntry("Octahedron",9);
	glutAddMenuEntry("Tetrahedron",10);
	nSolidMenu = glutCreateMenu(setPrim);
	glutAddMenuEntry("Sphere",11);
	glutAddMenuEntry("Cube",12);
	glutAddMenuEntry("Cone",13);
	glutAddMenuEntry("Torus",14);
	glutAddMenuEntry("Icosahedron",15);
	glutAddMenuEntry("Teapot",16);
	glutAddMenuEntry("Cuboid",17);
	glutAddMenuEntry("Dodecahedron",18);
	glutAddMenuEntry("Octahedron",19);
	glutAddMenuEntry("Tetrahedron",20);
	glutAddMenuEntry("Butterfly",21);
	nMainMenu = glutCreateMenu(setPrim);
	glutAddSubMenu("Wire_Frame", nWireMenu);
   	glutAddSubMenu("Solid_Structure", nSolidMenu);
	glutAttachMenu(GLUT_RIGHT_BUTTON);
	
	
	glutSpecialFunc(spec_keys);
	
	/* set callback functions */
   

	glClearColor(1.0, 1.0, 1.0, 1.0);

	/* set current colour to black */
	glColor3f(0.0, 0.0, 0.0);
	glEnable(GL_LIGHTING);
	glEnable(GL_NORMALIZE);
	glEnable(GL_COLOR_MATERIAL);
	glEnable(GL_POLYGON_SMOOTH);
	
	
	
    glutMainLoop();
	 
	return 0;
}





