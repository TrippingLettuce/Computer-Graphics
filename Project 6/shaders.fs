#version 330 core
out vec4 FragColor;

in vec3 ourColor;  // receive color from the vertex shader

void main()
{
    FragColor = vec4(ourColor, 1.0);  // set the output color to the color we received from the vertex shader
}
