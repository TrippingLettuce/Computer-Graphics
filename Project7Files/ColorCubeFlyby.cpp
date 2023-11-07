// This program is a flyby around the RGB color cube.  One intersting note
// is that because the cube is a convex polyhedron and it is the only thing
// in the scene, we can render it using backface culling only. i.e., there
// is no need for a depth buffer.

#ifdef __APPLE_CC__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif
#include <cmath>

// Global variables to control functionalities:
bool isMoving = true;
float verticalShift = 0.0;
float zoomFactor = 1.0;
float rotationAngle = 0.0;

// The cube has opposite corners at (0,0,0) and (1,1,1), which are black and
// white respectively.  The x-axis is the red gradient, the y-axis is the
// green gradient, and the z-axis is the blue gradient.  The cube's position
// and colors are fixed.

namespace Cube {

  const int NUM_VERTICES = 8;
  const int NUM_FACES = 6;

  GLint vertices[NUM_VERTICES][3] = {
    {0, 0, 0}, {0, 0, 1}, {0, 1, 0}, {0, 1, 1},
    {1, 0, 0}, {1, 0, 1}, {1, 1, 0}, {1, 1, 1}};

  GLint faces[NUM_FACES][4] = {
    {1, 5, 7, 3}, {5, 4, 6, 7}, {4, 0, 2, 6},
    {3, 7, 6, 2}, {0, 1, 3, 2}, {0, 4, 5, 1}};

  GLfloat vertexColors[NUM_VERTICES][3] = {
    {0.0, 0.0, 0.0}, {0.0, 0.0, 1.0}, {0.0, 1.0, 0.0}, {0.0, 1.0, 1.0},
    {1.0, 0.0, 0.0}, {1.0, 0.0, 1.0}, {1.0, 1.0, 0.0}, {1.0, 1.0, 1.0}};

  void draw() {
    glBegin(GL_QUADS);
    for (int i = 0; i < NUM_FACES; i++) {
      for (int j = 0; j < 4; j++) {
        glColor3fv((GLfloat*)&vertexColors[faces[i][j]]);
        glVertex3iv((GLint*)&vertices[faces[i][j]]);
      }
    }
    glEnd();
  }
}

class LeftPlane {
public:
    static void draw() {
        glPushMatrix();

        glTranslatef(-5.0f, 0.0f, 0.0f);   // Move to the left
        glScalef(0.1f, 5.0f, 5.0f);       // Scale to look like a thick plane
        glColor3f(0.7f, 0.7f, 0.7f);      // Color of the left plane
        glutSolidCube(1.0f);

        glPopMatrix();
    }
};

class RightPlane {
public:
    static void draw() {
        glPushMatrix();

        glTranslatef(5.0f, 0.0f, 0.0f);    // Move to the right
        glScalef(0.1f, 5.0f, 5.0f);       // Scale to look like a thick plane
        glColor3f(0.7f, 0.7f, 0.7f);      // Color of the right plane
        glutSolidCube(1.0f);

        glPopMatrix();
    }
};

namespace BouncingCubes {
    const int NUM_CUBES = 2;
    GLfloat cubeSpeeds[NUM_CUBES] = {0.02, -0.025};
    GLfloat cubePositions[NUM_CUBES][3] = {{-1.5, 0.5, 0.5}, {1.5, 0.5, 0.5}}; // Changed the initial positions to be close to the planes.
    
    void updatePositions() {
        for (int i = 0; i < NUM_CUBES; i++) {
            cubePositions[i][0] += cubeSpeeds[i];
            
            // Bounce the cube when it's about to touch or cross the plane
            if (cubePositions[i][0] <= -2 + 0.5 || cubePositions[i][0] >= 2 - 0.5) { // considering cube's half width
                cubeSpeeds[i] = -cubeSpeeds[i];
            }
        }
    }

    void draw() {
        for (int i = 0; i < NUM_CUBES; i++) {
            glPushMatrix();
            if (isMoving) { // Only move the bouncing cubes, not the central one.
                glTranslatef(cubePositions[i][0], cubePositions[i][1], cubePositions[i][2]);
            }
            Cube::draw();
            glPopMatrix();
        }
    }
}




// Display and Animation. To draw we just clear the window and draw the cube.
// Because our main window is double buffered we have to swap the buffers to
// make the drawing visible. Animation is achieved by successively moving our
// camera and drawing. The function nextAnimationFrame() moves the camera to
// the next point and draws. The way that we get animation in OpenGL is to
// register nextFrame as the idle function; this is done in main().
void display() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glMatrixMode(GL_MODELVIEW);
    // glLoadIdentity();
    // glTranslatef(0, 0, -10 * zoomFactor);  // Move back to view the entire scene with zoom factor applied
    // Apply global transformations to the whole scene
    glPushMatrix();
    glTranslatef(0, verticalShift, -10 * zoomFactor);  // Move the entire scene back and apply vertical shift
    glRotatef(rotationAngle, 0, 1, 0); // Rotate the whole scene

    // Draw the left and right planes and the bouncing cubes
    LeftPlane::draw();
    RightPlane::draw();
    BouncingCubes::draw(); // Draw the bouncing cubes

    // Draw the primary cube at the center without moving it
    if (isMoving) {
        Cube::draw();
    }

    glPopMatrix(); // Restore the original matrix

    // Swap buffers to display the frame
    glutSwapBuffers();
}


void keyboard(unsigned char key, int x, int y) {
    switch (key) {
    case 'r':
        rotationAngle += 10;  // Rotate by 10 degrees. Adjust as necessary.
        break;
    case 's':
        isMoving = false;
        break;
    case 'c':
        isMoving = true;
        break;
    case 'u':
        verticalShift += 0.5;
        break;
    case 'd':
        verticalShift -= 0.5;
        break;
    case '=':  // Zoom in
        zoomFactor -= 0.3;
        if (zoomFactor < 0.3) zoomFactor = 0.3; // Set minimum zoom limit
        break;
    case '-':  // Zoom out
        zoomFactor += 0.3;
        if (zoomFactor > 3.0) zoomFactor = 3.0; // Set maximum zoom limit
        break;
    }
    glutPostRedisplay();
}



// Modify the timer function to incorporate the new functionalities:
void timer(int v) {
    if (isMoving) {
        rotationAngle += 0.5;  // Increment rotation angle for rotating the whole scene
        BouncingCubes::updatePositions(); // Update positions of the bouncing cubes
    }
    glutPostRedisplay();
    glutTimerFunc(1000 / 60, timer, v);
}


// When the window is reshaped we have to recompute the camera settings to
// match the new window shape.  Set the viewport to (0,0)-(w,h).  Set the
// camera to have a 60 degree vertical field of view, aspect ratio w/h, near
// clipping plane distance 0.5 and far clipping plane distance 40.
void reshape(int w, int h) {
  glViewport(0, 0, w, h);
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  gluPerspective(60.0, GLfloat(w) / GLfloat(h), 0.5, 40.0);
  glMatrixMode(GL_MODELVIEW);
}

// Application specific initialization:  The only thing we really need to do
// is enable back face culling because the only thing in the scene is a cube
// which is a convex polyhedron.
void init() {
  glEnable(GL_CULL_FACE);
  glCullFace(GL_BACK);
}

// The usual main for a GLUT application.
int main(int argc, char** argv) {
  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
  glutInitWindowSize(500, 500);
  glutCreateWindow("The RGB Color Cube");
  glutReshapeFunc(reshape);
  glutTimerFunc(100, timer, 0);
  glutDisplayFunc(display);
  glutKeyboardFunc(keyboard);  // Register keyboard callback.
  init();
  glutMainLoop();
}