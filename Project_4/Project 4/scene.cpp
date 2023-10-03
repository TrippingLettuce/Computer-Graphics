// Below is the code for Project 4. This code utilizes basic openGL commands to make a 2D portrait of the picture that was chosen from Project 3. This utilized
// polygons, lines, and colors from the picture to render with our graphics. This will potentially be expanded to 3D in the future.
#include <iostream>
#include <GL/glut.h>
#include <stdlib.h>

void start(){
    glClearColor(187.0f/255.0f, 179.0f/255.0f, 165.0f/255.0f, 255.0);
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(0.0, 377, 0.0, 463);
    glViewport(0, 0, 377, 463);
}

// Object Declaration
void dryer() {
    
    glClear(GL_COLOR_BUFFER_BIT);

// ----------------------------------------------------------- //
    // Window Frame
    glBegin(GL_POLYGON);
    glColor4b(181 * 127 / 255,130 * 127 / 255,124 * 127 / 255,255);
    glVertex2i(0, 463 - 151);
    glVertex2i(217, 463 - 151);
    glVertex2i(217, 463 - 0);
    glVertex2i(0, 463 - 0);
    glEnd();

    // Window Middle Frame
    glBegin(GL_POLYGON);
    glColor4b(95 * 127 / 255,106 * 127 / 255,129 * 127 / 255,255);
    glVertex2i(77, 463 - 0);
    glVertex2i(92, 463 - 0);
    glVertex2i(99, 463 - 118);
    glVertex2i(84, 463 - 118);
    glEnd();

    // Window Bottom Frame
    glBegin(GL_POLYGON);
    glColor4b(179 * 127 / 255,177 * 127 / 255,176 * 127 / 255,255);
    glVertex2i(0, 463 - 149);
    glVertex2i(50, 463 - 149);
    glVertex2i(49, 463 - 152);
    glVertex2i(0, 463 - 152);
    glEnd();

    glBegin(GL_POLYGON);
    glColor4b(159 * 127 / 255,162 * 127 / 255,172 * 127 / 255,255);
    glVertex2i(0, 463 - 149);
    glVertex2i(50, 463 - 149);
    glVertex2i(49, 463 - 142);
    glVertex2i(0, 463 - 142);
    glEnd();

    glBegin(GL_POLYGON);
    glColor4b(101 * 127 / 255,105 * 127 / 255,117 * 127 / 255,255);
    glVertex2i(0, 463 - 142);
    glVertex2i(50, 463 - 142);
    glVertex2i(49, 463 - 145);
    glVertex2i(0, 463 - 146);
    glEnd();


    glLineWidth(4.0f);
    // Window Blind Lines (Left -> Right order)
    glBegin(GL_LINES);
    glColor4b(145 * 127 / 255,133 * 127 / 255,138 * 127 / 255,255);
    glVertex2i(5, 463 - 0);
    glVertex2i(21, 463 - 151);
    glEnd();

    glBegin(GL_LINES);
    glColor4b(145 * 127 / 255,133 * 127 / 255,138 * 127 / 255,255);
    glVertex2i(29, 463 - 0);
    glVertex2i(42, 463 - 151);
    glEnd();

    glBegin(GL_LINES);
    glColor4b(145 * 127 / 255,133 * 127 / 255,138 * 127 / 255,255);
    glVertex2i(52, 463 - 0);
    glVertex2i(67, 463 - 151);
    glEnd();

    glBegin(GL_LINES);
    glColor4b(145 * 127 / 255,133 * 127 / 255,138 * 127 / 255,255);
    glVertex2i(95, 463 - 0);
    glVertex2i(106, 463 - 151);
    glEnd();

    glBegin(GL_LINES);
    glColor4b(145 * 127 / 255,133 * 127 / 255,138 * 127 / 255,255);
    glVertex2i(112, 463 - 0);
    glVertex2i(120, 463 - 151);
    glEnd();

    glBegin(GL_LINES);
    glColor4b(145 * 127 / 255,133 * 127 / 255,138 * 127 / 255,255);
    glVertex2i(131, 463 - 0);
    glVertex2i(138, 463 - 151);
    glEnd();

    glBegin(GL_LINES);
    glColor4b(145 * 127 / 255,133 * 127 / 255,138 * 127 / 255,255);
    glVertex2i(149, 463 - 0);
    glVertex2i(157, 463 - 151);
    glEnd();

    glBegin(GL_LINES);
    glColor4b(145 * 127 / 255,133 * 127 / 255,138 * 127 / 255,255);
    glVertex2i(166, 463 - 0);
    glVertex2i(171, 463 - 151);
    glEnd();

    glBegin(GL_LINES);
    glColor4b(145 * 127 / 255,133 * 127 / 255,138 * 127 / 255,255);
    glVertex2i(181, 463 - 0);
    glVertex2i(186, 463 - 151);
    glEnd();

    glBegin(GL_LINES);
    glColor4b(145 * 127 / 255,133 * 127 / 255,138 * 127 / 255,255);
    glVertex2i(193, 463 - 0);
    glVertex2i(198, 463 - 151);
    glEnd();

// ----------------------------------------------------------- //
    // Wall Line
    glBegin(GL_POLYGON);
    glColor4b(25 * 127 / 255,29 * 127 / 255,32 * 127 / 255,255);
    glVertex2i(0, 463 - 423);
    glVertex2i(0, 463 - 402);
    glVertex2i(246, 463 - 317);
    glVertex2i(377, 463 - 393);
    glVertex2i(377, 463 - 420);
    glVertex2i(246, 463 - 341);
    glVertex2i(0, 463 - 424);
    glEnd();

    glBegin(GL_POLYGON);
    glColor4b(179 * 127 / 255, 167 * 127 / 255, 153 * 127 / 255,255);
    glVertex2i(219, 463 - 0);
    glVertex2i(229, 463 - 0);
    glVertex2i(229, 463 - 118);
    glVertex2i(219, 463 - 118);
    glEnd();

    glBegin(GL_POLYGON);
    glColor4b(159 * 127 / 255, 152 * 127 / 255, 136 * 127 / 255,255);
    glVertex2i(228, 463 - 0);
    glVertex2i(233, 463 - 0);
    glVertex2i(233, 463 - 118);
    glVertex2i(228, 463 - 118);
    glEnd();
    
    glBegin(GL_POLYGON);
    glColor4b(183 * 127 / 255, 174 * 127 / 255, 157 * 127 / 255,255);
    glVertex2i(235, 463 - 0);
    glVertex2i(248, 463 - 0);
    glVertex2i(248, 463 - 118);
    glVertex2i(235, 463 - 118);
    glEnd();


// ----------------------------------------------------------- //
    // Floor 
    glBegin(GL_POLYGON);
    glColor4b(41 * 127 / 255, 41 * 127 / 255, 39 * 127 / 255,255);
    glVertex2i(0, 463 - 463);
    glVertex2i(0, 463 - 424);
    glVertex2i(246, 463 - 341);
    glVertex2i(377, 463 - 420);
    glVertex2i(377, 463 - 463);
    glEnd();

// ----------------------------------------------------------- //
// Table
    // Table RGB values
    int t_r = 162 * 127 / 255;
    int t_g = 128 * 127 / 255;
    int t_b = 91 * 127 / 255;
    // Table Upper Surface
    glBegin(GL_POLYGON);
    glColor4b(t_r,t_g,t_b,255);
    glVertex2i(112, 463 - 303);
    glVertex2i(312, 463 - 287);
    glVertex2i(350,463 - 337);
    glVertex2i(94,463 - 337);
    glEnd();

    glBegin(GL_POLYGON);
    glColor4b(177 * 127/255, 144 * 127/255, 99 * 127/255,255);
    glVertex2i(94, 463 - 337);
    glVertex2i(350,463 - 337);
    glVertex2i(350,463 - 346);
    glVertex2i(94,463 - 346);
    glEnd();

    // Table Lower Surface
    glBegin(GL_POLYGON);
    glColor4b(t_r,t_g,t_b,255);
    glVertex2i(124, 463 - 358);
    glVertex2i(105, 463 - 411);
    glVertex2i(336,463 - 417);
    glVertex2i(309,463 - 361);
    glEnd();

    glBegin(GL_POLYGON);
    glColor4b(177 * 127/255, 144 * 127/255, 99 * 127/255,255);
    glVertex2i(105, 463 - 411);
    glVertex2i(105,463 - 416);
    glVertex2i(336,463 - 421);
    glVertex2i(336,463 - 416);
    glEnd();

    // Table Legs
        // Left Outer Leg
    glBegin(GL_POLYGON);
    glColor4b(0.0f,0.0f,0.0f,255);
    glVertex2i(117, 463 - 346);
    glVertex2i(123,463 - 346);
    glVertex2i(129,463 - 445);
    glVertex2i(123, 463 - 447);
    glEnd();
        // Left Inner Leg
    glBegin(GL_POLYGON);
    glColor4b(0.0f,0.0f,0.0f,255);
    glVertex2i(138, 463 - 346);
    glVertex2i(144,463 - 346);
    glVertex2i(144,463 - 359);
    glVertex2i(139, 463 - 358);
    glEnd();

        // Right Inner Leg
    glBegin(GL_POLYGON);
    glColor4b(0.0f,0.0f,0.0f,255);
    glVertex2i(290, 463 - 346);
    glVertex2i(295,463 - 346);
    glVertex2i(295,463 - 361);
    glVertex2i(290, 463 - 361);
    glEnd();

        // Right Outer Leg
    glBegin(GL_POLYGON);
    glColor4b(0.0f,0.0f,0.0f,255);
    glVertex2i(317, 463 - 346);
    glVertex2i(323,463 - 346);
    glVertex2i(317,463 - 453);
    glVertex2i(310, 463 - 453);
    glEnd();

// ----------------------------------------------------------- //
// TV

    // TV Outer Screen
    glBegin(GL_POLYGON);
    glColor4b(0.0f,0.0f,0.0f,255);
    glVertex2i(366, 463 - 117);
    glVertex2i(46,463 - 117);
    glVertex2i(63,463 - 307);
    glVertex2i(348, 463 - 284);
    glEnd();

    // TV Inner Screen for reflection and stuff
    glBegin(GL_POLYGON);
    glColor4b(29.0f,29.0f,34.0f,255);
    glVertex2i(363, 463 - 121);
    glVertex2i(50,463 - 120);
    glVertex2i(66,463 - 301);
    glVertex2i(346, 463 - 280);
    glEnd();

    // TV stands leg
    glBegin(GL_POLYGON); 
    glColor4b(0.0f,0.0f,0.0f,255);

    glVertex2i(149, 463 - 300);
    glVertex2i(154, 463 - 319);
    glVertex2i(283, 463 - 308);
    glVertex2i(265, 463 - 290);
    glEnd();

    glFlush();
    glutSwapBuffers();
}

int main(int argc, char ** argv) {
    // Initialize GLUT
    glutInit(&argc, argv);
    // Set display mode
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    // Set top - left display window position.
    glutInitWindowPosition(100, 100);
    // Set display window width and height
    glutInitWindowSize(377, 463);
    // Create display window with the given title
    glutCreateWindow("Scene1");
    // Execute initialization procedure
    start();
    // Send graphics to display window
    glutDisplayFunc(dryer);
    // Display everything and wait.
    glutMainLoop();


    return 0;
}