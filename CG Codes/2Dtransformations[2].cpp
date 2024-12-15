#include <windows.h>
#include <gl/glut.h>
#include<bits/stdc++.h>

using namespace std;

int screen_height = 690;
int screen_width = 1350;

/* Boolean Type Variables to keep track of the operation being performed */
bool complete = false, want_transformations = false;
bool doing_translation = false, doing_scaling = false;
bool doing_reflection = false, doing_shearing = false;
bool doing_rotation = false;

class Matrix
{
public:
    vector <vector<float>> ip_coordinates;
    vector <vector<float>> op_coordinates;
    void multiply(float t[3][3]);
    void drawString(char *str);
}M;

class Translation : public Matrix
{
public:
    int translate_coord_x, translate_coord_y;
    void translate();
}trans;

class Scaling : public Matrix
{
public:
    int scaling_factor[2], scaling_count;
    Scaling()
    {
        scaling_factor[0] = 0; scaling_factor[1] = 0; scaling_count = 0;
    }
    void scaling();
}scl;

class Rotation : public Matrix
{
public:
    char rotation_type;
    void rotation();
}rot;

class Reflection : public Matrix
{
public:
    char reflection_axis;
    void reflection();
}refl;

class Shearing : public Matrix
{
public:
    char shearing_axis;
    int shearing_factor;
    void shearing();
}sh;


int options;

void Matrix::multiply(float temp[3][3])
{
    M.op_coordinates.clear();
    int i,j,k;
    vector<float> sum;
    for(i = 0;i < M.ip_coordinates.size(); i++)
    {
        for(j = 0;j < 3; j++)
        {
            sum.push_back(0);
            for(k = 0;k < 3;k++)
                sum[j] = sum[j] + M.ip_coordinates[i][k] * temp[k][j];
        }
        M.op_coordinates.push_back(sum);
        sum.clear();

    }
}

void Matrix::drawString(char * str)
{
    glRasterPos3f(-640, 320, 0);
    glColor3f(1.0f, 0.0f, 0.0f);
    for (char* c = str; *c != '\0';c++)
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, *c);
    glutPostRedisplay();
}


void Translation::translate()
{
    M.op_coordinates.clear();
    glClear(GL_COLOR_BUFFER_BIT);
    glutPostRedisplay();
    M.drawString("Translation Done !!");
    int tx, ty;
    tx = translate_coord_x - M.ip_coordinates[0][0];
    ty = translate_coord_y - M.ip_coordinates[0][1];

    for(int i = 0;i < M.ip_coordinates.size(); i++)
        M.op_coordinates.push_back({M.ip_coordinates[i][0] + tx,M.ip_coordinates[i][1] + ty });

    if(want_transformations && M.op_coordinates.size() != 0)
    {
        glColor3f(0.0f, 1.0f, 0.0f);
        glBegin(GL_POLYGON);
        for(int i=0;i<M.op_coordinates.size();i++)
            glVertex2i(M.op_coordinates[i][0], M.op_coordinates[i][1]);
        glEnd();
    }
    glFlush();
}

void Scaling::scaling()
{
    if(scaling_count % 2 == 0)
    {
        M.op_coordinates.clear();
        glClear(GL_COLOR_BUFFER_BIT);
        glutPostRedisplay();
        M.drawString("Scaling Completed !! ");
        float scaling_matrix[3][3];
        scaling_matrix[0][0] = scaling_factor[0];
        scaling_matrix[0][1] = scaling_matrix[0][2] = scaling_matrix[1][0] = scaling_matrix[1][2] = 0;
        scaling_matrix[1][1] = scaling_factor[1];
        scaling_matrix[2][0] = scaling_matrix[2][1] = 0;
        scaling_matrix[2][2] = 1;
        M.multiply(scaling_matrix);

        glColor3f(0.0f, 0.0f, 1.0f);
        glBegin(GL_LINE_LOOP);
        for(int i=0;i<M.op_coordinates.size();i++)
            glVertex2i(M.op_coordinates[i][0], M.op_coordinates[i][1]);
        glEnd();
    }
    glFlush();
}

