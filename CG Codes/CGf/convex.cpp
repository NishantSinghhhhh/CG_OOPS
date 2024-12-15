#include <GL/glut.h>
#include <iostream>
#include <vector>

using namespace std;

struct Point
{
    int x, y;
};

// Function to draw a horizontal line from (x1, y) to (x2, y)
void drawHorizontalLine(int x1, int x2, int y)
{
    glBegin(GL_POINTS);
    for (int i = x1; i <= x2; i++)
        glVertex2i(i, y);
    glEnd();
}

// Function to implement the scan line polygon fill algorithm
void scanLineFill(const vector<Point> &vertices, int fill_color[])
{
    int minY = INT_MAX, maxY = INT_MIN;

    // Find the minimum and maximum y-coordinates
    for (const Point &vertex : vertices)
    {
        if (vertex.y < minY)
            minY = vertex.y;
        if (vertex.y > maxY)
            maxY = vertex.y;
    }

    // Traverse through each scan line
    for (int y = minY; y <= maxY; y++)
    {
        vector<int> xIntersections;

        // Find intersections with each edge
        for (size_t i = 0; i < vertices.size(); i++)
        {
            size_t next = (i + 1) % vertices.size();

            if ((y >= vertices[i].y && y < vertices[next].y) ||
                (y >= vertices[next].y && y < vertices[i].y))
            {
                xIntersections.push_back(vertices[i].x + (y - vertices[i].y) *
                                                             (vertices[next].x - vertices[i].x) /
                                                             (vertices[next].y - vertices[i].y));
            }
        }

        // Sort the intersections in increasing order
        sort(xIntersections.begin(), xIntersections.end());

        // Draw horizontal lines between pairs of intersections
        for (size_t i = 0; i < xIntersections.size(); i += 2)
        {
            drawHorizontalLine(xIntersections[i], xIntersections[i + 1], y);
        }
    }

    // Fill the polygon with the desired color
    glColor3f(fill_color[0], fill_color[1], fill_color[2]);
    glBegin(GL_POLYGON);
    for (const Point &vertex : vertices)
        glVertex2i(vertex.x, vertex.y);
    glEnd();
}

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);

    vector<Point> vertices;
    int numVertices;
    cout << "Enter the number of vertices: ";
    cin >> numVertices;

    for (int i = 0; i < numVertices; i++)
    {
        Point vertex;
        cout << "Enter the coordinates of vertex " << i + 1 << ": ";
        cin >> vertex.x >> vertex.y;
        vertices.push_back(vertex);
    }

    int fill_color[3];
    cout << "Enter the RGB values for fill color (0 to 255): ";
    cin >> fill_color[0] >> fill_color[1] >> fill_color[2];

    // Draw convex polygon and fill it
    glColor3f(1.0, 1.0, 1.0); // White color for polygon outline
    glBegin(GL_LINE_LOOP);
    for (const Point &vertex : vertices)
        glVertex2i(vertex.x, vertex.y);
    glEnd();

    scanLineFill(vertices, fill_color);

    glFlush();
}

int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitWindowSize(500, 500);
    glutCreateWindow("Convex Polygon Fill Algorithm");

    gluOrtho2D(0, 500, 0, 500);

    glutDisplayFunc(display);
    glutMainLoop();

    return 0;
}
