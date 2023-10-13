// Below is the code for Project 4. This code utilizes basic openGL commands to make a 2D portrait of the picture that was chosen from Project 3. This utilized
// polygons, lines, and colors from the picture to render with our graphics. This will potentially be expanded to 3D in the future.
#include <iostream>
#include <GL/glut.h>
#include <stdlib.h>
#include <math.h>
#include <SOIL/SOIL.h>

void start(){
    glClearColor(187.0f/255.0f, 179.0f/255.0f, 165.0f/255.0f, 255.0);
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(0.0, 377, 0.0, 463);
    glViewport(0, 0, 377, 463);
}
// ----------------------------------------------------------- //
#define NUM_SEGMENTS 100

void drawEllipse(float radiusX, float radiusY, float x, float y, float rotation, float r, float g, float b) {
    // Save the current transformation matrix
    glPushMatrix();

    // Translate to the center of the ellipse
    glTranslatef(x, y, 0.0f);

    // Rotate around the Z-axis
    glRotatef(rotation, 0.0f, 0.0f, 1.0f);

    // Set the color to fill the ellipse
    glColor3f(r, g, b);

    // Draw the filled ellipse
    glBegin(GL_POLYGON);
    for(int i = 0; i < NUM_SEGMENTS; i++) {
        float theta = 2.0f * M_PI * (float)i / (float)NUM_SEGMENTS;
        float dx = radiusX * cosf(theta);
        float dy = radiusY * sinf(theta);
        glVertex2f(dx, dy);
    }
    glEnd();

    // Restore the transformation matrix
    glPopMatrix();
}

