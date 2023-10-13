#include <iostream>
#include <GL/glut.h>
#include <stdlib.h>

void drawPyramid(float x, float y, float z) {
    glPushMatrix();
    glTranslatef(x, y, z);
    glBegin(GL_TRIANGLES);
        // Front face
        glColor3f(1.0, 0.0, 0.0); // Red
        glVertex3f( 0.0f,  1.0f, 0.0f);
        glColor3f(0.0, 1.0, 0.0); // Green
        glVertex3f(-1.0f, -1.0f, 1.0f);
        glColor3f(0.0, 0.0, 1.0); // Blue
        glVertex3f( 1.0f, -1.0f, 1.0f);

        // Right face
        glColor3f(1.0, 0.0, 0.0); // Red
        glVertex3f(0.0f,  1.0f, 0.0f);
        glColor3f(0.0, 0.0, 1.0); // Blue
        glVertex3f(1.0f, -1.0f, 1.0f);
        glColor3f(1.0, 1.0, 0.0); // Yellow
        glVertex3f(1.0f, -1.0f, -1.0f);

        // Back face
        glColor3f(1.0, 0.0, 0.0); // Red
        glVertex3f(0.0f,  1.0f, 0.0f);
        glColor3f(1.0, 1.0, 0.0); // Yellow
        glVertex3f(1.0f, -1.0f, -1.0f);
        glColor3f(1.0, 0.0, 1.0); // Purple
        glVertex3f(-1.0f, -1.0f, -1.0f);

        // Left Face
        glColor3f(1.0, 0.0, 0.0); // Red
        glVertex3f( 0.0f,  1.0f, 0.0f);
        glColor3f(1.0, 0.0, 1.0); // Purple
        glVertex3f(-1.0f, -1.0f, -1.0f);
        glColor3f(0.0, 1.0, 0.0); // Green
        glVertex3f(-1.0f, -1.0f,  1.0f);
    glEnd();
    glPopMatrix();
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();
    
    // Camera setup for an angled top-down view
    gluLookAt(
        3.0f, 8.0f, 3.0f,  // Camera position (x, y, z)
        3.0f, 0.0f, 0.0f,  // Look at point (x, y, z)
        0.0f, 1.0f, 0.0f   // Up vector (x, y, z)
    );
    
    drawPyramid(-2.0f, 0.0f, 0.0f); // Draw the left pyramid
    drawPyramid( 2.0f, 0.0f, 0.0f); // Draw the middle pyramid
    drawPyramid( 6.0f, 0.0f, 0.0f); // Draw the right pyramid
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
    glutInitWindowSize(800, 600); // Adjust window size to better fit three pyramids
    glutInitWindowPosition(100, 100);
    glutCreateWindow("OpenGL - Creating Pyramids");
    glEnable(GL_DEPTH_TEST);
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutMainLoop();
    return 0;
}