void Reflection::reflection()
{
    M.op_coordinates.clear();
    glClear(GL_COLOR_BUFFER_BIT);
    glutPostRedisplay();

    if(reflection_axis=='x'||reflection_axis=='X')
    {
        M.drawString("Reflection around x-axis");
        for(int i=0;i<M.ip_coordinates.size();i++)
            M.op_coordinates.push_back({M.ip_coordinates[i][0], M.ip_coordinates[i][1] * -1});
        glColor3f(1.0f, 1.0f, 0.0f);
        glBegin(GL_POLYGON);
        for(int i=0;i<M.op_coordinates.size();i++)
            glVertex2i(M.op_coordinates[i][0], M.op_coordinates[i][1]);
        glEnd();
    }


    else if(reflection_axis=='y'|| reflection_axis=='Y')
    {
        M.drawString("Reflection around y-axis");
        for(int i=0;i<M.ip_coordinates.size();i++)
            M.op_coordinates.push_back({M.ip_coordinates[i][0] * -1, M.ip_coordinates[i][1]});
        glColor3f(0.0f, 1.0f, 1.0f);
        glBegin(GL_POLYGON);
        for(int i=0;i<M.op_coordinates.size();i++)
            glVertex2i(M.op_coordinates[i][0], M.op_coordinates[i][1]);
        glEnd();
    }
    glFlush();
}

void Shearing::shearing()
{
    M.op_coordinates.clear();
    glClear(GL_COLOR_BUFFER_BIT);
    glutPostRedisplay();

    if(shearing_axis == 'x')
    {
        float shearing_matrix[3][3];
        shearing_matrix[0][0] = shearing_matrix[1][1] = shearing_matrix[2][2] = 1;
        shearing_matrix[0][1] = shearing_matrix[0][2] = shearing_matrix[1][2] = 0;
        shearing_matrix[1][0] = shearing_factor;
        shearing_matrix[2][0] = shearing_matrix[2][1] = 0;
        M.multiply(shearing_matrix);

        M.drawString("Shearing along x-axis ");
        glColor3f(1.0f, 0.0f, 1.0f);
        glBegin(GL_POLYGON);
        for(int i=0;i<M.op_coordinates.size();i++)
            glVertex2i(M.op_coordinates[i][0], M.op_coordinates[i][1]);
        glEnd();
        glFlush();
    }
    else if(shearing_axis == 'y')
    {
        float shearing_matrix[3][3];
        shearing_matrix[0][0] = shearing_matrix[1][1] = shearing_matrix[2][2] = 1;
        shearing_matrix[0][1] = shearing_factor;
        shearing_matrix[1][0] = shearing_matrix[0][2] = shearing_matrix[1][2] = 0;
        shearing_matrix[2][0] = shearing_matrix[2][1] = 0;
        M.multiply(shearing_matrix);

        M.drawString("Shearing along y-axis ");
        glColor3f(1.0f, 0.0f, 1.0f);
        glBegin(GL_POLYGON);
        for(int i=0;i<M.op_coordinates.size();i++)
            glVertex2i(M.op_coordinates[i][0], M.op_coordinates[i][1]);
        glEnd();
        glFlush();
    }
}