// ----------------------------------------------------------- //
// Object Declaration
void scene() {
    
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    GLuint texture;
    texture = SOIL_load_OGL_texture // load an image file directly as a new OpenGL texture
    (
        "/home/chris/Desktop/Project 4/texture/wooden_texture.jpg",
        SOIL_LOAD_AUTO,
        SOIL_CREATE_NEW_ID,
        SOIL_FLAG_MIPMAPS | SOIL_FLAG_INVERT_Y | SOIL_FLAG_NTSC_SAFE_RGB | SOIL_FLAG_COMPRESS_TO_DXT
    );

    // Check for an error during the load process
    if(texture == 0)
        printf("SOIL loading error: '%s'\n", SOIL_last_result());
    
    GLuint texture1;
    texture1 = SOIL_load_OGL_texture // load an image file directly as a new OpenGL texture
    (
        "/home/chris/Desktop/Project 4/texture/carpet.jpg",
        SOIL_LOAD_AUTO,
        SOIL_CREATE_NEW_ID,
        SOIL_FLAG_MIPMAPS | SOIL_FLAG_INVERT_Y | SOIL_FLAG_NTSC_SAFE_RGB | SOIL_FLAG_COMPRESS_TO_DXT
    );

    // Check for an error during the load process
    if(texture1 == 0)
        printf("SOIL loading error: '%s'\n", SOIL_last_result());

    // TV
    GLuint texture2;
    texture2 = SOIL_load_OGL_texture // load an image file directly as a new OpenGL texture
    (
        "/home/chris/Desktop/Project 4/texture/tv_screen.png",
        SOIL_LOAD_AUTO,
        SOIL_CREATE_NEW_ID,
        SOIL_FLAG_MIPMAPS | SOIL_FLAG_INVERT_Y | SOIL_FLAG_NTSC_SAFE_RGB | SOIL_FLAG_COMPRESS_TO_DXT
    );

    // Check for an error during the load process
    if(texture2 == 0)
        printf("SOIL loading error: '%s'\n", SOIL_last_result());

    // Window
    GLuint texture3;
    texture3 = SOIL_load_OGL_texture // load an image file directly as a new OpenGL texture
    (
        "/home/chris/Desktop/Project 4/texture/123.png",
        SOIL_LOAD_AUTO,
        SOIL_CREATE_NEW_ID,
        SOIL_FLAG_MIPMAPS | SOIL_FLAG_INVERT_Y | SOIL_FLAG_NTSC_SAFE_RGB | SOIL_FLAG_COMPRESS_TO_DXT
    );

    // Check for an error during the load process
    if(texture3 == 0)
        printf("SOIL loading error: '%s'\n", SOIL_last_result());

    // Carpet
    GLuint texture4;
    texture4 = SOIL_load_OGL_texture // load an image file directly as a new OpenGL texture
    (
        "/home/chris/Desktop/Project 4/texture/nintendo.png",
        SOIL_LOAD_AUTO,
        SOIL_CREATE_NEW_ID,
        SOIL_FLAG_MIPMAPS | SOIL_FLAG_INVERT_Y | SOIL_FLAG_NTSC_SAFE_RGB | SOIL_FLAG_COMPRESS_TO_DXT
    );

    // Check for an error during the load process
    if(texture4 == 0)
        printf("SOIL loading error: '%s'\n", SOIL_last_result());

// ----------------------------------------------------------- //
    // Window Frame
    glEnable(GL_TEXTURE_2D); // Enable texturing
    glBindTexture(GL_TEXTURE_2D, texture3); // Bind your texture
    glBegin(GL_POLYGON);
    glColor4b(255 * 127 / 255,255 * 127 / 255,255 * 127 / 255,255);
    glTexCoord2f(0.0f, 0.0f); glVertex2i(0, 463 - 151);
    glTexCoord2f(1.0f, 0.0f); glVertex2i(217, 463 - 151);
    glTexCoord2f(1.0f, 1.0f); glVertex2i(217, 463 - 0);
    glTexCoord2f(0.0f, 1.0f); glVertex2i(0, 463 - 0);
    glEnd();
    glDisable(GL_TEXTURE_2D);

    // ----------------------------------------------------------- //
    // Brick Wall
    glBegin(GL_POLYGON);
    glColor4b(181 * 127 / 255,130 * 127 / 255,124 * 127 / 255,255);
    glVertex2i(120, 463 - 0);
    glVertex2i(205, 463 - 0);
    glVertex2i(205, 463 - 118);
    glVertex2i(125, 463 - 118);
    glEnd();

    glLineWidth(2.0f);
    // Brick Wall Lines
    glBegin(GL_LINES);
    glColor4b(228 * 127 / 255,179 * 127 / 255,172 * 127 / 255,255);
    glVertex2i(121, 463 - 13);
    glVertex2i(137, 463 - 0);
    glEnd();

    glBegin(GL_LINES);
    glColor4b(228 * 127 / 255,179 * 127 / 255,172 * 127 / 255,255);
    glVertex2i(121, 463 - 30);
    glVertex2i(173, 463 - 0);
    glEnd();

    glBegin(GL_LINES);
    glColor4b(228 * 127 / 255,179 * 127 / 255,172 * 127 / 255,255);
    glVertex2i(122, 463 - 47);
    glVertex2i(205, 463 - 10);
    glEnd();

    glBegin(GL_LINES);
    glColor4b(228 * 127 / 255,179 * 127 / 255,172 * 127 / 255,255);
    glVertex2i(124, 463 - 63);
    glVertex2i(205, 463 - 32);
    glEnd();

    glBegin(GL_LINES);
    glColor4b(228 * 127 / 255,179 * 127 / 255,172 * 127 / 255,255);
    glVertex2i(123, 463 - 78);
    glVertex2i(205, 463 - 53);
    glEnd();

    glBegin(GL_LINES);
    glColor4b(228 * 127 / 255,179 * 127 / 255,172 * 127 / 255,255);
    glVertex2i(122, 463 - 47);
    glVertex2i(205, 463 - 10);
    glEnd();

    glBegin(GL_LINES);
    glColor4b(228 * 127 / 255,179 * 127 / 255,172 * 127 / 255,255);
    glVertex2i(124, 463 - 92);
    glVertex2i(205, 463 - 75);
    glEnd();

    glBegin(GL_LINES);
    glColor4b(228 * 127 / 255,179 * 127 / 255,172 * 127 / 255,255);
    glVertex2i(125, 463 - 107);
    glVertex2i(206, 463 - 93);
    glEnd();

    glBegin(GL_LINES);
    glColor4b(228 * 127 / 255,179 * 127 / 255,172 * 127 / 255,255);
    glVertex2i(165, 463 - 118);
    glVertex2i(205, 463 - 112);
    glEnd();

    glLineWidth(1.0f);
    // Brick Wall Lines Vertical
    glBegin(GL_LINES);
    glColor4b(228 * 127 / 255,179 * 127 / 255,172 * 127 / 255,255);
    glVertex2i(126, 463 - 10);
    glVertex2i(127, 463 - 27);
    glEnd();

    glBegin(GL_LINES);
    glColor4b(228 * 127 / 255,179 * 127 / 255,172 * 127 / 255,255);
    glVertex2i(145, 463 - 16);
    glVertex2i(146, 463 - 37);
    glEnd();

    glBegin(GL_LINES);
    glColor4b(228 * 127 / 255,179 * 127 / 255,172 * 127 / 255,255);
    glVertex2i(177, 463 - 22);
    glVertex2i(178, 463 - 42);
    glEnd();

    glBegin(GL_LINES);
    glColor4b(228 * 127 / 255,179 * 127 / 255,172 * 127 / 255,255);
    glVertex2i(139, 463 - 39);
    glVertex2i(140, 463 - 57);
    glEnd();

    glBegin(GL_LINES);
    glColor4b(228 * 127 / 255,179 * 127 / 255,172 * 127 / 255,255);
    glVertex2i(163, 463 - 47);
    glVertex2i(165, 463 - 66);
    glEnd();

    glBegin(GL_LINES);
    glColor4b(228 * 127 / 255,179 * 127 / 255,172 * 127 / 255,255);
    glVertex2i(181, 463 - 60);
    glVertex2i(182, 463 - 80);
    glEnd();

    glBegin(GL_LINES);
    glColor4b(228 * 127 / 255,179 * 127 / 255,172 * 127 / 255,255);
    glVertex2i(145, 463 - 70);
    glVertex2i(146, 463 - 87);
    glEnd();

    glBegin(GL_LINES);
    glColor4b(228 * 127 / 255,179 * 127 / 255,172 * 127 / 255,255);
    glVertex2i(128, 463 - 90);
    glVertex2i(129, 463 - 107);
    glEnd();

    glBegin(GL_LINES);
    glColor4b(228 * 127 / 255,179 * 127 / 255,172 * 127 / 255,255);
    glVertex2i(175, 463 - 80);
    glVertex2i(176, 463 - 98);
    glEnd();

    // ----------------------------------------------------------- //
    // Side Window Wall
    glBegin(GL_POLYGON);
    glColor4b(90 * 127 / 255, 89 * 127 / 255, 91 * 127 / 255,255);
    glVertex2i(204, 463 - 0);
    glVertex2i(210, 463 - 0);
    glVertex2i(211, 463 - 118);
    glVertex2i(204, 463 - 118);
    glEnd();

    // Side Window White Frame
    glBegin(GL_POLYGON);
    glColor4b(216 * 127 / 255, 204 * 127 / 255, 202 * 127 / 255,255);
    glVertex2i(210, 463 - 0);
    glVertex2i(217, 463 - 0);
    glVertex2i(217, 463 - 118);
    glVertex2i(210, 463 - 118);
    glEnd();
        // Shadow
    glBegin(GL_POLYGON);
    glColor4b(228 * 127 / 255, 226 * 127 / 255, 224 * 127 / 255,255);
    glVertex2i(217, 463 - 0);
    glVertex2i(221, 463 - 0);
    glVertex2i(221, 463 - 118);
    glVertex2i(217, 463 - 118);
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


    glLineWidth(6.0f);
    // Window Blind Lines (Left -> Right order)
    // glBegin(GL_LINES);
    // glColor4b(145 * 127 / 255,133 * 127 / 255,138 * 127 / 255,255);
    // glVertex2i(5, 463 - 0);
    // glVertex2i(21, 463 - 151);
    // glEnd();

    // glBegin(GL_LINES);
    // glColor4b(145 * 127 / 255,133 * 127 / 255,138 * 127 / 255,255);
    // glVertex2i(29, 463 - 0);
    // glVertex2i(42, 463 - 151);
    // glEnd();

    // glBegin(GL_LINES);
    // glColor4b(145 * 127 / 255,133 * 127 / 255,138 * 127 / 255,255);
    // glVertex2i(52, 463 - 0);
    // glVertex2i(67, 463 - 151);
    // glEnd();

    // glBegin(GL_LINES);
    // glColor4b(145 * 127 / 255,133 * 127 / 255,138 * 127 / 255,255);
    // glVertex2i(95, 463 - 0);
    // glVertex2i(106, 463 - 151);
    // glEnd();

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

    glBegin(GL_POLYGON);
    glColor4b(150 * 127 / 255, 141 * 127 / 255, 124 * 127 / 255,255);
    glVertex2i(221, 463 - 0);
    glVertex2i(225, 463 - 0);
    glVertex2i(225, 463 - 64);
    glVertex2i(221, 463 - 64);
    glEnd();

    glBegin(GL_POLYGON);
    glColor4b(121 * 127 / 255, 120 * 127 / 255, 121 * 127 / 255,255);
    glVertex2i(225, 463 - 0);
    glVertex2i(227, 463 - 0);
    glVertex2i(227, 463 - 64);
    glVertex2i(225, 463 - 64);
    glEnd();

    glDisable(GL_TEXTURE_2D);

// ----------------------------------------------------------- //
    // Floor 
    glEnable(GL_TEXTURE_2D); // Enable texturing
    glBindTexture(GL_TEXTURE_2D, texture1); // Bind your texture
    // glDisable(GL_LIGHTING);
    // Set color to white
    glColor3f(0.4647f, 0.4647f, 0.4569f);

    glBegin(GL_POLYGON);
    glTexCoord2f(0.0f, 0.0f); glVertex2i(0, 463 - 463);
    glTexCoord2f(1.0f, 0.0f); glVertex2i(377, 463 - 463);
    glTexCoord2f(1.0f, 1.0f); glVertex2i(377, 463 - 420);
    glTexCoord2f(0.0f, 1.0f); glVertex2i(0, 463 - 424);


    glEnd();
    glDisable(GL_TEXTURE_2D);


    glEnable(GL_TEXTURE_2D); // Enable texturing
    glBindTexture(GL_TEXTURE_2D, texture1); // Bind your texture
    glColor3f(0.4647f, 0.4647f, 0.4569f);
    
    glBegin(GL_POLYGON);
    glTexCoord2f(1.0f, 0.0f); glVertex2i(0, 463 - 424);
    glTexCoord2f(0.0f, 0.0f); glVertex2i(246, 463 - 341);
    glTexCoord2f(0.0f, 1.0f); glVertex2i(377, 463 - 420);
    glEnd();

    glDisable(GL_TEXTURE_2D);


// ----------------------------------------------------------- //
// Table
    glEnable(GL_TEXTURE_2D); // Enable texturing
    glBindTexture(GL_TEXTURE_2D, texture); // Bind your texture

    glDisable(GL_LIGHTING);
    // Set color to white
    glColor3f(0.8667f, 0.7373f, 0.5647f);

    // Table Upper Surface
    glBegin(GL_POLYGON);
    glTexCoord2f(0.0f, 0.0f); glVertex2i(112, 463 - 303);
    glTexCoord2f(1.0f, 0.0f); glVertex2i(312, 463 - 287);
    glTexCoord2f(1.0f, 1.0f); glVertex2i(350, 463 - 337);
    glTexCoord2f(0.0f, 1.0f); glVertex2i(94, 463 - 337);
    glEnd();

    // Second polygon
    glBegin(GL_POLYGON);
    glTexCoord2f(0.0f, 0.0f); glVertex2i(94, 463 - 337);
    glTexCoord2f(1.0f, 0.0f); glVertex2i(350, 463 - 337);
    glTexCoord2f(1.0f, 1.0f); glVertex2i(350, 463 - 346);
    glTexCoord2f(0.0f, 1.0f); glVertex2i(94, 463 - 346);
    glEnd();
    glDisable(GL_TEXTURE_2D);

    glEnable(GL_TEXTURE_2D); // Enable texturing
    glBindTexture(GL_TEXTURE_2D, texture); // Bind your texture

    glDisable(GL_LIGHTING);
    // Set color to white
    glColor3f(0.8667f, 0.7373f, 0.5647f);
    // Table Lower Surface
    glBegin(GL_POLYGON);
    glTexCoord2f(0.0f, 2.0f); glVertex2i(124, 463 - 358);
    glTexCoord2f(0.0f, 0.0f); glVertex2i(105, 463 - 411);
    glTexCoord2f(1.0f, 1.0f); glVertex2i(336, 463 - 417);
    glTexCoord2f(0.0f, 1.0f); glVertex2i(309, 463 - 361);
    glEnd();

    glBegin(GL_POLYGON);
    glTexCoord2f(0.0f, 0.0f); glVertex2i(105, 463 - 411);
    glTexCoord2f(1.0f, 0.0f); glVertex2i(105, 463 - 416);
    glTexCoord2f(1.0f, 1.0f); glVertex2i(336, 463 - 421);
    glTexCoord2f(0.0f, 1.0f); glVertex2i(336, 463 - 416);
    glEnd();

    glDisable(GL_TEXTURE_2D);

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

    glLineWidth(1.5f);
    //Cables
    glBegin(GL_LINES);
    glColor3f(0.0f, 0.0f, 0.0f); // Black color for the cable
    glVertex2i(280, 80); // Starting point of the cable (controller 1)
    glVertex2i(310, 60); // Ending point of the cable (controller 2)
    glEnd();
    glBegin(GL_LINES);
    glColor3f(0.0f, 0.0f, 0.0f); // Black color for the cable
    glVertex2i(280, 80); // Starting point of the cable (controller 1)
    glVertex2i(260, 90); // Ending point of the cable (controller 2)
    glEnd();
    glBegin(GL_LINES);
    glColor3f(0.0f, 0.0f, 0.0f); // Black color for the cable
    glVertex2i(260, 90); // Starting point of the cable (controller 1)
    glVertex2i(245, 105); // Ending point of the cable (controller 2)
    glEnd();
    glBegin(GL_LINES);
    glColor3f(0.0f, 0.0f, 0.0f); // Black color for the cable
    glVertex2i(280, 80); // Starting point of the cable (controller 1)
    glVertex2i(275, 105); // Ending point of the cable (controller 2)
    glEnd();
    glBegin(GL_LINES);
    glColor3f(0.0f, 0.0f, 0.0f); // Black color for the cable
    glVertex2i(280, 80); // Starting point of the cable (controller 1)
    glVertex2i(230, 55); // Ending point of the cable (controller 2)
    glEnd();

    glBegin(GL_LINE_STRIP);
    glColor3f(0.0f, 0.0f, 0.0f); // Black color for the cable
    float x1 = 280, y1 = 80;      // Starting point of the cable
    float x2 = 260, y2 = 60;      // Control point of the cable
    float x3 = 290, y3 = 60;      // Ending point of the cable

    for (float t = 0; t <= 1; t += 0.01) {
        float x = pow(1 - t, 2) * x1 + 2 * (1 - t) * t * x2 + pow(t, 2) * x3;
        float y = pow(1 - t, 2) * y1 + 2 * (1 - t) * t * y2 + pow(t, 2) * y3;
        glVertex2f(x, y);
    }
    glEnd();

    glBegin(GL_LINES);
    glColor3f(0.0f, 0.0f, 0.0f); // Black color for the cable
    glVertex2i(280, 80); // Starting point of the cable (controller 1)
    glVertex2i(310, 60); // Ending point of the cable (controller 2)
    glEnd();

    glBegin(GL_LINES);
    glColor3f(0.0f, 0.0f, 0.0f); // Black color for the cable
    glVertex2i(200, 80); // Starting point of the cable (controller 1)
    glVertex2i(240, 60); // Ending point of the cable (controller 2)
    glEnd();

    glBegin(GL_LINES);
    glColor3f(0.0f, 0.0f, 0.0f); // Black color for the cable
    glVertex2i(200, 80); // Starting point of the cable (controller 1)
    glVertex2i(180, 80); // Ending point of the cable (controller 2)
    glEnd();


    glBegin(GL_LINE_STRIP);
    glColor3f(0.0f, 0.0f, 0.0f); // Black color for the cable

    float x1_loop = 180, y1_loop = 80;      // Starting point of the cable
    float x2_loop = 190, y2_loop = 100;     // Control point of the cable
    float x3_loop = 200, y3_loop = 80;      // Ending point of the cable

    for (float t = 0; t <= 1; t += 0.01) {
        float x = pow(1 - t, 2) * x1_loop + 2 * (1 - t) * t * x2_loop + pow(t, 2) * x3_loop;
        float y = pow(1 - t, 2) * y1_loop + 2 * (1 - t) * t * y2_loop + pow(t, 2) * y3_loop;
        glVertex2f(x, y);
    }

    glEnd();


    glBegin(GL_LINES);
    glColor3f(0.0f, 0.0f, 0.0f); // Black color for the cable
    glVertex2i(207, 50); // Starting point of the cable (controller 1)
    glVertex2i(215, 80); // Ending point of the cable (controller 2)
    glEnd();

    // Loop cable using Bezier curve
    glBegin(GL_LINE_STRIP);
    glColor3f(0.0f, 0.0f, 0.0f); // Black color for the cable

    float x1_loop1 = 200, y1_loop1 = 80;      // Starting point of the cable
    float x2_loop1 = 215, y2_loop1 = 40;      // Control point of the cable (above starting point)
    float x3_loop1 = 220, y3_loop1 = 80;      // Ending point of the cable (same as starting point)

    for (float t = 0; t <= 1; t += 0.01) {
        float x = pow(1 - t, 2) * x1_loop1 + 2 * (1 - t) * t * x2_loop1 + pow(t, 2) * x3_loop1;
        float y = pow(1 - t, 2) * y1_loop1 + 2 * (1 - t) * t * y2_loop1 + pow(t, 2) * y3_loop1;
        glVertex2f(x, y);
    }

    glEnd();


// Nintendo Switch
    // Main Box
    // Joysticks with the box
    glBegin(GL_POLYGON);
    // glColor4b(40 * 127/255, 29 * 127/255, 22 * 127/255,255);
    glColor3f(1.0f,1.0f,1.0f);
    glVertex2i(213, 463 - 386);
    glVertex2i(262,463 - 388);
    glVertex2i(262,463 - 411);
    glVertex2i(212, 463 - 411);
    glEnd();

    glBegin(GL_POLYGON);
    glColor4b(34 * 127/255, 33 * 127/255, 33 * 127/255,255);
    glVertex2i(213, 463 - 380);
    glVertex2i(262, 463 - 381);
    glVertex2i(262, 463 - 411);
    glVertex2i(212, 463 - 411);
    glEnd();


    glEnable(GL_TEXTURE_2D); // Enable texturing
    glBindTexture(GL_TEXTURE_2D, texture4); // Bind your texture
    glColor3f(1.0f,1.0f,1.0f);

    glBegin(GL_POLYGON);
    // glColor4b(15 * 127/255, 15 * 127/255, 15 * 127/255,255);
    glTexCoord2f(0.0f, 0.0f); glVertex2i(213, 463 - 386);
    glTexCoord2f(1.0f, 0.0f); glVertex2i(262,463 - 388);
    glTexCoord2f(1.0f, 1.0f); glVertex2i(262,463 - 411);
    glTexCoord2f(0.0f, 1.0f); glVertex2i(212, 463 - 411);
    glEnd();
    glDisable(GL_TEXTURE_2D);

    drawEllipse(5, 10, 140.0f, 463.0f - 395.0f, 59.0f, 0.0f, 0.0f, 0.0f);

    glBegin(GL_POLYGON);
    glColor4b(15 * 127/255, 15 * 127/255, 15 * 127/255,255);
    glVertex2i(138, 463 - 385);
    glVertex2i(144,463 - 388);
    glVertex2i(142,463 - 391);
    glVertex2i(135, 463 - 388);
    glEnd();

    glBegin(GL_POLYGON);
    glColor4b(15 * 127/255, 15 * 127/255, 15 * 127/255,255);
    glVertex2i(142, 463 - 377);
    glVertex2i(160,463 - 382);
    glVertex2i(152,463 - 386);
    glVertex2i(136, 463 - 381);
    glEnd();

    glBegin(GL_POLYGON);
    glColor4b(59 * 127/255, 49 * 127/255, 42 * 127/255,255);
    glVertex2i(136, 463 - 381);
    glVertex2i(152,463 - 386);
    glVertex2i(152,463 - 392);
    glVertex2i(135, 463 - 385);
    glEnd();

    glBegin(GL_POLYGON);
    glColor4b(12 * 127/255, 14 * 127/255, 8 * 127/255,255);
    glVertex2i(152, 463 - 385);
    glVertex2i(159,463 - 381);
    glVertex2i(161,463 - 385);
    glVertex2i(152, 463 - 392);
    glEnd();


    drawEllipse(5, 12, 160.0f, 463.0f - 381.0f, 70.0f, 0.0f, 0.0f, 0.0f);

    glBegin(GL_POLYGON);
    glColor4b(15 * 127/255, 15 * 127/255, 15 * 127/255,255);
    glVertex2i(176, 463 - 386);
    glVertex2i(188,463 - 378);
    glVertex2i(196,463 - 381);
    glVertex2i(182, 463 - 390);
    glEnd();

    glBegin(GL_POLYGON);
    glColor4b(59 * 127/255, 49 * 127/255, 42 * 127/255,255);
    glVertex2i(182, 463 - 390);
    glVertex2i(196,463 - 381);
    glVertex2i(197,463 - 385);
    glVertex2i(184, 463 - 393);
    glEnd();

    glBegin(GL_POLYGON);
    glColor4b(12 * 127/255, 14 * 127/255, 8 * 127/255,255);
    glVertex2i(176, 463 - 386);
    glVertex2i(182,463 - 390);
    glVertex2i(185,463 - 393);
    glVertex2i(173, 463 - 389);
    glEnd();

    drawEllipse(5, 12, 178.0f, 463.0f - 386.0f, 115.0f, 0.0f, 0.0f, 0.0f);
    drawEllipse(3.5, 7, 195.0f, 463.0f - 393.0f, 130.0f, 0.0f, 0.0f, 0.0f);

    glBegin(GL_POLYGON);
    glColor4b(12 * 127/255, 14 * 127/255, 8 * 127/255,255);
    glVertex2i(189, 463 - 390);
    glVertex2i(195,463 - 386);
    glVertex2i(197,463 - 388);
    glVertex2i(192, 463 - 392);
    glEnd();

// ----------------------------------------------------------- //
// Switch Controller & Box
    // Box
    glBegin(GL_POLYGON);
    glColor4b(12 * 127/255, 14 * 127/255, 8 * 127/255,255);
    glVertex2i(290, 463 - 397);
    glVertex2i(303,463 - 404);
    glVertex2i(303,463 - 412);
    glVertex2i(288, 463 - 404);
    glEnd();

    glBegin(GL_POLYGON);
    glColor4b(41 * 127/255, 34 * 127/255, 25 * 127/255,255);
    glVertex2i(303, 463 - 404);
    glVertex2i(314,463 - 395);
    glVertex2i(314,463 - 404);
    glVertex2i(303, 463 - 412);
    glEnd();

    glBegin(GL_POLYGON);
    glColor4b(12 * 127/255, 14 * 127/255, 8 * 127/255,255);
    glVertex2i(290, 463 - 397);
    glVertex2i(304,463 - 386);
    glVertex2i(317,463 - 393);
    glVertex2i(303, 463 - 404);
    glEnd();

    // Pink Controller
    glBegin(GL_POLYGON);
    glColor4b(181 * 127/255, 117 * 127/255, 108 * 127/255,255);
    glVertex2i(298 - 8, 463 - 397);
    glVertex2i(300 - 8, 463 - 379);
    glVertex2i(304 - 8, 463 - 373);
    glVertex2i(306 - 8, 463 - 373);
    glVertex2i(307 - 8, 463 - 374);
    glVertex2i(307 - 8, 463 - 375);
    glVertex2i(303 - 8, 463 - 380);
    glVertex2i(302 - 8, 463 - 399);
    glVertex2i(300 - 8, 463 - 399);
    glVertex2i(297 - 8, 463 - 397);
    glEnd();

    glBegin(GL_POLYGON);
    glColor4b(181 * 127/255, 117 * 127/255, 108 * 127/255,255);
    glVertex2i(302 - 8, 463 - 399);
    glVertex2i(305 - 8, 463 - 398);
    glVertex2i(308 - 8, 463 - 375);
    glVertex2i(302 - 8, 463 - 380);
    glEnd();

    // Blue Controller
    glBegin(GL_POLYGON);
    glColor4b(30 * 127/255, 97 * 127/255, 108 * 121/255,255);
    glVertex2i(298, 463 - 397 - 3);
    glVertex2i(300, 463 - 379 - 3);
    glVertex2i(304, 463 - 373 - 3);
    glVertex2i(306, 463 - 373 - 3);
    glVertex2i(307, 463 - 374 - 3);
    glVertex2i(307, 463 - 375 - 3);
    glVertex2i(303, 463 - 380 - 3);
    glVertex2i(302, 463 - 399 - 3);
    glVertex2i(300, 463 - 399 - 3);
    glVertex2i(297, 463 - 397 - 3);
    glEnd();

    glBegin(GL_POLYGON);
    glColor4b(30 * 127/255, 97 * 127/255, 137 * 121/255,255);
    glVertex2i(302, 463 - 399 - 3);
    glVertex2i(305, 463 - 398 - 3);
    glVertex2i(308, 463 - 375 - 3);
    glVertex2i(302, 463 - 380 - 3);
    glEnd();

    // Bar
    glBegin(GL_POLYGON);
    glColor4b(11 * 127/255, 16 * 127/255, 14 * 127/255,255);
    glVertex2i(315 - 10, 463 - 403);
    glVertex2i(317 - 12,463 - 377);
    glVertex2i(320 - 8,463 - 374);
    glVertex2i(319 - 8, 463 - 398);
    glEnd();

    glBegin(GL_POLYGON);
    glColor4b(11 * 127/255, 16 * 127/255, 14 * 127/255,255);
    glVertex2i(317 - 10, 463 - 377);
    glVertex2i(310 - 12,463 - 374);
    glVertex2i(310 - 8,463 - 370);
    glVertex2i(317 - 6, 463 - 374);
    glEnd();

    // Red Controller
    glBegin(GL_POLYGON);
    glColor4b(172 * 127/255, 75 * 127/255, 79 * 127/255,255);
    glVertex2i(315 - 5, 463 - 400);
    glVertex2i(317 - 6,463 - 377);
    glVertex2i(320 - 4,463 - 374);
    glVertex2i(319 - 4, 463 - 393);
    glEnd();

    // Controller Buttons
        // Blue controller buttons
    drawEllipse(3, 3, 304.0f, 463.0f - 386.0f, 0.0f, 0.0f, 0.0f, 0.0f);
    drawEllipse(1.5, 1.5, 304.0f, 463.0f - 392.0f, 0.0f, 0.0f, 0.0f, 0.0f);
    drawEllipse(1.5, 1.5, 302.0f, 463.0f - 397.0f, 0.0f, 0.0f, 0.0f, 0.0f);
        // Pink controller buttons
    drawEllipse(3, 3, 296.0f, 463.0f - 382.0f, 0.0f, 0.0f, 0.0f, 0.0f);
    drawEllipse(1.5, 1.5, 294.0f, 463.0f - 395.0f, 0.0f, 0.0f, 0.0f, 0.0f);
    drawEllipse(1.5, 1.5, 296.0f, 463.0f - 390.0f, 0.0f, 0.0f, 0.0f, 0.0f);
        // Red controller buttons
    drawEllipse(3, 3, 313.0f, 463.0f - 384.0f, 0.0f, 0.0f, 0.0f, 0.0f);
    drawEllipse(1.5, 1.5, 313.0f, 463.0f - 390.0f, 0.0f, 0.0f, 0.0f, 0.0f);
    drawEllipse(1.5, 1.5, 313.0f, 463.0f - 394.0f, 0.0f, 0.0f, 0.0f, 0.0f);

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

    glEnable(GL_TEXTURE_2D); // Enable texturing
    glBindTexture(GL_TEXTURE_2D, texture2); // Bind your texture
    // glDisable(GL_LIGHTING);
    // Set color to white
    // glColor3f(0.6667f, 0.5373f, 0.3647f);
    glColor3f(1.0f, 1.0f, 1.0f);

    glBegin(GL_POLYGON);
    // glColor4b(29.0f,29.0f,34.0f,255);
    // glTexCoord2f(0.0f, 0.0f); glVertex2i(50, 463 - 120);   // Bottom-left
    // glTexCoord2f(1.0f, 0.0f); glVertex2i(66, 463 - 301);   // Bottom-right
    // glTexCoord2f(1.0f, 1.0f); glVertex2i(346, 463 - 280);  // Top-left
    // glTexCoord2f(0.0f, 1.0f); glVertex2i(363, 463 - 121);  // Top-right

    glTexCoord2f(0.0f, 0.0f); glVertex2i(66, 463 - 301);   // Bottom-right
    glTexCoord2f(1.0f, 0.0f); glVertex2i(346, 463 - 280);  // Top-left
    glTexCoord2f(1.0f, 1.0f); glVertex2i(363, 463 - 121);  // Top-right
    glTexCoord2f(0.0f, 1.0f); glVertex2i(50, 463 - 120);   // Bottom-left





    glEnd();
    glDisable(GL_TEXTURE_2D);


    // TV stands leg
    glBegin(GL_POLYGON); 
    glColor4b(0.0f,0.0f,0.0f,255);

    glVertex2i(149, 463 - 300);
    glVertex2i(154, 463 - 319);
    glVertex2i(283, 463 - 308);
    glVertex2i(265, 463 - 290);
    glEnd();

// ----------------------------------------------------------- //
    glFlush();
    glutSwapBuffers();

}

void display(){
    scene();
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
    glutCreateWindow("Caleb's Room");
    // Execute initialization procedure
    start();
    // Send graphics to display window
    glutDisplayFunc(display);
    // Display everything and wait.
    glutMainLoop();


    return 0;
}