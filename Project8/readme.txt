Caleb Klinger and Kyungchan Im
Loom Video Link:
https://www.loom.com/share/4f02f7aaef7f4428a47acaea22bd35b7?sid=185244e1-7c53-42a9-bbb4-b48742339d64

-----------------------------------------------------------------------------------------------
Prerequisites
To run this project, you need to have the following libraries installed:

    GLFW: For creating windows and handling input.
    GLEW: For loading OpenGL extensions.
    GLM: For 3D mathematics.
    GLUT and GLU (optional): For additional utilities (if used in the project).


Linux 
sudo apt-get update
sudo apt-get install libglfw3 libglfw3-dev libglew-dev libglu1-mesa-dev freeglut3-dev

Windows 
    GLFW: https://www.glfw.org/download.html
    GLEW: http://glew.sourceforge.net/
    GLM: https://github.com/g-truc/glm
    FreeGLUT: http://freeglut.sourceforge.net/

-----------------------------------------------------------------------------------------------
In terminal Run:
g++ 4dcube.cpp -o cube -lglfw -lGLEW -lglut -lGL -lGLU
./cube

Controls Keyboard: 
    Change Line Color: Press 'C' to change the color of the hypercube's lines.
    Toggle Party Mode (Epilepsy warning): Press 'P' to enable or disable party mode, where the lines flash random colors.
    Change Background Color: Press 'B' to change the background color.
    Cycle Rotation Modes: Press 'D' to cycle through different 4D rotation mode

-----------------------------------------------------------------------------------------------
