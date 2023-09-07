#include <GL/glut.h>

void drawTriangle(float[3][2], int);

void sierpinski(float[3][2], int depth) {
    if (depth == 0) {
        drawTriangle(points, depth);
    } else {
        float midpoints[3][2];
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 2; j++) {
                midpoints[i][j] = (points[i][j] + points[(i+1)%3][j]) / 2.0;
            }
        }
        sierpinski({points[0], midpoints[0], midpoints[2]}, depth-1);
        sierpinski({points[1], midpoints[0], midpoints[1]}, depth-1);
        sierpinski({points[2], midpoints[1], midpoints[2]}, depth-1);
    }
}

void drawTriangle(float points[3][2], int depth) {
    glBegin(GL_TRIANGLES);
    glVertex2fv(points[0]);
    glVertex2fv(points[1]);
    glVertex2fv(points[2]);
    glEnd();
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    float points[3][2] = {{0.0, 0.0}, {0.5, 1.0}, {1.0, 0.0}};
    sierpinski(points, 3);
    glFlush();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutCreateWindow("Sierpinski Gasket");
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}
