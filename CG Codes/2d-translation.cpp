#include <GL/glut.h>
#include <cmath>
#include<bits/stdc++.h>
// Global variables
int choice = 0;
float vertices_triangle[3][2] = {{-50, -50}, {50, -50}, {0, 50}};
float vertices_rhombus[4][2] = {{-50, 0}, {0, -50}, {50, 0}, {0, 50}};
float angle = 45.0f;
float scaling_factor = 1.5f;
float shearing_factor = 0.5f;

// Function to perform translation
void translate(float tx, float ty, float vertices[][2], int size) {
    for (int i = 0; i < size; ++i) {
        vertices[i][0] += tx;
        vertices[i][1] += ty;
    }
}

// Function to perform rotation
void rotate(float angle, float vertices[][2], int size) {
    float radian = angle * (M_PI / 180.0);
    float cosA = cos(radian);
    float sinA = sin(radian);

    for (int i = 0; i < size; ++i) {
        float x = vertices[i][0];
        float y = vertices[i][1];
        vertices[i][0] = x * cosA - y * sinA;
        vertices[i][1] = x * sinA + y * cosA;
    }
}

// Function to perform scaling
void scale(float sx, float sy, float vertices[][2], int size) {
    for (int i = 0; i < size; ++i) {
        vertices[i][0] *= sx;
        vertices[i][1] *= sy;
    }
}

// Function to perform shearing
void shear(float shx, float shy, float vertices[][2], int size) {
    for (int i = 0; i < size; ++i) {
        float x = vertices[i][0];
        float y = vertices[i][1];
        vertices[i][0] = x + shx * y;
        vertices[i][1] = y + shy * x;
    }
}

// Display function
void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0, 1.0, 1.0);

    // Original objects
    glBegin(GL_LINE_LOOP);
    for (int i = 0; i < 3; ++i) {
        glVertex2f(vertices_triangle[i][0], vertices_triangle[i][1]);
    }
    glEnd();

    glBegin(GL_LINE_LOOP);
    for (int i = 0; i < 4; ++i) {
        glVertex2f(vertices_rhombus[i][0], vertices_rhombus[i][1]);
    }
    glEnd();

    // Transformed objects based on user choice
    if (choice == 1) {
        translate(100, 100, vertices_triangle, 3);
    } else if (choice == 2) {
        rotate(angle, vertices_triangle, 3);
    } else if (choice == 3) {
        scale(scaling_factor, scaling_factor, vertices_triangle, 3);
    } else if (choice == 4) {
        shear(shearing_factor, shearing_factor, vertices_triangle, 3);
    }

    glColor3f(1.0, 0.0, 0.0);
    glBegin(GL_LINE_LOOP);
    for (int i = 0; i < 3; ++i) {
        glVertex2f(vertices_triangle[i][0], vertices_triangle[i][1]);
    }
    glEnd();

    if (choice == 1) {
        translate(200, 200, vertices_rhombus, 4);
    } else if (choice == 2) {
        rotate(angle, vertices_rhombus, 4);
    } else if (choice == 3) {
        scale(scaling_factor, scaling_factor, vertices_rhombus, 4);
    } else if (choice == 4) {
        shear(shearing_factor, shearing_factor, vertices_rhombus, 4);
    }

    glColor3f(0.0, 1.0, 0.0);
    glBegin(GL_LINE_LOOP);
    for (int i = 0; i < 4; ++i) {
        glVertex2f(vertices_rhombus[i][0], vertices_rhombus[i][1]);
    }
    glEnd();

    glFlush();
}

// Initialize function
void initialize() {
    glClearColor(0.0, 0.0, 0.0, 1.0);
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(-300, 300, -300, 300);
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(600, 600);
    glutCreateWindow("2D Transformations");

    initialize();

    // Menu to choose transformation
    printf("Choose transformation:\n");
    printf("1. Translation\n2. Rotation\n3. Scaling\n4. Shearing\n");
    scanf("%d", &choice);

    glutDisplayFunc(display);
    glutMainLoop();

    return 0;
}
