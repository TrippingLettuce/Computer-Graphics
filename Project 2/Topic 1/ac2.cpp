#ifdef __APPLE_CC__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif
#include <cstdlib>




struct GLintPoint {
    GLint x;
    GLint y;
};

void hardwiredHouse(void)
{
    glBegin(GL_LINE_LOOP);
        glVertex2i(40, 40);  // draw the shell of house 
        glVertex2i(40, 90);
        glVertex2i(70, 120);
        glVertex2i(100, 90);
        glVertex2i(100, 40);
    glEnd();
    glBegin(GL_LINE_STRIP); 
        glVertex2i(50, 100);    // draw the chimney 
        glVertex2i(50, 120);
        glVertex2i(60, 120);
        glVertex2i(60, 110);
    glEnd();
    // draw the door 
    // draw the window 
}

void parameterizedHouse(GLintPoint peak, GLint width, GLint height)
{
    glBegin(GL_LINE_LOOP);
        glVertex2i(peak.x, peak.y);  // draw shell of house 
        glVertex2i(peak.x + width / 2, peak.y - 3 * height / 8);
        glVertex2i(peak.x + width / 2, peak.y - height);
        glVertex2i(peak.x - width / 2, peak.y - height);
        glVertex2i(peak.x - width / 2, peak.y - 3 * height / 8);    
    glEnd();
    // draw chimney in the same fashion
    // draw the door
    // draw the window
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Hardwired House");
    
    // Initialization code here (if any)
    
    glutDisplayFunc(hardwiredHouse); // or parameterizedHouse or any other display function you have
    glutMainLoop();
    return 0;
}