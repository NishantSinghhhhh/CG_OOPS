#include<iostream>
#include<stdlib.h>
#include<windows.h>
#ifdef __APPLE__
#include<openGL/openGL.h>
#include<GLUT/glut.h>
#else
#include<GL/glut.h>
#include<math.h>
#endif

using namespace std;
float x=0.0,y=0.0,x1=5.0;
float ballX = -0.9f;
float ballY = -0.1f;
float ballZ = -1.2f;
float colR=1.0;
float colG=0.25;
float colB=0.0;
float bgColR=0.0;
float bgColG=0.0;
float bgColB=0.0,r1=0.01;
float sr=1.0, sg=1.0, sb = 1.0;
float sr1=1.0, sg1=1.0, sb1 = 1.0;
float sr2=1.0, sg2=1.0, sb2 = 1.0;
int stoggle = 0;
int stoggle1 = 0;
int stoggle2 = 0;

static int flag=0,flag1=1;



void cloudupdate()
{
    x+=0.001;
    x1-=0.002;
    if(x>6)
        {
            x=-6;
            x1=4;
    }
}

void drawClouds()
{

glTranslatef(x1,y,-5.0);
    glBegin(GL_POLYGON);

        glColor3f(1.0,1.0,1.0);

         glVertex3f(1.0,0.7,-5.0);
        glVertex3f(1.5,1.0,-5.0);

        glVertex3f(0.5,1.5,-5.0);

        glVertex3f(0.0,2.0,-5.0);

        glVertex3f(-0.7,0.5,-5.0);

        glVertex3f(-1.0,1.6,-5.0);

        glVertex3f(-1.5,1.0,-5.0);

        glVertex3f(-0.5,0.7,-5.0);

        glVertex3f(-1.0,0.5,-5.0);
    glEnd();
    glPopMatrix();

    glPushMatrix();

    glTranslatef(x,y,-5.0);

    glBegin(GL_POLYGON);

        glColor3f(0.8,0.75,1);

        glVertex3f(1.0,0.7,-5.0);

        glVertex3f(1.5,1.0,-5.0);

        glVertex3f(0.7,1.5,-5.0);

        glVertex3f(0.0,2.0,-5.0);

        glVertex3f(-0.7,1.5,-5.0);

        glVertex3f(-1.4,1.6,-5.0);

        glVertex3f(-1.7,1.0,-5.0);

        glVertex3f(-1.5,0.7,-5.0);

        glVertex3f(-1.0,0.5,-5.0);

    glEnd();

    glPopMatrix();



if(!flag)
{
glColor3f(0.45,0.77,0.34);
glBegin(GL_LINES);
glLineWidth(0.7);
        glVertex3f(0.45,0.20,-1.0);

        glVertex3f(0.43,0.180,-1.0);
glBegin(GL_LINES);
        glVertex3f(0.43,0.180,-1.0);
        glVertex3f(0.40,0.20,-1.0);
        //glVertex3f(-0.15,-0.03,-1.0);
        glEnd();

glBegin(GL_LINES);
glLineWidth(0.7);
        glVertex3f(0.05,0.20,-1.0);

        glVertex3f(0.03,0.180,-1.0);
glBegin(GL_LINES);
        glVertex3f(0.03,0.180,-1.0);
        glVertex3f(0.00,0.20,-1.0);
        //glVertex3f(-0.15,-0.03,-1.0);
        glEnd();


glBegin(GL_LINES);
glLineWidth(0.7);
        glVertex3f(-0.45,0.20,-1.0);

        glVertex3f(-0.43,0.180,-1.0);
glBegin(GL_LINES);
        glVertex3f(-0.43,0.180,-1.0);
        glVertex3f(-0.40,0.20,-1.0);
        //glVertex3f(-0.15,-0.03,-1.0);
        glEnd();

glColor3f(0.75,1.0,0.3);

glBegin(GL_LINES);
glLineWidth(5.0);
        glVertex3f(-0.25,0.10,-1.0);

        glVertex3f(-0.23,0.080,-1.0);
glBegin(GL_LINES);
glLineWidth(50.0);
        glVertex3f(-0.23,0.080,-1.0);
        glVertex3f(-0.20,0.10,-1.0);
        //glVertex3f(-0.15,-0.03,-1.0);
        glEnd();
}


    glBegin(GL_POLYGON);

        glColor3f(1.0,1.0,1.5);

        glVertex3f(-2.0,-2.0,-5.0);
        glVertex3f(-1.0,-1.5,-5.0);
        glVertex3f(0.0,0.0,-5.0);
        glVertex3f(2.0,-2.0,-5.0);
        glVertex3f(1.2,-1.5,-5.0);

    glEnd();

    cloudupdate();

    //glutSwapBuffers();

}