void Rotation::rotation()
{
    M.op_coordinates.clear();
    glClear(GL_COLOR_BUFFER_BIT);
    glutPostRedisplay();
    M.drawString("Enter Angle for Rotation in other window ");
    glFlush();

    float angle,rotation_matrix[3][3];
    cout<<"\n Enter angle for Rotation(in degrees) --> ";
    cin>>angle;
    glClear(GL_COLOR_BUFFER_BIT);
    angle = (3.14*angle)/180;
    if(rotation_type == 'c')
    {
        M.drawString("Clockwise Rotation Done!! ");
        rotation_matrix[0][0] = cos(angle);
        rotation_matrix[0][1] = -sin(angle);
        rotation_matrix[1][0] = sin(angle);
        rotation_matrix[1][1] =  cos(angle);
        rotation_matrix[0][2] = rotation_matrix[1][2] = rotation_matrix[2][0] = rotation_matrix[2][1] = 0;
        rotation_matrix[2][2] = 1;
    }
    else if(rotation_type == 'a')
    {
        M.drawString("Anti-Clockwise Rotation Done!! ");
        rotation_matrix[0][0] = cos(angle);
        rotation_matrix[0][1] = sin(angle);
        rotation_matrix[1][0] = -sin(angle);
        rotation_matrix[1][1] = cos(angle);
        rotation_matrix[0][2] = rotation_matrix[1][2] = rotation_matrix[2][0] = rotation_matrix[2][1] = 0;
        rotation_matrix[2][2] = 1;
    }

    M.multiply(rotation_matrix);
    glColor3f(1.0f, 1.0f, 1.0f);
    glBegin(GL_POLYGON);
    for(int i=0;i<M.op_coordinates.size();i++)
        glVertex2i(M.op_coordinates[i][0], M.op_coordinates[i][1]);
    glEnd();
    glFlush();
}


void initGL()
{
     glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
     glClear(GL_COLOR_BUFFER_BIT);
     glMatrixMode( GL_PROJECTION );
     glLoadIdentity();
     gluOrtho2D( -screen_width/2, screen_width/2, -screen_height/2, screen_height/2 );
}

void menu(int n)
{
    switch(n)
    {
        case 1: doing_translation = true;
                glClear(GL_COLOR_BUFFER_BIT);
                M.drawString("Left-Click the point where you want to Translate ");
                break;
        case 2: doing_scaling = true;
                glClear(GL_COLOR_BUFFER_BIT);
                M.drawString("Enter the x-scaling factor followed by y-scaling factor");
                break;
        case 3: doing_rotation = true;
                glClear(GL_COLOR_BUFFER_BIT);
                M.drawString("Type 'a' for Anti-Clockwise rotation and 'c' for Clockwise rotation");
                break;
        case 4: doing_reflection = true;
                glClear(GL_COLOR_BUFFER_BIT);
                M.drawString("Enter the axis for reflection(x or y)");
                break;
        case 5: doing_shearing = true;
                glClear(GL_COLOR_BUFFER_BIT);
                M.drawString("Enter the axis of Shearing followed by shearing factor");
                break;
        case 6: M.op_coordinates.clear();
                M.ip_coordinates.clear();
                want_transformations = false;
                complete = false;
                glutDestroyMenu(options);
                glClear(GL_COLOR_BUFFER_BIT);
                glutPostRedisplay();
                break;
        case 7: exit(0);
    }
}

void mouse_event(int button, int state, int x, int y)
{
    y = screen_height/2 - y;
    x = x - screen_width/2;
    if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN && !complete)
    {

        M.ip_coordinates.push_back({x, y, 1});
        glutPostRedisplay();
    }
    if(button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN && !complete)
    {
        complete = true;
        want_transformations = true;
        glutPostRedisplay();
    }

    if(want_transformations)
    {
        options = glutCreateMenu(menu);
            glutAddMenuEntry("TRANSLATION",1);
            glutAddMenuEntry("SCALING",2);
            glutAddMenuEntry("ROTATION",3);
            glutAddMenuEntry("REFLECTION",4);
            glutAddMenuEntry("SHEARING",5);
            glutAddMenuEntry("CLEAR",6);
            glutAddMenuEntry("EXIT",7);
        glutAttachMenu(GLUT_RIGHT_BUTTON);
    }

    if(doing_translation && button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
    {
        trans.translate_coord_x = x;
        trans.translate_coord_y = y;
        trans.translate();
        doing_translation = false;
    }
}

