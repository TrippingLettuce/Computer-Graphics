// This application is a trivial illustration of texture mapping.  It draws
// several triangles, each with a texture mapped on to it.  The same texture
// is used for each triangle, but the mappings vary quite a bit so it looks as
// if each triangle has a different texture.

#ifdef __APPLE_CC__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif
#include <cstdlib>

// Define a 2 x 2 red and yellow checkered pattern using RGB colors.
#define red {0xff, 0x00, 0x00}
#define yellow {0xff, 0xff, 0x00}
#define magenta {0xff, 0, 0xff}
GLubyte texture[][3] = {
    red, yellow,
    yellow, red,
};

GLfloat rotate_angle = 0.0f;
bool spinning = false;
GLfloat x_translation = 0.0f;
GLfloat y_translation = 0.0f;
GLfloat zoom_factor = 1.0f;

// Fixes up camera and remaps texture when window reshaped.
void reshape(int width, int height) {
  glViewport(0, 0, width, height);
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  gluPerspective(80, GLfloat(width) / height, 0.1, 40);
  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();
  gluLookAt(0, 0, 10, 0, 0, 0, 0, 1, 0);
  glEnable(GL_TEXTURE_2D);
  glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
  glTexImage2D(GL_TEXTURE_2D,
               0,                    // level 0
               3,                    // use only R, G, and B components
               2, 2,                 // texture has 2x2 texels
               0,                    // no border
               GL_RGB,               // texels are in RGB format
               GL_UNSIGNED_BYTE,     // color components are unsigned bytes
               texture);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
}

// Draws three textured triangles.  Each triangle uses the same texture,
// but the mappings of texture coordinates to vertex coordinates is
// different in each triangle.
void display() {
  glClear(GL_COLOR_BUFFER_BIT);

  glPushMatrix();
  
  // Apply the scaling first
  glScalef(zoom_factor, zoom_factor, 1.0f);
  
  // Then apply the translations and rotations
  glTranslatef(x_translation, y_translation, 0.0f);
  glRotatef(rotate_angle, 0.0f, 0.0f, 1.0f);
  
  glBegin(GL_TRIANGLES);
    glTexCoord2f(0.5, 1.0);    glVertex2f(-3, 3);
    glTexCoord2f(0.0, 0.0);    glVertex2f(-3, 0);
    glTexCoord2f(1.0, 0.0);    glVertex2f(0, 0);

    glTexCoord2f(4, 8);        glVertex2f(3, 3);
    glTexCoord2f(0.0, 0.0);    glVertex2f(0, 0);
    glTexCoord2f(8, 0.0);      glVertex2f(3, 0);

    glTexCoord2f(5, 5);        glVertex2f(0, 0);
    glTexCoord2f(0.0, 0.0);    glVertex2f(-1.5, -3);
    glTexCoord2f(4, 0.0);      glVertex2f(1.5, -3);
  glEnd();

  glPopMatrix();

  glutSwapBuffers();

  if (spinning) {
      rotate_angle += 0.5f; // Control the speed of the rotation
      if (rotate_angle > 360.0f) {
          rotate_angle -= 360.0f;
      }
      glutPostRedisplay(); // Redraw the scene
  }
}

void keyboard(unsigned char key, int x, int y) {
    switch (key) {
    case 'p':
        spinning = false;
        break;
    case 'o':
        spinning = true;
        glutPostRedisplay();
        break;
    case 'w':
        y_translation += 0.3f;
        glutPostRedisplay();
        break;
    case 's':
        y_translation -= 0.3f;
        glutPostRedisplay();
        break;
    case 'a':
        x_translation -= 0.3f;
        glutPostRedisplay();
        break;
    case 'd':
        x_translation += 0.3f;
        glutPostRedisplay();
        break;
    case '=':
        zoom_factor += 0.1f;
        glutPostRedisplay();
        break;
    case '-':
        zoom_factor -= 0.1f;
        glutPostRedisplay();
        break;
    }
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB); // Use GLUT_DOUBLE for double buffering
    glutInitWindowSize(520, 390);
    glutCreateWindow("Textured Triangles");
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutKeyboardFunc(keyboard); // Register the keyboard callback
    glutMainLoop();
    return 0;
}