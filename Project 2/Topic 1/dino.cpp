


//#include <windows.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>

#include <fstream>

void display();


void drawPolyLineFile(const char * fileName) {

	std::ifstream inStream;
	inStream.open(fileName);	// open the file

	if (inStream.fail()) return;
	glClear(GL_COLOR_BUFFER_BIT);      // clear the screen 

	GLint numpolys, numLines;
	GLfloat x, y;
	inStream >> numpolys;		           // read the number of polylines

	for (int iPoly = 0; iPoly < numpolys; iPoly++) { // read each polyline
		inStream >> numLines;
		glBegin(GL_LINE_STRIP);	     // draw the next polyline
		for (int i = 0; i < numLines; i++) {
			inStream >> x >> y;        // read the next x, y pair
			glVertex2f(x, y);
		}
		glFlush();
		glEnd();
	}
	glFlush();
	inStream.close();
}

int main(int argc, char** argv) {
	glutInit(&argc, argv);

	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(640, 480);
	glutInitWindowPosition(0, 0);
	glutCreateWindow("Dinosaur");

	glutDisplayFunc(display);
	glutMainLoop();

	return(0);

}

void setWindow(float left, float right, int bottom, int top) {
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(left, right, bottom, top);
}

void display() {

	glClear(GL_COLOR_BUFFER_BIT);

	setWindow(0, 1024.0, 0, 768.0);
	drawPolyLineFile("dino.dat");

	glFlush();

}

    