void keyboard(unsigned char key, int x, int y)
{
    if(doing_scaling)
    {
        switch(key)
        {
            case 48: scl.scaling_factor[scl.scaling_count%2] = 0;
                     break;
            case 49: scl.scaling_factor[scl.scaling_count%2] = 1;
                     break;
            case 50: scl.scaling_factor[scl.scaling_count%2] = 2;
                     break;
            case 51: scl.scaling_factor[scl.scaling_count%2] = 3;
                     break;
            case 52: scl.scaling_factor[scl.scaling_count%2] = 4;
                     break;
            case 53: scl.scaling_factor[scl.scaling_count%2] = 5;
                     break;
            case 54: scl.scaling_factor[scl.scaling_count%2] = 6;
                     break;
            case 55: scl.scaling_factor[scl.scaling_count%2] = 7;
                     break;
            case 56: scl.scaling_factor[scl.scaling_count%2] = 8;
                     break;
            case 57: scl.scaling_factor[scl.scaling_count%2] = 9;
                     break;
            default: break;


        }
        if(key >=48 && key <= 57)
        {
            if(scl.scaling_count%2 == 1)
                doing_scaling = false;
            scl.scaling_count += 1;
            scl.scaling();
        }
    }
    if(doing_reflection == true)
    {
        if(key == 'x' || key == 'X')
        {
            refl.reflection_axis = 'x';
            refl.reflection();
            doing_reflection = false;
        }
        else if(key == 'y' || key == 'Y')
        {
            refl.reflection_axis = 'y';
            refl.reflection();
            doing_reflection = false;
        }
    }
    if(doing_shearing == true)
    {
        if(key == 'x' || key == 'X')
        {
            sh.shearing_axis = 'x';
        }
        else if(key == 'y' || key == 'Y')
        {
            sh.shearing_axis = 'y';
        }
        switch(key)
        {
            case 48: sh.shearing_factor = 0;
                     break;
            case 49: sh.shearing_factor = 1;
                     break;
            case 50: sh.shearing_factor = 2;
                     break;
            case 51: sh.shearing_factor = 3;
                     break;
            case 52: sh.shearing_factor = 4;
                     break;
            case 53: sh.shearing_factor = 5;
                     break;
            case 54: sh.shearing_factor = 6;
                     break;
            case 55: sh.shearing_factor = 7;
                     break;
            case 56: sh.shearing_factor = 8;
                     break;
            case 57: sh.shearing_factor = 9;
                     break;
            default: break;
        }
        if(key >=48 && key <= 57)
        {
            doing_shearing = false;
            sh.shearing();

        }
    }

    if(doing_rotation)
    {
        if(key == 'A' || key == 'a')
            rot.rotation_type = 'a';
        else if(key == 'C' || key == 'c')
            rot.rotation_type = 'c';
        rot.rotation();
        doing_rotation = false;
    }
}


void display()
{
    glColor3f(1.0f, 0.0f, 0.0f);
    if(!complete)
    {
        glBegin(GL_LINE_STRIP);
        for(int i=0;i<M.ip_coordinates.size();i++)
            glVertex2i(M.ip_coordinates[i][0], M.ip_coordinates[i][1]);
        glEnd();
    }
    else if(complete && !doing_scaling)
    {
        glBegin(GL_POLYGON);
        for(int i=0;i<M.ip_coordinates.size();i++)
            glVertex2i(M.ip_coordinates[i][0], M.ip_coordinates[i][1]);
        glEnd();
    }
    else if(complete && doing_scaling)
    {
        glBegin(GL_LINE_LOOP);
        for(int i=0;i<M.ip_coordinates.size();i++)
            glVertex2i(M.ip_coordinates[i][0], M.ip_coordinates[i][1]);
        glEnd();
    }
    glFlush();
}


int main(int argc, char ** argv)
{
     glutInit(&argc, argv);
     glutInitWindowPosition(0, 0);
     glutInitWindowSize(screen_width, screen_height);
     glutCreateWindow("2D Transformations");
     initGL();
     glutDisplayFunc(display);
     glutMouseFunc(mouse_event);
     glutKeyboardFunc(keyboard);
     glutMainLoop();
     return(0);
 }