void drawBall(void) {

        glColor3f(colR,colG,colB); //set ball colour
        glTranslatef(ballX,ballY,ballZ); //moving it toward the screen a bit on creation
        glutSolidSphere (0.05, 30, 30); //create ball.

}

float car_x = -0.65, car_y = -0.23, car_x1= 0.65, car_y1 = -0.26;

void carupdate()
{
    car_x+= 0.002;
    car_x1-= 0.002;

    if(car_x > 0.7){
        car_x = -0.7;
        car_x1 = 0.7;
    }

    stoggle += 1;
    stoggle1 += 1;
    stoggle2 += 1;

    if(stoggle > 20) {
        if(sr == 1.0) {
            sr=sg=sb=0.6;

        } else {
            sr=sb=sg=1.0;
        }

        stoggle = 0;
    }

    if(stoggle1 > 30) {
        if(sr == 1.0) {
            sr1=sg1=sb1=0.6;

        } else {
            sr1=sb1=sg1=1.0;
        }

        stoggle1 = 0;
    }

    if(stoggle2 > 10) {
        if(sr == 1.0) {
            sr2=sg2=sb2=0.6;

        } else {
            sr2=sb2=sg2=1.0;
        }

        stoggle2 = 0;
    }
    //glutPostRedisplay();
}

void drawAv(void) {

        glMatrixMode(GL_PROJECTION);

        int i =0;
        float a1=-0.6, b1=-0.25;

//Car Code



        //Second car

        glColor3f(0,0,1);
glBegin(GL_POLYGON);

        glVertex3f(car_x1,car_y1,-1.0);

        glVertex3f(car_x1 - 0.1,-0.26,-1.0);

        glVertex3f(car_x1 - 0.1,-0.29,-1.0);

        glVertex3f(car_x1,-0.29,-1.0);
        glVertex3f(car_x1 + 0.03,-0.30,-1.0);
        glVertex3f(car_x1 + 0.03,-0.315,-1.0);
        glVertex3f(car_x1 - 0.15,-0.315,-1.0);
        glVertex3f(car_x1 - 0.15,-0.30,-1.0);

        glEnd();

        glColor3f(1,0,0);
glBegin(GL_POLYGON);
        glTranslatef(car_x, car_y, -1);
        glVertex3f(car_x,car_y,-1.0);

        glVertex3f(car_x + 0.1,car_y,-1.0);

        glVertex3f(car_x + 0.1,car_y -0.03,-1.0);

        glVertex3f(car_x,car_y -0.03,-1.0);
        glVertex3f(car_x - 0.03,car_y -0.04,-1.0);
        glVertex3f(car_x- 0.03,car_y -0.055,-1.0);
        glVertex3f(car_x + 0.15,car_y -0.055,-1.0);
        glVertex3f(car_x + 0.15,car_y -0.04,-1.0);

        glEnd();

        carupdate();

        glPushMatrix();

        glColor3f(1,1,1); //set ball colour
        glTranslatef(-0.65,-0.29,-1.0); //moving it toward the screen a bit on creation
        glutSolidSphere (0.05, 10, 10);

        glPopMatrix();


        glColor3f(1,1.0,1.0);
        while(i<3){
            glBegin(GL_POLYGON);

        glVertex3f(a1,b1,-1.0);

        glVertex3f(a1+0.15,b1,-1.0);

        glVertex3f(a1+0.15,b1-0.025,-1.0);

        glVertex3f(a1,b1-0.025,-1.0);
        a1+=0.5;
        i++;
        glEnd();
        }


        glBegin(GL_POLYGON);

        glColor3f(0.32 ,0.32,0.32);

        glVertex3f(-0.72,-0.2,-1.0);

        glVertex3f(0.72,-0.2,-1.0);

        glVertex3f(0.72,-0.4,-1.0);

        glVertex3f(-0.72,-0.4,-1.0);

        glEnd();


        //glVertex3f(6,0,-1.0);

        //glVertex3f(0.9,-0.7,-1.0);

    //glEnd();

}




