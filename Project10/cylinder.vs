#version 330 core
layout (location = 0) in vec3 aPos;     // Position attribute
layout (location = 1) in vec3 aNormal;  // Normal attribute
layout (location = 2) in vec2 TexCoords; // Texture coordinate attribute

out vec3 FragPos;  // Output fragment position (world space)
out vec3 Normal;   // Output normal (world space)
out vec2 TexCoords_Frag; // Output texture coordinate

uniform mat4 model;      // Model matrix
uniform mat4 view;       // View matrix
uniform mat4 projection; // Projection matrix

void main()
{
    // Transform vertex position into homogeneous clip coordinates
    gl_Position = projection * view * model * vec4(aPos, 1.0f);

    // Transform vertex position into world space
    FragPos = vec3(model * vec4(aPos, 1.0));

    // Transform normals to world space
    Normal = mat3(transpose(inverse(model))) * aNormal;

    // Pass texture coordinates to fragment shader
    TexCoords_Frag = TexCoords;
}
