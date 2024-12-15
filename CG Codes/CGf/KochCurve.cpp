#include<bits/stdc++.h>
#include<GL/glut.h>

using namespace std;

//here x and y are the initial points
float x = -0.5, y = 0;
int iter;

//HERE dir IS THE DIRECTION OF ROTATION FOR THE LINE...
void drKochCurve(float dir, float len, int iter)
{
    double dirrad = 0.0174533 * dir; //changing degree to rad.

    float nx = x + len * cos(dirrad); //this is the uplifted point x
    float ny = y + len * sin(dirrad); //this is the uplifted point y
    if (iter == 0)
    {
        glVertex2f(x, y);
        glVertex2f(nx, ny);
        x = nx;
        y = ny;
    }
    else
    {
        iter--;
        drKochCurve(dir, len, iter);
        dir += 60.0;

        drKochCurve(dir, len, iter);
        dir -= 120.0;

        drKochCurve(dir, len, iter);
        dir += 60.0;
        drKochCurve(dir, len, iter);
    }
}

void display(void)
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glBegin(GL_LINES);
    glColor3f(0.0, 1.0, 0.0);
    cout << "ENTER NUMBER OF ITERATIONS:- ";
    cin >> iter;
    drKochCurve(0, 0.1, iter);
    glEnd();
    glFlush();
}

int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(700, 700);
    glutInitWindowPosition(0, 0);
    glutCreateWindow(" KOCH CURVE GENERATION-7224");
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}
