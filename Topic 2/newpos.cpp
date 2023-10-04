#include <iostream>
#include <GL/glut.h>
#include <cmath>

// Define the mathematical function f(x, y, z)
float f(float x, float y, float z) {
    return sin(sqrt(x * x + y * y + z * z));
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();
    gluLookAt(2, 2, 2, 0, 0, 0, 0, 1, 0);

    float step = 0.1f; // Define the resolution of the mesh
    float range = 2.0f; // Define the range of x and y values to plot

    glBegin(GL_LINES);
    for (float x = -range; x <= range; x += step) {
        for (float y = -range; y <= range; y += step) {
            glVertex3f(x, y, f(x, y));
            glVertex3f(x + step, y, f(x + step, y));
            glVertex3f(x, y, f(x, y));
            glVertex3f(x, y + step, f(x, y + step));
        }
    }
    glEnd();

    glutSwapBuffers();
}

void reshape(int w, int h) {
    glViewport(0, 0, (GLsizei)w, (GLsizei)h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(60, (GLfloat)w / (GLfloat)h, 1.0, 100.0);
    glMatrixMode(GL_MODELVIEW);
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(500, 500);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("OpenGL - Simple Mesh");
    glEnable(GL_DEPTH_TEST);
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutMainLoop();
    return 0;
}