void initRendering() {
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_COLOR_MATERIAL);
    glEnable(GL_LIGHTING); //Enable lighting
    glEnable(GL_LIGHT0); //Enable light #0
    glEnable(GL_LIGHT1); //Enable light #1
    glEnable(GL_NORMALIZE); //Automatically normalize normals
    //glShadeModel(GL_SMOOTH); //Enable smooth shading
}

//Called when the window is resized
void handleResize(int w, int h) {
    //Tell OpenGL how to convert from coordinates to pixel values
    glViewport(0, 0, w, h);

    glMatrixMode(GL_PROJECTION); //Switch to setting the camera perspective

    //Set the camera perspective
    glLoadIdentity(); //Reset the camera
    gluPerspective(45.0,                  //The camera angle
                   (double)w / (double)h, //The width-to-height ratio
                   1.0,                   //The near z clipping coordinate
                   200.0);                //The far z clipping coordinate
}

void drawScene()
{
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
    glClearColor(bgColR,bgColG,bgColB,0.0);
    glMatrixMode(GL_MODELVIEW);

    glLoadIdentity();




    glPushMatrix();
        drawClouds();
    glPopMatrix();

    //drawing the SUN
    glPushMatrix();
        drawBall();
    glPopMatrix();





    glutSwapBuffers();
}

//float _angle = 30.0f;
void update(int value) {

//For sun
 if (!flag)
    {
        if(ballX<0.0f)
    {
        ballX += 0.001f;
        ballY +=0.0007f;
        if(ballY<-0.075f)
        {
            bgColR+=0.00625;
            bgColB+=0.000625;
        }
        else{
                colG+=0.0008;

        bgColR-=0.0008;
        bgColB+=0.00065;
        bgColG+=0.0008;
        }
    }
    else
    {   //colG=1.0;
        ballX += 0.001f;
        ballY -=0.0007f;
        if(ballY<-0.075f)
        {
            colG=0.25;
            bgColR-=0.00625;
            bgColB-=0.000625;
        }
        else{
                colG-=0.0008;
        bgColR+=0.0008;
        bgColB-=0.00065;
        bgColG-=0.0008;
        }

    }
    }

//For Moon


    if(ballX>0.9f)
    {
        ballX = -0.8f;
        ballY = -0.1f;
        //flag=1;
        if(flag==0)
        {
        colR=2.0;
        colG=1.50;
        colB=1.0;
        bgColR=0.18;
        bgColG=0.18;
        bgColB=0.31;
            flag=1;
        }
        else
        {
            flag=0;
            colR=1.0;
            colG=0.25;
            colB=0.0;
             bgColR=0.18;
        bgColG=0.18;
        bgColB=0.31;
        }

    }




    glutPostRedisplay(); //Tell GLUT that the display has changed


    glutTimerFunc(25, update, 0);
}

int main(int argc,char** argv)
{
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_DOUBLE|GLUT_RGB|GLUT_DEPTH);

    glutInitWindowSize(400,400);

    glutCreateWindow("Sunset and sunrise");

    initRendering();

    glutDisplayFunc(drawScene);



    //glutSpecialFunc(keyPress);
    glutReshapeFunc(handleResize);

    glutTimerFunc(25, update, 0);

    glutMainLoop();

    return(0);
}
