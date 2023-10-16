// This class is created simply to create the textures that are needed.
// while a full class is slight overkill this allows for better maintence and expansion in the future
#include <iostream>
#include <GL/glut.h>
#include <stdlib.h>
#include <SOIL/SOIL.h>

GLuint textures;
class covers{
    public:
    GLuint init(const std::string& value) { // getting the in string of what we need of the file path
        // Load the texture
        textures = SOIL_load_OGL_texture(
            value.c_str(), // turning the string into a char string so it can be correctly utilized (first parameter)
            SOIL_LOAD_AUTO,
            SOIL_CREATE_NEW_ID,
            SOIL_FLAG_MIPMAPS | SOIL_FLAG_INVERT_Y | SOIL_FLAG_NTSC_SAFE_RGB | SOIL_FLAG_COMPRESS_TO_DXT
        );

        // Check for an error during the load process
        if (textures == 0)
            printf("SOIL loading error: '%s'\n", SOIL_last_result());
    return textures;
    }
    
};