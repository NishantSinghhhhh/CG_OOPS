#include <GL/glut.h>
#include <cmath>

void drawCircle(float cx, float cy, float radius, int segments) {
    glBegin(GL_LINE_LOOP);
    for (int i = 0; i < segments; ++i) {
        float angle = 2.0 * 3.14159 * i / segments;
        float x = cx + radius * cos(angle);
        float y = cy + radius * sin(angle);
        glVertex2f(x, y);
    }
    glEnd();
}

void drawTriangle(float centerX, float centerY, float side) {
    glBegin(GL_LINE_LOOP);
    glVertex2f(centerX - side / 2, centerY - sqrt(3) * side / 6);
    glVertex2f(centerX + side / 2, centerY - sqrt(3) * side / 6);
    glVertex2f(centerX, centerY + sqrt(3) * side / 3);
    glEnd();
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0, 1.0, 1.0);

    // Draw the outer circle
    drawCircle(0, 0, 0.8, 100);

    // Draw the inscribed triangle
    glColor3f(0.0, 1.0, 0.0);  // Green color for the triangle
    drawTriangle(0, 0, 1.4);

    // Draw the inscribed circle within the triangle
    glColor3f(0.0, 0.0, 1.0);  // Blue color for the circle
    drawCircle(0, 0, 0.4, 100);

    glFlush();
}

void myInit() {
    glClearColor(0.0, 0.0, 0.0, 0.0);
    gluOrtho2D(-1.5, 1.5, -1.5, 1.5);
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(600, 600);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Pattern Generation");
    myInit();
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}
